#include <stdio.h>
#include <string.h>
#include "functions_project.c"
int *ptr_value;
int numbers[14];
float float_value[14];

char menu1[35]="Deep Fried Wontons";
char menu2[35]="Deep Fried Spring Roll";
char menu3[35]="Hot and Sour Soup Szechaun Style";
char menu4[35]="Grilled chicken";
char menu5[35]="Steamed duck";
char menu6[35]="Dried shrimps";
char menu8[35]="Chicken stir-fried with ginger";
char menu7[35]="Crisp fried mussel pancakes";
char menu9[35]="Fried fish toppted ";
char menu10[35]="Salted cat fish with chili paste";
char menu11[35]="Rice";

int *read_number()
{
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


  return 0;
}
}
void main(){
  Create_Head();
  Add_Menu();
  Create_Head();
  Create_Welcome();
  read_number();
  for (int I=0; I<14; I++) {
        float_value[I] = (float)numbers[I];
  }
  for (int i =0; i<11;i++ ){
      printf("%s \n",menu+str(i));
  }

}
