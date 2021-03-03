// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

// nが50

// nが小さいので
// 適当な二頂点の座標間のx、y方向の距離を計算できる(最大2500組)

// 2500組に対し全探索
// UnionFindの匂いがする

// UFなしでも行けるやろ（適当）

// __________
// サンプル２
// p1 = (1, 4)
// p2 = (4, 6)
// p3 = (7, 8)


// p1->p2 = (3, 2) p1->p3 = (6, 4)
// p2->p1 = (-3, -2) p2->p3 = (3, 2)
// p3->p1 = (-6, -4) p3->p2 = (-3, -2)

// (-3, -2)を選ぶと、p3->p2->p1を一気に取れる
//ゆうこうへんグラフっぽい？
//ゆうこうへんの本数分コストを減らせる？
int main(void){
    // Your code here!
    int n; cin >> n;
    vector <ll> x(n), y(n);
    rep(i ,n) cin >> x.at(i) >> y.at(i);
    
    //　距離計算
    vector <vector<ll>> d_x(n, vector<ll>(n)), d_y(n, vector<ll>(n));
    rep(i, n)rep(j, n){
        if(i == j) continue;
        // i -> j　の距離を求める
        d_x.at(i).at(j) = x.at(j) - x.at(i);
        d_y.at(i).at(j) = y.at(j) - y.at(i);
    }
    
    //　求めた距離のペアd_x、d_y全てについてコストを計算
    int ans = n;
    rep(_, n)rep(__, n){
        if(_ == __) continue;
        ll now_dx = d_x.at(_).at(__);
        ll now_dy = d_y.at(_).at(__);
        //cout << now_dx << " " << now_dy << endl;
        
        //うまいやり方分からないのでBFSします
        int cnt = 0;
        rep(i, n)rep(j, n){
            if(i == j) continue;
            if(now_dx == d_x.at(i).at(j) && now_dy == d_y.at(i).at(j)){
                cnt ++;
            }
        }
        
        ans = min(ans, n - cnt);
    }
    cout << ans << endl;
    
}
