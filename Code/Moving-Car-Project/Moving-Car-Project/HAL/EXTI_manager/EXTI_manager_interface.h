/**
 * @file EXTI_manager_interface.h
 * @brief External Interrupt Manager Interface Header File
 *
 * This header file defines the interface for managing external interrupts.
 * It includes data structures and function declarations for configuring, enabling, and disabling
 * external interrupts using the EXTI module.
 *
 * @date 2023-08-21
 * @author Arafa Arafa
 */

#ifndef EXTI_MANAGER_INTERFACE_H_
#define EXTI_MANAGER_INTERFACE_H_

#include "../../STD_LIB/bit_math.h"
#include "../../STD_LIB/std_types.h"
#include "../../MCAL/EXTI/EXTI_interface.h"

/**
 * @brief Enumeration defining return states for external interrupt management.
 *
 * This enumeration defines the possible return states for functions related to external
 * interrupt management.
 */
typedef enum {
    EXTIM_E_OK = 0,       /**< Operation was successful. */
    EXTIM_E_NOK,          /**< Operation failed due to an error. */
    EXTIM_NULL_PTR        /**< Null pointer was encountered. */
} extim_enu_return_state_t;

/**
 * @brief Configuration structure for external interrupt.
 *
 * This structure holds the configuration settings for an external interrupt.
 * It includes the external interrupt number and the edge detection state that triggers the interrupt.
 */
typedef struct {
    exti_interrupt_no_t enu_exti_interrupt_no;    /**< External interrupt number. */
    exti_edge_detection_t enu_edge_detection;     /**< Edge detection state triggering the interrupt. */
} extim_str_config_t;

/**
 * @brief Initialize the configuration for an external interrupt.
 *
 * This function initializes the configuration for an external interrupt.
 *
 * @param ptr_str_extim_config Pointer to the external interrupt configuration structure.
 * @param ptr_callback_func Pointer to the callback function associated with the interrupt.
 * @return The return state of the external interrupt initialization.
 *     - #EXTIM_E_OK: External interrupt initialization successful.
 *     - #EXTIM_E_NOK: External interrupt initialization failed.
 */
extim_enu_return_state_t extim_init(extim_str_config_t *ptr_str_extim_config, ptr_to_v_fun_in_void_t ptr_callback_func);

/**
 * @brief Enable an external interrupt based on its configuration.
 *
 * This function enables an external interrupt based on its configuration.
 *
 * @param ptr_str_extim_config Pointer to the external interrupt configuration structure.
 * @return The return state of the external interrupt enable operation.
 *     - #EXTIM_E_OK: External interrupt enable operation successful.
 *     - #EXTIM_E_NOK: External interrupt enable operation failed.
 */
extim_enu_return_state_t extim_enable(extim_str_config_t *ptr_str_extim_config);

/**
 * @brief Disable an external interrupt based on its configuration.
 *
 * This function disables an external interrupt based on its configuration.
 *
 * @param ptr_str_extim_config Pointer to the external interrupt configuration structure.
 * @return The return state of the external interrupt disable operation.
 *     - #EXTIM_E_OK: External interrupt disable operation successful.
 *     - #EXTIM_E_NOK: External interrupt disable operation failed.
 */
extim_enu_return_state_t extim_disable(extim_str_config_t *ptr_str_extim_config);

#endif /* EXTI_MANAGER_INTERFACE_H_ */