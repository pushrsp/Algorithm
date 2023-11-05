A, B, C, D, N = map(int, input().split())
E = (A+B+C+D) / 4
F = (A+B+C+D) // 4

if E >= N:
    print(0)
else:
    H = A+B+C+D
    if H%4 == 0:
        print(4*(N-F))
    else:
        print(4*N-H)