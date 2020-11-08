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
    int h, w, n, m; cin >> h >> w >> n >> m;
    // pair <int, int> a_b(n);
    // pair <int, int> c_d(m);

    vector <vector<char>> s(h, vector(w, '.'));

    rep(i, n){
        int a, b; cin >> a >> b;
        a--; b--;
        //a_b.at(i) = make_pair(a, b);
        s.at(a).at(b) = 'o';
    }
    rep(i, m){
        int c, d; cin >> c >> d;
        c--; d--;
        //c_d.at(i) = make_pair(c, d);
        s.at(c).at(d) = '#';
    }

    vector <vector<int>> lighted(h, vector(w, -1));
    vector <vector<int>> not_yoko(h, vector(w, -1));
    vector <vector<int>> not_tate(h, vector(w, -1));


    int ans = 0;
    for(int y = 0; y < h; y ++){
        for(int x = 0; x < w; x ++){
            //if(lighted.at(y).at(x) == 1) continue;
            if(s.at(y).at(x) != 'o') continue;
            
            if(not_yoko.at(y).at(x) == -1){
                int r_index = x;
                //bool flag = false;
                for(int nx = x; nx < w; nx++){
                    if(s.at(y).at(nx) == '#') break;
                    //if(s.at(y).at(nx) == 'o') flag = true;
                    r_index = nx;
                    if(lighted.at(y).at(nx) == 1) continue;
                    lighted.at(y).at(nx) = 1;
                    ans ++;
                    not_yoko.at(y).at(nx) = 1;
                }
                int l_index = x;
                for(int nx = x; nx >= 0; nx--){
                    if(s.at(y).at(nx) == '#') break;
                    l_index = nx;
                    if(lighted.at(y).at(nx) == 1) continue;
                    lighted.at(y).at(nx) = 1;
                    ans ++;
                    not_yoko.at(y).at(nx) = 1;
                }
                // for(int nx = l_index; nx <= r_index; nx++){
                //         if(lighted.at(y).at(nx) == 1) continue;
                //         lighted.at(y).at(nx) = 1;
                //         ans ++;
                //         not_yoko.at(y).at(nx) = 1;
                //         //cout << y << " " << nx << endl;
                // }
            }
            if(not_tate.at(y).at(x) == -1){
                for(int ny = y; ny < h; ny++){
                    if(s.at(ny).at(x) == '#') break;
                    //if(s.at(y).at(nx) == 'o') flag = true;
                    if(lighted.at(ny).at(x) == 1) continue;
                    lighted.at(ny).at(x) = 1;
                    ans ++;
                    not_tate.at(ny).at(x) = 1;
                }
                int l_index = x;
                for(int ny = y; ny >= 0; ny--){
                    if(s.at(ny).at(x) == '#') break;
                    if(lighted.at(ny).at(x) == 1) continue;
                    lighted.at(ny).at(x) = 1;
                    ans ++;
                    not_tate.at(ny).at(x) = 1;
                }
            }
        }
    }
    cout << ans << endl;
}