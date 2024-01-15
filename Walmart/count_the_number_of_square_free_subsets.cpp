// Question Link:-https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/

/*
You are given a positive integer 0-indexed array nums.

A subset of the array nums is square-free if the product of its elements is a square-free integer.

A square-free integer is an integer that is divisible by no square number other than 1.

Return the number of square-free non-empty subsets of the array nums. Since the answer may be too large, return it modulo 109 + 7.

A non-empty subset of nums is an array that can be obtained by deleting some (possibly none but not all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.



Example 1:

Input: nums = [3,4,4,5]
Output: 3
Explanation: There are 3 square-free subsets in this example:
- The subset consisting of the 0th element [3]. The product of its elements is 3, which is a square-free integer.
- The subset consisting of the 3rd element [5]. The product of its elements is 5, which is a square-free integer.
- The subset consisting of 0th and 3rd elements [3,5]. The product of its elements is 15, which is a square-free integer.
It can be proven that there are no more than 3 square-free subsets in the given array.
Example 2:

Input: nums = [1]
Output: 1
Explanation: There is 1 square-free subset in this example:
- The subset consisting of the 0th element [1]. The product of its elements is 1, which is a square-free integer.
It can be proven that there is no more than 1 square-free subset in the given array.


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 30
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int squareFreeSubsets(vector<int> &nums)
    {
        int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int count[31]{};

        for (int &num : nums)
        {
            ++count[num];
        }

        const int numOfPrimes = 10;
        const int mod = 1e9 + 7;

        vector<long long> subsetsState(1 << numOfPrimes);
        subsetsState[0] = 1;

        for (int i = 0; i < count[1]; ++i)
        {
            subsetsState[0] = (subsetsState[0] * 2) % mod;
        }

        for (int x = 2; x < 31; ++x)
        {
            if (count[x] == 0 || x % 4 == 0 || x % 9 == 0 || x % 25 == 0)
            {
                continue;
            }

            int mask = 0;
            for (int i = 0; i < numOfPrimes; ++i)
            {
                if (x % primes[i] == 0)
                {
                    mask |= 1 << i;
                }
            }

            for (int state = (1 << numOfPrimes) - 1; state; --state)
            {
                if ((state & mask) == mask)
                {
                    subsetsState[state] = (subsetsState[state] + 1LL * count[x] * subsetsState[state ^ mask]) % mod;
                }
            }
        }

        long long ans = -1;
        for (auto state : subsetsState)
        {
            ans = (ans + state) % mod;
        }

        return ans;
    }
};

int main()
{
    vector<int> arr = {3, 4, 4, 5};
    Solution ss;

    int ans = ss.squareFreeSubsets(arr);

    cout << ans << endl;

    return 0;
}