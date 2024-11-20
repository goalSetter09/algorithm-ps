#include <iostream>

using namespace std;

int n, m;
int arr[101][101];
int mon = 0;

void clean(int row, int& c) {
    for(int i = 1; i <= c; i++) {
        if(arr[row][i] == 1) {
            arr[row][i] = 0;
            mon--;
            return;
        }
    }
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                mon++;
            }
        }
    }
    int s1, s2, e1, e2;
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    for(int i = s1; i <= e1; i++) {
        clean(i, m);
    }
    for(int i = s2; i <= e2; i++) {
        clean(i, m);
    }

    cout << mon;
    return 0;
}