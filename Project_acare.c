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
int readmenu();
struct Allmenu Menu[1000];
float money_all = 0.0;
int max_strlen = strlen("Fried-fish-toppted-with-chilli-sauce ");
void Add_Menu() {
		sum_menu = readmenu(sum_value);
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
	}

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
void Create_Head()
{
  printf("*");
  for (int row_i = 0; row_i < max_rows; row_i++)
  {
    printf("_");
  }
  printf("*\n");
}
void Add_Head_Menu()
{
  char Menu[4] = "MENU";
  int len_name = strlen(Menu);
  printf("|");
  for (int row_m = 0; row_m < max_rows - len_name; row_m++)
  {
    if (row_m == (max_rows / 2) - (len_name / 2))
    {
      printf("%s", Menu);
    }
    printf("=");
  }
  printf("|\n");
}
void main() {

	Create_Head();
  Add_Head_Menu();
  Create_Head();
	// printf("Choose your choice => ");
  // scanf("%d", &condition_value);
  // printf("(1) Order food\n\n");
  // printf("(2) Billing\n\n");
  // printf("(3) Exit\n\n");
}
void Order_food() {
  int num_menu;
  Create_Head();
  Add_Head_Menu();
  Create_Head();
  Add_Promotion();
  Add_Menu();
  printf("Choose your number of menu => ");
  scanf("%d", &num_menu);
  check_number_of_priece(num_menu);
}
void check_number_of_priece(int number_menu) {
  int count_priece;
  Create_Head();
  Add_Head_Menu();
  Create_Head();
  Add_Promotion();
  printf("%s x 1 = %.2f \n", Menu[number_menu].foodname, Menu[number_menu].price);
  printf("Choose your pieces => ");
  scanf("%d", &count_priece);
  Menu[number_menu].number_of_pieces += count_priece;
	printf("%d",  Menu[number_menu].number_of_pieces );

}
void Add_Promotion() {
  char Promotion1[20] = "BUY 2 GET 10 %OFF |";
  char Promotion2[20] = "BUY 3 GET 20 %OFF |";
  char Promotion3[20] = "BUY 5 GET 30 %OFF";

  for (int i = 0; i < 10; i++) {
    printf("*");
  }
  printf("%s %s %s", Promotion1, Promotion2, Promotion3);
  for (int i = 0; i < 10; i++) {
    printf("*");
  }
  printf("\n\n\n");
}


void Create_Welcome()
{
  char Welcome[30] = "Welcome to Restaurant";
  int len_welcome = strlen(Welcome);
  printf("|");
  for (int row_k = 0; row_k < max_rows - len_welcome; row_k++)
  {
    if (row_k == (max_rows / 2) - (len_welcome / 2))
    {
      printf("%s", Welcome);
    }
    printf("_");
  }
  printf("|\n");
}
void attention() {
  printf("quit program when character q is entered");
}
void main_menu() {
  Create_Head();
  Add_Head_Menu();
  Create_Head();

  printf("(a) Order food\n\n");
  printf("(b) Billing\n\n");oid Order_food() {
  int num_menu;
  Create_Head();
  Add_Head_Menu();
  Create_Head();
  Add_Promotion();
  Add_Menu();
  printf("Choose your number of menu => ");
  scanf("%d", &num_menu);
  check_number_of_priece(num_menu);
}
void check_number_of_priece(int number_menu) {
  int count_priece;
  Create_Head();
  Add_Head_Menu();
  Create_Head();
  Add_Promotion();
  printf("%s x 1 = %.2f \n", Menu[number_menu].foodname, Menu[number_menu].price);
  printf("Choose your pieces => ");
  scanf("%d", &count_priece);
  Menu[number_menu].number_of_pieces += count_priece;
	printf("%d",  Menu[number_menu].number_of_pieces );

}
void Add_Promotion() {
  char Promotion1[20] = "BUY 2 GET 10 %OFF |";
  char Promotion2[20] = "BUY 3 GET 20 %OFF |";
  char Promotion3[20] = "BUY 5 GET 30 %OFF";

  for (int i = 0; i < 10; i++) {
    printf("*");
  }
  printf("%s %s %s", Promotion1, Promotion2, Promotion3);
  for (int i = 0; i < 10; i++) {
    printf("*");
  }
  printf("\n\n\n");
}

void Add_Menu() {
	int true_false =0;
  if (true_false==0){
		sum_menu = readmenu(sum_value);
	}
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
		true_false=1;
	}


void Create_Head()
{
  printf("*");
  for (int row_i = 0; row_i < max_rows; row_i++)
  {
    printf("_");
  }
  printf("*\n");
}
void Add_Head_Menu()
{
  char Menu[4] = "MENU";
  int len_name = strlen(Menu);
  printf("|");
  for (int row_m = 0; row_m < max_rows - len_name; row_m++)
  {
    if (row_m == (max_rows / 2) - (len_name / 2))
    {
      printf("%s", Menu);
    }
    printf("=");
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
    if (row_k == (max_rows / 2) - (len_welcome / 2))
    {
      printf("%s", Welcome);
    }
    printf("_");
  }
  printf("|\n");
}
void attention() {
  printf("quit program when character q is entered");
}
void main_menu() {
  Create_Head();
  Add_Head_Menu();
  printf("(c) Exit\n\n");

}
