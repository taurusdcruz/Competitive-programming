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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)



int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    ll t, n, k, max_diff;
    vll gar,tap;
    bool ending;
    cin>>t;
    rep(i1,0,t)
    {
        cin>>n>>k;
        gar.resize(n);
        tap.resize(k);



        cin>>tap[0];
        tap[0]-=1;
        max_diff=tap[0]+1, ending=true;

        for(ll i=1; i<k;i++)
        {
            cin>>tap[i];
            tap[i]-=1;
            if(abs(tap[i]-tap[i-1]+1) > max_diff) {max_diff=abs(tap[i]-tap[i-1]+1), ending=false; }


        }
        if(abs(n-1 - tap[k-1] +1 )> max_diff) max_diff=abs(n-1 - tap[k-1] +1 ), ending=true;

        if((max_diff%2 !=0) && (!ending)) max_diff+=1;
        ll res=(ending)?(max_diff):(max_diff/=2);

        cout<<((i1==0)?"":"\n")<<res;//<< " "<<max_diff<< " "<<ending;

    }
    return 0 ;
}
