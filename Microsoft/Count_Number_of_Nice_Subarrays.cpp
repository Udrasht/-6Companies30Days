// Question Link:-https://leetcode.com/problems/count-number-of-nice-subarrays/description/

/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.



Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16


Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                nums[i] = 0;
            }
            else
            {
                nums[i] = 1;
            }
        }
        unordered_map<int, int> cc;
        int ans = 0;
        // if(goal!=0){
        //     cc[0]++;
        // }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            if (sum == k)
            {
                ans = ans + 1;
            }
            if (cc.find(sum - k) != cc.end())
            {
                ans = ans + cc[sum - k];
            }
            cc[sum]++;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    Solution ss;

    int ans = ss.numberOfSubarrays(nums, k);

    cout << ans << endl;

    return 0;
}