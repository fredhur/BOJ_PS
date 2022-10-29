# Title : 箱と鍵 (Boxes and Keys) https://www.acmicpc.net/problem/24081
N,M = map(int, input().split())
Box = list(map(int, input().split()))
Key = list(map(int, input().split()))
cnt =0
for i in Box:
    if i in Key: 
        cnt+=1
print(cnt)