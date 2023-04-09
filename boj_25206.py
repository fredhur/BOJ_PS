lut={}

lut['A+'] = 4.5
lut['A0'] = 4.0
lut['B+'] = 3.5
lut['B0'] = 3.0
lut['C+'] = 2.5
lut['C0'] = 2.0
lut['D+'] = 1.5
lut['D0'] = 1.0
lut['F'] = 0.0

ret = 0.0
score = 0.0
for i in range(0,20):
    s = input().split()
    if (s[2]=='P') : continue
    ret += float(s[1]) * lut[s[2]]
    score += float(s[1])


ret = ret / score 

print(ret)