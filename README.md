# Hades
Land based exploration vehicle

### H-Bridge CTRL
PWM adapter for Pix to H-Bridge control of the brushed motor. 
The problem this software resolves is that the H-Bridge expects PWM on one of two inputs: forward IN and backward IN
Pix Flight Controller outputs only one throttle PWM zeroed at 1.5ms. 1.0 for full backward. 2.0ms for full forward
This software takes the PIX input and converts to two discrete outputs connected to the H-Bridge.


