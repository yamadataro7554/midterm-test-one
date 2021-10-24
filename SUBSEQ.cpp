
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
#define maxN 20
#define maxM 64
 
// To store the states of DP
int dp[maxN][maxM];
bool v[maxN][maxM];
 
// Function to return the length
// of the longest subsequence
// whose sum is divisible by m
int findLen(int* arr, int i, int curr,
            int n, int m)
{
    // Base case
    if (i == n) {
        if (!curr)
            return 0;
        else
            return -1;
    }
 
    // If the state has been solved before
    // return the value of the state
    if (v[i][curr])
        return dp[i][curr];
 
    // Setting the state as solved
    v[i][curr] = 1;
 
    // Recurrence relation
    int l = findLen(arr, i + 1, curr, n, m);
    int r = findLen(arr, i + 1,
                    (curr + arr[i]) % m, n, m);
    dp[i][curr] = l;
    if (r != -1)
        dp[i][curr] = max(dp[i][curr], r + 1);
    return dp[i][curr];
}
 
// Driver code
int main()
{
    freopen("SUBSEQ.inp", "r", stdin);
    freopen("SUBSEQ.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    int arr[n+5];
    for (int i=1; i<=n; i++)
        cin >> arr[i];

    cout << findLen(arr, 0, 0, n, m) - 1;
 
    return 0;
}