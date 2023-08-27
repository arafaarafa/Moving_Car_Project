/**
 * @file ext_interrupt.c
 * @brief External Interrupt Implementation
 *
 * This source file provides the implementation for initializing, enabling, disabling,
 * and setting callback functions for external interrupts. It also includes the
 * interrupt service routines (ISRs) for handling external interrupt events.
 *
 * @date 2023-08-21
 * @author Arafa Arafa
 */

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "../AVR_ARCH/ISR_interface.h"

/** @brief Function pointer to hold callback function for external interrupt 0 */
static void (*callback_EXT_0)(void);

/** @brief Function pointer to hold callback function for external interrupt 1 */
static void (*callback_EXT_1)(void);

exti_enu_return_state_t ext_interrupt_init(exti_interrupt_no_t copy_enu_exti_interrupt_no, exti_edge_detection_t copy_enu_edge_detection){
    exti_enu_return_state_t ret_val=EXTI_E_OK;
    switch (copy_enu_exti_interrupt_no)
    {
    case EXTI_0:
        MCUCR_ADD |= copy_enu_edge_detection;	
		SREG_ADD |= (1<<Globle_INT);
        break;

    case EXTI_1:
        MCUCR_ADD |= (copy_enu_edge_detection<<INT1_MODE_INDEX);	
		SREG_ADD |= (1<<Globle_INT);
        break;

    case EXTI_2:
        /* code */
        break;    
    
    default:
        break;
    }

    return ret_val;
}

exti_enu_return_state_t ext_interrupt_enable(exti_interrupt_no_t copy_enu_exti_interrupt_no){
    exti_enu_return_state_t ret_val=EXTI_E_OK;
    switch (copy_enu_exti_interrupt_no)
    {
		sei();
    case EXTI_0:
        GICR_ADD |= (1<<INT0_Globle);
        break;

    case EXTI_1:
        GICR_ADD |= (1<<INT1_Globle);

        break;

    case EXTI_2:
        /* code */
        break;    
    
    default:
        break;
    }
    return ret_val;
}

exti_enu_return_state_t ext_interrupt_disable(exti_interrupt_no_t copy_enu_exti_interrupt_no){
    exti_enu_return_state_t ret_val=EXTI_E_OK;
    switch (copy_enu_exti_interrupt_no)
    {
    case EXTI_0:
       GICR_ADD &= ~(1<<INT0_Globle);

        break;

    case EXTI_1:
        GICR_ADD &= ~(1<<INT1_Globle);

        break;

    case EXTI_2:
        /* code */
        break;    
    
    default:
        break;
    }
    return ret_val;

}

exti_enu_return_state_t ext_interrupt_set_callback_init(exti_interrupt_no_t copy_enu_exti_interrupt_no ,void(*callback)(void)){
    exti_enu_return_state_t ret_val=EXTI_E_OK;
    switch (copy_enu_exti_interrupt_no)
    {
    case EXTI_0:
        GICR_ADD &= ~(1<<INT0_Globle);
        callback_EXT_0 = callback;
		
        break;

    case EXTI_1:
        GICR_ADD &= ~(1<<INT1_Globle);
        callback_EXT_1 = callback;
        break;

    case EXTI_2:
        /* code */
        break;    
    
    default:
        break;
    }
    return ret_val;
}

/**
 * @brief Interrupt Service Routine for External Interrupt 0 (INT0)
 */
ISR(EXT_INT0)
{
	callback_EXT_0();
}


/* Uncomment and implement ISR for external interrupt 1 (INT1) if needed */
/*
ISR(EXT_INT1)
{
    callback_EXT_1();
}
*/

/* Uncomment and implement ISR for external interrupt 2 (INT2) if needed */
/*
ISR(EXT_INT2)
{
    //callback_int2();
}
*/