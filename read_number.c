#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sum_menu =0;
struct Allmenu{
	char foodname[50];
	int id;
	float price;
	int quantity;
};
// } Menu_1,Menu_2,Menu_3,Menu_4,Menu_5,Menu_6,Menu_7,Menu_8,Menu_9,Menu_10,Menu_11,m[15];
struct Allmenu Menu[1000];
int readmenu(){
  char name_food[1000];
  int value_menu;
  int i=0;
  FILE *fp = fopen("listmenu0.txt", "r");
  if(fp == NULL)
    {
        printf("File does not exist\n");
        exit(1);
    }
    while( fscanf(fp, "%s %d", name_food,&value_menu) != EOF )
    {
    		sum_menu++;
        strcpy(Menu[i].foodname,name_food);
				Menu[i].price=value_menu;
      	i++;
				sum_menu++;

    }
		return sum_menu;
}
void main(){

  sum_menu=readmenu();
  printf("%d %s %.2f ฿\n\n",1,Menu[0].foodname,Menu[0].price);
  printf("%d %s %.2f ฿\n\n",2,Menu[1].foodname,Menu[1].price);

}
