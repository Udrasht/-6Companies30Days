// Question Link:-https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1

// Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.

// Example 1:

// Input:
// D
// Output:
// 21
// Explanation:
// D is meant for decreasing, so we choose the minimum number among all possible numbers like 21,31,54,87,etc.
// Example 2:

// Input:
// IIDDD
// Output:
// 126543
// Explanation:
// Above example is self- explanatory,
// 1 < 2 < 6 > 5 > 4 > 3
//   I - I - D - D - D
// Your Task:

// You don't need to read input or print anything. Your task is to complete the function printMinNumberForPattern() which takes the string S and returns a string containing the minimum number following the valid number.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ Length of String ≤ 8

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{   
public:
    string printMinNumberForPattern(string S){
        stack<int> st;
        string ans="";
        int val=1;
        for(int i=0;i<S.size();i++){
            st.push(val);
            if(S[i]=='I'){
                while(!st.empty()){
                    ans=ans+to_string(st.top());
                    st.pop();
                }
            }
            val=val+1;
        }
        st.push(val);
         while(!st.empty()){
                    ans=ans+to_string(st.top());
                    st.pop();
                }
                return ans;
        
        // code here 
    }
};

int main()
{
    string input = "IIDDD";
    Solution ss;
    string ans=ss.printMinNumberForPattern(input);
    cout<<ans<<endl;
}