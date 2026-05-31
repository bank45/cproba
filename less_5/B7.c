#include <stdio.h>


int main(void)
{
	
	int a=1,b=0,c=0,d=0,start=0,arch=0,coun1=0,coun2=0;
	scanf("%d", &a);
	start=a; //копия для сравнения
	if (a==0){
		printf("%s ", "NO");
	}else{
		while (a>0)	{
			b=a%10;
			a=(a-b)/10;
			arch=b;
			coun1++;
			coun2=0;
				c=start;
				while (c>0){
				d=c%10;
				c=(c-d)/10;	
				coun2++;			
						if (d==arch&&coun1!=coun2) {
					printf("%s ","YES");
					return 0;
				}		
					}
	}
	printf("%s ", "NO");

	return 0;
}
}

