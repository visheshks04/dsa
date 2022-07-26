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
    
    private void bfs(TreeNode root, int level, ArrayList<List<Integer>> list){
        if (root == null)
            return;
        
        if(list.size() < level + 1)
            list.add(new ArrayList<>());
        
        list.get(level).add(root.val);
        bfs(root.left, level + 1, list);
        bfs(root.right, level + 1, list);
    }
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        ArrayList<List<Integer>> list = new ArrayList<>();
        bfs(root, 0, list);
        return list;
    }
}
