"""
Binary Tree Data Structure
This file contains binary tree implementations and common tree-based problems.
"""

from collections import deque


class TreeNode:
    """Definition for a binary tree node."""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinaryTree:
    """Basic Binary Tree Implementation"""
    
    def __init__(self):
        self.root = None
    
    def insert(self, val):
        """Insert a node in level-order."""
        new_node = TreeNode(val)
        
        if not self.root:
            self.root = new_node
            return
        
        queue = deque([self.root])
        while queue:
            node = queue.popleft()
            
            if not node.left:
                node.left = new_node
                return
            else:
                queue.append(node.left)
            
            if not node.right:
                node.right = new_node
                return
            else:
                queue.append(node.right)
    
    def inorder_traversal(self, node):
        """Inorder traversal: Left -> Root -> Right"""
        if not node:
            return []
        return (self.inorder_traversal(node.left) + 
                [node.val] + 
                self.inorder_traversal(node.right))
    
    def preorder_traversal(self, node):
        """Preorder traversal: Root -> Left -> Right"""
        if not node:
            return []
        return ([node.val] + 
                self.preorder_traversal(node.left) + 
                self.preorder_traversal(node.right))
    
    def postorder_traversal(self, node):
        """Postorder traversal: Left -> Right -> Root"""
        if not node:
            return []
        return (self.postorder_traversal(node.left) + 
                self.postorder_traversal(node.right) + 
                [node.val])
    
    def level_order_traversal(self):
        """Level-order traversal (BFS)"""
        if not self.root:
            return []
        
        result = []
        queue = deque([self.root])
        
        while queue:
            level_size = len(queue)
            level = []
            
            for _ in range(level_size):
                node = queue.popleft()
                level.append(node.val)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            result.append(level)
        
        return result


class BinarySearchTree:
    """Binary Search Tree Implementation"""
    
    def __init__(self):
        self.root = None
    
    def insert(self, val):
        """Insert a value into BST."""
        self.root = self._insert_recursive(self.root, val)
    
    def _insert_recursive(self, node, val):
        if not node:
            return TreeNode(val)
        
        if val < node.val:
            node.left = self._insert_recursive(node.left, val)
        else:
            node.right = self._insert_recursive(node.right, val)
        
        return node
    
    def search(self, val):
        """Search for a value in BST."""
        return self._search_recursive(self.root, val)
    
    def _search_recursive(self, node, val):
        if not node or node.val == val:
            return node
        
        if val < node.val:
            return self._search_recursive(node.left, val)
        return self._search_recursive(node.right, val)
    
    def inorder(self):
        """Return inorder traversal (sorted order for BST)."""
        result = []
        self._inorder_recursive(self.root, result)
        return result
    
    def _inorder_recursive(self, node, result):
        if node:
            self._inorder_recursive(node.left, result)
            result.append(node.val)
            self._inorder_recursive(node.right, result)


# Common Binary Tree Problem Patterns

def max_depth(root):
    """
    Find maximum depth of a binary tree.
    Time: O(n), Space: O(h)
    """
    if not root:
        return 0
    return 1 + max(max_depth(root.left), max_depth(root.right))


def is_balanced(root):
    """
    Check if a binary tree is height-balanced.
    Time: O(n), Space: O(h)
    """
    def height(node):
        if not node:
            return 0
        
        left_height = height(node.left)
        if left_height == -1:
            return -1
        
        right_height = height(node.right)
        if right_height == -1:
            return -1
        
        if abs(left_height - right_height) > 1:
            return -1
        
        return 1 + max(left_height, right_height)
    
    return height(root) != -1


def invert_tree(root):
    """
    Invert a binary tree (mirror).
    Time: O(n), Space: O(h)
    """
    if not root:
        return None
    
    root.left, root.right = root.right, root.left
    invert_tree(root.left)
    invert_tree(root.right)
    
    return root


def is_same_tree(p, q):
    """
    Check if two trees are identical.
    Time: O(n), Space: O(h)
    """
    if not p and not q:
        return True
    if not p or not q:
        return False
    
    return (p.val == q.val and 
            is_same_tree(p.left, q.left) and 
            is_same_tree(p.right, q.right))


def is_symmetric(root):
    """
    Check if a tree is symmetric.
    Time: O(n), Space: O(h)
    """
    def is_mirror(left, right):
        if not left and not right:
            return True
        if not left or not right:
            return False
        
        return (left.val == right.val and 
                is_mirror(left.left, right.right) and 
                is_mirror(left.right, right.left))
    
    if not root:
        return True
    return is_mirror(root.left, root.right)


def lowest_common_ancestor(root, p, q):
    """
    Find lowest common ancestor of two nodes.
    Time: O(n), Space: O(h)
    """
    if not root or root == p or root == q:
        return root
    
    left = lowest_common_ancestor(root.left, p, q)
    right = lowest_common_ancestor(root.right, p, q)
    
    if left and right:
        return root
    
    return left if left else right


def path_sum(root, target_sum):
    """
    Check if there's a root-to-leaf path with given sum.
    Time: O(n), Space: O(h)
    """
    if not root:
        return False
    
    if not root.left and not root.right:
        return root.val == target_sum
    
    target_sum -= root.val
    return (path_sum(root.left, target_sum) or 
            path_sum(root.right, target_sum))


def diameter_of_tree(root):
    """
    Find diameter of binary tree (longest path between any two nodes).
    Time: O(n), Space: O(h)
    """
    diameter = [0]
    
    def height(node):
        if not node:
            return 0
        
        left_height = height(node.left)
        right_height = height(node.right)
        
        diameter[0] = max(diameter[0], left_height + right_height)
        
        return 1 + max(left_height, right_height)
    
    height(root)
    return diameter[0]


def right_side_view(root):
    """
    Return values visible from right side of tree.
    Time: O(n), Space: O(w)
    """
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        
        for i in range(level_size):
            node = queue.popleft()
            
            if i == level_size - 1:
                result.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
    
    return result


def zigzag_level_order(root):
    """
    Return zigzag level order traversal.
    Time: O(n), Space: O(w)
    """
    if not root:
        return []
    
    result = []
    queue = deque([root])
    left_to_right = True
    
    while queue:
        level_size = len(queue)
        level = deque()
        
        for _ in range(level_size):
            node = queue.popleft()
            
            if left_to_right:
                level.append(node.val)
            else:
                level.appendleft(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        result.append(list(level))
        left_to_right = not left_to_right
    
    return result


def serialize(root):
    """
    Serialize a binary tree to a string.
    Time: O(n), Space: O(n)
    """
    if not root:
        return "null"
    
    result = []
    queue = deque([root])
    
    while queue:
        node = queue.popleft()
        if node:
            result.append(str(node.val))
            queue.append(node.left)
            queue.append(node.right)
        else:
            result.append("null")
    
    return ",".join(result)


def deserialize(data):
    """
    Deserialize a string to binary tree.
    Time: O(n), Space: O(n)
    """
    if not data or data == "null":
        return None
    
    values = data.split(",")
    root = TreeNode(int(values[0]))
    queue = deque([root])
    i = 1
    
    while queue and i < len(values):
        node = queue.popleft()
        
        if values[i] != "null":
            node.left = TreeNode(int(values[i]))
            queue.append(node.left)
        i += 1
        
        if i < len(values) and values[i] != "null":
            node.right = TreeNode(int(values[i]))
            queue.append(node.right)
        i += 1
    
    return root


if __name__ == "__main__":
    # Example usage
    bt = BinaryTree()
    bt.insert(1)
    bt.insert(2)
    bt.insert(3)
    bt.insert(4)
    bt.insert(5)
    
    print("Inorder:", bt.inorder_traversal(bt.root))
    print("Preorder:", bt.preorder_traversal(bt.root))
    print("Postorder:", bt.postorder_traversal(bt.root))
    print("Level Order:", bt.level_order_traversal())
    
    # BST example
    bst = BinarySearchTree()
    for val in [5, 3, 7, 2, 4, 6, 8]:
        bst.insert(val)
    print("\nBST Inorder (sorted):", bst.inorder())
