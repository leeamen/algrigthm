#!/usr/bin/python
#coding:utf8
import sort

def Swap(a, b):
  return b, a


'''
分治算法
数组中寻找第k小的数字
线性时间找到中位数 theta(n)
将数组分成<M =M >M 三部分 theta(n)
递归调用查找第k小的数字，根据不同部分的个数来选择在哪个部分进行遍历
'''
def LinearSelect(arr, start_idx, end_idx, k)
  n = end_idx - start_idx + 1



if __name__ == '__main__':
  print('start...')
