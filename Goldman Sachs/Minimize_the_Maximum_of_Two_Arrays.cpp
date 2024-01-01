// Question Link:-https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/


// We have two arrays arr1 and arr2 which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:

// arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
// arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
// No integer is present in both arr1 and arr2.
// Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer that can be present in either array.

 

// Example 1:

// Input: divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
// Output: 4
// Explanation: 
// We can distribute the first 4 natural numbers into arr1 and arr2.
// arr1 = [1] and arr2 = [2,3,4].
// We can see that both arrays satisfy all the conditions.
// Since the maximum value is 4, we return it.
// Example 2:

// Input: divisor1 = 3, divisor2 = 5, uniqueCnt1 = 2, uniqueCnt2 = 1
// Output: 3
// Explanation: 
// Here arr1 = [1,2], and arr2 = [3] satisfy all conditions.
// Since the maximum value is 3, we return it.
// Example 3:

// Input: divisor1 = 2, divisor2 = 4, uniqueCnt1 = 8, uniqueCnt2 = 2
// Output: 15
// Explanation: 
// Here, the final possible arrays can be arr1 = [1,3,5,7,9,11,13,15], and arr2 = [2,6].
// It can be shown that it is not possible to obtain a lower maximum satisfying all conditions. 
 

// Constraints:

// 2 <= divisor1, divisor2 <= 105
// 1 <= uniqueCnt1, uniqueCnt2 < 109
// 2 <= uniqueCnt1 + uniqueCnt2 <= 109




#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Solution {
private:
    int gcd(int a, int b) {
        if (!b) return a;
        return gcd(b, a % b);
    }
    int lcm(ll a, ll b) {
        ll temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }
public:
    int minimizeSet(int divisor1, int divisor2, int uc1, int uc2) {
        int l = 1, r = INT_MAX, LCM = lcm(divisor1, divisor2);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int a = mid / divisor1, b = mid / divisor2;
            if (uc1 <= mid - a && uc2 <= mid - b && uc1 + uc2 <= (mid - (mid / LCM))) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main(){
    int divisor1=2;
    int divisor2=7;
    int uc1=1;
    int uc2=3;
    Solution ss;
    cout<<ss.minimizeSet(divisor1,divisor2,uc1,uc2)<<endl;

}
