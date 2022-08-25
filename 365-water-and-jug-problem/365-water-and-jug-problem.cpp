#include<bits/stdc++.h>
class Solution {
public:
    
    int gcd(int a,int b){if(b==false)return a;return gcd(b,a%b);}
    //ax+by=c
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    // return __gcd(jug1Capacity,jug2Capacity)?true:false;
       if(jug1Capacity+jug2Capacity<targetCapacity)return false; 
        // else return true;
       return targetCapacity%gcd(jug1Capacity,jug2Capacity)==false;
    }
};