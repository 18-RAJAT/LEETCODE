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
    static void Dfs(TreeNode odd,TreeNode even, int ok)
    {
        if(odd==null || even==null)return;
        if(ok%2==1)
        {
            int tmp=odd.val;
            odd.val=even.val;
            even.val=tmp;
        }
        Dfs(odd.left,even.right,ok+1);
        Dfs(odd.right,even.left,ok+1);
    }
    public TreeNode reverseOddLevels(TreeNode root) {
        Dfs(root.left,root.right,1);
        return root;
    }
}