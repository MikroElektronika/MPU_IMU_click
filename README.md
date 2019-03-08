![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# MPU_IMU Click

---

- **CIC Prefix**  : MPUIMU
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Aug 2018.

---

### Software Support

We provide a library for the MPU_IMU Click on our [LibStock](https://libstock.mikroe.com/projects/view/1002/mpu-imu-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control and read X, Y & Z axis accel, gyro coordinates and temperatuer data from MPU IMU Click .

Key functions :

- ``` void mpuimu_readAccel( int16_t *accelX, int16_t *accelY, int16_t *accelZ ) ``` - Function read Accel X-axis, Y-axis and Z-axis
- ``` void mpuimu_readGyro( int16_t *gyroX, int16_t *gyroY, int16_t *gyroZ ) ``` - Function read Gyro X-axis, Y-axis and Z-axis axis
- ``` float mpuimu_readTemperature() ``` - Function read temperature data

**Examples Description**

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C, set INT pin as input.
- Application Initialization - Initialization driver enable's - I2C, initialize MPU-6000 and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of MPU IMU Click board.
     Measured accel and gyro coordinates (X,Y,Z) and temperature in degrees C are being sent to the uart where you can track their changes.
     All data logs on usb uart for every 1 sec.


```.c

void applicationTask()
{
    mpuimu_readAccel( &accelX, &accelY, &accelZ );
    Delay_100ms();
    mpuimu_readGyro(  &gyroX,  &gyroY, &gyroZ );
    Delay_100ms();
    temperature = mpuimu_readTemperature();
    Delay_100ms();

    mikrobus_logWrite( " Accel X :", _LOG_TEXT );
    IntToStr( accelX, logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( "  |  ", _LOG_TEXT );
    mikrobus_logWrite( " Gyro X :", _LOG_TEXT );
    IntToStr( gyroX, logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( "  *", _LOG_TEXT );
    mikrobus_logWrite( "*****************", _LOG_LINE );

    mikrobus_logWrite( " Accel Y :", _LOG_TEXT );
    IntToStr( accelY, logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( "  |  ", _LOG_TEXT );
    mikrobus_logWrite( " Gyro Y :", _LOG_TEXT );
    IntToStr( gyroY, logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( "  *  ", _LOG_TEXT );
    mikrobus_logWrite( "Temp.:", _LOG_TEXT );
    IntToStr( temperature, logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( "° *  ", _LOG_LINE );

    mikrobus_logWrite( " Accel Z :", _LOG_TEXT );
    IntToStr( accelZ, logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( "  |  ", _LOG_TEXT );
    mikrobus_logWrite( " Gyro Z :", _LOG_TEXT );
    IntToStr( gyroZ, logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( "  *", _LOG_TEXT );
    mikrobus_logWrite( "*****************", _LOG_LINE );

    mikrobus_logWrite("---------------------------------------------------------", _LOG_LINE);

    Delay_1sec();
}

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1002/mpu-imu-click-example) page.

Other mikroE Libraries used in the example:

- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
