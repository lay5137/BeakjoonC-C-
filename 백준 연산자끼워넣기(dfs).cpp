#include <iostream>
using namespace std;

int n, maxdata = -1000000001, mindata = 1000000001;
int arr[11];
int operators[4]; // 연산자

void dfs(int result, int depth) {
    if (depth == n) {
        if (result > maxdata)
            maxdata = result;
        if (result < mindata)
            mindata = result;
        return;
    }
    else {
        for (int i = 0; i < 4; i++) {
            if (operators[i] > 0) {
                operators[i]--;

                if (i == 0) dfs(result + arr[depth], depth + 1);
                else if (i == 1) dfs(result - arr[depth], depth + 1);
                else if (i == 2) dfs(result * arr[depth], depth + 1);
                else dfs(result / arr[depth], depth + 1);

                operators[i]++; // 다시 값을 더해서 다른 경우의 수 탐색
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < 4; i++)
        cin >> operators[i];

    dfs(arr[0], 1);

    cout << maxdata << '\n' << mindata;
}
