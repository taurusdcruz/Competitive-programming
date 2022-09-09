/*
ID: taurusd1
TASK: palsquare
LANG: C++14
*/

#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

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

const ll mod = (ll)(1e9 + 7);
const LD PI =(LD)acos(-1);
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define repc(c,i,l,r) for (auto b = next(c.begin(),(l)),i=b, e=next((c).begin(),(r)); i!=e; ++i)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(m,arr) {cout<<"\n"<<(m); for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m);for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}
#define debug(m,x) cout <<"\n"<<(m)<<#x<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<<#x << ", "<<#y<<"| "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<<" "<<#x<<", "<<#y<<", "<<#z<<"| "<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<#w<<", "<<#x<<", "<<#y<<", "<<#z<<"| "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
#define _(x) cout <<"\n"<< (#x) <<" "<< (x) ;

int main ( )
{
	freopen("palsquare.in","r",stdin);//redirects standard input
    freopen("palsquare.out","w",stdout);//redirects standard output
    ll B;
    cin>>B;
    vll d;
    vector<char> cd;
    vll nsq;
    auto f1=
    [](ll di)
    {
        if(di>9)
            return (di-10+'A');
        else
            return ('0'+di);
    };
    rep(i,0,20) d.pb(f1(i));
    rep(i,0,d.size())
    {
        cd.pb((char)d[i]);
    }
    //debug("",d)
    //debug("",cd)
    vector<pair<vector<char>,vector<char> > > res;

    auto f=
    [=,&f1, &res](ll n)
    {
        ll ns=n*n;
        pair<vector<char>,vector<char> > tmp;
        vector<char> nB,nsB;



        while(ns)
        {
            nsB.pb((char)f1(ns%B));
            ns/=B;
        }
        auto rnsB=nsB;
        reverse(all(nsB));
        //debug("",nsB)


        if(rnsB==nsB)
        {
            while(n)
            {
                nB.pb((char)f1(n%B));
                n/=B;
            }
            reverse(all(nB));
            tmp={nB,nsB};

            res.push_back(tmp);
        }
    };
    rep(i,1,301) f(i);
    //debug("",res)
    rep(i,0,res.size())
    {
        rep(j,0,res[i].first.size()){ cout<<res[i].first[j];}cout<<" ";
        rep(j,0,res[i].second.size()){ cout<<res[i].second[j];}cout<<endl;
    }
	return 0;
}

