# Given an array of nums, return the pair of numbers which their sum is closest and NOT EQUAL to target

# Un arreglo: [34,23,1,24,75,33,54,8]
# target: 60
# Output = [34, 24]

def closestSumToK(numbers, k):
    currSum = 0
    left = 0
    right = len(numbers) - 1
    pair = [0, 0]
    
    numbers.sort()

    while left < right :
        currSum = numbers[left] + numbers[right]

        if currSum < k:
            pair = [numbers[left], numbers[right]]
            left += 1        
        else:
            right -= 1
    
    return pair
