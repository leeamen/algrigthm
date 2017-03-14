#!/usr/bin/python
#coding:utf8
import random
import time
random.seed(time.time())
import matplotlib.pyplot as plt
import math


class Point(object):
  def __init__(self, x, y):
    self.x = x
    self.y = y
    self.remove = False

    '''
    极角
    '''
    self.polar = None
  def isRemove(self):
    return self.remove
  def Remove(self):
    self.remove = True


def RandomGauss(mu, sigma, n):
  arr = []
  for i in range(0, n):
    arr.append(random.gauss(mu, sigma))
  return arr

def RandomGaussPoint(mu, sigma, n):
  arr = []
  arr_x = RandomGauss(mu, sigma, n)
  arr_y = RandomGauss(mu, sigma, n)
  for i in range(0, n):
    arr.append(Point(arr_x[i], arr_y[i]))
  return arr

'''
面积法求点在三角形内部
'''
def TriangleArea(a, b, c):
  ab = Point(b.x - a.x, b.y - a.y)
  ac = Point(c.x - a.x, c.y - a.y)
  return 1./2 * abs(ab.x * ac.y - ab.y * ac.x)

'''
判断d是否在abc的三角形中
'''
def PointInTriangle(a, b, c, d):
  abc = TriangleArea(a, b, c)
  abd = TriangleArea(a, b, d)
  acd = TriangleArea(a, c, d)
  bcd = TriangleArea(b, c, d)

  diff = abc - abd - acd - bcd

  if diff >= -1.*math.e * (10 ** -5) and diff <= math.e * (10 **-5):
    return True
  else:
    return False

'''
brute force
凸包算法 theta(n^4)
'''
def BruteForceCH1(arr, n):
  if n <= 3:
    return

  i = 0
  while i < n:
    if arr[i].isRemove():
      i+=1
      continue
    j = 0
    while j < n:
      if arr[j].isRemove() or j is i:
        j+=1
        continue
      k = 0
      while k < n:
        if arr[k].isRemove() or k is i or k is j:
          k+=1
          continue
        l = 0
        while l < n:
          if arr[l].isRemove() or l is i or l is j or l is k:
            l+=1
            continue
          '''
          判断第四个点是否在三角形中
          '''
          r = PointInTriangle(arr[i], arr[j], arr[k], arr[l])
          if r is True:
            arr[l].Remove()
          l+=1
        k+=1
      j+=1
    i+=1

'''
蛮力算法 theta(n^3)
'''
def BruteForceCH2(arr, n):
  '''
  找到y最小的点,肯定是凸包边界的点
  '''
  min_p = None
  for i in range(0, n):
    if min_p is None:
      min_p = arr[i]
    elif min_p.y > arr[i].y:
      min_p = arr[i]

  i = 0
  while i < n:
    if arr[i].isRemove() or arr[i] is min_p:
      i+=1
      continue
    j = 0
    while j < n:
      if arr[j].isRemove() or arr[j] is min_p or j == i:
        j+=1
        continue
      k = 0
      while k < n:
        if arr[k].isRemove() or arr[k] is min_p or k == i or k == j:
          k+=1
          continue
        '''
        开始判断arr[k]是否在内部
        '''
        r = PointInTriangle(min_p, arr[i], arr[j], arr[k])
        if r is True:
          arr[k].Remove()
        k+=1
      j+=1
    i+=1


def PlotPoints(arr, n):
  '''
  plot
  '''
  plt.figure()
  plt.axis('equal')
  for i in range(0, n):
    if arr[i].isRemove():
      plt.plot(arr[i].x, arr[i].y, marker = '*', color = 'blue')
    else:
      plt.plot(arr[i].x, arr[i].y, marker = 'o', color = 'red')
  plt.show()

if __name__ == '__main__':
  print 'start...'

  n = 20
  arr = RandomGaussPoint(5, 2, n)

  area = TriangleArea(Point(0,0), Point(0,1), Point(1,0))
  print area

  '''
  调用算法
  '''
  #BruteForceCH1(arr, n)
  BruteForceCH2(arr, n)

  PlotPoints(arr, n)




