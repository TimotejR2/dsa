n = int(input())
nums = list(map(int, input().split()))

def minsoort_first(nums, first_index):
    min_num = 999999999999

    i = 0
    for num in nums[first_index:]:
        if num < min_num:
            min_num = num
            min_index = i+first_index
        i += 1

    tmp = nums[first_index]
    nums[first_index] = nums[min_index]
    nums[min_index] = tmp


for i in range(n-1):
    minsoort_first(nums, i)
print(*nums)