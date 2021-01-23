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
    int n; cin >> n;
    vector <string> s(n+1);
    rep(i, n) cin >> s.at(i);

    reverse(s.begin(), s.end());
    vector <ll> x_0(n+1), x_1(n+1), y_0(n+1), y_1(n+1);

    y_1.at(0) = 1;
    for(int i = 1; i <= n; i ++){
        if(s.at(i) == "OR"){
            y_1.at(i) += y_1.at(i-1) * 2;
            y_0.at(i) += (y_1.at(i-1) * 1) + (y_0.at(i-1) * 1);
        }
        else{
            y_1.at(i) += (y_1.at(i-1) * 1) + (y_0.at(i-1) * 1);
            y_0.at(i) += (y_1.at(i-1) * 0) + (y_0.at(i-1) * 2);
        }
        //cout << y_1.at(n) + y_0.at(n) << endl;
    }
    cout << y_1.at(n) + y_0.at(n) << endl;
}