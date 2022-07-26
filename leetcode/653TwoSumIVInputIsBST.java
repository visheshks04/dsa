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
    
    public boolean findTarget(TreeNode root, int k) {
        ArrayList<Integer> list = new ArrayList<>();
        inorder(list, root);
        
        int head = 0;
        int tail = list.size()-1;
        
        while(head < tail){
            if(list.get(head)+list.get(tail) == k)
                return true;
            
            else if(list.get(head)+list.get(tail) > k)
                tail--;
            
            else
                head++;
        }
        
        return false;
    }
    
    
}
