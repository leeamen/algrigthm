
#include<random>
#include<iostream>
#include<vector>

#define LINEAR_SELECT_LIB 1

#define LENGTH(a) (sizeof(a)/sizeof(int))

extern void InsertSort(int arr[], int n);

void Partition(int arr[], int n, int m, int &, int &);


std::vector<int> RandomInteger(int n, int bound_low, int bound_high)
{
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(bound_low, bound_high);
  std::vector<int>arr;
  for(int i = 0; i < n; i++)
  {
    int number = distribution(generator);
    arr.push_back(number);
  }
  return arr;
}

void Swap(int &a, int &b)
{
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
/*
寻找第k个小的元素
*/
int LinearSelect(int arr[], int n, int k)
{
  int i;
  /*
  开销：theta(1)
  */
  if(n < 20)
  {
    InsertSort(arr, n);
    return arr[k-1];
  }

  /* 选取Median
  每组5个，使用插入排序
  开销：theta(n):每个排序最多比较10次，n/5个排序，开销是theta(n)级别
  */
  for(i = 0; i < n/5; i++)
  {
    InsertSort(arr + i * 5, 5);
    /*
    小技巧，将每组的中位数交换到最前面
    */
    Swap(arr[i], arr[i * 5 + 2]);
  }
  /*
  选取中位数
  */
  int m = LinearSelect(arr, n/5, n/10);
  /*
  将arr分成三部分，小于m，等于m，大于m
  */
  int small_n, equal_n;
  Partition(arr, n, m, small_n, equal_n);
  if(small_n > k)
  {
    return LinearSelect(arr, small_n, k);
  }
  else if(small_n + equal_n >= k)
  {
    return arr[k-1];
  }
  else
  {
    return LinearSelect(arr + small_n + equal_n, n - small_n - equal_n, k - equal_n - small_n);
  }
}

/*
一次遍历
*/
void Partition(int arr[], int n, int m, int &small_n, int &equal_n)
{
  int i, j;

  for(i = 0,j = n - 1; i < j;)
  {
    while(arr[i] < m && i < j)
    {
      i++;
    }

    while(arr[j] > m && i < j)
    {
      j--;
    }

    if(arr[i] == m)
    {
      int k;
      for(k = i+1; k <= j; k++)
      {
        if(arr[k] < arr[i])
        {
          Swap(arr[k], arr[i]);
          i++;
        }
        else if(arr[k] > arr[i])
        {
          Swap(arr[k], arr[i]);
          break;
        }
      }

      if(k > j)
      {
        small_n = i;
        equal_n = j-i+1;
        return;
        //std::cout<<"small:"<<i<<",equal:"<<j-i+1<<std::endl;
      }
    }

    if(i < j)
    {
      Swap(arr[i], arr[j]);
      if(arr[i] < m)
      {
        i++;
      }
      j--;
    }
  }

  /*
  计算small & equal
  */
  /*
  small_n = 0;
  equal_n = 0;
  for(i = 0; i < n; i++)
  {
    if(arr[i] < m)
    {
      small_n++;
    }

    else if(arr[i] == m)
    {
      equal_n++;
    }
    else
    {
      break;
    }
  }
  */
}

#if LINEAR_SELECT_LIB < 1
int main(int argc, char **argv)
{
  int arr[] = {0,1,2,3,4,5,6,7,8,8,9,10};

  int k = 9;
  int o = LinearSelect(arr, LENGTH(arr), k);
  std::cout<<"LinearSelect Kth is:"<<o<<std::endl;


  InsertSort(arr, LENGTH(arr));
  std::cout<<"real Kth is:"<<arr[k-1]<<std::endl;
  return 0;

  int small_n, equal_n;
  Partition(arr, LENGTH(arr), 0, small_n, equal_n);
  std::cout<<"small & equal:"<<small_n<<","<<equal_n<<std::endl;
  for(int i = 0; i < LENGTH(arr); i++)
  {
    std::cout<<arr[i]<<std::endl;
  }

  return 0;
}
#endif
