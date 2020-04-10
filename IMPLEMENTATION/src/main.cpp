/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "clockconfig.h"
#include "Timerconfiguration.h"
#include "ADC.h"
			
#define PSC_VALUE 640
#define ARR_VALUE 66

int count = 0;
int value = 25;

custom_libraries::clock_config system_clock;
custom_libraries::Timer_configuration delay_timer(TIM3,PSC_VALUE,ARR_VALUE);
custom_libraries::_ADC potentiometer(ADC1,GPIOA,0,custom_libraries::ch0,custom_libraries::SLOW);

void delay_ms(int duration){
	count = 0;
	while(count < duration){}
}


extern "C" void TIM3_IRQHandler(void){
	if(TIM3->SR & TIM_SR_UIF){
					TIM3->SR &= ~TIM_SR_UIF;
					custom_libraries::_ADC::count++;
	}
}

extern "C" void ADC_IRQHandler(void){

	if(ADC1->SR & ADC_SR_EOC){
		ADC1->SR &= ~ADC_SR_EOC;
		value = ADC1->DR;
	}

}

int main(void)
{

	system_clock.initialize();
	delay_timer.initialize();

	NVIC_SetPriority(TIM3_IRQn,0x03);
	NVIC_EnableIRQ(TIM3_IRQn);

	potentiometer.initialize();

	NVIC_SetPriority(ADC_IRQn,0x03);
	NVIC_EnableIRQ(ADC_IRQn);


	/*
	//Enable the ADC RCC
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	//change ADC prescaler since it should not exceed 30MHz
	//(84MHz/4 = 21MHz)
	ADC->CCR |= ADC_CCR_ADCPRE_0;
	//Enable RCC for input GPIO
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	//Set pin to Analog Mode
	GPIOA->MODER |= GPIO_MODER_MODER1; //GPIOA1 for ADC1

	//Enable end of conversion Interrupt
	ADC1->CR1 |= ADC_CR1_EOCIE;

	//Set ADC Interrupt priority
	NVIC_SetPriority(ADC_IRQn, 0x00);
	//Enable NVIC interrupt
	NVIC_EnableIRQ(ADC_IRQn);

	//set the sampling rate
	ADC1->SMPR2 |= ADC_SMPR2_SMP1;

	//set the number of channels to be converted and the conversion sequence
	//by default only one channel is selected
	ADC1->SQR3 |= ADC_SQR3_SQ1_0;

	//enable ADC for the first time (wakes up ADC from power down mode) and set to continuous mode.
	ADC1->CR2 |= ADC_CR2_ADON | ADC_CR2_CONT;
	//delay tSTAB to enable the ADC power up
	delay_ms(2);
	//enable ADC for the second time to actually turn it on
	ADC1->CR2 |= ADC_CR2_ADON;
	delay_ms(2);

	//start first ADC conversion
	ADC1->CR2 |= ADC_CR2_SWSTART;

*/



	while(1){



	}
}
