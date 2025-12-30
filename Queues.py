"""
Queue Data Structure
This file contains queue implementations and common queue-based problems.
"""

from collections import deque


class Queue:
    """Basic Queue Implementation using List"""
    
    def __init__(self):
        self.items = []
    
    def enqueue(self, item):
        """Add an item to the rear of the queue."""
        self.items.append(item)
    
    def dequeue(self):
        """Remove and return the front item from the queue."""
        if not self.is_empty():
            return self.items.pop(0)
        raise IndexError("dequeue from empty queue")
    
    def front(self):
        """Return the front item without removing it."""
        if not self.is_empty():
            return self.items[0]
        raise IndexError("front from empty queue")
    
    def is_empty(self):
        """Check if the queue is empty."""
        return len(self.items) == 0
    
    def size(self):
        """Return the number of items in the queue."""
        return len(self.items)
    
    def __str__(self):
        return str(self.items)


class CircularQueue:
    """Circular Queue Implementation with fixed size"""
    
    def __init__(self, k):
        self.queue = [None] * k
        self.max_size = k
        self.front = 0
        self.rear = -1
        self.size = 0
    
    def enqueue(self, value):
        """Insert an element into the circular queue."""
        if self.is_full():
            return False
        self.rear = (self.rear + 1) % self.max_size
        self.queue[self.rear] = value
        self.size += 1
        return True
    
    def dequeue(self):
        """Delete an element from the circular queue."""
        if self.is_empty():
            return False
        self.front = (self.front + 1) % self.max_size
        self.size -= 1
        return True
    
    def get_front(self):
        """Get the front item from the queue."""
        if self.is_empty():
            return -1
        return self.queue[self.front]
    
    def get_rear(self):
        """Get the last item from the queue."""
        if self.is_empty():
            return -1
        return self.queue[self.rear]
    
    def is_empty(self):
        return self.size == 0
    
    def is_full(self):
        return self.size == self.max_size


class Deque:
    """Double-ended Queue Implementation"""
    
    def __init__(self):
        self.items = deque()
    
    def add_front(self, item):
        """Add item to the front."""
        self.items.appendleft(item)
    
    def add_rear(self, item):
        """Add item to the rear."""
        self.items.append(item)
    
    def remove_front(self):
        """Remove item from the front."""
        if not self.is_empty():
            return self.items.popleft()
        raise IndexError("remove from empty deque")
    
    def remove_rear(self):
        """Remove item from the rear."""
        if not self.is_empty():
            return self.items.pop()
        raise IndexError("remove from empty deque")
    
    def is_empty(self):
        return len(self.items) == 0
    
    def size(self):
        return len(self.items)


# Common Queue Problem Patterns

def sliding_window_maximum(nums, k):
    """
    Find maximum in each sliding window using deque.
    Time: O(n), Space: O(k)
    """
    if not nums or k == 0:
        return []
    
    dq = deque()
    result = []
    
    for i, num in enumerate(nums):
        # Remove elements outside window
        while dq and dq[0] < i - k + 1:
            dq.popleft()
        
        # Remove smaller elements
        while dq and nums[dq[-1]] < num:
            dq.pop()
        
        dq.append(i)
        
        if i >= k - 1:
            result.append(nums[dq[0]])
    
    return result


def first_unique_character(s):
    """
    Find the first non-repeating character in a string.
    Time: O(n), Space: O(1)
    """
    from collections import Counter
    
    count = Counter(s)
    
    for i, char in enumerate(s):
        if count[char] == 1:
            return i
    
    return -1


def generate_binary_numbers(n):
    """
    Generate binary numbers from 1 to n using queue.
    Time: O(n), Space: O(n)
    """
    result = []
    queue = deque(['1'])
    
    for _ in range(n):
        binary = queue.popleft()
        result.append(binary)
        queue.append(binary + '0')
        queue.append(binary + '1')
    
    return result


def perfect_squares(n):
    """
    Find least number of perfect squares that sum to n (BFS).
    Time: O(n * sqrt(n)), Space: O(n)
    """
    if n <= 0:
        return 0
    
    squares = []
    i = 1
    while i * i <= n:
        squares.append(i * i)
        i += 1
    
    queue = deque([(0, 0)])
    visited = {0}
    
    while queue:
        num, steps = queue.popleft()
        
        for square in squares:
            next_num = num + square
            if next_num == n:
                return steps + 1
            if next_num < n and next_num not in visited:
                visited.add(next_num)
                queue.append((next_num, steps + 1))
    
    return 0


def walls_and_gates(rooms):
    """
    Fill each empty room with distance to nearest gate (Multi-source BFS).
    Time: O(m * n), Space: O(m * n)
    """
    if not rooms:
        return
    
    m, n = len(rooms), len(rooms[0])
    queue = deque()
    
    # Add all gates to queue
    for i in range(m):
        for j in range(n):
            if rooms[i][j] == 0:
                queue.append((i, j))
    
    # BFS from all gates
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
    while queue:
        row, col = queue.popleft()
        
        for dr, dc in directions:
            new_row, new_col = row + dr, col + dc
            
            if (0 <= new_row < m and 0 <= new_col < n and 
                rooms[new_row][new_col] == 2147483647):
                rooms[new_row][new_col] = rooms[row][col] + 1
                queue.append((new_row, new_col))


def number_of_islands(grid):
    """
    Count number of islands using BFS.
    Time: O(m * n), Space: O(min(m, n))
    """
    if not grid:
        return 0
    
    m, n = len(grid), len(grid[0])
    count = 0
    
    def bfs(i, j):
        queue = deque([(i, j)])
        grid[i][j] = '0'
        
        while queue:
            row, col = queue.popleft()
            directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
            
            for dr, dc in directions:
                new_row, new_col = row + dr, col + dc
                if (0 <= new_row < m and 0 <= new_col < n and 
                    grid[new_row][new_col] == '1'):
                    grid[new_row][new_col] = '0'
                    queue.append((new_row, new_col))
    
    for i in range(m):
        for j in range(n):
            if grid[i][j] == '1':
                bfs(i, j)
                count += 1
    
    return count


def open_lock(deadends, target):
    """
    Minimum turns to open a combination lock (BFS).
    Time: O(10^4), Space: O(10^4)
    """
    dead = set(deadends)
    if "0000" in dead:
        return -1
    
    queue = deque([("0000", 0)])
    visited = {"0000"}
    
    def neighbors(code):
        result = []
        for i in range(4):
            digit = int(code[i])
            for d in [-1, 1]:
                new_digit = (digit + d) % 10
                result.append(code[:i] + str(new_digit) + code[i+1:])
        return result
    
    while queue:
        code, turns = queue.popleft()
        
        if code == target:
            return turns
        
        for neighbor in neighbors(code):
            if neighbor not in visited and neighbor not in dead:
                visited.add(neighbor)
                queue.append((neighbor, turns + 1))
    
    return -1


if __name__ == "__main__":
    # Example usage
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    print("Queue:", q)
    print("Dequeue:", q.dequeue())
    print("Front:", q.front())
    
    print("\nBinary Numbers:", generate_binary_numbers(5))
    print("First Unique Character:", first_unique_character("leetcode"))
