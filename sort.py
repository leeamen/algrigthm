#!/usr/bin/python
#coding:utf8

'''
插入排序，x是list
'''
def InsertSort(x):
  for i in range(1, len(x)):
    temp = x[i]
    j = i - 1
    while j >= 0:
      if x[j] > temp:
        x[j+1] = x[j]
        j-=1
      else:
        break
    x[j+1] = temp

'''
快速排序
'''
def QuickSort(x, start_idx, end_idx):
  i = start_idx
  j = end_idx

  if i >= j:
    return

  pivot = x[start_idx];

  while i < j:
    while i < j and x[j] > pivot:
      j-=1

    if i < j:
      x[i] = x[j];
      i+=1

    while i < j and x[i] < pivot:
      i+=1

    if i < j:
      x[j] = x[i];
      j-=1
  x[i] = pivot

  '''
  左边
  '''
  QuickSort(x, start_idx, i - 1);
  '''
  右边
  '''
  QuickSort(x, i + 1, end_idx)

if __name__ == '__main__':
  arr = [3,4,4,1,3,4,5,1,3,8,9,0]
  QuickSort(arr, 0, len(arr) - 1)
  print arr




