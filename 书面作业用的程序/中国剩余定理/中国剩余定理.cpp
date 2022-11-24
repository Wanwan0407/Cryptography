#include<iostream>
#include<stdio.h>
using namespace std;
#define LL long long

/***********************************
中国剩余数定理
ai=x(mod mi)    求x
eg:1=x(mod 11) 2=x(mod 7)
最后求得为满足条件的最小值
************************************/
LL ex_gcd(LL a, LL b, LL& x, LL& y)
{
    if (b == 0)
    {
        x = 1; y = 0;
        return a;
    }
    LL r = ex_gcd(b, a % b, x, y);
    LL t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

///n个mi互质
const LL maxn = 20;
LL a[maxn], m[maxn], n;
LL CRT(LL a[], LL m[], LL n)
{
    LL M = 1;
    for (int i = 0; i < n; i++) M *= m[i];
    LL ret = 0;
    for (int i = 0; i < n; i++)
    {
        LL x, y;
        LL tm = M / m[i];
        ex_gcd(tm, m[i], x, y);
        ret = (ret + tm * x * a[i]) % M;
    }
    return (ret + M) % M;
}

///n个mi不互质
//const LL maxn = 1000;
//LL a[maxn], m[maxn], n;
//LL CRT(LL a[], LL m[], LL n) {
//    if (n == 1) {
//        if (m[0] > a[0]) return a[0];
//        else return -1;
//    }
//    LL x, y, d;
//    for (int i = 1; i < n; i++) {
//        if (m[i] <= a[i]) return -1;
//        d = ex_gcd(m[0], m[i], x, y);
//        if ((a[i] - a[0]) % d != 0) return -1;  //不能整除
//        LL t = m[i] / d;
//        x = ((a[i] - a[0]) / d * x % t + t) % t;
//        a[0] = x * m[0] + a[0];
//        m[0] = m[0] * m[i] / d;
//        a[0] = (a[0] % m[0] + m[0]) % m[0];
//    }
//    return a[0];
//}

int main()
{
    LL T;
    while (~scanf_s("%lld", &T))
    {
        for (int i = 0; i < T; i++) scanf_s("%lld%lld", &m[i], &a[i]);
        cout << CRT(a, m, T) << endl;
    }

}