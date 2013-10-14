#include <stdio.h>
void printArray(int array[], int lim);
int is_corner(int array[], int lim);

int main(){
	int hex[10][3] = { 1, 0, 0, 
		               0, 2, 0, 
					   0, 0, 3, 
					   -4, 0, 0, 
					   0, -5, 0, 
					   0, 0, -6, 
					   -7, 1, 0,
					   -7, 0, 8,
					   8, 0, 0 };
	int hexan[70][3] = {0,0,0,-1,0,0};
	int i;
	int magnitude = 0;
	int direction;
	for ( i=0; i<10; i++){
		int size = (sizeof(hex[i]) / sizeof(hex[i][0]));
		/*printArray( hex[i] , size );
		printf("This is corner status %d\n", is_corner(hex[i], size));*/
	}
	/*for ( i=0; i<10; i++){
		int size = (sizeof(hex[i]) / sizeof(hex[i][0]));
		printArray( hex[i] , size );
	}*/

	//begin generator
	for (i=2; i<70; i++){
		int corner = is_corner(hexan[i - 1], 3);
		if (corner != 0){
			direction = corner;
			switch(corner){
				case -1:hexan[i][1] = -1;
						hexan[i][0] = -magnitude;
						break;
				case -2:hexan[i][2] = -1;
						hexan[i][1] = -magnitude;
						break;
				case -3:hexan[i][0] = 1;
						hexan[i][2] = -magnitude;
						break;
				case 1: hexan[i][1] = 1;
						hexan[i][0] = magnitude;
						break;
				case 2: hexan[i][2] = 1;
						hexan[i][1] = magnitude;
						break;
				case 3: magnitude++;
						hexan[i][0] = -1;
						hexan[i][2] = magnitude;
						break;
			}
		}
		else{
			printf("Direction = %d with index %d and input array ",direction,i);
			printArray(hexan[i],3);
			switch(direction){
			case 3: hexan[i][0] = hexan[i-1][0] - 1;
					hexan[i][2] = hexan[i-1][2] - 1;
					break;
			case -1:hexan[i][0] = hexan[i-1][0] + 1;
					hexan[i][1] = hexan[i-1][1] - 1;
					break;
			case -2:hexan[i][1] = hexan[i-1][1] + 1;
					hexan[i][2] = hexan[i-1][2] - 1;
					break;
			case -3:hexan[i][0] = hexan[i-1][0] + 1;
					hexan[i][2] = hexan[i-1][2] + 1;
					break;
			case 1: hexan[i][0] = hexan[i-1][0] - 1;
					hexan[i][1] = hexan[i-1][1] + 1;
					break;
			case 2: hexan[i][2] = hexan[i-1][2] + 1;
					hexan[i][1] = hexan[i-1][1] - 1;
					break;
			}
		}
	}
	for (i=0; i<70; i++){
		printf("%2d: ",i+1);
		printArray(hexan[i],3);
	}
	getchar();
	return 0;
}

void printArray( int a[], int lim ){
	int i;
	for (i=0; i < lim; i++) {
		printf("%2d ",a[i]);
		if ( lim == (i + 1) )
			printf("\n");
	}
}

int is_corner( int a[], int lim){
	int i;
	int corner = 0; //get rid of the = 0 in production
	int zeroes = 0;
	for (i=0; i < lim; i++) {
		if (a[i] == 0)
			zeroes++;
		else{
			if (a[i] > 0)
				corner = i + 1;
			else
				corner = -i - 1;
		}
	}
	if (zeroes == 1)
		corner = 0;
	return corner;
}


/* [000]
   [-100]
   [0-10]
   [00-1]
   [110]
   []
next ring occurs on 00X
next turn occurs on X00, 0x0,or 00x
question is how to generate the next hex

array returnsArrayOfNextCoordinates(array motherArray){
	
}*/

/*
http://www-ee.eng.hawaii.edu/~tep/EE160/Code/Textbook/Chap7/scores2.c
*/