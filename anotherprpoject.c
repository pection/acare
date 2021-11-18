#include "stdio.h"
#include "stdlib.h"
#include "string.h"
	char name[100];
	int price;
};


struct Menu{
	char foodname[50];
	int id;
	float price;
	int quantity;
}

struct Menus menu[1000];
int alc[1000];
int count_buffet = 0;
int count_alc = 0;
int total;
float cash;
float sum=0;
int tmp;
int count_checked=0;
int count_unchecked=0;
int main_menu(){
	int num;
	printf("\n\n=================================================================\n");
  printf("|                               MENU                            |\n");
	printf("=================================================================\n");
	printf("| (1). Add Buffet                                               |\n");
	printf("| (2). Add A la carte                                           |\n");
	printf("| (3). View Buffet                                              |\n");
	printf("| (4). Check bill buffet                                        |\n");
	printf("| (5). Report buffet                                            |\n");
	printf("| (9). Exit                                                     |\n");
	printf("=================================================================\n");
	printf("Choose menu => ");
	scanf("%d",&num);
	return num;
}


void read_menu(){
	char str1[1000];
	int num1;
	int i=0;
	FILE *fp = fopen("menu.txt", "r");
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

int buffet_course(){
	int buffet_price = 0;
	printf(" 1. 399 Baht\n");
	printf(" 2. 699 Baht\n");
	printf(" 3. 999 Baht\n");
	printf("Choose => ");
	scanf("%d",&buffet_price);
	while(buffet_price < 1 || buffet_price > 3){
		printf("Choose => ");
		scanf("%d",&buffet_price);
	}
	return buffet_price;
}

int get_buffet_price(int buffet_price){
	if(buffet_price == 1){
		buffet_price = 399;
	}
	if(buffet_price == 2){
		buffet_price = 699;
	}
	if(buffet_price == 3){
		buffet_price = 999;
	}
	return buffet_price;
}

void add_buffet(int price, int count_p){
	buffet[count_buffet].id = count_buffet+1;
	buffet[count_buffet].price = price;
	buffet[count_buffet].count_p = count_p;
	count_buffet++;
}

void view_buffet(){
	int i;
	for(i=0; i<count_buffet; ++i){
		printf("%d: number of people => %2d | price => %4d | Total => %d Baht %s\n",buffet[i].id,buffet[i].count_p,  buffet[i].price,  buffet[i].count_p*buffet[i].price, buffet[i].check == 1? "[ Checked ]":"");
	}
}

void add_alacarte(int menu_id){
	alc[count_alc] = menu_id;
}



int main(){
	int i,j;
	while(1){
		int count_p = 0;
		int buffet_price = 0;
		switch(main_menu()){
			case 1:
				buffet_price = get_buffet_price(buffet_course());
				printf("Input number of people for %d Baht:",buffet_price);
				scanf("%d",&count_p);

				add_buffet(buffet_price, count_p);
				break;
			case 2:
				system("cls");
				read_menu();
				int n=1;
				while(n){

					printf("Input menu id (-1 to exit): ");
					scanf("%d",&tmp);
					if(tmp == -1){
						n = 0;
					}else{
						alc[count_alc] = tmp;
						count_alc++;
					}
				}
				system("cls");
				printf("\n[  All your orders  ]\n");
				for(i=0; i<count_alc;++i){
					int id = alc[i]-1;
					printf("%d. %s %d\n",i+1,menu[id].name,menu[id].price);
					sum += menu[id].price;
				}
				sum = sum;
				printf("\nTotal : %5.2f\n",sum);
				printf("Input cash : ");
				scanf("%f",&cash);
				while(cash < sum){
					printf("Input cash : ");
					scanf("%f",&cash);
				}
				printf("Your change : %5.2f\n",cash-sum);
				break;
			case 3:
				view_buffet(buffet);
				break;
			case 4:
				printf("Input order buffet id : ");
				scanf("%d",&tmp);
				while(tmp < 1 || tmp > count_buffet){
					printf("Input order buffet id : ");
					scanf("%d",&tmp);
				}
				tmp -= 1;
				sum = buffet[tmp].count_p*buffet[tmp].price;
				printf("\nTotal : %5.2f\n",sum);
				printf("Input cash : ");
				scanf("%f",&cash);
				sum = sum;

				while(cash < sum){

					printf("Input cash : ");
					scanf("%f",&cash);
				}
				buffet[tmp].check = 1;
				printf("Your change : %5.2f\n",cash-sum);
				break;
			case 5:
				count_checked=0;
				count_unchecked=0;
				for(i=0; i<count_buffet; ++i){
					if(buffet[i].check == 1){

						count_checked++;
					}else{
						count_unchecked++;
					}
				}
				printf("Checked buffet : %d order\n",count_checked);
				for(i=0; i<count_buffet; ++i){
					if(buffet[i].check == 1){
						printf("%d: number of people => %2d | price => %4d | Total => %5d Baht %s\n",buffet[i].id,buffet[i].count_p,  buffet[i].price,  buffet[i].count_p*buffet[i].price, buffet[i].check == 1? "[ Checked ]":"");
					}
				}
				printf("Unchecked buffet : %d order\n",count_unchecked);
				for(i=0; i<count_buffet; ++i){
					if(buffet[i].check != 1){
						printf("%d: number of people => %2d | price => %4d | Total => %5d Baht %s\n",buffet[i].id,buffet[i].count_p,  buffet[i].price,  buffet[i].count_p*buffet[i].price, buffet[i].check == 1? "[ Checked ]":"");
					}
				}
				break;
			case 9:
				return 0;
		}
	}
	return 0;
}
