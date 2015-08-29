#include "cargo_imports_Var_license.h"
#include "BLC.h"
 
//Function to Initialize PORTS 
void port_init() 
{ 
	lcd_port_config(); 
	adc_pin_config();
   
	motion_pin_config(); 
	buzzer_pin_config();  
  
	motion_pin_config(); //robot motion pins config
  
	left_encoder_pin_config(); //left encoder pin config
	right_encoder_pin_config(); //right encoder pin config

	servo1_pin_config(); //Configure PORTB 5 pin for servo motor 1 operation
	servo2_pin_config(); //Configure PORTB 6 pin for servo motor 2 operation
	servo3_pin_config(); //Configure PORTB 7 pin for servo motor 3 operation
	dc1F_pin_config();
	dc1B_pin_config();
	dc2F_pin_config();
	dc2B_pin_config();
	color_sensor_pin_config();//color sensor pin configuration
} 
 
//Initializing Device
void init_devices(void) 
{ 
  cli();                 //Clears the global interrupts 
  port_init(); 
  timer1_init();
  left_position_encoder_interrupt_init();
  right_position_encoder_interrupt_init();
  color_sensor_pin_interrupt_init();
  adc_init(); 
  timer5_init(); 
  sei();                  //Enables the global interrupts 
}

//ARM initializatoin
void init_arm(){
	servo_2(120);
	_delay_ms(3000);
	servo_1(90);
	_delay_ms(3000);
	servo_3(75);
	_delay_ms(3000);
}
void read_color(void){
	_delay_ms(1000);
	red_read();
	_delay_ms(1000);
	green_read();
	_delay_ms(1000);
	blue_read();
	_delay_ms(1000);
}	  

 int check_color(){
	read_color();
	if((red <= thresh_color && red >= 800)&&(green <= thresh_color && green >= 800)&&(blue <= thresh_color && blue >= 800)){
		lcd_cursor(1,1);  //set the cursor on row 1, column 1
		lcd_string("BLACK color"); // Display "Green Pulses" on LCD
		_delay_ms(500);	// Display for 1000ms or 1 second
		lcd_wr_command(0x01); //Clear the LCD
		return 4;
	}	
	else if((green > red) && (green > blue)){
		lcd_cursor(1,1);  //set the cursor on row 1, column 1
		lcd_string("GREEN color"); // Display "Green Pulses" on LCD
		_delay_ms(1000);	// Display for 1000ms or 1 second
		lcd_wr_command(0x01); //Clear the LCD
		return 2;
	}		
	else if ((blue > red)&&(blue > green)){
		lcd_cursor(1,1);  //set the cursor on row 1, column 1
		lcd_string("BLUE color"); // Display "Green Pulses" on LCD
		_delay_ms(1000);	// Display for 1000ms or 1 second
		lcd_wr_command(0x01); //Clear the LCD
		return 3;
	}		
	else if((red > green) && (red > blue)){
		lcd_cursor(1,1);  //set the cursor on row 1, column 1
		lcd_string("RED color"); // Display "Green Pulses" on LCD
		_delay_ms(1000);	// Display for 1000ms or 1 second
		lcd_wr_command(0x01); //Clear the LCD	
		return 1;	
	}else{
		return -1;
	}
}	


//Main Function
//Main Function
int main() { 
	init_devices(); 
	lcd_set_4bit(); 
	lcd_init(); 
	color_sensor_scaling();
	init_arm();
	//velocity(lv,rv);
	//forward();	
	while(1){ 
		update_sensor();
		forward();		
		velocity(lv,rv);
		buzzer_off();
		lineFollow();
	}
}
