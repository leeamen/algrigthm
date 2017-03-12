#include<cstdio>
#include<cstdlib>
#include<random>
#include<iostream>
using namespace std;

int MaxInt(int *arr, int start_index, int end_index)
{
    int split_index = (start_index + end_index) / 2;

    if(start_index < end_index)
    {
        int a = MaxInt(arr, start_index, split_index);
        int b = MaxInt(arr, split_index+1, end_index);
        return a > b?a:b;
    }
    else
    {
        return arr[start_index];
    }
}

int main(int argc, char **argv)
{
    int arr[] = {1,2,3,4,5,7,4,3,2,3,4,5,6,7,2,2,1,3,4,5,20};
    int len = sizeof(arr)/sizeof(int);
    int m = MaxInt(arr, 0, len - 1);
    std::cout<<"max:"<<m<<endl;

    return 0;
}
