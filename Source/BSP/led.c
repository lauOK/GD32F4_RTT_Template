#include <rtthread.h>
#include "gd32f4xx.h"

#include <string.h>

#define LED_RCU     RCU_GPIOC
#define LED_GPIO    GPIOC
#define LED_PIN     GPIO_PIN_0

#define LED_ON      RESET
#define LED_OFF     SET


int led_init(void)
{
    rcu_periph_clock_enable(LED_RCU);
    
    gpio_mode_set(LED_GPIO, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN);
    
    gpio_bit_write(LED_GPIO, LED_PIN, LED_OFF);
    
    return 0;
}
INIT_BOARD_EXPORT(led_init);

int led_toggle(int argc, char *argv[])
{
    if(argc < 2)
    {
        gpio_bit_toggle(LED_GPIO, LED_PIN);
    }
    else
    {     
        if(rt_strcmp(argv[1], "ON") == 0)
        {
            gpio_bit_write(LED_GPIO, LED_PIN, LED_ON);
            rt_kprintf("LED ON\n");
        }
        else if(rt_strcmp(argv[1], "OFF") == 0)
        {
            gpio_bit_write(LED_GPIO, LED_PIN, LED_OFF);
            rt_kprintf("LED OFF\n");
        }
        else
        {
            rt_kprintf("Error Parameter\n");
        }
    }
    return 0;
}
MSH_CMD_EXPORT(led_toggle, LED ON/OFF)
