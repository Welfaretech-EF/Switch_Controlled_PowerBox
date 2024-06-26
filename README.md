# Switch Controlled Power Box
People with motor disabilities might not be able to power on household devices in a usual manner. Solutions do exist, that makes it possible to power on a device, with the control of a switch. However,  these solutions are often quite expensive and less portable, since they often work as a direct link between two power cables.

This project is a cheap and simple approach, for controlling a power outlet remotely with the push of a switch/button.

The box is able to control an RF controlled (On/Off) device, such as a remote-controlled power plug, without the need for wifi or bluetooth.

<img src="https://github.com/Welfaretech-EF/Switch_Controlled_PowerBox/blob/main/Images/Sketch.png" width="512">

# Requirements
* Arduino Nano or similar + USB cable
* 433MHz Transmitter
* 0/1 Switch
* Female 3.5mm socket
* Momentary button

# Assembly
In order to assemble the circuit, the following frizting sketch has been designed
<img src="https://github.com/Welfaretech-EF/Switch_Controlled_PowerBox/blob/main/Images/Fritzing.png" width="512">

# Decoding an RF device
Since every RF device uses different codes, you'll need to decode the signal beforehand and replace the two variables "ON_BITS" and "OFF_BITS" in the Arduino code. There are several tutorials online for decoding, but one example is: https://randomnerdtutorials.com/decode-and-send-433-mhz-rf-signals-with-arduino/

# 3D Printed case
A 3d printable custom case has been designed, enclosing all the electronics. All the stl files can be found in the "3D Models" folder.