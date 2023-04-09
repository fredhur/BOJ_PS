teams={}
youndoo = input()
l = ['L','O','V','E']
N = int(input())
while N > 0 : 
    s = input()
    temp = {}
    for i in l: temp[i] = youndoo.count(i) + s.count(i)
    ans =1
    for i in range(0, 3):
        for j in range(i+1, 4):
            ans = ans *(temp[l[i]]+temp[l[j]]);
    teams[s] = ans % 100
    N -=1
A = list(sorted(teams.items(), key=lambda x: (-x[1], x[0])))
print(A[0][0])
