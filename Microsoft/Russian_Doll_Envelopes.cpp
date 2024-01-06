// Question Link:-https://leetcode.com/problems/russian-doll-envelopes/description/

/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.



Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1


Constraints:

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(vector<int> a, vector<int> b)
{
    return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
}

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        int m = 0;
        for (int i = 1; i < envelopes.size(); i++)
        {
            if (envelopes[i][1] > temp[m])
            {
                m++;
                temp.push_back(envelopes[i][1]);
            }
            else
            {
                auto idx = lower_bound(temp.begin(), temp.end(), envelopes[i][1]) - temp.begin();
                temp[idx] = envelopes[i][1];
            }
        }

        return m + 1;
    }
};

int main()
{
    Solution ss;

    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};

    int ans = ss.maxEnvelopes(envelopes);
    cout << ans << endl;
    return 0;
}