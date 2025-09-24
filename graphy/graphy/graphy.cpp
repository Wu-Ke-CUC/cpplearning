#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int graphy[7][7] = {
    //A B C D E F G
/*A*/{0,0,1,1,0,1,0},
/*B*/{0,0,1,0,0,0,0},
/*C*/{1,1,0,1,0,0,0},
/*D*/{1,0,1,0,0,0,0},
/*E*/{0,0,0,0,0,0,1},
/*F*/{1,0,0,0,0,0,1},
/*G*/{0,0,0,0,1,1,0},
};
bool isPutStack[7] = { 0 };
//栈实现
void DFS1()
{
    stack<int> s;
    s.push(0);
    isPutStack[0] = 1;
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        cout << char(temp + 'A');
        for (int i = 0; i < 7; i++)
        {
            if (graphy[temp][i] == 1 && !isPutStack[i])
            {
                s.push(i);
                isPutStack[i] = 1;
            }
        }
    }
}
//递归实现
int maxDepth = 0;
void DFS2(int begin, int depth = 1)
{
    isPutStack[begin] = 1;
    maxDepth = max(maxDepth, depth);
    cout << char(begin + 'A');
    for (int i = 0; i < 7; i++)
    {
        if (graphy[begin][i] == 1 && !isPutStack[i])
        {
            DFS2(i, depth + 1);
        }
    }
}
//广度优先搜索
struct node1
{
    int index;
    int layer;
};
void DFS3()
{
    //queue<int> q;
    queue<node1> q;
    q.push(node1{0,1});
    isPutStack[0] = 1;
    while (!q.empty())
    {
        node1 temp = q.front();
        maxDepth = max(maxDepth, temp.layer);
        q.pop();
        cout << char(temp.index + 'A');
        for (int i = 0; i < 7; i++)
        {
            if (graphy[temp.index][i] == 1 && !isPutStack[i])
            {
                q.push(node1{ i,temp.layer + 1 });
                isPutStack[i] = 1;
            }
        }
    }
}
//迷宫案例深搜
char maze[101][101];
bool vis[101][101];
int n, m;
int sx, sy, fx, fy;
bool flag = false;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int depth = 0;
void DFS4(int x, int y,int dep = 0)
{
    if (x == fx && y == fy)
    {
        flag = true;
        depth = max(depth, dep);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int bx = x + dx[i], by = y + dy[i];
        if (bx < 0 || bx >= n || by < 0 || by >= m)continue;
        if (maze[bx][by] == '*')continue;
        if (vis[bx][by])continue;
        vis[bx][by] = 1;
        DFS4(bx, by, dep + 1);
    }
}
//广搜
struct node2
{
    int x, y, dep;
};
void BFS(int sx,int sy)
{
    queue<node2> q;
    q.push(node2{ sx ,sy ,0 });
    while (!q.empty())
    {
        node2 temp = q.front();
        q.pop();
        if (temp.x == fx && temp.y == fy)
        {
            flag = true;
            depth = temp.dep;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int bx = temp.x + dx[i], by = temp.y + dy[i];
            if (bx < 0 || bx >= n || by < 0 || by >= m)continue;
            if (maze[bx][by] == '*')continue;
            if (vis[bx][by])continue;
            vis[bx][by] = 1;
            q.push(node2{ bx ,by ,temp.dep + 1 });
        }
    }
}
int main()
{
    //DFS1();
    //DFS2(0);
    //DFS3();
    //cout << endl << maxDepth;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'S')
            {
                sx = i, sy = j;
            }
            if (maze[i][j] == 'F')
            {
                fx = i, fy = j;
            }
        }
    }
    vis[sx][sy] = 1;
    //DFS4(sx, sy);
    BFS(sx, sy);
    cout << (flag ? "Yes" : "No") << endl;
    cout << depth;
    return 0;
}