# Title : 시간복잡도를 배운 도도 https://www.acmicpc.net/problem/24510
N = int(input())

cnt = 0
for i in range(0,N):
    s = input()
    tmp = s.count("for") + s.count("while")
    cnt = max(cnt, tmp)
print(cnt)
