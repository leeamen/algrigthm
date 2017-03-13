#!/usr/bin/python
#coding:utf8

import random
import time
random.seed(time.time())
import linear_select as ls
import sort as sort
from matplotlib.pyplot import *

'''
  随机生成整数list
'''
def RandomInteger(n, range_low, range_high):
  a = []
  while n > 0:
    i = random.randint(range_low, range_high)
    if i not in a:
      a.append(i)
    n-=1
  return a

def ClosestPairOf3Number(a, b, c):
  dist1 = Distance(a, b)
  dist2 = Distance(a, c)
  dist3 = Distance(b, c)
  if dist1 >= dist2:
    if dist2 >= dist3:
      return b,c
    else:
      return a,c
  else:
    if dist1 <= dist3:
      return a,b
    else:
      return b,c

'''
a1:(x1, x2)
'''
def CloseestPairOfTuple(a1, a2, a3):
  dist1 = Distance(a1[0], a1[1])
  dist2 = Distance(a2[0], a2[1])
  dist3 = Distance(a3[0], a3[1])

  if dist1 <= dist2:
    if dist1 <= dist3:
      return a1[0], a1[1]
    else:
      return a3[0], a3[1]
  else:
    if dist2 <= dist3:
      return a2[0], a2[1]
    else:
      return a3[0], a3[1]


'''
  找到距离最近的两个点,集合x:list
'''
def FindClosestPari1D(x):
  n = len(x)

  if n == 3:
    return ClosestPairOf3Number(x[0], x[1], x[2])
  elif n == 2:
    return x[0], x[1]
  elif n == 1:
    print 'fuck here!'
    exit()

  m = ls.LinearSelect(x, 0, n-1, n/2)
  x1 = []
  a3 = None
  b3 = None
  x2 = []
  for e in x:
    if e <= m:
      x1.append(e)
      if a3 is None:
        a3 = e
      elif a3 < e:
        a3 = e
    else:
      x2.append(e)
      if b3 is None:
        b3 = e
      elif b3 > e:
        b3 = e

  a1, b1 = FindClosestPari1D(x1)
  a2, b2 = FindClosestPari1D(x2)
  return CloseestPairOfTuple((a1, b1), (a2, b2), (a3, b3))


def Distance(x, y):
  return abs(x-y)

if __name__ == '__main__':
  print 'start...'

  arr = RandomInteger(10, 0, 200)
  print arr
  a1, a2 = FindClosestPari1D(arr)
  print a1, a2

  arr.remove(a1)
  arr.remove(a2)
  plot(arr, [1]*len(arr), marker = '*', color = 'red')
  plot([a1, a2], [1]*2, marker = 'o', color = 'blue')
  show()



