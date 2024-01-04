// Question Link:- https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/



/*
You are given two positive integers startPos and endPos. Initially, you are standing at position startPos on an infinite number line. With one step, you can move either one position to the left, or one position to the right.

Given a positive integer k, return the number of different ways to reach the position endPos starting from startPos, such that you perform exactly k steps. Since the answer may be very large, return it modulo 109 + 7.

Two ways are considered different if the order of the steps made is not exactly the same.

Note that the number line includes negative integers.

 

Example 1:

Input: startPos = 1, endPos = 2, k = 3
Output: 3
Explanation: We can reach position 2 from 1 in exactly 3 steps in three ways:
- 1 -> 2 -> 3 -> 2.
- 1 -> 2 -> 1 -> 2.
- 1 -> 0 -> 1 -> 2.
It can be proven that no other way is possible, so we return 3.
Example 2:

Input: startPos = 2, endPos = 5, k = 10
Output: 0
Explanation: It is impossible to reach position 5 from position 2 in exactly 10 steps.
 

Constraints:

1 <= startPos, endPos, k <= 1000
*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
int MOD=1e9+7;
int helper(int currPos,int steps,int &endpos,int &k,vector<vector<int>> &dp)
{
    if(currPos==endpos&&steps==k){
        return 1;

    }
    if(abs(endpos-currPos)>(k-steps)){
        return 0;
    }
    if(steps>=k){
        return 0;
    }
    
    // string key=to_string(steps)+"_"+to_string(currPos);
    if(dp[currPos+1000][steps]!=-1){
        return dp[currPos+1000][steps];
    }
    long long ans= helper(currPos+1,steps+1,endpos,k,dp)%MOD;
    ans=(ans+helper(currPos-1,steps+1,endpos,k,dp))%MOD;
    
    dp[currPos+1000][steps]=ans;
    return ans;
}
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3000,vector<int>(k,-1));
       return helper(startPos,0,endPos,k,dp);
        
    }
};   
 

int main(){
    
    int startPos = 1, endPos = 2, k = 3;
    

    
    Solution ss;
    int  ans=ss.numberOfWays(startPos,endPos,k);
    cout<<ans<<endl;
    return 0;

}