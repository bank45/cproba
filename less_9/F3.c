#include <stdio.h>
#include <math.h>


#define COLS 2
  void print_arr(int (*a)[COLS], int rows)
 {
	 for(size_t i=0; i<rows;i++)
	 {
		 printf("%d %d\n",a[i][0],a[i][1]);

	 }
		 printf("\n");
 }
 
 void sort_even_odd(int *rows, int (*a)[COLS])
{
	int a1=0;
	int a2=0;
	
	int b=0;

	 int i=0;
	 int coun=0;
	 while(i<((*rows)-1)&& coun <(*rows))
	 {
		a1 = a[i][0];
		a2 = a[i+1][0];
		 
		 if(a1>a2)
		 {
			 b=a[i][0];
			 a[i][0]=a[i+1][0];	
			 a[i+1][0]=b;
			// инициализация второй колонки
			a[i][1]=0;
		 }
		 i++;
		 if(i==((*rows)-1))
		 {
			 coun++;
			 i=0;
		 }
	 }
 }
 
void count(int (*arr)[COLS],int *rows, int (*res)[COLS], int *rows_res)
{
	int i=0;
	int j=0;
	int s=0;

	res[i][0]=arr[j][0];

	(*rows_res)++;

		while(i<=(*rows))
		{
			while(j<(*rows))
			{
				if(res[i][0]!=arr[j][0])
				{
					i++;
					res[i][0]=arr[j][0];
					res[i][1]++;				
				
					(*rows_res)++;				

				}else
				{
					res[i][1]++;
				}	

				j++;	
			
			}
			s=(res[i][1]);		
			j+=s;					
			i++;
		}
	
		print_arr(res, (*rows_res));
}

void number(double num, int *rows,int (*arr)[2])
{

long d=0;
int b=0;
int i=0;
int coun=0;

if(num==0)
{
	(*rows)++;	
}
while(num>0)
{
	
	d=fmod(num, 10);
	printf("d: %ld\n",d);

	arr[(*rows)][0]=d;	
	num=(num-i)/10;
	printf("num: %f\n",num);	
	(*rows)++;		
	//~ size++;
}


while(i<(*rows) && coun <(*rows))
{
		 if(arr[i][0]<arr[i+1][0])
		 {
			 b=arr[i][0];
			 arr[i][0]=arr[i+1][0];	
			 arr[i+1][0]=b;
		 } 
		 		 i++;
		 if(i==((*rows)-1))
		 {
			 coun++;
			 i=0;
		 }
} 

	//Пузырьковая сортировка
	sort_even_odd(rows,arr);

}

int main(int argc, char **argv)
{
	int rows = 0;
	int rows_res =0;
	double num = 0;
	int arr[1000][COLS];	
	int res[1000][COLS];
	
	scanf("%lf",&num);	
	// Преобразование числа в массив 
	number(num, &rows, arr);
	// Подсчет повторов
	count(arr,&rows,res,&rows_res);
	return 0;
}

