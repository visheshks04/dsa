/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    private boolean helper(TreeNode root, int targetSum, int currSum){
        if(root.right == null && root.left == null){
            if(currSum+root.val == targetSum)
                return true;
            else
                return false;
        }
        
        if(root.left != null && root.right != null)
            return helper(root.left, targetSum, currSum+root.val) || helper(root.right, targetSum, currSum+root.val);
        
        if(root.left != null)
            return helper(root.left, targetSum, currSum+root.val);
        if(root.right != null)
            return helper(root.right, targetSum, currSum+root.val);
        
        return false;
    }
    
    public boolean hasPathSum(TreeNode root, int targetSum) {
        
        if(root == null)
            return false;
        
        int currSum = root.val;
        
        if(root.left == null && root.right == null){
            if(targetSum == root.val)
                return true;
            
            return false;
        }
        
        if(root.left != null && root.right != null)
            return helper(root.left, targetSum, currSum) || helper(root.right, targetSum, currSum);
        
        if(root.left != null)
            return helper(root.left, targetSum, currSum);
        if(root.right != null)
            return helper(root.right, targetSum, currSum);
        
        return false;
        
    }
}
