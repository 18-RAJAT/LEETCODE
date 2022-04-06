/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    ListNode* global_Head;
    
     bool isSubPathUtil(ListNode* head, TreeNode* root) 
     {
       if(!head)
       {
           return true;
       }
         
      if(!root)
      {
          return false;
      }
         
         if(head->val != root->val)
         {
             return false;
         }
         
 return isSubPathUtil(head->next,root->left) or isSubPathUtil(head->next, root->right);
         
     }
         bool dfs(TreeNode* root)
         {
             if(!root)
             {
                 return false;
             }
             
    return isSubPathUtil(global_Head,root) or dfs(root->left) or dfs(root->right);
         }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        global_Head = head;
        
        return dfs(root);
        
    }
};













