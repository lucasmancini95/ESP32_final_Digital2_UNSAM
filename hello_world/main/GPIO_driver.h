#pragma once
// #ifndef GPIO_DRIVER_H_
// #define GPIO_DRIVER_H_

void gpio_input_direct_cfg(unsigned int x);
void gpio_input_to_periferic_cfg(unsigned int x, unsigned int y);
unsigned int gpio_get_state(unsigned int x);

//#endif
