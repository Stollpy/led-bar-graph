#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define HIGH 0
#define LOW 1
#define barPin1 17
#define barPin2 18
#define barPin3 27
#define barPin4 22
#define barPin5 23
#define barPin6 24
#define barPin7 25
#define barPin8 2
#define barPin9 3
#define barPin10 8

int main() {
    if (gpioInitialise() < 0) {
        fprintf(stderr, "pigpio initialisation failed\n");
        return 1;
    }

    int barPins[10] = {
            barPin1,
            barPin2,
            barPin3,
            barPin4,
            barPin5,
            barPin6,
            barPin7,
            barPin8,
            barPin9,
            barPin10
    };

    for (int i = 0; i < 10; ++i) {
        gpioSetMode(barPins[i], PI_OUTPUT);
    }

    while (1) {
        for (int i = 0; i < 10; ++i) {
            printf("Led pin %d ON ... \n", i);
            gpioWrite(barPins[i], HIGH);
            usleep(300000);
        }

        for(int i=10-1;i>-1;i--){
            printf("Led pin %d OFF ... \n", i);
                gpioWrite(barPins[i], LOW);
            usleep(300000);
        }
    }

}
