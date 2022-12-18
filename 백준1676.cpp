#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, a = 0, b = 0, count = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 125 == 0) count += 3;
        else if (i % 25 == 0) count += 2;
        else if (i % 5 == 0) count++;
    }
    cout << count;
}
