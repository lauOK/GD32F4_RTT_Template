#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include <rtthread.h>

#include "led.h"
#include "uart0.h"

/*!
    \brief    main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    while(1) {
        
        //helpled_toggle();
        
        rt_thread_mdelay(1000);
    }
}
