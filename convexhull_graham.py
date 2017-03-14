#!/usr/bin/python
#coding:utf8

import random
import time
random.seed(time.time())
import matplotlib.pyplot as plt
import math
import convexhull_bf as ch
import sort

class Stack(list):
  def __init__(self):
    self.top = -1
  def Push(self, x):
    self.append(x)
    self.top+=1
  def Pop(self):
    if self.top <= -1:
      return None
    else:
      p = self[self.top]
      self.pop()
      self.top -= 1
      return p
  def GetNext2Top(self):
    if self.top >= 1:
      return self[self.top - 1]
    else:
      return None
  def Top(self):
    if self.top >= 0:
      return self[self.top]
    else:
      return None

'''
graham格莱翰算法
'''
def GrahamScan(arr, n):
  if n <= 3:
    return arr

  '''
  获取y坐标最小的点
  '''
  origin = GetMinY(arr, n)
  print origin.x ,origin.y

  '''
  计算极角并且排序
  '''
  for i in range(0, n):
    arr[i].polar = CalcPolar(arr[i], origin)
  '''
  按照极角排序
  '''
  sort.QuickSortCallback(arr, 0, n - 1, CompareByPolar)

  '''
  用栈
  '''
  st = Stack()
  st.Push(arr[0])
  st.Push(arr[1])
  st.Push(arr[2])
  i = 3
  while i < n:
    '''
    循环
    '''
    while True:
      p3 = arr[i]
      p1 = st.GetNext2Top()
      p2 = st.Top()
      if p1 is None:
        break
      if Judge(p1, p2, p3) is False:
        st.Pop()
      else:
        break
    st.Push(p3)
    i+=1

  return st


'''
验证是否在内部
1.可以用面积
2.可以用向量的投影是否小于0，即内积是否小于0
  p1是次栈顶，p2是栈顶，p3是需要判断的点
'''
def Judge(p1, p2, p3):
  axis_x = p1.y - p2.y
  axis_y = p2.x - p1.x

  x = p3.x - p1.x
  y = p3.y - p1.y

  if x * axis_x + y * axis_y > 0:
    return True
  else:
    return False


'''
根据坐标求极角，相对于一个直角坐标系的点
'''
def CalcPolar(a, origin):
  if a is origin:
    return 0
  x = a.x - origin.x
  y = a.y - origin.y
  polar = math.atan(1.*y/x)
  if polar > 0:
    return polar
  else:
    return polar + math.pi

'''
获取y坐标最小的点
'''
def GetMinY(arr, n):
  m = None
  for i in range(0, n):
    if m is None:
      m = arr[i]
    else:
      if m.y > arr[i].y:
        m = arr[i]
  return m

'''
根据极角比较方法
'''
def CompareByPolar(a, b):
  if a.polar == b.polar:
    return 0
  elif a.polar  < b.polar:
    return -1
  else:
    return 1

if __name__ == '__main__':
  print 'start...'

  n = 100
  arr = ch.RandomGaussPoint(5, 2, n)

  st = GrahamScan(arr, n)

  '''
  plot
  '''
  plt.figure()
  plt.axis('equal')
  for i in range(0, n):
    plt.plot(arr[i].x, arr[i].y, marker = '*', color = 'blue')
  for i in range(0, len(st)):
    plt.plot(st[i].x, st[i].y, marker = 'o', color = 'red')
  plt.show()

