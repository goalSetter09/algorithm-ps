#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<pair<int, int> > point;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.X < b.X) {
        return true;
    } else if(a.X > b.X) {
        return false;
    }else if(a.Y <= b.Y) {
        return true;
    } else return false;
}

void print(const pair<int, int> &p) {
    cout << p.X << ' ' << p.Y << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int x, y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        point.push_back(make_pair(x, y));
    }

    sort(point.begin(), point.end(), cmp);

    for_each(point.begin(), point.end(), print);
}