class UnionFind:
    def __init__(self):
        self.uf = []

    def union(self, koren1, koren2):
        p1, p2 = self.find(koren1), self.find(koren2)
        new_con = 0

        if p1 != p2:

            new_size = self.uf[p1][1] + self.uf[p2][1]
            new_con = self.uf[p1][1] * self.uf[p2][1]

            if self.uf[p1][1] >  self.uf[p2][1]:
                self.uf[p2] = (p1, 1)
                self.uf[p1] = (p1,  new_size)
            else:
                self.uf[p1] = (p2, 1)
                self.uf[p2] = (p2,  new_size)

        return new_con



    def find(self, prvok):
        while True:
            A = []
            parent = self.uf[prvok][0]
            if parent == prvok:
                for x in A:
                    self.uf[x] = parent, 1
                return prvok
            else:
                A.append(prvok)
                prvok = parent

def main():
    n = int(input())
    uf = UnionFind()

    # Convert input
    mesta = dict()
    min_num = 0
    for _ in range(n):
        m1, m2 = input().split()

        if m1 not in mesta:
            mesta[m1] = min_num
            m1 = min_num

            foo = (min_num, 1)
            uf.uf.append(foo)
            min_num +=1
        else:
            m1 = mesta[m1]
        if m2 not in mesta:
            mesta[m2] = min_num
            m2 = min_num

            foo = (min_num, 1)
            uf.uf.append(foo)
            min_num += 1
        else:
            m2 = mesta[m2]


        val = uf.union(m1, m2)
        print(val)

if __name__ == '__main__':
    main()