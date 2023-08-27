/**
 * @file BUTTON_interface.h
 * @brief Button Interface Header File
 *
 * This header file defines an interface for working with buttons.
 * It includes button state enumeration, return state enumeration, and a configuration structure.
 *
 * @note This file should be included by modules that interact with buttons.
 *       Make sure to include the necessary DIO (Digital I/O) header file.
 *
 * @date 2023-08-21 
 * 
 * @author Arafa Arafa
 */

#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_
#include "BUTTON_config.h"
#include "../../MCAL/DIO/DIO_interface.h"


/**
 * @brief Button states enumeration.
 *
 * This enumeration defines the possible states of a button:
 * - #BTN_PUSHED: The button is currently pushed (pressed).
 * - #BTN_RELEASED: The button is currently released.
 */
typedef enum{
	BTN_PUSHED,
	BTN_RELEASED,
}btn_enu_state_t;


/**
 * @brief Button return states enumeration.
 *
 * This enumeration defines the possible return states for button-related operations:
 * - #BTN_E_OK: Operation was successful.
 * - #BTN_NOT_OK: Operation failed.
 */
typedef enum{
	BTN_E_OK,
	BTN_NOT_OK
}btn_enu_return_state_t;


/**
 * @brief Button configuration structure.
 *
 * This structure holds the configuration settings for a button.
 * It includes the port and pin information for the button's connection.
 */
typedef struct {
    dio_enu_port_t enu_port; /**< The port to which the button is connected. */
    dio_enu_pin_t enu_pin;   /**< The pin to which the button is connected. */
} btn_str_config_t;


/**
 * @brief Initialize a button based on its configuration.
 *
 * This function initializes a button by configuring its associated GPIO pin as an input.
 *
 * @param ptr_str_btn_config Pointer to the button's configuration structure.
 * @return The return state of the button initialization.
 *     - #BTN_E_OK: Button initialization successful.
 *     - #BTN_NOT_OK: Button initialization failed due to a null configuration pointer.
 */
btn_enu_return_state_t BTN_init(const btn_str_config_t *ptr_str_btn_config);



/**
 * @brief Get the state of a button (pushed or released).
 *
 * This function retrieves the state of a button, considering debounce and checking time.
 *
 * @param ptr_str_btn_config Pointer to the button's configuration structure.
 * @param ptr_enu_btn_state Pointer to store the retrieved button state.
 * @return The return state of the button state retrieval.
 *     - #BTN_E_OK: Button state retrieval successful.
 *     - #BTN_NOT_OK: Button state retrieval failed due to null configuration pointers.
 */
btn_enu_return_state_t BTN_get_state(const btn_str_config_t *ptr_str_btn_config, btn_enu_state_t *ptr_enu_btn_state);


#endif /* BUTTON_INTERFACE_H_ */