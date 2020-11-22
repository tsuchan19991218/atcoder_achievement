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
    int n, x; cin >> n >> x;
    string s; cin >> s;
    int now = x;

    for(auto c: s){
        if(c == 'o'){
            now += 1;
        }
        else{
            now = max(0, now - 1);
        }

    }
    cout << now << endl;
}