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
    int x, y; cin >> x >> y;
    if(max(x, y) < min(x, y) + 3){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}