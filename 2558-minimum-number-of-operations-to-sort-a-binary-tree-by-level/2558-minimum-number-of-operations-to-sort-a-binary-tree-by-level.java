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
    int countSwaps(List<Integer>arr)
    {
        int n=arr.size();
        int[][]A=new int[n][2];
        for(int i=0;i<n;++i)A[i]=new int[]{arr.get(i),i};
        Arrays.sort(A,(a,b)->Integer.compare(a[0],b[0]));
        boolean[]vis=new boolean[n];
        int swaps=0;
        for(int i=0;i<n;++i)
        {
            if(vis[i] || A[i][1]==i)continue;
            int cnt=0,j=i;
            while(!vis[j])
            {
                vis[j]=true;
                j=A[j][1];
                cnt++;
            }
            if(cnt>=2)swaps+=cnt-1;
        }
        return swaps;
    }
    public int minimumOperations(TreeNode root) {
        if(root==null)return 0;
        Queue<TreeNode>q=new LinkedList<>();
        q.add(root);
        int swaps=0;
        while(!q.isEmpty())
        {
            int n=q.size();
            List<Integer>lvl=new ArrayList<>();
            for(int i=0;i<n;++i)
            {
                TreeNode node=q.poll();
                lvl.add(node.val);
                if(node.left!=null)q.add(node.left);
                if(node.right!=null)q.add(node.right);
            }
            swaps+=countSwaps(lvl);
        }
        return swaps;
    }
}