#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int compare(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}	
	
int main(int argc, char **argv)
{
FILE *f;
FILE *fout;


int c;
int number = 0;

int num=0;
int count=0;
int arr[1000]={0};
//~ char res[]={};


//~ int i=0;
//~ int j=0;

f = fopen("input.txt","r");
fout = fopen("output.txt","w");
if(!f) return 1;
if(!fout) return 1;

if(!f) return 1;


while((c=fgetc(f))!=EOF)
{
	if(isdigit(c))
	{
		//~ fputc(c, fout);
		number = number * 10 + (c - '0');
		//~ printf("c: %c \n",c);

		//~ fputc(c, fout);
		num=1;
	}else
	{
		if(num)
		{
		//~ fputc(' ', fout);
		arr[count] = number;
		//~ printf("number: %d \n",number);		
		count++;
		
		num=0;
		number=0;
		}
	}
		//~ printf("c: %c ",n);
		//~ number[count]=n;
		//~ count++;
}

//~ size_t n = sizeof(arr) / sizeof(arr[0]);
qsort(arr, count, sizeof(int), compare);

for(int i=0;i<count;i++)
{
	//~ printf("%d ",arr[i]);
	fprintf(fout, "%d ", arr[i]);

}
   fclose(f);
   fclose(fout);
	return 0;
}

