#include <rtthread.h>
#include "gd32f4xx.h"
#include <string.h>

int uart0_print(const char* str);

int uart0_init(void)
{
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_USART0);
    
    gpio_af_set(GPIOA, GPIO_AF_7, GPIO_PIN_9);
    gpio_af_set(GPIOA, GPIO_AF_7, GPIO_PIN_10);
    
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_9);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_9);
    
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_10);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_10);
    
    usart_deinit(USART0);
    usart_baudrate_set(USART0,115200);
    usart_receive_config(USART0, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);
    usart_enable(USART0);
        
    return 0;
}

int uart0_print(const char* str)
{
    int i = 0, size = 0;
    char a = '\r';

    size = strlen(str);

    for (i = 0; i < size; i++)
    {
        if (*(str + i) == '\n')
        {
            usart_data_transmit(USART0, (uint32_t )a);
            while((usart_flag_get(USART0, USART_FLAG_TC) == RESET));
        }
        usart_data_transmit(USART0, (uint32_t)*(str + i));
        while((usart_flag_get(USART0, USART_FLAG_TC) == RESET));
    }
    return 0;
}
