/*
    __mpuimu_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__mpuimu_driver.h"
#include "__mpuimu_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __MPUIMU_DRV_I2C__
static uint8_t _slaveAddress;
#endif

// Register Address Map
const uint8_t    _MPUIMU_SELF_TEST_X       = 0x0D;
const uint8_t    _MPUIMU_SELF_TEST_Y       = 0x0E;
const uint8_t    _MPUIMU_SELF_TEST_Z       = 0x0F;
const uint8_t    _MPUIMU_SELF_TEST_A       = 0x10;
const uint8_t    _MPUIMU_SMPLRT_DIV        = 0x19;
const uint8_t    _MPUIMU_CONFIG            = 0x1A;
const uint8_t    _MPUIMU_GYRO_CONFIG       = 0x1B;
const uint8_t    _MPUIMU_ACCEL_CONFIG      = 0x1C;
const uint8_t    _MPUIMU_MOT_THR           = 0x1F;
const uint8_t    _MPUIMU_FIFO_EN           = 0x23;
const uint8_t    _MPUIMU_I2C_MST_CTRL      = 0x24;
const uint8_t    _MPUIMU_I2C_SLV0_ADDR     = 0x25;
const uint8_t    _MPUIMU_I2C_SLV0_REG      = 0x26;
const uint8_t    _MPUIMU_I2C_SLV0_CTRL     = 0x27;
const uint8_t    _MPUIMU_I2C_SLV1_ADDR     = 0x28;
const uint8_t    _MPUIMU_I2C_SLV1_REG      = 0x29;
const uint8_t    _MPUIMU_I2C_SLV1_CTRL     = 0x2A;
const uint8_t    _MPUIMU_I2C_SLV2_ADDR     = 0x2B;
const uint8_t    _MPUIMU_I2C_SLV2_REG      = 0x2C;
const uint8_t    _MPUIMU_I2C_SLV2_CTRL     = 0x2D;
const uint8_t    _MPUIMU_I2C_SLV3_ADDR     = 0x2E;
const uint8_t    _MPUIMU_I2C_SLV3_REG      = 0x2F;
const uint8_t    _MPUIMU_I2C_SLV3_CTRL     = 0x30;
const uint8_t    _MPUIMU_I2C_SLV4_ADDR     = 0x31;
const uint8_t    _MPUIMU_I2C_SLV4_REG      = 0x32;
const uint8_t    _MPUIMU_I2C_SLV4_DO       = 0x33;
const uint8_t    _MPUIMU_I2C_SLV4_CTRL     = 0x34;
const uint8_t    _MPUIMU_I2C_SLV4_DI       = 0x35;
const uint8_t    _MPUIMU_I2C_MST_STATUS    = 0x36;
const uint8_t    _MPUIMU_INT_PIN_CFG       = 0x37;
const uint8_t    _MPUIMU_INT_ENABLE        = 0x38;
const uint8_t    _MPUIMU_INT_STATUS        = 0x3A;
const uint8_t    _MPUIMU_RAW_ACCEL         = 0x3B;
const uint8_t    _MPUIMU_ACCEL_XOUT_H      = 0x3B;
const uint8_t    _MPUIMU_ACCEL_XOUT_L      = 0x3C;
const uint8_t    _MPUIMU_ACCEL_YOUT_H      = 0x3D;
const uint8_t    _MPUIMU_ACCEL_YOUT_L      = 0x3E;
const uint8_t    _MPUIMU_ACCEL_ZOUT_H      = 0x3F;
const uint8_t    _MPUIMU_ACCEL_ZOUT_L      = 0x40;
const uint8_t    _MPUIMU_TEMP_OUT_H        = 0x41;
const uint8_t    _MPUIMU_TEMP_OUT_L        = 0x42;
const uint8_t    _MPUIMU_RAW_GYRO          = 0x43;
const uint8_t    _MPUIMU_GYRO_XOUT_H       = 0x43;
const uint8_t    _MPUIMU_GYRO_XOUT_L       = 0x44;
const uint8_t    _MPUIMU_GYRO_YOUT_H       = 0x45;
const uint8_t    _MPUIMU_GYRO_YOUT_L       = 0x46;
const uint8_t    _MPUIMU_GYRO_ZOUT_H       = 0x47;
const uint8_t    _MPUIMU_GYRO_ZOUT_L       = 0x48;
const uint8_t    _MPUIMU_EXT_SENS_DATA_00  = 0x49;
const uint8_t    _MPUIMU_EXT_SENS_DATA_01  = 0x4A;
const uint8_t    _MPUIMU_EXT_SENS_DATA_02  = 0x4B;
const uint8_t    _MPUIMU_EXT_SENS_DATA_03  = 0x4C;
const uint8_t    _MPUIMU_EXT_SENS_DATA_04  = 0x4D;
const uint8_t    _MPUIMU_EXT_SENS_DATA_05  = 0x4E;
const uint8_t    _MPUIMU_EXT_SENS_DATA_06  = 0x4F;
const uint8_t    _MPUIMU_EXT_SENS_DATA_07  = 0x50;
const uint8_t    _MPUIMU_EXT_SENS_DATA_08  = 0x51;
const uint8_t    _MPUIMU_EXT_SENS_DATA_11  = 0x54;
const uint8_t    _MPUIMU_EXT_SENS_DATA_09  = 0x52;
const uint8_t    _MPUIMU_EXT_SENS_DATA_10  = 0x53;
const uint8_t    _MPUIMU_EXT_SENS_DATA_12  = 0x55;
const uint8_t    _MPUIMU_EXT_SENS_DATA_13  = 0x56;
const uint8_t    _MPUIMU_EXT_SENS_DATA_14  = 0x57;
const uint8_t    _MPUIMU_EXT_SENS_DATA_15  = 0x58;
const uint8_t    _MPUIMU_EXT_SENS_DATA_16  = 0x59;
const uint8_t    _MPUIMU_EXT_SENS_DATA_17  = 0x5A;
const uint8_t    _MPUIMU_EXT_SENS_DATA_18  = 0x5B;
const uint8_t    _MPUIMU_EXT_SENS_DATA_19  = 0x5C;
const uint8_t    _MPUIMU_EXT_SENS_DATA_20  = 0x5D;
const uint8_t    _MPUIMU_EXT_SENS_DATA_21  = 0x5E;
const uint8_t    _MPUIMU_EXT_SENS_DATA_22  = 0x5F;
const uint8_t    _MPUIMU_EXT_SENS_DATA_23  = 0x60;
const uint8_t    _MPUIMU_I2C_SLV0_DO       = 0x63;
const uint8_t    _MPUIMU_I2C_SLV1_DO       = 0x64;
const uint8_t    _MPUIMU_I2C_SLV2_DO       = 0x65;
const uint8_t    _MPUIMU_I2C_SLV3_DO       = 0x66;
const uint8_t    _MPUIMU_I2C_MST_DELAY_CT  = 0x67;
const uint8_t    _MPUIMU_SIGNAL_PATH_RES   = 0x68;
const uint8_t    _MPUIMU_MOT_DETECT_CTRL   = 0x69;
const uint8_t    _MPUIMU_USER_CTRL         = 0x6A;
const uint8_t    _MPUIMU_PWR_MGMT_1        = 0x6B;
const uint8_t    _MPUIMU_PWR_MGMT_2        = 0x6C;
const uint8_t    _MPUIMU_FIFO_COUNTH       = 0x72;
const uint8_t    _MPUIMU_FIFO_COUNTL       = 0x73;
const uint8_t    _MPUIMU_FIFO_R_W          = 0x74;
const uint8_t    _MPUIMU_WHO_AM_I          = 0x75;  // default 0x68
const uint8_t    _MPUIMU_I2C_ADDR_0        = 0xD2;
const uint8_t    _MPUIMU_I2C_ADDR_1        = 0x69;

// Register Control
const uint8_t    _MPUIMU_PWR_CONFIG        = 0x80;
const uint8_t    _MPUIMU_PWR_SET           = 0x00;
const uint8_t    _MPUIMU_FIFO_EN_CONFIG    = 0x78;
const uint8_t    _MPUIMU_INT_ENABLE_CONFIG = 0x10;


/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __MPUIMU_DRV_SPI__

void mpuimu_spiDriverInit(T_MPUIMU_P gpioObj, T_MPUIMU_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __MPUIMU_DRV_I2C__

void mpuimu_i2cDriverInit(T_MPUIMU_P gpioObj, T_MPUIMU_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __MPUIMU_DRV_UART__

void mpuimu_uartDriverInit(T_MPUIMU_P gpioObj, T_MPUIMU_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif


/* ----------------------------------------------------------- IMPLEMENTATION */


/* Generic write data function */
void mpuimu_writeData( uint8_t address, uint8_t writeCommand )
{
    uint8_t buffer[2];
    buffer[0]= address;
    buffer[1]= writeCommand;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, buffer, 2, END_MODE_STOP );
}

/* Generic read data function */
uint8_t mpuimu_readData( uint8_t address )
{
    uint8_t writeReg[1];
    uint8_t readReg[1];

    writeReg[0] = address;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, writeReg, 1, END_MODE_RESTART );
    Delay_100ms();
    hal_i2cRead( _slaveAddress, readReg, 1, END_MODE_STOP );
    Delay_100ms();

    return readReg[0];
}

/* Function get data from two MPU-6000 register */
int16_t mpuimu_getAxis( uint8_t adrRegHigh )
{
    uint16_t result;
    uint8_t buffer[2];

    buffer[0] = mpuimu_readData( adrRegHigh );
    buffer[1] = mpuimu_readData( adrRegHigh + 1 );

    result = buffer[0];
    result <<= 8;
    result |= buffer[1];

    return result;
}

/* Function read Gyro X-axis, Y-axis and Z-axis axis */
void mpuimu_readGyro( int16_t *gyroX, int16_t *gyroY, int16_t *gyroZ )
{
    *gyroX = mpuimu_getAxis( _MPUIMU_GYRO_XOUT_H );
    *gyroY = mpuimu_getAxis( _MPUIMU_GYRO_YOUT_H );
    *gyroZ = mpuimu_getAxis( _MPUIMU_GYRO_ZOUT_H );
}

/* Function read Accel X-axis, Y-axis and Z-axis */
void mpuimu_readAccel( int16_t *accelX, int16_t *accelY, int16_t *accelZ )
{
    *accelX = mpuimu_getAxis( _MPUIMU_ACCEL_XOUT_H );
    *accelY = mpuimu_getAxis( _MPUIMU_ACCEL_YOUT_H );
    *accelZ = mpuimu_getAxis( _MPUIMU_ACCEL_ZOUT_H );
}

/* Function read temperature data */
float mpuimu_readTemperature()
{
    int16_t result;
    uint8_t buffer[2];
    float temperature;

    buffer[0] = mpuimu_readData( _MPUIMU_TEMP_OUT_H );
    buffer[1] = mpuimu_readData(  _MPUIMU_TEMP_OUT_L );

    result = buffer[0];
    result <<= 8;
    result |= buffer[1];
    
    temperature =  ( float ) result;
    temperature = temperature / 340;
    temperature += 36.54;

    return temperature;
}




/* -------------------------------------------------------------------------- */
/*
  __mpuimu_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */