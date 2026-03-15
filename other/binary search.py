n = int(input())
A = pole = list(map(int, input().split()))
q = int(input())
for i in range(q):
  x = int(input())

  z, k = 0, q+2
  while k-z > 1:
    s = int((z+k)/2)
    if A[s] <= x:
      z = s
    else:
      k = s

  if A[z] == x:
    print(z)
  else:
    print(-1)