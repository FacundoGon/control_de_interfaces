# Links de pinout
## Puente h: https://forum.arduino.cc/t/puente-h-l298n-no-funciona-como-deberia/1007524/5
## Raspberry pi pico w: https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html
# Explicaciones
## Puente H
un puente H invierte la polaridad aplicada al motor para cambiar el sentido de giro. Mediante la combinación adecuada de cuatro interruptores electrónicos, puede hacer que el motor avance, retroceda,o se detenga, y si se combina con una señal PWM, también permite controlar su velocidad. Es uno de los circuitos fundamentales en robótica, automatización y control de motores
## Porta Pilas
un porta pilas no modifica la electricidad ni controla el circuito, unicamente proporciona una forma segura y práctica de conectar una o varias pilas a un dispositivo, asegurando el contacto eléctrico y la polaridad correcta de este 
# Links de Modelaje 3D
## Tutorial de modelaje 3D en TinkerCad: https://youtu.be/h1whQ4swb-E?si=TpErBmOfd9v8LY6O
# Investigaciones sobre PWM, ENA y ENB

## PWM: modulación por ancho de pulso

PWM significa **Pulse Width Modulation**, o **modulación por ancho de pulso**. Es una técnica que permite regular la energía entregada a un motor mediante una señal digital que alterna rápidamente entre un nivel alto y uno bajo.

En el robot, la Raspberry Pi Pico W genera la señal de control y el puente H conmuta la alimentación del motor. El motor recibe su energía de las pilas a través del puente H; los GPIO de la Raspberry no alimentan directamente los motores.

### Ciclo de trabajo y frecuencia

El **ciclo de trabajo**, también llamado *duty cycle*, es el porcentaje de cada período durante el cual la señal permanece en nivel alto:

**D (%) = (tiempo en alto / período total) × 100**

La **frecuencia** indica cuántas veces se repite el ciclo por segundo y se mide en hertz (Hz). Para regular la velocidad se puede mantener fija la frecuencia y modificar el ciclo de trabajo.

![Señales PWM con distintos ciclos de trabajo](https://cdn.sparkfun.com/assets/f/9/c/8/a/512e869bce395fbc64000002.JPG)

Imagen: comparación de señales con distintos ciclos de trabajo.

Con un ciclo de trabajo del 0 %, el canal queda deshabilitado. Al subir al 25 %, 50 % o 75 %, aumenta el tiempo durante el cual se acciona el motor. Con el 100 %, el canal permanece habilitado de forma continua.

Por ejemplo, si el período dura 1 ms y la señal está en alto durante 0,25 ms, el ciclo de trabajo es del 25 % y la frecuencia es de 1000 Hz. Si se aumenta el tiempo en alto a 0,75 ms sin cambiar el período, el ciclo de trabajo pasa al 75 %.

Un ciclo de trabajo mayor suele producir una velocidad mayor, pero **50 % de PWM no garantiza la mitad exacta de la velocidad**. También influyen la carga, el rozamiento, las pilas y las pérdidas del puente H. Con valores muy bajos, el motor puede no llegar a arrancar.

## ENA: habilitación del canal A

**ENA** significa *Enable A*. Habilita el canal A del L298N, cuyas salidas son **OUT1 y OUT2**. En esas salidas se conecta uno de los motores. Una señal PWM en ENA permite regular su accionamiento; **IN1 e IN2** seleccionan el sentido de giro.

## ENB: habilitación del canal B

**ENB** significa *Enable B*. Cumple la misma función para el segundo motor, conectado a **OUT3 y OUT4**. Su sentido de giro se selecciona con **IN3 e IN4**. ENA y ENB permiten controlar los dos motores por separado.

En el canal A, ENA regula la habilitación, IN1 e IN2 seleccionan el sentido y OUT1 y OUT2 se conectan al motor. En el canal B se utilizan ENB, IN3 e IN4, y OUT3 y OUT4, respectivamente.

Con Enable en bajo, el canal queda deshabilitado y el motor puede detenerse por inercia. Con Enable en alto y las dos entradas opuestas, gira en uno u otro sentido; con ambas entradas iguales se produce frenado eléctrico. El sentido físico depende de cómo estén conectados los cables del motor.

![Conexiones de ENA, ENB y entradas de dirección en el diseño del robot](https://github.com/user-attachments/assets/17565a6b-efff-4d77-8b82-09dc2a432571)

*Figura: diseño del proyecto. ENA y ENB controlan la habilitación de los canales; IN1 a IN4 determinan el sentido de giro.*

## Aplicación en nuestro robot sumo

En el diseño se asignan **GP6 a ENA** y **GP7 a ENB**. Los GPIO **GP1 a GP4** se utilizan para las entradas de dirección. La masa **GND de la Pico W, del puente H y de la alimentación** debe estar conectada en común para compartir la referencia de las señales.

Para aplicar PWM a los Enable de un módulo L298N típico, se retiran **los jumpers de ENA y ENB**, que normalmente los mantienen habilitados. No deben confundirse con el jumper del regulador de 5 V del módulo, que cumple otra función.

La Pico W dispone de 26 GPIO accesibles: **GP0 a GP22 y GP26 a GP28**. Todos admiten PWM; esto no significa que sus nombres sean GP0 a GP25. El RP2040 tiene 16 canales PWM distribuidos en ocho bloques o *slices*. GP6 y GP7 pertenecen al mismo bloque: pueden tener distintos ciclos de trabajo, aunque comparten la frecuencia, lo cual resulta útil para controlar ambos motores.

Al variar los ciclos de trabajo de ENA y ENB se puede hacer que una rueda gire más rápido que la otra y lograr que el robot doble. Para avanzar, retroceder o girar sobre su eje también se combinan las entradas de dirección.

## Fuentes consultadas

- [Hoja de datos del L298 — STMicroelectronics](https://www.st.com/resource/en/datasheet/l298.pdf).
- [Documentación de Raspberry Pi Pico y Pico W](https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html).
- [API de hardware y PWM del Pico SDK](https://www.raspberrypi.com/documentation/pico-sdk/hardware.html).
- [Ilustración del ciclo de trabajo — SparkFun Learn](https://learn.sparkfun.com/tutorials/pulse-width-modulation/duty-cycle).

# Proyecto: Robot sumo
## Diagrama esquemático del robot
Primero se diseñó un diagrama esquemático del robot para planificar
la distribución de sus partes y la relación entre los distintos
elementos del sistema.
![Diagrama esquemático del robot](https://github.com/user-attachments/assets/8ff9f10b-06f5-4277-8a90-94beb9759bb1)
## Primer diseño del circuito
Luego se realizó un primer diseño del circuito. Este permitió plantear las conexiones iniciales
y analizar cómo se conectarían los componentes.
![Primer diseño del circuito](https://github.com/user-attachments/assets/51e2b6e2-9857-4050-864c-d38aad430201)
## Diagrama del circuito pasado a limpio
A partir del primer diseño del circuito, se elaboró una versión pasada
a limpio, con las conexiones organizadas para facilitar su lectura
y utilizarla como guía durante el armado.
![Diagrama del circuito pasado a limpio](https://github.com/user-attachments/assets/17565a6b-efff-4d77-8b82-09dc2a432571)
## Armado y prueba en protoboard
Se armó el circuito en una protoboard siguiendo el diagrama.
Este montaje permitió probar su funcionamiento y revisar las
conexiones antes de instalarlo sobre la base del robot.
Durante esta etapa se realizaron pruebas para comprobar la respuesta
del circuito y detectar posibles errores de conexión.
Video del armado y la prueba en protoboard:
https://github.com/user-attachments/assets/de9d0876-0a72-4d14-8cde-4501158d515c
