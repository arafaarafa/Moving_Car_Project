/**
 * @file MOTOR_prog.c
 * @brief MOTOR Module Implementation File
 *
 * This file contains the implementation of functions for controlling motors.
 * It includes functions to initialize, move forward, move backward, and stop motors
 * based on their configuration.
 *
 * @note This file assumes that the MOTOR_interface.h and DIO_interface.h files are properly included.
 *
 * @date 2023-08-21
 * @author Arafa Arafa
 */


#include "MOTOR_interface.h"


motor_enu_return_state_t MOTOR_INIT(const motor_str_config_t *ptr_str_motor_config)
{
	
	dio_enu_return_state_t enu_return_state_pin_1 = DIO_init(ptr_str_motor_config->port,ptr_str_motor_config->pin_num1,DIO_PIN_OUTPUT);
	dio_enu_return_state_t enu_return_state_pin_2 = DIO_init(ptr_str_motor_config->port,ptr_str_motor_config->pin_num2,DIO_PIN_OUTPUT);
	if((enu_return_state_pin_1 == DIO_OK) && (enu_return_state_pin_2 == DIO_OK ))
	{
		return MOTOR_OK;
	}
	else
	{
		return MOTOR_NOK;
	}
}

motor_enu_return_state_t MOTOR_FORWARD(const motor_str_config_t *ptr_str_motor_config)
{
	dio_enu_return_state_t enu_return_state_pin_1 = DIO_write_pin(ptr_str_motor_config->port,ptr_str_motor_config->pin_num1,DIO_PIN_HIGH_LEVEL);
	dio_enu_return_state_t enu_return_state_pin_2 = DIO_write_pin(ptr_str_motor_config->port,ptr_str_motor_config->pin_num2,DIO_PIN_LOW_LEVEL);
	if((enu_return_state_pin_1 == DIO_OK) && (enu_return_state_pin_2 == DIO_OK))
	{   
		return MOTOR_OK;
	}
	else
	{
		return MOTOR_NOK;
	}
}

motor_enu_return_state_t MOTOR_BACKWARD(const motor_str_config_t *ptr_str_motor_config)
{
	dio_enu_return_state_t enu_return_state_pin_1 = DIO_write_pin(ptr_str_motor_config->port,ptr_str_motor_config->pin_num1,DIO_PIN_LOW_LEVEL);
	dio_enu_return_state_t enu_return_state_pin_2 = DIO_write_pin(ptr_str_motor_config->port,ptr_str_motor_config->pin_num2,DIO_PIN_HIGH_LEVEL);
	
	if((enu_return_state_pin_1==DIO_OK) && (enu_return_state_pin_2 == DIO_OK))
	{    
		return MOTOR_OK;
	}
	else
	{
		return MOTOR_NOK;
	}
}

motor_enu_return_state_t MOTOR_STOP(const motor_str_config_t *ptr_str_motor_config)
{
	dio_enu_return_state_t enu_return_state_pin_1 = DIO_write_pin(ptr_str_motor_config->port,ptr_str_motor_config->pin_num1,DIO_PIN_LOW_LEVEL);
	dio_enu_return_state_t enu_return_state_pin_2 = DIO_write_pin(ptr_str_motor_config->port,ptr_str_motor_config->pin_num2,DIO_PIN_LOW_LEVEL);
	
	if( (enu_return_state_pin_1 == DIO_OK) && (enu_return_state_pin_2 == DIO_OK))
	{   
		return MOTOR_OK;
	}
	else
	{
		return MOTOR_NOK;
	}
}