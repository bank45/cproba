#include <stdio.h>

	
	
int main(int argc, char **argv)
{
FILE *f;
FILE *fout;

char str[1000]={0};

char c;
char end;
int count=0;

int i=0;

f = fopen("input.txt","r");
fout = fopen("output.txt","w");
if(!f) return 1;
if(!fout) return 1;

if(!f) return 1;

fseek(f,0,SEEK_END);
long last = ftell(f);
last = last - 1;
if(last>0)
{
count = last;
printf("%ld\n",last);	
}
fseek(f,0,SEEK_SET);
while(i < count)
{

	c=fgetc(f);
	str[i]=c;
	i++;
}

//~ printf("%s\n",str);
i=0;

while(i<(count/2))
{
	end = str[last-(i+1)];
	if(str[i]!=end)
	{
		fprintf(fout,"%s","NO");
		//~ printf("%s\n","NO");
		return 0;
	}
	i++;
}
		fprintf(fout,"%s","YES");
		//~ printf("%s\n","YES");

   fclose(f);
   fclose(fout);
	return 0;
}

