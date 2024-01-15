// Question Link:-https://leetcode.com/problems/word-break/description/
/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false


Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        const int n = s.length();
        const unordered_set<string> wordSet{wordDict.begin(), wordDict.end()};

        vector<bool> dp(n + 1);
        dp[0] = true;

        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < i; ++j)

                if (dp[j] && wordSet.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    //   break;
                }

        return dp[n];
    }
};
int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution ss;

    bool ans = ss.wordBreak(s, wordDict);
    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}