#include <stdio.h>

	
	
int main(int argc, char **argv)
{
FILE *f;
FILE *fout;
char c;
int d=0;
int coun=0;
f = fopen("input.txt","r");
fout = fopen("output.txt","w");
while(coun<3)
{
	d=0;
	while((c=fgetc(f))!=EOF)
	{
			if(c!='\n')
			{
			fprintf(fout,"%c",c);
			d++;
			}
	}
		if(coun==2)
		{
			fprintf(fout," %d", d);	
		}else
		{
			fprintf(fout,", ");	
		}	
	fseek(f,0,SEEK_SET);
	coun++;
}

fclose(f);
fclose(fout);

	return 0;
}

