#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "finding first and last occurrence of a character is amazing";
	char alpha[] = "abcdefghijklmnopqrstuvwxyz";



	for (int i = 0; i < strlen(alpha); i++)
	{
		char *position_ptr = strchr(str, alpha[i]);
		char *r_position_ptr = strrchr(str, alpha[i]);

		int position = (position_ptr == NULL ? -1 : position_ptr - str);
		int r_position = (r_position_ptr == NULL ? -1 : r_position_ptr - str);

		printf("%4c: %4d %4d\n", alpha[i], position, r_position);
	}

	return 0;
}
