#include<cstdio>
#include<cstdlib>
#include<random>
#include<iostream>
#include<algorithm>

//分治算法 divide and conquer,
//排序

void Combine(int *arr, int start_index1, int end_index1, int start_index2, int end_index2);

int MergeSort(int *arr, int start_index, int end_index)
{
    int split_index = (end_index + start_index) / 2;

    if(start_index < split_index)
    {
        MergeSort(arr, start_index, split_index);
        MergeSort(arr, split_index + 1, end_index);
    }

    Combine(arr, start_index, split_index, split_index + 1, end_index);
}

void Combine(int *arr, int start_index1, int end_index1, int start_index2, int end_index2)
{
    int arr_index = 0;
    int arr_tmp_len = end_index2 - start_index1 + 1;
    int arr_tmp[arr_tmp_len] = {0};

    int i = start_index1, j = start_index2;


    while(i <= end_index1 && j <= end_index2)
    {
        if(j > end_index2 || i > end_index1)
        {
            break;
        }

        if(arr[i] > arr[j])
        {
            arr_tmp[arr_index] = arr[j];
            j++;
        }
        else
        {
            arr_tmp[arr_index] = arr[i];
            i++;
        }
        arr_index++;
    }

    for(;i <= end_index1;i++, arr_index++)
    {
        arr_tmp[arr_index] = arr[i];
    }
    for(;j <= end_index2;j++, arr_index++)
    {
        arr_tmp[arr_index] = arr[j];
    }

    //复制
    for(i = 0; i < arr_tmp_len; i++)
    {
        arr[start_index1] = arr_tmp[i];
        start_index1++;
    }
}

void Swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

using namespace std;

int main(int argc, char **argv)
{
    int arr[] = {3,4,5,6,7,2,3,3,1,1,3,2,8,9,0,2,3,1,10,33};
    MergeSort(arr, 0, sizeof(arr)/sizeof(int));

    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        std::cout<<i<<":"<<arr[i]<<endl;
    }

    return 0;
}

