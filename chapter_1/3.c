/*
 * //quan pai lie
 *
 * */
#include<stdio.h>
void swap(char *m,char *n);
void perm(char *list,int i,int n);
void main()
{
    char list[3]={'a','b','c'};
    perm(list,0,2);
}
void perm(char *list,int i,int n)
{
    int j;
    if(i==n)
    {
	for(j=0;j<=n;j++)
	{
	    printf("%c  ",list[j]);
	}
	printf("\n");
    }
    else
    {
	for(j=i;j<=n;j++)
	{
	    swap(&list[i],&list[j]);
	    perm(list,i+1,n);
	    swap(&list[i],&list[j]);
	}
    }
}
void swap(char *m,char *n)
{
    char t;
    t=*m;
    *m=*n;
    *n=t;
}
