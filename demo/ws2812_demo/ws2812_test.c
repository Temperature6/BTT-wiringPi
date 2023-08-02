#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "ws2812.h"
//gcc *.c -I. -o ws2812_test -lpthread -lwiringPi && ./ws2812_test

int main()
{
    printf("Hello ws2812\n");
    ws2812_Init();

    int i = 0;
    while (1)
    {
        /* code */
        ws2812_Clear();
        ws2812_SetPixel(i, 255, 0, 0);
        ws2812_SetPixel(i - 1, 0, 255, 0);
        ws2812_SetPixel(i - 2, 0, 0, 255);
        i++;
        if (i >= 11)
        {
            i = 0;
        }
        ws2812_Show();
        usleep(150000);
    }
    
}
