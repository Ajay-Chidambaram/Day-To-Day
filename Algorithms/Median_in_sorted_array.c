/***************************************************************************************************
                    Merge Sort Algorithm
                    
        Approach :
          1) Using Recursion go untill single element
          2) Then sort that single element array
          3) Two pointer like varaiable used to check the range in the sort function
          4) Finally replace the original array with new one. 
          
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int start, int mid, int end, int a[])
{
    int arr[end-start+1];
    int x=start,z=mid+1,k=0;
    for(int i=start;i<=end;i++)
    {
        if(z > end)
        {
            arr[k++] = a[x++];
        }
        else if(x > mid)
        {
            arr[k++] = a[z++];
        }
        else if(a[x] >= a[z])
        {
            arr[k++] = a[z++];
        }    
        else {
            arr[k++] = a[x++];
        }
    }

    for(int i=0;i<k;i++)
    {
        a[start++] = arr[i];
    }
}

void merge_sort(int start, int end, int a[])
{
    if(start < end)
    {
        int mid = (start + end)/2;
        merge_sort(start, mid, a);
        merge_sort(mid+1, end, a);
        merge(start, mid, end, a);
    }
}

int findMedian(int arr_count, int* arr) {

    int start = 0, end = arr_count-1;
    merge_sort(start,end,arr);
    return arr[(arr_count)/2];
}

int main()
{
    int n;
    scanf("%d",&n);

    int a[n];

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("%d",findMedian(n,a));
}
