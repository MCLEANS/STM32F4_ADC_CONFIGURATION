/*
 * ADC.cpp
 *
 *  Created on: Apr 9, 2020
 *      Author: MCLEANS
 */

#include "ADC.h"

namespace custom_libraries {

_ADC::_ADC(GPIO_TypeDef *GPIO,uint8_t PIN,ADC_channel channel,Sampling_rate sample_rate): GPIO(GPIO),
																							PIN(PIN),
																							channel(channel),
																							sample_rate(sample_rate){

	//Enable GPIO_RCC
	//Enable ADC_RCC
	//Set ADC prescaler
	//Set number of channels
	//Set channel sequence


}

void _ADC::initialize()

_ADC::~_ADC() {
	// TODO Auto-generated destructor stub
}

} /* namespace custom_libraries */
