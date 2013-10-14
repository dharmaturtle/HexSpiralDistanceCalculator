#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int lim);
int is_corner(int array[]);

int main(){
	int i, j, a, b, c, direction; // for loop, another for loop, first user input, second user input, max of user input, direction hex is going in
	int magnitude = 1;	// magnitude of hex
	int** hex;			// mother array, holds all the coordintes
	
	printf("Please type the first hex number : ");
	scanf_s("%d", &a);
	getchar(); // swallows the /n from the scan_f
	printf("Please type the second hex number: ");
	scanf_s("%d", &b);
	getchar();

	if ( a > b )
		c = a;
	else
		c = b;
	
	// creating hex. Dimensions of max(userinput)*3, because there are 3 coordinates
	hex = (int**) malloc(c*sizeof(int*));
	for (i = 0; i < c; i++){
		hex[i] = (int*) malloc(3*sizeof(int));
		for (j = 0; j < 3; j++)
			hex[i][j] = 0; // fills hex with 0's
	}
	hex[1][1] = -1;
	hex[1][2] = 1; // Results in hex[] = {0,0,0},{0,-1,1} which are the initial conditions necessary to get goin!

	for (i=2; i<c; i++){
		int corner = is_corner(hex[i - 1]);
		
		// if this is a corner...
		// case/switch values were determined looking at patterns in the spiral
		if (corner != 0){
			direction = corner; // establish direction for non-corners
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
					magnitude++; // moving onto the next ring of the spiral
					break;
			}
		}

		// if not a corner... (a straight segment)
		else{
			switch(direction){ // grab corner as determined earlier
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
	
	//  this prints the coordinates of every hex. Used for debugging.
	/*for (i=0; i<c; i++){
		printf("%2d: ",i+1);
		printArray(hex[i],3);
	}*/

	//printf("Coordinates of %3d are: (%3d, %3d, %3d)\n", a, hex[a-1][0], hex[a-1][1], hex[a-1][2] );
	//printf("Coordinates of %3d are: (%3d, %3d, %3d)\n", b, hex[b-1][0], hex[b-1][1], hex[b-1][2] );
	printf("Minimum hexagons between them is %d\n", ( abs(hex[a-1][0] - hex[b-1][0]) + abs(hex[a-1][1] - hex[b-1][1]) + abs(hex[a-1][2] - hex[b-1][2]))/2);

	// just for practice! Better to learn good technique now
	for (i = 0; i < c; i++)
	   free(hex[i]);
	free(hex);
	
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

int is_corner( int a[]){
	int corner = 0; // initially not a corner
	if ((a[0] == 0) && (a[1] < 0) && (a[2] > 0))
		corner = 1; // but it can be. South
	else if ((a[1] == 0) && (a[0] < 0) && (a[2] > 0))
		corner = 2; // south west
	else if ((a[2] == 0) && (a[0] < 0) && (a[1] > 0))
		corner = 3; // north west
	else if ((a[0] == 0) && (a[1] > 0) && (a[2] < 0))
		corner = 4; // north
	else if ((a[1] == 0) && (a[0] > 0) && (a[2] < 0))
		corner = 5; // north east
	else if ((a[2] == 0) && (a[0] > 0) && (a[1] < 0))
		corner = 6; // south east
	return corner;
}

/*
http://www-ee.eng.hawaii.edu/~tep/EE160/Code/Textbook/Chap7/scores2.c
http://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm
*/