def is_palindrome(s):
  
    s = s.lower()
    temp = []

    for ele in s:
        if 'a'<=ele<='z':
            temp.append(ele)

    s_cleaned = ''.join(temp)
    left = 0
    right = len(s_cleaned) - 1

    while left <= right:
        if s_cleaned[left] != s_cleaned[right]:
            return False
        
        left += 1
        right -= 1

    return True