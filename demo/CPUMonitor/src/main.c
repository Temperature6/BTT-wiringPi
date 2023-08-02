#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "ws2812.h"
#include "DevInfo.h"


#define TEMP_HIGH_VAL       60
#define TEMP_HIGH_COLOR     "ff0000"
#define TEMP_MID_VAL        40
#define TEMP_MID_COLOR      "ffff00"
#define TEMP_LOW_COLOR      "00ff00"

#define BG_COLOR            "000000"
#define OCC_HIGH_VAL        60
#define OCC_HIGH_COLOR      "ff8000"
#define OCC_MID_VAL         30
#define OCC_MID_COLOR       "66ccff"
#define OCC_LOW_COLOR       "008200"

float map(float val, float old_min, float old_max, float new_min, float new_max);

int main()
{
    printf("Hello ws2812\n");

    float cpuUsage = 0;
    float cpuTemp = 0;
    
    ws2812_Init();
    ws2812_Show();

    while (1)
    {
        cpuUsage = GetCpuUsage();
        cpuTemp = GetCpuTemp();
        ws2812_Clear();
        ws2812_FillPixel2(1,
                (uint16_t)(map(cpuUsage, 0, 100, 1, 7) + 0.5),
                cpuUsage > OCC_HIGH_VAL ? OCC_HIGH_COLOR : (cpuUsage > OCC_MID_VAL ? OCC_MID_COLOR : OCC_LOW_COLOR));
        ws2812_SetPixel2(0, cpuTemp > TEMP_HIGH_VAL ? TEMP_HIGH_COLOR : (cpuTemp > TEMP_MID_VAL ? TEMP_MID_COLOR : TEMP_LOW_COLOR));
        ws2812_Show();
    }
    
}

float map(float val, float old_min, float old_max, float new_min, float new_max)
{
    float new_val = (val  - old_min) / (old_max - old_min) * (new_max - new_min);
    return new_val > new_max ? new_max : (new_val < new_min ? new_min : new_val);
}
