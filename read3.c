#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    FILE* filePointer;
    int bufferLength = 255;
    char buffer[bufferLength];
    char MENU[1000];
    filePointer = fopen("listmenu.txt", "r");
    count = 0;
    while(fgets(buffer, bufferLength, filePointer)) {
        MENU[100]+=buffer;
        printf("%s\n", buffer);
    }
    printf("%s",MENU);

    fclose(filePointer);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
