#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"


// definir constantes con los pines/puertos que irán conectados al puente h
#define ENA1 1
#define ENA2 2
#define ENA3 3
#define ENA4 4
#define PWMA 6
#define PWMB 7


// Funciones

void Avanzar() {
    gpio_put(ENA1, 0);
    gpio_put(ENA2, 1);

    gpio_put(ENA3, 0);
    gpio_put(ENA4, 1);
}
void Retroceder() {
    gpio_put(ENA1, 1);
    gpio_put(ENA2, 0);

    gpio_put(ENA3, 1);
    gpio_put(ENA4, 0);
}
void Girar_Derecha() {
    gpio_put(ENA1, 1);
    gpio_put(ENA2, 0);

    gpio_put(ENA3, 0);
    gpio_put(ENA4, 1);
}
void Girar_Izquierda() {
    gpio_put(ENA1, 0);
    gpio_put(ENA2, 1);

    gpio_put(ENA3, 1);
    gpio_put(ENA4, 0);
}
void Frenar() {

}

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
    gpio_init(PWMA);
    gpio_init(PWMB);

    gpio_set_dir(ENA1, GPIO_OUT);
    gpio_set_dir(ENA2, GPIO_OUT);
    gpio_set_dir(ENA3, GPIO_OUT);
    gpio_set_dir(ENA4, GPIO_OUT);
    gpio_set_function(PWMA, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWMA);
    gpio_set_function(PWMB, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWMB);
    

  while (true) {
        // Go Forward
        if (true){
            Avanzar();
        }

        // Turn Right
        if (false){
            Girar_Derecha();
        }

        // Turn Left
        if (false){
            Girar_Izquierda();
        }

        // Go Backward
        if (false){
            Retroceder();
        }
  }
  return 0;
}