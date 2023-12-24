

/*preprocessor file guard */

#ifndef MCAL_ADC_INTERFACE_H_
#define MCAL_ADC_INTERFACE_H_

#define ADC_STATE		ENABLE

typedef struct
		{
	u8 Channel_ID ;
	u16 * Result;
	void (*Copy_PvNotification)(void);
} ADC_t;




void ADC_void_Init (void);

u8 ADC_u8_StartSingleConversionSyn (ADC_t *singleSync );

u8 ADC_u8_StartSingleConversionAsyn (ADC_t *singleAsync);







#endif
