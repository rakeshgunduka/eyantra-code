/*
 * lineFollower.h
 *
 * Created: 25-12-2014 13:20:25
 *  Author: zainul
 */ 

lineFollow(){
	check_010();
	check_001();
	check_011();
	check_100();
	check_110();
	check_111();
} 




void check_010(void){
	if((Left_white_line<=left_sens_thres) && (Center_white_line>mid_sens_thres) && (Right_white_line<=right_sens_thres)){     //010
		velocity(lv,rv);
		forward();
	}
}
void check_001(void){
	if((Left_white_line<=left_sens_thres) && (Center_white_line<=mid_sens_thres) && (Right_white_line>right_sens_thres)){     //001
		//velocity(212,197);
		right_degrees(6);
	}
}
void check_011(void){
	if ((Left_white_line<=left_sens_thres) && (Center_white_line>mid_sens_thres) && (Right_white_line>right_sens_thres)){     //011
		//right_degrees(3);
	}
}
void check_100(void){
	if((Left_white_line>left_sens_thres) && (Center_white_line<=mid_sens_thres) && (Right_white_line<=right_sens_thres)){     //100
		//velocity(197,212);
		left_degrees(6);
	}
}
void check_110(void){
	if((Left_white_line>left_sens_thres) && (Center_white_line>mid_sens_thres) && (Right_white_line<=right_sens_thres)){       //110
		//left_degrees(3);
	}
}
//Traversing Functions
void tr_s(){
		if(l1 == 1){
			if(gr == 1){
				path1 = 0;
				sr = 1;
			}else{
				path1 = 1;
				sr = 0;
			}	
			bound = 1;
			tr = 1;
		}else if (l2 == 1){
			if(gr == 1){
				path2 = 0;
				sl = 1;
			}else{
				path2 = 1;
				sl= 0;
			}
			bound = 1;
			tr = 1;
		}
}
void tl_s(){
	if(gr == 1){
		if(l1 == 1){
			sr = 1;
		}else if(l2 == 1){
			sl = 1;
		}
	}else{
		sr = 0;
		sl = 0;
	}
	bound = 0;
	tr = 0;
}
void s_tr(){
	if(path == 3){
		path2 = 0;
		l2 = 1;
		sl = 0;
		bound = 1;
	}else if(path == 1){
		path1 = 0;
		l1 = 1;
		sr = 0;
		bound = 1;
	}	
}
void tr_tl(){
	
}

void s_tl(){
	if(path == 3){
		bound = 1;
		path2 = 2;
		l2 = 1;
		sl = 0;
	}else if(path == 1){
		bound = 1;
		path1 = 2;
		l1 = 1;
		sr = 0;
	}	
}
void tl_tr(){
	
}

void pth1_pth3(){
	buzzer_on();
	_delay_ms(500);
	buzzer_off();
	path1 = 0;
	path = 1;
	path2 = 0;
	l1 = 0;
	bound = 1;
	l0 = 1;
	mp_r = 1;
}
void pth3_pth1(){
	buzzer_on();
	_delay_ms(500);
	buzzer_off();
	path1 = 0;
	path = 3;
	path2 = 0;
	l2 = 0;
	bound = 0;
	l0 = 1;
	mp_r = 0;
}
void trotate_right(){
	_delay_ms(1000);
	servo_1(185);
	_delay_ms(1000);
	servo_2(160);
	_delay_ms(1000);
	servo_3(40);
	_delay_ms(1000);
}
void trotate_left(){
	_delay_ms(1000);
	servo_1(0);
	_delay_ms(1000);
	servo_2(160);
	_delay_ms(1000);
	servo_3(40);
	_delay_ms(1000);
}
int scan(){
	return check_color();
	_delay_ms(6000);
}
void pick(int gcolor){
	hold();
	gr = 1;
	init_arm();
	grcolor = gcolor;
}
int direct_ter13(){
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			if(grcolor == blrefL[i][j]){
				if(vacantL[i][j] == 0){
					if(i==0 && j ==0){
						srotate_right();
						var = 11;
					}
					else if(i==0 && j ==1){
						srotate_right();
						var = 12;
					}
					else if(i==1 && j ==0){
						srotate_left();
						var = 31;
					}
					else if(i==1 && j ==1){
						srotate_left();
						var = 32;
					}
					return 1;
				}
			}
		}
	}
	if(i == 2 && j == 2){
		return 0;
	}
}
int direct_ter24(){
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			if(grcolor == blrefR[i][j]){
				if(vacantR[i][j] == 0){
					if(i==0 && j ==0){
						srotate_left();
						var = 21;
					}
					else if(i==0 && j ==1){
						srotate_left();
						var = 22;
					}
					else if(i==1 && j ==0){
						srotate_right();
						var = 41;
					}
					else if(i==1 && j ==1){
						srotate_right();
						var = 42;
					}
					return 1;
				}
			}
		}
	}
	if(i == 2 && j == 2){
		return 0;
	}
}
int path_3_func(){
	if(gr == 1){
		if(direct_ter13()){
			return 1;	
		}else{
			buzzer_on();
			_delay_ms(1000);
			buzzer_off();
			if(sortL[0] == 0 || sortL[0] == -1){
				drop_in_sort(0);
			}else if(sortL[1] == 0 || sortL[1] == -1){
				drop_in_sort(1);
			}
			return 2;
		}
	}else if(gr == 0){
		return 0;
	}	
}

int path_1_func(){
	if(gr == 1){
		if(direct_ter24()){
			return 1;
		}else{
			buzzer_on();
			_delay_ms(1000);
			buzzer_off();
			if(sortL[0] == 0 || sortL[0] == -1){
				drop_in_sort(0);
			}else if(sortL[1] == 0 || sortL[1] == -1){
				drop_in_sort(1);
			}
			return 2;
		}
	}else if(gr == 0){
		return 0;
	}
}

void check_111(void)
{
	if((Left_white_line>left_sens_thres) && (Center_white_line>mid_sens_thres) && (Right_white_line>right_sens_thres)){        //111
	buzzer_on();
	_delay_ms(1);
		if(count111 == 1){
			buzzer_off();
			stop();
			forward_mm(30);
			//arm movement right 90
			/*servo_3(80);
			_delay_ms(2000);
			servo_1(173);
			_delay_ms(2000);
			servo_2(178);
			_delay_ms(3000);
			servo_3(50);
			_delay_ms(1000);
			dc1F();
			dc2F();
			_delay_ms(2000);
			dc1B();
			dc2B();
			_delay_ms(4000);
			dcoff();*/
			//i4 = check_color();
			i4 = 4;
			/*servo_3(80);
			_delay_ms(3000);
			servo_2(120);
			_delay_ms(3000);*/
			//arm left 180
			/*servo_1(0);
			_delay_ms(2000);
			servo_2(178);
			_delay_ms(3000);
			servo_3(50);
			_delay_ms(3000);
			dc1F();
			dc2F();
			_delay_ms(2000);
			dc1B();
			dc2B();
			_delay_ms(4000);
			dcoff();*/
	//		i3 = check_color();
			i3 = 2;
			//arm right 90
			/*servo_3(80);
			_delay_ms(2000);
			servo_2(120);
			_delay_ms(2000);
			servo_1(90);
			_delay_ms(2000);
			velocity(lv,rv);
			forward();*/
		}
		if(count111 == 2){
			buzzer_off();
			stop();
			forward_mm(30);
			//arm movement right 90
			/*servo_3(80);
			_delay_ms(2000);
			servo_1(170);
			_delay_ms(2000);
			servo_2(185);
			_delay_ms(2000);
			servo_3(50);
			_delay_ms(2000);
			dc1F();
			dc2F();
			_delay_ms(2000);
			dc1B();
			dc2B();
			_delay_ms(4000);
			dcoff();*/
		//	i2 = check_color();
			i2 = 1;
			/*servo_3(80);
			_delay_ms(2000);
			servo_2(120);
			_delay_ms(2000);
			//arm left 180
			servo_1(0);
			_delay_ms(2000);
			servo_2(120);
			_delay_ms(2000);
			servo_3(50);
			_delay_ms(2000);
			dc1F();
			dc2F();
			_delay_ms(2000);
			dc1B();
			dc2B();
			_delay_ms(4000);
			dcoff();*/
		//	i1 = check_color();
			i1 = 3;
			//arm right 90
			/*servo_3(80);
			_delay_ms(2000);
			servo_2(185);
			_delay_ms(2000);
			servo_1(90);
			_delay_ms(2000);
			velocity(195,202);
			forward();*/
			for(i=0;i<2;i++){
				for(j=0;j<2;j++){
					vacantR[i][j] = -1;
					vacantL[i][j] = -1;
					if(i == 0){
						if(j == 0){
							blrefL[i][j] = i1;
							blrefR[i][j] = i2;	
													
						}else if(j == 1){
							blrefL[i][j] = i1;
							blrefR[i][j] = i2;
						}
					}else if(i == 1){
						if(j == 0){
							blrefL[i][j] = i3;
							blrefR[i][j] = i4;
						}else if(j == 1){
							blrefL[i][j] = i3;
							blrefR[i][j] = i4;
						}
					}
				}
			}
			for(i=0;i<2;i++){
				sortR[i] = -1;
				sortL[i] = -1;
			}
			velocity(lv,rv);
			forward();
		}
		if(count111 == 3){
			buzzer_off();
			velocity(lv,rv);
			forward_mm(fm);
			stop(); 
			_delay_ms(100);
			right_degrees(nd);
		}
		if(count111 > 3)
		{
			velocity(187,192);			
			buzzer_off();
			if(bound == 1){
				if(l0 == 1){
					path++;
					if(path == upper_B){
						bound = 0;
					}
				}else if(l1 == 1){
					path1++; 
					if(path1 == upper_B){
						bound = 0;
					}
				}else if(l2 == 1){
					path2++;
					if(path2 == upper_B){
						bound = 0;
					}
				}	
				update_lcd();
			}else{			
				if(l0 == 1){
					path--;
					if(path == lower_B){
						bound = 1;
					}
				}else if(l1 == 1){
					path1--;
					if(path1 == 2 && sr == 0){
						bound = 1;	
					}
				}else if(l2 == 1){
					path2--; 
					if(path2 == 2 && sl == 0 ){
						bound = 1;
					}
				}
				update_lcd();	
			}			
			if((path == 1) && (l0 == 1)){
				stop();
				val = path_1_func();
				if(val == 1){
					l0 = 0;
					l1 = 1;
					l2 = 0;
					t2t = 0;
					if(var == 41 || var == 42){
						s_tr();
					}else if(var == 21 || var == 22){
						s_tl();
					}
				}else if(val == 2){
					if(vacantR[0][0] == -1 &&vacantR[0][1] == -1 &&vacantR[1][0] == -1 &&vacantR[1][1] == -1){
						right_degrees(95);
						l0 = 0;
						l1 = 1;
						l2 = 0;
						t2t = 0;
						path1 = 0;
						bound = 1;
						sr = 0;
						//set normal values
					}else{					//to call BLC
						l0 = 0;
						l1 = 1;
						l2 = 0;
						t2t = 0;
						path1 = 1;
						bound = 1;
						sr = 0;
						tr = 2;
					}					
				}else if(val == 0){
					if(vacantR[0][0] == -1 &&vacantR[0][1] == -1 &&vacantR[1][0] == -1 &&vacantR[1][1] == -1){
						right_degrees(95);
						l0 = 0;
						l1 = 1;
						l2 = 0;
						t2t = 0;
						path1 = 0;
						bound = 1;
						sr = 0;
						//set normal values
					}else{					//to call BLC
						l0 = 0;
						l1 = 1;
						l2 = 0;
						t2t = 0;
						path1 = 1;
						bound = 1;
						sr = 0;
						tr = 2;
					}
				}
				
			}else if(path == 2 && l0 == 1 && sr == 0){
				leave = 0;
				l1 = 0;
				l2 = 0;
			}else if((path1 == 1) && (l1 == 1) && (sr == 1)){
				stop();
				if(gr == 1){
					if(leave != 1){
						if(sortR[0] == 0 || sortR[0] == -1){
							right_degrees(96);
							drop_in_sort(0);
							grcolor = 0;
						}else if(sortR[1] == 0 || sortR[1] == -1){
							right_degrees(96);
							drop_in_sort(1);
							grcolor = 0;
						}
					}else{
						left_degrees(90);
						pth1_pth3();
						forward();
						leave = 0;
					}
				}
				if(vacantR[1][0] == -1 || vacantR[1][1] == -1){
					right_degrees(96);
					s_tr();
					forward();		
				}else{
					left_degrees(96);
					s_tl();
					forward();
				}
			}else if((path1 == 1) && (l1 == 1) && (sr == 0)){
				//arm movement right
				stop();
				if(ter_var_pick == 41){
					trotate_left(); 
					pick(vacantR[1][0]);
					vacantR[1][0] = 0;
					left_degrees(185);
					tl_s();
					forward();
					t2t = 1;
					ter_var_pick = 0;
				}else if(ter_var_pick == 42){
					trotate_right();
					pick(vacantR[1][0]);
					vacantR[1][0] = 0;
					left_degrees(185);
					tl_s();
					sr = 0;
					t2t = 1;
					forward();
					ter_var_pick = 0;
				}else if(ter_var_drop == 41){
					trotate_right();
					loose();
					vacantR[1][1] = grcolor;
					init_arm();
					grcolor = 0;
					ter_var_drop = 0;
					t2t = 0;
					bound = 1;
					tr = 1;
					right_degrees(185);
				}else if(ter_var_drop == 42){
					trotate_left();
					loose();
					vacantR[1][1] = grcolor;
					init_arm();
					grcolor = 0;
					ter_var_drop = 0;
					t2t = 0;
					bound = 1;
					tr = 1;
					right_degrees(185);
				}else if(var == 41){
					if(gr == 1){
						trotate_right();
						loose();
						vacantR[1][0] = grcolor;
						init_arm();
						grcolor = 0;
						var = 0; 
					}else{
						trotate_right();
						pick(vacantR[1][0]);
						grcolor = vacantR[1][0];
						vacantR[1][0] = 0;
						right_degrees(90);
						tr_s();
						leave = 1;
						var = 0;
					}						
				}else if(var == 42){
					if(gr == 1){
						trotate_left();
						loose();
						vacantR[1][0] = grcolor;
						init_arm();
						grcolor = 0;
						var = 0;
					}else{
						trotate_left();
						pick(vacantR[1][1]);
						grcolor = vacantR[1][1];
						vacantR[1][1] = 0;
						right_degrees(90);
						tr_s();
						leave = 1;
						var = 0;
					}					
				}else{
					fl = 0;
					if(vacantR[1][0] == -1 && gr == 0){
						int val;
						trotate_right();
						one_time = 1;
						//val = scan();
						val = 4;
						vacantR[1][0] = val;
					}
					if((vacantR[1][0] != blrefR[1][0]) && (vacantR[1][0] != -1) && (vacantR[1][0] != 0) && gr == 0){
						if((sortR[0] == 0 || sortR[0] == -1) || (sortR[1] == 0 || sortR[1] == -1)){
							if(one_time != 1){
								trotate_right();
							}						
							pick(vacantR[1][0]);
							vacantR[1][0] = 0;
							right_degrees(190);
							tr_s();
							forward();
							fl = 1;
							//turn and forward
						}else{
							init_arm();
						}
					}else if((vacantR[1][0] == blrefR[1][0])){
						init_arm();
					}
					if(vacantR[1][1] == -1 && gr == 0 && fl != 1){
							int val;
							trotate_left();
							one_time = 2;
							//val = scan();
							val = 3;
							vacantR[1][1] = val;
							_delay_ms(100);
					}
					if((vacantR[1][1] != blrefR[1][1]) && (vacantR[1][1] != -1) && (vacantR[1][1] != 0) && gr == 0 && fl != 1){
						if((sortR[0] == 0 || sortR[0] == -1) || (sortR[1] == 0 || sortR[1] == -1)){
							if(one_time != 2){
								trotate_left();
							}						
							pick(vacantR[1][1]);
							grcolor = vacantR[1][1];
							sr == 1;
							vacantR[1][1] = 0;
							right_degrees(190);
							tr_s();
							forward();
							//turn and forward
						}else{
							gr = 0;
							init_arm();
							right_degrees(185);
							tr_s();
						}
					}else if((vacantR[1][1] == blrefR[1][0])){
						gr = 0;
						init_arm();
						right_degrees(185);
						tr_s();
					}
				}								
			}else if((path1 == 2) && (l1 == 1) && (sr == 1) && (t2t!=1)){
				stop();
				if(gr == 1){
					if(leave != 1){
						if(sortR[0] == 0){
							left_degrees(96);
							drop_in_sort(0);
							grcolor = 0;
						}else if(sortR[1] == 0){
							left_degrees(96);
							drop_in_sort(1);
							grcolor = 0;
						}
					}else{
						buzzer_on();
						_delay_ms(500);
						buzzer_off();
						if(tr == 0){
							right_degrees(90);
						}else{
							left_degrees(90);
						}					
						pth1_pth3();
						forward();
						sr = 0;
					}					
				}else{
					if(sortR[0] != 0){
						pick_from_sort(0);
						grcolor = sortR[0];
						gr = 1;
						sortR[0] = 0;
					}else{
						pick_from_sort(1);
						grcolor = sortR[0];
						gr = 1;
						sortR[1] = 0;
					}
				}
				if(leave != 1){
					if(vacantR[0][0] == -1 || vacantR[0][1] == -1){
						left_degrees(96);
						s_tl();
						forward();
					}else if(vacantR[0][0] == -1 || vacantR[0][1] == -1){
						right_degrees(96);
						s_tr();
						forward();
					}
				}				
			}else if((path1 == 2) && (l1 == 1) && (sr == 0) && (t2t == 1)){
				if(tr != 1){
					s_tr();
				}else{
					s_tl();
				}
			}else if((path1 == 2) && (l1 == 1) && (sr == 0) && (t2t !=1)){
				if(tr == 1){
					right_degrees(95);
				}else if(tr == 0){
					left_degrees(95);
				}
				if(vacantR[0][0] != -1 && vacantR[0][1] != -1 && vacantR[1][0] != -1 && vacantR[1][1] != -1){
					before_leaving_check();
				}else{
					if(tr == 1){
						left_degrees(95);
						s_tl();
					}else{
						right_degrees(95);
						s_tr();
					}
				}				
			}else if(path1 == 3 && l1 == 1 && (sr == 0)){
					stop();
					if(ter_var_pick == 21){
						trotate_left();
						pick(vacantR[0][0]);
						vacantR[0][0] = 0;
						left_degrees(185);
						tl_s();
						sr=0;
						t2t = 1;
						forward();
						ter_var_pick = 0;
					}else if(ter_var_pick == 22){
						buzzer_on();
						_delay_ms(1000);
						buzzer_off();
						trotate_right();
						pick(vacantR[0][1]);
						vacantR[0][1] = 0;
						left_degrees(185);
						tl_s();
						sr = 0;
						t2t = 1;
						bound = 0;
						//forward();
						ter_var_pick = 0;
					}else if(ter_var_drop == 21){
						trotate_left();
						loose();
						vacantR[0][0] = grcolor;
						init_arm();
						grcolor = 0;
						ter_var_drop = 0;
						t2t = 0;
						tl_s();
						right_degrees(185);
					}else if(ter_var_drop == 22){
						trotate_right();
						loose();
						vacantR[0][1] = grcolor;
						init_arm();
						grcolor = 0;
						ter_var_drop = 0;
						t2t = 0;
						tl_s();
						right_degrees(185);
					}else if(var == 21){
						if(gr == 1){
							trotate_left();
							loose();
							vacantR[0][0] = grcolor;
							init_arm();
							grcolor = 0;
							var = 0;
						}else{
							trotate_left();
							pick(vacantR[0][0]);
							vacantR[0][0] = 0;
							left_degrees(185);
							leave = 1;
							tl_s();
							forward();
							var = 0;
						}						
					}else if(var == 22){
						if(gr == 1){
							trotate_right();
							loose();
							vacantR[0][1] = grcolor;
							init_arm();
							grcolor = 0;
							right_degrees(185);
							tl_s();
							var = 0;
						}else{
							trotate_right();
							pick(vacantR[0][1]);
							vacantR[0][1] = 0;
							right_degrees(185);
							leave = 1;
							tl_s();
							var = 0;
						}							
					}else{
						if(vacantR[0][1] == -1 && gr == 0){
							int val;
							trotate_right();
							one_time = 1;
							//val = scan();
							val = 1;
							vacantR[0][1] = val;
						}
						if((vacantR[0][1] != blrefR[0][1]) && (vacantR[0][1] != -1) && (vacantR[0][1] != 0) && gr == 0){
							if((sortR[0] == 0 || sortR[0] == -1) || (sortR[1] == 0 || sortR[1] == -1)){
								if(one_time != 1){
									trotate_right();
								}
								pick(vacantR[0][1]);
								grcolor = vacantR[0][1];
								vacantR[0][1] = 0;
								right_degrees(185);
								tl_s();
								forward();
								//turn and forward
							}else{
								init_arm();
								_delay_ms(500);
							}
						}else{
							init_arm();
						}							
						if(vacantR[0][0] == -1 && gr == 0){
							int val;
							trotate_left();
							one_time = 2;
							//val = scan();
							val = 1;
							vacantR[0][0] = val;
						}
						if((vacantR[0][0] != blrefR[0][0]) && (vacantR[0][0] != -1) && (vacantR[0][0] != 0) && gr == 0){
							if((sortR[0] == 0 || sortR[0] == -1) || (sortR[1] == 0 || sortR[1] == -1)){
								if(one_time != 2){
									trotate_right();
								}
								pick(vacantR[0][0]);
								grcolor = vacantR[0][0];
								vacantR[0][0] = 0;
								left_degrees(185);
								tl_s();
								//turn and forward
							}else{
								gr = 0;
								init_arm();
								right_degrees(185);
								tl_s();
							}
						}else{
							gr = 0;
							init_arm();
							right_degrees(185);
							tl_s();	
						}
					}						
			}
			if(path == 3 && l0 == 1){
				stop();
				val = path_3_func();			
				if(val == 1){
					l0 = 0;
					l2 = 1;
					l1 = 0;
					t2t = 0;
					if(var == 11 || var == 12){
						s_tr();
					}else if(var == 31 || var == 32){
						s_tl();	
					}
				}else if(val == 2){
					if(vacantL[0][0] == -1 &&vacantL[0][1] == -1 &&vacantL[1][0] == -1 &&vacantL[1][1] == -1){
						right_degrees(95);
						l0 = 0;
						l2 = 1;
						l1 = 0;
						t2t = 0;
						path2 = 0;
						bound = 1;
						sl = 0;
						//set normal values
					}else{					//to call BLC
						l0 = 0;
						l2 = 1;
						l1 = 0;
						t2t = 0;
						path2 = 1;
						bound = 1;
						sl = 0;
						tr = 2;
					}
				}else if(val == 0){
					if(vacantL[0][0] == -1 &&vacantL[0][1] == -1 &&vacantL[1][0] == -1 &&vacantL[1][1] == -1){
						right_degrees(95);
						l0 = 0;
						l2 = 1;
						l1 = 0;
						t2t = 0;
						path2 = 0;
						bound = 1;
						sl = 0;
						//set normal values
					}else{					//to call BLC
						l0 = 0;
						l2 = 1;
						l1 = 0;
						t2t = 0;
						path2 = 1;
						bound = 1;
						sl = 0;
						tr = 2;
					}					
					
				}		
				//_delay_ms(100);
			}else if(path2 == 1 && l2 == 1 && sl == 1){
				stop();
				if(gr == 1){
					if(leave != 1){
						if(sortL[0] == 0 || sortL[0] == -1){
							right_degrees(96);
							drop_in_sort(0);
							grcolor = 0;
						}else if(sortL[1] == 0 || sortL[1] == -1){
							right_degrees(96);
							drop_in_sort(1);
							
							grcolor = 0;
						}
					}else{
						left_degrees(90);
						pth3_pth1();
						forward();
						leave = 0;
					}
				}
				if(vacantL[0][0] == -1 || vacantL[0][1] == -1){
					right_degrees(96);
					s_tr();
					forward();
				}else{
					left_degrees(96);
					s_tl();
					forward();
				}	
			}else if(path2 == 1 && l2 == 1 && sl == 0){
				 stop();
				 if(ter_var_pick == 11){
					 trotate_left();
					 pick(vacantL[0][0]);
					 vacantL[0][0] = 0;
					 left_degrees(185);	
					 tl_s();
					 t2t = 1;
					 forward();
					 ter_var_pick = 0;
				 }else if(ter_var_pick == 12){
					 trotate_right();
					 pick(vacantL[0][1]);
					 vacantL[0][1] = 0;
					 left_degrees(185);
					 leave = 1;
					 tl_s();
					 t2t = 1;
					 forward();
					 ter_var_pick = 0;
				 }else if(ter_var_drop == 11){
					 trotate_left();
					 loose();
					 vacantL[0][0] = grcolor;
					 init_arm();
					 grcolor = 0;
					 ter_var_drop = 0;
					 right_degrees(185);
					 tr_s();
					 t2t = 0;
				 }else if(ter_var_drop == 12){
					 trotate_right();
					 loose();
					 vacantL[0][1] = grcolor;
					 init_arm();
					 grcolor = 0;
					 ter_var_drop = 0;
					 right_degrees(185);
					 tr_s();
					 t2t = 0;
				 }else if(var == 12){
					 if(gr == 1){
						 trotate_right();
						 loose();
						 vacantL[1][0] = grcolor;
						 init_arm();
						 grcolor = 0;
					 }else{
						 trotate_right();
						 pick(vacantL[1][0]);
						 grcolor = vacantL[1][0];
						 vacantL[1][0] = 0;
						 right_degrees(90);
						 tr_s();
						 leave = 1;
					 }
				 }else if(var == 11){
					 if(gr == 1){
						 trotate_left();
						 loose();
						 vacantL[0][0] = grcolor;
						 init_arm();
						 grcolor = 0;
					 }else{
						 trotate_left();
						 pick(vacantL[0][0]);
						 grcolor = vacantL[0][0];
						 vacantL[0][0] = 0;
						 right_degrees(90);
						 tr_s();
						 leave = 1;
					 }
				 }else{
					 fl = 0;
					 if(vacantL[0][1] == -1 && gr == 0){
						 int val;
						 trotate_right();
						 one_time = 1;
						 //val = scan();
						 val = 4;
						 vacantL[0][1] = val;
					 }
					 if((vacantL[0][1] != blrefL[0][1]) && (vacantL[0][1] != -1) && (vacantL[0][1] != 0) && gr == 0){
						 if((sortL[0] == 0 || sortL[0] == -1) || (sortL[1] == 0 || sortL[1] == -1)){
							 if(one_time != 1){
								 trotate_right();
							 }
							 pick(vacantL[0][1]);
							 vacantL[0][1] = 0;
							 right_degrees(180);
							 tr_s();
							 fl = 1;
							 //turn and forward
						 }else{
							 init_arm();
							 fl = 0;
						 }
					 }else if((vacantL[0][1] == blrefL[0][1])){
						 init_arm();
						 fl = 0;
					 }
					 if(vacantL[0][0] == -1 && gr == 0 && fl != 1){
						 int val;
						 trotate_left();
						 one_time = 2;
						 //val = scan();
						 val = 3;
						 vacantL[0][0] = val;
					 }
					 if((vacantL[0][0] != blrefL[0][0]) && (vacantL[0][0] != -1) && (vacantL[0][0] != 0) && gr == 0 && fl != 1){
						 if((sortL[0] == 0 || sortL[0] == -1) || (sortL[1] == 0 || sortL[1] == -1)){
							 if(one_time != 2){
								 trotate_left();
							 }
							 pick(vacantL[0][0]);
							 grcolor = vacantL[0][0];
							 vacantL[0][0] = 0;
							 right_degrees(185);
							 tr_s();
							 forward();
							 //turn and forward
						}else{
							 gr = 0;
							 init_arm();
							 right_degrees(185);
							 tr_s();
						 }
					 }else if((vacantL[0][0] == blrefL[0][0])){
						 gr = 0;
						 init_arm();
						 right_degrees(185);
						 tr_s();
					 }
				 }				
			}else if(path2 == 2 && l2 == 1 && sl == 1 && (t2t!=1)){
				stop();
				if(gr == 1){
					if(leave != 1){
						if(sortL[0] == 0){
							left_degrees(96);
							drop_in_sort(0);
							sortL[0] = grcolor;
							grcolor = 0;
						}else if(sortR[1] == 0){
							left_degrees(96);
							drop_in_sort(1);
							sortL[0] = grcolor;
							grcolor = 0;
						}
					}else{
						buzzer_on();
						_delay_ms(500);
						buzzer_off();
						if(tr == 0){
							right_degrees(90);
						}else{
							left_degrees(90);
						}
						pth3_pth1();
						forward();
						sl = 0;
					}
				}else{
					if(sortL[0] != 0){
						pick_from_sort(0);
						grcolor = sortL[0];
						gr = 1;
						sortL[0] = 0;
					}else{
						pick_from_sort(1);
						grcolor = sortL[0];
						gr = 1;
						sortL[1] = 0;
					}
				}
				if(leave != 1){
					if(vacantL[0][0] == -1 || vacantL[0][1] == -1){
						left_degrees(96);
						s_tl();
						forward();
					}else if(vacantL[0][0] == -1 || vacantL[0][1] == -1){
						right_degrees(96);
						s_tr();
						forward();
					}
				}	
			}else if((path2 == 2) && (l2 == 1) && (sl == 0) && (t2t == 1)){
				if(tr != 1){
					s_tr();
				}else{
					s_tl();
				}
			}else if(path2 == 2 && l2 == 1 && sl == 0 && (t2t !=1)){
				if(tr == 1){
					right_degrees(95);
				}else if(tr == 0){
					left_degrees(95);
				}
				if(vacantL[0][0] != -1 && vacantL[0][1] != -1 && vacantL[1][0] != -1 && vacantL[1][1] != -1){
					before_leaving_check();
				}else{
					if(tr == 1){
						left_degrees(95);
						s_tl();
					}else{
						right_degrees(95);
						s_tr();
					}
				}
			}else if(path2 == 3 && l2 == 1 && sl == 0){
				stop();
				if(ter_var_pick == 32){
					trotate_left();
					pick(vacantL[1][1]);
					vacantL[1][1] = 0;
					left_degrees(185);
					tl_s();
					sl=0;
					t2t = 1;
					forward();
					ter_var_pick = 0;
				}else if(ter_var_pick == 31){
					buzzer_on();
					_delay_ms(1000);
					buzzer_off();
					trotate_right();
					pick(vacantL[1][0]);
					vacantL[1][0] = 0;
					left_degrees(185);
					tl_s();
					sl = 0;
					t2t = 1;
					//forward();
					ter_var_pick = 0;
				}else if(ter_var_drop == 32){
					trotate_left();
					loose();
					vacantL[1][1] = grcolor;
					init_arm();
					grcolor = 0;
					ter_var_drop = 0;
					t2t = 0;
					tl_s();
					right_degrees(185);
		
				}else if(ter_var_drop == 31){
					trotate_right();
					loose();
					vacantL[1][0] = grcolor;
					init_arm();
					grcolor = 0;
					ter_var_drop = 0;
					t2t = 0;
					tl_s();
					right_degrees(185);
				}else if(var == 32){
					if(gr == 1){
						trotate_left();
						loose();
						vacantL[1][1] = grcolor;
						init_arm();
						grcolor = 0;
						tl_s();
						right_degrees(185);
					}else{
						trotate_left();
						pick(vacantL[1][1]);
						vacantL[1][1] = 0;
						left_degrees(185);
						leave = 1;
						tl_s();
					}
				}else if(var == 31){
					if(gr == 1){
						trotate_right();
						loose();
						vacantL[1][0] = grcolor;
						init_arm();
						grcolor = 0;
						tl_s();
						right_degrees(185);
					}else{
						trotate_right();
						pick(vacantL[1][0]);
						vacantL[1][0] = 0;
						right_degrees(185);
						leave = 1;
						tl_s();
					}
				}else{
					fl = 0;
					if(vacantL[1][0] == -1 && gr == 0){
						int val;
						trotate_right();
						one_time = 1;
						//val = scan();
						val = 3;
						vacantL[1][0] = val;
					}
					if((vacantL[1][0] != blrefL[1][0]) && (vacantL[1][0] != -1) && (vacantL[1][0] != 0) && gr == 0){
						if((sortL[0] == 0 || sortL[0] == -1) || (sortL[1] == 0 || sortL[1] == -1)){
							if(one_time != 1){
								trotate_right();
							}
							pick(vacantL[1][0]);
							grcolor = vacantL[1][0];
							vacantL[1][0] = 0;
							right_degrees(188);
							tl_s();
							forward();
							fl = 1;
							//turn and forward
						}else{
							init_arm();
						}
					}else if((vacantL[1][0] == blrefL[1][0])){
						init_arm();
					}
					if(vacantL[1][1] == -1 && gr == 0 && fl != 1 ){
						int val;
						trotate_left();
						one_time = 2;
						//val = scan();
						val = 2;
						vacantL[1][1] = val;
					}
					if((vacantL[1][1] != blrefL[1][1]) && (vacantL[1][1] != -1) && (vacantL[1][1]= 0) && gr == 0 && fl != 1){
						if((sortL[0] == 0 || sortL[0] == -1) || (sortL[1] == 0 || sortL[1] == -1)){
							if(one_time != 2){
								trotate_right();
							}
							pick(vacantL[1][1]);
							grcolor = vacantL[1][1];
							vacantL[1][1] = 0;
							left_degrees(185);
							tl_s();
							forward();
							//turn and forward
						}
						else{
							gr = 0;
							init_arm();
							right_degrees(185);
							tl_s();
						}
					}else if(vacantL[1][1] == blrefL[1][1]){
						gr = 0;
						init_arm();
						right_degrees(185);
						tl_s();
					}
				}
			}
		}	
		count111++;	
	}
}
find_non_matching_terminal(){
	if(l1 == 1){	
		if(vacantR[0][0] != blrefR[0][0] && vacantR[0][0] != 0){
			return 21;
		}
		else if(vacantR[0][1] != blrefR[0][1] && vacantR[0][1] != 0){
			return 22;
		}
		else if(vacantR[1][0] != blrefR[1][0] && vacantR[1][0] != 0){
			return 41;
		}
		else if(vacantR[1][1] != blrefR[1][1] && vacantR[1][1] != 0){
			return 42;
		}else{
			return 0;
		}
	}else if(l2 == 1){
		
		if(vacantL[0][0] != blrefL[0][0] && vacantL[0][0] != 0){
			return 11;
		}
		else if(vacantL[0][1] != blrefL[0][1] && vacantL[0][1] != 0){
			return 12;
		}
		else if(vacantL[1][0] != blrefL[1][0] && vacantL[1][0] != 0){
			return 31;
		}
		else if(vacantL[1][1] != blrefL[1][1] && vacantL[1][1] != 0){
			return 32;
		}else{
			return 0;
		}
	}	
}	


