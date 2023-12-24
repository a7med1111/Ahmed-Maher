
 *




#ifndef MOTOR__INTERFACE_H
#define MOTOR__INTERFACE_H


/*options for PIN1_ID and PIN2_ID
 * 1-PIN0
 * 2-PIN1
 * 3-PIN2
 * 4-PIN3
 * 5-PIN4
 * 6-PIN5
 * 7-PIN6
 * 8-PIN7
 * **/
/*options for TimerName
 * 1-TIMER0
 * 2-TIMER2
 * **/
#define	TIMER0		1
#define	TIMER2		2
/*options for Speed:
The value for OCR0/OCR2
 * **/



typedef struct
{
	u8 Pin1_ID;				
	u8 Pin2_ID;
	u8 TimerName;
	u8 Speed;
}MOTOR_t;


void MOTOR_vd_CCW(MOTOR_t *motor);

void MOTOR_vd_CW(MOTOR_t *motor);

void MOTOR_vd_stop(MOTOR_t *motor);





#endif /* MOTOR__INTERFACE_H_ */
