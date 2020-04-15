#ifndef GPIO_DIRECTION_STRUCT_H_
#define GPIO_DIRECTION_STRUCT_H_

#define I2C0_PORT_BASE		0x3FF53000 //direccion base del registro
#define I2C0				((I2C_T *) I2C0_PORT_BASE) //Apunto la struct a la direccion de memoria base del i2c0

#define I2C1_PORT_BASE		0x3FF67000 //direccion base del registro
#define I2C1				((I2C_T *) I2C1_PORT_BASE) //Apunto la struct a la direccion de memoria base del i2c1


#define MS_MODE_BIT 4
#define TRANS_START_BIT 5
#define I2C_SLAVE_ADDR_10BIT_EN 31


typedef struct {
unsigned int I2C_SCL_LOW_PERIOD_REG; // Configures the low level width of the SCL clock
unsigned int I2C_CTR_REG;
unsigned int I2C_SR_REG;
unsigned int I2C_TO_REG;
//Configuration registers
unsigned int I2C_SLAVE_ADDR_REG //Configures the I2C slave - R/W
unsigned int I2C_RXFIFO_ST_REG //FIFO status register - RO
unsigned int I2C_FIFO_CONF_REG //FIFO configuration register - R/W
unsigned int NA2;
//Interrupt registers
unsigned int I2C_INT_RAW_REG; //interrupt status RO
unsigned int I2C_INT_ENA_REG; // Interrupt enable bits R/W
unsigned int I2C_INT_CLR_REG; // Interrupt clear bits WO
unsigned int NA3[2];
//Timing registers (R/W)
unsigned int I2C_SDA_HOLD_REG;  //Configures the hold time after a negative SCL edge
unsigned int I2C_SDA_SAMPLE_REG; //Configures the sample time after a positive SCL edge
// 					 I2C_SCL_LOW_PERIOD_REG --> this REG is in the first position  // Configures the low level width of the SCL clock
unsigned int I2C_SCL_HIGH_PERIOD_REG;//Configures the high level width of the SCL clock
unsigned int NA4;
unsigned int I2C_SCL_START_HOLD_REG;//Configures the delay between the SDA and SCL negative edge for a start condition
unsigned int I2C_SCL_RSTART_SETUP_REG;//Configures the delay between the positive edge of SCL and the negative edge of SDA
unsigned int I2C_SCL_STOP_HOLD_REG;// Configures the delay after the SCL clock edge for a stop condition
unsigned int I2C_SCL_STOP_SETUP_REG;//Configures the delay between the SDA and SCL positive edge for a stop condition
//Filter registers
unsigned int I2C_SCL_FILTER_CFG_REG ; // SCL filter configuration register R/W
unsigned int I2C_SDA_FILTER_CFG_REG  ; // SDA filter configuration register R/W
//Command registers
unsigned int I2C_COMD_REG[16];
unsigned int NA5[2];
//i2c RAM structure
unsigned int I2C_RAM_REG[8];
} I2C_T;

#endif
