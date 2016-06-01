from math import *
precision=3
def calcDis(x1,y1,x2,y2):
    dis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)
    dis=round(sqrt(dis),precision)
    return dis
def calcCircle(n,block):
    circle=[]
    while n>0:
        maxr=0
        for i in range(-10**precision,10**precision):
            for j in range(-10**precision,10**precision):
                x=i/10**precision
                y=j/10**precision
                r=min(abs(-1-x),abs(1-x),abs(-1-y),abs(1-y))
                for c in circle:
                    if x==-0.83 and y==-0.83:
                        a=0
                    r=min(r,calcDis(x,y,c[1],c[2])-c[0])
                for d in block:
                    r=min(r,calcDis(x,y,d[0],d[1]))
                if r>maxr:
                    maxr=r
                    xm=x
                    ym=y
        circle.append([round(maxr,precision),xm,ym])
        n-=1
return circle
Unit Test implemented by ÓÚ±±´¨
from Algorithm import calcCircle
from Algorithm import precision
from random import randint
def genD(n):
    dlist=[]
    for i in range(d):
        x=randint(-10**precision,10**precision)
        y=randint(-10**precision,10**precision)
        dlist.append([x/10**precision,y/10**precision])
    return dlist
n=int(input("please input circle number:"))
d=int(input("please input block number:"))
dlist=genD(d)
for d in dlist:
    print(d[0],d[1])
clist=calcCircle(n,dlist)
sum=0
for c in clist:
    sum+=c[0]*c[0]
sum=round(sum,precision)
print("the maximum coverage is:",sum)
