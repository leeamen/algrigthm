
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define QSORT_LIB 1

void qsort(int* arr, int start_index, int end_index)
{
    int pivot, i, j;

    j = end_index;
    i = start_index;
    pivot = arr[i];

    if(i >= j)
    {
        return ;
    }
    while(i < j)
    {
        if(i < j && arr[j] < pivot)
        {
            arr[i] = arr[j];
            i++;
        }
        else
        {
            j--;
            continue;
        }

        if(i < j && arr[i] > pivot)
        {
            arr[j] = arr[i];
            j--;
        }
        else
        {
            i++;
            continue;
        }
    }

    arr[i] = pivot;
    qsort(arr, start_index, i-1);
    qsort(arr, i+1, end_index);
}
#if QSORT_LIB < 1
int main(int argc, char **argv)
{
    int arr[] = {3,4,1,2,3,4,6,7};

    qsort(arr, 0, sizeof(arr)/sizeof(int) - 1);
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
#endif
