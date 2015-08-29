/*
 * sensors.h
 *
 * Created: 25-12-2014 12:11:52
 *  Author: zainul
 */ 


//****************************************************      SENSORS - STARTS***********************************************************************
//ADC pin configuration
void adc_pin_config (void)
{
	DDRF = 0x00;
	PORTF = 0x00;
	DDRK = 0x00;
	PORTK = 0x00;
}
void adc_init()
{
	ADCSRA = 0x00;
	ADCSRB = 0x00; //MUX5 = 0
	ADMUX = 0x20;  //Vref=5V external --- ADLAR=1 --- MUX4:0 = 0000
	ACSR = 0x80;
	ADCSRA = 0x86;          //ADEN=1 --- ADIE=1 --- ADPS2:0 = 1 1 0
}

//Function For ADC Conversion
unsigned char ADC_Conversion(unsigned char Ch)
{
	unsigned char a;
	if(Ch>7)
	{
		ADCSRB = 0x08;
	}
	Ch = Ch & 0x07;
	ADMUX= 0x20| Ch;
	ADCSRA = ADCSRA | 0x40;           //Set start conversion bit
	while((ADCSRA&0x10)==0);         //Wait for conversion to complete
	a=ADCH;
	ADCSRA = ADCSRA|0x10;      //clear ADIF (ADC Interrupt Flag) by writing 1 to it
	ADCSRB = 0x00;
	return a;
}

// This Function calculates the actual distance in millimeters (mm) from the input
// analog value of Sharp Sensor.
unsigned int Sharp_GP2D12_estimation(unsigned char adc_reading)
{
	float distance;
	unsigned int distanceInt;
	distance = (int)(10.00*(2799.6*(1.00/(pow(adc_reading,1.1546)))));
	distanceInt = (int)distance;
	if(distanceInt>800)
	{
		distanceInt=800;
	}
	return distanceInt;
}

 update_sensor(){
	 Left_white_line = ADC_Conversion(3);    //Getting data of Left WL Sensor
	 Center_white_line = ADC_Conversion(2);  //Getting data of Center WL Sensor
	 Right_white_line = ADC_Conversion(1);   //Getting data of Right WL Sensor
	 Front_Sharp_Sensor = ADC_Conversion(11);
	 Front_IR_Sensor = ADC_Conversion(6);
	 update_lcd();
 }

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  SENSORS - ENDS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

