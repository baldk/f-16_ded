/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _SSD1322__H_
#define _SSD1322__H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void SSD1322_Initialize(void);
void SSD1322_Reset(void);

void SSD1322_Display(void);
void SSD1322_DrawPixel(int16_t x, int16_t y, uint16_t gscale);
int SSD1322_DrawUnicode(unsigned int uniCode, int x, int y, uint8_t invert);
void SSD1322_Fill(uint8_t fillChar);

/* Private defines -----------------------------------------------------------*/
#define SSD1322_CMD_SETCOMMANDLOCK 				    0xFD
#define SSD1322_CMD_DISPLAYOFF 					      0xAE
#define SSD1322_CMD_DISPLAYON 					      0xAF
#define SSD1322_CMD_SETCLOCKDIVIDER 			    0xB3
#define SSD1322_CMD_SETDISPLAYOFFSET 			    0xA2
#define SSD1322_CMD_SETSTARTLINE 				      0xA1
#define SSD1322_CMD_FUNCTIONSEL 				      0xAB
#define SSD1322_CMD_SETREMAP 					        0xA0
#define SSD1322_CMD_DISPLAYENHANCE 				    0xB4
#define SSD1322_CMD_SETCONTRASTCURRENT 		    0xC1
#define SSD1322_CMD_MASTERCURRENTCONTROL 	    0xC7
#define SSD1322_CMD_SETPHASELENGTH 				    0xB1
#define SSD1322_CMD_DISPLAYENHANCEB 			    0xD1
#define SSD1322_CMD_SETPRECHARGEVOLTAGE 		  0xBB
#define SSD1322_CMD_SETSECONDPRECHARGEPERIOD 	0xB6
#define SSD1322_CMD_SETVCOMH 					        0xBE
#define SSD1322_CMD_NORMALDISPLAY 				    0xA6
#define SSD1322_CMD_INVERSEDISPLAY 				    0xA7
#define SSD1322_CMD_SETMUXRATIO 				      0xCA
#define SSD1322_CMD_SETCOLUMNADDR 				    0x15
#define SSD1322_CMD_SETROWADDR 					      0x75
#define SSD1322_CMD_WRITERAM 					        0x5C
#define SSD1322_CMD_ENTIREDISPLAYON 			    0xA5
#define SSD1322_CMD_ENTIREDISPLAYOFF 			    0xA4
#define SSD1322_CMD_SETGPIO 					        0xB5
#define SSD1322_CMD_EXITPARTIALDISPLAY 			  0xA9
#define SSD1322_CMD_SELECTDEFAULTGRAYSCALE 		0xB9

#define SSD1322_MIN_SEG                       0x1C
#define SSD1322_MAX_SEG                       0x5B

#ifdef __cplusplus
}
#endif

#endif /* _SSD1322__H_ */
