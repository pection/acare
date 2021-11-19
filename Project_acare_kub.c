#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curses.h>
#define true 1
#define false 0
int first = 1;
int i = 1;
int condition_value;
float all_sum = 0;
int sum_menu = 0, sum_value = 0, max_rows = 100;
char food_find[100];

struct Allmenu {
  char foodname[50];
  int id;
  float price;
  int number_of_pieces;
  ;
};
struct Allmenu Menu[1000];

int main_menu() {
  int order_number;
  printf("*_____________________________________________________________________________________________________*\n");
  printf("|================================================MENU=================================================|\n");
  printf("*_____________________________________________________________________________________________________*\n");
  printf("| (1). View Menu                                                                                      |\n");
  printf("| (2). Edit Price                                                                                     |\n");
  printf("| (3). Check bill Order                                                                               |\n");
  printf("| (4). Find Menu                                                                                      |\n");
  printf("| (5). Exit                                                                                           |\n");
  printf("=======================================================================================================\n");
  printf("Choose menu => ");
  scanf("%d", &order_number);
  return order_number;
}
float money_all = 0.0;
int max_strlen = strlen("Fried-fish-toppted-with-chilli-sauce ");
int readmenu() {
  char name_food[1000];
  int value_menu;
  int sum_menu = 0;
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
  return Menu, sum_menu;
}


// return sum_menu;
int main() {
  Menu, sum_menu = readmenu();
  int i, j;
  float ratio, sum = 0.0;
  int piece = 0;
  while (1) {
    switch (main_menu()) {
      case 1:
        printf("========================================================================================================\n");
        printf("|                                              FOOD MENU                                               |\n");
        printf("========================================================================================================\n");

        for (i = 1; i <= sum_menu; i++) {
          printf("%d %s ", i, Menu[i].foodname);
          for (int row = 0; row < abs(strlen(Menu[i].foodname) - max_strlen); row++) {
            printf(" ");
          }
          if (i < 10) {
            printf(" ");
          }
          printf("|  %.1f", Menu[i].price);
          if (Menu[i].price > 99) {
            printf(" BATH\n");
          }
          else {
            printf("  BATH\n");

          }
        }
        int order_number_value, value;
        printf("Choose menu => ");
        scanf("%d", &order_number_value);
        char Promotion1[30] = ">>>BUY 2 GET 10 %OFF |";
        char Promotion2[20] = "BUY 3 GET 20 %OFF |";
        char Promotion3[30] = "BUY 5 GET 30 %OFF<<<\n";
        printf("%s %s %s", Promotion1, Promotion2, Promotion3);
        printf("How many %s => ", Menu[order_number_value].foodname);
        scanf("%d", &value);
        Menu[order_number_value].number_of_pieces = value;
        piece += value;
        sum = sum + (Menu[order_number_value].number_of_pieces * Menu[order_number_value].price);
        system("cls");
        break;
      case 2:

        printf("========================================================================================================\n");
        printf("|                                              FOOD MENU                                               |\n");
        printf("========================================================================================================\n");

        for (i = 1; i <= sum_menu; i++) {
          printf("%d %s ", i, Menu[i].foodname);
          for (int row = 0; row < abs(strlen(Menu[i].foodname) - max_strlen); row++) {
            printf(" ");
          }
          if (i < 10) {
            printf(" ");
          }
          printf("|  %.1f", Menu[i].price);
          if (Menu[i].price > 99) {
            printf(" BATH\n");
          }
          else {
            printf("  BATH\n");

          }
        }
        int edit;
        printf("Number of food Edit price =>  BATH   " );
        scanf("%d", &edit);
        float edit_price;
        printf("How much in float =>   ");
        scanf("%f", &edit_price);
        printf("%s change %.2f BATH to %.2f BATH", Menu[edit].foodname, Menu[edit].price, edit_price);
        Menu[edit].price = edit_price;
        printf("Success");
        system("cls");
        break;
      case 3:
        if (piece == 2) {
          ratio = 0.1;
        }
        else if (piece == 3) {
          ratio = 0.2;
        }
        else if (piece >= 5) {
          ratio = 0.3;
        }
        float money;
        printf("INPUT MONEY ==> in float");
        scanf("%f", &money);
        printf("SubTotal = %.2f BATH\n", sum);
        printf("Discount = %.2f BATH\n", (sum * ratio));
        printf("Total = %.2f BATH\n", sum - (sum * ratio));
        printf("Sum of Total = %.2f BATH\n", money - (sum - (sum * ratio)));
        break;
      case 4:
        printf("Scan your food  => ");
        scanf("%s",food_find);
        // int c= compare(str1,str2); // calling compare() function
        // if(c==0)
        // printf("strings are same");
        // else
        // printf("strings are not same");
        // printf("%s ",food_find);
        for (int i =0 ;i<max_rows;i++){
          if (strcmp(food_find,Menu[i].foodname)){
            printf("%s is in List menu",food_find);
            break;
          }

        }
        case 5:
          return 0;
        }
    }

  }
