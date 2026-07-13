#include <stdio.h>
#include "pico/stdlib.h"

// definir constantes con los pines/puertos que irán conectados al puente h
#define ENA1 1
#define ENA2 2
#define ENA3 3
#define ENA4 4

int main(void) {
  // Inicializo el USB
  stdio_init_all();
  // Demora para esperar la conexion
  sleep_ms(1000);

  // Initializing and setting pins
    gpio_init(ENA1);
    gpio_init(ENA2);
    gpio_init(ENA3);
    gpio_init(ENA4);

    gpio_set_dir(ENA1, GPIO_OUT);
    gpio_set_dir(ENA2, GPIO_OUT);
    gpio_set_dir(ENA3, GPIO_OUT);
    gpio_set_dir(ENA4, GPIO_OUT);

  while (true) {
        // Go Forward
        if (true){
            gpio_put(ENA1, 0);
            gpio_put(ENA2, 1);

            gpio_put(ENA3, 0);
            gpio_put(ENA4, 1);
        }

        // Turn Right
        if (false){
            gpio_put(ENA1, 1);
            gpio_put(ENA2, 0);

            gpio_put(ENA3, 0);
            gpio_put(ENA4, 1);
        }

        // Turn Left
        if (false){
            gpio_put(ENA1, 0);
            gpio_put(ENA2, 1);

            gpio_put(ENA3, 1);
            gpio_put(ENA4, 0);
        }

        // Go Backward
        if (false){
            gpio_put(ENA1, 1);
            gpio_put(ENA2, 0);

            gpio_put(ENA3, 1);
            gpio_put(ENA4, 0);
        }
  }
  return 0;
}