"""
Linked List Data Structure
This file contains common linked list implementations and problem patterns.
"""

class ListNode:
    """Definition for singly-linked list node."""
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class DoublyListNode:
    """Definition for doubly-linked list node."""
    def __init__(self, val=0, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next


class LinkedList:
    """Basic Singly Linked List Implementation"""
    
    def __init__(self):
        self.head = None
    
    def insert_at_beginning(self, val):
        """Insert a node at the beginning of the list."""
        new_node = ListNode(val)
        new_node.next = self.head
        self.head = new_node
    
    def insert_at_end(self, val):
        """Insert a node at the end of the list."""
        new_node = ListNode(val)
        if not self.head:
            self.head = new_node
            return
        
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
    
    def delete_node(self, val):
        """Delete the first node with the given value."""
        if not self.head:
            return
        
        if self.head.val == val:
            self.head = self.head.next
            return
        
        current = self.head
        while current.next:
            if current.next.val == val:
                current.next = current.next.next
                return
            current = current.next
    
    def reverse(self):
        """Reverse the linked list."""
        prev = None
        current = self.head
        
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        
        self.head = prev
    
    def display(self):
        """Display all elements in the list."""
        elements = []
        current = self.head
        while current:
            elements.append(str(current.val))
            current = current.next
        return " -> ".join(elements)


# Common Linked List Problem Patterns

def reverse_linked_list(head):
    """
    Reverse a singly linked list.
    Time: O(n), Space: O(1)
    """
    prev = None
    current = head
    
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    
    return prev


def find_middle(head):
    """
    Find the middle node of a linked list using slow and fast pointers.
    Time: O(n), Space: O(1)
    """
    if not head:
        return None
    
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    return slow


def has_cycle(head):
    """
    Detect if a linked list has a cycle using Floyd's algorithm.
    Time: O(n), Space: O(1)
    """
    if not head:
        return False
    
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    
    return False


def merge_two_sorted_lists(l1, l2):
    """
    Merge two sorted linked lists.
    Time: O(n + m), Space: O(1)
    """
    dummy = ListNode(0)
    current = dummy
    
    while l1 and l2:
        if l1.val <= l2.val:
            current.next = l1
            l1 = l1.next
        else:
            current.next = l2
            l2 = l2.next
        current = current.next
    
    current.next = l1 if l1 else l2
    return dummy.next


def remove_nth_from_end(head, n):
    """
    Remove the nth node from the end of the list.
    Time: O(n), Space: O(1)
    """
    dummy = ListNode(0)
    dummy.next = head
    fast = slow = dummy
    
    # Move fast n+1 steps ahead
    for _ in range(n + 1):
        if not fast:
            return head
        fast = fast.next
    
    # Move both pointers until fast reaches the end
    while fast:
        fast = fast.next
        slow = slow.next
    
    # Remove the nth node
    slow.next = slow.next.next
    return dummy.next


if __name__ == "__main__":
    # Example usage
    ll = LinkedList()
    ll.insert_at_end(1)
    ll.insert_at_end(2)
    ll.insert_at_end(3)
    ll.insert_at_end(4)
    ll.insert_at_end(5)
    
    print("Original List:", ll.display())
    
    ll.reverse()
    print("Reversed List:", ll.display())
