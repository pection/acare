#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_number()
{
  int numbers[10];
  int i = 0;
  FILE *file;

  if (file = fopen("menu_value.txt", "r"))
  {
    while (fscanf(file, "%d", &numbers[i]) != EOF)
    {
      i++;
    }
    fclose(file);

    numbers[i] = '\n';

    for (i = 0; numbers[i] != '\n'; i++)
      printf("%d\n", numbers[i]);
  }

  return 0;
}
