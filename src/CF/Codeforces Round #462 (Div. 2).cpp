/*
ID: taurus1
TASK: ride
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
//#include <bigInt.h>

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector< vll > vvll;



template<class T> T abs(T x) { return x > 0 ? x : -x;}

const ll mod = 1000000000 + 7;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define MD(i) ((i) -(long long)(i))
//const LD EPS=1e-12;
//const LD INF=1e100;
const ll MN =-1000000000 -1;
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions

template <class T>
ll gcd(T a1, T b1) {

	T a=abs(a1), b=abs(b1);
	return b == 0 ? a : gcd(b, fmod(a, b));
}

int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    vll a,b;
    ll na, nb;
    ll mx_a1=MN, mx_a2=MN, mx_b=MN;
    cin >>na>>nb;
    a.resize(na);
    b.resize(nb);
    rep(i,0,na)
    {
        cin>>a[i];
        if(i==1)
        {
            sort(a.begin(), a. begin() + 2);
            mx_a1=a[1], mx_a2=a[0];
        }

        if(i >=2 && mx_a2< a[i] && mx_a1> =a[i]) mx_a2=a[i];
        else if(i >=2 && mx_a2< a[i] && mx_a1< a[i])mx_a2=mx_a1, mx_a1=a[i];

    }
    rep(i,0,nb)
    {
        cin>>b[i];
        if(mx_b< b[i]) mx_b=b[i];

    }


    cout<< mx_a2*mx_b;



	return 0 ;
}

