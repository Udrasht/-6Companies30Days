// Question Link:-https://leetcode.com/problems/sort-characters-by-frequency/
/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.



Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.length();
        string ans;
        vector<int> count(128, 0);

        vector<vector<char>> buckets(n + 1);

        for (const char c : s)
            count[c]++;

        for (int i = 0; i < 128; ++i)
        {
            int freq = count[i];
            if (freq > 0)
                buckets[freq].push_back((char)i);
        }

        for (int freq = n; freq > 0; --freq)
            for (char c : buckets[freq])
                ans += string(freq, c);

        return ans;
    }
};
int main()
{
    string s = "cccaaa";

    Solution ss;

    string ans = ss.frequencySort(s);

    cout << ans << endl;

    return 0;
}