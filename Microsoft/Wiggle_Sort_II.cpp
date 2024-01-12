// Question Link:-https://leetcode.com/problems/wiggle-sort-ii/description/

/*
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.



Example 1:

Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.
Example 2:

Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]


Constraints:

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 5000
It is guaranteed that there will be an answer for the given input nums.


Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int right = n - 1;
        int left = n / 2;
        if (n % 2 == 0)
        {
            left--;
        }
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                temp[i] = nums[left];
                left--;
            }
            else
            {
                temp[i] = nums[right];
                right--;
            }
        }
        nums = temp;
    }
};

int main()
{
    vector<int> nums = {1, 5, 1, 1, 6, 4};

    Solution ss;

    ss.wiggleSort(nums);
    for (auto it : nums)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}