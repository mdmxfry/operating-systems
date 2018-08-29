#include <stdio.h>
#include <string.h>
 
int main()
{
  	char Str[100];
  	int i, j, len;
 
  	printf("\n Please Enter any String :  ");
  	fgets(Str, "%d", stdin);
  	
  	j = 0;
  	len = strlen(Str);
 
  	for (i = len - 1; i >= 0; i--)
  	{
      putchar(Str[i]);
  	}
    printf("\n");
  	return 0;
}