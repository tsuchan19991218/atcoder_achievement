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
    string a, b; cin >> a >> b;
    int ans1, ans2; ans1 = ans2 = 0;
    for(auto c: a){
        ans1 += c - '0';
    }
    for(auto c: b){
        ans2 += c - '0';
    }
    cout << max(ans1, ans2) << endl;
}