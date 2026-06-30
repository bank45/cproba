#include <stdio.h>

	
	
int main(int argc, char **argv)
{
FILE *f;
FILE *fout;

//~ char str[1000]={0};

char c;
//~ char end;
int count=0;
int small=0;
int capital=0;

int i=0;

f = fopen("input.txt","r");
fout = fopen("output.txt","w");
if(!f) return 1;
if(!fout) return 1;

if(!f) return 1;

fseek(f,0,SEEK_END);
long last = ftell(f);
last = last;
if(last>0)
{
count = last;
}
fseek(f,0,SEEK_SET);
while(i < count)
{

	c=fgetc(f);
	if(c>96&&c<123&&c)
	{
		small++;

	}
	if(c>64&&c<91&&c)
	{
		capital++;		
	}

	i++;
}
		fprintf(fout,"%d %d\n",small,capital);



   fclose(f);
   fclose(fout);
	return 0;
}
