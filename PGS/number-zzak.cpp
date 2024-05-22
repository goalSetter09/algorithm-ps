#include<bits/stdc++.h>

using namespace std;

string solution(string X, string Y) {

    int numCntX[10] = {};
    int numCntY[10] = {};
    fill(numCntX, numCntX + 9, 0);
    fill(numCntY, numCntY + 9, 0);

    for(auto c : X) {
        numCntX[(c - '0')]++; // X에서 각 자리수의 개수
    }
    for(auto c : Y) {
        numCntY[(c - '0')]++; // Y에서 각 자리수 개수
    }

    string answer = "";

    for(int i = 9; i >= 0; i--) {
        int tmp = min(numCntX[i], numCntY[i]);
        if(tmp == 0) {
            continue;
        }
        for(int j = 0; j < tmp; j++) {
            answer.push_back(i + '0');
        }
    }
    if(answer == "") {
        return "-1";
    }
    if(answer[0] == '0') {
        return "0";
    }
    return answer;
}