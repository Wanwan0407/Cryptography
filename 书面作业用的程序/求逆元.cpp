#include <stdio.h>
using namespace std;
typedef long long ll;
 void exgcd(ll a, ll b, ll & d, ll & x, ll & y) {
	     if (!b) { d = a; x = 1; y = 0; }
	     else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
	
} 
 ll inv(ll a, ll p) {
	    ll d, x, y;
     exgcd(a, p, d, x, y);
	    return d == 1 ? (x + p) % p : -1;
	
}
 int main()
 {
	 printf("%s\n", "����Ԫ��");
	     ll a, p;
	     while (1) {
			 printf("%s", "����������ģ����");
	        scanf_s("%lld %lld", &a, &p);
		    printf("%lld\n", inv(a, p));
		
	}


	 }