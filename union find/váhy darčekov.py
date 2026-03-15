class UnionFind:
    def __init__(self, pocet_vrcholov):
        self.uf = [None for _ in range(pocet_vrcholov)]


    def union(self, koren1, koren2, rozdiel):






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
    d, n = tuple(map(int, input().split()))
    uf = UnionFind(d)
    for _ in range(n):
        vstup = input().split()

        if vstup[0] == '!':
            uf.union(
                list(map(int, vstup[1:]))
            )
        elif vstup[0] == '?':
            pass




if __name__ == '__main__':
    main()

