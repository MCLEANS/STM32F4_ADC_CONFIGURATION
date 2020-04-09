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

class ADC {
public:
	ADC();
	~ADC();
};

} /* namespace custom_libraries */

#endif /* ADC_H_ */
