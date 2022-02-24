# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        holder=None
        while root:
            if root.right:
                tempHolder=holder
                holder=root.right
                temp=holder
                while temp.right:
                    temp=temp.right
                temp.right=tempHolder
            if root.left:
                root.right=root.left
                root.left=None
            else:
                root.right=holder
                holder=None
            root=root.right
        