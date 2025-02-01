#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/watchdog.h"
#include "hardware/clocks.h"
#include "hardware/uart.h"

#define LED_RED 13
#define LED_YELLOW 12
#define LED_GREEN 11

volatile int state = 0; // Estado atual do semáforo

// Callback do temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alternar entre os estados do semáforo
    switch (state) {
        case 0: // Vermelho ligado, outros desligados
            gpio_put(LED_RED, 1);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 0);
            state = 1;
            break;
        case 1: // Amarelo ligado, outros desligados
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 1);
            gpio_put(LED_GREEN, 0);
            state = 2;
            break;
        case 2: // Verde ligado, outros desligados
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 1);
            state = 3;
            break;
        case 3: // Volta para o vermelho
            gpio_put(LED_RED, 1);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 0);
            state = 1;
            break;
    }
    return true; // Mantém o timer rodando
}

int main() {
    stdio_init_all();
    
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    while (1) {
        printf("Semáforo funcionando...");
        sleep_ms(1000);
    }
}
