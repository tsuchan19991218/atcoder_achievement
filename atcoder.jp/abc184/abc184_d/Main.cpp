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

    vector <vector<vector<double>>> p(105, vector(105, vector<double>(105, 0)));
    p.at(a).at(b).at(c) = 1;

    for(int i = a; i < 101; i ++){
        for(int j = b; j < 101; j ++){
            for(int k = c; k < 101; k ++){
                //if(i == 0 || j == 0 || k == 0) continue;
                if(i == a && j == b && k == c) continue;
                double pa = (double)(i - 1)/(double)(i + j + k - 1);
                double pb = (double)(j - 1)/(double)(i + j + k - 1);
                double pc = (double)(k - 1)/(double)(i + j + k - 1);
                //cout << i << " " << j << " " << k << endl;
                if(k != 0 && i != 100 && j != 100){
                    //cout << i << " " << j << " " << k-1 << " ";
                    //cout << p.at(i).at(j).at(k - 1) << endl;
                    p.at(i).at(j).at(k) += p.at(i).at(j).at(k - 1) * pc;
                }
                if(j != 0 && i != 100 && k != 100){
                    //cout << i << " " << j-1 << " " << k << " ";
                    //cout << p.at(i).at(j - 1).at(k) << endl;
                    p.at(i).at(j).at(k) += p.at(i).at(j - 1).at(k) * pb;
                }
                if(i != 0 && j != 100 && k != 100){
                    //cout << i-1 << " " << j << " " << k << " ";
                    //cout << p.at(i-1).at(j).at(k) << endl;
                    p.at(i).at(j).at(k) += p.at(i - 1).at(j).at(k) * pa;
                }
                //cout << p.at(i).at(j).at(k) << endl;
            }
        }
    }

    int first = a + b + c;
    double ans = 0;
    for(int i = 0; i < 100; i ++){
        for(int j = 0; j < 100; j ++){
            int cnt = (100 + i + j) - first;
            if(cnt < 0) continue;
            ans += p.at(100).at(i).at(j) * cnt;
            ans += p.at(i).at(100).at(j) * cnt;
            ans += p.at(i).at(j).at(100) * cnt;
        }
    }
    cout << fixed << setprecision(15) << ans << endl;
}