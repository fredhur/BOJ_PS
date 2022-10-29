# Title : 希少な数 (Rare Number) https://www.acmicpc.net/problem/24085
N = int(input())
l = list(map(int, input().split()))
D = dict()
for i in l :
    if i in D: D[i] += 1
    else : D[i] = 1;

a = sorted(D.items(), key=lambda x: (x[1], x[0]))

print(a[0][0])