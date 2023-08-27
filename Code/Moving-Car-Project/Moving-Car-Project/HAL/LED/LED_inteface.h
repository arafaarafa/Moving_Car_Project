/**
 * @file LED_interface.h
 * @brief LED Module Interface Header File
 *
 * This header file defines the interface for controlling LEDs.
 * It includes data structures, enumerations, and function declarations for initializing,
 * turning on, and turning off LEDs based on their configuration.
 *
 * @note This file should be included by modules that need to interact with LEDs.
 *       Ensure that the necessary standard libraries, DIO_interface.h, and the required
 *       configurations are properly included.
 *
 * @date 2023-08-21
 * @author Arafa Arafa
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "../../MCAL/DIO/DIO_interface.h"


/**
 * @brief Enumeration defining LED states.
 *
 * This enumeration defines the possible states of an LED: OFF or ON.
 */
typedef enum {
    LED_OFF,   /**< LED is turned off. */
    LED_ON     /**< LED is turned on. */
} led_enu_state_t;

/**
 * @brief Enumeration defining return states for LED functions.
 *
 * This enumeration defines the possible return states for functions related to LED management.
 */
typedef enum {
    LED_OK,                /**< Operation was successful. */
    LED_INVALID_PIN,       /**< LED operation failed due to an invalid pin. */
    LED_INVALID_PORT,      /**< LED operation failed due to an invalid port. */
    LED_NULL_PTR           /**< LED operation failed due to a null configuration pointer. */
} led_enu_return_state_t;


/**
 * @brief Configuration structure for LED.
 *
 * This structure holds the configuration settings for an LED.
 * It includes the GPIO port and pin associated with the LED.
 */
typedef struct {
    dio_enu_port_t enu_port;  /**< GPIO port associated with the LED. */
    dio_enu_pin_t  enu_pin;   /**< GPIO pin associated with the LED. */
} led_str_config_t;


/**
 * @brief Initialize an LED based on its configuration.
 *
 * This function initializes an LED by configuring its associated GPIO pin as an output.
 *
 * @param ptr_str_led_config Pointer to the LED's configuration structure.
 * @return The return state of the LED initialization.
 *     - #LED_OK: LED initialization successful.
 *     - #LED_INVALID_PIN: LED initialization failed due to an invalid pin.
 *     - #LED_INVALID_PORT: LED initialization failed due to an invalid port.
 *     - #LED_NULL_PTR: LED initialization failed due to a null configuration pointer.
 */
led_enu_return_state_t LED_init(const led_str_config_t *ptr_str_led_config);

/**
 * @brief Turn off an LED based on its configuration.
 *
 * This function turns off an LED by writing a low-level signal to its associated GPIO pin.
 *
 * @param ptr_str_led_config Pointer to the LED's configuration structure.
 * @return The return state of turning off the LED.
 *     - #LED_OK: LED turned off successfully.
 *     - #LED_INVALID_PIN: LED turn-off failed due to an invalid pin.
 *     - #LED_INVALID_PORT: LED turn-off failed due to an invalid port.
 *     - #LED_NULL_PTR: LED turn-off failed due to a null configuration pointer.
 */
led_enu_return_state_t LED_off(const led_str_config_t *ptr_str_led_config);

/**
 * @brief Turn on an LED based on its configuration.
 *
 * This function turns on an LED by writing a high-level signal to its associated GPIO pin.
 *
 * @param ptr_str_led_config Pointer to the LED's configuration structure.
 * @return The return state of turning on the LED.
 *     - #LED_OK: LED turned on successfully.
 *     - #LED_INVALID_PIN: LED turn-on failed due to an invalid pin.
 *     - #LED_INVALID_PORT: LED turn-on failed due to an invalid port.
 *     - #LED_NULL_PTR: LED turn-on failed due to a null configuration pointer.
 */
led_enu_return_state_t LED_on(const led_str_config_t *ptr_str_led_config);




#endif /* LED_INTERFACE_H_ */