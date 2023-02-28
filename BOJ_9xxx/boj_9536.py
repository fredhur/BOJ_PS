tc = int(input())


for i in range(0, tc):
    sound = list(map(str, input().split()))
    
    t = []
    while True: 
       cand = list(input().rstrip().split())
       if(len(cand)>3): break
       t.append(cand[2])
    
    for c in t:
        p = []
        for i in sound:
            if( i!= c): p.append(i)
        sound = p
    print(*p)

