def rozdel(A, pivot):
    less = []
    same = []
    more = []
    for num in A:
        if num < pivot:
            less.append(num)
        elif num == pivot:
            same.append(num)
        else:
            more.append(num)
    return less, same, more



def quicksort(A):
  # ak je pole dost male, uz je rovno utriedene
  if len(A)<=1:
    return A

  pivot = A[0]
  mensie, rovne, vacsie = rozdel(A, pivot)

  mensie = quicksort(mensie)
  vacsie = quicksort(vacsie)

  return mensie+rovne+vacsie

if __name__ == '__main__':
    input()
    nums = list(map(int, input().split()))
    print(*quicksort(nums))