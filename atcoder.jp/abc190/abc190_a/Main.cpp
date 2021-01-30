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
    int a, b, c; cin >> a >> b >> c;

    if(c == 0){
        if(a > b){
            cout << "Takahashi" << endl;
        }
        else{
            cout << "Aoki" << endl;
        }
    }
    if(c == 1){
        if(a < b){
            cout << "Aoki" << endl;
        }
        else{
            cout << "Takahashi" << endl;
        }
    }
}