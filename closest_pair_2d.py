#!/usr/bin/python
#coding:utf8
import linear_select as ls
import sort
import random
import time
random.seed(time.time())
import matplotlib.pyplot as plt
import math

def Compare_x(a, b):
  if a.x == b.x:
    return 0
  elif a.x > b.x:
    return 1
  else:
    return -1
def Compare_y(a, b):
  if a.y == b.y:
    return 0
  elif a.y > b.y:
    return 1
  else:
    return -1

def RandomGauss(mu, sigma, n):
  arr = []
  for i in range(0, n):
    arr.append(random.gauss(mu, sigma))
  return arr


'''
a, b:Point.平面上两个点之间的距离
'''
def Distance(a, b):
  s = (a.x - b.x) ** 2 + (a.y - b.y) ** 2
  return math.sqrt(s)


class Point(object):
  def __init__(self, x, y):
    self.x = x
    self.y = y

def PreprocessPoint(s):
  s1 = []
  s2 = []

  '''
  s1按照x排序
  s2按照y排序
  '''
  for e in s:
    s2.append(e)
    s1.append(e)

  sort.QuickSortCallback(s1, 0, len(s1) - 1, Compare_x)
  sort.QuickSortCallback(s2, 0, len(s2) - 1, Compare_y)
  return s1, s2

'''
返回最近的点对，3个点中
'''
def ClosestPointOf3Points(p1, p2, p3):
  d1 = Distance(p1, p2)
  d2 = Distance(p2, p3)
  d3 = Distance(p1, p3)

  if d1 <= d2:
    if d1 <= d3:
      return p1, p2,d1
    else:
      return p1, p3,d3
  else:
    if d2 <= d3:
      return p2,p3,d2
    else:
      return p1,p3,d3

def FindClosestPoint(s):
  s1, s2 = PreprocessPoint(s)
  return ClosestPoint(s1, s2, len(s1))


def ClosestPoint(s1, s2, n):
  '''
  只有三个点，那么返回最近的三个点
  '''
  if n == 3:
    return ClosestPointOf3Points(s1[0], s1[1], s1[2])
  elif n == 2:
    return s1[0], s1[1],Distance(s1[0], s1[1])
  elif n == 1:
    print 'fuck here!'
    exit()

  '''
  划分点集
  '''
  k = n/2
  s1_left = []
  s1_right = []
  s2_left = []
  s2_right = []
  for i in range(0, k):
    s1_left.append(s1[i])
  for i in range(k, n):
    s1_right.append(s1[i])
  for e in s2:
    if e in s1_left:
      s2_left.append(e)
    elif e in s1_right:
      s2_right.append(e)
    else:
      print 'fuck fuck!'
      exit()
  '''
  递归求解
  '''
  p1,p2,d1 = ClosestPoint(s1_left, s2_left, len(s1_left))
  q1,q2,d2 = ClosestPoint(s1_right, s2_right, len(s1_right))

  '''
  较小的
  '''
  if d1 < d2:
    d = d1
    p = p1
    q = p2
  else:
    d = d2
    p = q1
    q = q2
  '''
  中间值
  '''
  m = s1[k-1].x
  print 'm is:', m

  '''
  左边k-1个点找右边的点，是否小于d
  '''
  i = 0
  while i < k:
    if s2_left[i].x < m - d:
      i+=1
      continue

    j = 0
    while j < n-k:
      if s2_right[j].y > s2_left[i].y + d:
        break
      elif s2_right[j].y < s2_left[i].y - d:
        j+=1
        continue
      else:
        if s2_right[j].x <= m + d:
          d_new = Distance(s2_left[i], s2_right[j])
          if d_new < d:
            d = d_new
            p = s2_left[i]
            q = s2_right[j]
        j+=1
    i+=1
  return p,q,d


if __name__ == '__main__':
  print 'start...'

  n = 30
  x = RandomGauss(5, 2, n)
  y = RandomGauss(5, 2, n)


  '''
  点集合s
  '''
  s = []
  for i in range(0, n):
    s.append(Point(x[i], y[i]))
    print '(%f, %f)'%(x[i], y[i])

  p,q,d = FindClosestPoint(s)
  print 'closest pair:(%f, %f),(%f, %f)'%(p.x, p.y, q.x, q.y)
  print 'distance:', d

  '''
  画点
  '''
  plt.figure()
  plt.axis('equal')
  for i in range(0, n):
    plt.plot(x[i], y[i], marker = '*', color = 'red')
  plt.plot(p.x, p.y, marker = 'o', color = 'blue')
  plt.plot(q.x, q.y, marker = 'o', color = 'blue')
  plt.show()




