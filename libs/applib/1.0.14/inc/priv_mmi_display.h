#ifndef PRIV_MMI_DISPLAY_H
#define PRIV_MMI_DISPLAY_H

#include "mmi_display.h"

#define DEBUG_MMI_DISPLAY           0
#if DEBUG_MMI_DISPLAY
#ifdef TAG
#undef TAG
#endif
#define TAG "mmi_display"
#endif

//---------------------------------------------------------------------------
// Display pixels (32*24)
//---------------------------------------------------------------------------
#define LINEPIX     32
#define FONTPIX     24

/**
 * @brief enum definition of display type
 */
typedef enum
{
    VIEW_TEXT    = 0,   /*!< displays the text content */
    VIEW_PICTURE,       /*!< display image */
    VIEW_PIXS,          /*!< display bitmap */
    VIEW_QRPAYCODE,     /*!< display qr code */
    VIEW_EMPTYRECT,     /*!< emptyrect */
    VIEW_PROGREEBAR     /*!< display the progress bar */
}teDispType;

/**
 * @brief struct definition of timer parameters
 */
typedef struct
{
    unsigned char   flipEnable;
    unsigned char   runing;
    unsigned char   interrupt;
    TIMER_PTR       timer;
    int             time;
    int             timeout;
    DISP_VAlign     line;
    unsigned int    column;
} MMI_TimerParam;

//---------------------------------------------------------------------------
// View define
//---------------------------------------------------------------------------
/**
 * @brief struct definition of View \n
 * used to hold the LCD data
 */
typedef struct
{
    unsigned int  percent;          /*!< percent */
    teDispType  type;               /*!< display type */
    char    *text;                  /*!< display string */
    char    *pData;                 /*!< qrCodeData/pixsData */
    int     bgColor;                /*!< background color of the font */
    int     color;                  /*!< font color */
    int     fontBgColor;            /*!< font */
    unsigned char   fontSize;       /*!< font size */
    unsigned short  width;          /*!< And the width of the rectangular box pictures, qr code, (0, screen width] */
    unsigned short  height;         /*!< Pictures, qr code, rectangular box height, (0, the screen height] */

    DISP_VAlign     alignV;         /*!< The vertical position */
    unsigned int    alignL;         /*!< The level of the relative position */

    int   marginLeft;     /*!< Relative to the left side of the spacing, the unit pixel, don't allow greater than 255 */
    int   marginRight;    /*!< Relative to the right side of the spacing, the unit pixel, don't allow greater than 255 */
    int   marginTop;      /*!< Relative to the top spacing, the unit pixel, don't allow greater than 255 */
    int   marginBottom;   /*!< At the bottom of the relative spacing, unit pixels, don't allow greater than 255 */
}MMI_ViewItem;

MMI_ViewItem *mmi_lcd_addViewItem(void);
void mmi_lcd_getWidthHeight(void);
void mmi_lcd_getXY(MMI_ViewItem *node, unsigned short *x, unsigned short *y, int pixs);
void mmi_lcd_getPictureXY(MMI_ViewItem *node, unsigned short *x, unsigned short *y);
void mmi_lcd_drawPixs(unsigned short x, unsigned short y,
                        unsigned short width, unsigned short height,
                        unsigned short color, const char *pixs);

int mmi_lcd_getLine(DISP_VAlign line);
int mmi_lcd_getNextLine(unsigned int y);

//
void mmi_lcd_getMsgPixs(char* msg, int* pixs);
int mmi_lcd_drawViewNode(MMI_ViewItem *node);
int mmi_lcd_displayEx(tsDispParam *pDispParam, DISP_VAlign line, const char *text);


//---------------------------------------------------------------------------
// global variable
//---------------------------------------------------------------------------
extern unsigned int mmi_width_pix;
extern unsigned int mmi_height_pix;

#endif

