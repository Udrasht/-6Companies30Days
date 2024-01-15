// Question Link:-https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.



Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].


Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    map<int, Node *> childern;
    bool endFlag = false;
    bool containsKey(int ch)
    {
        if (childern.find(ch) != childern.end())
        {
            return true;
        }
        return false;
    }
    void put(int ch, Node *node)
    {
        childern[ch] = node;
    }
    Node *get(int ch)
    {
        return childern[ch];
    }
    void setEnd()
    {
        endFlag = true;
    }

    bool getEnd()
    {
        return endFlag;
    }
};

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        Node *root = new Node();
        ;
        int n = nums1.size();
        for (int j = 0; j < n; j++)
        {
            Node *node = root;
            for (int i = j; i < n; i++)
            {
                if (!node->containsKey(nums1[i]))
                {
                    node->put(nums1[i], new Node());
                }

                node = node->get(nums1[i]);
            }
            node->setEnd();
        }
        int m = nums2.size();
        int ans = 0;
        for (int j = 0; j < m; j++)
        {
            Node *node = root;
            int count = 0;
            for (int i = j; i < m; i++)
            {
                if (!node->containsKey(nums2[i]))
                {
                    break;
                }
                count++;
                node = node->get(nums2[i]);
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums1 = {1, 2, 3, 2, 1}, nums2 = {3, 2, 1, 4, 7};

    Solution ss;

    int ans = ss.findLength(nums1, nums2);

    cout << ans << endl;

    return 0;
}