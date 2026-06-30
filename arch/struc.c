#include <stdio.h>
#include <string.h>

struct tag_fio 
{
	char name[50];
};

struct point 
{
	int x;
	int y;
	int z;
	struct tag_fio fio;
};	
	
	
	
int main(int argc, char **argv)
{
FILE *f;
FILE *fout;


f = fopen("input.txt","r");
fout = fopen("output.txt","wb");
if(!f) return 1;
if(!fout) return 1;

if(!f) return 1;



struct point pnt =
{
	1,	2, 3, {"Aleksandr\n"}
};

size_t written = fwrite(&pnt, sizeof(struct point),1,fout);

if(written != 1)
{
	return 1;
}


fclose(f);
fclose(fout);
return 0;
}

