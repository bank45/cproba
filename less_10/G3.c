#include <stdio.h>

	
	
int main(int argc, char **argv)
{
FILE *f;
FILE *fout;
//~ char end;
int c;
int i=0;
f = fopen("input.txt","r");
fout = fopen("output.txt","w");
if(!f) return 1;
if(!fout) return 1;

fseek(f,0,SEEK_END);
long last = ftell(f);

long last_end = last -1;
int end_char = EOF;

while(last_end >=0)
{
	fseek(f, last_end, SEEK_SET);
	int ch = fgetc(f);

	        if (ch != '\n' && ch != '\r' && ch != EOF) {
            end_char = ch;
            break; // Нашли последнюю букву
        }
	last_end--;
}




if(end_char != EOF)
{
	//~ end=fgetc(f);
	fseek(f,0,SEEK_SET);

	while(i < last_end && (c=fgetc(f))!=(EOF))
	{
	
		if(c==end_char)
		{
			fprintf(fout,"%d ", i);
		}
		i++;	
	}
}
   fclose(f);
   fclose(fout);
	return 0;
}

