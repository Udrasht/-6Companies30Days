// Question Link:- https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/



// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].



#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Solution {
public:
    void func(int i,int n,map<char,string> &mp,vector<string> &ans,string temp,string &digits){
            if(temp.size()==n){
                ans.push_back(temp);
            }

            char p=digits[i];
            int m=mp[p].size();
            for(int k=0;k<m;k++){
                func(i+1,n,mp,ans,temp+mp[p][k],digits);
            }
    }
    vector<string> letterCombinations(string digits) {
        map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string> ans;
        int n=digits.size();
        if(n==0){
            return {};
        }
        string u="";
        func(0,n,mp,ans,u,digits);
       
        return ans;
    }
};

int main(){
    string digit="23";
    
    Solution ss;
    vector<string> ans=ss.letterCombinations(digit);
    for(auto it: ans){
        
            cout<<it<<" ";
        
    }
    return 0;

}