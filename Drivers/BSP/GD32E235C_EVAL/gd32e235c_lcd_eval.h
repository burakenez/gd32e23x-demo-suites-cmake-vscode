/*!
    \file  gd32e235_lcd_eval.h
    \brief LCD driver header file

    \version 2025-02-10, V2.4.0, demo for GD32E23x
*/

/*
    Copyright (c) 2025, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/

#ifndef GD32E235_LCD_EVAL_H
#define GD32E235_LCD_EVAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gd32e235c_eval.h"

/* Colors */
#define RED             0xf800
#define GREEN           0x07e0
#define BLUE            0x001f
#define WHITE           0xffff
#define BLACK           0x0000
#define YELLOW          0xFFE0

/* GRAYs */
#define GRAY0           0xEF7D
#define GRAY1           0x8410
#define GRAY2           0x4208

/* PB0 tft cs */
#define LCD_CS_SET      ((uint32_t)(GPIO_BOP(GPIOB) = GPIO_PIN_0))
#define LCD_CS_CLR      ((uint32_t)(GPIO_BC(GPIOB) = GPIO_PIN_0))

/* PB2 tft rs/dc */
#define LCD_RS_SET      ((uint32_t)(GPIO_BOP(GPIOB) = GPIO_PIN_2))
#define LCD_RS_CLR      ((uint32_t)(GPIO_BC(GPIOB) = GPIO_PIN_2))

/* PB1 tft rst */
#define LCD_RST_SET     ((uint32_t)(GPIO_BOP(GPIOB) = GPIO_PIN_1))
#define LCD_RST_CLR     ((uint32_t)(GPIO_BC(GPIOB) = GPIO_PIN_1))

/* lcd init */
void lcd_init(void);
/* clear the lcd */
void lcd_clear(uint16_t color);
/* set the start display point of lcd */
void lcd_set_xy(uint16_t x, uint16_t y);
/* draw a point on the lcd */
void lcd_draw_point(uint16_t x, uint16_t y, uint16_t data);

/* bgr to rgb format conversion */
uint16_t lcd_bgr2rgb(uint16_t c);
/* draw a circle on the lcd */
void lcd_circle_draw(uint16_t x, uint16_t y, uint16_t r, uint16_t fc);
/* draw a line on the LCD */
void lcd_line_draw(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);
/* LCD rectangle draw */
void lcd_rect_draw(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t line_color);
/* LCD box */
void lcd_box(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t bc);
/* LCD box2 */
void lcd_box2(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t mode);
/* draw a rectangle with color on the lcd */
void lcd_rect_color_draw(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t fc);
/* display button down */
void display_button_down(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
/* display button up */
void display_button_up(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
/* draw gbk16 font on the LCD */
void lcd_draw_font_gbk16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, char *s);
/* draw gbk24 font on the LCD */
void lcd_draw_font_gbk24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, char *s);
/* draw num32 font on the LCD */
void lcd_draw_font_num32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint16_t num);

void lcd_region_set(uint16_t StartX, uint16_t StartY, uint16_t EndX, uint16_t EndY);

#ifdef __cplusplus
}
#endif

#endif /* GD32E235_LCD_EVAL_H */

