#include "ADC.h"
static U8 adc_flag=0;
void ADC_init(ADC_Volt_Ref_type vrf,ADC_Prescaler_type scaler){
	switch(vrf){
		case VRF_AREF:
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
		case VRF_VCC:
		SET_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
		case VRF_V265:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	scaler=scaler&0x07;
	ADCSRA=ADCSRA&0xF8;
	ADCSRA=ADCSRA|scaler;
	CLEAR_BIT(ADMUX,ADLAR);
	
}
U16 ADC_read(ADC_channal_type ch){
	SET_BIT(ADCSRA,ADEN);
	ADMUX=ADMUX&0xE0;
	ADMUX=ADMUX|ch;
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC));
	return ADC;
}
void ADC_start(ADC_channal_type ch){
	if (adc_flag==0)
	{
		SET_BIT(ADCSRA,ADEN);
		ADMUX=ADMUX&0xE0;
		ADMUX=ADMUX|ch;
		SET_BIT(ADCSRA,ADSC);
		adc_flag=1;
	}
	
}
U8 ADC_read_without_start(U16* flag){
	if (READ_BIT(ADCSRA,ADSC)==0)
	{
		*flag=ADC;
		adc_flag=0;
		return 1;
		
	}
	else{
		return 0;
	}
}