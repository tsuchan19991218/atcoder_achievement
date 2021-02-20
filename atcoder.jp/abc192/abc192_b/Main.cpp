#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

int main(){
    string s; cin >> s;

    bool flag = true;
    for(int i = 0; i < s.size(); i ++){
        auto c = s.at(i);
        bool komoji = false;
        if(c >= 'a' && c <= 'z') komoji = true;

        if(i % 2 == 0 && !komoji) flag = false;
        if(i % 2 == 1 && komoji) flag = false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}