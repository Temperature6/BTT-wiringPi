#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LED_PIN 13

//gcc -Wall -o IO_TEST main.c -lwiringPi -lpthread

int main(int argc, char** argv)
{
    wiringPiSetup();
    int pin = LED_PIN;
    if (argc == 1)
    {
        printf("Usage: sudo ./IO_TEST {wPi}\r\n");
    }
    else
    {
        pin = atoi(argv[1]);
    }
    printf("Now, testing pin: %d\n", pin);

    pinMode (pin, OUTPUT);
    while (1)
    {
        digitalWrite(pin, HIGH);
        delay (1000);
        digitalWrite(pin, LOW);
        delay (1000);
    }
}
