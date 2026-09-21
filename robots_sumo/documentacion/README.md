# Links de pinout
## Puente h: https://forum.arduino.cc/t/puente-h-l298n-no-funciona-como-deberia/1007524/5
## Raspberry pi pico w: https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html
# Explicaciones
## Puente H: un puente H invierte la polaridad aplicada al motor para cambiar el sentido de giro. Mediante la combinación adecuada de cuatro interruptores electrónicos, puede hacer que el motor avance, retroceda, se detenga o frene, y si se combina con una señal PWM, también permite controlar su velocidad. Es uno de los circuitos fundamentales en robótica, automatización y control de motores
## Porta Pilas: un porta pilas no modifica la electricidad ni controla el circuito, unicamente proporciona una forma segura y práctica de conectar una o varias pilas a un dispositivo, asegurando el contacto eléctrico y la polaridad correcta de este 
# imagenes 
# Links de Modelaje 3D
## Tutorial de modelaje 3D en TinkerCad: https://youtu.be/h1whQ4swb-E?si=TpErBmOfd9v8LY6O
# Investigaciones sobre PWM, ENA y ENB
## Para controlar la velocidad de giro de los motores tenemos que quitar los jumpers y usar los pines ENA y ENB. Los conectaremos a dos salidas PWM de la Raspberry. Todos los 26 pines GPIO (del GP0 al GP25) de la Raspberry Pi Pico W son compatibles con PWM.
