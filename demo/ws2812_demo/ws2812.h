#ifndef WS2812_H_
#define WS2812_H_
#include <stdint.h>

#define SPI_CHANNEL 0
#define SPI_PORT    0

#define LED_LENGTH  16

void ws2812_Init();
void ws2812_SetPixel(uint16_t index, uint8_t R, uint8_t G, uint8_t B);
void ws2812_FilePixel(uint16_t begIndex, uint16_t endIndex, uint8_t R, uint8_t G, uint8_t B);
void ws2812_Clear();
void ws2812_Show();

#endif //WS2812_H_
