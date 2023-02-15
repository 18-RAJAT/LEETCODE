class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k)
	{
		function<vector<int>(vector<int>, int)> add = [&](vector<int> num, int k)->vector<int> 
    {
			int n = num.size();
			//this loop is for adding the k to the last digit of the number
			for (int i = n - 1; i >= 0; --i) {
				//adding the k to the last digit of the number
				num[i] += k;
				//if the number is greater than 10 then we will add the carry to the next digit
				k = num[i] / 10;
				//if the number is greater than 10 then we will take the remainder of the number
				num[i] %= 10;
			}
			while (k > 0) {
				//if the number is greater than 10 then we will add the carry to the next digit
				num.insert(num.begin(), k % 10);
				//if the number is greater than 10 then we will take the remainder of the number
				k /= 10;
			}
			//returning the number
			return num;
		};
		//calling the function
		return add(num, k);
	}
};
