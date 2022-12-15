#include <iostream>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, mod, left, tmp;
    cin >> n >> m;
    mod = n % m; // 두 수를 나눈 나머지 값
    tmp = m; // tmp에 2번째 값 대입
    left = m;
    while (mod > 0) { // 두 수를 나눈 나머지 값으로 2번째 숫자를 나눈다. 나머지가 0이 되는 순간의 2번째 값이 최대공약수
        tmp = mod; // tmp에 mod연산 값 대입
        mod = left % mod; // mod에 2번째 값과 나머지를 나눈 나머지 값 대입
        left = tmp;
    }
    cout << tmp << '\n';

    cout << (n * m) / tmp; // 최대공약수 * 최소공배수 = 두 수의 곱
}
