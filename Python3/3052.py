A = [int(input()) for _ in range(10)]
res = set([])
for i in A:
    res.add(i % 42)
print(len(res))
