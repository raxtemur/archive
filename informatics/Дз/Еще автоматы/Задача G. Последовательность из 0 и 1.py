t = 1
j = 0 
N = int(input())
for i in range(1, N):
    buf = t
    t = t + j
    j = buf
print(t*2 + j)