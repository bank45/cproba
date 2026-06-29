#include <stdio.h>

	
	
int main(int argc, char **argv)
{
FILE *f;
FILE *fout;
//~ char word_1[100];
//~ char word_2[100];
//~ int str[1000]={0};
char c;
//~ int k=97;
//~ int i=0;
f = fopen("input.txt","r");
fout = fopen("output.txt","w");
if(!f) return 1;
if(!fout) return 1;

if(!f) return 1;

while((c=fgetc(f))!=EOF)
{
	switch (c)
	{
		case 'a':
			c='b';
			//~ printf("%c",c);
			fprintf(fout,"%c",c);
			break;		
		case 'b':
			c='a';
			//~ printf("%c",c);
			fprintf(fout,"%c",c);
			break;	
		case 'A':
			c='B';
			//~ printf("%c",c);
			fprintf(fout,"%c",c);	
			break;	
		case 'B':
			c='A';
			//~ printf("%c",c);
			fprintf(fout,"%c",c);
			break;		
		default:
			//~ printf("%c",c);
			fprintf(fout,"%c",c);			
	}


}







   fclose(f);
   fclose(fout);
	return 0;
}

