N, X = map(int, input().split())
L = [i for i in list(map(int, input().split())) if i < X]
for i in L:
    print(i, end=' ')