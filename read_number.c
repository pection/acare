#include <stdio.h>

int main(void)
{
  int numbers[500];
  int i = 0;
  FILE *file;

  if (file = fopen("menu_value.txt", "r"))
  {
    while (fscanf(file, "%d", &numbers[i]) != EOF)
    {
      i++;
    }
    fclose(file);

    numbers[i] = '\0';

    for (i = 0; numbers[i] != '\0'; i++)
      printf("%d\n", numbers[i]);
  }
  printf("%.2f",value);
  return 0;
}
