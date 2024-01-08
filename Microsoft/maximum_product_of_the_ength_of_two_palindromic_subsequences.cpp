// Question Link:-https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/

/*
Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.

Return the maximum possible product of the lengths of the two palindromic subsequences.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.



Example 1:

example-1
Input: s = "leetcodecom"
Output: 9
Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
The product of their lengths is: 3 * 3 = 9.
Example 2:

Input: s = "bb"
Output: 1
Explanation: An optimal solution is to choose "b" (the first character) for the 1st subsequence and "b" (the second character) for the 2nd subsequence.
The product of their lengths is: 1 * 1 = 1.
Example 3:

Input: s = "accbcaxxcxx"
Output: 25
Explanation: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
The product of their lengths is: 5 * 5 = 25.


Constraints:

2 <= s.length <= 12
s consists of lowercase English letters only.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    unordered_map<string, int> mp;
    int n = 0;
    bool ispalin(string str)
    {
        int j = str.size() - 1;
        int i = 0;
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int func(int idx, string str1, string str2, string &str)
    {
        if (idx == n)
        {
            if (ispalin(str1) && ispalin(str2))
            {
                return str1.size() * str2.size();
            }
            else
            {
                return 0;
            }
        }
        if (idx >= n)
        {
            return 0;
        }
        int ans = 0;
        string ss = to_string(idx) + "_" + str1 + "_" + str2;
        if (mp.find(ss) != mp.end())
        {
            return mp[ss];
        }

        for (int i = idx; i < n; i++)
        {
            int a = func(i + 1, str1 + str[i], str2, str);
            int b = func(i + 1, str1, str2 + str[i], str);
            int c = func(i + 1, str1, str2, str);

            ans = max(ans, max(b, max(a, c)));
        }
        mp[ss] = ans;
        return ans;
    }
    int maxProduct(string str)
    {
        // string str1="";
        // string str2="";
        n = str.size();
        mp.clear();

        return func(0, "", "", str);
    }
};

int main()
{
    Solution ss;

    string s = "leetcodecom";

    int ans = ss.maxProduct(s);
    cout << ans << endl;
    return 0;
}