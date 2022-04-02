class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        if(board.empty())
        {
            return false;
        }
        
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[0].size();++j)
            {
                if(dfs(board,0,i,j,word))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board,int count,int i,int j,string& word)
    {
        if(word.size() == count)
        {
            return true;
        }
        
        if(i<0 or j<0 or i >= board.size() or j >= board[0].size() or board[i][j] != word[count])
        {
            return false;
        }
        
        char temp = board[i][j];
        
        board[i][j] = ' ';
        
     bool result =  dfs(board, count+1, i+1, j, word) || dfs(board, count+1, i-1, j, word) || dfs(board, count+1, i, j+1, word) ||dfs(board, count+1, i, j-1, word);
            
            board[i][j] = temp;
        
        return result;
    }
};
