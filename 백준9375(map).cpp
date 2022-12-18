#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, n;
    string name, kind;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        map<string, int> m;
        while (n--) { //map에 종류와 개수 집어넣기
            cin >> name >> kind;
            if (m.find(kind) == m.end()) //입력된 옷 종류가 처음인 경우 map에 넣기
                m.insert({ kind, 1 });
            else //중복된 경우 경우를 1 더하기
                m[kind]++;
        }
        int ans = 1;
        for (auto iter : m) { //auto-형식을 자동으로 맞춰줌
            ans *= (iter.second + 1); //1을 더하여 해당 옷이 선택되지 않는 경우를 고려함
        }
        ans -= 1;
        cout << ans << endl;
    }
}
