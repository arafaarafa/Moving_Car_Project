/**
 * @file EXTI_private.h
 * @brief External Interrupt Private Register Definitions
 *
 * This private header file provides the register definitions used for configuring
 * external interrupts in microcontrollers. It defines the addresses of the relevant
 * registers and their bit indices for controlling global interrupt enable and interrupt modes.
 *
 * @date 2023-08-21
 * @author Arafa Arafa
 */


#ifndef EXT_INTERRUPT_PRIVATE_REG_H_
#define EXT_INTERRUPT_PRIVATE_REG_H_
#include "../../STD_LIB/std_types.h"

/** @brief General Interrupt Control Register (GICR) address */
#define GICR_ADD			 (*((volatile uint8_t *) 0x5B))

/** @brief Bit index for enabling global interrupt for INT0 */
#define INT0_Globle		6

/** @brief Bit index for enabling global interrupt for INT1 */
#define INT1_Globle		7

/** @brief Bit index for enabling global interrupt for INT2 */
#define INT2_Globle		5

/** @brief MCU Control Register (MCUCR) address */
#define MCUCR_ADD			(*((volatile uint8_t *) 0x55))

/** @brief Bit index for interrupt mode configuration of INT0 */
#define INT0_MODE_INDEX	0

/** @brief Bit index for interrupt mode configuration of INT1 */
#define INT1_MODE_INDEX	2

/** @brief MCU Control and Status Register (MCUCSR) address */
#define MCUCSR_ADD			(*((volatile uint8_t *) 0x54))

/** @brief Bit index for interrupt mode configuration of INT2 */
#define INT2_MODE_INDEX	6

/** @brief Status Register (SREG) address */
#define SREG_ADD			(*((volatile uint8_t *) 0x5F))

/** @brief Bit index for enabling global interrupts (I-bit) */
#define Globle_INT		7



#endif /* EXT_INTERRUPT_PRIVATE_REG_H_ */