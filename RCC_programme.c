/****************************************************************/
/******* Author    : Moustafa saad Dawood *****************/
/******* Date      : 9 oct 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : RCC_programe.c              *****************/
/****************************************************************/


#include "../LIB/BIT_MATH.h"
#include  "../LIB/STD_TYPES.h"
#include "RCC_private.h"
#include "RCC_interface.h"
#include "RCC_config.h"





Std_ReturnType Mcal_RCC_PLLMULT(u8 MULT_FACTOR)

{

    RCC_CR|=  ((MULT_FACTOR &0x0F)<<18);


}



 
Std_ReturnType MCAL_RCC_INITCLK (u8 multiplication_Factor, u8 prescale_ABb1,u8 prescale_ABb2,u8 pll_SOURCE)
{
  Std_ReturnType local_function_status=E_NOT_OK;

#if RCC_SYSCLK==RC_HSE

#if RCC_CLK_BYPASS==RCC_RC_CLK_

    SET_BIT(RCC_CR,RCC_CR_HSEBYP);

    #elif RCC_CLK_BYPASS==RCC_CRYSTAL_CLK_

    CLR_BIT(RCC_CR,RCC_CR_HSEBYP);

    #elif
    #error "wrong option"
    #endif "bypass"

    SET_BIT(RCC_CR,RCC_CR_HSEON);

    while (!GET_BIT(RCC_CR,RCC_CR_HSERDY)) /*WAITIG UNTIL CLOCK READY*/

    RCC_CFGR=0X00000001; /* IF I SELECTED THAT I AM IN HSE RC MOOD*/
    

#endif /*SYSCLK HSE*/


#if RCC_SYSCLK==RC_HSI

SET_BIT(RCC_CR,RCC_CR_HSION);


 while (!GET_BIT(RCC_CR,RCC_CR_HSIRDY)) /*WAITIG UNTIL CLOCK READY*/

 RCC_CFGR=0X00000000; /* SELECTING HSI AS A SOURCE FOR THE CLK*/
 #endif
 #if RCC_SYSCLK==RC_PLL

 SET_BIT(RCC_CR,RCC_CR_HSEON);

 while (!GET_BIT(RCC_CR,RCC_CR_HSERDY));

 CLR_BIT(RCC_CR,RCC_PLLSRC);


if (pll_SOURCE==RCC_CR_HSI)
{

    CLR_BIT(RCC_CFGR,RCC_PLLSRC);
}
else  SET_BIT(RCC_CFGR,RCC_PLLSRC);


 Mcal_RCC_PLLMULT(multiplication_Factor);
 


 SET_BIT(RCC_CR,RCC_PLLRDY);

 while (!GET_BIT(RCC_CR,RCC_PLLRDY));



 SET_BIT(RCC_CR,RCC_PLLON);

 while (!GET_BIT(RCC_CR,RCC_PLLRDY))
 
 

 RCC_CFGR!=(0x00000010<<0);

 RCC_CFGR!=prescale_ABb1<<8;
 RCC_CFGR!=prescale_ABb2<<11;




 #endif 

    

}
Std_ReturnType MCAL_RCC_Enable_perifral(u8 Copy_Perifral_Id,u8 Copy_Bus_Id)
{

Std_ReturnType local_function_status=E_NOT_OK;

switch (Copy_Bus_Id)
{
case RCC_AHB :
    SET_BIT(Copy_Bus_Id,Copy_Perifral_Id);
    local_function_status=E_OK;

    break;

 case RCC_APB1 :
SET_BIT(RCC_APB1ENR,Copy_Perifral_Id);
local_function_status=E_OK;
    break;

case RCC_APB2 :
SET_BIT(RCC_APB2ENR,Copy_Perifral_Id);
local_function_status=E_OK;
    break;
    

default:local_function_status=E_NOT_OK;
    break;
}



return local_function_status;

    
}


Std_ReturnType MCAL_RCC_DISABLE_perifral(u8 Copy_Perifral_Id,u8 Copy_Bus_Id)
{
Std_ReturnType local_function_status=E_NOT_OK;
switch (Copy_Bus_Id)
{
case RCC_AHB :
    CLR_BIT(RCC_AHBENR,Copy_Perifral_Id);
    local_function_status=E_OK;

    break;

 case RCC_APB1 :
CLR_BIT(RCC_APB1ENR,Copy_Perifral_Id);
local_function_status=E_OK;
    break;

case RCC_APB2 :
CLR_BIT(RCC_APB2ENR,Copy_Perifral_Id);
local_function_status=E_OK;
    break;
    

default:local_function_status=E_NOT_OK;
    break;
}



return local_function_status;



}