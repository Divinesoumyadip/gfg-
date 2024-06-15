
There is a standard numeric keypad on a mobile phone. You can only press the current button or buttons that are directly up, left, right, or down from it (for ex if you press 5, then pressing 2, 4, 6 & 8 are allowed). Diagonal movements and pressing the bottom row corner buttons (* and #) are prohibited.



Given a number n, find the number of possible unique sequences of length n that you can create by pressing buttons. You can start from any digit.

Examples

Input: n = 1
Output: 10
Explanation: Number of possible numbers are 10 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)  
Input: n = 2
Output: 36
Explanation: Possible numbers: 00, 08, 11, 12, 14, 22, 21, 23, 25 and so on. If we start with 0, valid numbers will be 00, 08 (count: 2). If we start with 1, valid numbers will be 11, 12, 14 (count: 3). If we start with 2, valid numbers  will be 22, 21, 23,25 (count: 4). If we start with 3, valid numbers will be 33, 32, 36 (count: 3). If we start with 4, valid numbers will be 44,41,45,47 (count: 4). If we start with 5, valid numbers will be 55,54,52,56,58 (count: 5) and so on.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:








class Solution {
  public:
    long long getcount(int i,int n,map<int,vector<int>> &m,vector<vector<long long int>> &dp)
    {
        if(n==1) return 1;
        if(dp[n][i]!=-1) return dp[n][i];
        long long k=0;
        for(auto j:m[i])
        {
            k=k+getcount(j,n-1,m,dp);
        }
        return dp[n][i]=k;
    }
    long long getCount(int n) {
        map<int,vector<int>> m;
        m[0]={0,8};
        m[1] = {2,4,1};
        m[2] = {1,3,5,2};
        m[3] = {2,6,3};
        m[4] = {1,5,7,4};
        m[5] = {2,4,6,8,5};
        m[6] = {3,5,9,6};
        m[7] = {4,8,7};
        m[8] = {5,7,9,0,8};
        m[9] = {6,8,9};
        
        long long s=0;
        vector<vector<long long int>> dp(n+1,vector<long long int>(10,-1));
        
        for(int i=0;i<10;i++)
        {
            s=s+getcount(i,n,m,dp);
        }
        return s;
        // Your code goes here
    }
};
