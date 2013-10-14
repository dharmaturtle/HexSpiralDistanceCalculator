#include <stdio.h>
#include <stdlib.h>
#define INDEX 100
void printArray(int array[], int lim);
int is_corner(int array[], int lim);

int main(){
	int hex[INDEX][3] = {0,0,0,0,-1,1};
	int i, a, b;
	int magnitude = 1;
	int direction;

	printf("Please type the first hex number (under 100): ");
	scanf_s("%d", &a);
	getchar();
	printf("Please type the second hex number (under 100): ");
	scanf_s("%d", &b);
	getchar();

	//if (a > b)
	//	a = index

	for (i=2; i<INDEX; i++){
		int corner = is_corner(hex[i - 1], 3);
		if (corner != 0){
			direction = corner;
			switch(corner){
			case 1: hex[i][0] = -1;
					hex[i][1] = -magnitude + 1;
					hex[i][2] = magnitude;
					break;
			case 2: hex[i][0] = -magnitude;
					hex[i][1] = 1;
					hex[i][2] = magnitude - 1;
					break;
			case 3: hex[i][0] = -magnitude + 1;
					hex[i][1] = magnitude;
					hex[i][2] = -1;
					break;
			case 4: hex[i][0] = 1;
					hex[i][1] = magnitude -1;
					hex[i][2] = -magnitude;
					break;
			case 5: hex[i][0] = magnitude;
					hex[i][1] = -1;
					hex[i][2] = -magnitude +1;
					break;
			case 6: hex[i][0] = magnitude;
					hex[i][1] = -magnitude -1;
					hex[i][2] = 1;
					magnitude++;
					break;
			}
		}
		else{
			switch(direction){
			case 6: hex[i][0] = hex[i-1][0] - 1;
					hex[i][1] = hex[i-1][1];
					hex[i][2] = hex[i-1][2] + 1;
					break;
			case 1: hex[i][0] = hex[i-1][0] - 1;
					hex[i][1] = hex[i-1][1] + 1;
					hex[i][2] = hex[i-1][2];
					break;
			case 2: hex[i][0] = hex[i-1][0];
					hex[i][1] = hex[i-1][1] + 1;
					hex[i][2] = hex[i-1][2] - 1;
					break;
			case 3: hex[i][0] = hex[i-1][0] + 1;
					hex[i][1] = hex[i-1][1];
					hex[i][2] = hex[i-1][2] - 1;
					break;
			case 4: hex[i][0] = hex[i-1][0] + 1;
					hex[i][1] = hex[i-1][1] - 1;
					hex[i][2] = hex[i-1][2];
					break;
			case 5: hex[i][0] = hex[i-1][0];
					hex[i][1] = hex[i-1][1] - 1;
					hex[i][2] = hex[i-1][2] + 1;
					break;
			}
		}
	}
	for (i=0; i<INDEX; i++){
		printf("%2d: ",i+1);
		printArray(hex[i],3);
	}

	printf("%d %d %d\n", hex[a-1][0], hex[a-1][1], hex[a-1][2] );
	printf("%d %d %d\n", hex[b-1][0], hex[b-1][1], hex[b-1][2] );
	printf("%d", ( abs(hex[a-1][0] - hex[b-1][0]) + abs(hex[a-1][1] - hex[b-1][1]) + abs(hex[a-1][2] - hex[b-1][2]))/2);
	
	getchar();
	return 0;
}

void printArray( int a[], int lim ){
	int i;
	for (i=0; i < lim; i++){
		printf("%2d ",a[i]);
		if (lim == (i + 1))
			printf("\n");
	}
}

int is_corner( int a[], int lim){
	int corner = 0;
	if ((a[0] == 0) && (a[1] < 0) && (a[2] > 0))
		corner = 1;
	else if ((a[1] == 0) && (a[0] < 0) && (a[2] > 0))
		corner = 2;
	else if ((a[2] == 0) && (a[0] < 0) && (a[1] > 0))
		corner = 3;
	else if ((a[0] == 0) && (a[1] > 0) && (a[2] < 0))
		corner = 4;
	else if ((a[1] == 0) && (a[0] > 0) && (a[2] < 0))
		corner = 5;
	else if ((a[2] == 0) && (a[0] > 0) && (a[1] < 0))
		corner = 6;
	return corner;
}

/*
http://www-ee.eng.hawaii.edu/~tep/EE160/Code/Textbook/Chap7/scores2.c
http://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm
*/