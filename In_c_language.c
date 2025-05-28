#include <stdio.h>
int main()
{
    printf("Current directory:\n");
    system("pwd");
    printf("List of files:\n");
    system("ls -ltrh");
    return 0;
}