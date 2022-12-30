#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, count = 0;
    cin >> n;
    for (int i = 666;; i++) { // 666부터 무한대로 반복 돌림, 중간에 i<=n X -> n은 몇 번째이지 무슨 숫자까지 반복 돌리라는게 아님
        int num = i; // i를 그대로 나눠버리면 i값이 훼손 되기 때문
        while (num >= 666) {
            if (num % 1000 == 666) { // 1000으로 나눈 나머지가 666인 것은 6이 연속해서 3번 있단 소리
                count++;
                break;
            }
            num /= 10; // while반복문 조건인 666보다 클 때 까지 10으로 나눠 자리수를 1개씩 삭제시킨다
        }
        if (n == count) {
            cout << i;
            break;
        }
    }
}
