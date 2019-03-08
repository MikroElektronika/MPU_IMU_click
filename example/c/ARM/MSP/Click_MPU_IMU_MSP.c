/*
Example for MPU_IMU Click

    Date          : Aug 2018.
    Author        : Nenad Filipovic

Test configuration MSP :
    
    MCU              : MSP432
    Dev. Board       : Clicker 2 for MSP432
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C, set INT pin as input.
- Application Initialization - Initialization driver enable's - I2C, initialize MPU-6000 and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of MPU IMU Click board.
     Measured accel and gyro coordinates (X,Y,Z) and temperature in degrees C are being sent to the uart where you can track their changes.
     All data logs on usb uart for every 1 sec.

Additional Functions :

- UART
- Conversions

*/

#include "Click_MPU_IMU_types.h"
#include "Click_MPU_IMU_config.h"

int16_t accelX;
int16_t accelY;
int16_t accelZ;
int16_t gyroX;
int16_t gyroY;
int16_t gyroZ;
float temperature;
uint8_t temp[2]    = {0};
char logText[ 15 ] = {0};

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_MPUIMU_I2C_CFG[0] );
    mikrobus_logInit( _MIKROBUS2, 9600 );
    Delay_100ms();
}

void applicationInit()
{
    mpuimu_i2cDriverInit( (T_MPUIMU_P)&_MIKROBUS1_GPIO, (T_MPUIMU_P)&_MIKROBUS1_I2C, _MPUIMU_I2C_ADDR_1 );
    Delay_100ms();

    /* Initializes */
    mpuimu_writeData( _MPUIMU_PWR_MGMT_1 , _MPUIMU_PWR_CONFIG );
    Delay_10ms();
    mpuimu_writeData( _MPUIMU_PWR_MGMT_1 , _MPUIMU_PWR_SET );
    Delay_10ms();
    mpuimu_writeData( _MPUIMU_FIFO_EN , _MPUIMU_FIFO_EN_CONFIG );
    Delay_10ms();
    mpuimu_writeData( _MPUIMU_INT_ENABLE , _MPUIMU_INT_ENABLE_CONFIG );
    Delay_10ms();

    mikrobus_logWrite("      Accel            Gyro           Temp. °C",_LOG_LINE);
    mikrobus_logWrite("---------------------------------------------------------", _LOG_LINE);
}

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

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}