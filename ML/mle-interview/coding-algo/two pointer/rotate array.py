def reverse(nums, left, right):
    while left< right:
        nums[left], nums[right] = nums[right], nums[left]
        left += 1
        right -= 1

def rotate(nums, k):
    n = len(nums)
    k %= n
    reverse(nums, 0, n-1) # reverse the whole array, thus reverse the last k element to the bigining, but in reverse order.
    reverse(nums, 0, k-1) # recover the relative order of the removed k elements.
    reverse(nums, k, n-1) # recover the relative order of the n-k elements originally at the begining of array.

def main():
    test_cases = [
        ([1, 2, 3, 4, 5], 2),
        ([-35, -29, -7, 8, 6], 3),
        ([1], 5),
        ([10, 20, 30, 40, 50], 7),
        ([0, 0, 0, 0], 10),
        ([1, 2], 1),
        ([2, 4, 6, 8, 10], 0),
    ]

    for i, (nums, k) in enumerate(test_cases):
        print(i + 1, ".\tInput:", sep="")
        print("\tnums =", nums)
        print("\tk =", k)
        
        rotate(nums, k)  # perform rotation
        
        print("\n\tOutput =", nums)
        print("-" * 100)


if __name__ == '__main__':
    main()