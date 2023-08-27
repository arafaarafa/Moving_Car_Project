/**
 * @file APP_prog.c
 * @brief Application Implementation File
 *
 * This implementation file defines the functions and logic for the application's main
 * functionality. It includes the initialization, state handling, and helper functions
 * to control the application's behavior.
 *
 * @date 2023-08-21
 * @author Arafa Arafa
 */

#include "APP_interface.h"

/***************************************************************************/
/*******				Static function prototypes					*******/
/***************************************************************************/

static void APP_init(void);
static void APP_timer0OvfHandeler(void);
static void APP_timer1OvfHandeler(void);
static void APP_extInt0OvfHandeler(void);
static void APP_longSide(void);
static void APP_shortSide(void);
static void APP_stop(void);
static void App_rotate(void);
static void APP_startState(void);
static void APP_stopState(void);



/** @brief External Interrupt 0 configuration structure */
static extim_str_config_t gs_str_extim_config_0 ;

/** @brief Program state */
static app_enu_state_t gs_enu_app_state = BTN_STOP;

/** @brief Delay counter */
uint8_t volatile gv_u8_delay = 0;

/** @brief PWM counter */
uint8_t volatile gv_u8_pwm = 0;


/**
 * @brief LED configuration array
 *
 * This array holds the configuration for the LEDs used in the application.
 * Each entry in the array represents an LED with its associated port and pin.
 */
const led_str_config_t gc_st_leds_config[] = {
    /**< LED_SHORT_SIDE: Short side LED configuration */
    {PORTA, PIN5},

    /**< LED_LONG_SIDE: Long side LED configuration */
    {PORTA, PIN6},

    /**< LED_STOP: Stop LED configuration */
    {PORTA, PIN7},

    /**< LED_ROTATE: Rotate LED configuration */
    {PORTB, PIN0}
};

/** @brief Buttons configuration structure */
const btn_str_config_t gc_str_btn_config[]={
	{PORTD,PIN3},
	{PORTD,PIN2}
};

/** @brief Motors configuration structure  */
const motor_str_config_t gc_str_motor_config[]={
	{
		PORTA,PIN3,PIN4
	},
	{
		PORTA,PIN0,PIN1
	}
};







// Will be used to generate delay 
const timerm_str_config_t gc_st_timer_1 = {
		TIMER_1 , TIMER_NORMAL_MODE , APP_TIMER_1_INIT_VALUE , ((uint16_t)NULL) , APP_timer1OvfHandeler
};

// Timer 0 configuration structure 
// Will be used to generate PWM
const timerm_str_config_t gc_st_timer_0 = {
	TIMER_0 , TIMER_NORMAL_MODE , APP_TIMER_0_INIT_VALUE , ((uint16_t)NULL) , APP_timer0OvfHandeler
};

void APP_start(void)
{
	// Initialize all modules used in the app
	APP_init();
	
	while(1)
	{
		while (gs_enu_app_state == BTN_STOP)
		{
			// Perform stop state routine 
			APP_stopState();
		}
		while (gs_enu_app_state == BTN_START)
		{
			// Perform start state routine
			APP_startState();
		}
	}
}

/**
 * @brief Initializes the application modules.
 *
 * This function initializes LEDs, buttons, motors, timers, and external interrupt for the application.
 */
void APP_init(void)
{
	// Initialize all LEDs
	for(uint8_t u8_index = U8_ZERO_VALUE ; u8_index < APP_LED_MAX_NUM ; u8_index++)
	{
		LED_init(&gc_st_leds_config[u8_index]);
	}
	
	// Initialize all buttons
	for (uint8_t u8_index = U8_ZERO_VALUE ; u8_index < APP_BUTTON_MAX_NUM ; u8_index++)
	{
		BTN_init((gc_str_btn_config+u8_index));
	}
	
	// Initialize car module
	
	CAR_INIT(&gc_str_motor_config[APP_MOTOR_1],&gc_str_motor_config[APP_MOTOR_2]);

	
	// Initialize Timer 1
	TIMER_MANGER_init(&gc_st_timer_1);
	
	
	// Initialize Timer 0
	TIMER_MANGER_init(&gc_st_timer_0);
	
	// Initialize External Interrupt module
	
	gs_str_extim_config_0.enu_exti_interrupt_no = EXTI_0;
	gs_str_extim_config_0.enu_edge_detection = EXTI_FALLING_EDGE;
	extim_init(&gs_str_extim_config_0,APP_extInt0OvfHandeler);
	

}


/**
 * @brief Timer 0 overflow handler.
 *
 * This function is called when timer 0 overflows. It increments the PWM counter and sets the timer for generating PWM.
 */
void APP_timer0OvfHandeler(void)
{
	// Increment PWM counter
	gv_u8_pwm++;
	// Set timer 0 with the Initial value to generate interrupt every 2 ms
	TIMER_MANGER_setValue(TIMER_0,gc_st_timer_0.u16_timer_initial_value);		// 2 ms with prescaler 1024 and F_CPU = 8M
}

/**
 * @brief Timer 1 overflow handler.
 *
 * This function is called when timer 1 overflows. It increments the delay counter and sets the timer for generating a delay.
 */
void APP_timer1OvfHandeler(void)
{
	// Increment Delay counter
	gv_u8_delay++;
	// Set timer 1 value to generate interrupt every 500 ms
	TIMER_MANGER_setValue(TIMER_1,gc_st_timer_1.u16_timer_initial_value);	// 500 ms with prescaler 1024 and F_CPU = 8M
}

/**
 * @brief External Interrupt 0 overflow handler.
 *
 * This function is called when external interrupt 0 is triggered. It resets the delay and PWM counters and changes the program state to stop.
 */
void APP_extInt0OvfHandeler(void)
{
	// Set Delay counter and PWM Counter to zero
	gv_u8_delay = U8_ZERO_VALUE;
	gv_u8_pwm = U8_ZERO_VALUE;
	
	// Change program state to stop 
	gs_enu_app_state = BTN_STOP;
}


/**
 * @brief Handles the long side routine.
 *
 * This function turns off other LEDs and turns on the long side LED, then moves the car forward with 50% speed for a certain duration.
 */
void APP_longSide(void)
{
	// Turn all LEDs off and turn long side LED on
	LED_off((gc_st_leds_config+LED_SHORT_SIDE));
	LED_on((gc_st_leds_config+LED_LONG_SIDE));
	LED_off((gc_st_leds_config+LED_ROTATE));
	LED_off((gc_st_leds_config+LED_STOP));
	
	
	// car move forward with 50% speed
	
	gv_u8_pwm = 0;
	TIMER_MANGER_start(F_CPU_1024,TIMER_0);							// start timer 0
	while (gv_u8_pwm <= 5)						// 10 ms ON
	{
		CAR_FORWARD(&gc_str_motor_config[0],&gc_str_motor_config[1]);
	}
	while (gv_u8_pwm > 5 && gv_u8_pwm <= 10)	// 10 ms OFF
	{
		CAR_STOP(&gc_str_motor_config[0],&gc_str_motor_config[1]);
	}
	TIMER_MANGER_stop(TIMER_0);										// stop timer 0
	gv_u8_pwm = 0;
}


/**
 * @brief Handles the short side routine.
 *
 * This function turns off other LEDs and turns on the short side LED, then moves the car forward with 30% speed for a certain duration.
 */
void APP_shortSide(void)
{
	// Turn all LEDs off and turn short side LED on
	LED_on((gc_st_leds_config+LED_SHORT_SIDE));
	LED_off((gc_st_leds_config+LED_LONG_SIDE));
	LED_off((gc_st_leds_config+LED_ROTATE));
	LED_off((gc_st_leds_config+LED_STOP));
	
	
	// move forward with 30% speed
	
	gv_u8_pwm = 0;
	TIMER_MANGER_start(F_CPU_1024,TIMER_0);									// start timer 0
	while (gv_u8_pwm <= 3)							// 6 ms ON
	{
		CAR_FORWARD(&gc_str_motor_config[0],&gc_str_motor_config[1]);
	}
	while (gv_u8_pwm > 3 && gv_u8_pwm <= 10)		// 14 ms OFF
	{
		CAR_STOP(&gc_str_motor_config[0],&gc_str_motor_config[1]);
	}
	TIMER_MANGER_stop(TIMER_0);										// stop timer 0
	gv_u8_pwm = 0;
}

/**
 * @brief Handles the stop routine.
 *
 * This function turns off other LEDs and turns on the stop LED, then stops the car motors.
 */
void APP_stop(void)
{
	// Turn all LEDs off and turn stop LED on
	LED_off((gc_st_leds_config+LED_SHORT_SIDE));
	LED_off((gc_st_leds_config+LED_LONG_SIDE));
	LED_off((gc_st_leds_config+LED_ROTATE));
	LED_on((gc_st_leds_config+LED_STOP));
	
	
	// Here We Will STOP motors
	CAR_STOP(&gc_str_motor_config[0],&gc_str_motor_config[1]);
}


/**
 * @brief Handles the rotation routine.
 *
 * This function turns off other LEDs and turns on the rotate LED, then rotates the car to the right with 50% speed to achieve a 90-degree rotation.
 */
void App_rotate(void)
{
	// Turn all LEDs off and turn rotate LED on
	LED_off((gc_st_leds_config+LED_SHORT_SIDE));
	LED_off((gc_st_leds_config+LED_LONG_SIDE));
	LED_on((gc_st_leds_config+LED_ROTATE));
	LED_off((gc_st_leds_config+LED_STOP));
	
	
	
	// rotate to right with 50% speed for 0.5 s to achieve 90 degree rotate to side
	gv_u8_pwm = 0;
	TIMER_MANGER_start(F_CPU_1024,TIMER_0);									// start timer 0
	while (gv_u8_pwm <= 5)							// 10 ms ON
	{
		CAR_REVERSE_RIGHT(&gc_str_motor_config[0],&gc_str_motor_config[1]);
	}
	while (gv_u8_pwm > 5 && gv_u8_pwm <= 10)		// 10 ms OFF
	{
		CAR_STOP(&gc_str_motor_config[0],&gc_str_motor_config[1]);
	}
	TIMER_MANGER_stop(TIMER_0);										// stop timer 0
	gv_u8_pwm = 0;
}

/**
 * @brief Handles the start state routine.
 *
 * This function enables external interrupt 0, starts timer 1, and performs specific actions based on delay value for the start state.
 */
void APP_startState(void)
{
	extim_enable(&gs_str_extim_config_0);											// Enable External interrupt 0
	TIMER_MANGER_start(F_CPU_1024,TIMER_1);						// start timer 1
	if (gv_u8_delay>= 2)										// 1s delay
	{
		if (gv_u8_delay <= 8 )									// longest side for 3s with speed 50%
		{
			APP_longSide();
		}
		else if (gv_u8_delay>8 && gv_u8_delay <=9)				// stop for 0.5
		{
			APP_stop();
		}
		else if (gv_u8_delay >9 && gv_u8_delay <=10)			// rotate 90 degree to right
		{
			App_rotate();
		}
		else if (gv_u8_delay > 10 && gv_u8_delay <=11)			// Stop the car for 0.5 s
		{
			APP_stop();
		}
		else if (gv_u8_delay > 11 && gv_u8_delay <= 15)				// short size for 2 s with speed 30%
		{
			APP_shortSide();
		}
		else if (gv_u8_delay>15 && gv_u8_delay <=16)				// stop for 0.5 s
		{
			APP_stop();
		}
		else if (gv_u8_delay >16 && gv_u8_delay <=17)			// rotate 90 degree to right
		{
			App_rotate();
		}
		else if (gv_u8_delay > 17 && gv_u8_delay <=18)			// Stop the car for 0.5 s
		{
			APP_stop();
		}
		else{
			gv_u8_delay = 2;
		}
		
	}
}

/**
 * @brief Handles the stop state routine.
 *
 * This function disables external interrupt 0, stops timer 1, stops the car, and reads the start button state to determine the program state.
 */
void APP_stopState(void)
{
	btn_enu_state_t enu_btn_state = BTN_RELEASED;
	
	extim_disable(&gs_str_extim_config_0);						// Disable External interrupt 0
	
	TIMER_MANGER_stop(TIMER_1);				// stop timer 1
	
	
	APP_stop();							
	
	
	// Read Start Button state
	BTN_get_state(&gc_str_btn_config[APP_BTN_START_INDEX],&enu_btn_state);
	
	if (enu_btn_state == BTN_PUSHED)
	{
		gs_enu_app_state = BTN_START;
	}
	gv_u8_delay = 0;
}