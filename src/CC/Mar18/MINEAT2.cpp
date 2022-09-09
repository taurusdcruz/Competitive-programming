
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
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) cout<<"\n"; for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " ";
#define debug(m,x) cout <<"\n"<<m<< x;
#define debug2(m,x,y) cout <<"\n"<<m<<" "<< x << " " << y;
#define debug3(m,x,y,z) cout <<"\n"<<m<< x << " " << y << " " << z;
const LD EPS=1e-12;
const LD INF=1e100;
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}


class sol
{
    vector< pair<ll,ll> > ac;
    ll bix;
    ll k;

public:

    ll time(ll pilelen, ll k)
    {
        return (pilelen/k +((pilelen%k ==0)?0:1) );
    }
    ll ttime(vector< pair<ll,ll> > &ac, ll bix, ll k)
    {
        ll tt=bix;
        rep(i,bix,ac.size())
        {
            tt+= ac[i].second * time(ac[i].first, k);
        }
        return tt;
    }
    ll calcbix(vector< pair<ll,ll> > &ac,ll bix, ll k)
    {
        rep(i,bix,ac.size())
        {
            if(ac[i].first>=k ) {return i;}
        }
        return -1;
    }


};
int main()
{
    freopen("inMINEAT.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll T, N, H;
    cin>> T;
    //a(duplicate), au(unique)
    vll a;
    vll ak;
    //vector of pairs(val, cnt)
    vector< pair<ll,ll> > ac;

    ll tot,tt, k;
    ll bix;
    rep(i,0,T)
    {
        cin>>N>>H;
        a.resize(N);
        ac.resize(0);


        tot=0;
        bix=0;

        rep(i,0,N)
        {
            cin>>a[i];
            tot+= a[i];
        }
        sort(a.begin(),a.end());

        ll j=-1;
        rep(i,0,N)
        {
            if(j==-1 ||ac[j].first!=a[i]) {ac.push_back(pair<ll,ll>(a[i],1));j++;}
            else if(ac[j].first==a[i]) ac[j].second +=1;
        }
        /*
        print(a);
        print(ac);
        print(au);
        */
        ak.resize(a[N-1]);
        rep(i,0,a[N-1]) ak[i]=i+1;

        upper_bound(ak.begin(),ak.end(),ttime(ac,bix,N,k)<=H)
        bix=calcbix(ac,bix,k);

        bool flg=true;
        while(flg)
        {
            tt=ttime(ac,bix,k);
            if(tt<=H) flg=false; else k+=1;
        }

        cout<<"\n"<<k;
    }

    return 0;



}
