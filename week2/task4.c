#include <stdio.h>

void swap(int *x, int *y) {

   int temp;
   temp = *x;    /* save the value at address x */
   *x = *y;      /* put y into x */
   *y = temp;    /* put temp into y */
  
   return;
}

int main()
{	
	int num1=5, num2=2;
	swap(&num1, &num2);
	printf("%i %i\n", num1, num2);
}