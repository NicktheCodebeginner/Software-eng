#include <stdio.h>
#include <stdlib.h>
#include "header.h"

extern void switchFunc();
extern void showMenu();

int main(){
	showMenu();
	switchFunc();
	return 0;
}
