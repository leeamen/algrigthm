

#include<iostream>
#define INSERT_SORT_LIB 1

#define LENGTH(a) (sizeof(a)/sizeof(int))

void InsertSort(int arr[], int n)
{
  int i,j,temp;
  for(i = 1; i < n; i++)
  {
    temp = arr[i];
    for(j = i - 1; j >= 0 && arr[j] > temp; arr[j+1]=arr[j--]);
    arr[j+1] = temp;
  }
}

#if INSERT_SORT_LIB < 1
int main(int argc, char **argv)
{
  int arr[] = {3,4,5,6,62,2,3,1,4,45,2,11};
  InsertSort(arr, LENGTH(arr));
  for(int i = 0; i < LENGTH(arr); i++)
  {
    std::cout<<arr[i]<<std::endl;
  }
  return 0;
}
#endif
