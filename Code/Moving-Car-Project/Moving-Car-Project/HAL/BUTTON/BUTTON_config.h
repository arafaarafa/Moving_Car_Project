/**
 * @file BUTTON_config.h
 * @brief Button Configuration Header File
 *
 * This header file defines configuration parameters for button-related operations.
 * It includes debounce threshold and checking time values for button handling.
 *
 * @note This file should be included by modules that interact with buttons.
 *       Modify the values below to customize button behavior as needed.
 *
 * @date 2023-08-24
 * 
 * @author Arafa Arafa
 */

#ifndef BUTTON_CONFIG_H_
#define BUTTON_CONFIG_H_

/**
 * @brief Debounce threshold for button press detection.
 *
 * This defines the time threshold (in milliseconds) used to debounce button presses.
 * It specifies the minimum time that a button signal must be stable before considering it valid.
 * Adjust this value based on the characteristics of your hardware and button components.
 */
#define BUTTON_DEBOUNCE_THRESHOLD    20

/**
 * @brief Checking time interval for button state.
 *
 * This defines the time interval (in milliseconds) at which the button state is checked.
 * It specifies how frequently the program should poll the button status to detect changes.
 * A shorter interval increases responsiveness but may also increase CPU load.
 * Adjust this value to achieve a suitable balance between responsiveness and efficiency.
 */
#define BUTTON_CHECKING_TIME    100

#endif /* BUTTON_CONFIG_H_ */