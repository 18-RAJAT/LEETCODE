// bool comapre(vector<int>&a , vector<int>&b)
// {
//         return(a[1]<b[1]);
// }
class Solution {
public:
        int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
	sort(begin(boxTypes), end(boxTypes), [](auto& a, auto& b){ return a[1] > b[1];});
                
	int answer = 0;
	for(auto& box : boxTypes) 
        {
		if(truckSize <= 0) break;                   
		answer = answer + min(truckSize, box[0]) * box[1];
		truckSize = truckSize - box[0];
	}
	return answer;
    }
};