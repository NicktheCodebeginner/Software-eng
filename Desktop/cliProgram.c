#include <stdio.h>
#define STRLEN 50

/*void showMenu(char * options){
    int numOfOptions = 0;
	for(int i = 0; i <= STRLEN; i++)
		printf("*");
	printf("\n");
	for(int i = 0; i < 8; i++)
	{
		printf("*");
		for(int k = 0; k < 5; k++){
			printf(" ");
		}
		printf("#%d: ", i + 1);
		for(int j = 0; j < 20; j++)
		{

			printf("%c", options[i][j]);
		}
		for(int k = 0; k < 5; k++){
			printf(" ");
		}
		printf("*");
	}
	for(int i = 0; i <= STRLEN; i++)
		printf("*");
}

int lenOfArray(char * arr){
	int i = 0;
	int count = 0;
	for(i;arr[i];i++){
		count++;
	}
	return count;
}*/

void printSomeStar(){
	for(int i = 0; i < 10; i++)
		printf("*");
	printf("\n");
}

void calculateAdd(){
	printf("%d\n", 3+4);
}

void calculateMulti(){
	printf("%d\n", 7*4);
}

void giveSomeWords(){
	printf("Software engineering.\n");
}

void printSomeAt(){
	for(int i = 0; i< 10; i++)
		printf("@");
	printf("\n");
}

void calculateDivide(){
	printf("%d\n", 8/2);
}

void calculateSub(){
	printf("%d\n", 4-1);
}

void drawBox(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++)
		{
			printf('*');
		}
		printf("\n");
	}
}

int main(){
	char options[][20] = {{"Print some *"},{"Calculate 3 + 4"}, {"Calculate 7 * 4"}, {"Give some words"},
{"Print some @"}, {"Calculate 8 / 2"}, {"Calculate 4 - 1"}, {"Draw a box"}, {"Enter again"}};
	for(int i = 0; i < 8; i++)
	{
		printf("#%d: ", i+1);
		for(int j = 0; j < 20; j++)
			printf("%c", options[i][j]);
		printf("\n");
	}
	int option = 0;
	//showMenu(options);
	printf("Enter your option(Only numbers): ");
	while(scanf("%d", &option) != EOF){
		switch(option)
		{
			case 1: printSomeStar();
				break;
			case 2: calculateAdd();
				break;
			case 3: calculateMulti();
				break;
			case 4: giveSomeWords();
				break;
			case 5: printSomeAt();
				break;
			case 6: calculateDivide();
				break;
			case 7: calculateSub();
				break;
			case 8: drawBox();
			default: printf("Wrong input!\n");
				break;
		}
		printf("Enter again: ");
	}
	return 0;
}
