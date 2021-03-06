/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "gpio.h"
#include "falcon_ded_font.h"
#include "ssd1322.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define SSD1322_256_64_4

#if defined(SSD1322_256_64_4)
  #define SSD1322_LCDHEIGHT             64
  #define SSD1322_LCDWIDTH              256
  #define SSD1322_BITS_PER_PIXEL        4
#endif

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
static uint8_t buffer[SSD1322_LCDHEIGHT * SSD1322_LCDWIDTH / (8 / SSD1322_BITS_PER_PIXEL)] = { 0x00 };

/* Private function prototypes -----------------------------------------------*/
void SSD1322_Command(uint8_t command);
void SSD1322_Data(uint8_t data);
void SSD1322_DataBytes(uint8_t* data, uint16_t length);
void SSD1322_Write(uint8_t isCommand, uint8_t* payload, uint16_t length);


/* Private user code ---------------------------------------------------------*/


void SSD1322_Initialize(void)
{
	// Reset
	SSD1322_Reset();

	// Initialize
	SSD1322_Command(SSD1322_CMD_SETCOMMANDLOCK);// 0xFD
	SSD1322_Data(0x12);// Unlock OLED driver IC

	SSD1322_Command(SSD1322_CMD_DISPLAYOFF);// 0xAE

	SSD1322_Command(SSD1322_CMD_SETCLOCKDIVIDER);// 0xB3
	SSD1322_Data(0x91);// 0xB3

	SSD1322_Command(SSD1322_CMD_SETMUXRATIO);// 0xCA
	SSD1322_Data(0x3F);// duty = 1/64

	SSD1322_Command(SSD1322_CMD_SETDISPLAYOFFSET);// 0xA2
	SSD1322_Data(0x00);

	SSD1322_Command(SSD1322_CMD_SETSTARTLINE);// 0xA1
	SSD1322_Data(0x00);

	SSD1322_Command(SSD1322_CMD_SETREMAP);// 0xA0
	SSD1322_Data(0x14);//Horizontal address increment,Disable Column Address Re-map,Enable Nibble Re-map,Scan from COM[N-1] to COM0,Disable COM Split Odd Even
	SSD1322_Data(0x11);//Enable Dual COM mode

	SSD1322_Command(SSD1322_CMD_SETGPIO);// 0xB5
	SSD1322_Data(0x00);// Disable GPIO Pins Input

	SSD1322_Command(SSD1322_CMD_FUNCTIONSEL);// 0xAB
	SSD1322_Data(0x01);// selection external vdd

	SSD1322_Command(SSD1322_CMD_DISPLAYENHANCE);// 0xB4
	SSD1322_Data(0xA0);// enables the external VSL
	SSD1322_Data(0xFD);// 0xfFD,Enhanced low GS display quality;default is 0xb5(normal),

	SSD1322_Command(SSD1322_CMD_SETCONTRASTCURRENT);// 0xC1
	SSD1322_Data(0xFF);// 0xFF - default is 0x7f

	SSD1322_Command(SSD1322_CMD_MASTERCURRENTCONTROL);// 0xC7
	SSD1322_Data(0x0F);// default is 0x0F

	// Set grayscale
	SSD1322_Command(SSD1322_CMD_SELECTDEFAULTGRAYSCALE); // 0xB9

	SSD1322_Command(SSD1322_CMD_SETPHASELENGTH);// 0xB1
	SSD1322_Data(0xE2);// default is 0x74

	SSD1322_Command(SSD1322_CMD_DISPLAYENHANCEB);// 0xD1
	SSD1322_Data(0x82);// Reserved;default is 0xa2(normal)
	SSD1322_Data(0x20);//

	SSD1322_Command(SSD1322_CMD_SETPRECHARGEVOLTAGE);// 0xBB
	SSD1322_Data(0x1F);// 0.6xVcc

	SSD1322_Command(SSD1322_CMD_SETSECONDPRECHARGEPERIOD);// 0xB6
	SSD1322_Data(0x08);// default

	SSD1322_Command(SSD1322_CMD_SETVCOMH);// 0xBE
	SSD1322_Data(0x07);// 0.86xVcc;default is 0x04

	SSD1322_Command(SSD1322_CMD_NORMALDISPLAY);// 0xA6

	SSD1322_Command(SSD1322_CMD_EXITPARTIALDISPLAY);// 0xA9

	// Clear down image ram before opening display
	SSD1322_Fill(0x00);

	// Turn Display ON
	SSD1322_Command(SSD1322_CMD_DISPLAYON);// 0xAF
}


void SSD1322_Reset(void)
{
	// Release RESET pin
	HAL_GPIO_WritePin(RES_GPIO_Port, RES_Pin, GPIO_PIN_SET);

	// Wait for 100ms
	HAL_Delay(100);

	// Set RESET pin
	HAL_GPIO_WritePin(RES_GPIO_Port, RES_Pin, GPIO_PIN_RESET);

	// Wait for 400ms
	HAL_Delay(400);

	// Release RESET pin
	HAL_GPIO_WritePin(RES_GPIO_Port, RES_Pin, GPIO_PIN_SET);
}


void SSD1322_Command(uint8_t command)
{
  SSD1322_Write(1, &command, 1);
}


void SSD1322_Data(uint8_t data)
{
  SSD1322_Write(0, &data, 1);
}


void SSD1322_DataBytes(uint8_t* data, uint16_t length)
{
  SSD1322_Write(0, data, length);
}


void SSD1322_Write(uint8_t isCommand, uint8_t* payload, uint16_t length)
{
  // Set CS pin high
  HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);

  if (isCommand)
  {
    // Command - Set DC pin low
    HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, GPIO_PIN_RESET);
  }
  else
  {
    // Data - Set DC pin high
    HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, GPIO_PIN_SET);
  }

  // Set CS pin low
  HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);

  // Write command
  HAL_SPI_Transmit(&hspi3, payload, length, 1000);

  // Set CS pin high
  HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
}


void SSD1322_Display(void)
{
  SSD1322_Command(SSD1322_CMD_SETCOLUMNADDR);
  SSD1322_Data(SSD1322_MIN_SEG);
  SSD1322_Data(SSD1322_MAX_SEG);

  SSD1322_Command(SSD1322_CMD_SETROWADDR);
  SSD1322_Data(0);
  SSD1322_Data(63);

  SSD1322_Command(SSD1322_CMD_WRITERAM);

  uint16_t bufSize = (SSD1322_LCDHEIGHT * SSD1322_LCDWIDTH / (8 / SSD1322_BITS_PER_PIXEL)); // bytes
  uint8_t *pBuf = buffer;

#ifdef SSD1322_256_64_4
  // Write as quickly as possible
  SSD1322_DataBytes(pBuf, bufSize);
#endif
#ifdef SSD1322_256_64_1
  uint16_t srcIndex = 0;

  while (srcIndex < bufSize)
  {
    uint8_t destIndex = 0;
    uint8_t destArray[64] = {0};

    while (destIndex < 64)
    {
      uint8_t mask = 0x80;

      while (mask > 0)
      {
        // upper nibble
        destArray[destIndex] |= (pBuf[srcIndex] & mask) ? 0xf0 : 0x00;
        //shift mask to next bit, but this goes into lower nibble.
        mask >>= 1;
        destArray[destIndex] |= (pBuf[srcIndex] & mask) ? 0x0f : 0x00;

        destIndex++;
        mask >>= 1;
      }
      srcIndex++;
    }
    // Send to display here.
    ssd1322_dataBytes(destArray, 64);
  }
#endif
}


void SSD1322_Fill(uint8_t color)
{
  uint8_t x;
  uint8_t y;

  // Set column
  SSD1322_Command(SSD1322_CMD_SETCOLUMNADDR);
  SSD1322_Data(SSD1322_MIN_SEG);
  SSD1322_Data(SSD1322_MAX_SEG);

  // Set row
  SSD1322_Command(SSD1322_CMD_SETROWADDR);
  SSD1322_Data(0);
  SSD1322_Data(63);

  // Set color
  color = (color & 0x0F) | (color << 4);

  // Set Write RAM command
  SSD1322_Command(SSD1322_CMD_WRITERAM);

  // Write data
  for (y = 0; y < 64; y++)
  {
    for (x = 0; x < 128; x++)
    {
      SSD1322_Data(color);
    }
  }

  HAL_Delay(0);
}


void SSD1322_DrawPixel(int16_t x, int16_t y, uint16_t gscale)
{
#if 0
  // Check rotation, move pixel around if necessary
  switch (getRotation())
  {
    case 1:
    {
      _swap_int16_t(x, y);
      x = WIDTH - x - 1;
    }
    break;

    case 2:
    {
      x = WIDTH - x - 1;
      y = HEIGHT - y - 1;
    }
    break;

    case 3:
    {
      _swap_int16_t(x, y);
      y = HEIGHT - y - 1;
    }
    break;

    default:
    {
      // Empty
    }
  }
#endif

  //if ((x < 0) || (x >= width()) || (y < 0) || (y >= height()))
  if ((x < 0) || (x >= SSD1322_LCDWIDTH) || (y < 0) || (y >= SSD1322_LCDHEIGHT))
  {
    return;
  }

#ifdef SSD1322_256_64_4 // 4 bits per pixel
  uint8_t mask = ((x % 2) ? gscale : gscale << 4);
  uint8_t *pBuf = &buffer[(x >> 1) + (y * (SSD1322_LCDWIDTH / 2))];
  uint8_t b1 = *pBuf;
  b1 &= (x % 2) ? 0xF0 : 0x0F; // cleardown nibble to be replaced
  // write our value in
  *pBuf++ = b1 | mask;
#endif
#ifdef SSD1322_256_64_1 // 1 bit per pixel
  register uint8_t *pBuf = &buffer[(x >> 3) + (y * (SSD1322_LCDWIDTH / 8))];
  switch (gscale)
  {
    case WHITE: *pBuf |=  (0x80 >> (x%8)); break;
    case BLACK: *pBuf &= ~(0x80 >> (x%8)); break;
    case INVERSE: *pBuf ^=  (0x80 >> (x%8)); break;
  }
#endif
}


#if 0
int SSD1322_DrawUnicode(unsigned int uniCode, int x, int y, int size)
{
  uint16_t rowData;
  uint8_t  pixelData;

  for (uint8_t col = 0; col < 11; col++)
  {
    //rowData = falconDedFont[col];
    rowData = falconDedFont[uniCode][col];

    for (int8_t row = 4; row >= 0; row--)
    {
      pixelData   = rowData & 0x1 ? 0x0F : 0x00;
      pixelData  |= rowData & 0x2 ? 0xF0 : 0x00;
      rowData   >>= 2;

      //character[col][row] = pixelData;
      buffer[((y + col) * 128) + ((x / 2) + row)] = pixelData;
    }
  }

  return 1;
}
#elif 0
int SSD1322_DrawUnicode(unsigned int uniCode, int x, int y, uint8_t invert)
{
  uint16_t rowData;
  uint8_t  pixelMask;
  uint8_t  pixelValue = 0xFF;

  for (uint8_t row = 0; row < 9; row++)
  {
    //rowData = falconDedFont_Normal[uniCode][row];
    // 0-9
    if ((uniCode >= 0x30) && (uniCode <= 0x39))
    {
      rowData = falconDedFont_Numbers_Normal[uniCode - 0x30][row];
    }
    // A-Z
    else if ((uniCode >= 0x41) && (uniCode <= 0x5A))
    {
      rowData = falconDedFont_Letters_Normal[uniCode - 0x41][row];
    }
    // Specials
    else
    {
      switch(uniCode)
      {
        //case '\0000':
        case 0x00:
        {
          rowData = falconDedFont_Specials_Normal[0][row];
        }
        break;

        default:
        {
          return 0;
        }
      }
    }

    for (int8_t col = 0; col < 8; col++)
    {
      pixelMask = ((x + col) % 2 == 0) ? 0xF0 : 0x0F;

      // Clear pixel
      buffer[((y + row) * 128) + ((x + col) / 2)] &= ~pixelMask;

      // Set pixel
      if (rowData & 0x40)
      {
        buffer[((y + row) * 128) + ((x + col) / 2)] |= (pixelValue & pixelMask);
      }
      rowData <<= 1;
    }
  }

  return 1;
}
#elif 0
int SSD1322_DrawUnicode(unsigned int uniCode, int x, int y, uint8_t invert)
{
  uint16_t rowData;
  uint8_t  pixelMask;
  uint8_t  pixelValue = 0xFF;

  for (uint8_t row = 0; row < 11; row++)
  {
    // 0-9
    if ((uniCode >= 0x30) && (uniCode <= 0x39))
    {
      rowData = falconDedFont_Numbers_Normal[uniCode - 0x30][row];
    }
    // A-Z
    else if ((uniCode >= 0x41) && (uniCode <= 0x5A))
    {
      rowData = falconDedFont_Letters_Normal[uniCode - 0x41][row];
    }
    // Specials
    else
    {
      switch(uniCode)
      {
        //case '\0000':
        case 0x00:
        {
          rowData = falconDedFont_Specials_Normal[0][row];
        }
        break;

        case 0x01:
        {
          rowData = falconDedFont_Specials_Normal[1][row];
        }
        break;

        default:
        {
          return 0;
        }
      }
    }

    rowData = invert ? ~rowData : rowData;

    for (int8_t col = 0; col < 8; col++)
    {
      pixelMask = ((x + col) % 2 == 0) ? 0xF0 : 0x0F;

      // Clear pixel
      buffer[((y + row) * 128) + ((x + col) / 2)] &= ~pixelMask;

      // Set pixel
      if (rowData & 0x80)
      {
        buffer[((y + row) * 128) + ((x + col) / 2)] |= (pixelValue & pixelMask);
      }
      rowData <<= 1;
    }
  }

  return 1;
}
#elif 0
int SSD1322_DrawUnicode(unsigned int uniCode, int x, int y, uint8_t invert)
{
  uint16_t rowData;
  uint8_t  pixelMask;
  uint8_t  pixelValue = 0xFF;

  for (uint8_t row = 0; row < 11; row++)
  {
    // Characters between (and including) 33 and 95
    if ((uniCode >= 33) && (uniCode <= 95))
    {
      rowData = falconDedFont_33_95_Normal[uniCode - 33][row];
      invert = 0;
    }
    // Characters between (and including) 97 and 122
    else if ((uniCode >= 97) && (uniCode <= 122))
    {
      rowData = falconDedFont_33_95_Normal[uniCode - 65][row];
      invert = 1;
    }
    // Characters between (and including) 123 and 125
    else if ((uniCode >= 123) && (uniCode <= 125))
    {
      rowData = falconDedFont_123_125_Normal[uniCode - 123][row];
      invert = 0;
    }
    // Specials
    else
    {
      switch(uniCode)
      {
        case 160:
        {

        }
        break;

        case 161:
        {

        }
        break;

        case 162:
        {

        }
        break;

        case 163:
        {

        }
        break;

        case 164:
        {

        }
        break;

        case 166:
        {

        }
        break;

        case 168:
        {

        }
        break;

        case 169:
        {

        }
        break;

        default:
        {
          return 0;
        }
        break;
      }
    }

    rowData = invert ? ~rowData : rowData;

    for (int8_t col = 0; col < 8; col++)
    {
      pixelMask = ((x + col) % 2 == 0) ? 0xF0 : 0x0F;

      // Clear pixel
      buffer[((y + row) * 128) + ((x + col) / 2)] &= ~pixelMask;

      // Set pixel
      if (rowData & 0x80)
      {
        buffer[((y + row) * 128) + ((x + col) / 2)] |= (pixelValue & pixelMask);
      }
      rowData <<= 1;
    }
  }

  return 1;
}
#else
int SSD1322_DrawUnicode(unsigned int uniCode, int x, int y, uint8_t invert)
{
  uint16_t rowData;
  uint8_t  pixelMask;
  uint8_t  pixelValue = 0xFF;
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

  for (uint8_t row = 0; row < 11; row++)
  {
    rowData = *pCharacter;

    for (int8_t col = 0; col < 9; col++)
    {
      pixelMask = ((x + col) % 2 == 0) ? 0xF0 : 0x0F;

      // Clear pixel
      buffer[((y + row) * 128) + ((x + col) / 2)] &= ~pixelMask;

      // Set pixel
      if (rowData & 0x100)
      {
        buffer[((y + row) * 128) + ((x + col) / 2)] |= (pixelValue & pixelMask);
      }
      rowData <<= 1;
    }

    pCharacter++;
  }

  return 1;
}
#endif


int SSD1322_DrawChar(char c, int x, int y, int size)
{

}


#if 0
int SSD1322_DrawChar(char c, int x, int y, int size)
{
//#ifdef LOAD_GLCD
  // Use Adafruit font 5x7
  if (size == 0)
  {
     setCursor(x, y);
     return  print(c);
  }
//#endif
  int retVal = drawUnicode(c, x, y, size);

  return retVal;
}
#endif


#if 0
int ESP8266_SSD1322::drawString(char *string, int poX, int poY, int size)
{
//Serial.println("drawString:E");
#ifdef LOAD_GLCD
  // Use Adafruit font 5x7
  if (size == 0)
  {
    setCursor(poX, poY);
    print(string);
    return 0;
  }
#endif
  int sumX = 0;

  while(*string)
  {
    int xPlus = drawChar(*string, poX, poY, size);
    sumX += xPlus;
    string++;
    poX += xPlus;                            /* Move cursor right       */
  }
//Serial.print("drawString:x:");
//Serial.println(sumX);
  return sumX;
}
#endif


#if 0
void SSD1322_DrawFastHorizontalLineInternal(int16_t x, int16_t y, int16_t w, uint16_t color)
{
  // Do bounds/limit checks
  if (y < 0 || y >= HEIGHT) {
    return;
  }

  // Make sure we don't try to draw below 0
  if (x < 0)
  {
    w += x;
    x = 0;
  }

  // Make sure we don't go off the edge of the display
  if ((x + w) > WIDTH)
  {
    w = (WIDTH - x);
  }

  // If our width is now negative, punt
  if (w <= 0)
  {
    return;
  }

  // set up the pointer for  movement through the buffer
#ifdef SSD1322_256_64_4

  // adjust the buffer pointer for the current row
  register uint8_t *pBuf = buffer;
  pBuf += (x >> 1) + (y * (SSD1322_LCDWIDTH / 2));

  register uint8_t oddmask = color;
  register uint8_t evenmask = (color << 4);
  register uint8_t fullmask = (color << 4) + color;
  uint8_t byteLen = w / 2;

  if (((x % 2) == 0) && ((w % 2) == 0))  // Start at even and length is even
  {
    while (byteLen--)
    {
      *pBuf++ = fullmask;
    }

    return;
  }

  if (((x % 2) == 1) && ((w % 2) == 1)) // Start at odd and length is odd
  {
    register uint8_t b1 = *pBuf;
    b1 &= (x % 2) ? 0xF0 : 0x0F; // cleardown nibble to be replaced

    // write our value in
    *pBuf++ = b1 | oddmask;

    while (byteLen--)
    {
      *pBuf++ = fullmask;
    }
    return;
  }

  if (((x % 2) == 0) && ((w % 2) == 1)) // Start at even and length is odd
  {
    while (byteLen--)
    {
      *pBuf++ = fullmask;
    }

    register uint8_t b1 = *pBuf;
    b1 &= 0x0F; // cleardown nibble to be replaced

    // write our value in
    *pBuf++ = b1 | evenmask;
    return;
  }

  if (((x % 2) == 1) && ((w % 2) == 0)) // Start at odd and length is even
  {
    register uint8_t b1 = *pBuf;
    b1 &= (x % 2) ? 0xF0 : 0x0F; // cleardown nibble to be replaced

    // write our value in
    *pBuf++ = b1 | oddmask;

    while (byteLen--)
    {
      *pBuf++ = fullmask;
    }

    b1 = *pBuf;
    b1 &= 0x0F; // cleardown nibble to be replaced

    // write our value in
    *pBuf++ = b1 | evenmask;
    return;
  }
#endif
#ifdef SSD1322_256_64_1
  register uint8_t *pBuf = &buffer[(x >> 3) + (y * (SSD1322_LCDWIDTH / 8))];
  // do the first partial byte, if necessary - this requires some masking
  register uint8_t mod = (x % 8);

//Serial.println("** START ***");
//Serial.print("mod=");
//Serial.println(mod);
  if (mod)
  {
    // mask off the high n bits we want to set
    mod = 8-mod;

//Serial.print("mod=");
//Serial.println(mod);
    // note - lookup table results in a nearly 10% performance improvement in fill* functions
    // register uint8_t mask = ~(0xFF >> (mod));
    static uint8_t premask[8] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F };
    register uint8_t mask = premask[mod];

    // adjust the mask if we're not going to reach the end of this byte
    if( w < mod)
    {
//Serial.println("here 2");
      mask &= (0XFF << (mod - w));
//Serial.print("mask=");
//Serial.println((int)mask);
    }

    switch (color)
    {
      case WHITE:   *pBuf |=  mask;  break;
      case BLACK:   *pBuf &= ~mask;  break;
      case INVERSE: *pBuf ^=  mask;  break;
    }

    // fast exit if we're done here!
    if(w < mod)
    {
      return;
    }

    w -= mod;

    // adjust the buffer forward
    pBuf++;
  }


  // write solid bytes while we can - effectively doing 8 rows at a time
  if (w >= 8)
  {
    if (color == INVERSE)
    {          // separate copy of the code so we don't impact performance of the black/white write version with an extra comparison per loop
      do
      {
        *pBuf=~(*pBuf);

        // adjust the buffer forward
        pBuf++;

        // adjust h & y (there's got to be a faster way for me to do this, but this should still help a fair bit for now)
        w -= 8;
        } while(w >= 8);
    }
    else
    {
//Serial.println("here 1");
      // store a local value to work with
      register uint8_t val = (color == WHITE) ? 255 : 0;

      do
      {
//Serial.print("w=");
//Serial.println(w);
        // write our value in
        *pBuf = val;

        // adjust the buffer forward
        pBuf++;

        // adjust h & y (there's got to be a faster way for me to do this, but this should still help a fair bit for now)
        w -= 8;
      } while(w >= 8);
    }
  }

  // now do the final partial byte, if necessary
  if (w)
  {
    mod = w % 8;
//Serial.print("w%8=");
//Serial.println(mod);
    // this time we want to mask the low bits of the byte, vs the high bits we did above
    // register uint8_t mask = (1 << mod) - 1;
    // note - lookup table results in a nearly 10% performance improvement in fill* functions
    static uint8_t postmask[8] = {0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE };
    register uint8_t mask = postmask[mod];
    switch (color)
    {
      case WHITE:   *pBuf |=  mask;  break;
      case BLACK:   *pBuf &= ~mask;  break;
      case INVERSE: *pBuf ^=  mask;  break;
    }
  }
#endif

}
#endif
