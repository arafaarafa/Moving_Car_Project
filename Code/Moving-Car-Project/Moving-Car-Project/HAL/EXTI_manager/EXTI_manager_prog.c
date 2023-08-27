
#include "EXTI_manager_interface.h"


extim_enu_return_state_t extim_init(extim_str_config_t *ptr_str_extim_config, ptr_to_v_fun_in_void_t ptr_callback_func){

    extim_enu_return_state_t enu_return_state = EXTIM_E_OK;
	
	
	if((ptr_str_extim_config != NULL) && (ptr_callback_func != NULL)){
		ext_interrupt_init(ptr_str_extim_config->enu_exti_interrupt_no, ptr_str_extim_config->enu_edge_detection);
		ext_interrupt_set_callback_init(ptr_str_extim_config->enu_exti_interrupt_no , ptr_callback_func);
	}else{
		enu_return_state = EXTIM_NULL_PTR;
	}
    

    return enu_return_state;
}

extim_enu_return_state_t extim_enable(extim_str_config_t *ptr_str_extim_config){
    
    extim_enu_return_state_t enu_return_state = EXTIM_E_OK;
	if( ptr_str_extim_config != NULL ){
		ext_interrupt_enable(ptr_str_extim_config->enu_exti_interrupt_no);
	}else{
		enu_return_state = EXTIM_NULL_PTR;
	}
    return enu_return_state;
}
extim_enu_return_state_t extim_disable(extim_str_config_t *ptr_str_extim_config){

	extim_enu_return_state_t enu_return_state = EXTIM_E_OK;
	if( ptr_str_extim_config != NULL ){
		ext_interrupt_disable(ptr_str_extim_config->enu_exti_interrupt_no);
	}else{
	enu_return_state = EXTIM_NULL_PTR;
	}
    return enu_return_state;
}