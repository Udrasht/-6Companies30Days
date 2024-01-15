// Question Link:-https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/

/*
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation:
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7.
Another possible subsequence is [4, 3].


Constraints:

1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<pair<int, int>> temp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());
        vector<pair<int, int>> ans;

        for (int i = nums.size() - k; i < n; i++)
        {

            ans.push_back({temp[i].second, temp[i].first});
        }
        vector<int> res;
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            res.push_back(ans[i].second);
        }

        return res;
    }
};

int main()
{
    vector<int> arr = {-1, -2, 3, 4};
    Solution ss;
    int k = 3;

    vector<int> ans = ss.maxSubsequence(arr, k);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}