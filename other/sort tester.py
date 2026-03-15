n = int(input())
nums = map(int, input().split())
prev_num = -1

rastuce = None
for num in nums:
    if (rastuce == True and num < prev_num) or (rastuce == False and num > prev_num):
        print("bordel")
        break
    elif (rastuce == None and prev_num != -1):
        if prev_num < num:
            restuce = True
        elif prev_num > num:
            rastuce = False
    prev_num = num

else:
    print("poriadok")
