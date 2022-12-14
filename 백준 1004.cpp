#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, x1, y1, x2, y2, n, cx, cy, r;
        cin >> t;
    while (t--) {
        int enter = 0, out = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        while (n--) {
            cin >> cx >> cy >> r;

            if ((x1 - cx)*(x1 - cx) + (y1 - cy) * (y1 - cy) < r * r){
                if ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) > r * r) { //한 행성계에 시작점과 끝점이 있는 경우 제외
                    out++;
                }
            }
            if ((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) > r * r) {
                if ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) < r * r) {
                    enter++;
                }
            }
        }
        cout << out + enter << endl;
    }
    return 0;
}
