#include <stdio.h>
#include <string.h>
 
int main()
{	
	// Reading 
	char str[100];
	int heigh, width, stars_count;
	fgets(str, "%d", stdin);
	sscanf(str, "%i", &heigh);
	

	width = 2*heigh-1;

	// output
	for (int i=0; i<heigh; i++){
		stars_count = 1 + 2 * i;
		for (int j=0; j<width; j++){
			if (j < ((width-stars_count)/2)){
				printf(" ");
			}
			else{
				if (j > ((width-stars_count)/2)+stars_count-1){
					printf(" ");
				}
				else {
					printf("*");
				}
			}
		}
		printf("\n");
	}
}