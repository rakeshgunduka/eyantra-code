void srotate_right(){
	right_degrees(90);
}
void srotate_left(){
	left_degrees(90);
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
	dc2F();
	_delay_ms(5000);
}
void pick_from_sort(int s){
	if(s == 0){
		leftsort();
		hold();
		init_arm();
		gr = 1;
	}else if(s == 1){
		rightsort();
		hold();
		init_arm();
		gr = 1;
	}
}
void drop_in_sort(int s){
	if(s == 0){
		leftsort();
		loose();
		init_arm();
		gr = 0;
	}else if(s == 1){
		rightsort();
		loose();
		init_arm();
		gr = 0s;
	}
}
before_leaving_check(){
	if((sortL[0] == 0 && sortL[1] == 0) && (sortR[0] == 0 && sortR[1] == 0)){
		//beep();
	}else if( l1 == 1){
		if(sortR[0] != -1 && sortR[1] != -1){
			for(i=0;i<2;i++){
				for(j =0;j<2 ;j++){
					if(vacantR[i][j] == 0){
						if(sortR[0] == blrefR[i][j]){
							pick_from_sort(0);
							grcolor = sortR[0];
							go_and_drop(0,i,j);				//sort to position
						}else if(sortR[1] == blrefR[i][j]){
							pick_from_sort(1);
							grcolor = sortR[1];
							go_and_drop(1,i,j);				//sort to position
						}
					}									
				}				
			}
		}		
	}else if( l2 == 1){
		if(sortL[0] != -1 && sortL[1] != -1){
			for(i=0;i<2;i++){
				for(j = 0;j<2 ;j++){
					if(vacantL[i][j] == 0){
						if(sortL[0] == blrefL[i][j]){
							pick_from_sort(0);
							go_and_drop(0,i,j);				//sort to position
						}
						if(sortL[1] == blrefL[i][j]){
							pick_from_sort(1);
							go_and_drop(1,i,j);				//sort to position
						}
					}
				}
			}
		}
	}else if(l1 == 1 && (sortR[0] == 0 || sortR[1] == 0)){
		int tmp = check_matching_from_sort();
		if(tmp == i2){
			go_to_terminal(i2);
			if(check_which_can_be_lifted(1) == 1){
				//right se lift kar
			}else if(check_which_can_be_lifted(2) == 2){
				//left se lift kar
			}
			if(sortR[0] == 0){
				drop_in_sort(0);
			}else{
				drop_in_sort(1);
			}			
		}else if(tmp == i4){
			go_to_terminal(i2);
			if(check_which_can_be_lifted(1) == 1){
				//right se lift kar
			}else if(check_which_can_be_lifted(2) == 2){
				//left se lift kar
			}
			if(sortR[0] == 0){
				drop_in_sort(0);
			}else{
				drop_in_sort(1);
			}
		}else{
			take_something_and_drop_in_sort();
		}
	}else if(l2 == 2 && (sortL[0] == 0 || sortL[1] == 0)){
		int tmp = check_matching_from_sort();
		if(tmp == i1){
			go_to_terminal(i2);
			if(check_which_can_be_lifted(1) == 1){
				//right se lift kar
			}else if(check_which_can_be_lifted(2) == 2){
				//left se lift kar
			}
			if(sortL[0] == 0){
				drop_in_sort(0);
			}else{
				drop_in_sort(1);
			}
		}else if(tmp == i3){
			go_to_terminal(i2);
			if(check_which_can_be_lifted(1) == 1){
				//right se lift kar
			}else if(check_which_can_be_lifted(2) == 2){
				//left se lift kar
			}
			if(sortL[0] == 0){
				drop_in_sort(0);
			}else{
				drop_in_sort(1);
			}
		}else{
			take_something_and_drop_in_sort();
		}
	}else {
		int var = find_non_matching_terminal();
		if(var == 21){
			left_degrees(90);
			s_tl();
			forward();
		}else if(var == 22){
			left_degrees(90);
			s_tl();
			forward();
		}else if(var == 41){
			right_degrees(90);
			s_tr();
			forward();
		}else if(var == 42){
			right_degrees(90);
			s_tr();
			forward();
		}else{
			if(gr == 1){
				right_degrees(185);
				forward();
				pth1_pth3();
				leave = 0;
			}else{
				if(sortR[0] != 0){
					pick_from_sort(0);
				}else{
					pick_from_sort(1);
				}
				pth1_pth3();
				leave = 0;
			}
		}
	}
}

find_non_matching_terminal(){
	if(vacantR[0][0] != blrefR[0][0] && vacantR[0][0] != 0){
		return 21;
	}
	if(vacantR[0][1] != blrefR[0][1] && vacantR[0][1] != 0){
		return 22;
	}
	if(vacantR[1][0] != blrefR[1][0] && vacantR[1][0] != 0){
		return 41;
	}
	if(vacantR[1][1] != blrefR[1][1] && vacantR[1][1] != 0){
		return 42;
	}
}