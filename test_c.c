void addMenu(){
  char Menu[4]="MENU";
  int len_name = strlen(Menu);
  printf("%d",len_name);
  printf("|");
  for(int i =0; i<max_rows-len_name;i++){
    if(i == 44){
      printf("%s",Menu);
    }
    printf("_");
  }
  printf("|\n");
}

