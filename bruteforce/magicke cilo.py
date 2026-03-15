n = int(input())

def opakujuce(n):
    n = list(map(int, str(n)))
    used = set()
    for i in n:
        if i in used:
            return True
        used.add(i)
    return False

while True:
    n += 1
    if not opakujuce(n):
        print(n)
        break