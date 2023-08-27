/**
 * @file MOTOR_interface.h
 * @brief MOTOR Module Interface Header File
 *
 * This header file defines the interface for controlling motors.
 * It includes a data structure for motor configuration, an enumeration for return states,
 * and function declarations for initializing, moving forward, moving backward, and stopping motors.
 *
 * @note This file should be included by modules that need to interact with motors.
 *       Ensure that the necessary standard libraries, DIO_interface.h, and required configurations are properly included.
 *
 * @date 2023-08-21
 * @author Arafa Arafa
 */


#ifndef MOTOR_H_
#define MOTOR_H_


#include "../../MCAL/DIO/DIO_interface.h"


/**
 * @brief Configuration structure for a motor.
 *
 * This structure holds the configuration settings for a motor, including its associated GPIO pins.
 */
typedef struct motor_str_config_t {
    dio_enu_port_t port;      /**< GPIO port associated with the motor. */
    dio_enu_pin_t  pin_num1;  /**< GPIO pin number for the first control signal. */
    dio_enu_pin_t  pin_num2;  /**< GPIO pin number for the second control signal. */
} motor_str_config_t;



/**
 * @brief Enumeration defining return states for motor functions.
 *
 * This enumeration defines the possible return states for functions related to motor control.
 */
typedef enum motor_enu_return_state_t {
    MOTOR_OK,   /**< Operation was successful. */
    MOTOR_NOK   /**< Operation failed. */
} motor_enu_return_state_t;
	


/**
 * @brief Initialize a motor based on its configuration.
 *
 * This function initializes a motor by configuring its associated GPIO pins as outputs.
 *
 * @param ptr_str_motor_config Pointer to the motor's configuration structure.
 * @return The return state of the motor initialization.
 *     - #MOTOR_OK: Motor initialization successful.
 *     - #MOTOR_NOK: Motor initialization failed.
 */
motor_enu_return_state_t MOTOR_INIT(const motor_str_config_t *ptr_str_motor_config);

/**
 * @brief Move the motor forward based on its configuration.
 *
 * This function moves the motor forward by setting its associated GPIO pins accordingly.
 *
 * @param ptr_str_motor_config Pointer to the motor's configuration structure.
 * @return The return state of moving the motor forward.
 *     - #MOTOR_OK: Motor moved forward successfully.
 *     - #MOTOR_NOK: Motor movement forward failed.
 */
motor_enu_return_state_t MOTOR_FORWARD(const motor_str_config_t* ptr_str_motor_config);

/**
 * @brief Move the motor backward based on its configuration.
 *
 * This function moves the motor backward by setting its associated GPIO pins accordingly.
 *
 * @param ptr_str_motor_config Pointer to the motor's configuration structure.
 * @return The return state of moving the motor backward.
 *     - #MOTOR_OK: Motor moved backward successfully.
 *     - #MOTOR_NOK: Motor movement backward failed.
 */
motor_enu_return_state_t MOTOR_BACKWARD(const motor_str_config_t* ptr_str_motor_config);

/**
 * @brief Stop the motor based on its configuration.
 *
 * This function stops the motor by setting its associated GPIO pins accordingly.
 *
 * @param ptr_str_motor_config Pointer to the motor's configuration structure.
 * @return The return state of stopping the motor.
 *     - #MOTOR_OK: Motor stopped successfully.
 *     - #MOTOR_NOK: Motor stop failed.
 */
motor_enu_return_state_t MOTOR_STOP(const motor_str_config_t* ptr_str_motor_config);





#endif /* MOTOR_INTERFACE_H_ */