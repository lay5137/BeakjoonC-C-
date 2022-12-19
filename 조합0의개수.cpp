#include <iostream>
#include <algorithm>
using namespace std;

long long count_n(long long n) {
    long long t_cnt = 0;
    for (long long i = 2; i <= n; i *= 2) { // 시간 초과를 방지하기 위해 *2를 해줌, i가 n 범위 이므로 i의 형을 꼭 long long으로 한다.
        t_cnt += n / i; // n! 연산 중 나오는 2의 모든 약수의 개수를 구하기
    }
    return t_cnt;
}

long long count_m(long long n) {
    long long f_cnt = 0;
    for (long long i = 5; i <= n; i *= 5) { // 시간 초과를 방지하기 위해 *2를 해줌
        f_cnt += n / i; // n! 연산 중 나오는 5의 모든 약수의 개수를 구하기
    }
    return f_cnt;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n, m, t_cnt = 0, f_cnt = 0;
    cin >> n >> m; //두 수 (m<=n) 입력받기

    t_cnt = count_n(n) - count_n(m) - count_n(n - m);
    f_cnt = count_m(n) - count_m(m) - count_m(n - m);
    cout << min(t_cnt, f_cnt); // 둘 중 작은 값 출력 (작은 값의 개수가 곧 10의 개수)
}
