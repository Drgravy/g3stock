/*
 * include/linux/mfd/wm831x/irq.h -- Interrupt controller for WM831x
 *
 * Copyright 2009 Wolfson Microelectronics PLC.
 *
 * Author: Mark Brown <broonie@opensource.wolfsonmicro.com>
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 */

#ifndef __MFD_WM831X_IRQ_H__
#define __MFD_WM831X_IRQ_H__

/*                                           */
#define WM831X_IRQ_TEMP_THW 0
#define WM831X_IRQ_GPIO_1   1
#define WM831X_IRQ_GPIO_2   2
#define WM831X_IRQ_GPIO_3   3
#define WM831X_IRQ_GPIO_4   4
#define WM831X_IRQ_GPIO_5   5
#define WM831X_IRQ_GPIO_6   6
#define WM831X_IRQ_GPIO_7   7
#define WM831X_IRQ_GPIO_8   8
#define WM831X_IRQ_GPIO_9   9
#define WM831X_IRQ_GPIO_10  10
#define WM831X_IRQ_GPIO_11  11
#define WM831X_IRQ_GPIO_12  12
#define WM831X_IRQ_GPIO_13  13
#define WM831X_IRQ_GPIO_14  14
#define WM831X_IRQ_GPIO_15  15
#define WM831X_IRQ_GPIO_16  16
#define WM831X_IRQ_ON           17
#define WM831X_IRQ_PPM_SYSLO    18
#define WM831X_IRQ_PPM_PWR_SRC  19
#define WM831X_IRQ_PPM_USB_CURR 20
#define WM831X_IRQ_WDOG_TO      21
#define WM831X_IRQ_RTC_PER      22
#define WM831X_IRQ_RTC_ALM      23
#define WM831X_IRQ_CHG_BATT_HOT  24
#define WM831X_IRQ_CHG_BATT_COLD 25
#define WM831X_IRQ_CHG_BATT_FAIL 26
#define WM831X_IRQ_CHG_OV        27
#define WM831X_IRQ_CHG_END       29
#define WM831X_IRQ_CHG_TO        30
#define WM831X_IRQ_CHG_MODE      31
#define WM831X_IRQ_CHG_START     32
#define WM831X_IRQ_TCHDATA       33
#define WM831X_IRQ_TCHPD         34
#define WM831X_IRQ_AUXADC_DATA   35
#define WM831X_IRQ_AUXADC_DCOMP1 36
#define WM831X_IRQ_AUXADC_DCOMP2 37
#define WM831X_IRQ_AUXADC_DCOMP3 38
#define WM831X_IRQ_AUXADC_DCOMP4 39
#define WM831X_IRQ_CS1           40
#define WM831X_IRQ_CS2           41
#define WM831X_IRQ_HC_DC1        42
#define WM831X_IRQ_HC_DC2        43
#define WM831X_IRQ_UV_LDO1       44
#define WM831X_IRQ_UV_LDO2       45
#define WM831X_IRQ_UV_LDO3       46
#define WM831X_IRQ_UV_LDO4       47
#define WM831X_IRQ_UV_LDO5       48
#define WM831X_IRQ_UV_LDO6       49
#define WM831X_IRQ_UV_LDO7       50
#define WM831X_IRQ_UV_LDO8       51
#define WM831X_IRQ_UV_LDO9       52
#define WM831X_IRQ_UV_LDO10      53
#define WM831X_IRQ_UV_DC1        54
#define WM831X_IRQ_UV_DC2        55
#define WM831X_IRQ_UV_DC3        56
#define WM831X_IRQ_UV_DC4        57

#define WM831X_NUM_IRQS     58

/*
                                      
 */
#define WM831X_PS_INT                           0x8000  /*        */
#define WM831X_PS_INT_MASK                      0x8000  /*        */
#define WM831X_PS_INT_SHIFT                         15  /*        */
#define WM831X_PS_INT_WIDTH                          1  /*        */
#define WM831X_TEMP_INT                         0x4000  /*          */
#define WM831X_TEMP_INT_MASK                    0x4000  /*          */
#define WM831X_TEMP_INT_SHIFT                       14  /*          */
#define WM831X_TEMP_INT_WIDTH                        1  /*          */
#define WM831X_GP_INT                           0x2000  /*        */
#define WM831X_GP_INT_MASK                      0x2000  /*        */
#define WM831X_GP_INT_SHIFT                         13  /*        */
#define WM831X_GP_INT_WIDTH                          1  /*        */
#define WM831X_ON_PIN_INT                       0x1000  /*            */
#define WM831X_ON_PIN_INT_MASK                  0x1000  /*            */
#define WM831X_ON_PIN_INT_SHIFT                     12  /*            */
#define WM831X_ON_PIN_INT_WIDTH                      1  /*            */
#define WM831X_WDOG_INT                         0x0800  /*          */
#define WM831X_WDOG_INT_MASK                    0x0800  /*          */
#define WM831X_WDOG_INT_SHIFT                       11  /*          */
#define WM831X_WDOG_INT_WIDTH                        1  /*          */
#define WM831X_TCHDATA_INT                      0x0400  /*             */
#define WM831X_TCHDATA_INT_MASK                 0x0400  /*             */
#define WM831X_TCHDATA_INT_SHIFT                    10  /*             */
#define WM831X_TCHDATA_INT_WIDTH                     1  /*             */
#define WM831X_TCHPD_INT                        0x0200  /*           */
#define WM831X_TCHPD_INT_MASK                   0x0200  /*           */
#define WM831X_TCHPD_INT_SHIFT                       9  /*           */
#define WM831X_TCHPD_INT_WIDTH                       1  /*           */
#define WM831X_AUXADC_INT                       0x0100  /*            */
#define WM831X_AUXADC_INT_MASK                  0x0100  /*            */
#define WM831X_AUXADC_INT_SHIFT                      8  /*            */
#define WM831X_AUXADC_INT_WIDTH                      1  /*            */
#define WM831X_PPM_INT                          0x0080  /*         */
#define WM831X_PPM_INT_MASK                     0x0080  /*         */
#define WM831X_PPM_INT_SHIFT                         7  /*         */
#define WM831X_PPM_INT_WIDTH                         1  /*         */
#define WM831X_CS_INT                           0x0040  /*        */
#define WM831X_CS_INT_MASK                      0x0040  /*        */
#define WM831X_CS_INT_SHIFT                          6  /*        */
#define WM831X_CS_INT_WIDTH                          1  /*        */
#define WM831X_RTC_INT                          0x0020  /*         */
#define WM831X_RTC_INT_MASK                     0x0020  /*         */
#define WM831X_RTC_INT_SHIFT                         5  /*         */
#define WM831X_RTC_INT_WIDTH                         1  /*         */
#define WM831X_OTP_INT                          0x0010  /*         */
#define WM831X_OTP_INT_MASK                     0x0010  /*         */
#define WM831X_OTP_INT_SHIFT                         4  /*         */
#define WM831X_OTP_INT_WIDTH                         1  /*         */
#define WM831X_CHILD_INT                        0x0008  /*           */
#define WM831X_CHILD_INT_MASK                   0x0008  /*           */
#define WM831X_CHILD_INT_SHIFT                       3  /*           */
#define WM831X_CHILD_INT_WIDTH                       1  /*           */
#define WM831X_CHG_INT                          0x0004  /*         */
#define WM831X_CHG_INT_MASK                     0x0004  /*         */
#define WM831X_CHG_INT_SHIFT                         2  /*         */
#define WM831X_CHG_INT_WIDTH                         1  /*         */
#define WM831X_HC_INT                           0x0002  /*        */
#define WM831X_HC_INT_MASK                      0x0002  /*        */
#define WM831X_HC_INT_SHIFT                          1  /*        */
#define WM831X_HC_INT_WIDTH                          1  /*        */
#define WM831X_UV_INT                           0x0001  /*        */
#define WM831X_UV_INT_MASK                      0x0001  /*        */
#define WM831X_UV_INT_SHIFT                          0  /*        */
#define WM831X_UV_INT_WIDTH                          1  /*        */

/*
                                       
 */
#define WM831X_PPM_SYSLO_EINT                   0x8000  /*                */
#define WM831X_PPM_SYSLO_EINT_MASK              0x8000  /*                */
#define WM831X_PPM_SYSLO_EINT_SHIFT                 15  /*                */
#define WM831X_PPM_SYSLO_EINT_WIDTH                  1  /*                */
#define WM831X_PPM_PWR_SRC_EINT                 0x4000  /*                  */
#define WM831X_PPM_PWR_SRC_EINT_MASK            0x4000  /*                  */
#define WM831X_PPM_PWR_SRC_EINT_SHIFT               14  /*                  */
#define WM831X_PPM_PWR_SRC_EINT_WIDTH                1  /*                  */
#define WM831X_PPM_USB_CURR_EINT                0x2000  /*                   */
#define WM831X_PPM_USB_CURR_EINT_MASK           0x2000  /*                   */
#define WM831X_PPM_USB_CURR_EINT_SHIFT              13  /*                   */
#define WM831X_PPM_USB_CURR_EINT_WIDTH               1  /*                   */
#define WM831X_ON_PIN_EINT                      0x1000  /*             */
#define WM831X_ON_PIN_EINT_MASK                 0x1000  /*             */
#define WM831X_ON_PIN_EINT_SHIFT                    12  /*             */
#define WM831X_ON_PIN_EINT_WIDTH                     1  /*             */
#define WM831X_WDOG_TO_EINT                     0x0800  /*              */
#define WM831X_WDOG_TO_EINT_MASK                0x0800  /*              */
#define WM831X_WDOG_TO_EINT_SHIFT                   11  /*              */
#define WM831X_WDOG_TO_EINT_WIDTH                    1  /*              */
#define WM831X_TCHDATA_EINT                     0x0400  /*              */
#define WM831X_TCHDATA_EINT_MASK                0x0400  /*              */
#define WM831X_TCHDATA_EINT_SHIFT                   10  /*              */
#define WM831X_TCHDATA_EINT_WIDTH                    1  /*              */
#define WM831X_TCHPD_EINT                       0x0200  /*            */
#define WM831X_TCHPD_EINT_MASK                  0x0200  /*            */
#define WM831X_TCHPD_EINT_SHIFT                      9  /*            */
#define WM831X_TCHPD_EINT_WIDTH                      1  /*            */
#define WM831X_AUXADC_DATA_EINT                 0x0100  /*                  */
#define WM831X_AUXADC_DATA_EINT_MASK            0x0100  /*                  */
#define WM831X_AUXADC_DATA_EINT_SHIFT                8  /*                  */
#define WM831X_AUXADC_DATA_EINT_WIDTH                1  /*                  */
#define WM831X_AUXADC_DCOMP4_EINT               0x0080  /*                    */
#define WM831X_AUXADC_DCOMP4_EINT_MASK          0x0080  /*                    */
#define WM831X_AUXADC_DCOMP4_EINT_SHIFT              7  /*                    */
#define WM831X_AUXADC_DCOMP4_EINT_WIDTH              1  /*                    */
#define WM831X_AUXADC_DCOMP3_EINT               0x0040  /*                    */
#define WM831X_AUXADC_DCOMP3_EINT_MASK          0x0040  /*                    */
#define WM831X_AUXADC_DCOMP3_EINT_SHIFT              6  /*                    */
#define WM831X_AUXADC_DCOMP3_EINT_WIDTH              1  /*                    */
#define WM831X_AUXADC_DCOMP2_EINT               0x0020  /*                    */
#define WM831X_AUXADC_DCOMP2_EINT_MASK          0x0020  /*                    */
#define WM831X_AUXADC_DCOMP2_EINT_SHIFT              5  /*                    */
#define WM831X_AUXADC_DCOMP2_EINT_WIDTH              1  /*                    */
#define WM831X_AUXADC_DCOMP1_EINT               0x0010  /*                    */
#define WM831X_AUXADC_DCOMP1_EINT_MASK          0x0010  /*                    */
#define WM831X_AUXADC_DCOMP1_EINT_SHIFT              4  /*                    */
#define WM831X_AUXADC_DCOMP1_EINT_WIDTH              1  /*                    */
#define WM831X_RTC_PER_EINT                     0x0008  /*              */
#define WM831X_RTC_PER_EINT_MASK                0x0008  /*              */
#define WM831X_RTC_PER_EINT_SHIFT                    3  /*              */
#define WM831X_RTC_PER_EINT_WIDTH                    1  /*              */
#define WM831X_RTC_ALM_EINT                     0x0004  /*              */
#define WM831X_RTC_ALM_EINT_MASK                0x0004  /*              */
#define WM831X_RTC_ALM_EINT_SHIFT                    2  /*              */
#define WM831X_RTC_ALM_EINT_WIDTH                    1  /*              */
#define WM831X_TEMP_THW_EINT                    0x0002  /*               */
#define WM831X_TEMP_THW_EINT_MASK               0x0002  /*               */
#define WM831X_TEMP_THW_EINT_SHIFT                   1  /*               */
#define WM831X_TEMP_THW_EINT_WIDTH                   1  /*               */

/*
                                       
 */
#define WM831X_CHG_BATT_HOT_EINT                0x8000  /*                   */
#define WM831X_CHG_BATT_HOT_EINT_MASK           0x8000  /*                   */
#define WM831X_CHG_BATT_HOT_EINT_SHIFT              15  /*                   */
#define WM831X_CHG_BATT_HOT_EINT_WIDTH               1  /*                   */
#define WM831X_CHG_BATT_COLD_EINT               0x4000  /*                    */
#define WM831X_CHG_BATT_COLD_EINT_MASK          0x4000  /*                    */
#define WM831X_CHG_BATT_COLD_EINT_SHIFT             14  /*                    */
#define WM831X_CHG_BATT_COLD_EINT_WIDTH              1  /*                    */
#define WM831X_CHG_BATT_FAIL_EINT               0x2000  /*                    */
#define WM831X_CHG_BATT_FAIL_EINT_MASK          0x2000  /*                    */
#define WM831X_CHG_BATT_FAIL_EINT_SHIFT             13  /*                    */
#define WM831X_CHG_BATT_FAIL_EINT_WIDTH              1  /*                    */
#define WM831X_CHG_OV_EINT                      0x1000  /*             */
#define WM831X_CHG_OV_EINT_MASK                 0x1000  /*             */
#define WM831X_CHG_OV_EINT_SHIFT                    12  /*             */
#define WM831X_CHG_OV_EINT_WIDTH                     1  /*             */
#define WM831X_CHG_END_EINT                     0x0800  /*              */
#define WM831X_CHG_END_EINT_MASK                0x0800  /*              */
#define WM831X_CHG_END_EINT_SHIFT                   11  /*              */
#define WM831X_CHG_END_EINT_WIDTH                    1  /*              */
#define WM831X_CHG_TO_EINT                      0x0400  /*             */
#define WM831X_CHG_TO_EINT_MASK                 0x0400  /*             */
#define WM831X_CHG_TO_EINT_SHIFT                    10  /*             */
#define WM831X_CHG_TO_EINT_WIDTH                     1  /*             */
#define WM831X_CHG_MODE_EINT                    0x0200  /*               */
#define WM831X_CHG_MODE_EINT_MASK               0x0200  /*               */
#define WM831X_CHG_MODE_EINT_SHIFT                   9  /*               */
#define WM831X_CHG_MODE_EINT_WIDTH                   1  /*               */
#define WM831X_CHG_START_EINT                   0x0100  /*                */
#define WM831X_CHG_START_EINT_MASK              0x0100  /*                */
#define WM831X_CHG_START_EINT_SHIFT                  8  /*                */
#define WM831X_CHG_START_EINT_WIDTH                  1  /*                */
#define WM831X_CS2_EINT                         0x0080  /*          */
#define WM831X_CS2_EINT_MASK                    0x0080  /*          */
#define WM831X_CS2_EINT_SHIFT                        7  /*          */
#define WM831X_CS2_EINT_WIDTH                        1  /*          */
#define WM831X_CS1_EINT                         0x0040  /*          */
#define WM831X_CS1_EINT_MASK                    0x0040  /*          */
#define WM831X_CS1_EINT_SHIFT                        6  /*          */
#define WM831X_CS1_EINT_WIDTH                        1  /*          */
#define WM831X_OTP_CMD_END_EINT                 0x0020  /*                  */
#define WM831X_OTP_CMD_END_EINT_MASK            0x0020  /*                  */
#define WM831X_OTP_CMD_END_EINT_SHIFT                5  /*                  */
#define WM831X_OTP_CMD_END_EINT_WIDTH                1  /*                  */
#define WM831X_OTP_ERR_EINT                     0x0010  /*              */
#define WM831X_OTP_ERR_EINT_MASK                0x0010  /*              */
#define WM831X_OTP_ERR_EINT_SHIFT                    4  /*              */
#define WM831X_OTP_ERR_EINT_WIDTH                    1  /*              */
#define WM831X_PS_POR_EINT                      0x0004  /*             */
#define WM831X_PS_POR_EINT_MASK                 0x0004  /*             */
#define WM831X_PS_POR_EINT_SHIFT                     2  /*             */
#define WM831X_PS_POR_EINT_WIDTH                     1  /*             */
#define WM831X_PS_SLEEP_OFF_EINT                0x0002  /*                   */
#define WM831X_PS_SLEEP_OFF_EINT_MASK           0x0002  /*                   */
#define WM831X_PS_SLEEP_OFF_EINT_SHIFT               1  /*                   */
#define WM831X_PS_SLEEP_OFF_EINT_WIDTH               1  /*                   */
#define WM831X_PS_ON_WAKE_EINT                  0x0001  /*                 */
#define WM831X_PS_ON_WAKE_EINT_MASK             0x0001  /*                 */
#define WM831X_PS_ON_WAKE_EINT_SHIFT                 0  /*                 */
#define WM831X_PS_ON_WAKE_EINT_WIDTH                 1  /*                 */

/*
                                       
 */
#define WM831X_UV_LDO10_EINT                    0x0200  /*               */
#define WM831X_UV_LDO10_EINT_MASK               0x0200  /*               */
#define WM831X_UV_LDO10_EINT_SHIFT                   9  /*               */
#define WM831X_UV_LDO10_EINT_WIDTH                   1  /*               */
#define WM831X_UV_LDO9_EINT                     0x0100  /*              */
#define WM831X_UV_LDO9_EINT_MASK                0x0100  /*              */
#define WM831X_UV_LDO9_EINT_SHIFT                    8  /*              */
#define WM831X_UV_LDO9_EINT_WIDTH                    1  /*              */
#define WM831X_UV_LDO8_EINT                     0x0080  /*              */
#define WM831X_UV_LDO8_EINT_MASK                0x0080  /*              */
#define WM831X_UV_LDO8_EINT_SHIFT                    7  /*              */
#define WM831X_UV_LDO8_EINT_WIDTH                    1  /*              */
#define WM831X_UV_LDO7_EINT                     0x0040  /*              */
#define WM831X_UV_LDO7_EINT_MASK                0x0040  /*              */
#define WM831X_UV_LDO7_EINT_SHIFT                    6  /*              */
#define WM831X_UV_LDO7_EINT_WIDTH                    1  /*              */
#define WM831X_UV_LDO6_EINT                     0x0020  /*              */
#define WM831X_UV_LDO6_EINT_MASK                0x0020  /*              */
#define WM831X_UV_LDO6_EINT_SHIFT                    5  /*              */
#define WM831X_UV_LDO6_EINT_WIDTH                    1  /*              */
#define WM831X_UV_LDO5_EINT                     0x0010  /*              */
#define WM831X_UV_LDO5_EINT_MASK                0x0010  /*              */
#define WM831X_UV_LDO5_EINT_SHIFT                    4  /*              */
#define WM831X_UV_LDO5_EINT_WIDTH                    1  /*              */
#define WM831X_UV_LDO4_EINT                     0x0008  /*              */
#define WM831X_UV_LDO4_EINT_MASK                0x0008  /*              */
#define WM831X_UV_LDO4_EINT_SHIFT                    3  /*              */
#define WM831X_UV_LDO4_EINT_WIDTH                    1  /*              */
#define WM831X_UV_LDO3_EINT                     0x0004  /*              */
#define WM831X_UV_LDO3_EINT_MASK                0x0004  /*              */
#define WM831X_UV_LDO3_EINT_SHIFT                    2  /*              */
#define WM831X_UV_LDO3_EINT_WIDTH                    1  /*              */
#define WM831X_UV_LDO2_EINT                     0x0002  /*              */
#define WM831X_UV_LDO2_EINT_MASK                0x0002  /*              */
#define WM831X_UV_LDO2_EINT_SHIFT                    1  /*              */
#define WM831X_UV_LDO2_EINT_WIDTH                    1  /*              */
#define WM831X_UV_LDO1_EINT                     0x0001  /*              */
#define WM831X_UV_LDO1_EINT_MASK                0x0001  /*              */
#define WM831X_UV_LDO1_EINT_SHIFT                    0  /*              */
#define WM831X_UV_LDO1_EINT_WIDTH                    1  /*              */

/*
                                       
 */
#define WM831X_HC_DC2_EINT                      0x0200  /*             */
#define WM831X_HC_DC2_EINT_MASK                 0x0200  /*             */
#define WM831X_HC_DC2_EINT_SHIFT                     9  /*             */
#define WM831X_HC_DC2_EINT_WIDTH                     1  /*             */
#define WM831X_HC_DC1_EINT                      0x0100  /*             */
#define WM831X_HC_DC1_EINT_MASK                 0x0100  /*             */
#define WM831X_HC_DC1_EINT_SHIFT                     8  /*             */
#define WM831X_HC_DC1_EINT_WIDTH                     1  /*             */
#define WM831X_UV_DC4_EINT                      0x0008  /*             */
#define WM831X_UV_DC4_EINT_MASK                 0x0008  /*             */
#define WM831X_UV_DC4_EINT_SHIFT                     3  /*             */
#define WM831X_UV_DC4_EINT_WIDTH                     1  /*             */
#define WM831X_UV_DC3_EINT                      0x0004  /*             */
#define WM831X_UV_DC3_EINT_MASK                 0x0004  /*             */
#define WM831X_UV_DC3_EINT_SHIFT                     2  /*             */
#define WM831X_UV_DC3_EINT_WIDTH                     1  /*             */
#define WM831X_UV_DC2_EINT                      0x0002  /*             */
#define WM831X_UV_DC2_EINT_MASK                 0x0002  /*             */
#define WM831X_UV_DC2_EINT_SHIFT                     1  /*             */
#define WM831X_UV_DC2_EINT_WIDTH                     1  /*             */
#define WM831X_UV_DC1_EINT                      0x0001  /*             */
#define WM831X_UV_DC1_EINT_MASK                 0x0001  /*             */
#define WM831X_UV_DC1_EINT_SHIFT                     0  /*             */
#define WM831X_UV_DC1_EINT_WIDTH                     1  /*             */

/*
                                       
 */
#define WM831X_GP16_EINT                        0x8000  /*           */
#define WM831X_GP16_EINT_MASK                   0x8000  /*           */
#define WM831X_GP16_EINT_SHIFT                      15  /*           */
#define WM831X_GP16_EINT_WIDTH                       1  /*           */
#define WM831X_GP15_EINT                        0x4000  /*           */
#define WM831X_GP15_EINT_MASK                   0x4000  /*           */
#define WM831X_GP15_EINT_SHIFT                      14  /*           */
#define WM831X_GP15_EINT_WIDTH                       1  /*           */
#define WM831X_GP14_EINT                        0x2000  /*           */
#define WM831X_GP14_EINT_MASK                   0x2000  /*           */
#define WM831X_GP14_EINT_SHIFT                      13  /*           */
#define WM831X_GP14_EINT_WIDTH                       1  /*           */
#define WM831X_GP13_EINT                        0x1000  /*           */
#define WM831X_GP13_EINT_MASK                   0x1000  /*           */
#define WM831X_GP13_EINT_SHIFT                      12  /*           */
#define WM831X_GP13_EINT_WIDTH                       1  /*           */
#define WM831X_GP12_EINT                        0x0800  /*           */
#define WM831X_GP12_EINT_MASK                   0x0800  /*           */
#define WM831X_GP12_EINT_SHIFT                      11  /*           */
#define WM831X_GP12_EINT_WIDTH                       1  /*           */
#define WM831X_GP11_EINT                        0x0400  /*           */
#define WM831X_GP11_EINT_MASK                   0x0400  /*           */
#define WM831X_GP11_EINT_SHIFT                      10  /*           */
#define WM831X_GP11_EINT_WIDTH                       1  /*           */
#define WM831X_GP10_EINT                        0x0200  /*           */
#define WM831X_GP10_EINT_MASK                   0x0200  /*           */
#define WM831X_GP10_EINT_SHIFT                       9  /*           */
#define WM831X_GP10_EINT_WIDTH                       1  /*           */
#define WM831X_GP9_EINT                         0x0100  /*          */
#define WM831X_GP9_EINT_MASK                    0x0100  /*          */
#define WM831X_GP9_EINT_SHIFT                        8  /*          */
#define WM831X_GP9_EINT_WIDTH                        1  /*          */
#define WM831X_GP8_EINT                         0x0080  /*          */
#define WM831X_GP8_EINT_MASK                    0x0080  /*          */
#define WM831X_GP8_EINT_SHIFT                        7  /*          */
#define WM831X_GP8_EINT_WIDTH                        1  /*          */
#define WM831X_GP7_EINT                         0x0040  /*          */
#define WM831X_GP7_EINT_MASK                    0x0040  /*          */
#define WM831X_GP7_EINT_SHIFT                        6  /*          */
#define WM831X_GP7_EINT_WIDTH                        1  /*          */
#define WM831X_GP6_EINT                         0x0020  /*          */
#define WM831X_GP6_EINT_MASK                    0x0020  /*          */
#define WM831X_GP6_EINT_SHIFT                        5  /*          */
#define WM831X_GP6_EINT_WIDTH                        1  /*          */
#define WM831X_GP5_EINT                         0x0010  /*          */
#define WM831X_GP5_EINT_MASK                    0x0010  /*          */
#define WM831X_GP5_EINT_SHIFT                        4  /*          */
#define WM831X_GP5_EINT_WIDTH                        1  /*          */
#define WM831X_GP4_EINT                         0x0008  /*          */
#define WM831X_GP4_EINT_MASK                    0x0008  /*          */
#define WM831X_GP4_EINT_SHIFT                        3  /*          */
#define WM831X_GP4_EINT_WIDTH                        1  /*          */
#define WM831X_GP3_EINT                         0x0004  /*          */
#define WM831X_GP3_EINT_MASK                    0x0004  /*          */
#define WM831X_GP3_EINT_SHIFT                        2  /*          */
#define WM831X_GP3_EINT_WIDTH                        1  /*          */
#define WM831X_GP2_EINT                         0x0002  /*          */
#define WM831X_GP2_EINT_MASK                    0x0002  /*          */
#define WM831X_GP2_EINT_SHIFT                        1  /*          */
#define WM831X_GP2_EINT_WIDTH                        1  /*          */
#define WM831X_GP1_EINT                         0x0001  /*          */
#define WM831X_GP1_EINT_MASK                    0x0001  /*          */
#define WM831X_GP1_EINT_SHIFT                        0  /*          */
#define WM831X_GP1_EINT_WIDTH                        1  /*          */

/*
                               
 */
#define WM831X_IRQ_OD                           0x0002  /*        */
#define WM831X_IRQ_OD_MASK                      0x0002  /*        */
#define WM831X_IRQ_OD_SHIFT                          1  /*        */
#define WM831X_IRQ_OD_WIDTH                          1  /*        */
#define WM831X_IM_IRQ                           0x0001  /*        */
#define WM831X_IM_IRQ_MASK                      0x0001  /*        */
#define WM831X_IM_IRQ_SHIFT                          0  /*        */
#define WM831X_IM_IRQ_WIDTH                          1  /*        */

/*
                                           
 */
#define WM831X_IM_PS_INT                        0x8000  /*           */
#define WM831X_IM_PS_INT_MASK                   0x8000  /*           */
#define WM831X_IM_PS_INT_SHIFT                      15  /*           */
#define WM831X_IM_PS_INT_WIDTH                       1  /*           */
#define WM831X_IM_TEMP_INT                      0x4000  /*             */
#define WM831X_IM_TEMP_INT_MASK                 0x4000  /*             */
#define WM831X_IM_TEMP_INT_SHIFT                    14  /*             */
#define WM831X_IM_TEMP_INT_WIDTH                     1  /*             */
#define WM831X_IM_GP_INT                        0x2000  /*           */
#define WM831X_IM_GP_INT_MASK                   0x2000  /*           */
#define WM831X_IM_GP_INT_SHIFT                      13  /*           */
#define WM831X_IM_GP_INT_WIDTH                       1  /*           */
#define WM831X_IM_ON_PIN_INT                    0x1000  /*               */
#define WM831X_IM_ON_PIN_INT_MASK               0x1000  /*               */
#define WM831X_IM_ON_PIN_INT_SHIFT                  12  /*               */
#define WM831X_IM_ON_PIN_INT_WIDTH                   1  /*               */
#define WM831X_IM_WDOG_INT                      0x0800  /*             */
#define WM831X_IM_WDOG_INT_MASK                 0x0800  /*             */
#define WM831X_IM_WDOG_INT_SHIFT                    11  /*             */
#define WM831X_IM_WDOG_INT_WIDTH                     1  /*             */
#define WM831X_IM_TCHDATA_INT                   0x0400  /*                */
#define WM831X_IM_TCHDATA_INT_MASK              0x0400  /*                */
#define WM831X_IM_TCHDATA_INT_SHIFT                 10  /*                */
#define WM831X_IM_TCHDATA_INT_WIDTH                  1  /*                */
#define WM831X_IM_TCHPD_INT                     0x0200  /*              */
#define WM831X_IM_TCHPD_INT_MASK                0x0200  /*              */
#define WM831X_IM_TCHPD_INT_SHIFT                    9  /*              */
#define WM831X_IM_TCHPD_INT_WIDTH                    1  /*              */
#define WM831X_IM_AUXADC_INT                    0x0100  /*               */
#define WM831X_IM_AUXADC_INT_MASK               0x0100  /*               */
#define WM831X_IM_AUXADC_INT_SHIFT                   8  /*               */
#define WM831X_IM_AUXADC_INT_WIDTH                   1  /*               */
#define WM831X_IM_PPM_INT                       0x0080  /*            */
#define WM831X_IM_PPM_INT_MASK                  0x0080  /*            */
#define WM831X_IM_PPM_INT_SHIFT                      7  /*            */
#define WM831X_IM_PPM_INT_WIDTH                      1  /*            */
#define WM831X_IM_CS_INT                        0x0040  /*           */
#define WM831X_IM_CS_INT_MASK                   0x0040  /*           */
#define WM831X_IM_CS_INT_SHIFT                       6  /*           */
#define WM831X_IM_CS_INT_WIDTH                       1  /*           */
#define WM831X_IM_RTC_INT                       0x0020  /*            */
#define WM831X_IM_RTC_INT_MASK                  0x0020  /*            */
#define WM831X_IM_RTC_INT_SHIFT                      5  /*            */
#define WM831X_IM_RTC_INT_WIDTH                      1  /*            */
#define WM831X_IM_OTP_INT                       0x0010  /*            */
#define WM831X_IM_OTP_INT_MASK                  0x0010  /*            */
#define WM831X_IM_OTP_INT_SHIFT                      4  /*            */
#define WM831X_IM_OTP_INT_WIDTH                      1  /*            */
#define WM831X_IM_CHILD_INT                     0x0008  /*              */
#define WM831X_IM_CHILD_INT_MASK                0x0008  /*              */
#define WM831X_IM_CHILD_INT_SHIFT                    3  /*              */
#define WM831X_IM_CHILD_INT_WIDTH                    1  /*              */
#define WM831X_IM_CHG_INT                       0x0004  /*            */
#define WM831X_IM_CHG_INT_MASK                  0x0004  /*            */
#define WM831X_IM_CHG_INT_SHIFT                      2  /*            */
#define WM831X_IM_CHG_INT_WIDTH                      1  /*            */
#define WM831X_IM_HC_INT                        0x0002  /*           */
#define WM831X_IM_HC_INT_MASK                   0x0002  /*           */
#define WM831X_IM_HC_INT_SHIFT                       1  /*           */
#define WM831X_IM_HC_INT_WIDTH                       1  /*           */
#define WM831X_IM_UV_INT                        0x0001  /*           */
#define WM831X_IM_UV_INT_MASK                   0x0001  /*           */
#define WM831X_IM_UV_INT_SHIFT                       0  /*           */
#define WM831X_IM_UV_INT_WIDTH                       1  /*           */

/*
                                            
 */
#define WM831X_IM_PPM_SYSLO_EINT                0x8000  /*                   */
#define WM831X_IM_PPM_SYSLO_EINT_MASK           0x8000  /*                   */
#define WM831X_IM_PPM_SYSLO_EINT_SHIFT              15  /*                   */
#define WM831X_IM_PPM_SYSLO_EINT_WIDTH               1  /*                   */
#define WM831X_IM_PPM_PWR_SRC_EINT              0x4000  /*                     */
#define WM831X_IM_PPM_PWR_SRC_EINT_MASK         0x4000  /*                     */
#define WM831X_IM_PPM_PWR_SRC_EINT_SHIFT            14  /*                     */
#define WM831X_IM_PPM_PWR_SRC_EINT_WIDTH             1  /*                     */
#define WM831X_IM_PPM_USB_CURR_EINT             0x2000  /*                      */
#define WM831X_IM_PPM_USB_CURR_EINT_MASK        0x2000  /*                      */
#define WM831X_IM_PPM_USB_CURR_EINT_SHIFT           13  /*                      */
#define WM831X_IM_PPM_USB_CURR_EINT_WIDTH            1  /*                      */
#define WM831X_IM_ON_PIN_EINT                   0x1000  /*                */
#define WM831X_IM_ON_PIN_EINT_MASK              0x1000  /*                */
#define WM831X_IM_ON_PIN_EINT_SHIFT                 12  /*                */
#define WM831X_IM_ON_PIN_EINT_WIDTH                  1  /*                */
#define WM831X_IM_WDOG_TO_EINT                  0x0800  /*                 */
#define WM831X_IM_WDOG_TO_EINT_MASK             0x0800  /*                 */
#define WM831X_IM_WDOG_TO_EINT_SHIFT                11  /*                 */
#define WM831X_IM_WDOG_TO_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_TCHDATA_EINT                  0x0400  /*                 */
#define WM831X_IM_TCHDATA_EINT_MASK             0x0400  /*                 */
#define WM831X_IM_TCHDATA_EINT_SHIFT                10  /*                 */
#define WM831X_IM_TCHDATA_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_TCHPD_EINT                    0x0200  /*               */
#define WM831X_IM_TCHPD_EINT_MASK               0x0200  /*               */
#define WM831X_IM_TCHPD_EINT_SHIFT                   9  /*               */
#define WM831X_IM_TCHPD_EINT_WIDTH                   1  /*               */
#define WM831X_IM_AUXADC_DATA_EINT              0x0100  /*                     */
#define WM831X_IM_AUXADC_DATA_EINT_MASK         0x0100  /*                     */
#define WM831X_IM_AUXADC_DATA_EINT_SHIFT             8  /*                     */
#define WM831X_IM_AUXADC_DATA_EINT_WIDTH             1  /*                     */
#define WM831X_IM_AUXADC_DCOMP4_EINT            0x0080  /*                       */
#define WM831X_IM_AUXADC_DCOMP4_EINT_MASK       0x0080  /*                       */
#define WM831X_IM_AUXADC_DCOMP4_EINT_SHIFT           7  /*                       */
#define WM831X_IM_AUXADC_DCOMP4_EINT_WIDTH           1  /*                       */
#define WM831X_IM_AUXADC_DCOMP3_EINT            0x0040  /*                       */
#define WM831X_IM_AUXADC_DCOMP3_EINT_MASK       0x0040  /*                       */
#define WM831X_IM_AUXADC_DCOMP3_EINT_SHIFT           6  /*                       */
#define WM831X_IM_AUXADC_DCOMP3_EINT_WIDTH           1  /*                       */
#define WM831X_IM_AUXADC_DCOMP2_EINT            0x0020  /*                       */
#define WM831X_IM_AUXADC_DCOMP2_EINT_MASK       0x0020  /*                       */
#define WM831X_IM_AUXADC_DCOMP2_EINT_SHIFT           5  /*                       */
#define WM831X_IM_AUXADC_DCOMP2_EINT_WIDTH           1  /*                       */
#define WM831X_IM_AUXADC_DCOMP1_EINT            0x0010  /*                       */
#define WM831X_IM_AUXADC_DCOMP1_EINT_MASK       0x0010  /*                       */
#define WM831X_IM_AUXADC_DCOMP1_EINT_SHIFT           4  /*                       */
#define WM831X_IM_AUXADC_DCOMP1_EINT_WIDTH           1  /*                       */
#define WM831X_IM_RTC_PER_EINT                  0x0008  /*                 */
#define WM831X_IM_RTC_PER_EINT_MASK             0x0008  /*                 */
#define WM831X_IM_RTC_PER_EINT_SHIFT                 3  /*                 */
#define WM831X_IM_RTC_PER_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_RTC_ALM_EINT                  0x0004  /*                 */
#define WM831X_IM_RTC_ALM_EINT_MASK             0x0004  /*                 */
#define WM831X_IM_RTC_ALM_EINT_SHIFT                 2  /*                 */
#define WM831X_IM_RTC_ALM_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_TEMP_THW_EINT                 0x0002  /*                  */
#define WM831X_IM_TEMP_THW_EINT_MASK            0x0002  /*                  */
#define WM831X_IM_TEMP_THW_EINT_SHIFT                1  /*                  */
#define WM831X_IM_TEMP_THW_EINT_WIDTH                1  /*                  */

/*
                                            
 */
#define WM831X_IM_CHG_BATT_HOT_EINT             0x8000  /*                      */
#define WM831X_IM_CHG_BATT_HOT_EINT_MASK        0x8000  /*                      */
#define WM831X_IM_CHG_BATT_HOT_EINT_SHIFT           15  /*                      */
#define WM831X_IM_CHG_BATT_HOT_EINT_WIDTH            1  /*                      */
#define WM831X_IM_CHG_BATT_COLD_EINT            0x4000  /*                       */
#define WM831X_IM_CHG_BATT_COLD_EINT_MASK       0x4000  /*                       */
#define WM831X_IM_CHG_BATT_COLD_EINT_SHIFT          14  /*                       */
#define WM831X_IM_CHG_BATT_COLD_EINT_WIDTH           1  /*                       */
#define WM831X_IM_CHG_BATT_FAIL_EINT            0x2000  /*                       */
#define WM831X_IM_CHG_BATT_FAIL_EINT_MASK       0x2000  /*                       */
#define WM831X_IM_CHG_BATT_FAIL_EINT_SHIFT          13  /*                       */
#define WM831X_IM_CHG_BATT_FAIL_EINT_WIDTH           1  /*                       */
#define WM831X_IM_CHG_OV_EINT                   0x1000  /*                */
#define WM831X_IM_CHG_OV_EINT_MASK              0x1000  /*                */
#define WM831X_IM_CHG_OV_EINT_SHIFT                 12  /*                */
#define WM831X_IM_CHG_OV_EINT_WIDTH                  1  /*                */
#define WM831X_IM_CHG_END_EINT                  0x0800  /*                 */
#define WM831X_IM_CHG_END_EINT_MASK             0x0800  /*                 */
#define WM831X_IM_CHG_END_EINT_SHIFT                11  /*                 */
#define WM831X_IM_CHG_END_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_CHG_TO_EINT                   0x0400  /*                */
#define WM831X_IM_CHG_TO_EINT_MASK              0x0400  /*                */
#define WM831X_IM_CHG_TO_EINT_SHIFT                 10  /*                */
#define WM831X_IM_CHG_TO_EINT_WIDTH                  1  /*                */
#define WM831X_IM_CHG_MODE_EINT                 0x0200  /*                  */
#define WM831X_IM_CHG_MODE_EINT_MASK            0x0200  /*                  */
#define WM831X_IM_CHG_MODE_EINT_SHIFT                9  /*                  */
#define WM831X_IM_CHG_MODE_EINT_WIDTH                1  /*                  */
#define WM831X_IM_CHG_START_EINT                0x0100  /*                   */
#define WM831X_IM_CHG_START_EINT_MASK           0x0100  /*                   */
#define WM831X_IM_CHG_START_EINT_SHIFT               8  /*                   */
#define WM831X_IM_CHG_START_EINT_WIDTH               1  /*                   */
#define WM831X_IM_CS2_EINT                      0x0080  /*             */
#define WM831X_IM_CS2_EINT_MASK                 0x0080  /*             */
#define WM831X_IM_CS2_EINT_SHIFT                     7  /*             */
#define WM831X_IM_CS2_EINT_WIDTH                     1  /*             */
#define WM831X_IM_CS1_EINT                      0x0040  /*             */
#define WM831X_IM_CS1_EINT_MASK                 0x0040  /*             */
#define WM831X_IM_CS1_EINT_SHIFT                     6  /*             */
#define WM831X_IM_CS1_EINT_WIDTH                     1  /*             */
#define WM831X_IM_OTP_CMD_END_EINT              0x0020  /*                     */
#define WM831X_IM_OTP_CMD_END_EINT_MASK         0x0020  /*                     */
#define WM831X_IM_OTP_CMD_END_EINT_SHIFT             5  /*                     */
#define WM831X_IM_OTP_CMD_END_EINT_WIDTH             1  /*                     */
#define WM831X_IM_OTP_ERR_EINT                  0x0010  /*                 */
#define WM831X_IM_OTP_ERR_EINT_MASK             0x0010  /*                 */
#define WM831X_IM_OTP_ERR_EINT_SHIFT                 4  /*                 */
#define WM831X_IM_OTP_ERR_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_PS_POR_EINT                   0x0004  /*                */
#define WM831X_IM_PS_POR_EINT_MASK              0x0004  /*                */
#define WM831X_IM_PS_POR_EINT_SHIFT                  2  /*                */
#define WM831X_IM_PS_POR_EINT_WIDTH                  1  /*                */
#define WM831X_IM_PS_SLEEP_OFF_EINT             0x0002  /*                      */
#define WM831X_IM_PS_SLEEP_OFF_EINT_MASK        0x0002  /*                      */
#define WM831X_IM_PS_SLEEP_OFF_EINT_SHIFT            1  /*                      */
#define WM831X_IM_PS_SLEEP_OFF_EINT_WIDTH            1  /*                      */
#define WM831X_IM_PS_ON_WAKE_EINT               0x0001  /*                    */
#define WM831X_IM_PS_ON_WAKE_EINT_MASK          0x0001  /*                    */
#define WM831X_IM_PS_ON_WAKE_EINT_SHIFT              0  /*                    */
#define WM831X_IM_PS_ON_WAKE_EINT_WIDTH              1  /*                    */

/*
                                            
 */
#define WM831X_IM_UV_LDO10_EINT                 0x0200  /*                  */
#define WM831X_IM_UV_LDO10_EINT_MASK            0x0200  /*                  */
#define WM831X_IM_UV_LDO10_EINT_SHIFT                9  /*                  */
#define WM831X_IM_UV_LDO10_EINT_WIDTH                1  /*                  */
#define WM831X_IM_UV_LDO9_EINT                  0x0100  /*                 */
#define WM831X_IM_UV_LDO9_EINT_MASK             0x0100  /*                 */
#define WM831X_IM_UV_LDO9_EINT_SHIFT                 8  /*                 */
#define WM831X_IM_UV_LDO9_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_UV_LDO8_EINT                  0x0080  /*                 */
#define WM831X_IM_UV_LDO8_EINT_MASK             0x0080  /*                 */
#define WM831X_IM_UV_LDO8_EINT_SHIFT                 7  /*                 */
#define WM831X_IM_UV_LDO8_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_UV_LDO7_EINT                  0x0040  /*                 */
#define WM831X_IM_UV_LDO7_EINT_MASK             0x0040  /*                 */
#define WM831X_IM_UV_LDO7_EINT_SHIFT                 6  /*                 */
#define WM831X_IM_UV_LDO7_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_UV_LDO6_EINT                  0x0020  /*                 */
#define WM831X_IM_UV_LDO6_EINT_MASK             0x0020  /*                 */
#define WM831X_IM_UV_LDO6_EINT_SHIFT                 5  /*                 */
#define WM831X_IM_UV_LDO6_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_UV_LDO5_EINT                  0x0010  /*                 */
#define WM831X_IM_UV_LDO5_EINT_MASK             0x0010  /*                 */
#define WM831X_IM_UV_LDO5_EINT_SHIFT                 4  /*                 */
#define WM831X_IM_UV_LDO5_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_UV_LDO4_EINT                  0x0008  /*                 */
#define WM831X_IM_UV_LDO4_EINT_MASK             0x0008  /*                 */
#define WM831X_IM_UV_LDO4_EINT_SHIFT                 3  /*                 */
#define WM831X_IM_UV_LDO4_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_UV_LDO3_EINT                  0x0004  /*                 */
#define WM831X_IM_UV_LDO3_EINT_MASK             0x0004  /*                 */
#define WM831X_IM_UV_LDO3_EINT_SHIFT                 2  /*                 */
#define WM831X_IM_UV_LDO3_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_UV_LDO2_EINT                  0x0002  /*                 */
#define WM831X_IM_UV_LDO2_EINT_MASK             0x0002  /*                 */
#define WM831X_IM_UV_LDO2_EINT_SHIFT                 1  /*                 */
#define WM831X_IM_UV_LDO2_EINT_WIDTH                 1  /*                 */
#define WM831X_IM_UV_LDO1_EINT                  0x0001  /*                 */
#define WM831X_IM_UV_LDO1_EINT_MASK             0x0001  /*                 */
#define WM831X_IM_UV_LDO1_EINT_SHIFT                 0  /*                 */
#define WM831X_IM_UV_LDO1_EINT_WIDTH                 1  /*                 */

/*
                                            
 */
#define WM831X_IM_HC_DC2_EINT                   0x0200  /*                */
#define WM831X_IM_HC_DC2_EINT_MASK              0x0200  /*                */
#define WM831X_IM_HC_DC2_EINT_SHIFT                  9  /*                */
#define WM831X_IM_HC_DC2_EINT_WIDTH                  1  /*                */
#define WM831X_IM_HC_DC1_EINT                   0x0100  /*                */
#define WM831X_IM_HC_DC1_EINT_MASK              0x0100  /*                */
#define WM831X_IM_HC_DC1_EINT_SHIFT                  8  /*                */
#define WM831X_IM_HC_DC1_EINT_WIDTH                  1  /*                */
#define WM831X_IM_UV_DC4_EINT                   0x0008  /*                */
#define WM831X_IM_UV_DC4_EINT_MASK              0x0008  /*                */
#define WM831X_IM_UV_DC4_EINT_SHIFT                  3  /*                */
#define WM831X_IM_UV_DC4_EINT_WIDTH                  1  /*                */
#define WM831X_IM_UV_DC3_EINT                   0x0004  /*                */
#define WM831X_IM_UV_DC3_EINT_MASK              0x0004  /*                */
#define WM831X_IM_UV_DC3_EINT_SHIFT                  2  /*                */
#define WM831X_IM_UV_DC3_EINT_WIDTH                  1  /*                */
#define WM831X_IM_UV_DC2_EINT                   0x0002  /*                */
#define WM831X_IM_UV_DC2_EINT_MASK              0x0002  /*                */
#define WM831X_IM_UV_DC2_EINT_SHIFT                  1  /*                */
#define WM831X_IM_UV_DC2_EINT_WIDTH                  1  /*                */
#define WM831X_IM_UV_DC1_EINT                   0x0001  /*                */
#define WM831X_IM_UV_DC1_EINT_MASK              0x0001  /*                */
#define WM831X_IM_UV_DC1_EINT_SHIFT                  0  /*                */
#define WM831X_IM_UV_DC1_EINT_WIDTH                  1  /*                */

/*
                                            
 */
#define WM831X_IM_GP16_EINT                     0x8000  /*              */
#define WM831X_IM_GP16_EINT_MASK                0x8000  /*              */
#define WM831X_IM_GP16_EINT_SHIFT                   15  /*              */
#define WM831X_IM_GP16_EINT_WIDTH                    1  /*              */
#define WM831X_IM_GP15_EINT                     0x4000  /*              */
#define WM831X_IM_GP15_EINT_MASK                0x4000  /*              */
#define WM831X_IM_GP15_EINT_SHIFT                   14  /*              */
#define WM831X_IM_GP15_EINT_WIDTH                    1  /*              */
#define WM831X_IM_GP14_EINT                     0x2000  /*              */
#define WM831X_IM_GP14_EINT_MASK                0x2000  /*              */
#define WM831X_IM_GP14_EINT_SHIFT                   13  /*              */
#define WM831X_IM_GP14_EINT_WIDTH                    1  /*              */
#define WM831X_IM_GP13_EINT                     0x1000  /*              */
#define WM831X_IM_GP13_EINT_MASK                0x1000  /*              */
#define WM831X_IM_GP13_EINT_SHIFT                   12  /*              */
#define WM831X_IM_GP13_EINT_WIDTH                    1  /*              */
#define WM831X_IM_GP12_EINT                     0x0800  /*              */
#define WM831X_IM_GP12_EINT_MASK                0x0800  /*              */
#define WM831X_IM_GP12_EINT_SHIFT                   11  /*              */
#define WM831X_IM_GP12_EINT_WIDTH                    1  /*              */
#define WM831X_IM_GP11_EINT                     0x0400  /*              */
#define WM831X_IM_GP11_EINT_MASK                0x0400  /*              */
#define WM831X_IM_GP11_EINT_SHIFT                   10  /*              */
#define WM831X_IM_GP11_EINT_WIDTH                    1  /*              */
#define WM831X_IM_GP10_EINT                     0x0200  /*              */
#define WM831X_IM_GP10_EINT_MASK                0x0200  /*              */
#define WM831X_IM_GP10_EINT_SHIFT                    9  /*              */
#define WM831X_IM_GP10_EINT_WIDTH                    1  /*              */
#define WM831X_IM_GP9_EINT                      0x0100  /*             */
#define WM831X_IM_GP9_EINT_MASK                 0x0100  /*             */
#define WM831X_IM_GP9_EINT_SHIFT                     8  /*             */
#define WM831X_IM_GP9_EINT_WIDTH                     1  /*             */
#define WM831X_IM_GP8_EINT                      0x0080  /*             */
#define WM831X_IM_GP8_EINT_MASK                 0x0080  /*             */
#define WM831X_IM_GP8_EINT_SHIFT                     7  /*             */
#define WM831X_IM_GP8_EINT_WIDTH                     1  /*             */
#define WM831X_IM_GP7_EINT                      0x0040  /*             */
#define WM831X_IM_GP7_EINT_MASK                 0x0040  /*             */
#define WM831X_IM_GP7_EINT_SHIFT                     6  /*             */
#define WM831X_IM_GP7_EINT_WIDTH                     1  /*             */
#define WM831X_IM_GP6_EINT                      0x0020  /*             */
#define WM831X_IM_GP6_EINT_MASK                 0x0020  /*             */
#define WM831X_IM_GP6_EINT_SHIFT                     5  /*             */
#define WM831X_IM_GP6_EINT_WIDTH                     1  /*             */
#define WM831X_IM_GP5_EINT                      0x0010  /*             */
#define WM831X_IM_GP5_EINT_MASK                 0x0010  /*             */
#define WM831X_IM_GP5_EINT_SHIFT                     4  /*             */
#define WM831X_IM_GP5_EINT_WIDTH                     1  /*             */
#define WM831X_IM_GP4_EINT                      0x0008  /*             */
#define WM831X_IM_GP4_EINT_MASK                 0x0008  /*             */
#define WM831X_IM_GP4_EINT_SHIFT                     3  /*             */
#define WM831X_IM_GP4_EINT_WIDTH                     1  /*             */
#define WM831X_IM_GP3_EINT                      0x0004  /*             */
#define WM831X_IM_GP3_EINT_MASK                 0x0004  /*             */
#define WM831X_IM_GP3_EINT_SHIFT                     2  /*             */
#define WM831X_IM_GP3_EINT_WIDTH                     1  /*             */
#define WM831X_IM_GP2_EINT                      0x0002  /*             */
#define WM831X_IM_GP2_EINT_MASK                 0x0002  /*             */
#define WM831X_IM_GP2_EINT_SHIFT                     1  /*             */
#define WM831X_IM_GP2_EINT_WIDTH                     1  /*             */
#define WM831X_IM_GP1_EINT                      0x0001  /*             */
#define WM831X_IM_GP1_EINT_MASK                 0x0001  /*             */
#define WM831X_IM_GP1_EINT_SHIFT                     0  /*             */
#define WM831X_IM_GP1_EINT_WIDTH                     1  /*             */


#endif
