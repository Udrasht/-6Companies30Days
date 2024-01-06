// Question Link:-https://leetcode.com/problems/image-smoother/description/

/*
An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).


Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.



Example 1:


Input: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Example 2:


Input: img = [[100,200,100],[200,50,200],[100,200,100]]
Output: [[137,141,137],[141,138,141],[137,141,137]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
For the points (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
For the point (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138


Constraints:

m == img.length
n == img[i].length
1 <= m, n <= 200
0 <= img[i][j] <= 255
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size();
        int m = img[0].size();
        int tt = 255;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int neighbourCount = 1;
                int sum = img[i][j];

                for (int k = 0; k < 8; k++)
                {
                    int xx = i + x[k];
                    int yy = j + y[k];
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m)
                    {
                        neighbourCount++;
                        sum = sum + (img[xx][yy] & tt);
                    }
                }

                sum = sum / neighbourCount;
                sum = sum << 8;
                img[i][j] = img[i][j] | sum;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                img[i][j] = img[i][j] >> 8;
            }
        }
        return img;
    }
};

int main()
{
    Solution ss;

    vector<vector<int>> img = {{100, 200, 100}, {200, 50, 200}, {100, 200, 100}};

    vector<vector<int>> ans = ss.imageSmoother(img);
    for (auto it : ans)
    {
        for (auto jt : it)
        {
            cout << jt << " ";
        }
        cout << endl;
    }
    return 0;
}