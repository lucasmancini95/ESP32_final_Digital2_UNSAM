#ifndef GPIO_DIRECTION_STRUCT_H_
#define GPIO_DIRECTION_STRUCT_H_

#define GPIO_PORT_BASE		0x3FF44000 //direccion base del registro
#define GPIO 				((GPIO_T *) GPIO_PORT_BASE) //Apunto la struct a la direccion de memoria base de los gpio

#define IO_MUX_PORT_BASE		0x3FF49000 //direccion base del registro
#define IO_MUX 				((IO_MUX_T *) IO_MUX_PORT_BASE) //Apunto la struct a la direccion de memoria base de los gpio

typedef struct {
	unsigned int GPIO_OUT_REG;
  unsigned int GPIO_OUT_W1TS_REG;
  unsigned int GPIO_OUT_W1TC_REG;
  unsigned int GPIO_OUT1_REG;
  unsigned int GPIO_OUT1_W1TS_REG ;
  unsigned int GPIO_OUT1_W1TC_REG ;
  unsigned int GPIO_ENABLE_REG ;
  unsigned int GPIO_ENABLE_W1TS_REG ;
  unsigned int GPIO_ENABLE_W1TC_REG ;
  unsigned int GPIO_ENABLE1_REG ;
  unsigned int GPIO_ENABLE1_W1TS_REG;
  unsigned int GPIO_ENABLE1_W1TC_REG;
  unsigned int GPIO_STRAP_REG ;
  unsigned int GPIO_IN_REG ;
  unsigned int GPIO_IN1_REG ;
  unsigned int GPIO_STATUS_REG ;
  unsigned int GPIO_STATUS_W1TS_REG ;
  unsigned int GPIO_STATUS_W1TC_REG ;
  unsigned int GPIO_STATUS1_REG  ;
  unsigned int GPIO_STATUS1_W1TS_REG;
  unsigned int GPIO_STATUS1_W1TC_REG;
  unsigned int GPIO_ACPU_INT_REG;
  unsigned int GPIO_ACPU_NMI_INT_REG;
  unsigned int GPIO_PCPU_INT_REG;
  unsigned int GPIO_PCPU_NMI_INT_REG;
  unsigned int GPIO_ACPU_INT1_REG;
  unsigned int GPIO_ACPU_NMI_INT1_REG;
  unsigned int GPIO_PCPU_INT1_REG;
  unsigned int GPIO_PCPU_NMI_INT1_REG;

  unsigned int GPIO_PIN_REG[40];

  unsigned int GPIO_FUNC_IN_SEL_CFG_REG[256];

  unsigned int GPIO_FUNC_OUT_SEL_CFG_REG[40];
} GPIO_T;

typedef struct {
	unsigned int IO_MUX_PIN_CTRL ;
	unsigned int IO_MUX_GPIO36_REG ;
	unsigned int IO_MUX_GPIO37_REG ;
	unsigned int IO_MUX_GPIO38_REG ;
	unsigned int IO_MUX_GPIO39_REG ;
	unsigned int IO_MUX_GPIO34_REG ;
	unsigned int IO_MUX_GPIO35_REG ;
	unsigned int IO_MUX_GPIO32_REG ;
	unsigned int IO_MUX_GPIO33_REG ;
	unsigned int IO_MUX_GPIO25_REG ;
	unsigned int IO_MUX_GPIO26_REG ;
	unsigned int IO_MUX_GPIO27_REG;
	unsigned int IO_MUX_MTMS_REG;
	unsigned int IO_MUX_MTDI_REG;
	unsigned int IO_MUX_MTCK_REG;
	unsigned int IO_MUX_MTDO_REG;
	unsigned int IO_MUX_GPIO2_REG;
	unsigned int IO_MUX_GPIO0_REG ;
	unsigned int IO_MUX_GPIO4_REG ;
	unsigned int IO_MUX_GPIO16_REG;
	unsigned int IO_MUX_GPIO17_REG ;
	unsigned int IO_MUX_SD_DATA2_REG;
	unsigned int IO_MUX_SD_DATA3_REG;
	unsigned int IO_MUX_SD_CMD_REG;
	unsigned int IO_MUX_SD_CLK_REG;
	unsigned int IO_MUX_SD_DATA0_REG;
	unsigned int IO_MUX_SD_DATA1_REG;
	unsigned int IO_MUX_GPIO5_REG ;
	unsigned int IO_MUX_GPIO18_REG ;
	unsigned int IO_MUX_GPIO19_REG ;
	unsigned int IO_MUX_GPIO20_REG ;
	unsigned int IO_MUX_GPIO21_REG ;
	unsigned int IO_MUX_GPIO22_REG ;
	unsigned int IO_MUX_U0RXD_REG ;
	unsigned int IO_MUX_U0TXD_REG;
	unsigned int IO_MUX_GPIO23_REG;
	unsigned int IO_MUX_GPIO24_REG ;
} IO_MUX_T;

#endif
