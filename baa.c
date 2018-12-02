#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define max (100)

int  myArray[max];
int numberProcesses = 0;
int head;
int sum = 0;
int myArray2[max];
void fcfs(){
	int temp = 0;
	head = myArray[0];
	for(int i = 0; i < numberProcesses; i++){
		if(head > myArray[i]){
			temp = head - myArray[i];
			sum += temp;
			head = myArray[i];
		}
		//if(head < myArray[i]){
		else{
			temp = myArray[i] - head;
			sum += temp;
			head = myArray[i];
		}
	}
	printf("\nFCFS Total Seek: %d",sum);
}

void sstf(){
	int temp = 0;
	sum = 0;
	head = myArray[0];
	for(int i=0; i < numberProcesses -1 ; i++){
		for(int j = i+1; j < numberProcesses; j++){
			if(abs(myArray[i] - myArray[j]) < abs(myArray[i] - myArray[i+1])){
				int temp = myArray[i+1];
   				myArray[i+1] = myArray[j];
    				myArray[j] = temp;
			}
    		}
	}
	for(int i = 1; i < numberProcesses; i++){
		sum = sum + abs(head-myArray[i]);
		head = myArray[i];
	}
	printf("\nSSTF Total Seek: %d", sum);
}

void look(){
	int temp = 0;
	sum = 0;
	head = myArray[0];
	int x;
	for(int i = 0; i < numberProcesses; i++){
		for(int j = 0; j < numberProcesses; j++){
			if(myArray[j] > myArray[i]){
				temp = myArray[i];
				myArray[i] = myArray[j];
				myArray[j] = temp;
			}
		}
	}
	for(int i = 0; i < numberProcesses; i++){
		if(myArray[i] == head){
			x = i;
		}
	}
	for(int i = x; i < numberProcesses-1; i++){
		sum += myArray[i+1]-myArray[i];
	}
	sum +=  myArray[numberProcesses-1] - myArray[x];

	for(int i = x; i > 0; i--){
		sum += myArray[i] - myArray[i-1];
	}
	printf("\nLOOK Total Seek: %d", sum);
}
void clook(){
	int temp = 0;
	sum = 0;
	head = 0;
	head = myArray2[0];
	int x;

	for(int i = 0; i < numberProcesses; i++){
		for(int j = 0; j < numberProcesses; j++){
			if(myArray2[j] > myArray2[i]){
				temp = myArray2[i];
				myArray2[i] = myArray2[j];
				myArray2[j] = temp;
			}
		}
	}
	for(int i = 0; i < numberProcesses; i++){
		if(myArray2[i] == head){
			x = i;
		}
	}
	for(int i = x; i < numberProcesses-1; i++){
		sum += myArray2[i+1]-myArray2[i];
	}
	sum +=  myArray2[numberProcesses-1] - myArray2[0];

	for(int i = 0; i < x-1; i++){
		sum += myArray2[i+1] - myArray2[i];
	}
	printf("\nC-LOOK Total Seek: %d", sum);
}

int main (int argc, char **argv) {

	int i = 0;

	FILE *input = argc > 1 ? fopen (argv[1],"r") : stdin;
	if (!input) {
		fprintf (stderr, "error: file open failed '%s'.\n", argv[1]);
		return 1;
	}
	while (i < max && fscanf (input, "%d", &myArray[i]) == 1){
		numberProcesses++;
		i++;
	}

	for(int i=0; i<numberProcesses; i++){
		myArray2[i] = myArray[i];
	}

	printf("\nAssignment 7: Block Access Algorithm");
	printf("\nBy: Mariana Acosta\n");
	fcfs();
	sstf();
	look(); 
	clook();

	printf("\n");
	return 0;


}
/*FCFS Total Seek: 1594
SSTF Total Seek: 287
LOOK Total Seek: 269
C-LOOK Total Seek: 477

*/
