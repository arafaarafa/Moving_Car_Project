/**
 * @file LED_prog.c
 * @brief LED Module Implementation File
 *
 * This file contains the implementation of functions for controlling LEDs.
 * It includes functions to initialize, turn on, and turn off LEDs based on their configuration.
 *
 * @note This file assumes that the LED_interface.h and DIO_interface.h files are properly included.
 *
 * @date 2023-08-21
 * @author Arafa Arafa
 */

#include "LED_inteface.h"

led_enu_return_state_t LED_init(const led_str_config_t *ptr_str_led_config)
{
	led_enu_return_state_t enu_return_state = LED_OK; 
	dio_enu_return_state_t enu_dio_api_return_state = DIO_OK;
	if(ptr_str_led_config != NULL){
	
		enu_dio_api_return_state = DIO_init(ptr_str_led_config->enu_port, ptr_str_led_config->enu_pin, DIO_PIN_OUTPUT);
		if(enu_dio_api_return_state == DIO_OK){
			enu_return_state = LED_OK;
		}else if (enu_dio_api_return_state == DIO_INVALID_PIN){
			enu_return_state = LED_INVALID_PIN;
		}else if (enu_dio_api_return_state == DIO_INVALID_PORT){
			enu_return_state = LED_INVALID_PORT;
		}else{
			
		}

	}else{

		enu_return_state = LED_NULL_PTR;
	}
	return enu_return_state; 
}

led_enu_return_state_t LED_off(const led_str_config_t *ptr_str_led_config)
{
	led_enu_return_state_t enu_return_state = LED_OK;
	dio_enu_return_state_t enu_dio_api_return_state = DIO_OK;
	
	if(ptr_str_led_config != NULL){
		enu_dio_api_return_state = DIO_write_pin (ptr_str_led_config->enu_port, ptr_str_led_config->enu_pin, DIO_PIN_LOW_LEVEL);
		if(enu_dio_api_return_state == DIO_OK){
			enu_return_state = LED_OK;
			}else if (enu_dio_api_return_state == DIO_INVALID_PIN){
			enu_return_state = LED_INVALID_PIN;
			}else if (enu_dio_api_return_state == DIO_INVALID_PORT){
			enu_return_state = LED_INVALID_PORT;
			}else{
			
		}

	}else{

		enu_return_state = LED_NULL_PTR;
	}
	
	
	return enu_return_state;
}

led_enu_return_state_t LED_on(const led_str_config_t *ptr_str_led_config)
{

	led_enu_return_state_t enu_return_state = LED_OK;
	dio_enu_return_state_t enu_dio_api_return_state = DIO_OK;
	
	
	if(ptr_str_led_config != NULL){
		
		enu_dio_api_return_state = DIO_write_pin (ptr_str_led_config->enu_port, ptr_str_led_config->enu_pin, DIO_PIN_HIGH_LEVEL);
		if(enu_dio_api_return_state == DIO_OK){
			enu_return_state = LED_OK;
		}else if (enu_dio_api_return_state == DIO_INVALID_PIN){
			enu_return_state = LED_INVALID_PIN;
		}else if (enu_dio_api_return_state == DIO_INVALID_PORT){
			enu_return_state = LED_INVALID_PORT;
		}else{
		}

		}else{

			enu_return_state = LED_NULL_PTR;
		}
	return enu_return_state;
}