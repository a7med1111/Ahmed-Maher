


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


#define COLUMN_NUM			4
#define ROW_NUM				4


#define KPDROW_PORT  				PORTC_ID
#define KPDCOL_PORT  				PORTD_ID



#define KPD_ARR_VAL 				{{'c',0,'=','+'},{1,2,3,'-'},{4,5,6,'*'},{7,8,9,'/'}}


#define KPD_COLUMN0_PIN				PIN7
#define KPD_COLUMN1_PIN  			PIN6
#define KPD_COLUMN2_PIN  	 		PIN5
#define KPD_COLUMN3_PIN  	 		PIN3

#define KPD_ROW0_PIN				PIN5
#define KPD_ROW1_PIN  				PIN4
#define KPD_ROW2_PIN  	 			PIN3
#define KPD_ROW3_PIN  	 			PIN2

#define KPD_NO_PRESSED_KEY	0xff

#endif
