N = int(input())
s = input()
arr=[]
for i in range(0, len(s), N):
    arr.append(list(s[i:i+N]))

for i in range(len(arr)):
    if i % 2 != 0:
        data = list(reversed(arr[i]))
        arr[i] = data

for j in range(N):
    for i in range(len(arr)):
        print(arr[i][j],end="")
