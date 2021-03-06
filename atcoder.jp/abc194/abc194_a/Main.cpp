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
    int a, b;
    cin >> a >> b;
    if(a + b >= 15 && b >= 8){
        cout << "1" << endl;
        return 0;
    }
    if(a + b >= 10 && b >= 3){
        cout << "2" << endl;
        return 0;
    }
    if(a + b >= 3){
        cout << "3" << endl;
        return 0;
    }
    cout << "4" << endl;

}