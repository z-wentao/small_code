#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int inf = 999999;
int mp[N][N], path[N][N];
int n, m;
void print(int a, int b)
{
    if (path[a][b] == -1)
        return;                  //因为开始初始化为-1，这里就可以避免相邻的再次输出
    print(a, path[a][b]);        //前半部
    cout << path[a][b] << "-->"; //输出该点
    print(path[a][b], b);        //后半部
}
int main()
{
    cin >> n >> m;
    memset(path, -1, sizeof(path)); //初始化-1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                mp[i][j] = 0;
            else
                mp[i][j] = inf;
    while (m -- ) {
    	int x, y, d; cin >> x >> y >> d;
    	mp[x][y] = mp[y][x] = min(mp[x][y], d);
	}
    //三层循环
    for (int k = 0; k < n; k++)
    {
        //第k个点进行松弛
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mp[i][j] > mp[i][k] + mp[k][j]) //如果能够缩短就更新距离
                {
                    mp[i][j] = mp[i][k] + mp[k][j];
                    path[i][j] = k; //记录能松弛的点
                }
    }
    while (1) {
    	cout << "请输入起点" << endl;
		int a; cin >> a;
		cout << "请输入终点" << endl;
		int b; cin >> b; 
	    if (mp[a - 1][b - 1] == inf)
	    { //两者不通
	        cout << a << ' ' << b;
	        cout << " 这两点间没有通路\n\n";
	        continue;
	    }
	    cout << a << " 到 " << b << " 最短路长度是 " << mp[a - 1][b - 1] << endl;
	    cout << "这个最短路径为\n";
	    cout << a << "-->";
	    print(a - 1, b - 1);
	    cout << b << ' ';
	    cout << endl << endl;
	}
    
}
