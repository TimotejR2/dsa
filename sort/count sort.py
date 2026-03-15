def count(A):
    values = [0 for _ in range(100000)]
    for el in A:
        if el <= 0:
            raise Exception
        values[el-1] += 1
    return values

def zavazia(A):
    i = 1
    najviac = (0,0)
    for el in A:
        if el > najviac[1]:
            najviac = (i, el)
        i+=1
    print(*najviac)

def countsort(A):
    A = count(A)
    val = []
    i = 0
    for el in A:
        for _ in range(el):
            val.append(i+1)
        i +=1
    return val
if __name__ == '__main__':
    n = int(input())
    A = list(map(int, input().split()))

    print(*countsort(A))
