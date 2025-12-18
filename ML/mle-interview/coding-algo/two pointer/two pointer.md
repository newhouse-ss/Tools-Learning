## Rotate array
1. simple but with extra space:
```python
nums[:] = nums[n-k:] + nums[0:n-k]
```
the main idea is use slicing to move the last k elements which will be out of boundry to the bigining of array; and move the first n-k elements k position later.

2. in-place approach:
learn the reverse method, it can reverse the part nums[left, right] in array:
```python
def reverse(nums, left, right):
    while left < right:
        nums[left], nums[right] = nums[right], nums[left]

        left += 1
        right -= 1
```
this method will reverse the array, the trick is: it will also move the last k elements to the corresponding rigon at the bigining!!!
```python
nums = [1, 2, 3, 4], k = 2
nums_reverse = [4, 3, 2, 1]
```
where `[3, 4]` are moved to `[4, 3]` at the begining in a reverse order, then apply reverse() on `[4, 3]` again.

So rotate():
```python
def rotate(nums, k):
    reverse(nums, 0, n-1)
    reverse(nums, 0, k-1)
    reverse(nums, k, n-1)
```

## 3Sum
The main idea of this problem is to sort the array first, then pin the smallest nums[i],then use 2-pointers to find the other 2 nums which make 3sum = 0; Only need to notice how to deal with duplicate. 
- nums[i]:
```python
if i == 0 or nums[i] != nums[i-1]:
    OK
```
- nums[left]:
after found a 3Sum:
```python
while left<right and nums[left] == nums[left-1]:
    left += 1
```
- nums[right]:
same as left.
