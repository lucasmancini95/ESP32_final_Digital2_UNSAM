
#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

//Configuration macros-----------------------------------------------------
#define FUN_DRV_VALUE 3 // desired value for output strength (0-3), proportional to current that can be sourced/sunk from the selected pin.
#define ENABLE_OUTPUT_OPEN_DRAIN 0 //Output open drain mode enable
  //if open drain mode is enabled:
  #define ENABLE_OUTPUT_OPEN_DRAIN_PDOWN 0
  #define ENABLE_OUTPUT_OPEN_DRAIN_PUP 0

//Function declaration-------------------------------------------------------
void gpio_input_direct_cfg(unsigned int x);
void gpio_input_to_peripheral_cfg(unsigned int x, unsigned int y);
unsigned int gpio_get_state(unsigned int x);
void gpio_output_direct_cfg(unsigned int x);
void gpio_output_peripheral_cfg(unsigned int x,unsigned int y);
void gpio_set_state(unsigned int x, unsigned int state);

#endif
