/**
 * @file APP_interface.h
 * @brief Application Interface Header File
 *
 * This header file provides declarations for the application module's interface functions,
 * macros, and data types. It includes constants, function prototypes, and enumerations
 * relevant to the application's functionality.
 *
 * @date 2023-08-21
 * @author Arafa Arafa
 */

#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

/** @brief CPU Frequency for delay calculation */
#define  F_CPU		8000000UL


#include "../HAL/BUTTON/BUTTON_interface.h"
#include "../HAL/LED/LED_inteface.h"
#include "../HAL/EXTI_manager/EXTI_manager_interface.h"
#include "../HAL/CAR_CONTROL/CAR_CONTROL_interface.h"
#include "../HAL/TIMER_manager/TIMER_manger_interface.h"
#include "../STD_LIB/bit_math.h"
#include "../STD_LIB/std_types.h"
/** @brief Motor 1 ID for application */
#define	APP_MOTOR_1					0

/** @brief Motor 2 ID for application */
#define	APP_MOTOR_2					1

/** @brief Maximum number of buttons in the application */
#define APP_BUTTON_MAX_NUM			2

/** @brief Maximum number of LEDs in the application */
#define APP_LED_MAX_NUM				4

/** @brief Start index for buttons in the application */
#define APP_BTN_START_INDEX			0

/** @brief Initial value for Timer 1 */
#define APP_TIMER_1_INIT_VALUE		61628

/** @brief Initial value for Timer 0 */
#define APP_TIMER_0_INIT_VALUE		240

/**
 * @brief Enumeration for the application's state based on button press
 */
typedef enum {
    BTN_START = 0, /**< Start button pressed state */
    BTN_STOP       /**< Stop button pressed state */
} app_enu_state_t;





/**
 * @brief LED IDs for the application
 */
typedef uint8_t u8_en_ledIdType;

/** @brief LED ID for the short side LED */
#define LED_SHORT_SIDE ((u8_en_ledIdType)0x00)

/** @brief LED ID for the long side LED */
#define LED_LONG_SIDE ((u8_en_ledIdType)0x01)

/** @brief LED ID for the stop LED */
#define LED_STOP ((u8_en_ledIdType)0x02)

/** @brief LED ID for the rotate LED */
#define LED_ROTATE ((u8_en_ledIdType)0x03)


/**
 * @brief Start the application's main functionality.
 */
void APP_start(void);


#endif /* APP_INTERFACE_H_ */