#include <iostream>
#include <vector>
using namespace std;
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
        {
            f = -1;
        }
        c = getchar();
    }
    while (isdigit(c))
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

vector<int> a(const vector<int> &x, const vector<int> &y)
{
    vector<int> r;
    int c = 0, i = 0;
    while (i < x.size() || i < y.size() || c)
    {
        int s = c;
        if (i < x.size())
            s += x[i];
        if (i < y.size())
            s += y[i];
        r.push_back(s % 10);
        c = s / 10;
        i++;
    }
    return r;
}

vector<int> m1(const vector<int> &x, int b)
{
    vector<int> r;
    int c = 0;
    for (int i = 0; i < x.size() || c; i++)
    {
        long long p = c;
        if (i < x.size())
            p += (long long)x[i] * b;
        r.push_back(p % 10);
        c = p / 10;
    }
    return r;
}

vector<int> m2(const vector<int> &x, const vector<int> &y)
{
    vector<int> r(x.size() + y.size(), 0);
    for (int i = 0; i < x.size(); i++)
    {
        int c = 0;
        for (int j = 0; j < y.size() || c; j++)
        {
            long long p = r[i + j] + c;
            if (j < y.size())
                p += (long long)x[i] * y[j];
            r[i + j] = p % 10;
            c = p / 10;
        }
    }
    while (r.size() > 1 && r.back() == 0)
        r.pop_back();
    return r;
}

#define min(a, b) a < b ? a : b
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> f1 = {1}, f2 = {2}, j1 = {1}, j2 = {2}, f, j;
    vector<int> c;
    for (int i = 1; i < n; i++)
    {
        if (i == 1)
            c = m2(f1, j1);
        else if (i == 2)
            c = m2(f2, j2);
        else
        {
            f = a(f2, f1);
            j = m1(j2, i);
            f1 = f2;
            f2 = f;
            j2 = j;
        }
    }
    if (n == 1)
        c = m2(f1, j1);
    else if (n == 2)
        c = m2(f2, j2);
    else
        f = a(f2, f1), j = m1(j2, n), c = m2(f, j);
    bool is = 1;
    for (int i = min(99, (int)c.size() - 1); i >= 0; i--)
    {
        if (c[i] != 0)
        {
            is = 0;
            break;
        }
    }
    for (int i = min(99, (int)c.size() - 1); i >= 0; i--)
    {
        printf("%d", c[i]);
    }
    if (is)
    {
        printf("\n%d %d", c[c.size() - 1], c.size() - 1);
    }
    return 0;
}