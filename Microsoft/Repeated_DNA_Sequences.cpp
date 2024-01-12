// Question Link:-https://leetcode.com/problems/repeated-dna-sequences/description/

/*
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.



Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]


Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> counter;
        vector<string> res;

        if (s.size() < 10)
            return res;

        for (int i = 0; i < s.size() - 9; i++)
        {
            counter[s.substr(i, 10)]++;
        }

        for (auto a : counter)
        {
            if (a.second > 1)
                res.push_back(a.first);
        }

        return res;
    }
};

int main()
{
    string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    Solution ss;

    vector<string> ans = ss.findRepeatedDnaSequences(str);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}