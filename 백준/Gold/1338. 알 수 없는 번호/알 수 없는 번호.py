A,B = map(int,input().split())
 
 
if A>B:
    A,B = B,A
 
X,Y = map(int,input().split())
 
X = abs(X)
left_div = A//X
right_div = (B+X)//X
result = []
flag = True
if Y>=abs(X) or Y<0:
    flag = False
if flag:
    for div in range(left_div,right_div+1):
        temp = div*X+Y
        if A<=temp<=B:
            if result:
                flag = False
                break
            else:
                result.append(temp)
 
 
if flag and result:
    print(*result)
else:
    print('Unknwon Number')