/**
 * @file CAR_CONTROL_interface.h
 * @brief Car Control Interface Header File
 *
 * This header file defines the interface for controlling a car's operations, such as
 * movement and stopping, using motor configurations.
 *
 * It includes function declarations for various car control operations.
 *
 * @note This file should be included by modules that need to control the car's behavior.
 *       Make sure to include the necessary motor configuration headers as well.
 *
 * @date 2023-08-21 
 * 
 * @author Arafa Arafa
 */


#ifndef CAR_CONTRO_INTERFACE_H_
#define CAR_CONTRO_INTERFACE_H_

#include "../motor/MOTOR_interface.h"


/**
 * @brief Enumeration defining the return states for car-related operations.
 *
 * This enumeration defines the possible return states that indicate the outcome
 * of various car-related operations.
 */
typedef enum car_enu_return_state_t
{
    CAR_OK,         /**< Operation was successful. */
    CAR_NOK,        /**< Operation failed due to an error. */
    CAR_NULL_PTR    /**< Operation failed due to a null pointer. */
} car_enu_return_state_t;


/**
 * @brief Initialize the car with two motors.
 *
 * This function initializes the car by initializing two motors with the provided motor configurations.
 *
 * @param ptr_str_motor_1 Pointer to the configuration structure of the first motor.
 * @param ptr_str_motor_2 Pointer to the configuration structure of the second motor.
 * @return The return state of the car initialization.
 *     - #CAR_OK: Car initialization successful.
 *     - #CAR_NOK: Car initialization failed due to motor initialization errors.
 *     - #CAR_NULL_PTR: One or both motor configuration pointers are NULL.
 */
car_enu_return_state_t CAR_INIT(const motor_str_config_t *ptr_str_motor_1,const motor_str_config_t *ptr_str_motor_2);

			
			
/**
 * @brief Move the car forward using two motors.
 *
 * This function moves the car forward by activating the forward motion of two motors.
 *
 * @param ptr_str_motor_1 Pointer to the configuration structure of the first motor.
 * @param ptr_str_motor_2 Pointer to the configuration structure of the second motor.
 * @return The return state of the car forward operation.
 *     - #CAR_OK: Car moved forward successfully.
 *     - #CAR_NOK: Car forward operation failed due to motor errors.
 *     - #CAR_NULL_PTR: One or both motor configuration pointers are NULL.
 */
car_enu_return_state_t CAR_FORWARD(const motor_str_config_t *ptr_str_motor_1,const motor_str_config_t *ptr_str_motor_2);


/**
 * @brief Move the car in a reverse right direction using two motors.
 *
 * This function moves the car in a reverse right direction by activating the forward motion of one motor and the backward motion of another motor.
 *
 * @param ptr_str_motor_1 Pointer to the configuration structure of the first motor.
 * @param ptr_str_motor_2 Pointer to the configuration structure of the second motor.
 * @return The return state of the car reverse right operation.
 *     - #CAR_OK: Car moved in reverse right direction successfully.
 *     - #CAR_NOK: Car reverse right operation failed due to motor errors.
 *     - #CAR_NULL_PTR: One or both motor configuration pointers are NULL.
 */
car_enu_return_state_t CAR_REVERSE_RIGHT(const motor_str_config_t *ptr_str_motor_1,const motor_str_config_t *ptr_str_motor_2);



/**
 * @brief Stop the car by stopping two motors.
 *
 * This function stops the car by halting the motion of two motors.
 *
 * @param ptr_str_motor_1 Pointer to the configuration structure of the first motor.
 * @param ptr_str_motor_2 Pointer to the configuration structure of the second motor.
 * @return The return state of the car stop operation.
 *     - #CAR_OK: Car stopped successfully.
 *     - #CAR_NOK: Car stop operation failed due to motor errors.
 *     - #CAR_NULL_PTR: One or both motor configuration pointers are NULL.
 */
car_enu_return_state_t CAR_STOP(const motor_str_config_t *ptr_str_motor_1,const motor_str_config_t *ptr_str_motor_2);

#endif /* CAR_CONTROL_INTERFACE_H_ */