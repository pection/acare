#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int max_rows = 100;
void Create_Head()
{
  printf("*");
  for (int row_i = 0; row_i < max_rows; row_i++)
  {
    printf("_");
  }
  printf("*\n");
}
void Add_Menu()
{
  char Menu[4] = "MENU";
  int len_name = strlen(Menu);
  printf("|");
  for (int row_m = 0; row_m < max_rows - len_name; row_m++)
  {
    if (row_m == (max_rows/2) - (len_name / 2))
    {
      printf("%s", Menu);
    }
    printf("_");
  }
  printf("|\n");
}
void Create_Welcome()
{
  char Welcome[30] = "Welcome to Restaurant";
  int len_welcome = strlen(Welcome);
  printf("|");
  for (int row_k = 0; row_k < max_rows - len_welcome; row_k++)
  {
    if (row_k == (max_rows/2) - (len_welcome / 2))
    {
      printf("%s", Welcome);
    }
    printf("_");
  }
  printf("|\n");
}

int *read_number()
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

    for (int i = 0; numbers[i] != '\n'; i++)
      printf("%d\n", numbers[i]);
  }
  return 0;
}
