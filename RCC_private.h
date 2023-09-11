/****************************************************************/
/******* Author    : Moustafa saad Dawood *****************/
/******* Date      : 9 oct 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : BIT_private.h            *****************/
/****************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define RCC_CR (*(volatile u32*)(0x40021000))
/*first register has the base address anther +=offset*/

#define RCC_CFGR              (*(volatile u32*)(0x40021004))

#define RCC_CIR               (*(volatile u32*)(0x40021008))

#define RCC_APB2RSTR          (*((volatile u32 *)0x4002100C))

#define RCC_APB1RSTR          (*((volatile u32 *)0x40021010))

#define RCC_AHBENR            (*((volatile u32 *)0x40021014))

#define RCC_APB2ENR           (*((volatile u32 *)0x40021018))

#define RCC_APB1ENR           (*((volatile u32 *)0x4002101C))

#define RCC_BDCR              (*((volatile u32 *)0x40021020))

#define RCC_CSR               (*((volatile u32 *)0x40021024))
/* *******************PINS***********************************/

#define RCC_CR_HSION        0   /**< Internal High-Speed Clock Enable */

#define RCC_CR_HSIRDY       1   /**< Internal High-Speed Clock Ready */

#define RCC_CR_HSICAL       8   /**< Internal High-Speed Clock Calibration */

#define RCC_CR_HSEON        16  /**< External High-Speed Clock Enable */

#define RCC_CR_HSERDY       17  /**< External High-Speed Clock Ready */

#define RCC_CR_HSEBYP       18  /**< External High-Speed Clock Bypass */

#define RCC_CR_HSEPRE       19  /**< External High-Speed Clock Prescaler */

#define RCC_CR_CSSON        24  /**< Clock Security System Enable */

#define RCC_CR_PLLON        24  /**< PLL Enable */

#define RCC_CR_PLLRDY       25  /**< PLL Ready */
/************************************************     */
#define RCC_CR_HSE   0
#define RCC_CR_HSI   1
#define RCC_CR_PLL   2
/************CLK TYPES***********************/
#define RCC_CRYSTAL_CLK_    0   /**< Crystal Oscillator Clock Type */
#define RCC_RC_CLK_         1   /**< RC Oscillator Clock Type */

/** @} */ // end of RCC_Clock_Type
#define RCC_PLLON      1
#define RCC_PLLRDY     1
#define RCC_PLLCLK_RDY 1
#define RCC_PLLSRC     0
/******/


#define        RCC_CR_HSE  0
#define        RCC_CR_HSI  1


#endif /*end of RCC_private_H */