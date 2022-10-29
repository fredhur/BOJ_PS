# Title : 수 이어 쓰기 3 https://www.acmicpc.net/problem/2154


N = int(input())

s = ""
for i in range(0,N+1):
    s += str(i)

print(s.index(str(N)))