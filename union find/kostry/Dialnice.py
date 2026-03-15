from logging import exception


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
        while i < len(hrany):
            koren1, koren2, hodnota = hrany[i]
            if self.same_parent(koren1, koren2):
                if hodnota < 0:
                    val += hodnota
                i += 1
                continue
            else:
                i += 1
                self.union(koren1, koren2)
                val += hodnota
                used += 1
        while i < n:
            if hrany[i][2] < 0:
                val += hrany[i][2]
            i+=1
        print(val)

def main():
    n = int(input())
    hrany = []
    for i in range(n):
        x = list(map(int, input().split()))
        for j in range(i+1, n):
            hrany.append(
                (i, j, x[j])
            )
    hrany.sort(key=lambda x: x[2])

    uf = UnionFind(n)
    uf.kostra(hrany, n)

if __name__ == '__main__':
    main()