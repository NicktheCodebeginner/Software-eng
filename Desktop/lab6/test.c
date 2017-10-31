#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.h"

int Quit(int argc, char *argv[])
{
    exit(0);
}
int main(int argc, char *argv[])
{
    MenuConfig("version", "program v1.0(Menu program v2.0.0 inside)", NULL);
    MenuConfig("quit", "quit from program", Quit);
    ExecuteMenu();
    return 0;
}
