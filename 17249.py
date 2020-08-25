A = str(input())
face = A.index('(^0^)')
print(A[:face].count('@'), end=' ')
print(A[face:].count('@'))
