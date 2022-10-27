#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        vector<int>temp(m+n);
        std::merge(n1.begin(),n1.begin()+m,n2.begin(),n2.begin()+n,temp.begin());
        n1=temp;
    }
};