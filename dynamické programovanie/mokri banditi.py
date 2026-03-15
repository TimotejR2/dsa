n = int(input())
values = list(
    map(int, input().split())
)

D = [values[0], max(values[0], values[1])]

for i in range(2,n):
    D.append(max(
        values[i] + D[i-2],
        D[i-1]
    ))
print(D[-1])
