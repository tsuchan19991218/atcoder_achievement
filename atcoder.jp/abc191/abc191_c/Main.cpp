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
    int h, w; cin >> h >> w;
    vector <string> s(h);
    rep(i, h){
        cin >> s.at(i);
    }

    vector <vector <int>> ue(h, vector<int>(w));
    vector <vector <int>> sita(h, vector<int>(w));
    vector <vector <int>> migi(h, vector<int>(w));
    vector <vector <int>> hidari(h, vector<int>(w));
    int ans = 0;
    for(int i = 1; i < h-1; i ++){
        for(int j = 1; j < w-1; j ++){
            if(s.at(i).at(j) == '.')continue;

            if(s.at(i-1).at(j) == '.'){
                ue.at(i).at(j) = 1;
                if(ue.at(i).at(j-1) != 1){
                    ans ++;
                }
            }
            if(s.at(i+1).at(j) == '.'){
                sita.at(i).at(j) = 1;
                if(sita.at(i).at(j-1) != 1){
                    ans ++;
                }
            }

            if(s.at(i).at(j-1) == '.'){
                hidari.at(i).at(j) = 1;
                if(hidari.at(i-1).at(j) != 1){
                    ans ++;
                }
            }
            if(s.at(i).at(j+1) == '.'){
                migi.at(i).at(j) = 1;
                if(migi.at(i-1).at(j) != 1){
                    ans ++;
                }
            }
        }
    }

    cout << ans << endl;

    /*vector <vector<int>> grid(h+1, vector<int>(w+1, 0));
    rep(i, h)rep(j, w){
        if(s.at(i).at(j) == '#'){
            grid.at(i).at(j) = 1;
            grid.at(i).at(j+1) = 1;
            grid.at(i+1).at(j) = 1;
            grid.at(i+1).at(j+1) = 1;
        }
    }*/
}