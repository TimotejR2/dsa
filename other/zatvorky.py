vstup = input()

obla = 0
hranata = 0
divna = 0

for char in vstup:
    if char == '(':
        obla +=1
    if char == ')':
        obla -=1
    if char == '[':
        hranata +=1
    if char == ']':
        hranata -=1
    if char == '{':
        divna +=1
    if char == '}':
        divna -=1
if obla or hranata or divna:
    print('Nie')
else:
    print('Ano')