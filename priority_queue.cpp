#include <iostream>
#include <queue>
using namespace std;

struct Point {
    double x, y;
};

bool operator <(const Point &a, const Point &b) {
    return a.x < b.x || a.x == b.x && a.y > b.y;
}
    
int main() {
    priority_queue<Point> q;
    int T; cin >> T;
    while (T -- ) {
    	double x, y; cin >> x >> y;
    	q.push({x, y});
	}
    while (q.size()) {
        auto t = q.top();
        q.pop();
        cout << t.x << ' ' << t.y << endl;
    }
}
