"""s=3.14*r*r

r=odmocnina z pi/(100*i)

obsah/(100*1)"""

import math
while True:
    x,y = list(map(float, input().split()))
    if x == 0 and y == 0:
        break
    vzdialenost = math.sqrt(x * x + y * y)
    i = math.ceil((3.14 * vzdialenost * vzdialenost) / 100)
    print(f"The property will be flooded in hour {i}.")


