#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int r, c, k;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second > b.second) {
        return true;
    } else if (a.second == b.second) {
        return a.first > b.first;
    } eles {
        return false;
    };
}

void rowSort(int row, int col) {
    for (int i = 1; i <= row; i++) {
        pair<int, int>  numCnt[101];
        for (int j = 1; j <= col; j++) {
            numCnt[arr[i][j]].first = arr[i][j];
            numCnt[arr[i][j]].second++;
        }
        sort(numCnt + 1, numCnt + 101, cmp);

        int tmp = 1;
        for (auto v: numCnt) {
            if (v.second == 0) {
                continue;
            }
            arr[i][tmp] = v.first;
            arr[i][tmp + 1] = v.second;
            tmp += 2;
        }
    }
}

void colSort(int row, int col) {
    for (int i = 1; i <= col; i++) {
        pair<int, int>  numCnt[101];
        for (int j = 1; j <= row; j++) {
            numCnt[arr[j][i]].first = arr[j][i];
            numCnt[arr[j][i]].second++;
        }
        sort(numCnt + 1, numCnt + 101, cmp);

        int tmp = 1;
        for (auto v: numCnt) {
            if (v.second == 0) {
                continue;
            }
            arr[i][tmp] = v.first;
            arr[i][tmp + 1] = v.second;
            tmp += 2;
        }
    }

}

void solve() {
    int row = -1, col = -1;
    for (int i = 1; i <= 100; i++) {
        int cnt = 0;
        for (int j = 1; j <= 100; j++) {
            if (arr[i][j] != 0) {
                cnt++;
            }
        }
        col = max(col, cnt);
    }

    for (int i = 1; i <= 100; i++) {
        int cnt = 0;
        for (int j = 1; j <= 100; j++) {
            if (arr[j][i] != 0) {
                cnt++;
            }
        }
        row = max(row, cnt);
    }

    if (row >= col) {
        rowSort(row, col);
    } else {
        colSort(row, col);
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];
        }
    }

    for (int time = 0; time <= 100; time++) {
        if (arr[r][c] == k) {
            cout << time;
            return 0;
        } else {
            solve();
        }
    }


}