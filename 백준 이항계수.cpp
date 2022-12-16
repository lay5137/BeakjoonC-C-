#include <iostream>
#include <algorithm>
using namespace std;

// 동적프로그래밍 이용: 점화식 (n+1,k+1) = (n,k) + (n,k+1) - 파스칼의 삼각형
int dp[1001][1001];
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1; //배열 범위를 넘지 않기 위해

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) dp[i][j] = 1;
            else if (j == 0)dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
        }
    }
    cout << dp[n][k];
}
