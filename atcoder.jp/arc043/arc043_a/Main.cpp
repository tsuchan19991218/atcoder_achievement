 #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
	int n, a, b; cin >> n >> a >> b;
	vector <ll> s(n);
	ll sum = 0;
	rep(i, n){
		cin >> s.at(i);
		sum += s.at(i);
	}
	double avr = (double)sum / (double)n; 
	sort(s.begin(), s.end());
	ll dist = abs(s.at(0) - s.at(n - 1));
  	if(dist == 0){
      cout << -1 << endl;
      return 0;
    }
  	double ans1 = (double)b / (double)dist;
	//double ans1 = (double)(a - b) / (double)(avr - dist);
	double ans2 = (double)a - (avr * ans1);
  
  //cout << avr << " " << dist << endl;

	printf("%.10lf %.10lf\n", ans1, ans2);
}