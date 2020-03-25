
#include <stdio.h>

#include "GPIO_driver.h"
#include "GPIO_direction_struct.h"



void test_X_Y_cfg(unsigned int x, unsigned int y){
  //OBS: como no los registros no estan en orden creo este vector para acceder mas comodamente
  unsigned int IO_MUX_VEC_AUX[40]={
    IO_MUX->IO_MUX_GPIO0_REG,
    IO_MUX->IO_MUX_GPIO2_REG,
    IO_MUX->IO_MUX_GPIO4_REG,
    IO_MUX->IO_MUX_GPIO5_REG,
    IO_MUX->IO_MUX_GPIO16_REG,
    IO_MUX->IO_MUX_GPIO17_REG,
    IO_MUX->IO_MUX_GPIO18_REG,
    IO_MUX->IO_MUX_GPIO19_REG,
    IO_MUX->IO_MUX_GPIO20_REG,
    IO_MUX->IO_MUX_GPIO21_REG,
    IO_MUX->IO_MUX_GPIO22_REG,
    IO_MUX->IO_MUX_GPIO23_REG,
    IO_MUX->IO_MUX_GPIO24_REG,
    IO_MUX->IO_MUX_GPIO25_REG,
    IO_MUX->IO_MUX_GPIO26_REG,
    IO_MUX->IO_MUX_GPIO27_REG,
    IO_MUX->IO_MUX_GPIO32_REG,
    IO_MUX->IO_MUX_GPIO33_REG,
    IO_MUX->IO_MUX_GPIO34_REG,
    IO_MUX->IO_MUX_GPIO35_REG,
    IO_MUX->IO_MUX_GPIO36_REG,
    IO_MUX->IO_MUX_GPIO37_REG,
    IO_MUX->IO_MUX_GPIO38_REG,
    IO_MUX->IO_MUX_GPIO39_REG
    };

  printf("%s\n","prueba!" );
  if (x > 39){
      printf("%s\n","error: la x es mas grande de lo que debe" );
    }

  //Para leer el “GPIO pad X” por el  “peripheral signal Y”:

//1-Configurar el registro GPIO_FUNCy_IN_SEL_CFG :
    // configurar el campo :  GPIO_FUNCy_IN_SEL
      GPIO->GPIO_FUNC_IN_SEL_CFG_REG[y] &= x;
    // limpiar el resto de los campos del registro => son el bit 6 y 7
      GPIO->GPIO_FUNC_IN_SEL_CFG_REG[y] &= ~(3<<6);
        //Selection control for peripheral input m. A value of 0-39 selects which of the 40 GPIO Matrix input pins this signal is connected to,
        // or 0x38 for a constantly high input or 0x30 for a constantly low input. (R/W)

// 2- Configurar el registro GPIO_FUNCx_OUT_SEL_CFG correspondiente  al PAD X:
    // (y limpiar el campo  GPIO_ENABLE_DATA[X] del mismo)

    //Primero Setear el bit GPIO_FUNCx_OEN_SEL (bit 10)
    //para forzar que el estado de salida este determinado siempre por GPIO_ENABLE_DATA[x] justamente.

      GPIO->GPIO_FUNC_OUT_SEL_CFG_REG[x] |= 1<<10;

    // el GPIO_ENABLE_DATA[x] field puede ser
    //  GPIO_ENABLE_REG (GPIOs 0-31)
    // o
    //  GPIO_ENABLE1_REG (GPIOs 32-39).
    // ⇒ Despues hay que limpiar este bit para deshabilitar el driver del  output.

      if(x<32){
        GPIO->GPIO_ENABLE_REG &= ~(1<<x);
      }
      else if(32<=x && x<40){
        GPIO->GPIO_ENABLE1_REG &= ~(1<<(x-32));
      }
  //3- Configurar el  IO_MUX para que seleccione el GPIO Matrix.
    //Hay que setear el registro  IO_MUX_x_REG:

  // a- Setear el campo (MCU_SEL) para la funcion IO_MUX function (correspondiente a X)
    //(this is Function #3—numeric value 2—for all pins).



  IO_MUX_VEC_AUX[x] |= (0x2)<<12; //seteo la funcion 3

  //Enable del bit bit FUN_IE

  IO_MUX_VEC_AUX[x] |= (0x1)<<9;

  //Set o clear de los bits FUN_WPU y FUN_WPD
  //segun enable/disable internal pull-up/pull-down resistors

  IO_MUX_VEC_AUX[x] |= (0x0)<<7; //corresponde a pull down
  IO_MUX_VEC_AUX[x] |= (0x1)<<8; //corresponde a pull up

  return;
}

unsigned int read_X_Y(unsigned int x){
  unsigned int state=35;
  unsigned int aux;

  if(x<32){
    aux= GPIO-> GPIO_IN_REG;
    aux&= (1<<x);
    state= aux>>x;
  }
  else if(32<=x && x<40){
    aux= GPIO-> GPIO_IN1_REG;
    aux&= (1<<x);
    state= aux>>x;
  }

  return state;

}
