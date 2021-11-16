#include <stdio.h>
#include <string.h>
int max_rows=100;
void createHead(){
  printf("|");
  for(int i =0; i<max_rows;i++){
    printf("_");
  }
  printf("|\n");
}
void addMenu(){
  char Menu[4]="MENU";
  printf("|");
  for(int i =0; i<max_rows-strlen(Menu);i++){
    if(i == 44){
      printf("%s",Menu);
    }
    printf("_");
  }
  printf("|\n");
}

void main(){
  createHead();
  addMenu();
  createHead();
}
