/**
 * @file EXTI_interface.h
 * @brief External Interrupt Interface Header File
 *
 * This header file provides declarations for the external interrupt module's interface functions
 * and related data types. It includes enums for interrupt numbers and edge detection, as well as
 * function prototypes for initializing, enabling, disabling, and setting callback functions
 * for external interrupts.
 *
 * @date 2023-08-21
 * @author Arafa Arafa
 */

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H



/**
 * @brief Enumeration for External Interrupt return states.
 */
typedef enum {
    EXTI_E_OK = 0,       /**< Operation performed successfully. */
    EXTI_E_NOK       /**< Operation performed with issues or errors. */
} exti_enu_return_state_t;


/**
 * @brief Enumeration for external interrupt numbers.
 */
typedef enum {
    EXTI_0 = 0,   /**< External Interrupt 0. */
    EXTI_1,       /**< External Interrupt 1. */
    EXTI_2        /**< External Interrupt 2. */
} exti_interrupt_no_t;


/**
 * @brief Enumeration for external interrupt edge detection types.
 */
typedef enum {
    EXTI_LOW_LEVEL,       /**< Low-level edge detection. */
    EXTI_LOGICAL_CHANGE,  /**< Logical change edge detection. */
    EXTI_FALLING_EDGE,    /**< Falling edge detection. */
    EXTI_RISING_EDGE      /**< Rising edge detection. */
} exti_edge_detection_t;




/**
 * @brief Initialize the configuration of an external interrupt.
 *
 * This function initializes the configuration of an external interrupt based on the provided
 * interrupt number and edge detection condition.
 *
 * @param copy_enu_exti_interrupt_no The interrupt number to configure.
 * @param copy_enu_edge_detection The edge detection condition for the interrupt.
 * @return The return state of the initialization.
 *     - #EXTI_E_OK: External interrupt initialization successful.
 *     - #EXTI_E_NOK: External interrupt initialization failed.
 */
exti_enu_return_state_t ext_interrupt_init(exti_interrupt_no_t copy_enu_exti_interrupt_no, exti_edge_detection_t copy_enu_edge_detection);

/**
 * @brief Enable an external interrupt.
 *
 * This function enables a specified external interrupt based on the provided interrupt number.
 *
 * @param copy_enu_exti_interrupt_no The interrupt number to enable.
 * @return The return state of enabling the interrupt.
 *     - #EXTI_E_OK: External interrupt enabled successfully.
 *     - #EXTI_E_NOK: External interrupt enabling failed.
 */
exti_enu_return_state_t ext_interrupt_enable(exti_interrupt_no_t copy_enu_exti_interrupt_no);

/**
 * @brief Disable an external interrupt.
 *
 * This function disables a specified external interrupt based on the provided interrupt number.
 *
 * @param copy_enu_exti_interrupt_no The interrupt number to disable.
 * @return The return state of disabling the interrupt.
 *     - #EXTI_E_OK: External interrupt disabled successfully.
 *     - #EXTI_E_NOK: External interrupt disabling failed.
 */
exti_enu_return_state_t ext_interrupt_disable(exti_interrupt_no_t copy_enu_exti_interrupt_no);

/**
 * @brief Set a callback function for an external interrupt.
 *
 * This function sets a callback function to be executed when the specified external interrupt occurs.
 *
 * @param copy_enu_exti_interrupt_no The interrupt number to set the callback for.
 * @param callback Pointer to the callback function.
 * @return The return state of setting the callback function.
 *     - #EXTI_E_OK: Callback function set successfully.
 *     - #EXTI_E_NOK: Callback function setting failed.
 */
exti_enu_return_state_t ext_interrupt_set_callback_init(exti_interrupt_no_t copy_enu_exti_interrupt_no ,void(*callback)(void));

#endif /* EXTI_interface.h */