int sort_to_ter(){
	buzzer_on();
	_delay_ms(10);
	buzzer_off();
	if( l1 == 1 && ((sortR[0] != -1 && sortR[0] != 0) || (sortR[1] != -1 && sortR[1] != 0))){
		if(sortR[0] == i2 || sortR[0] == i4 ){
			for(i=0;i<2;i++){
				for(j=0;j<2;j++){
					if(vacantR[i][j] == 0){
						if(sortR[0] == blrefR[i][j]){
							pick_from_sort(0);
							if(i==0 && j ==0){
								srotate_left();
								s_tl();
								var = 21;
							}
							else if(i==0 && j ==1){
								buzzer_on();
								_delay_ms(500);
								buzzer_off();
								srotate_left();
								s_tl();
								var = 22;
							}
							else if(i==1 && j ==0){
								srotate_right();
								s_tr();
								var = 41;
							}
							else if(i==1 && j ==1){
								srotate_right();
								s_tr();
								var = 42;
							}
							return 1;
						}							
					}
				}
			}
		}else if(sortR[1] == i2 || sortR[1] == i4 ){
			for(i=0;i<2;i++){
				for(j=0;j<2;j++){
					if(vacantR[i][j] == 0){
						if(sortR[1] == blrefR[i][j]){
								if(i==0 && j ==0){
									srotate_left();
									s_tl();
									var = 21;
								}
								else if(i==0 && j ==1){
									srotate_left();
									s_tl();
									var = 22;
								}
								else if(i==1 && j ==0){
									srotate_right();
									s_tr();
									var = 41;
								}
								else if(i==1 && j ==1){
									srotate_right();
									s_tr();
									var = 42;
								}
							return 2;
						}
					}
				}
			}
		}else{
			return 0;
		} 	
	}else if( l2 == 1 && ((sortL[0] != -1 && sortL[0] != 0) || (sortL[1] != -1 && sortL[1] != 0))){
		buzzer_on();
		_delay_ms(10);
		buzzer_off();
		if(sortL[0] == i1 || sortL[0] == i3 ){
			for(i=0;i<2;i++){
				for(j=0;j<2;j++){
					if(vacantL[i][j] == 0){
						if(sortL[0] == blrefL[i][j]){
							pick_from_sort(0);
							if(i==0 && j ==0){
								srotate_right();
								s_tr();
								var = 11;
							}
							else if(i==0 && j ==1){
								srotate_right();
								s_tr();
								var = 12;
							}
							else if(i==1 && j ==0){
								buzzer_on();
								_delay_ms(500);
								buzzer_off();
								srotate_left();
								s_tl();
								var = 31;
							}
							else if(i==1 && j ==1){
								srotate_left();
								s_tl();
								var = 32;
							}
							return 1;
						}
					}
				}
			}
		}else if(sortL[1] == i1 || sortL[1] == i3 ){
			for(i=0;i<2;i++){
				for(j=0;j<2;j++){
					if(vacantL[i][j] == 0){
						if(sortL[1] == blrefL[i][j]){
							pick_from_sort(1);
							if(i==0 && j ==0){
								srotate_right();
								s_tr();
								var = 11;
							}
							else if(i==0 && j ==1){
								srotate_right();
								s_tr();
								var = 12;
							}
							else if(i==1 && j ==0){
								srotate_left();
								s_tl();
								var = 31;
							}
							else if(i==1 && j ==1){
								srotate_left();
								s_tl();
								var = 32;
							}
							return 1;
						}
					}
				}
			} 
		}else{
			return 0;
		}
	}	
}

void srotate_right(){
	right_degrees(95);
}
void srotate_left(){
	left_degrees(95);
}
void go_and_drop(int s,int m,int n){				//sort_to_position
if(l1 == 1){
	if((m == 0) && (n == 0)){
		srotate_left();
		s_tl();
		var = 21;
	}
	if((m == 0) && (n == 1)){
		srotate_left();
		s_tl();
		var = 22;
	}
	if((m == 1) && (n == 0)){
		srotate_right();
		s_tr(); 
		var = 41;
	}
	if((m == 1) && (n == 1)){
		srotate_right();
		s_tr();
		var = 42;
	}
}else if(l2 == 1){
	if((m == 0) && (n == 0)){
		srotate_left();
	}
	if((m == 0) && (n == 1)){
		srotate_left();
	}
	if((m == 1) && (n == 0)){
		srotate_right();
	}
	if((m == 1) && (n == 1)){
		srotate_right();
	}
}
}
void leftsort(){
	_delay_ms(1000);
	servo_1(45);
	_delay_ms(1000);
	servo_2(160);
	_delay_ms(1000);
	servo_3(45);
}
void rightsort(){
	_delay_ms(1000);
	servo_1(135); 
	_delay_ms(1000);
	servo_2(160);
	_delay_ms(1000);
	servo_3(45);
}
void hold(){
	dc1F();
	dc2F();
	_delay_ms(5000);
}
void loose(){
	dc1B();
	dc2B();
	_delay_ms(5000);
	gr = 0;
}
void pick_from_sort(int s){
	if(l1 == 1){
		if(s == 0){
			leftsort();
			hold();
			init_arm();
			gr = 1;
			grcolor = sortR[0];
			sortR[0] = 0;
		}else if(s == 1){
			rightsort();
			hold();
			init_arm();
			gr = 1;
			grcolor = sortR[1];
			sortR[1] = 0;
		}
	}else if(l2 == 1){
		if(s == 0){
			leftsort();
			hold();
			init_arm();
			gr = 1;
			grcolor = sortL[0];
			sortL[0] = 0;
		}else if(s == 1){
			rightsort();
			hold();
			init_arm();
			gr = 1;
			grcolor = sortL[1];
			sortL[1] = 0;
		}
	}	
}
void drop_in_sort(int s){
	if(l1 == 1){
		if(s == 0){
			leftsort();
			loose();
			init_arm();
			sortR[0] = grcolor;
			gr = 0;
			grcolor = 0;
		}else if(s == 1){
			rightsort();
			loose();
			init_arm();
			sortR[1] = grcolor;
			gr = 0;
			grcolor = 0;
		}
	}else if(l2 == 1){
		if(s == 0){
			leftsort();
			loose();
			init_arm();
			sortL[0] = grcolor;
			gr = 0;
			grcolor = 0;
		}else if(s == 1){
			rightsort();
			loose();
			init_arm();
			sortL[1] = grcolor;
			gr = 0;
			grcolor = 0;
		}
	}else if(l0 == 1){
		if(mp_r == 1){
			if(s == 0){
				leftsort();
				loose();
				init_arm();
				sortL[0] = grcolor;
				gr = 0;
				grcolor = 0;
			}else if(s == 1){
				rightsort();
				loose();
				init_arm();
				sortL[1] = grcolor;
				gr = 0;
				grcolor = 0;
			}
		}else if(mp_r == 0){
			if(s == 0){
				leftsort();
				loose();
				init_arm();
				sortR[0] = grcolor;
				gr = 0;
				grcolor = 0;
			}else if(s == 1){
				rightsort();
				loose();
				init_arm();
				sortR[1] = grcolor;
				gr = 0;
				grcolor = 0;
			}
		}		
	}	
}
before_leaving_check(){
	stop();
	buzzer_on();
	_delay_ms(500);
	buzzer_off();
	if(l1 == 1){
		if(gr == 0){
			if(vacantR[0][0] == i4){					//check T2 to T4
				if(vacantR[1][0] == 0){
					left_degrees(95);
					s_tl();
					ter_var_pick = 21;
					ter_var_drop = 41;
					return;
				}else if(vacantR[1][1] == 0){
					left_degrees(95);
					s_tl();
					ter_var_pick = 21;
					ter_var_drop = 42;
					return;
				}else{
					//optimize
				}
			}else if(vacantR[0][1] == i4){				//check T2 to T4
				if(vacantR[1][0] == 0){
					buzzer_on();
					_delay_ms(1000);
					buzzer_off();
					left_degrees(95);
					s_tl();
					ter_var_pick = 22;
					ter_var_drop = 41;
					t2t = 1;
					sr = 0;
					return;
				}else if(vacantR[1][1] == 0){
					left_degrees(95);
					s_tl();
					ter_var_pick = 22;
					ter_var_drop = 42;
				}else{
					//optimize
				}
			}else if(vacantR[1][0] == i2){				//check T4 to T2
				gr = 0;
				if(vacantR[0][0] == 0){
					right_degrees(95);
					s_tr();
					ter_var_pick= 41;
					ter_var_drop = 21;
				}else if(vacantR[0][1] == 0){
					right_degrees(95);
					s_tr();
					ter_var_pick = 41;
					ter_var_drop = 22;
				}else{
					//optimize
				}
			}else if(vacantR[1][1] == i2){				//check T4 to T2
				gr = 0;
				if(vacantR[0][0] == 0){
					right_degrees(95);
					s_tr();
					ter_var_pick = 42;
					ter_var_drop = 21;
				}else if(vacantR[1][0] == 0){
					right_degrees(95);
					s_tr();
					ter_var_pick = 42;
					ter_var_drop = 22;
				}else{
					//optimize
				}
			}else if(sort_to_ter()){
				
			}else if(find_non_matching_terminal()){
				var = find_non_matching_terminal();
				if(var > 0){
					if(var == 21){
						left_degrees(90);
						s_tl();
						//forward();
					}else if(var == 22){
						left_degrees(90);
						s_tl();
						//forward();
					}else if(var == 41){
						right_degrees(90);
						s_tr();
						//forward();
					}else if(var == 42){
						right_degrees(90);
						s_tr();
						//forward();
					}
				}
			}else if((sortR[0] != 0 && sortR[0] != -1) || (sortR[1] != 0 && sortR[1] != -1)){
				buzzer_on();
				_delay_ms(500);
				buzzer_off();
				if(sortR[0] != i2 && sortR[0] != i4 && sortR[0] != 0){
					//pick sortR[0] and leave
					pick_from_sort(0);
					right_degrees(185);
					pth1_pth3();
					sr = 0;
				}else if(sortR[1] != i2 && sortR[1] != i4 && sortR[1] != 0){
					pick_from_sort(1);
					right_degrees(185);
					pth1_pth3();
					sr = 0;
				}
				
			}						
		}else if(gr == 1){
			if(grcolor == vacantR[0][0]){
				left_degrees(95);
				s_tl();
				var = 21;
			}else if(grcolor == vacantR[0][1]){
				left_degrees(95);
				s_tl();
				var = 22;
			}else if(grcolor == vacantR[1][0]){
				right_degrees(95);
				s_tr();
				var = 41;
			}else if(grcolor == vacantR[1][1]){
				right_degrees(95);
				s_tr();
				var = 42;
			}else if(sortR[0] == 0){
				drop_in_sort(0);
				sr = 0;
			}else if(sortR[1] == 0){
				drop_in_sort(1);
				sr = 0;
			}
		}
	}else if(l2 == 1){
		if(gr == 0){
			if(vacantL[1][1] == i1){					//check T3 to T1
				if(vacantL[0][1] == 0){
					left_degrees(95);
					s_tl();
					ter_var_pick = 32;
					ter_var_drop = 12;
				}else if(vacantL[0][0] == 0){
					left_degrees(95);
					s_tl();
					ter_var_pick = 32;
					ter_var_drop = 11;
				}else{
					//optimize
				}
			}else if(vacantL[1][0] == i1){				//check T3 to T1
				if(vacantL[0][1] == 0){
					left_degrees(95);
					s_tl();
					ter_var_pick = 31;
					ter_var_drop =12 ;
				}else if(vacantL[0][0] == 0){
					left_degrees(95);
					s_tl();
					ter_var_pick = 31;
					ter_var_drop = 11;
				}else{
					//optimize
				}
			}else if(vacantL[0][1] == i3){				//check T1 to T3
				gr = 0;
				if(vacantL[1][1] == 0){
					right_degrees(95);
					s_tr();
					ter_var_pick= 12;
					ter_var_drop = 32;
				}else if(vacantL[1][0] == 0){
					right_degrees(95);
					s_tr();
					ter_var_pick = 12;
					ter_var_drop = 31;
				}else{
					//optimize
				}
			}else if(vacantL[0][0] == i3){				//check T1 to T3
				gr = 0;
				if(vacantL[1][1] == 0){
					right_degrees(95);
					s_tr();
					ter_var_pick = 11;
					ter_var_drop = 32;
				}else if(vacantL[0][1] == 0){
					right_degrees(95);
					s_tr();
					ter_var_pick = 11;
					ter_var_drop =31;
				}else{
					//optimize
				}
			}else if(sort_to_ter()){
				buzzer_on();
				_delay_ms(1000);
				buzzer_off();
			}else if(find_non_matching_terminal()){
				var = find_non_matching_terminal();
				if(var > 0){
					if(l1 == 1){
						if(var == 21){
							left_degrees(90);
							s_tl();
							//forward();
						}else if(var == 22){
							left_degrees(90);
							s_tl();
							//forward();
						}else if(var == 41){
							right_degrees(90);
							s_tr();
							//forward();
						}else if(var == 42){
							right_degrees(90);
							s_tr();
							//forward();
						}
					}else if(l2 == 1){
						if(var == 31){
							left_degrees(90);
							s_tl();
							//forward();
						}else if(var == 32){
							left_degrees(90);
							s_tl();
							//forward();
						}else if(var == 11){
							right_degrees(90);
							s_tr();
							//forward();
						}else if(var == 12){
							right_degrees(90);
							s_tr();
							//forward();
						}
					}					
				}
			}else if((sortL[0] != 0 && sortL[0] != -1) || (sortL[1] != 0 && sortL[1] != -1)){
				if(sortL[0] != i1 && sortL[0] != i3 && sortL[0] != 0){
					//pick sortL[0] and leave
					pick_from_sort(0);
					right_degrees(190);
					pth3_pth1();
					sl = 0;
				}else if(sortL[1] != i1 && sortL[1] != i3 && sortL[1] != 0){
					pick_from_sort(1);
					right_degrees(190);
					pth3_pth1();
					sl = 0;
				}
			}						
		}else if(gr == 1){
			if(grcolor == vacantL[0][0]){
				left_degrees(95);
				s_tl();
				var = 21;
			}else if(grcolor == vacantL[0][1]){
				left_degrees(95);
				s_tl();
				var = 22;
			}else if(grcolor == vacantL[1][0]){
				right_degrees(95);
				s_tr();
				var = 41;
			}else if(grcolor == vacantL[1][1]){
				right_degrees(95);
				s_tr();
				var = 42;
			}else if(sortL[0] == 0){
				drop_in_sort(0);
				sr = 0;
			}else if(sortL[1] == 0){
				drop_in_sort(1);
				sl = 0;
			}
		}
	}else if(l0 == 1){
		if(path == 3){
			if(gr == 1){
				if(sort_to_ter()){
					
				}else{
					if(sortL[0] == 0){
						drop_in_sort(0);
					}else if(sortL[1] == 0){
						drop_in_sort(1);
					}
				}
			}else{
				l2 = 1;
				l0 = 0;
				l1 = 0;
				path2 = 2;
				sl = 0;
				t2t = 0;
			}			
		}else if(path == 1){
			if(gr == 1){
				if(sort_to_ter()){
									
				}else{
					if(sortL[0] == 0){
						drop_in_sort(0);
					}else if(sortL[1] == 0){
						drop_in_sort(1);
					}					
				}
			}
		}		
	}				
}					
			