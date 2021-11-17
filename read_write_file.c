#include <stdio.h>
#include <string.h>
int main(void)
{
    FILE *open;
    open = fopen("listmenu.txt", "r");
    FILE *write;
    write = fopen("write_menu.txt", "w");
    FILE *a;

    char ch;
    char str[127];

    while ((ch = fgetc(open)) != EOF)
    {
        if (ch == 32 || ch == ',' || ch == '#')
            fprintf(write, "\n");

        else
            fprintf(write, "%c", ch);
    }

    fclose(write);
    fclose(open);
    a = fopen("write_menu.txt", "r");

    while (!feof(a))
    {
        if (fgets(str, 126, a))
            printf("%s", str);
    }
    fclose(a);
    return 0;
  }
