#include <stdio.h>
#include <stdlib.h>

int display(int arr[],int n){
    printf("Array = [ ");
    for(int i=0 ;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("]\n");
}

void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}

int linearSearch(int arr[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}


int binarySearch(int arr[],int low, int high,int key)
{
    if(high>=low)
    {
        int mid=(high+low)/2;
        if(arr[mid]>key)
            return binarySearch(arr,low,mid-1,key);
        if(arr[mid]<key)
            return binarySearch(arr,mid+1,high,key);
        if(arr[mid]==key)
            return mid;
    }
    else
        return -1;
}

  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        swap(&arr[min_idx], &arr[i]); 
    } 
} 


int main()
{
    int value=1;
    printf("Hello world!\n");
    int array1[]={12,13,1,56,6};
    int len = sizeof(array1)/sizeof(array1[0]);
    display(array1,len);
    //int result=binarySearch(array1,0,len,value);
    int result = linearSearch(array1,len,value);
    if(result==-1)
    printf("Not Found\n");
    else
    printf("Position: %d\n",result);
    selectionSort(array1,len);
    display(array1,len);


    return 0;
}
