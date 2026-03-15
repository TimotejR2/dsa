import re

def rozdel_retazec(retazec):
    i = 0
    for letter in retazec:
        i += 1
        if letter.isdigit():
            i = i-1
            break
    if i == len(retazec):
        return retazec, None
    else:
        return retazec[:i], int(retazec[i:])


def getnum(min_num, used):
    new_num = min_num + 1
    while True:
        if not new_num in used:
            if new_num == 0:
                print(text)
            else:
                print(text + str(new_num))
            return new_num
        else:
            #used.remove(new_num)

            new_num += 1

users = dict()
while True:
    # Input handle
    try:
        vstup = input()
    except EOFError:
        break
    text, num = rozdel_retazec(vstup)

    # If new username
    if text not in users:
        print(vstup)
        if num:
            users[text] = [-1, set([num])] # -1 => este nepouzite prazdne meno
        else:
           users[text] = [0, set()]  # => 0 => prazdne meno pouzite

    # If username used with any number
    else:

        if not num:
            if users[text][0] == -1: # ak si nezvolil cislo a este neexistuje prazdne
                print(vstup)
                users[text][0] = 0
            else:
                # Get smallest possible num
                users[text][0] = getnum(users[text][0], users[text][1])

        else:
            # If possible to assign new username with num
            if num not in users[text][1] and num > users[text][0]:
                print(vstup)
                users[text][1].add(num)
            else:
                users[text][0] = getnum(users[text][0], users[text][1])



