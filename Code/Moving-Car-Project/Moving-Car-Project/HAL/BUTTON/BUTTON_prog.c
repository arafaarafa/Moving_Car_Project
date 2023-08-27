/**
 * @file BUTTON_prog.c
 * @brief Button Interface Implementation File
 *
 * This file implements functions to interact with buttons, including initialization and state retrieval.
 * It includes external dependencies for GPIO handling and button configuration.
 *
 * @note This file assumes that the BUTTON_interface.h and BUTTON_config.h files are properly included.
 *       Modify the code below as needed to match your hardware and requirements.
 *
 * @date 2023-08-21
 * 
 * @author Arafa Arafa
 */



#include "BUTTON_interface.h"
#include "BUTTON_config.h"
#include "../../MCAL/DIO/DIO_interface.h"

btn_enu_return_state_t BTN_init(const btn_str_config_t *ptr_str_btn_config)
{
	btn_enu_return_state_t enu_return_state = BTN_E_OK;
	if(ptr_str_btn_config != NULL){
		DIO_init (ptr_str_btn_config->enu_port, ptr_str_btn_config->enu_pin, DIO_PIN_INPUT);
	}else{
		enu_return_state = BTN_NOT_OK;
	}
	return enu_return_state;
}


btn_enu_return_state_t BTN_get_state(const btn_str_config_t *ptr_str_btn_config, btn_enu_state_t *ptr_enu_btn_state)
{
	btn_enu_return_state_t enu_return_state = BTN_E_OK;
	dio_enu_level_t enu_pin_state;
	uint16_t u16_button_time_counter = 0;
	uint16_t u16_debounceThreshold_counter = 0;
	if((ptr_str_btn_config != NULL) && (ptr_enu_btn_state != NULL)){
		 // Read the state of the button's associated GPIO pin.
		DIO_read_pin (ptr_str_btn_config->enu_port, ptr_str_btn_config->enu_pin, &enu_pin_state);
		if(enu_pin_state == DIO_PIN_LOW_LEVEL)
		{

			// Increment debounce threshold counter for stable low signal.
			u16_debounceThreshold_counter++;
			
			// Check button status within the checking time window.
			while(u16_button_time_counter < BUTTON_CHECKING_TIME){
				DIO_read_pin (ptr_str_btn_config->enu_port, ptr_str_btn_config->enu_pin, &enu_pin_state);
				if(enu_pin_state == DIO_PIN_LOW_LEVEL){
					u16_debounceThreshold_counter++;
				}else{
					// Button state changed, exit the loop.
				}
				u16_button_time_counter++;
			}
			
			// Determine button state based on the debounce threshold.
			if(u16_debounceThreshold_counter >= BUTTON_DEBOUNCE_THRESHOLD)
			{
				*ptr_enu_btn_state = BTN_PUSHED;
			}
			else
			{
				*ptr_enu_btn_state = BTN_RELEASED;
			}
			
		}
		else
		{
			*ptr_enu_btn_state = BTN_RELEASED;
		}
	}else{
		enu_return_state = BTN_NOT_OK;
	}
	return enu_return_state;
	
	
}

