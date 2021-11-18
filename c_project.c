#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "functions_project.c"

typedef struct node
{
	float data;
	char foodname[50];
	int quantity;
	float price;
  struct node *next;

}node;

struct Menu{
	int ;
	int price;
	int count_p;
	int check;
};

void read_menu(){
	char str1[1000];
	int num1;
	int i=0;
	FILE *fp = fopen("listmenu.txt", "r");
	if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    int count_menu = 0;
    while( fscanf(fp, "%s %d", str1, &num1) != EOF )
    {
        ++count_menu;
        strcpy(menu[i].name,str1);
        menu[i].price = num1;
        ++i;
    }
    printf("====================================================\n");
    printf("|                    FOOD MENU                     |\n");
    printf("====================================================\n");
    printf("| %2s | %-30s | %-10s |\n","#","MENU","price");
    printf("====================================================\n");
    for(i=0; i<count_menu; ++i){
    printf("| %2d | %-30s | %-10d |\n",i+1, menu[i].name , menu[i].price);
	}
	printf("====================================================\n");
	fclose(fp);
}