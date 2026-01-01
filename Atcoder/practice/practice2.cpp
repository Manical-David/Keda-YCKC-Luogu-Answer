#include <bits/stdc++.h>
using namespace std;
char s[29], ans[29];
int cmp['Z' + 5]['Z' + 5];
int cnt = 0;
bool cmp_char(const char a, const char b)
{
    char cp;
    if (cmp[a][b] == -1)
    {
        printf("? %c %c\n", a, b);
        fflush(stdout);
        scanf(" %c", &cp);
        if (cp == '>')
        {
            cmp[a][b] = true;
            cmp[b][a] = false;
            return true;
        }
        else
        {
            cmp[a][b] = false;
            cmp[b][a] = true;
            return false;
        }
    }

    return cmp[a][b];
}
void sort_N5(char c)
{
    if (cmp_char(c, s[1]))
    {
        if (cmp_char(c, s[2]))
        {
            s[3] = c;
        }
        else
        {
            s[3] = s[2];
            s[2] = c;
        }
    }
    else
    {
        if (cmp_char(c, s[0]))
        {
            s[3] = s[2];
            s[2] = s[1];
            s[1] = c;
        }
        else
        {
            s[3] = s[2];
            s[2] = s[1];
            s[1] = s[0];
            s[0] = c;
        }
    }
}
void sort_N26(char c)
{
    int l = 0, r = cnt;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (cmp_char(c, ans[mid]))
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cnt++;
    if (cmp_char(c, ans[r]))
    {
        r++;
    }

    for (int i = cnt; i >= r + 1; i--)
    {
        ans[i] = ans[i - 1];
    }

    ans[r] = c;
}
int main() {
    int N, Q;
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < 26; i++)
    {
        s[i] = (char)(i + 'A');
    }
    s[N] = '\0';
    memset(cmp, -1, sizeof(cmp));
    if (N == 26)
    {
        cnt = 0;
        ans[0] = s[0];
        ans[N] = '\0';
        for (int i = 1; i < N; i++)
        {
            sort_N26(s[i]);
        }

        printf("! %s\n", ans);
    }
    else
    {
        if (cmp_char(s[0], s[1]))
        {
            swap(s[0], s[1]);
        }

        if (cmp_char(s[2], s[3]))
        {
            swap(s[2], s[3]);
        }

        if (cmp_char(s[1], s[3]))
        {
            swap(s[0], s[2]);
            swap(s[1], s[3]);
        }
        char tmp = s[2];
        if (cmp_char(s[4], s[1]))
        {
            if (cmp_char(s[4], s[3]))
            {
                s[2] = s[3];
            }
            else
            {
                s[2] = s[4];
                s[4] = s[3];
            }
        }
        else
        {
            if (cmp_char(s[4], s[0]))
            {
                s[2] = s[1];
                s[1] = s[4];
                s[4] = s[3];
            }
            else
            {
                s[2] = s[1];
                s[1] = s[0];
                s[0] = s[4];
                s[4] = s[3];
            }
        }
        sort_N5(tmp);
        printf("! %s\n", s);
    }
    return 0;
}