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
    vector <pair<int, int>> x_y(n);
    rep(i, n){
        int x, y; cin >> x >> y;
        x_y.at(i) = make_pair(x, y);
    }
    sort(x_y.begin(), x_y.end());
    
    bool flag = false;
    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j ++){
            for(int k = j + 1; k < n; k ++){
                int x1, x2, x3;
                x1 = x_y.at(i).first;
                x2 = x_y.at(j).first;
                x3 = x_y.at(k).first;

                int y1, y2, y3;
                y1 = x_y.at(i).second;
                y2 = x_y.at(j).second;
                y3 = x_y.at(k).second;

                if((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3)){
                    flag = true;
                    continue;
                }

                if((y2 - y1) * (x3 - x2) == (x2 - x1) * (y3 - y2)){
                    flag = true;
                }
            }
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}