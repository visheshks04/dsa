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
    
    private void inorder(ArrayList<Integer> l, TreeNode root){
        if(root == null){
            return;
        }
        
        inorder(l, root.left);
        l.add(root.val);
        inorder(l, root.right);
    }
    
    
    public boolean isValidBST(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<>();
        inorder(list, root);
        
        for(int i=1;i<list.size();i++){
            if(list.get(i) <= list.get(i-1))
                return false;
        }
        
        return true;
        
    }
    
}
