halda = []
import math

def add(x):
    halda.append(x)
    new_index = len(halda)-1
    up(new_index)

def get_parent(index):
    new = (index-1)//2
    if new < len(halda) and new >= 0:
        return new
    return None

def get_child(index):
    if 2*index+1 < len(halda):
        return 2*index+1, None
    if 2*index+2 < len(halda):
        return 2*index+1, 2*index+2
    return None, None


def up(x):
    parent = get_parent(x)

    if parent != None:
        if halda[x] > halda[parent]:

            tmp = halda[x]
            halda[x] = halda[parent]
            halda[parent] = tmp
            up(parent)
            return

def down(x): # x = index
    x_val = halda[x]
    child = get_child(x)
    if child[0] == None:
        return
    to_swap = None

    if halda[child[0]] > x_val:
        to_swap = child[0]

    elif child[1] != None and halda[child[1]] > x_val:
        to_swap = child[1]

    if to_swap != None:
        tmp = halda[to_swap]
        halda[to_swap] = halda[x]
        halda[x] = tmp
        down(child[0])
        return

def remove():
    if not halda:
        return
    tmp = halda.pop()
    if not halda:
        return
    if len(halda):
         # Last item
        halda[0] = tmp

    down(0)

if __name__ == '__main__':

    n = int(input())
    for _ in range(n):
        operation, value = list(map(int, input().split()))
        if operation == 1:
            add(value)
        else:
            remove()
        if halda:
            print(halda[0])
            if max(halda) != halda[0]:
                raise Exception
        else:
            print('empty')

        #print(halda)
"""
5
1 5
1 6
1 1
1 3
0 5
"""
