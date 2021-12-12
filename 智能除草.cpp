#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1010;
int s[1010][1010];
int n, k;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int x;
            cin >> x;
            s[i][j] += x + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int x1, y1;
            x1 = min(n, i + k - 1), y1 = min(n, j + k - 1);
        
            int tmp = s[x1][y1] - s[i - 1][y1] - s[x1][j - 1] + s[i - 1][j - 1];
            sum = max(sum, tmp);
		}
	cout << sum << endl;
}
