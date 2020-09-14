import sys
S = sys.stdin.readline().rstrip()
A = [S[i:] for i in range(len(S))]
A.sort()
for i in A:
    print(i)
