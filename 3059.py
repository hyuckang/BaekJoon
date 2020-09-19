import sys
T = int(sys.stdin.readline())
for _ in range(T):
    A, res = [False] * 26, 2015
    S = sys.stdin.readline().rstrip()
    for x in S:
        if A[ord(x) - 65] == False:
            A[ord(x) - 65] = True
            res -= ord(x)
    print(res)
