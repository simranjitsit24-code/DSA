"""
Stack Data Structure
This file contains stack implementations and common stack-based problems.
"""


class Stack:
    """Basic Stack Implementation using List"""
    
    def __init__(self):
        self.items = []
    
    def push(self, item):
        """Add an item to the top of the stack."""
        self.items.append(item)
    
    def pop(self):
        """Remove and return the top item from the stack."""
        if not self.is_empty():
            return self.items.pop()
        raise IndexError("pop from empty stack")
    
    def peek(self):
        """Return the top item without removing it."""
        if not self.is_empty():
            return self.items[-1]
        raise IndexError("peek from empty stack")
    
    def is_empty(self):
        """Check if the stack is empty."""
        return len(self.items) == 0
    
    def size(self):
        """Return the number of items in the stack."""
        return len(self.items)
    
    def __str__(self):
        return str(self.items)


class MinStack:
    """Stack that supports push, pop, top, and retrieving minimum in O(1)."""
    
    def __init__(self):
        self.stack = []
        self.min_stack = []
    
    def push(self, val):
        self.stack.append(val)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)
    
    def pop(self):
        if self.stack:
            val = self.stack.pop()
            if val == self.min_stack[-1]:
                self.min_stack.pop()
            return val
    
    def top(self):
        if self.stack:
            return self.stack[-1]
    
    def get_min(self):
        if self.min_stack:
            return self.min_stack[-1]


# Common Stack Problem Patterns

def is_valid_parentheses(s):
    """
    Check if parentheses are balanced.
    Time: O(n), Space: O(n)
    """
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    
    for char in s:
        if char in mapping:
            top = stack.pop() if stack else '#'
            if mapping[char] != top:
                return False
        else:
            stack.append(char)
    
    return not stack


def evaluate_reverse_polish(tokens):
    """
    Evaluate Reverse Polish Notation.
    Time: O(n), Space: O(n)
    """
    stack = []
    operators = {'+', '-', '*', '/'}
    
    for token in tokens:
        if token in operators:
            b = stack.pop()
            a = stack.pop()
            if token == '+':
                stack.append(a + b)
            elif token == '-':
                stack.append(a - b)
            elif token == '*':
                stack.append(a * b)
            else:
                stack.append(int(a / b))
        else:
            stack.append(int(token))
    
    return stack[0]


def daily_temperatures(temperatures):
    """
    Find how many days until warmer temperature (Monotonic Stack).
    Time: O(n), Space: O(n)
    """
    n = len(temperatures)
    result = [0] * n
    stack = []
    
    for i in range(n):
        while stack and temperatures[i] > temperatures[stack[-1]]:
            prev_index = stack.pop()
            result[prev_index] = i - prev_index
        stack.append(i)
    
    return result


def largest_rectangle_histogram(heights):
    """
    Find the largest rectangle in a histogram.
    Time: O(n), Space: O(n)
    Note: Works with a copy to avoid modifying the input array.
    """
    stack = []
    max_area = 0
    heights = heights + [0]  # Create a copy with sentinel value
    
    for i, h in enumerate(heights):
        while stack and heights[stack[-1]] > h:
            height_index = stack.pop()
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, heights[height_index] * width)
        stack.append(i)
    
    return max_area


def simplify_path(path):
    """
    Simplify Unix-style file path.
    Time: O(n), Space: O(n)
    """
    stack = []
    components = path.split('/')
    
    for component in components:
        if component == '..' and stack:
            stack.pop()
        elif component and component != '.' and component != '..':
            stack.append(component)
    
    return '/' + '/'.join(stack)


def next_greater_element(nums):
    """
    Find next greater element for each element.
    Time: O(n), Space: O(n)
    """
    result = [-1] * len(nums)
    stack = []
    
    for i in range(len(nums)):
        while stack and nums[i] > nums[stack[-1]]:
            index = stack.pop()
            result[index] = nums[i]
        stack.append(i)
    
    return result


def decode_string(s):
    """
    Decode encoded string like "3[a2[c]]" -> "accaccacc".
    Time: O(n), Space: O(n)
    """
    stack = []
    current_num = 0
    current_string = ""
    
    for char in s:
        if char.isdigit():
            current_num = current_num * 10 + int(char)
        elif char == '[':
            stack.append((current_string, current_num))
            current_string = ""
            current_num = 0
        elif char == ']':
            prev_string, num = stack.pop()
            current_string = prev_string + current_string * num
        else:
            current_string += char
    
    return current_string


def trap_rain_water(height):
    """
    Calculate how much rain water can be trapped.
    Time: O(n), Space: O(n)
    """
    if not height:
        return 0
    
    n = len(height)
    left_max = [0] * n
    right_max = [0] * n
    
    left_max[0] = height[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], height[i])
    
    right_max[n - 1] = height[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], height[i])
    
    water = 0
    for i in range(n):
        water += min(left_max[i], right_max[i]) - height[i]
    
    return water


if __name__ == "__main__":
    # Example usage
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    print("Stack:", stack)
    print("Pop:", stack.pop())
    print("Peek:", stack.peek())
    
    print("\nValid Parentheses:", is_valid_parentheses("()[]{}"))
    print("Daily Temperatures:", daily_temperatures([73, 74, 75, 71, 69, 72, 76, 73]))
