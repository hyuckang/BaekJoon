T = int(input())
for _ in range(T):
    A, B = map(str, input().split(' '))
    str_len = len(A)
    print('Distances:', end=' ')
    for i in range(str_len):
        a, b = ord(A[i]), ord(B[i])
        if(a <= b):
            print(b-a, end=' ')
        else:
            print(b-a+26, end=' ')
    print('')
