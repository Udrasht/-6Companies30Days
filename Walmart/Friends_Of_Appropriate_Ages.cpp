// Question Link:-https://leetcode.com/problems/friends-of-appropriate-ages/description/
/*
There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.

A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:

age[y] <= 0.5 * age[x] + 7
age[y] > age[x]
age[y] > 100 && age[x] < 100
Otherwise, x will send a friend request to y.

Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.

Return the total number of friend requests made.



Example 1:

Input: ages = [16,16]
Output: 2
Explanation: 2 people friend request each other.
Example 2:

Input: ages = [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.
Example 3:

Input: ages = [20,30,100,110,120]
Output: 3
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.


Constraints:

n == ages.length
1 <= n <= 2 * 104
1 <= ages[i] <= 120
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        vector<int> count(121, 0);
        int ans = 0;
        for (int age : ages)
        {
            count[age]++;
        }

        for (int A = 1; A <= 120; A++)
        {
            for (int B = 1; B <= 120; B++)
            {
                if ((B > A / 2 + 7) && (B <= A) && (B <= 100 || A >= 100))
                {
                    if (A == B)
                    {
                        ans = ans + count[B] * (count[B] - 1);
                    }
                    else
                    {
                        ans = ans + count[B] * (count[A]);
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> ages = {20, 30, 100, 110, 120};

    Solution ss;

    int ans = ss.numFriendRequests(ages);

    cout << ans << endl;

    return 0;
}