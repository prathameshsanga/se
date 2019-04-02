#include<stdio.h>
#include<stdlib.h>

int n;

double fact(int n) 
{ 
	if (n <= 1)         
		return 1; 
    	return n*fact(n-1); 
} 
  
double nPr(int n, int r) 
{ 
    	return fact(n)/fact(n-r); 
}

void swap(int *a, int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

void printArray(int *array,int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
} 

void permute(int *array,int i,int length) 
{ 
	if (length == i)
  	{
     		printArray(array,length);
     		return;
  	}
  	int j = i;
  	for (j = i; j < n; j++) 
  	{ 
     		swap(array+i,array+j);
     		permute(array,i+1,length);
     		swap(array+i,array+j);
  	}
  	return;
}
  
int main() 
{ 
	int i, r; 
    	printf("Enter n: "); 
    	scanf("%d", &n); 
    	printf("Enter r: "); 
    	scanf("%d", &r);
    	int *a=(int *)malloc(r*sizeof(int));
    	for(i=0;i<n;i++)
    		a[i]=i+1;
    	for(i=0;i<n;i++)
		printf("%d\n",a[i]); 
  
    	printf("%dP%d is %f\n", n, r, nPr(n, r));
 
    	permute(a,0,r);
  
    	return 0;
}
