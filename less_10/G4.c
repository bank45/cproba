#include <stdio.h>

	
	
int main(int argc, char **argv)
{
FILE *f;
FILE *fout;
char word_1[100];
char word_2[100];
int alp[122]={0};
int c;
int k=97;
//~ int i=0;
f = fopen("input.txt","r");
fout = fopen("output.txt","w");
if(!f) return 1;
if(!fout) return 1;


int pars = fscanf(f, "%100s %100s", word_1, word_2);

if(pars == 2)
{
//~ printf("word_1: %s\n", word_1);
//~ printf("word_2: %s\n", word_2);

for(int i = 0; word_1[i]!='\0';i++)
{
	//~ printf("%c\n",word_1[i]);
	for(int j = 0; word_2[j]!='\0';j++)
	{
			if(word_1[i] == word_2[j])
			{
				c = (int) word_2[j];
				alp[c]++;
				//~ printf("%d\n",alp[c]);		
				//~ printf("%c\n",(char) c);		
			}
	}
	
}

while(k<=122)
{
	c = alp[k];
	if(c==1)
	{
	//~ printf("%d\n",c);	
	fprintf(fout,"%c ", (char)k);		
	//~ printf("%c\n",(char)k);			
	}
	
	k++;
}
}








   fclose(f);
   fclose(fout);
	return 0;
}

