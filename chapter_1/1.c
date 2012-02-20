/*选择排序算法
 *
 * */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_N_SIZE 100
void sort(int list[],int n);
void swap(int *m,int *n);
void main()
{
    int i,n,rd[5]={0,1,2,3,4};
    int list[MAX_N_SIZE];
    printf("please input the num n:");
    scanf("%d",&n);
    if(n<1 || n>MAX_N_SIZE)
    {
	fprintf(stderr,"Improper value of n\n");
	exit(1);
    }
    for(i=0;i<n;i++)
    {
	list[i]=rand()%1000;
    }	
    sort(list,n);
    for(i=0;i<n;i++)
    {
	printf("%d-",list[i]);
    }
    
}
void sort(int list[],int n)
{
    int i=0,j=0;
    for(i=0;i<n-1;i++)
    {
	for(j=i+1;j<n-1;j++)
	{
	    if(list[j]<list[i])
	    {
		swap(&list[j],&list[i]);
	    }
	}
    }
}
void swap(int *m,int *n)
{
    int t;
    t=*m;
    *m=*n;
    *n=t;
}
