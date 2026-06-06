#include <stdio.h>


 void recurs(char str[100], int i)
 {

	 if(str[i] != '.')
	 {
					
			
			
		recurs(str,i+1);
		printf("%c",str[i]);

	}
		 
 }
	
	
int main()
{
	int i=0;
	char str[100];
	fgets(str,sizeof(str),stdin);
	recurs(str,i);

	return 0;
}


