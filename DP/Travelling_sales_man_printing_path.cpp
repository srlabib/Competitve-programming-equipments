#include <bits/stdc++.h>
using namespace std;

#define N 10
int mem[N][1 << N];
int w[N][N];
int parent[N][1 << N];

const int INF = 1e8;
// -1 means ifinity
int TSP(int i, int mask, int n)
{
	if (mask == (1 << n) - 1)
	{
		if (w[i][0] == -1)
			return 10000000;
		return w[i][0];
	}

	if (mem[i][mask] != -1) return mem[i][mask];

	int ans = INF;

	for (int j = 0; j < n; j++)
	{
		if (w[i][j] == -1) continue;
		if ((mask &(1 << j)) == 0)
		{
			int result = TSP(j, (mask | (1 << j)), n) + w[i][j];
			if (result < ans)
			{
				ans = result;
				parent[i][mask] = j;
			}
		}
	}

	return mem[i][mask] = ans;
}

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) w[i][j] = -1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < (1 << N); j++)
		{
			parent[i][j] = -1;
			mem[i][j] = -1;
		}

	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		w[a][b] = c;
	}

	cout << TSP(0, 1, n) << endl;
	vector<int> path;
	int indx = 0, mask = 1, res = INF;

	path.push_back(indx);
	while (parent[indx][mask] != -1)
	{
		indx = parent[indx][mask];
		path.push_back(indx);
		mask |= (1 << indx);
	}

	for (auto e: path) cout << e << " ";
	cout << "\n";

}
