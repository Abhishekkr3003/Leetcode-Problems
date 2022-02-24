# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        res=[]
        stack=[root]
        while len(stack)>0:
            node=stack[-1]
            stack.pop()
            res.append(node.val)
            if node.left: 
                stack.append(node.left)
            if node.right: 
                stack.append(node.right)
            
        return res[::-1]
            
            
            
        
        