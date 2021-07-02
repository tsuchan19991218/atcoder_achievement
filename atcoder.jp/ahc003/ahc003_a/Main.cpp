#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

const int MOD =  INF;
long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % MOD;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x = x * x % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

struct Pos{
	int x;
	int y;
	bool operator==(const Pos& pos) const {
		return x == pos.x && y == pos.y;
	}
	bool operator!=(const Pos& pos) const {
		return x != pos.x || y != pos.y;
	}
};

vector <vector<double>> Edge_yoko(30, vector<double>(30, 10000));
vector <vector<double>> Edge_tate(30, vector<double>(30, 10000));
vector <vector<int>> seen(30, vector<int>(30, -1));
Pos start, goal, now;
string ans = "";

int DIST(Pos &P){
	return abs(P.x - goal.x) + abs(P.y - goal.y);
}

void move_to_gy(){
	while(now.y != goal.y){
		if(now.y < goal.y){
			ans += "D";
			now.y ++;
		}
		else{
			ans += "U";
			now.y --;
		}
	}
}
void move_to_gx(){
	while(now.x != goal.x){
		if(now.x < goal.x){
			ans += "R";
			now.x ++;
		}
		else{
			ans += "L";
			now.x --;
		}
	}
}
void move_to_sy(){
	if(now != goal){
		while(now.y != start.y){
			if(now.y < start.y){
				ans += "D";
				now.y ++;
			}
			else{
				ans += "U";
				now.y --;
			}
		}
	}
}
void move_to_sx(){
	if(now != goal){
		while(now.x != start.x){
			if(now.x < start.x){
				ans += "R";
				now.x ++;
			}
			else{
				ans += "L";
				now.x --;
			}
		}
	}
}
void move_1_gy(){
	if(now.y != goal.y){
		if(now.y < goal.y){
			ans += "D";
			now.y ++;
		}
		else{
			ans += "U";
			now.y --;
		}
	}
}
void move_1_gx(){
	if(now.x != goal.x){
		if(now.x < goal.x){
			ans += "R";
			now.x ++;
		}
		else{
			ans += "L";
			now.x --;
		}
	}
}
void naibun(double &x, double y){
	double a, b;
	a = 1; b = 1;
	x = (a*x + b*y) / (a + b);
}
void update(double output){
	double length = ans.size();
	double value = output / length;
	// reverse(ans.begin(), ans.end());
	now = start;
	for(auto c: ans){
		// cout << now.y << " " << now.x << endl;
		if(c == 'D'){
			naibun(Edge_tate.at(now.x).at(now.y), value);
			now.y ++;
		}
		if(c == 'U'){
			naibun(Edge_tate.at(now.x).at(now.y-1), value);
			now.y --;
		}
		if(c == 'R'){
			naibun(Edge_yoko.at(now.y).at(now.x), value);
			now.x ++;
		}
		if(c == 'L'){
			naibun(Edge_yoko.at(now.y).at(now.x-1), value);
			now.x --;
		}
	}
}
void ijk(){
	// P : pair<pair<double, pair<int, int>>, string>
	vector<vector<double>> distances(30, vector<double>(30, INF));
	distances.at(start.y).at(start.x) = 0;
	priority_queue<pair<pair<double, pair<int, int>>, string>, vector<pair<pair<double, pair<int, int>>, string>>, greater<pair<pair<double, pair<int, int>>, string>>> pq;
	pq.push(make_pair(make_pair(0.0, make_pair(start.y, start.x)),""));
	while (pq.size()){
		auto p = pq.top();
		pq.pop();
		string str = p.second;
		int vy = p.first.second.first;
		int vx = p.first.second.second;
		if(vy == goal.y && vx == goal.x){
			ans = str;
			break;
		}
		if(distances.at(vy).at(vx) < p.first.first) continue;
		// cout << start.y << " " << start.x << endl;
		// cout << str << endl;
		// cout << vy << " " << vx << endl;
		// cout << p.first.first << endl;
		rep(i, 4){
			int ny, nx;
			string nstr = str;
			ny = vy + dy[i];
			nx = vx + dx[i];
			if(ny < 0 || ny >= 30 || nx < 0 || nx >= 30){
				continue;
			}
			Pos P, N;
			P.y = vy; P.x = vx;
			N.y = ny; N.x = nx;
			// if(DIST(P) < DIST(N)) continue;
			if(dy[i] != 0){
				if (distances.at(ny).at(nx) > distances.at(vy).at(vx) + Edge_tate.at(vx).at(min(vy, ny))) {  // 最短距離候補なら priority_queue に追加
					distances.at(ny).at(nx) = distances.at(vy).at(vx) + Edge_tate.at(vx).at(min(vy, ny));
					// printf("%d %d から\n", start.y, start.x);
					// printf("%d %d までのパス -> %s\n", vy, vx, str.c_str());
					if(dy[i] == 1) nstr += "D";
					else nstr += "U";
					// printf("%d %d へ移動 -> %s\n", ny, nx, nstr.c_str());
					pq.push(make_pair(make_pair(distances.at(ny).at(nx), make_pair(ny, nx)), nstr));
				}
			}
			else{
				if (distances.at(ny).at(nx) > distances.at(vy).at(vx) + Edge_yoko.at(vy).at(min(vx, nx))) {  // 最短距離候補なら priority_queue に追加
					distances.at(ny).at(nx) = distances.at(vy).at(vx) + Edge_yoko.at(vy).at(min(vx, nx));
					// printf("%d %d から\n", start.y, start.x);
					// printf("%d %d までのパス -> %s\n", vy, vx, str.c_str());
					if(dx[i] == 1) nstr += "R";
					else nstr += "L";
					// printf("%d %d へ移動 -> %s\n", ny, nx, nstr.c_str());
					pq.push(make_pair(make_pair(distances.at(ny).at(nx), make_pair(ny, nx)), nstr));
				}
			}
		}
	}
}
void solve(int k){
	ans = "";
	if(k < 110){
		while(now != goal){
			// cout << now.y << " " << now.x << endl;
			if(k % 2 == 0){
				move_to_gy(); // goal と同じ高さまで移動
				move_1_gx(); // goal に向かう方向へ1横移動
				move_to_sy(); // start と同じ高さまで移動
				move_1_gx(); // goal に向かう方向へ1横移動
			}
			else{
				move_to_gx(); // goal と同じ高さまで移動
				//cout << now.y << " " << now.x << endl;
				move_1_gy(); // goal に向かう方向へ1横移動
				//cout << now.y << " " << now.x << endl;
				move_to_sx(); // start と同じ高さまで移動
				//cout << now.y << " " << now.x << endl;
				move_1_gy(); // goal に向かう方向へ1横移動
			}
		}
		printf("%s\n", ans.c_str());
		fflush(stdout);
		double output; cin >> output;
		update(output); // 辺の重みを上書き
	}
	else{
		ijk();
		printf("%s\n", ans.c_str());
		fflush(stdout);
		double output; cin >> output;
		update(output); // 辺の重みを上書き
	}
}


int main(){
	for(int k = 0; k < 1000; k ++){
		cin >> start.y >> start.x >> goal.y >> goal.x;
		now = start;
		solve(k);
	}
}