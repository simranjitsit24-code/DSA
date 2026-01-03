"""
Array Data Structure
This file contains common array problems and patterns.
"""


# Common Array Problem Patterns

def two_sum(nums, target):
    """
    Find two numbers that add up to target.
    Time: O(n), Space: O(n)
    """
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []


def max_subarray_sum(nums):
    """
    Find the maximum sum of a contiguous subarray (Kadane's Algorithm).
    Time: O(n), Space: O(1)
    """
    if not nums:
        return 0
    
    max_sum = current_sum = nums[0]
    for num in nums[1:]:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)
    
    return max_sum


def binary_search(nums, target):
    """
    Binary search in a sorted array.
    Time: O(log n), Space: O(1)
    """
    left, right = 0, len(nums) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1


def sliding_window_max(nums, k):
    """
    Find maximum in each sliding window of size k.
    Time: O(n), Space: O(k)
    """
    from collections import deque
    
    if not nums or k == 0:
        return []
    
    result = []
    dq = deque()
    
    for i, num in enumerate(nums):
        # Remove elements outside the window
        while dq and dq[0] < i - k + 1:
            dq.popleft()
        
        # Remove smaller elements as they are useless
        while dq and nums[dq[-1]] < num:
            dq.pop()
        
        dq.append(i)
        
        # Add to result when window is complete
        if i >= k - 1:
            result.append(nums[dq[0]])
    
    return result


def merge_intervals(intervals):
    """
    Merge overlapping intervals.
    Time: O(n log n), Space: O(n)
    """
    if not intervals:
        return []
    
    intervals.sort(key=lambda x: x[0])
    merged = [intervals[0]]
    
    for current in intervals[1:]:
        if current[0] <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], current[1])
        else:
            merged.append(current)
    
    return merged


def rotate_array(nums, k):
    """
    Rotate array to the right by k steps.
    Time: O(n), Space: O(1)
    """
    n = len(nums)
    k = k % n
    
    # Reverse entire array
    nums.reverse()
    # Reverse first k elements
    nums[:k] = reversed(nums[:k])
    # Reverse remaining elements
    nums[k:] = reversed(nums[k:])


def find_duplicate(nums):
    """
    Find the duplicate number in an array (Floyd's Cycle Detection).
    Time: O(n), Space: O(1)
    """
    slow = fast = nums[0]
    
    # Find intersection point
    while True:
        slow = nums[slow]
        fast = nums[nums[fast]]
        if slow == fast:
            break
    
    # Find entrance to cycle
    slow = nums[0]
    while slow != fast:
        slow = nums[slow]
        fast = nums[fast]
    
    return slow


def product_except_self(nums):
    """
    Calculate product of array except self without division.
    Time: O(n), Space: O(1) excluding output
    """
    n = len(nums)
    result = [1] * n
    
    # Calculate left products
    left_product = 1
    for i in range(n):
        result[i] = left_product
        left_product *= nums[i]
    
    # Calculate right products and multiply
    right_product = 1
    for i in range(n - 1, -1, -1):
        result[i] *= right_product
        right_product *= nums[i]
    
    return result


def three_sum(nums):
    """
    Find all unique triplets that sum to zero.
    Time: O(n²), Space: O(1)
    """
    nums.sort()
    result = []
    
    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        
        left, right = i + 1, len(nums) - 1
        while left < right:
            total = nums[i] + nums[left] + nums[right]
            if total == 0:
                result.append([nums[i], nums[left], nums[right]])
                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1
                left += 1
                right -= 1
            elif total < 0:
                left += 1
            else:
                right -= 1
    
    return result


def container_with_most_water(height):
    """
    Find two lines that form a container with the most water.
    Time: O(n), Space: O(1)
    """
    left, right = 0, len(height) - 1
    max_area = 0
    
    while left < right:
        width = right - left
        max_area = max(max_area, min(height[left], height[right]) * width)
        
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    
    return max_area


if __name__ == "__main__":
    # Example usage
    print("Two Sum:", two_sum([2, 7, 11, 15], 9))
    print("Max Subarray Sum:", max_subarray_sum([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
    print("Binary Search:", binary_search([1, 2, 3, 4, 5, 6, 7], 4))
