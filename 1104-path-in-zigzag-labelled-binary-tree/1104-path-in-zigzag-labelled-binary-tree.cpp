class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>result;
    int level=(int)log2(label)+1; 
	int x=label;
	result.push_back(x);
	
	while(level>1)
	{
	x=(((int)pow(2,level)-1-x)+(int)pow(2,level-1))/2;    
            result.push_back(x);
            level--;
	}
	reverse(result.begin(),result.end());
	
	return result;
	
    }
};