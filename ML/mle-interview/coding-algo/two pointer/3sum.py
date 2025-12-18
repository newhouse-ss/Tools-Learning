def three_sum(nums):
    
    n = len(nums)
    nums.sort()
    result = []
    for i in range(n-2):
        if nums[i] > 0: # since we've sorted the array, if the smallest num>0, no triple == 0
            break
# eable the first iteration since nums[0-1] is the last ele, 
# and avoid repeat since if nums[i] == nums[i-1], we don't have to regard the
# same element as begining twice.
        if i == 0 or nums[i] != nums[i-1]:
            left = i+1
            right = n-1
            while left < right:
                if nums[i] + nums[left] + nums[right] > 0:
                    right -= 1
                elif nums[i] + nums[left] + nums[right] < 0:
                    left += 1
                else:
                    result.append((nums[i], nums[left], nums[right]))
                    right-=1
                    left+=1
                    while left < right and nums[left] == nums[left - 1]:
                            left += 1
                    while left < right and nums[right] == nums[right + 1]:
                            right -= 1
    return result

print(three_sum([-1,0,1,-1,2]))