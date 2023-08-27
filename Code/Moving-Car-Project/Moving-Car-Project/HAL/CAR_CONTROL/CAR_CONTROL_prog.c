/**
 * @file CAR_CONTROL_prog.c
 * 
 * @brief Car Control Source File
 * 
 * @details Implementation for controlling a car's operations, such as movement and stopping, using motor configurations.
 * 
 * @date 2023-08-21 
 * 
 * @author Arafa Arafa
 */


#include"CAR_CONTROL_interface.h"


car_enu_return_state_t CAR_INIT(const motor_str_config_t *ptr_str_motor_1,const motor_str_config_t *ptr_str_motor_2)
{
	car_enu_return_state_t enu_return_state=CAR_OK;
	
	motor_enu_return_state_t enu_motor_error_1 ;
	motor_enu_return_state_t enu_motor_error_2 ;
	if((ptr_str_motor_1 !=NULL) && (ptr_str_motor_2 != NULL))
	{
		enu_motor_error_1 = MOTOR_INIT(ptr_str_motor_1);
		enu_motor_error_2 = MOTOR_INIT(ptr_str_motor_2);
		if((enu_motor_error_1 != MOTOR_OK) || (enu_motor_error_2 != MOTOR_OK)){
			enu_return_state=CAR_NOK;
		}else{
			// Car initialization successful with both motors initialized.
		}
	}
	else
	{
		enu_return_state=CAR_NULL_PTR;
	}
	return enu_return_state;
}


car_enu_return_state_t CAR_FORWARD(const motor_str_config_t *ptr_str_motor_1,const motor_str_config_t *ptr_str_motor_2)
{
	car_enu_return_state_t enu_return_state=CAR_OK;
	motor_enu_return_state_t enu_motor_error_1;
	motor_enu_return_state_t enu_motor_error_2;
	
	if((ptr_str_motor_1 !=NULL) && (ptr_str_motor_2 != NULL))
	{
		enu_motor_error_1 = MOTOR_FORWARD(ptr_str_motor_1);
		enu_motor_error_2 = MOTOR_FORWARD(ptr_str_motor_2);
		if((enu_motor_error_1 != MOTOR_OK) || (enu_motor_error_2 != MOTOR_OK)){
			enu_return_state=CAR_NOK;
		}else{
            // Car moved forward successfully with both motors operating in forward motion.
		}
	}
	else
	{
		enu_return_state=CAR_NULL_PTR;
	}
	return enu_return_state;
}


car_enu_return_state_t CAR_REVERSE_RIGHT(const motor_str_config_t *ptr_str_motor_1,const motor_str_config_t *ptr_str_motor_2)
{
	car_enu_return_state_t enu_return_state=CAR_OK;
	motor_enu_return_state_t enu_motor_error_1;
	motor_enu_return_state_t enu_motor_error_2;
	if((ptr_str_motor_1 !=NULL) && (ptr_str_motor_2 != NULL))
	{
		enu_motor_error_1 = MOTOR_FORWARD(ptr_str_motor_1);
		enu_motor_error_2 = MOTOR_BACKWARD(ptr_str_motor_2);
		if((enu_motor_error_1 != MOTOR_OK) || (enu_motor_error_2 != MOTOR_OK)){
			enu_return_state=CAR_NOK;
			}else{
				// Car moved in reverse right direction successfully with one motor forward and another motor backward.

		}
	}
	else
	{
		enu_return_state=CAR_NULL_PTR;
	}
	return enu_return_state;
}


car_enu_return_state_t CAR_STOP(const motor_str_config_t *ptr_str_motor_1,const motor_str_config_t *ptr_str_motor_2)
{
	car_enu_return_state_t enu_return_state=CAR_OK;
	motor_enu_return_state_t enu_motor_error_1;
	motor_enu_return_state_t enu_motor_error_2;
	if((ptr_str_motor_1 !=NULL) && (ptr_str_motor_2 != NULL))
	{
		enu_motor_error_1 = MOTOR_STOP(ptr_str_motor_1);
		enu_motor_error_2 = MOTOR_STOP(ptr_str_motor_2);
		if((enu_motor_error_1 != MOTOR_OK) || (enu_motor_error_2 != MOTOR_OK)){
			enu_return_state=CAR_NOK;
			}else{
			// Car stopped successfully with both motors halted.

		}
	}
	else
	{
		enu_return_state=CAR_NULL_PTR;
	}
	return enu_return_state;
}