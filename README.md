The contents of this repository contain two simple projects that helped me get more fimiliar with the pico. 

I used the pico sdk as reference for the projects in this repository.

I also used cmake to automate the build of these projects.

The first project involves a GPIO, button, pull-down resistor, and an external LED. 

All these components were connected so that when the button is pressed, the state of the LED is toggeled.

The other projects involved a deeper and stronger understanding of the pico.

I used an external LED for this project. However, the built in LED also works just fine.

PWM is the core concept of this project. I used the built in pwm channels and slices in the pico.

The clock was divided by 12500 to generate a 10 kHz frequency. 

The duty cycle is constantly altered as the pwm signal.

As a result the brightness of the LED is changed.
