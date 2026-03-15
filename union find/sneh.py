class UnionFind:
    def __init__(self, pocet_vrcholov):
        self.uf = [None for _ in range(pocet_vrcholov)]
    def union(self, koren1, koren2):
        if not self.same_parent(koren1, koren2):
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
        return self.find(m1) == self.find(m2)

def main():
    n, k = list(map(int, input().split()))
    uf = UnionFind(n)

    for i in range(k):
        operacia, m1, m2 = input().split()
        m1, m2 = int(m1), int(m2)

        if operacia == 'odhrab':
            uf.union(m1, m2)
        elif operacia == 'cesta':
            print("ANO" if uf.same_parent(m1, m2) else "NIE")




if __name__ == '__main__':
    main()

