// Question Link:-https://leetcode.com/problems/circle-and-rectangle-overlapping/description/

/*
You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.



Example 1:


Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0).
Example 2:

Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output: false
Example 3:


Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
Output: true


Constraints:

1 <= radius <= 2000
-104 <= xCenter, yCenter <= 104
-104 <= x1 < x2 <= 104
-104 <= y1 < y2 <= 104
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        //   find the closest point with in the rectange closest to circle;
        int xclosest = max(x1, min(x2, xCenter));
        int yclosest = max(y1, min(y2, yCenter));
        int xdis = xCenter - xclosest;
        int ydis = yCenter - yclosest;
        if (xdis * xdis + ydis * ydis <= radius * radius)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    int radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1;

    Solution ss;

    int ans = ss.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2);

    cout << ans << endl;

    return 0;
}