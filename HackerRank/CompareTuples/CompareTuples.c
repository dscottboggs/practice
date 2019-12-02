#include <bits/stdc++.h>
using namespace std;

vector <int> solve(int a0, int a1, int a2, int b0, int b1, int b2){
    int ascore = 0;
    int bscore = 0;
    process_score(a0, b0, ascore, bscore);
    process_score(a1, b1, ascore, bscore);
    process_score(a2, b2, ascore, bscore);
    vector<int> result;
    result.push_back(ascore);
    result.push_back(bscore);
    return result;
}

void process_score(int aVal, int bVal, int *ascore, int *bscore){
    if (aVal > bVal) ++ascore;
    if (bVal > aVal) ++bscore;
}

int main() {
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    vector < int > result = solve(a0, a1, a2, b0, b1, b2);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
