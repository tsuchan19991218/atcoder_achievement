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
    int a, b; cin >> a >> b;
    int w; cin >> w;
    w *= 1000;

    if(w < a){
        cout << "UNSATISFIABLE" << endl;
        return 0;
    }

    bool flag = false;
    for(int i = a; i <= b; i ++){
        if(a <= w % i && w % i <= b) flag = true;
        if(w % i == 0) flag = true;

    }
    if(!flag){
        cout << "UNSATISFIABLE" << endl;
        return 0;
    }

    cout << (w + b - 1) / b << " ";
    cout << (w) / a << endl;
}