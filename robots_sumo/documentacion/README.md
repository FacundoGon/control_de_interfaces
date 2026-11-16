# Links de pinout
## Puente h: https://forum.arduino.cc/t/puente-h-l298n-no-funciona-como-deberia/1007524/5
## Raspberry pi pico w: https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html
# Explicaciones
## Puente H: un puente H invierte la polaridad aplicada al motor para cambiar el sentido de giro. Mediante la combinación adecuada de cuatro interruptores electrónicos, puede hacer que el motor avance, retroceda,o se detenga, y si se combina con una señal PWM, también permite controlar su velocidad. Es uno de los circuitos fundamentales en robótica, automatización y control de motores
## Porta Pilas: un porta pilas no modifica la electricidad ni controla el circuito, unicamente proporciona una forma segura y práctica de conectar una o varias pilas a un dispositivo, asegurando el contacto eléctrico y la polaridad correcta de este 
# imagenes 
# Links de Modelaje 3D
## Tutorial de modelaje 3D en TinkerCad: https://youtu.be/h1whQ4swb-E?si=TpErBmOfd9v8LY6O
# Investigaciones sobre PWM, ENA y ENB
## Para controlar la velocidad de giro de los motores tenemos que quitar los jumpers y usar los pines ENA y ENB. Los conectaremos a dos salidas PWM de la Raspberry. Todos los 26 pines GPIO (del GP0 al GP25) de la Raspberry Pi Pico W son compatibles con PWM.
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

## Armado sobre la base
Después de realizar las pruebas en protoboard, se montaron los
componentes sobre la base del robot y se realizaron las conexiones
correspondientes.
![Armado del robot sobre la base](https://github.com/user-attachments/assets/054d971a-9bd5-43bc-bd63-7075de77f29a)

![Vista inferior del armado sobre la base](https://github.com/user-attachments/assets/391087be-62d3-46dd-99a0-27a95633a231)
