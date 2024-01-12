// Question Link:-https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/

/*
You are given an array of non-overlapping axis-aligned rectangles rects where rects[i] = [ai, bi, xi, yi] indicates that (ai, bi) is the bottom-left corner point of the ith rectangle and (xi, yi) is the top-right corner point of the ith rectangle. Design an algorithm to pick a random integer point inside the space covered by one of the given rectangles. A point on the perimeter of a rectangle is included in the space covered by the rectangle.

Any integer point inside the space covered by one of the given rectangles should be equally likely to be returned.

Note that an integer point is a point that has integer coordinates.

Implement the Solution class:

Solution(int[][] rects) Initializes the object with the given rectangles rects.
int[] pick() Returns a random integer point [u, v] inside the space covered by one of the given rectangles.


Example 1:


Input
["Solution", "pick", "pick", "pick", "pick", "pick"]
[[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
Output
[null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]

Explanation
Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
solution.pick(); // return [1, -2]
solution.pick(); // return [1, -1]
solution.pick(); // return [-1, -2]
solution.pick(); // return [-2, -2]
solution.pick(); // return [0, 0]


Constraints:

1 <= rects.length <= 100
rects[i].length == 4
-109 <= ai < xi <= 109
-109 <= bi < yi <= 109
xi - ai <= 2000
yi - bi <= 2000
All the rectangles do not overlap.
At most 104 calls will be made to pick.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<vector<int>> rects;

    Solution(vector<vector<int>> rects) : rects(rects)
    {
    }

    vector<int> pick()
    {
        int sum_area = 0;
        vector<int> selected;

        for (auto r : rects)
        {

            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sum_area += area;

            if (rand() % sum_area < area)
                selected = r;
        }

        int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
        int y = rand() % (selected[3] - selected[1] + 1) + selected[1];

        return {x, y};
    }
};

int main()
{
    vector<string> opration = {"Solution", "pick", "pick", "pick", "pick", "pick"};
    vector<vector<int>> rect = {{-2, -2, 1, 1}, {2, 2, 4, 6}};

    Solution ss(rect);
    for (int i = 1; i < opration.size(); i++)
    {
        vector<int> ans = ss.pick();
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}