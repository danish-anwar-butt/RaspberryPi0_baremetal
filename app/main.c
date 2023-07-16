#include <stdint.h>

#define GPIO_BASE 0x20200000
#define ACTION_LED_PIN 47

struct GPIO {
  uint32_t GPFSEL[6];   	// GPIO Function Select R/W 
  uint32_t Reserve1;  		//- - 
  uint32_t GPSET[2];    	// GPIO Pin Output Set W
  uint32_t Reserved2; 		// - - 
  uint32_t GPCLR[2];    	// GPIO Pin Output Clear W 
  uint32_t Reserved3; 		// - - 
  uint32_t GPLEV[2];    	//GPIO Pin Level R
};

static volatile struct GPIO * gpio = (struct GPIO *) GPIO_BASE;


void gpio_set_output(unsigned int pin);
void gpio_write(unsigned int pin, unsigned int val);

void main(void){
	unsigned int i;
  gpio_set_output(ACTION_LED_PIN);
  while(1){
    gpio_write(ACTION_LED_PIN, 1);
    for(i=0;i<0x3F0000;i++);
    //timer_delay_ms(500);
     
    gpio_write(ACTION_LED_PIN, 0);
    for(i=0;i<0x3F0000;i++);
    //timer_delay_ms(500);
    
  }
}

void gpio_set_output(unsigned int pin){
  
  unsigned char shift_value;
  unsigned int  temp;
  
  shift_value = 21;
  temp = 4;
  
  temp &= ~(0x07 << shift_value);
  temp |= (01 & 0x07) << shift_value;
  gpio -> GPFSEL[pin/10] = temp;
}


void gpio_write(unsigned int pin, unsigned int val){
  uint8_t idx;
  
  if(pin < 32){
    idx = 0;
  }
  else {
    idx = 1;
    pin = pin - 32;
  }
  
  if (val == 1){
    gpio -> GPSET[idx] = 1<<(pin);
  }
  else{
    gpio -> GPCLR[idx] = 1<<(pin);
  }
}
