#include <bits/stdc++.h>
using namespace std;

#define  Infile               freopen("input.txt", "r", stdin)
#define  Outfile              freopen("output.txt", "w", stdout)
#define  show(a)              cerr<<"\n-> "<<#a<<" = "<<a<<endl
#define  ms(a, u)             memset(a, u, sizeof(a))
#define  mp(a,b)              make_pair(a, b)
#define  pb(x)                push_back(x)
#define  _                    <<", "<<
#define  endl                 '\n'

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

db const EPS  = DBL_EPSILON;
ll const INF  = LLONG_MAX;


//declare here
ll t, x, y, u, v;
ll ans = 0, w = 0, s = 0;

void Result()
{
	//code here
	cin >> t;
	while(t--)
	{
		cin >> x >> y >> u >> v;
		x = abs (x-u);
		y = abs(u-v);
		w = sqrt(x*x+y*y)
		if (w == 0) w = (abs(u-v) + abs (x-u))/2;
		if ((x+y) &1)
			cout << w  <<endl;
		else
			cout << w+1 << endl;
	}

}
	

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef HUYENCUTE
//		Infile;
//		Outfile;
	#endif
	Result();
	
	return 0;
}
