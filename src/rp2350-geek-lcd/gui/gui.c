#include "gui.h"
#include <stdbool.h>
#include "LCD_1in14_V2.h"
#include "GUI_Paint.h"
#include "ImageData.h"

static UWORD imageBuff[LCD_1IN14_V2_HEIGHT * LCD_1IN14_V2_WIDTH * 2];

// todo, implement more elegant getters instead of globals
extern bool txLedValue;
extern bool rxLedValue;
extern bool usbConnectedVal;
extern bool dapConnectedVal;
extern bool dapRunningVal;

void gui_init(uint32_t startScreenDurationMs) {
    sleep_ms(100);

    if (DEV_Module_Init() != 0) {
        return;
    }
    DEV_SET_PWM(0);

    /* LCD Init */
    LCD_1IN14_V2_Init(HORIZONTAL);
    LCD_1IN14_V2_Clear(BLACK);
    DEV_SET_PWM(75);

    // /*1.Create a new image cache named IMAGE_RGB and fill it with white*/
    Paint_NewImage((UBYTE *)imageBuff, LCD_1IN14_V2.WIDTH, LCD_1IN14_V2.HEIGHT, 0, WHITE);
    Paint_SetScale(65);
    Paint_Clear(BLACK);
    Paint_SetRotate(ROTATE_0);
    Paint_Clear(BLACK);

#if 1
    DEV_SET_PWM(0);
    Paint_DrawImage(gImage_1inch14_1, 0, 0, 240, 135);
    LCD_1IN14_V2_Display(imageBuff);
    DEV_SET_PWM(100);
    sleep_ms(startScreenDurationMs);
#endif

    DEV_SET_PWM(50);
}

void gui_run(void) {
    Paint_Clear(BLACK);

    Paint_DrawString_EN(16, 10, "Pico-GEEK-Probe", &Font20, RED, BLACK);

    if (usbConnectedVal) {
        Paint_DrawString_EN(50, 30, "USB Connected", &Font16, GREEN, BLACK);
    } else {
        Paint_DrawString_EN(28, 30, "USB Not Connected", &Font16, RED, BLACK);
    }   

    Paint_DrawString_EN(35, 60, "Debug", &Font16, BLUE, BLACK);
    Paint_DrawString_EN(5, 85, "Conn", &Font16, WHITE, BLACK);
    Paint_DrawCircle(105, 90, 8, GREEN, DOT_PIXEL_1X1, dapConnectedVal ? DRAW_FILL_FULL : DRAW_FILL_EMPTY);
    Paint_DrawString_EN(5, 110, "Run", &Font16, WHITE, BLACK);
    Paint_DrawCircle(105, 115, 8, GREEN, DOT_PIXEL_1X1, dapRunningVal ? DRAW_FILL_FULL : DRAW_FILL_EMPTY);


    Paint_DrawString_EN(145, 60,  "Serial", &Font16, BLUE, BLACK);
    Paint_DrawString_EN(135, 85,  "Tx", &Font16, WHITE, BLACK);
    Paint_DrawCircle(220, 90, 8, YELLOW, DOT_PIXEL_1X1, txLedValue ? DRAW_FILL_FULL : DRAW_FILL_EMPTY);
    Paint_DrawString_EN(135, 110, "RX", &Font16, WHITE, BLACK);
    Paint_DrawCircle(220, 115, 8, YELLOW, DOT_PIXEL_1X1, rxLedValue ? DRAW_FILL_FULL : DRAW_FILL_EMPTY);

    /*3.Refresh the picture in RAM to LCD*/
    LCD_1IN14_V2_Display(imageBuff);
}