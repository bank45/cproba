#include <stdio.h>

	
	
int main(int argc, char **argv)
{
FILE *f;
FILE *fout;
//~ char c[100];
int d=0;
int i=0;
int digit = 50;
int letter = 65;
f = fopen("input.txt","r");
fout = fopen("output.txt","w");
if(!f) return 1;


if(fscanf(f,"%d",&d)==1)
{

	while(i<d)
	{
		if(i % 2 == 0)
		{
			fprintf(fout,"%c",(char)(letter));
			letter++;				
		}else
		{
			fprintf(fout,"%c",(char)(digit));
			digit++;				
			digit++;
			if(digit==58)
			{
				digit=50;
			}				
		}

		
		i++;
	}
}

	return 0;
}

