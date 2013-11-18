#include "writer.h"
#include <stdio.h>

void a_write(int content)
{
    FILE *file;
    file = fopen("file.txt", "w+");
    fprintf(file, "%i", content);
    fclose(file);
}

int a_read()
{
    char* read = calloc(sizeof(char), 10);
    FILE *file;
    file = fopen("file.txt", "r");
    fscanf(file, "%s", read);
    fclose(file);
    return atoi(read);
}