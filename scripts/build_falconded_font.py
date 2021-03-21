from falconded_font_raw import *

FONT_NAME = "FALCON_DED_FONT"
INDENT = '  '
CHARACTER_HEIGHT_DEFINE = "CHARACTER_HEIGHT"
CHARACTER_HEIGHT = 11

fontRaw = falconded_font_raw

def print_char(index, fontCharValues):
    print('Character index:', index)
    print('')
    #for value in fontCharValues[2:-3]:
    for value in fontCharValues:
        print((bin(value)[2:].zfill(10)[::-1][2:]).replace('0', ' ').replace('1', '█'))
    print('---------------------')
    
def convert_char_to_binary_array(fontCharValues):
    fontCharBinaryArray = []

    for value in fontCharValues:
        #fontCharBinaryArray.append(bin(value)[2:].zfill(10)[::-1][2:])
        
        binaryArray = bin(value)[2:].zfill(10)[::-1][2:]
        
        if len(binaryArray) == 8:
            binaryArray = binaryArray[-1] + binaryArray
        
        fontCharBinaryArray.append(binaryArray)
    
    return fontCharBinaryArray

def convert_to_header_file_segment(uniCodeValue, fontCharBinaryArray):
    variableName = '%s_CHAR_%s' % (FONT_NAME, uniCodeValue)
    
    headerFileStr  = '/******************************************************************************\n'
    headerFileStr += ' * Character: %c (%s)\n' % (chr(int(uniCodeValue)), uniCodeValue)    
    headerFileStr += ' **/\n'
    headerFileStr += 'const uint16_t %s[%s] =\n' % (variableName, CHARACTER_HEIGHT_DEFINE)
    headerFileStr += '{\n'
    
    for binaryString in fontCharBinaryArray:
        headerFileStr += '%s0b%s,\t// %s\n' % (INDENT, binaryString, (binaryString.replace('0', ' ').replace('1', '█')))
        
    headerFileStr += '};\n'
    
    return [variableName, headerFileStr]
    
def create_header_file_beginning():
    headerfileBeginning  = '\n'
    headerfileBeginning += '#ifndef _%s__H_\n' % (FONT_NAME)
    headerfileBeginning += '#define _%s__H_\n' % (FONT_NAME)
    headerfileBeginning += '\n'
    headerfileBeginning += '\n'
    
    return headerfileBeginning
    
def create_header_defines():
    headerfileDefines  = '#define %s\t\t%d\n' % (CHARACTER_HEIGHT_DEFINE, CHARACTER_HEIGHT)
    headerfileDefines += '\n'
    
    return headerfileDefines
    
def create_header_file_end():
    headerfileEnd  = '\n'
    headerfileEnd += '\n'
    headerfileEnd += '#endif // _%s__H_\n' % (FONT_NAME)
    headerfileEnd += '\n'
    
    return headerfileEnd
    
def create_look_up_code(characterSegments):
    lookUpCode  = '\n'
    lookUpCode += '#if 0 // Copy code below into place of usage\n'
    lookUpCode += 'const uint16_t* pCharacter;\n'
    lookUpCode += '\n'
    lookUpCode += 'switch (uniCode)\n'
    lookUpCode += '{\n'
    
    for character in characterSegments:
        lookUpCode += '%scase %4s: { pCharacter = %-27s} break;\n' % (INDENT, character, characterSegments[character] + ';')
        
    lookUpCode += '%s%-11s{ return %-33s} break;\n' % (INDENT, 'default:', '0;')
    lookUpCode += '}\n'
    lookUpCode += '#endif\n'
    
    return lookUpCode

def create_header_file(filename, fontRawValues):
    headerFileStr = ''
    fontCharBinaryArrays = {}
    characterSegments = {}
    headerFileSegments = {}

    for uniCodeChar in fontRawValues:
        #print_char(uniCodeChar, fontRaw[uniCodeChar])
        fontCharBinaryArrays[uniCodeChar] = convert_char_to_binary_array(fontRaw[uniCodeChar][2:-3])
        variableName, headerFileSegment = convert_to_header_file_segment(uniCodeChar, fontCharBinaryArrays[uniCodeChar])
        characterSegments[uniCodeChar] = variableName
        headerFileSegments[uniCodeChar] = headerFileSegment

    headerFileStr += create_header_file_beginning()
    headerFileStr += create_header_defines()
    headerFileStr += create_look_up_code(characterSegments)
    headerFileStr += '\n'
    headerFileStr += '\n'
    headerFileStr += '/********************** CHARACTERS **********************/\n'
    headerFileStr += '\n'
    headerFileStr += '\n'
    
    for headerFileSegment in headerFileSegments:
        for line in headerFileSegments[headerFileSegment]:
            headerFileStr += line
        headerFileStr += '\n'
    
    headerFileStr += create_header_file_end()
    
    with open(filename, 'w', encoding='utf-8') as f:
        f.write(headerFileStr)
    

create_header_file('falcon_ded_font.h', fontRaw)
