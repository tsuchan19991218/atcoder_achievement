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
    int v, t, s, d; cin >> v >> t >> s >> d;

    if(v * t <= d && v * s >= d){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl; 
}