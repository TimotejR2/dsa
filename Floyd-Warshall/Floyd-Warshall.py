class FloydWarshall:
    def __init__(self, arr, n):
        self.D = arr
        self.n = n
        self.N = [
            [i for i in range(n)] for _ in range(n)
        ]

    def count(self):
        for k in range(self.n):
            for x in range(self.n):
                for y in range(self.n):
                    if self.D[x][k] + self.D[k][y] < self.D[x][y]:
                        self.D[x][y] = self.D[x][k] + self.D[k][y]
                        self.N[x][y] = self.N[x][k]
    def print_res(self):
        for row in self.D:
            print(*row)

def main():
    n = int(input())

    arr = []
    for _ in range(n):
        arr.append(
            list(map(int, input().split()))
        )
    fw = FloydWarshall(arr, n)
    fw.count()
    fw.print_res()


if __name__ == '__main__':
    main()