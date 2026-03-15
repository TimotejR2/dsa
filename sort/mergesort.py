def merge(first, sec):
    first.reverse()
    sec.reverse()

    new = []
    while first and sec:
        if first[-1] <= sec[-1]:
            new.append(first[-1])
            first.pop()
        else:
            new.append(sec[-1])
            sec.pop()

    while sec:
        i = sec.pop()
        new.append(i)

    while first:
        i = first.pop()
        new.append(i)
    return new

def mergesort(A):
  # ak je pole dost male, uz je rovno utriedene
  if len(A)==1:
    return A
  # rozdel pole A na dve rovnako velke polia B a C...
  half_index = len(A)//2
  B, C = A[half_index:], A[:half_index]
  # ...utried polia samostatne...
  B = mergesort(B)
  C = mergesort(C)

  # ...a vysledok uloz do A
  return merge(B,C)


if __name__ == '__main__':
    n = int(input())
    elements = list(map(int, input().split()))
    elements = mergesort(elements)
    print(*elements)
