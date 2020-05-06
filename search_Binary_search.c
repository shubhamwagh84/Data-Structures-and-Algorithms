#include<stdio.h>
void binsearch(int[],int,int);
void main()
{
    int arr[]={11,22,33,44,55,66,77,88,99};
    int arrlen=9,findElement=44;
    binsearch(arr,arrlen,findElement);
}

void binsearch(int arr[],int maxlen,int item)
{
    int minlen=0,mean;
    maxlen=maxlen-1; 
    while(minlen<=maxlen)
    {
        mean=(minlen+maxlen)/2;
        if(arr[mean]==item)
        {
            printf("Element Present\n");
            return;
        }
        else if(item>arr[mean])
            minlen=mean+1;
        else
            maxlen=mean-1;
    }
    printf("Element Not Present\n");
}