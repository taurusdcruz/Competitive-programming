
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



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
struct frstlst
{
    ll f,l;
    public:
   void  assgn(ll x,ll y)
    {
       f=x,l=y;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions


int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll T, Q;
    string A, B;
    vll chst(26,0);
    vll init(26,0);
    vector< frstlst >  Bfl(26,{0,0});
    ll c1, x, l, r;
    char y;
    cin>>T;

    rep(i,0,T)
    {
        cin>>A>>B;
        cin>>Q;
        chst=init;
      //make char set of A from l to r
        tr(A,i)
        {
            chst[*i-'a']+=1;
        }
        rep(i,0,Q)
        {

              if(c1==1)
              {
                  cin>> c1>>x>>y;
                  if(A[x-1] !=y)
                  {
                      chst[A[x-1] -'a']-=1;
                      chst[y-'a']+=1;
                      A[x-1]=y;
                  }
              }
              else if(c1==2)
              {
                  cin>> c1>>x>>y;
                  if(B[x-1] !=y)
                  {
                      B[x-1]=y;
                  }
              }
              else if(c1==3)
              {
                  tr(B,i){}
              }

        }
    }
	return 0 ;
}

