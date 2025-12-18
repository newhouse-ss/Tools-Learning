class Solution(object):
    def threeSum(self, nums):
        n = len(nums)
        nums.sort()
        result = []
        
        # nums[i] is the 1st element of triple
        for i in range(n-2):
            if nums[i] > 0:
                break
            # avoid the first repeat
            if i == 0 or nums[i] != nums[i-1]:
                left = i+1
                right = n-1
                while left<right:
                    sum = nums[i] + nums[left] + nums[right]
                    
                    if sum > 0:
                        right -= 1
                    elif sum < 0:
                        left += 1
                    else:
                        result.append(nums[i], nums[left], nums[right])
                        left += 1
                        right -= 1
                        # avoid the second repeat.
                        while left < right and nums[left] == nums[left-1]:
                            left += 1
                        # avoid the third repeat.
                        while left < right and nums[right] == nums[right+1]:
                            right -= 1
        return result