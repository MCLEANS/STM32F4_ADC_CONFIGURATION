/*
 * ADC.h
 *
 *  Created on: Apr 9, 2020
 *      Author: MCLEANS
 *
 *      This Library expects the user to implement their own interrupt service routine
 */

#ifndef ADC_H_
#define ADC_H_

namespace custom_libraries {

enum sampling_rate{
	LOW,
	MEDIUM,
	HIGH
};

enum adc_channel{
	ch0,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11,ch12,ch13,ch14,ch15
};

class ADC {
private:

private:

public:

public:
	ADC();
	~ADC();
};

} /* namespace custom_libraries */

#endif /* ADC_H_ */
