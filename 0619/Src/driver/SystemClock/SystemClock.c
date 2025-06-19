
#include "SystemClock.h"

void SystemClock_Init() {
    RCC->AHB1ENR |= (1U << 0); // RCC AHB1ENR
    RCC->AHB1ENR |= (1U << 1); // RCC AHB1ENR
    RCC->AHB1ENR |= (1U << 2); // RCC AHB1ENR
}

void delay(int loop) {
    for (int j = 0; j < loop; j++) {
        for (int i = 0; i < 100000; i++) {
        }
    }
}
