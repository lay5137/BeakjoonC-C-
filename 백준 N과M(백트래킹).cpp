#include <iostream>
#define SIZE 9
using namespace std;

int n, m;
bool tree[SIZE] = { 0, };
int arr[SIZE] = { 0, };

void dfs(int num, int depth) { //인자를 중복을 제외하기 위해 num값과 깊이를 나타내는 depth 사용
    if (depth == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }
    else {
        for (int i = num; i <= n; i++) { //첫 번째 값을 num인자로 해서 i보다 작은 수를 제외시킴
            if (!tree[i]) {
                tree[i] = true;
                arr[depth] = i;
                dfs(i + 1, depth + 1); //i+1을 함수 인자값으로 넘겨 다음 재귀호출 때 중복을 제거시킴
                tree[i] = false; //백트래킹 실시
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    dfs(1, 0);
}
