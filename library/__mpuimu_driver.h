/*
    __mpuimu_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __mpuimu_driver.h
@brief    MPU_IMU Driver
@mainpage MPU_IMU Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   MPUIMU
@brief      MPU_IMU Click Driver
@{

| Global Library Prefix | **MPUIMU** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Aug 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _MPUIMU_H_
#define _MPUIMU_H_

/** 
 * @macro T_MPUIMU_P
 * @brief Driver Abstract type 
 */
#define T_MPUIMU_P    const uint8_t*

/** @defgroup MPUIMU_COMPILE Compilation Config */              /** @{ */

//  #define   __MPUIMU_DRV_SPI__                            /**<     @macro __MPUIMU_DRV_SPI__  @brief SPI driver selector */
   #define   __MPUIMU_DRV_I2C__                            /**<     @macro __MPUIMU_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __MPUIMU_DRV_UART__                           /**<     @macro __MPUIMU_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup MPUIMU_VAR Variables */                           /** @{ */

// Register Address Map
extern const uint8_t    _MPUIMU_SELF_TEST_X;
extern const uint8_t    _MPUIMU_SELF_TEST_Y;
extern const uint8_t    _MPUIMU_SELF_TEST_Z;
extern const uint8_t    _MPUIMU_SELF_TEST_A;
extern const uint8_t    _MPUIMU_SMPLRT_DIV;
extern const uint8_t    _MPUIMU_CONFIG;
extern const uint8_t    _MPUIMU_GYRO_CONFIG;
extern const uint8_t    _MPUIMU_ACCEL_CONFIG;
extern const uint8_t    _MPUIMU_MOT_THR;
extern const uint8_t    _MPUIMU_FIFO_EN;
extern const uint8_t    _MPUIMU_I2C_MST_CTRL;
extern const uint8_t    _MPUIMU_I2C_SLV0_ADDR;
extern const uint8_t    _MPUIMU_I2C_SLV0_REG;
extern const uint8_t    _MPUIMU_I2C_SLV0_CTRL;
extern const uint8_t    _MPUIMU_I2C_SLV1_ADDR;
extern const uint8_t    _MPUIMU_I2C_SLV1_REG;
extern const uint8_t    _MPUIMU_I2C_SLV1_CTRL;
extern const uint8_t    _MPUIMU_I2C_SLV2_ADDR;
extern const uint8_t    _MPUIMU_I2C_SLV2_REG;
extern const uint8_t    _MPUIMU_I2C_SLV2_CTRL;
extern const uint8_t    _MPUIMU_I2C_SLV3_ADDR;
extern const uint8_t    _MPUIMU_I2C_SLV3_REG;
extern const uint8_t    _MPUIMU_I2C_SLV3_CTRL;
extern const uint8_t    _MPUIMU_I2C_SLV4_ADDR;
extern const uint8_t    _MPUIMU_I2C_SLV4_REG;
extern const uint8_t    _MPUIMU_I2C_SLV4_DO;
extern const uint8_t    _MPUIMU_I2C_SLV4_CTRL;
extern const uint8_t    _MPUIMU_I2C_SLV4_DI;
extern const uint8_t    _MPUIMU_I2C_MST_STATUS;
extern const uint8_t    _MPUIMU_INT_PIN_CFG;
extern const uint8_t    _MPUIMU_INT_ENABLE;
extern const uint8_t    _MPUIMU_INT_STATUS;
extern const uint8_t    _MPUIMU_RAW_ACCEL;
extern const uint8_t    _MPUIMU_ACCEL_XOUT_H;
extern const uint8_t    _MPUIMU_ACCEL_XOUT_L;
extern const uint8_t    _MPUIMU_ACCEL_YOUT_H;
extern const uint8_t    _MPUIMU_ACCEL_YOUT_L;
extern const uint8_t    _MPUIMU_ACCEL_ZOUT_H;
extern const uint8_t    _MPUIMU_ACCEL_ZOUT_L;
extern const uint8_t    _MPUIMU_TEMP_OUT_H;
extern const uint8_t    _MPUIMU_TEMP_OUT_L;
extern const uint8_t    _MPUIMU_RAW_GYRO;
extern const uint8_t    _MPUIMU_GYRO_XOUT_H;
extern const uint8_t    _MPUIMU_GYRO_XOUT_L;
extern const uint8_t    _MPUIMU_GYRO_YOUT_H;
extern const uint8_t    _MPUIMU_GYRO_YOUT_L;
extern const uint8_t    _MPUIMU_GYRO_ZOUT_H;
extern const uint8_t    _MPUIMU_GYRO_ZOUT_L;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_00;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_01;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_02;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_03;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_04;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_05;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_06;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_07;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_08;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_11;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_09;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_10;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_12;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_13;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_14;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_15;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_16;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_17;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_18;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_19;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_20;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_21;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_22;
extern const uint8_t    _MPUIMU_EXT_SENS_DATA_23;
extern const uint8_t    _MPUIMU_I2C_SLV0_DO;
extern const uint8_t    _MPUIMU_I2C_SLV1_DO;
extern const uint8_t    _MPUIMU_I2C_SLV2_DO;
extern const uint8_t    _MPUIMU_I2C_SLV3_DO;
extern const uint8_t    _MPUIMU_I2C_MST_DELAY_CT;
extern const uint8_t    _MPUIMU_SIGNAL_PATH_RES;
extern const uint8_t    _MPUIMU_MOT_DETECT_CTRL;
extern const uint8_t    _MPUIMU_USER_CTRL;
extern const uint8_t    _MPUIMU_PWR_MGMT_1;
extern const uint8_t    _MPUIMU_PWR_MGMT_2;
extern const uint8_t    _MPUIMU_FIFO_COUNTH;
extern const uint8_t    _MPUIMU_FIFO_COUNTL;
extern const uint8_t    _MPUIMU_FIFO_R_W;
extern const uint8_t    _MPUIMU_WHO_AM_I;
extern const uint8_t    _MPUIMU_I2C_ADDR_0;
extern const uint8_t    _MPUIMU_I2C_ADDR_1;

// Register Control
extern const uint8_t    _MPUIMU_PWR_CONFIG;
extern const uint8_t    _MPUIMU_PWR_SET;
extern const uint8_t    _MPUIMU_FIFO_EN_CONFIG;
extern const uint8_t    _MPUIMU_INT_ENABLE_CONFIG;

                                                                       /** @} */
/** @defgroup MPUIMU_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup MPUIMU_INIT Driver Initialization */              /** @{ */

#ifdef   __MPUIMU_DRV_SPI__
void mpuimu_spiDriverInit(T_MPUIMU_P gpioObj, T_MPUIMU_P spiObj);
#endif
#ifdef   __MPUIMU_DRV_I2C__
void mpuimu_i2cDriverInit(T_MPUIMU_P gpioObj, T_MPUIMU_P i2cObj, uint8_t slave);
#endif
#ifdef   __MPUIMU_DRV_UART__
void mpuimu_uartDriverInit(T_MPUIMU_P gpioObj, T_MPUIMU_P uartObj);
#endif


/** @defgroup MPUIMU_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic write data function
 *
 * @param[in] address         Register address
 *
 * @param[in] writeCommand    Command to write
 *
 * Function write byte of data to MPU-6000
 */
void mpuimu_writeData( uint8_t address, uint8_t writeCommand );

/**
 * @brief Generic read data function
 *
 * @param[in] address         Register address
 *
 * @return    Data from addressed register in MPU-6000
 *
 * Function read byte of data from register address of MPU-6000
 */
uint8_t mpuimu_readData( uint8_t address );

/**
 * @brief Function get low and high register data
 *
 * @param[in] adrRegLow         low data register address
 *
 * @param[in] adrRegHigh         high data register address
 *
 * @return         16-bit value ( low and high data )
 *
 * Function get data from two MPU-6000 register
 */
int16_t mpuimu_getAxis( uint8_t adrRegHigh );

/**
 * @brief Function read axis
 *
 * @param[out] gyroX             pointer to read Gyro X-axis data
 * @param[out] gyroY             pointer to read Gyro Y-axis data
 * @param[out] gyroZ             pointer to read Gyro Z-axis data
 *
 * Function read Gyro X-axis, Y-axis and Z-axis axis.
 *
 */
void mpuimu_readGyro( int16_t *gyroX, int16_t *gyroY, int16_t *gyroZ );

/**
 * @brief Function read axis
 *
 * @param[out] gyroX             pointer to read Accel X-axis data
 * @param[out] gyroY             pointer to read Accel Y-axis data
 * @param[out] gyroZ             pointer to read Accel Z-axis data
 *
 * Function read Accel X-axis, Y-axis and Z-axis axis.
 *
 */
void mpuimu_readAccel( int16_t *accelX, int16_t *accelY, int16_t *accelZ );

/**
 * @brief Function read temperature data in degrees [ °C ]
 *
 * @return         temperature in degrees [ °C ]
 *
 * Function read temperature data
 */
float mpuimu_readTemperature();





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_MPU_IMU_STM.c
    @example Click_MPU_IMU_TIVA.c
    @example Click_MPU_IMU_CEC.c
    @example Click_MPU_IMU_KINETIS.c
    @example Click_MPU_IMU_MSP.c
    @example Click_MPU_IMU_PIC.c
    @example Click_MPU_IMU_PIC32.c
    @example Click_MPU_IMU_DSPIC.c
    @example Click_MPU_IMU_AVR.c
    @example Click_MPU_IMU_FT90x.c
    @example Click_MPU_IMU_STM.mbas
    @example Click_MPU_IMU_TIVA.mbas
    @example Click_MPU_IMU_CEC.mbas
    @example Click_MPU_IMU_KINETIS.mbas
    @example Click_MPU_IMU_MSP.mbas
    @example Click_MPU_IMU_PIC.mbas
    @example Click_MPU_IMU_PIC32.mbas
    @example Click_MPU_IMU_DSPIC.mbas
    @example Click_MPU_IMU_AVR.mbas
    @example Click_MPU_IMU_FT90x.mbas
    @example Click_MPU_IMU_STM.mpas
    @example Click_MPU_IMU_TIVA.mpas
    @example Click_MPU_IMU_CEC.mpas
    @example Click_MPU_IMU_KINETIS.mpas
    @example Click_MPU_IMU_MSP.mpas
    @example Click_MPU_IMU_PIC.mpas
    @example Click_MPU_IMU_PIC32.mpas
    @example Click_MPU_IMU_DSPIC.mpas
    @example Click_MPU_IMU_AVR.mpas
    @example Click_MPU_IMU_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __mpuimu_driver.h

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