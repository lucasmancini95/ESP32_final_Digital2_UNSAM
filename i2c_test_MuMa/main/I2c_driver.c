
#include <stdio.h>

#include "GPIO_driver.h"
#include "I2C_direction_struct.h"


void i2c_init(i2c_number_t i2c_num, i2c_mode_t i2c_mode,i2c_pins_t i2c_pins,i2c_buffer_size_t i2c_buffer_size){

  i2c_set_pin(i2c_num,i2c_pins.sda_io_num,i2c_pins.scl_io_num,i2c_mode);

  if(i2c_mode == I2C_MASTER){
    i2c_init_master(i2c_num, i2c_pins);
  }
  else if(i2c_mode == I2C_SLAVE){
    i2c_init_slave(i2c_pins,i2c_pins, i2c_buffer_size);
  }

  return;
}

void i2c_set_pin(i2c_number_t i2c_num, int sda_io_num, int scl_io_num,/* gpio_pullup_t sda_pullup_en, gpio_pullup_t scl_pullup_en,*/ i2c_mode_t mode);



}

void i2c_init_master(i2c_num, i2c_pins){

}
