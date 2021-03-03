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

const int mod = 1000000000 + 7;


// 全体　2^n通り？
// そこからa本の花束を作るパターンとb本のパターンを引く

// ans = 2^n - (nCa + nCb) ????

ll my_pow(ll x, ll n){
    ll ret = 1;
    while (n > 0) {
        if (n & 1){
            ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
            ret %= mod;
        }
        x *= x;
        x %= mod;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret %= mod;
}


int main(void){
    // Your code here!
    ll n, a, b; cin >> n >> a >> b;
    vector <ll> fac(300000), ifac(300000);
    fac.at(0) = 1;
    ifac.at(0) = 1;
    
    for(ll i = 1; i < 200000 + 5; i ++){
        fac.at(i) = i * fac.at(i-1) % mod;
        ifac.at(i) = my_pow(fac.at(i), mod-2); //逆元これだっけ
    }
    
    // (6!/3!) % mod = 120 
    
    // cout << fac.at(6) * ifac.at(3) % mod << endl;
    ll now = n;
    ll ue = 1;
    rep(i, a){
        ue *= now;
        ue %= mod;
        now --;
    }
    ll nCa = ue * ifac.at(a);
    nCa %= mod;
    
    now = n;
    ue = 1;
    rep(i, b){
        ue *= now;
        ue %= mod;
        now --;
    }
    ll nCb = ue * ifac.at(b);
    nCb %= mod;
    
    ll ans = my_pow(2, n) - nCa - nCb;
    while(ans < 0) ans += mod;
    ans %= mod;
    //cout << nCa << " " << nCb << endl;
    cout << ans - 1 << endl;
    
}
