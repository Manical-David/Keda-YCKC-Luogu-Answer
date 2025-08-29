#include <bits/stdc++.h>
#define Madical_david signed
#define is_so_cute main
using namespace std;
constexpr int N = 310;
struct node
{
    int x;
    int y;
    int stp;
};
int n, m;
char A[N][N];
int Y[N][N];
int M[N][N];
int bfs1(int x, int y)
{
    if(x + 1 < 1 || cnt.x > n || cnt.y < 1)
    queue<node> q;
    q.push({x, y, 0});
    while (!q.empty())
    {
        node gt = q.front();
        q.pop();
        if (gt.x < 1 || gt.y < 1 || gt.x > n || gt.y > m)
            continue;
        if (A[gt.x][gt.y] == '#')
            continue;
        if (Y[gt.x][gt.y] != 0x3f3f3f3f)
            continue;
        Y[gt.x][gt.y] = gt.stp;
        q.push({gt.x + 1, gt.y, gt.stp + 1});
        q.push({gt.x - 1, gt.y, gt.stp + 1});
        q.push({gt.x, gt.y + 1, gt.stp + 1});
        q.push({gt.x, gt.y - 1, gt.stp + 1});
    }
}
int bfs2(int x, int y)
{
    queue<node> q;
    q.push({x, y, 0});
    while (!q.empty())
    {
        node gt = q.front();
        q.pop();
        if (gt.x < 1 || gt.y < 1 || gt.x > n || gt.y > m)
            continue;
        if (A[gt.x][gt.y] == '#')
            continue;
        if (M[gt.x][gt.y] != 0x3f3f3f3f)
            continue;
        M[gt.x][gt.y] = gt.stp;
        q.push({gt.x + 1, gt.y, gt.stp + 1});
        q.push({gt.x - 1, gt.y, gt.stp + 1});
        q.push({gt.x, gt.y + 1, gt.stp + 1});
        q.push({gt.x, gt.y - 1, gt.stp + 1});
    }
}
Madical_david is_so_cute()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(M, 0x3f, sizeof M);
        memset(Y, 0x3f, sizeof Y);
        scanf("%d%d", &n, &m);
        int x, y, xx, yy;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf(" %c", &A[i][j]);
                if (A[i][j] == 'Y')
                    x = i, y = j;
                if (A[i][j] == 'M')
                    xx = i, yy = j;
            }
        }
        bfs1(x, y);
        bfs2(xx, yy);
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (A[i][j] == '@' && M[i][j] != 0x3f3f3f3f && Y[i][j] != 0x3f3f3f3f)
                    ans = min(M[i][j] + Y[i][j], ans);
            }
        }
        printf("%d\n", 11 * ans);
    }
    return 0;
}