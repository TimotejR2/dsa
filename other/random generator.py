import random

# Nastavenie počtu čísel
n = 5000

# Generovanie náhodných čísel
numbers = [random.randint(-10**9, 10**9) for _ in range(n)]

# Uloženie do textového súboru
with open('vystup.txt', 'w') as file:
    file.write(f"{n}\n")
    for i in range(n):
        if i % 9 != 0:
            file.write(f"1 {numbers[i]}\n")
        if i % 9 == 0:
            file.write(f"0 {numbers[i]}\n")
