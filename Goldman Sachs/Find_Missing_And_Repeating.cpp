// Question Link:- https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1



// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.

// Example 1:

// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and 
// smallest positive missing number is 1.
// Example 2:

// Input:
// N = 3
// Arr[] = {1, 3, 3}
// Output: 3 2
// Explanation: Repeating number is 3 and 
// smallest positive missing number is 2.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 ≤ N ≤ 105
// 1 ≤ Arr[i] ≤ N


#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int N)
    {
        int missing = -1;
        int repeatNumber = -1;
        for (int i = 0; i < N; i++)
        {
            arr[(arr[i] - 1) % (N + 1)] += N + 1;
        }
        for (int i = 0; i < N; i++)
        {
            if (arr[i] <= N)
            {
                missing = i + 1;
            }
            if (arr[i] > 2 * N + 2)
            {
                repeatNumber = i + 1;
            }
        }
        return {repeatNumber, missing};

        // code here
    }
};

int main()
{

    int n = 47;
    vector<int> arr = {13, 33, 43, 16, 25, 19, 23, 31, 29, 35, 10, 2, 32, 11, 47, 15, 34, 46, 30, 26, 41, 18, 5, 17, 37, 39, 6, 4, 20, 27, 9, 3, 8, 40, 24, 44, 14, 36, 7, 38, 12, 1, 42, 12, 28, 22, 45};
    Solution ss;
    vector<int> ans = ss.findTwoElement(arr, n);
    for (auto it : ans)
    {

        cout << it << " ";
    }
    cout << endl;
}