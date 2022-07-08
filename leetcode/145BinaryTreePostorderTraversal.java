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
    
    private void postorder(ArrayList<Integer> l, TreeNode root){
        if(root == null){
            return;
        }
        
        postorder(l, root.left);
        postorder(l, root.right);
        l.add(root.val);
        
    }
    
    public List<Integer> postorderTraversal(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<>();
        postorder(list, root);
        
        return list;
    }
}
