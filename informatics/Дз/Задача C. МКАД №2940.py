a = 109
v = int(input())
t = int(input())
if v<0:v=a+v
s=v*t
c=s-a*(s//a)
if v>0:print(c)
