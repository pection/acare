#include <stdio.h>
int main()
{
	char name[30];
	printf("Enter name: ");
	scanf("%[^\n]",name);

	printf("Name is: %s\n",name);
	return 0;
}
