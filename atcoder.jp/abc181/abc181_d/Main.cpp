#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

template <typename TYPE1, typename TYPE2>
void print_2(TYPE1 a, TYPE2 b){
    cout << a << " " << b << endl;
}

template <typename TYPE1, typename TYPE2>
void print_pair(pair <TYPE1, TYPE2> p){
    cout << p.first << " " << p.second << endl;
}

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

int main(){
    string s; cin >> s;
    if(s.size() < 3){
        // while(s.size() < 3){
        //     s = '0' + s;
        // }
        sort(s.begin(), s.end());
        do{
            int num = 0;
            int d = 1;
            for(int i = 0; i < s.size(); i ++){
                num += d * (s.at(s.size() - 1 - i) - '0');
                d *= 10;
            }
            if(num % 8 == 0){
                //cout << num << endl;
                cout << "Yes" << endl;
                return 0;
            }

        }while(next_permutation(s.begin(), s.end()));
        cout << "No" << endl;
        return 0;
    }
    vector <int> cnt(10);
    vector <vector <int>> div_8(0, vector<int>(10, 0));
    rep(i, 1000 / 8){
        int num = i * 8;
        //cout << num << endl;
        div_8.push_back(vector<int>(10, 0));
        int c = 3;
        while(c > 0){
            c --;
            //div_8.at(i).at(num%10) ++;
            div_8.back().at(num%10) ++;
            num /= 10;
        }
        for(auto n: div_8.back()){
            //cout << n << " ";
        }
        //cout << endl;
    }
    for(auto c: s){
        cnt.at(c - '0') ++;
    }

    bool flag = false;
    for(auto vec: div_8){
        bool _flag = true;
        for(int i = 0; i < 10; i ++){
            //cout << i << " ";
            //print_2(vec.at(i), cnt.at(i));
            if(vec.at(i) <= cnt.at(i)) continue;
            _flag = false;
        }
        if(_flag){
            flag = true;
            //for(auto num: vec) cout << num << " ";
        }
        // for(auto num: vec) cout << num << " ";
        //     cout << endl;
    }
    
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}