// Question Link:- https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

/*
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.



Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
Example 2:

Input: nums = [1,10,2,9]
Output: 16


Constraints:

n == nums.length
1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefixCount;

        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            long long prefixsumRequired = (ll)i * (ll)nums[i];
            prefixCount.push_back(prefixsumRequired - sum);
            sum = sum + nums[i];
        }
        long long ans = INT_MAX;
        sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            long long suffixsumRequired = (ll)(n - 1 - i) * (ll)nums[i];
            ans = min(ans, prefixCount[i] + (sum - suffixsumRequired));
            sum = sum + nums[i];
        }
        return ans;
    }
};

int main()
{
    Solution ss;

    vector<int> nums = {1, 10, 2, 9};

    int ans = ss.minMoves2(nums);

    cout << ans << endl;

    return 0;
}