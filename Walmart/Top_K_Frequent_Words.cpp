// Question Link:-https://leetcode.com/problems/top-k-frequent-words/description/
/*
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.



Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.


Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]


Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(const pair<int, string> &a, const pair<int, string> &b)
{
    if (a.first == b.first)
    {
        // Lexicographical comparison in descending order
        return a.second > b.second;
    }
    return a.first < b.first;
}

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(&cmp)> pq(&cmp);
        // priority_queue<pair<int, string>> pq;
        sort(words.begin(), words.end());
        int currcount = 0;
        string currword = "";
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            if (currword.size() != 0 && currword != words[i])
            {
                // cout<<"currword "<<currword<<" "<<currcount<<endl;
                pq.push({currcount, currword});
                currcount = 1;
                currword = words[i];
            }
            else
            {
                currword = words[i];
                currcount++;
            }
        }
        // cout<<"currword "<<currword<<" "<<currcount<<endl;
        pq.push({currcount, currword});
        vector<string> ans;
        while (!pq.empty() && k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
int main()
{
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    Solution ss;

    vector<string> ans = ss.topKFrequent(words, k);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}