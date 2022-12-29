#include <iostream>
using namespace std;

int N, min_data = 2000000000; // 최솟값에 20억 대입
int score_table[20][20]; // 능력치 입력받는 배열
int score_select[20]; // 두 개의 팀으로 나누기 위한 배열
int team1[10]; // 팀1
int team2[10]; // 팀2

void find_min() {
    int team1_idx = 0, team2_idx = 0;
    int team1_sum = 0, team2_sum = 0;
    for (int i = 0; i < N; i++) {
        if (score_select[i] == 1) team1[team1_idx++] = i;
        else team2[team2_idx++] = i;
    }
    for (int i = 0; i < (N / 2); i++) {
        for (int j = i + 1; j < (N / 2); j++) {
            team1_sum += (score_table[team1[i]][team1[j]] + score_table[team1[j]][team1[i]]);
            team2_sum += (score_table[team2[i]][team2[j]] + score_table[team2[j]][team2[i]]);
        }
    }
    if (min_data > abs(team1_sum - team2_sum))
        min_data = abs(team1_sum - team2_sum);
}

void dfs(int depth, int idx) {
    if (depth == (N / 2)) { // 팀이 2개 이므로 n/2값 까지 수행
        find_min(); // 팀1과 팀2의 차이를 구하고 최솟값 판별하는 함수
        return;
    }
    for (int i = idx; i < N; i++) {
        score_select[idx] = 1;
        dfs(depth + 1, i + 1); // dfs(depth + 1, idx + 1) 오답 -> idx로 넣게 된다면 1번 반복 후에 증가된 값이 idx값으로 들어가지 못하고 고정된 idx값이 들어가게 된다. 따라서 1씩 증가되는 i값을 넣어야함.
        score_select[idx] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> score_table[i][j];
        }
    }
    dfs(0, 0);
    cout << min_data; 
    return 0;
}
