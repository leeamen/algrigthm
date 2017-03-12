#!/usr/bin/python
#coding:utf8
import sort

def Swap(a, b):
  return b, a

'''
分治算法,数组中寻找第k小的数字
每组5个，分n/5组，每组进行排序，对n/5组的中位数中找到中位数
将数组分成<M =M >M 三部分 theta(n)
递归调用查找第k小的数字，根据不同部分的个数来选择在哪个部分进行遍历
'''
def LinearSelect(arr, start_idx, end_idx, k):
  n = end_idx - start_idx + 1
  '''
    算法时间复杂度接近o(1)
  '''
  if n < 20:
    sort.QuickSort(arr, start_idx, end_idx)
    return arr[k - 1]

  '''
  每组5个元素进行排序，排序时间复杂度相当于O(1)
  并将每组的中味数放在数组的前边，进行排序，然后选取中位数
  '''
  for i in range(0, n/5):
    sort.QuickSort(arr, i*5, i*5 + 4)
    arr[i], arr[i*5+2] = Swap(arr[i], arr[i*5+2])

  '''
  选取中位数，不需要这么写，递归的调用本方法即可
  sort.QuickSort(arr, 0, n/5)
  m = arr[2]
  '''
  m = LinearSelect(arr, 0, n/5, n/10)

  '''
  分割三部分
  '''
  small_n, equal_n = Partition(arr, m, 0, n - 1)
  if small_n > k:
    return LinearSelect(arr, 0, small_n - 1, k)
  elif small_n + equal_n < k:
    return LinearSelect(arr, small_n + equal_n, n - small_n - equal_n - 1, k - small_n - equal_n)
  else:
    return arr[k - 1];


'''
将数组分成三部分，<m =m >m，返回小于的个数和等于的个数
线性时间复杂度，并且不需要分割完毕再进行统计个数
'''
def Partition(arr, start_idx, end_idx):
  n = end_idx - start_idx
  i = start_idx
  j = end_idx

  while i < j:
    while i < j and arr[i] < m:
      i+=1

    '''
    如果arr[i]等于m，那么需要后移动，这里有点复杂，需要画一下
    '''
    if arr[i] <= m:
      k = i + 1
      while k <= j:
        if arr[k] < m:
          arr[i], arr[k] = Swap(arr[i], arr[k])
          i+=1
        elif arr[k] > m:
          arr[i], arr[k] = Swap(arr[i], arr[k])
          break;
        else:
          k += 1

    '''
    k超越j，说明已经分配完毕
    '''
    if k > j:
      return i,j-i+1

    while i < j and arr[j] > m:
      j-=1

    if i < j:
      arr[i], arr[j] = Swap(arr[i], arr[j])
      '''
      如果和m相同，那么需要后移
      '''
      if arr[i] < m:
        i+=1
      j-=1


if __name__ == '__main__':
  print('start...')
  arr = [156, 81, 127, 147, 43, 196, 46, 38, 181]
  k = len(arr)/2
  m = LinearSelect(arr, 0, len(arr) - 1, k)
  print m

  sort.QuickSort(arr, 0, len(arr) - 1)
  print arr[k -1]



