
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
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
const LD EPS=1e-12;
const LD INF=1e100;
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)
#define ADJ(i1,i2,i3,delta,ad) ((i1==0 || i1% i3==0 )?SIGN(delta):ad)



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions
int main()
{
    freopen("inCHEGLOVE.txt","r",stdin);//redirects standard input
        //freopen("out.txt","w",stdout);//redirects standard output
    ll T,N;
    cin>>T;
    vll L, G;
    rep(i,0,T)
    {
        cin>>N;
        L.resize(N);
        G.resize(N);
        rep(i,0,N) cin>>L[i];
        rep(i,0,N) cin>>G[i];
        //cout<<"\n";print(L);
        //cout<<"\n";print(G);

        bool front=true, back=true;
        rep(i,0,N)
        {

            if(front && L[i]>G[i]) front=false;
            if(back && L[i]>G[N-1-i]) back=false;
            if(!front && !back) break;
        }
        //cout<<"\n"<<front<<back;
        cout<<((i==0)?"":"\n")<<((front && back) ?"both":front?"front":back?"back":"none");
    }

    return 0;



}
