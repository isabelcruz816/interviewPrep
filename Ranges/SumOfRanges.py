def sumOfRanges(ranges, nums):
    if len(ranges) == 0 or len(nums) == 0:
        return [0]
    
    sums =[]
    currSum = 0

    for i in range(len(nums)):
        currSum += nums[i]
        nums[i] = currSum
    
    for item in ranges:
        if item[0] == 0:
            sums.append(nums[item[1]])
        else:
            sums.append(nums[item[1]] - nums[item[0] - 1])
    return sums

# Test: print(sumOfRanges([[0, 3], [3, 4]], [1, 2, 3, 4, 5]))