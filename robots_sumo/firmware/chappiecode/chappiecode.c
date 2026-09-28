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
    pwm_set_gpio_level(PWMA, 0);
    pwm_set_gpio_level(PWMB, 0);
}

void velocidad(uint porcentaje) {
    if (porcentaje > 100) {
        porcentaje = 100;
    }

    uint nivel = (65535 * porcentaje) / 100;

    pwm_set_gpio_level(PWMA, nivel);
    pwm_set_gpio_level(PWMB, nivel);
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

    pwm_config config = pwm_get_default_config();

    gpio_set_function(PWMA, GPIO_FUNC_PWM);
    uint slice_numA = pwm_gpio_to_slice_num(PWMA);
    pwm_init(slice_numA, &config, true);
    gpio_set_function(PWMB, GPIO_FUNC_PWM);
    uint slice_numB = pwm_gpio_to_slice_num(PWMB);
    pwm_init(slice_numB, &config, true);
    

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

        // Cambiar Velocidad
        if (true){
            velocidad(50);
        }
        if (false){
            velocidad(100);
        }
  }
  return 0;
}