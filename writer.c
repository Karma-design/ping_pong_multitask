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
    int result;
    FILE *file;
    file = fopen("file.txt", "r");
    fscanf(file, "%d", &result);
    fclose(file);
    return result;
}