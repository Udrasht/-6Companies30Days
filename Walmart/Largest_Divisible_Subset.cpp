// Question Link:-https://leetcode.com/problems/largest-divisible-subset/description/

/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.



Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> dp(n, 1);

        int ans = 0;
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0)
                {
                    if (dp[i] < dp[j] + 1)
                    {

                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if (ans < dp[i])
            {
                ans = dp[i];
                ind = i;
            }
        }
        int ans1 = 0;
        vector<int> dp2(ans, -1);
        dp2[ans - 1] = arr[ind];
        ans--;
        for (int i = n - 1; i >= 0; i--)
        {
            if (ans == dp[i] && arr[ind] % arr[i] == 0)
            {
                dp2[ans - 1] = arr[i];
                ind = i;
                ans--;
            }
            if (ans < 0)
            {
                break;
            }
        }

        return dp2;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3};
    Solution ss;

    vector<int> ans = ss.largestDivisibleSubset(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}