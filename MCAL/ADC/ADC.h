#ifndef ADC_H_
#define ADC_H_
#include "MemoryMap.h"
#include "DIO_Interface.h"
#include "StdTypes.h"
#include "Utils.h"
typedef enum{
	VRF_VCC,
	VRF_AREF,
	VRF_V265
	}ADC_Volt_Ref_type;
typedef enum{
	ADC_scaler2=1,
	ADC_scaler4,
	ADC_scaler8,
	ADC_scaler16,
	ADC_scaler32,
	ADC_scaler64,
	ADC_scaler128
	}ADC_Prescaler_type;
typedef enum{
	ADC_CH0,
	ADC_CH1,
	ADC_CH2,
	ADC_CH3,
	ADC_CH4,
	ADC_CH5,
	ADC_CH6,
	ADC_CH7
	}ADC_channal_type;

void ADC_init(ADC_Volt_Ref_type vrf,ADC_Prescaler_type scaler);
U16 ADC_read(ADC_channal_type ch);
void ADC_start(ADC_channal_type ch);
U8 ADC_read_without_start(U16* flag);
#endif /* ADC_H_ */