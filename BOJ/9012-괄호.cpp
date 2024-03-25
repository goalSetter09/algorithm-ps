#include <bits/stdc++.h>
using namespace std;

stack<char> st;
bool isCorrect;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    string s;
    while (t--) {
        while (!st.empty()) {
            st.pop();
        }
        isCorrect = true;
        cin >> s;
        for (char i : s) {
            if (i == '(') {
                st.push('(');
            } else {
                if (st.empty()) {
                    isCorrect = false;
                    break;
                }
                if (st.top() == '(') {
                    st.pop();
                }
            }
        }
        if (!isCorrect || !st.empty()) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
}
