/*
 * lcd.h
 *
 * Created: 25-12-2014 12:17:39
 *  Author: zainul
 */ 


//****************************************************      LCD - STARTS***********************************************************************
//Function to configure LCD port
void lcd_port_config (void)
{
	DDRC = DDRC | 0xF7;            //all the LCD pin's direction set as output
	PORTC = PORTC & 0x80;       // all the LCD pins are set to logic 0 except PORTC 7
}
//Function To Print Sensor Values At Desired Row And Column Location on LCD
void print_sensor(char row, char coloumn,unsigned char channel)
{
	
	ADC_Value = ADC_Conversion(channel);
	lcd_print(row, coloumn, ADC_Value, 3);
}

update_lcd(){
	print_sensor(1,1,3);            //Prints value of White Line Sensor1
	print_sensor(1,5,2);             //Prints Value of White Line Sensor2
	print_sensor(1,9,1);          //Prints Value of White Line Sensor3
	//print_sensor(1,13,6);         //Prints Value of Front IR Sensor
	lcd_print(1,13,path,1);
	lcd_print(1,15,l0,1);
	lcd_print(2,1,path1,1);
	lcd_print(2,3,l1,1);
	lcd_print(2,5,sr,1);
	lcd_print(2,8,path2,1);
	lcd_print(2,10,l2,1);
	lcd_print(2,12,sl,1);
	sharp = Front_Sharp_Sensor;
	value = Sharp_GP2D12_estimation(sharp);      //Stores Dist. calculated in “value”
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  LCD - ENDS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

