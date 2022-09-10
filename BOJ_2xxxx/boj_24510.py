N = int(input())

cnt = 0
for i in range(0,N):
    s = input()
    tmp = s.count("for") + s.count("while")
    cnt = max(cnt, tmp)
print(cnt)
