#include "stdio.h"
#include "stdlib.h"
#include "string.h"
	char name[100];
	int price;
};
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curses.h>
#define true 1
#define false 0

int i = 1;
int condition_value;
float all_sum = 0;
int sum_menu = 0, sum_value = 0, max_rows = 100;
struct Allmenu {
  char foodname[50];
  int id;
  float price;
  int number_of_pieces;
  ;
};
int main_menu(){
	int order_number;
	printf("\n\n--------------------------------------------------------------\n");
  printf("|                               MENU                            |\n");
	printf("--------------------------------------------------------------\n");
	printf("| (1). View Menu                                               |\n");
	printf("| (2). Edit Price                                           |\n");
	printf("| (4). Check bill Order                                       |\n");
	printf("| (5). Report buffet                                            |\n");
	printf("| (4). Exit                                                     |\n");
	printf("=================================================================\n");
	printf("Choose menu => ");
	scanf("%d",&order_number);
	return order_number;
}
struct Allmenu Menu[1000];
float money_all = 0.0;
int max_strlen = strlen("Fried-fish-toppted-with-chilli-sauce ");
int readmenu() {
  char name_food[1000];
  int value_menu;
  int i = 0;
  FILE *fp = fopen("listmenu.txt", "r");
  if (fp == NULL)
  {
    printf("File does not exist\n");
    exit(1);
  }
  while ( fscanf(fp, "%s %d", name_food, &value_menu) != EOF )
  {
    i++;
    strcpy(Menu[i].foodname, name_food);
    Menu[i].price = value_menu;
    sum_menu++;

  }
  fclose(fp);
  return sum_menu;
}
void main
