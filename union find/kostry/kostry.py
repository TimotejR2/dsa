class UnionFind:
    def __init__(self, pocet_vrcholov):
        self.uf = [None for i in range(pocet_vrcholov)]
    def union(self, koren1, koren2):

        p1, p2 = self.find(koren1), self.find(koren2)
        self.uf[p1] = p2


    def find(self, prvok):
        A = []
        # Pokial prvok nieje vrcholom
        while self.uf[prvok] != None:
            A.append(prvok)
            # Prvok = jeho rodic
            prvok = self.uf[prvok]

        # Pre kazde prehladane dieta zvolit vrchol ako jeho parenrt
        for x in A:
            self.uf[x] = prvok
        return prvok


    def same_parent(self, m1, m2):
        return (self.find(m1) == self.find(m2)) and self.find(m1) != None

    def kostra(self, hrany, n):
        val = 0
        used = 0

        i = 0
        while used < n - 1:
            koren1, koren2, hodnota = hrany[i]
            if self.same_parent(koren1, koren2):
                i += 1
                continue
            else:
                i += 1
                self.union(koren1, koren2)
                val += hodnota
                used += 1
        print(val, end='')

def main():
    n, k = list(map(int, input().split()))
    uf = UnionFind(n)
    hrany = []
    for i in range(k):
        x = list(map(int, input().split()))
        x[0] -=1
        x[1] -= 1
        hrany.append(x)

    hrany.sort(key=lambda x: x[2])

    uf2 = UnionFind(n)
    uf.kostra(hrany, n)
    print(' ',end='')
    hrany.reverse()
    uf2.kostra(hrany, n)
    print()

if __name__ == '__main__':
    main()