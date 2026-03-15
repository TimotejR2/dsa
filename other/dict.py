import re


def rozdel_retazec(retazec):
    # Použijeme regulárny výraz na nájdenie písmen a číslic
    match = re.match(r"([a-zA-Z]+)(\d+)", retazec)
    if match:
        pismena = match.group(1)  # Prvá skupina (písmená)
        cisla = match.group(2)  # Druhá skupina (čísla)
        return pismena, int(cisla)
    return retazec, None


names = dict()

vstup = input()
while vstup:
    text, num = rozdel_retazec(vstup)
    if text not in names:
        print(vstup)
        if not num:
            names[text] = set()
        else:
            names[text] = set([num])

    else:
        if num is not None and num not in names[text]:
            names[text].add(num)
            print(vstup)
        else:
            num = 1
            while num in names[text]:
                num += 1
            print(text + str(num))
            names[text].add(num)
    try:
        vstup = input()
    except EOFError:
        break