#include <stdio.h>
#include <string.h>

	
	
int main(int argc, char **argv)
{
FILE *f;
FILE *fout;


int n;

int count=0;
char number[100];
//~ char res[]={};


//~ int i=0;
//~ int j=0;

f = fopen("input.txt","r");
fout = fopen("output.txt","w");
if(!f) return 1;
if(!fout) return 1;

if(!f) return 1;


while(fscanf(f,"%d",&n)==1)
{
		printf("c: %c ",n);
		number[count]=n;
		count++;
}

for(int i=0;i<count;i++)
	printf("c: %c ",number[i]);



   fclose(f);
   fclose(fout);
	return 0;
}

