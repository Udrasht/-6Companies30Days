// Question Link:-https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
/*
One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as '#'.


For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.

Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid.

For example, it could never contain two consecutive commas, such as "1,,3".
Note: You are not allowed to reconstruct the tree.



Example 1:

Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:

Input: preorder = "1,#"
Output: false
Example 3:

Input: preorder = "9,#,#,1"
Output: false


Constraints:

1 <= preorder.length <= 104
preorder consist of integers in the range [0, 100] and '#' separated by commas ','.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        stack<pair<string, int>> st;
        string str = "";
        preorder = preorder + ",";
        int n = preorder.size();
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            if (preorder[i] != ',')
            {
                str = str + preorder[i];
            }
            else
            {
                if (str == "#")
                {
                    if (st.size() == 0 && n == 2)
                    {
                        return true;
                    }
                    if (st.size() == 0 && n != 2)
                    {
                        return false;
                    }
                    if (st.top().second == 1)
                    {
                        while (!st.empty() && st.top().second == 1)
                        {
                            // cout<<"Pop"<<st.top().first<<" "<<st.top().second<<endl;
                            st.pop();
                        }
                        if (!st.empty())
                        {
                            st.top().second = 1;
                            // cout<<"change"<<st.top().first<<" "<<st.top().second<<endl;
                        }
                    }
                    else
                    {
                        st.top().second = 1;
                        //  cout<<"change"<<st.top().first<<" "<<st.top().second<<endl;
                    }
                }
                else
                {
                    st.push({str, 0});
                    t = 1;
                    // cout<<"Push"<<str<<" "<<0<<endl;
                }
                str = "";
            }

            if (t == 1 && st.size() == 0 && i != n - 1)
            {
                // cout<<"end"<<endl;/
                return false;
            }
        }

        if (st.size() == 0)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";

    Solution ss;

    bool ans = ss.isValidSerialization(preorder);
    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}