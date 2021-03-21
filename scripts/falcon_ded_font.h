
#ifndef _FALCON_DED_FONT__H_
#define _FALCON_DED_FONT__H_


#define CHARACTER_HEIGHT		11


#if 0 // Copy code below into place of usage
const uint16_t* pCharacter;

switch (uniCode)
{
  case   32: { pCharacter = FALCON_DED_FONT_CHAR_32;   } break;
  case   33: { pCharacter = FALCON_DED_FONT_CHAR_33;   } break;
  case   34: { pCharacter = FALCON_DED_FONT_CHAR_34;   } break;
  case   35: { pCharacter = FALCON_DED_FONT_CHAR_35;   } break;
  case   36: { pCharacter = FALCON_DED_FONT_CHAR_36;   } break;
  case   37: { pCharacter = FALCON_DED_FONT_CHAR_37;   } break;
  case   38: { pCharacter = FALCON_DED_FONT_CHAR_38;   } break;
  case   39: { pCharacter = FALCON_DED_FONT_CHAR_39;   } break;
  case   40: { pCharacter = FALCON_DED_FONT_CHAR_40;   } break;
  case   41: { pCharacter = FALCON_DED_FONT_CHAR_41;   } break;
  case   42: { pCharacter = FALCON_DED_FONT_CHAR_42;   } break;
  case   43: { pCharacter = FALCON_DED_FONT_CHAR_43;   } break;
  case   44: { pCharacter = FALCON_DED_FONT_CHAR_44;   } break;
  case   45: { pCharacter = FALCON_DED_FONT_CHAR_45;   } break;
  case   46: { pCharacter = FALCON_DED_FONT_CHAR_46;   } break;
  case   47: { pCharacter = FALCON_DED_FONT_CHAR_47;   } break;
  case   48: { pCharacter = FALCON_DED_FONT_CHAR_48;   } break;
  case   49: { pCharacter = FALCON_DED_FONT_CHAR_49;   } break;
  case   50: { pCharacter = FALCON_DED_FONT_CHAR_50;   } break;
  case   51: { pCharacter = FALCON_DED_FONT_CHAR_51;   } break;
  case   52: { pCharacter = FALCON_DED_FONT_CHAR_52;   } break;
  case   53: { pCharacter = FALCON_DED_FONT_CHAR_53;   } break;
  case   54: { pCharacter = FALCON_DED_FONT_CHAR_54;   } break;
  case   55: { pCharacter = FALCON_DED_FONT_CHAR_55;   } break;
  case   56: { pCharacter = FALCON_DED_FONT_CHAR_56;   } break;
  case   57: { pCharacter = FALCON_DED_FONT_CHAR_57;   } break;
  case   58: { pCharacter = FALCON_DED_FONT_CHAR_58;   } break;
  case   59: { pCharacter = FALCON_DED_FONT_CHAR_59;   } break;
  case   60: { pCharacter = FALCON_DED_FONT_CHAR_60;   } break;
  case   61: { pCharacter = FALCON_DED_FONT_CHAR_61;   } break;
  case   62: { pCharacter = FALCON_DED_FONT_CHAR_62;   } break;
  case   63: { pCharacter = FALCON_DED_FONT_CHAR_63;   } break;
  case   64: { pCharacter = FALCON_DED_FONT_CHAR_64;   } break;
  case   65: { pCharacter = FALCON_DED_FONT_CHAR_65;   } break;
  case   66: { pCharacter = FALCON_DED_FONT_CHAR_66;   } break;
  case   67: { pCharacter = FALCON_DED_FONT_CHAR_67;   } break;
  case   68: { pCharacter = FALCON_DED_FONT_CHAR_68;   } break;
  case   69: { pCharacter = FALCON_DED_FONT_CHAR_69;   } break;
  case   70: { pCharacter = FALCON_DED_FONT_CHAR_70;   } break;
  case   71: { pCharacter = FALCON_DED_FONT_CHAR_71;   } break;
  case   72: { pCharacter = FALCON_DED_FONT_CHAR_72;   } break;
  case   73: { pCharacter = FALCON_DED_FONT_CHAR_73;   } break;
  case   74: { pCharacter = FALCON_DED_FONT_CHAR_74;   } break;
  case   75: { pCharacter = FALCON_DED_FONT_CHAR_75;   } break;
  case   76: { pCharacter = FALCON_DED_FONT_CHAR_76;   } break;
  case   77: { pCharacter = FALCON_DED_FONT_CHAR_77;   } break;
  case   78: { pCharacter = FALCON_DED_FONT_CHAR_78;   } break;
  case   79: { pCharacter = FALCON_DED_FONT_CHAR_79;   } break;
  case   80: { pCharacter = FALCON_DED_FONT_CHAR_80;   } break;
  case   81: { pCharacter = FALCON_DED_FONT_CHAR_81;   } break;
  case   82: { pCharacter = FALCON_DED_FONT_CHAR_82;   } break;
  case   83: { pCharacter = FALCON_DED_FONT_CHAR_83;   } break;
  case   84: { pCharacter = FALCON_DED_FONT_CHAR_84;   } break;
  case   85: { pCharacter = FALCON_DED_FONT_CHAR_85;   } break;
  case   86: { pCharacter = FALCON_DED_FONT_CHAR_86;   } break;
  case   87: { pCharacter = FALCON_DED_FONT_CHAR_87;   } break;
  case   88: { pCharacter = FALCON_DED_FONT_CHAR_88;   } break;
  case   89: { pCharacter = FALCON_DED_FONT_CHAR_89;   } break;
  case   90: { pCharacter = FALCON_DED_FONT_CHAR_90;   } break;
  case   91: { pCharacter = FALCON_DED_FONT_CHAR_91;   } break;
  case   92: { pCharacter = FALCON_DED_FONT_CHAR_92;   } break;
  case   93: { pCharacter = FALCON_DED_FONT_CHAR_93;   } break;
  case   94: { pCharacter = FALCON_DED_FONT_CHAR_94;   } break;
  case   95: { pCharacter = FALCON_DED_FONT_CHAR_95;   } break;
  case   97: { pCharacter = FALCON_DED_FONT_CHAR_97;   } break;
  case   98: { pCharacter = FALCON_DED_FONT_CHAR_98;   } break;
  case   99: { pCharacter = FALCON_DED_FONT_CHAR_99;   } break;
  case  100: { pCharacter = FALCON_DED_FONT_CHAR_100;  } break;
  case  101: { pCharacter = FALCON_DED_FONT_CHAR_101;  } break;
  case  102: { pCharacter = FALCON_DED_FONT_CHAR_102;  } break;
  case  103: { pCharacter = FALCON_DED_FONT_CHAR_103;  } break;
  case  104: { pCharacter = FALCON_DED_FONT_CHAR_104;  } break;
  case  105: { pCharacter = FALCON_DED_FONT_CHAR_105;  } break;
  case  106: { pCharacter = FALCON_DED_FONT_CHAR_106;  } break;
  case  107: { pCharacter = FALCON_DED_FONT_CHAR_107;  } break;
  case  108: { pCharacter = FALCON_DED_FONT_CHAR_108;  } break;
  case  109: { pCharacter = FALCON_DED_FONT_CHAR_109;  } break;
  case  110: { pCharacter = FALCON_DED_FONT_CHAR_110;  } break;
  case  111: { pCharacter = FALCON_DED_FONT_CHAR_111;  } break;
  case  112: { pCharacter = FALCON_DED_FONT_CHAR_112;  } break;
  case  113: { pCharacter = FALCON_DED_FONT_CHAR_113;  } break;
  case  114: { pCharacter = FALCON_DED_FONT_CHAR_114;  } break;
  case  115: { pCharacter = FALCON_DED_FONT_CHAR_115;  } break;
  case  116: { pCharacter = FALCON_DED_FONT_CHAR_116;  } break;
  case  117: { pCharacter = FALCON_DED_FONT_CHAR_117;  } break;
  case  118: { pCharacter = FALCON_DED_FONT_CHAR_118;  } break;
  case  119: { pCharacter = FALCON_DED_FONT_CHAR_119;  } break;
  case  120: { pCharacter = FALCON_DED_FONT_CHAR_120;  } break;
  case  121: { pCharacter = FALCON_DED_FONT_CHAR_121;  } break;
  case  122: { pCharacter = FALCON_DED_FONT_CHAR_122;  } break;
  case  123: { pCharacter = FALCON_DED_FONT_CHAR_123;  } break;
  case  124: { pCharacter = FALCON_DED_FONT_CHAR_124;  } break;
  case  125: { pCharacter = FALCON_DED_FONT_CHAR_125;  } break;
  case  160: { pCharacter = FALCON_DED_FONT_CHAR_160;  } break;
  case  161: { pCharacter = FALCON_DED_FONT_CHAR_161;  } break;
  case  162: { pCharacter = FALCON_DED_FONT_CHAR_162;  } break;
  case  163: { pCharacter = FALCON_DED_FONT_CHAR_163;  } break;
  case  164: { pCharacter = FALCON_DED_FONT_CHAR_164;  } break;
  case  166: { pCharacter = FALCON_DED_FONT_CHAR_166;  } break;
  case  168: { pCharacter = FALCON_DED_FONT_CHAR_168;  } break;
  case  169: { pCharacter = FALCON_DED_FONT_CHAR_169;  } break;
  case  170: { pCharacter = FALCON_DED_FONT_CHAR_170;  } break;
  case  171: { pCharacter = FALCON_DED_FONT_CHAR_171;  } break;
  case  172: { pCharacter = FALCON_DED_FONT_CHAR_172;  } break;
  case  174: { pCharacter = FALCON_DED_FONT_CHAR_174;  } break;
  case  175: { pCharacter = FALCON_DED_FONT_CHAR_175;  } break;
  case  176: { pCharacter = FALCON_DED_FONT_CHAR_176;  } break;
  case  177: { pCharacter = FALCON_DED_FONT_CHAR_177;  } break;
  case  182: { pCharacter = FALCON_DED_FONT_CHAR_182;  } break;
  case  185: { pCharacter = FALCON_DED_FONT_CHAR_185;  } break;
  case  186: { pCharacter = FALCON_DED_FONT_CHAR_186;  } break;
  case  187: { pCharacter = FALCON_DED_FONT_CHAR_187;  } break;
  case  191: { pCharacter = FALCON_DED_FONT_CHAR_191;  } break;
  case  192: { pCharacter = FALCON_DED_FONT_CHAR_192;  } break;
  case  193: { pCharacter = FALCON_DED_FONT_CHAR_193;  } break;
  case  194: { pCharacter = FALCON_DED_FONT_CHAR_194;  } break;
  case  195: { pCharacter = FALCON_DED_FONT_CHAR_195;  } break;
  case  196: { pCharacter = FALCON_DED_FONT_CHAR_196;  } break;
  case  197: { pCharacter = FALCON_DED_FONT_CHAR_197;  } break;
  case  198: { pCharacter = FALCON_DED_FONT_CHAR_198;  } break;
  case  199: { pCharacter = FALCON_DED_FONT_CHAR_199;  } break;
  case  200: { pCharacter = FALCON_DED_FONT_CHAR_200;  } break;
  case  201: { pCharacter = FALCON_DED_FONT_CHAR_201;  } break;
  case  215: { pCharacter = FALCON_DED_FONT_CHAR_215;  } break;
  case  247: { pCharacter = FALCON_DED_FONT_CHAR_247;  } break;
  case 8212: { pCharacter = FALCON_DED_FONT_CHAR_8212; } break;
  case 8218: { pCharacter = FALCON_DED_FONT_CHAR_8218; } break;
  case 8219: { pCharacter = FALCON_DED_FONT_CHAR_8219; } break;
  case 8222: { pCharacter = FALCON_DED_FONT_CHAR_8222; } break;
  case 8226: { pCharacter = FALCON_DED_FONT_CHAR_8226; } break;
  case 8249: { pCharacter = FALCON_DED_FONT_CHAR_8249; } break;
  case 8250: { pCharacter = FALCON_DED_FONT_CHAR_8250; } break;
  case 8364: { pCharacter = FALCON_DED_FONT_CHAR_8364; } break;
  case 8482: { pCharacter = FALCON_DED_FONT_CHAR_8482; } break;
  default:   { return 0;                               } break;
}
#endif


/********************** CHARACTERS **********************/


/******************************************************************************
 * Character:   (32)
 **/
const uint16_t FALCON_DED_FONT_CHAR_32[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
};

/******************************************************************************
 * Character: ! (33)
 **/
const uint16_t FALCON_DED_FONT_CHAR_33[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000000000,	//          
};

/******************************************************************************
 * Character: " (34)
 **/
const uint16_t FALCON_DED_FONT_CHAR_34[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000110110,	//    ██ ██ 
  0b000110110,	//    ██ ██ 
  0b000110110,	//    ██ ██ 
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
};

/******************************************************************************
 * Character: # (35)
 **/
const uint16_t FALCON_DED_FONT_CHAR_35[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000100100,	//    █  █  
  0b000100100,	//    █  █  
  0b001111110,	//   ██████ 
  0b000100100,	//    █  █  
  0b000100100,	//    █  █  
  0b000100100,	//    █  █  
  0b001111110,	//   ██████ 
  0b000100100,	//    █  █  
  0b000100100,	//    █  █  
  0b000000000,	//          
};

/******************************************************************************
 * Character: $ (36)
 **/
const uint16_t FALCON_DED_FONT_CHAR_36[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000111100,	//    ████  
  0b001011010,	//   █ ██ █ 
  0b001011000,	//   █ ██   
  0b000111100,	//    ████  
  0b000011010,	//     ██ █ 
  0b001011010,	//   █ ██ █ 
  0b000111100,	//    ████  
  0b000011000,	//     ██   
  0b000000000,	//          
};

/******************************************************************************
 * Character: % (37)
 **/
const uint16_t FALCON_DED_FONT_CHAR_37[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000100010,	//    █   █ 
  0b001010110,	//   █ █ ██ 
  0b000100100,	//    █  █  
  0b000001000,	//      █   
  0b000011000,	//     ██   
  0b000010000,	//     █    
  0b000100100,	//    █  █  
  0b001101010,	//   ██ █ █ 
  0b001000100,	//   █   █  
  0b000000000,	//          
};

/******************************************************************************
 * Character: & (38)
 **/
const uint16_t FALCON_DED_FONT_CHAR_38[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000111100,	//    ████  
  0b000100100,	//    █  █  
  0b000011000,	//     ██   
  0b000111100,	//    ████  
  0b001100110,	//   ██  ██ 
  0b001101110,	//   ██ ███ 
  0b001111100,	//   █████  
  0b000111010,	//    ███ █ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: ' (39)
 **/
const uint16_t FALCON_DED_FONT_CHAR_39[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000100000,	//    █     
  0b000100000,	//    █     
  0b000100000,	//    █     
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
};

/******************************************************************************
 * Character: ( (40)
 **/
const uint16_t FALCON_DED_FONT_CHAR_40[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000001100,	//      ██  
  0b000011000,	//     ██   
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000011000,	//     ██   
  0b000001100,	//      ██  
  0b000000000,	//          
};

/******************************************************************************
 * Character: ) (41)
 **/
const uint16_t FALCON_DED_FONT_CHAR_41[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000110000,	//    ██    
  0b000011000,	//     ██   
  0b000001100,	//      ██  
  0b000001100,	//      ██  
  0b000001100,	//      ██  
  0b000001100,	//      ██  
  0b000001100,	//      ██  
  0b000011000,	//     ██   
  0b000110000,	//    ██    
  0b000000000,	//          
};

/******************************************************************************
 * Character: * (42)
 **/
const uint16_t FALCON_DED_FONT_CHAR_42[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000001000,	//      █   
  0b000101010,	//    █ █ █ 
  0b000011100,	//     ███  
  0b101111111,	// █ ███████
  0b000011100,	//     ███  
  0b000101010,	//    █ █ █ 
  0b000001000,	//      █   
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
};

/******************************************************************************
 * Character: + (43)
 **/
const uint16_t FALCON_DED_FONT_CHAR_43[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000000000,	//          
  0b000000000,	//          
};

/******************************************************************************
 * Character: , (44)
 **/
const uint16_t FALCON_DED_FONT_CHAR_44[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000000000,	//          
};

/******************************************************************************
 * Character: - (45)
 **/
const uint16_t FALCON_DED_FONT_CHAR_45[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
};

/******************************************************************************
 * Character: . (46)
 **/
const uint16_t FALCON_DED_FONT_CHAR_46[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000000000,	//          
};

/******************************************************************************
 * Character: / (47)
 **/
const uint16_t FALCON_DED_FONT_CHAR_47[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000000010,	//        █ 
  0b000000110,	//       ██ 
  0b000000100,	//       █  
  0b000001000,	//      █   
  0b000011000,	//     ██   
  0b000010000,	//     █    
  0b000100000,	//    █     
  0b001100000,	//   ██     
  0b001000000,	//   █      
  0b000000000,	//          
};

/******************************************************************************
 * Character: 0 (48)
 **/
const uint16_t FALCON_DED_FONT_CHAR_48[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000111100,	//    ████  
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b000111100,	//    ████  
  0b000011000,	//     ██   
  0b000000000,	//          
};

/******************************************************************************
 * Character: 1 (49)
 **/
const uint16_t FALCON_DED_FONT_CHAR_49[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000001000,	//      █   
  0b000011000,	//     ██   
  0b000111000,	//    ███   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000111100,	//    ████  
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: 2 (50)
 **/
const uint16_t FALCON_DED_FONT_CHAR_50[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000111100,	//    ████  
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b000000110,	//       ██ 
  0b000011110,	//     ████ 
  0b000111100,	//    ████  
  0b001100000,	//   ██     
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: 3 (51)
 **/
const uint16_t FALCON_DED_FONT_CHAR_51[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000000110,	//       ██ 
  0b000001100,	//      ██  
  0b000011100,	//     ███  
  0b000000110,	//       ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: 4 (52)
 **/
const uint16_t FALCON_DED_FONT_CHAR_52[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001101100,	//   ██ ██  
  0b001101100,	//   ██ ██  
  0b001101100,	//   ██ ██  
  0b001101100,	//   ██ ██  
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000001100,	//      ██  
  0b000001100,	//      ██  
  0b000001100,	//      ██  
  0b000000000,	//          
};

/******************************************************************************
 * Character: 5 (53)
 **/
const uint16_t FALCON_DED_FONT_CHAR_53[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b001100000,	//   ██     
  0b001111100,	//   █████  
  0b001111110,	//   ██████ 
  0b000000110,	//       ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: 6 (54)
 **/
const uint16_t FALCON_DED_FONT_CHAR_54[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000111110,	//    █████ 
  0b001111110,	//   ██████ 
  0b001100000,	//   ██     
  0b001111100,	//   █████  
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: 7 (55)
 **/
const uint16_t FALCON_DED_FONT_CHAR_55[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000000110,	//       ██ 
  0b000000110,	//       ██ 
  0b000001100,	//      ██  
  0b000011000,	//     ██   
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000000000,	//          
};

/******************************************************************************
 * Character: 8 (56)
 **/
const uint16_t FALCON_DED_FONT_CHAR_56[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000111100,	//    ████  
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b000111100,	//    ████  
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: 9 (57)
 **/
const uint16_t FALCON_DED_FONT_CHAR_57[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000111100,	//    ████  
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b000111110,	//    █████ 
  0b000000110,	//       ██ 
  0b000111110,	//    █████ 
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: : (58)
 **/
const uint16_t FALCON_DED_FONT_CHAR_58[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000000000,	//          
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000000000,	//          
  0b000000000,	//          
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
};

/******************************************************************************
 * Character: ; (59)
 **/
const uint16_t FALCON_DED_FONT_CHAR_59[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000000000,	//          
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b000000000,	//          
};

/******************************************************************************
 * Character: < (60)
 **/
const uint16_t FALCON_DED_FONT_CHAR_60[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000001100,	//      ██  
  0b000011000,	//     ██   
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000011000,	//     ██   
  0b000001100,	//      ██  
  0b000000000,	//          
  0b000000000,	//          
};

/******************************************************************************
 * Character: = (61)
 **/
const uint16_t FALCON_DED_FONT_CHAR_61[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000111100,	//    ████  
  0b000111100,	//    ████  
  0b000000000,	//          
  0b000000000,	//          
  0b000111100,	//    ████  
  0b000111100,	//    ████  
  0b000000000,	//          
  0b000000000,	//          
};

/******************************************************************************
 * Character: > (62)
 **/
const uint16_t FALCON_DED_FONT_CHAR_62[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000110000,	//    ██    
  0b000011000,	//     ██   
  0b000001100,	//      ██  
  0b000001100,	//      ██  
  0b000011000,	//     ██   
  0b000110000,	//    ██    
  0b000000000,	//          
  0b000000000,	//          
};

/******************************************************************************
 * Character: ? (63)
 **/
const uint16_t FALCON_DED_FONT_CHAR_63[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000111100,	//    ████  
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b000001100,	//      ██  
  0b000001100,	//      ██  
  0b000011000,	//     ██   
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000000000,	//          
};

/******************************************************************************
 * Character: @ (64)
 **/
const uint16_t FALCON_DED_FONT_CHAR_64[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000111100,	//    ████  
  0b001111110,	//   ██████ 
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b000111100,	//    ████  
  0b000011000,	//     ██   
  0b000000000,	//          
};

/******************************************************************************
 * Character: A (65)
 **/
const uint16_t FALCON_DED_FONT_CHAR_65[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000111100,	//    ████  
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: B (66)
 **/
const uint16_t FALCON_DED_FONT_CHAR_66[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111100,	//   █████  
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001111100,	//   █████  
  0b001111100,	//   █████  
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b001111100,	//   █████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: C (67)
 **/
const uint16_t FALCON_DED_FONT_CHAR_67[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000111100,	//    ████  
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: D (68)
 **/
const uint16_t FALCON_DED_FONT_CHAR_68[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111100,	//   █████  
  0b000110110,	//    ██ ██ 
  0b000110110,	//    ██ ██ 
  0b000110110,	//    ██ ██ 
  0b000110110,	//    ██ ██ 
  0b000110110,	//    ██ ██ 
  0b000110110,	//    ██ ██ 
  0b000110110,	//    ██ ██ 
  0b001111100,	//   █████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: E (69)
 **/
const uint16_t FALCON_DED_FONT_CHAR_69[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b001100000,	//   ██     
  0b001111100,	//   █████  
  0b001111100,	//   █████  
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: F (70)
 **/
const uint16_t FALCON_DED_FONT_CHAR_70[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b001100000,	//   ██     
  0b001111100,	//   █████  
  0b001111100,	//   █████  
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b000000000,	//          
};

/******************************************************************************
 * Character: G (71)
 **/
const uint16_t FALCON_DED_FONT_CHAR_71[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000111100,	//    ████  
  0b001111110,	//   ██████ 
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001101110,	//   ██ ███ 
  0b001101110,	//   ██ ███ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: H (72)
 **/
const uint16_t FALCON_DED_FONT_CHAR_72[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: I (73)
 **/
const uint16_t FALCON_DED_FONT_CHAR_73[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: J (74)
 **/
const uint16_t FALCON_DED_FONT_CHAR_74[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b001111000,	//   ████   
  0b001110000,	//   ███    
  0b000000000,	//          
};

/******************************************************************************
 * Character: K (75)
 **/
const uint16_t FALCON_DED_FONT_CHAR_75[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001100110,	//   ██  ██ 
  0b001101110,	//   ██ ███ 
  0b001111100,	//   █████  
  0b001110000,	//   ███    
  0b001100000,	//   ██     
  0b001110000,	//   ███    
  0b001111000,	//   ████   
  0b001101110,	//   ██ ███ 
  0b001100110,	//   ██  ██ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: L (76)
 **/
const uint16_t FALCON_DED_FONT_CHAR_76[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: M (77)
 **/
const uint16_t FALCON_DED_FONT_CHAR_77[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001000010,	//   █    █ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: N (78)
 **/
const uint16_t FALCON_DED_FONT_CHAR_78[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001000110,	//   █   ██ 
  0b001100110,	//   ██  ██ 
  0b001110110,	//   ███ ██ 
  0b001110110,	//   ███ ██ 
  0b001101110,	//   ██ ███ 
  0b001101110,	//   ██ ███ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100010,	//   ██   █ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: O (79)
 **/
const uint16_t FALCON_DED_FONT_CHAR_79[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000111100,	//    ████  
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: P (80)
 **/
const uint16_t FALCON_DED_FONT_CHAR_80[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111100,	//   █████  
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b001111100,	//   █████  
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b001100000,	//   ██     
  0b000000000,	//          
};

/******************************************************************************
 * Character: Q (81)
 **/
const uint16_t FALCON_DED_FONT_CHAR_81[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000111100,	//    ████  
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001101110,	//   ██ ███ 
  0b001111100,	//   █████  
  0b000111010,	//    ███ █ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: R (82)
 **/
const uint16_t FALCON_DED_FONT_CHAR_82[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111100,	//   █████  
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b001111100,	//   █████  
  0b001101100,	//   ██ ██  
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: S (83)
 **/
const uint16_t FALCON_DED_FONT_CHAR_83[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000111100,	//    ████  
  0b001111110,	//   ██████ 
  0b001100000,	//   ██     
  0b001111100,	//   █████  
  0b000111110,	//    █████ 
  0b000000110,	//       ██ 
  0b000000110,	//       ██ 
  0b001111110,	//   ██████ 
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: T (84)
 **/
const uint16_t FALCON_DED_FONT_CHAR_84[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000000000,	//          
};

/******************************************************************************
 * Character: U (85)
 **/
const uint16_t FALCON_DED_FONT_CHAR_85[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: V (86)
 **/
const uint16_t FALCON_DED_FONT_CHAR_86[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b000100100,	//    █  █  
  0b000111100,	//    ████  
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000000000,	//          
};

/******************************************************************************
 * Character: W (87)
 **/
const uint16_t FALCON_DED_FONT_CHAR_87[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b001100110,	//   ██  ██ 
  0b001000010,	//   █    █ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: X (88)
 **/
const uint16_t FALCON_DED_FONT_CHAR_88[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b000100100,	//    █  █  
  0b000111100,	//    ████  
  0b000011000,	//     ██   
  0b000111100,	//    ████  
  0b000100100,	//    █  █  
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: Y (89)
 **/
const uint16_t FALCON_DED_FONT_CHAR_89[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001100110,	//   ██  ██ 
  0b001100110,	//   ██  ██ 
  0b000100100,	//    █  █  
  0b000111100,	//    ████  
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000000000,	//          
};

/******************************************************************************
 * Character: Z (90)
 **/
const uint16_t FALCON_DED_FONT_CHAR_90[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000000110,	//       ██ 
  0b000001100,	//      ██  
  0b000011000,	//     ██   
  0b000110000,	//    ██    
  0b001100000,	//   ██     
  0b001111110,	//   ██████ 
  0b001111110,	//   ██████ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: [ (91)
 **/
const uint16_t FALCON_DED_FONT_CHAR_91[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000111100,	//    ████  
  0b000111100,	//    ████  
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000110000,	//    ██    
  0b000111100,	//    ████  
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: \ (92)
 **/
const uint16_t FALCON_DED_FONT_CHAR_92[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001000000,	//   █      
  0b001100000,	//   ██     
  0b000100000,	//    █     
  0b000010000,	//     █    
  0b000011000,	//     ██   
  0b000001000,	//      █   
  0b000000100,	//       █  
  0b000000110,	//       ██ 
  0b000000010,	//        █ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: ] (93)
 **/
const uint16_t FALCON_DED_FONT_CHAR_93[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000111100,	//    ████  
  0b000111100,	//    ████  
  0b000001100,	//      ██  
  0b000001100,	//      ██  
  0b000001100,	//      ██  
  0b000001100,	//      ██  
  0b000001100,	//      ██  
  0b000111100,	//    ████  
  0b000111100,	//    ████  
  0b000000000,	//          
};

/******************************************************************************
 * Character: ^ (94)
 **/
const uint16_t FALCON_DED_FONT_CHAR_94[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000100100,	//    █  █  
  0b000100100,	//    █  █  
  0b000011000,	//     ██   
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
};

/******************************************************************************
 * Character: _ (95)
 **/
const uint16_t FALCON_DED_FONT_CHAR_95[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: a (97)
 **/
const uint16_t FALCON_DED_FONT_CHAR_97[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111000011,	// ███    ██
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: b (98)
 **/
const uint16_t FALCON_DED_FONT_CHAR_98[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000011,	// ██     ██
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b110000011,	// ██     ██
  0b110000011,	// ██     ██
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b110000011,	// ██     ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: c (99)
 **/
const uint16_t FALCON_DED_FONT_CHAR_99[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: d (100)
 **/
const uint16_t FALCON_DED_FONT_CHAR_100[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000011,	// ██     ██
  0b111001001,	// ███  █  █
  0b111001001,	// ███  █  █
  0b111001001,	// ███  █  █
  0b111001001,	// ███  █  █
  0b111001001,	// ███  █  █
  0b111001001,	// ███  █  █
  0b111001001,	// ███  █  █
  0b110000011,	// ██     ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: e (101)
 **/
const uint16_t FALCON_DED_FONT_CHAR_101[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b110011111,	// ██  █████
  0b110000011,	// ██     ██
  0b110000011,	// ██     ██
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: f (102)
 **/
const uint16_t FALCON_DED_FONT_CHAR_102[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b110011111,	// ██  █████
  0b110000011,	// ██     ██
  0b110000011,	// ██     ██
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: g (103)
 **/
const uint16_t FALCON_DED_FONT_CHAR_103[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b110000001,	// ██      █
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110010001,	// ██  █   █
  0b110010001,	// ██  █   █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: h (104)
 **/
const uint16_t FALCON_DED_FONT_CHAR_104[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: i (105)
 **/
const uint16_t FALCON_DED_FONT_CHAR_105[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: j (106)
 **/
const uint16_t FALCON_DED_FONT_CHAR_106[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b110000111,	// ██    ███
  0b110001111,	// ██   ████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: k (107)
 **/
const uint16_t FALCON_DED_FONT_CHAR_107[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110011001,	// ██  ██  █
  0b110010001,	// ██  █   █
  0b110000011,	// ██     ██
  0b110001111,	// ██   ████
  0b110011111,	// ██  █████
  0b110001111,	// ██   ████
  0b110000111,	// ██    ███
  0b110010001,	// ██  █   █
  0b110011001,	// ██  ██  █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: l (108)
 **/
const uint16_t FALCON_DED_FONT_CHAR_108[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: m (109)
 **/
const uint16_t FALCON_DED_FONT_CHAR_109[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110111101,	// ██ ████ █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: n (110)
 **/
const uint16_t FALCON_DED_FONT_CHAR_110[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110111001,	// ██ ███  █
  0b110011001,	// ██  ██  █
  0b110001001,	// ██   █  █
  0b110001001,	// ██   █  █
  0b110010001,	// ██  █   █
  0b110010001,	// ██  █   █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011101,	// ██  ███ █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: o (111)
 **/
const uint16_t FALCON_DED_FONT_CHAR_111[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: p (112)
 **/
const uint16_t FALCON_DED_FONT_CHAR_112[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000011,	// ██     ██
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b110000011,	// ██     ██
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: q (113)
 **/
const uint16_t FALCON_DED_FONT_CHAR_113[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110000011,	// ██     ██
  0b111000101,	// ███   █ █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: r (114)
 **/
const uint16_t FALCON_DED_FONT_CHAR_114[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000011,	// ██     ██
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b110000011,	// ██     ██
  0b110010011,	// ██  █  ██
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: s (115)
 **/
const uint16_t FALCON_DED_FONT_CHAR_115[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b110000001,	// ██      █
  0b110111111,	// ██ ██████
  0b110000011,	// ██     ██
  0b111000001,	// ███     █
  0b111111001,	// ██████  █
  0b111111001,	// ██████  █
  0b110000001,	// ██      █
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: t (116)
 **/
const uint16_t FALCON_DED_FONT_CHAR_116[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: u (117)
 **/
const uint16_t FALCON_DED_FONT_CHAR_117[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: v (118)
 **/
const uint16_t FALCON_DED_FONT_CHAR_118[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b111011011,	// ███ ██ ██
  0b111000011,	// ███    ██
  0b111100111,	// ████  ███
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: w (119)
 **/
const uint16_t FALCON_DED_FONT_CHAR_119[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b110111101,	// ██ ████ █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: x (120)
 **/
const uint16_t FALCON_DED_FONT_CHAR_120[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b111011011,	// ███ ██ ██
  0b111000011,	// ███    ██
  0b111100111,	// ████  ███
  0b111000011,	// ███    ██
  0b111011011,	// ███ ██ ██
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: y (121)
 **/
const uint16_t FALCON_DED_FONT_CHAR_121[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b111011011,	// ███ ██ ██
  0b111000011,	// ███    ██
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: z (122)
 **/
const uint16_t FALCON_DED_FONT_CHAR_122[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111111001,	// ██████  █
  0b111110011,	// █████  ██
  0b111100111,	// ████  ███
  0b111001111,	// ███  ████
  0b110011111,	// ██  █████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: { (123)
 **/
const uint16_t FALCON_DED_FONT_CHAR_123[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b001111100,	//   █████  
  0b001110000,	//   ███    
  0b001100000,	//   ██     
  0b001000000,	//   █      
  0b001100000,	//   ██     
  0b001110000,	//   ███    
  0b001111100,	//   █████  
  0b001111110,	//   ██████ 
  0b000000000,	//          
};

/******************************************************************************
 * Character: | (124)
 **/
const uint16_t FALCON_DED_FONT_CHAR_124[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b000011000,	//     ██   
  0b001111110,	//   ██████ 
  0b000111100,	//    ████  
  0b000011000,	//     ██   
  0b000000000,	//          
};

/******************************************************************************
 * Character: } (125)
 **/
const uint16_t FALCON_DED_FONT_CHAR_125[CHARACTER_HEIGHT] =
{
  0b000000000,	//          
  0b001111110,	//   ██████ 
  0b000111110,	//    █████ 
  0b000001110,	//      ███ 
  0b000000110,	//       ██ 
  0b000000010,	//        █ 
  0b000000110,	//       ██ 
  0b000001110,	//      ███ 
  0b000111110,	//    █████ 
  0b001111110,	//   ██████ 
  0b000000000,	//          
};

/******************************************************************************
 * Character:   (160)
 **/
const uint16_t FALCON_DED_FONT_CHAR_160[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ¡ (161)
 **/
const uint16_t FALCON_DED_FONT_CHAR_161[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ¢ (162)
 **/
const uint16_t FALCON_DED_FONT_CHAR_162[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111000011,	// ███    ██
  0b110100101,	// ██ █  █ █
  0b110100111,	// ██ █  ███
  0b111000011,	// ███    ██
  0b111100101,	// ████  █ █
  0b110100101,	// ██ █  █ █
  0b111000011,	// ███    ██
  0b111100111,	// ████  ███
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: £ (163)
 **/
const uint16_t FALCON_DED_FONT_CHAR_163[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111000011,	// ███    ██
  0b111011011,	// ███ ██ ██
  0b111100111,	// ████  ███
  0b111000011,	// ███    ██
  0b110011001,	// ██  ██  █
  0b110010001,	// ██  █   █
  0b110000011,	// ██     ██
  0b111000101,	// ███   █ █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ¤ (164)
 **/
const uint16_t FALCON_DED_FONT_CHAR_164[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ¦ (166)
 **/
const uint16_t FALCON_DED_FONT_CHAR_166[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b110000001,	// ██      █
  0b111000011,	// ███    ██
  0b111100111,	// ████  ███
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ¨ (168)
 **/
const uint16_t FALCON_DED_FONT_CHAR_168[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: © (169)
 **/
const uint16_t FALCON_DED_FONT_CHAR_169[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b111000001,	// ███     █
  0b111110001,	// █████   █
  0b111111001,	// ██████  █
  0b111111101,	// ███████ █
  0b111111001,	// ██████  █
  0b111110001,	// █████   █
  0b111000001,	// ███     █
  0b110000001,	// ██      █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ª (170)
 **/
const uint16_t FALCON_DED_FONT_CHAR_170[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111001111,	// ███  ████
  0b111001111,	// ███  ████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: « (171)
 **/
const uint16_t FALCON_DED_FONT_CHAR_171[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b111000011,	// ███    ██
  0b111001111,	// ███  ████
  0b111001111,	// ███  ████
  0b111001111,	// ███  ████
  0b111001111,	// ███  ████
  0b111001111,	// ███  ████
  0b111000011,	// ███    ██
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ¬ (172)
 **/
const uint16_t FALCON_DED_FONT_CHAR_172[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110111111,	// ██ ██████
  0b110011111,	// ██  █████
  0b111011111,	// ███ █████
  0b111101111,	// ████ ████
  0b111100111,	// ████  ███
  0b111110111,	// █████ ███
  0b111111011,	// ██████ ██
  0b111111001,	// ██████  █
  0b111111101,	// ███████ █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ® (174)
 **/
const uint16_t FALCON_DED_FONT_CHAR_174[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b110000011,	// ██     ██
  0b110001111,	// ██   ████
  0b110011111,	// ██  █████
  0b110111111,	// ██ ██████
  0b110011111,	// ██  █████
  0b110001111,	// ██   ████
  0b110000011,	// ██     ██
  0b110000001,	// ██      █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ¯ (175)
 **/
const uint16_t FALCON_DED_FONT_CHAR_175[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b111111111,	// █████████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ° (176)
 **/
const uint16_t FALCON_DED_FONT_CHAR_176[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111011011,	// ███ ██ ██
  0b111011011,	// ███ ██ ██
  0b111100111,	// ████  ███
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ± (177)
 **/
const uint16_t FALCON_DED_FONT_CHAR_177[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b111000011,	// ███    ██
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b111000011,	// ███    ██
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ¶ (182)
 **/
const uint16_t FALCON_DED_FONT_CHAR_182[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111101,	// ███████ █
  0b111111001,	// ██████  █
  0b111111011,	// ██████ ██
  0b111110111,	// █████ ███
  0b111100111,	// ████  ███
  0b111101111,	// ████ ████
  0b111011111,	// ███ █████
  0b110011111,	// ██  █████
  0b110111111,	// ██ ██████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ¹ (185)
 **/
const uint16_t FALCON_DED_FONT_CHAR_185[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111110011,	// █████  ██
  0b111100111,	// ████  ███
  0b111001111,	// ███  ████
  0b111001111,	// ███  ████
  0b111100111,	// ████  ███
  0b111110011,	// █████  ██
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: º (186)
 **/
const uint16_t FALCON_DED_FONT_CHAR_186[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111001111,	// ███  ████
  0b111100111,	// ████  ███
  0b111110011,	// █████  ██
  0b111110011,	// █████  ██
  0b111100111,	// ████  ███
  0b111001111,	// ███  ████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: » (187)
 **/
const uint16_t FALCON_DED_FONT_CHAR_187[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b111000011,	// ███    ██
  0b111110011,	// █████  ██
  0b111110011,	// █████  ██
  0b111110011,	// █████  ██
  0b111110011,	// █████  ██
  0b111110011,	// █████  ██
  0b111000011,	// ███    ██
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ¿ (191)
 **/
const uint16_t FALCON_DED_FONT_CHAR_191[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b111110011,	// █████  ██
  0b111110011,	// █████  ██
  0b111100111,	// ████  ███
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: À (192)
 **/
const uint16_t FALCON_DED_FONT_CHAR_192[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111000011,	// ███    ██
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b111000011,	// ███    ██
  0b111100111,	// ████  ███
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: Á (193)
 **/
const uint16_t FALCON_DED_FONT_CHAR_193[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111110111,	// █████ ███
  0b111100111,	// ████  ███
  0b111000111,	// ███   ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111000011,	// ███    ██
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: Â (194)
 **/
const uint16_t FALCON_DED_FONT_CHAR_194[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b111111001,	// ██████  █
  0b111100001,	// ████    █
  0b111000011,	// ███    ██
  0b110011111,	// ██  █████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: Ã (195)
 **/
const uint16_t FALCON_DED_FONT_CHAR_195[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111111011,	// ██████ ██
  0b111110011,	// █████  ██
  0b111100011,	// ████   ██
  0b111111001,	// ██████  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: Ä (196)
 **/
const uint16_t FALCON_DED_FONT_CHAR_196[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110010011,	// ██  █  ██
  0b110010011,	// ██  █  ██
  0b110010011,	// ██  █  ██
  0b110010011,	// ██  █  ██
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111110011,	// █████  ██
  0b111110011,	// █████  ██
  0b111110011,	// █████  ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: Å (197)
 **/
const uint16_t FALCON_DED_FONT_CHAR_197[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b110011111,	// ██  █████
  0b110000011,	// ██     ██
  0b110000001,	// ██      █
  0b111111001,	// ██████  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: Æ (198)
 **/
const uint16_t FALCON_DED_FONT_CHAR_198[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111000001,	// ███     █
  0b110000001,	// ██      █
  0b110011111,	// ██  █████
  0b110000011,	// ██     ██
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: Ç (199)
 **/
const uint16_t FALCON_DED_FONT_CHAR_199[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111111001,	// ██████  █
  0b111111001,	// ██████  █
  0b111110011,	// █████  ██
  0b111100111,	// ████  ███
  0b111001111,	// ███  ████
  0b111001111,	// ███  ████
  0b111001111,	// ███  ████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: È (200)
 **/
const uint16_t FALCON_DED_FONT_CHAR_200[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b111000011,	// ███    ██
  0b111000011,	// ███    ██
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: É (201)
 **/
const uint16_t FALCON_DED_FONT_CHAR_201[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111000011,	// ███    ██
  0b110000001,	// ██      █
  0b110011001,	// ██  ██  █
  0b110011001,	// ██  ██  █
  0b110000001,	// ██      █
  0b111000001,	// ███     █
  0b111111001,	// ██████  █
  0b111000001,	// ███     █
  0b111000011,	// ███    ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: × (215)
 **/
const uint16_t FALCON_DED_FONT_CHAR_215[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111101111,	// ████ ████
  0b110101011,	// ██ █ █ ██
  0b111000111,	// ███   ███
  0b100000001,	// █       █
  0b111000111,	// ███   ███
  0b110101011,	// ██ █ █ ██
  0b111101111,	// ████ ████
  0b111111111,	// █████████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ÷ (247)
 **/
const uint16_t FALCON_DED_FONT_CHAR_247[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111011101,	// ███ ███ █
  0b110101001,	// ██ █ █  █
  0b111011011,	// ███ ██ ██
  0b111110111,	// █████ ███
  0b111100111,	// ████  ███
  0b111101111,	// ████ ████
  0b111011011,	// ███ ██ ██
  0b110010101,	// ██  █ █ █
  0b110111011,	// ██ ███ ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: — (8212)
 **/
const uint16_t FALCON_DED_FONT_CHAR_8212[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b110000001,	// ██      █
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ‚ (8218)
 **/
const uint16_t FALCON_DED_FONT_CHAR_8218[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111001111,	// ███  ████
  0b111001111,	// ███  ████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ‛ (8219)
 **/
const uint16_t FALCON_DED_FONT_CHAR_8219[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111011111,	// ███ █████
  0b111011111,	// ███ █████
  0b111011111,	// ███ █████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: „ (8222)
 **/
const uint16_t FALCON_DED_FONT_CHAR_8222[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111001001,	// ███  █  █
  0b111001001,	// ███  █  █
  0b111001001,	// ███  █  █
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: • (8226)
 **/
const uint16_t FALCON_DED_FONT_CHAR_8226[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111100111,	// ████  ███
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ‹ (8249)
 **/
const uint16_t FALCON_DED_FONT_CHAR_8249[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111001111,	// ███  ████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b110011111,	// ██  █████
  0b111001111,	// ███  ████
  0b111100111,	// ████  ███
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: › (8250)
 **/
const uint16_t FALCON_DED_FONT_CHAR_8250[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111110011,	// █████  ██
  0b111111001,	// ██████  █
  0b111111001,	// ██████  █
  0b111111001,	// ██████  █
  0b111111001,	// ██████  █
  0b111111001,	// ██████  █
  0b111110011,	// █████  ██
  0b111100111,	// ████  ███
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: € (8364)
 **/
const uint16_t FALCON_DED_FONT_CHAR_8364[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111011011,	// ███ ██ ██
  0b111011011,	// ███ ██ ██
  0b110000001,	// ██      █
  0b111011011,	// ███ ██ ██
  0b111011011,	// ███ ██ ██
  0b111011011,	// ███ ██ ██
  0b110000001,	// ██      █
  0b111011011,	// ███ ██ ██
  0b111011011,	// ███ ██ ██
  0b111111111,	// █████████
};

/******************************************************************************
 * Character: ™ (8482)
 **/
const uint16_t FALCON_DED_FONT_CHAR_8482[CHARACTER_HEIGHT] =
{
  0b111111111,	// █████████
  0b111100111,	// ████  ███
  0b111000011,	// ███    ██
  0b110000001,	// ██      █
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b111111111,	// █████████
  0b110000001,	// ██      █
  0b111000011,	// ███    ██
  0b111100111,	// ████  ███
  0b111111111,	// █████████
};



#endif // _FALCON_DED_FONT__H_

