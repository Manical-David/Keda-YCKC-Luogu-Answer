#include <bits/stdc++.h>
#include <unistd.h>
const int MAX_NUM = 10000;
short cnt[MAX_NUM];
char buf[1 << 20];
int buf_ptr = 0;
inline void put_num(int x) {
    if (buf_ptr + 10 >= (1 << 20)) {
        write(1, buf, buf_ptr);
        buf_ptr = 0;
    }
    char tmp[10];
    int tmp_ptr = 0;
    if (x == 0) {
        tmp[tmp_ptr++] = '0';
    } else {
        while (x > 0) {
            tmp[tmp_ptr++] = x % 10 + '0';
            x /= 10;
        }
    }
    for (int i = tmp_ptr - 1; i >= 0; --i) {
        buf[buf_ptr++] = tmp[i];
    }
    buf[buf_ptr++] = ' ';
}
int main() {
    static char input[1 << 20];
    setvbuf(stdin, input, _IOFBF, 1 << 20);
    memset(cnt, 0, sizeof(cnt));
    int N;
    fscanf(stdin, "%d", &N);
    for (int i = 0; i < N; ++i) {
        int num;
        fscanf(stdin, "%d", &num);
        if (num >= 0 && num < MAX_NUM) {
            cnt[num]++;
        }
    }
    for (int i = 0; i < MAX_NUM; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            put_num(i);
        }
    }
    if (buf_ptr > 0) {
        if (buf_ptr > 0) buf_ptr--;
        write(1, buf, buf_ptr);
    }
    return 0;
}