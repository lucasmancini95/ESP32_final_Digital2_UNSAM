
#include <stdio.h>

#include "GPIO_driver.h"
#include "I2C_direction_struct.h"


void i2c_init(i2c_number_t i2c_num, i2c_mode_t i2c_mode,i2c_pins_t i2c_pins,i2c_buffer_size_t i2c_buffer_size){

  i2c_set_pin(i2c_num,i2c_pins.sda_io_num,i2c_pins.scl_io_num);

  if(i2c_mode == I2C_MASTER){
    i2c_init_master(i2c_num);
  }
  else if(i2c_mode == I2C_SLAVE){
    i2c_init_slave(i2c_pins, i2c_buffer_size);
  }

  return;
}

void i2c_set_pin(i2c_number_t i2c_num, int sda_io_num, int scl_io_num);

    //configurar el GPIO matrix
      //con los pines de SDA y SCL
      //y el numero del periferico I2C 0 o 1

}

void i2c_init_master(i2c_number_t i2c_num){

  I2C_T* I2CX;

  if(i2c_num == I2C_NUM_0){
    I2CX==I2C0;
  }
  else if(i2c_num == I2C_NUM_1){
    I2CX==I2C1;
  }

  I2CX->I2C_CTR_REG|=1<< MCOMDS_MODE_BIT; //Set this bit to configure the module as an I2C Master.

  if( I2C_SLAVE_ADDR_10BIT_OPC == 1){ // to enable the 10 bit adrr of the slave
      I2CX->I2C_SLAVE_ADDR_REG|=1<<SLAVE_ADDR_10BIT_EN_BIT;
  }

  return;

}

void i2c_init_slave(i2c_num){
  I2C_T* I2CX;

  if(i2c_num == I2C_NUM_0){
    I2Cx==I2C0;
  }
  else if(i2c_num == I2C_NUM_1){
    I2Cx==I2C1;
  }
  I2CX->I2C_CTR_REG&=~(1<< MS_MODE_BIT); //Clear this bit to configure the module as an I 2 C Slave.
  //I2CX->I2C_SLAVE_ADDR_REG|= I2C_SLAVE_ADDR_CONFIG; //When configured as an I 2 C Slave, this field is used to configure the its own address
  return;
}

void i2c_master_new_link(i2c_cmd_array_t* cmd_array , i2c_number_t i2c_num){

  if(((cmd_array[0]).op_code)!=RSTART){
    printf("ERROR: the first command MUST be RSTAR\n");
    return;
  }

  printf("Filling the commands\n" );
  for(int i=0; ((cmd_array[i]).op_code)==STOP; i++){
    i2c_master_fill_cmd(cmd_array[i],i,i2c_num);
    printf("The %d cmd was inserted\n", i);
  }

  I2CX->I2C_CTR_REG|= 1<< TRANS_START_BIT; //Set this bit to start sending the data in txfifo. (R/W)
  return;
}

void i2c_master_fill_cmd(i2c_cmd_t cmd,int i, i2c_number_t i2c_num){
  I2C_T* I2CX;

  if(i2c_num == I2C_NUM_0){
    I2CX==I2C0;
  }
  else if(i2c_num == I2C_NUM_1){
    I2CX==I2C1;
  }

    (I2CX->I2C_COMD_REG)[i]|=cmd.op_code<<OP_CODE_BITS;

    (I2CX->I2C_COMD_REG)[i]|=cmd.ack_value<<ACK_VALUE_BIT;

    (I2CX->I2C_COMD_REG)[i]|=cmd.ack_exp<<ACK_EXP_BIT;

    (I2CX->I2C_COMD_REG)[i]|=cmd.ack_check_en<< ACK_CHECK_EN_BIT;

    (I2CX->I2C_COMD_REG)[i]|=cmd.byte_num<< BYTE_NUM_BITS;

    return;
}


void i2c_master_write_adress(){}
void i2c_master_write_data(){}

void i2c_write_on_RAM(i2c_num){

  /* RAM, the size of which is 32 x 8 bits (32*8=256), and it is directly mapped onto the address space of the CPU cores,
starting at address REG_I2C_BASE+0x100. Each "byte(8 bits) of I2C data" is stored in a "32-bit word of memory"
(so, the first byte is at +0x100, the second byte at +0x104, the third byte at +0x108, etc.)*/
//Users need to set register I2C_NONFIFO_EN

//REG_I2C_BASE --> es I2C0 o I2C1 --> i2c_num
//RAM_
//0x100 tu primer byte (8 bits) --> los primero 8 con el dato y los siguientes 24 vacios
//distancia de 4 bytes==> 32 bits
//0x104 tu segundo byte (8 bits) --> los primero 8 con el dato y los siguientes 24 vacios
//etc ... hasta --> ??

}
