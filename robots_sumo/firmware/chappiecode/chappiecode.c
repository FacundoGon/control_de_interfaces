#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

// definir constantes con los pines/puertos que irán conectados al puente h

//#define ENA 7


int main()
{
    stdio_init_all();

    // Initializing and setting pins
    gpio_init(1);
    gpio_init(2);
    gpio_init(3);
    gpio_init(4);

    gpio_set_dir(1, GPIO_OUT);
    gpio_set_dir(2, GPIO_OUT);
    gpio_set_dir(3, GPIO_OUT);
    gpio_set_dir(4, GPIO_OUT);

    /*
    // Initialise the Wi-Fi chip
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    // Enable wifi station
    cyw43_arch_enable_sta_mode();

    printf("Connecting to Wi-Fi...\n");
    if (cyw43_arch_wifi_connect_timeout_ms("Your Wi-Fi SSID", "Your Wi-Fi Password", CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        printf("failed to connect.\n");
        return 1;
    } else {
        printf("Connected.\n");
        // Read the ip address in a human readable way
        uint8_t *ip_address = (uint8_t*)&(cyw43_state.netif[0].ip_addr.addr);
        printf("IP address %d.%d.%d.%d\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
    }
*/
    while (true) {
        // Go Forward
        if (true){
            gpio_put(1, 0);
            gpio_put(2, 1);

            gpio_put(3, 0);
            gpio_put(4, 1);
        }

        // Turn Right
        if (false){
            gpio_put(1, 1);
            gpio_put(2, 0);

            gpio_put(3, 0);
            gpio_put(4, 1);
        }

        // Turn Left
        if (true){
            gpio_put(1, 0);
            gpio_put(2, 1);

            gpio_put(3, 1);
            gpio_put(4, 0);
        }

        // Go Backward
        if (true){
            gpio_put(1, 1);
            gpio_put(2, 0);

            gpio_put(3, 1);
            gpio_put(4, 0);
        }
    }
}
