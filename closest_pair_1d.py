#/usr/bin/python
#coding:utf8

import random
import time
random.seed(time.time())

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

'''
  找到距离最近的两个点
'''
def FindClosestPari1D(q, n):


def ClosestPair(q1, q2, n):

def Distance(x, y):
  return abs(x-y)

if __name__ == '__main__':
  print 'hello!'

  a = RandomInteger(10, 0, 200)
  print a
  plot(a, [1]*len(a), marker = '*')
  show()





