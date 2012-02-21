/*二分法查找    递归和非递归	
 *
     * */
#include<stdio.h>
void main()
{
    int list[10]={1,3,5,8,11,14,18,22,34,38};
    int tmp;
    //tmp = bin_search(list,11,0,9);
    tmp = recur_bin_search(list,18,0,9);
    printf("middle is %d\n",tmp); 
}
// not recursive algorithm
int bin_search(int list[],int search_num,int left,int right)
{
    int middle;
    while(left<=right)
    {
	middle=(left+right)/2;
	if(list[middle]==search_num)
	{
	    return middle;
	}
	else if(search_num>list[middle])
	{
	    left=middle+1;
	}
	else
	{
	    right=middle-1;
	}
    }
    return -1;
}

int recur_bin_search(int list[],int search_num,int left,int right)
{
    int middle;
    middle=(left+right)/2;
    if(list[middle]==search_num)
    {
	return middle;
    }
    else if(list[middle]>search_num)
    {
	recur_bin_search(list,search_num,left,middle-1);
    }
    else
    {
	recur_bin_search(list,search_num,middle+1,right);
    }
}
