//시간 초과
 
#include <cstdio>
#include <vector>
using namespace std;
#define MAX_N 100001
/*
 * Time complexity: TODO
 * Space complexity: TODO
 */

vector<int>adj[MAX_N];
vector<int>edlist;
bool visited[MAX_N]= {false,};
bool connected[MAX_N]={false,};

int cnt = 0;
void dfs(int start)
{
	visited[start] = true;
	//connected[start] = true;
	for (int i=0; i < adj[start].size(); i++)
	{
		if (!visited[adj[start][i]])
		{
			dfs(adj[start][i]);
		}
	}
}

int main(void) {
    int N;
    scanf("%d", &N);
	//vector<int> temp;
    for (int i = 0; i < N; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
        
        edlist.push_back(x);
        edlist.push_back(y);
    }
	
	//printf("%d\n", edlist.size());
	for(int i=0; i<edlist.size(); i++)
	{
		int idx = edlist[i];
		if(!visited[idx])
		{
			dfs(idx);
			cnt++;
		}
		else
			continue;
	}
	
	printf("%d\n", cnt);
    return 0;
}

