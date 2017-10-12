#include <stdio.h>
#include "header.h"

void showMenu(){
    char options[][20] = {{"Print some star"},{"Calculate 3 + 4"}, {"Calculate 7 * 4"}, {"Give some words"},
{"Print some @"}, {"Calculate 8 / 2"}, {"Calculate 4 - 1"}, {"Draw a box"}, {"Q to quit"}, {"For help enter h"}};
	for(int i = 0; i < 10; i++)
	{
		printf("#%d: ", i+1);
		for(int j = 0; j < 20; j++)
			printf("%c", options[i][j]);
		printf("\n");
	}
}

void printSomeStar(){
	for(int i = 0; i < 5; i++)
		printf("* ");
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
		printf("*********\n");
	}
}

void help(){
	printf("Enter your options and see the result.\n");
}

void switchFunc(){
	int option = 0;
	printf("Enter your option(Only numbers): ");
	while(scanf("%c", &option) != EOF){
		switch(option)
		{
			case '1': printSomeStar();
				break;
			case '2': calculateAdd();
				break;
			case '3': calculateMulti();
				break;
			case '4': giveSomeWords();
				break;
			case '5': printSomeAt();
				break;
			case '6': calculateDivide();
				break;
			case '7': calculateSub();
				break;
			case '8': drawBox();
				break;
			case 'h': help();
				break;
			case 'q': return 0;
			default: printf("Enter again: ");
		}
	}
}
