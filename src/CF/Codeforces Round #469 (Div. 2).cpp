
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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " ";
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
const LD EPS=1e-12;
const LD INF=1e100;


template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions


    bool cbc(ll i, ll l, ll r)
    {

        return (i<=r && i>=l);
    }


int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll n, m;
    cin>>n>>m;
    vll nn(n),mm(m);
    rep(i,0,n) cin>> nn[i];
    rep(i,0,m) cin>> mm[i];

    cout<<"\n";print(nn);
    cout<<"\n";print(mm);

    vector< pll > dbg1;
    vector< pair< pll, pll > > dbg;

    ll in=0, im=0;
    ll sn=0, sm=0;
    ll cnt=0;
    ll zero=0;
    bool flgn=true, flgm=true;
    while(flgn || flgn )
    {
        //cout<<"\n cbc(in,im)=("<<cbc(in+1,0,n-1)<< ", "<<cbc(im+1,0,m-1)<<")";
        sn+=nn[in], sm+=mm[im];

        while(sn<sm )
        {
            cout<<"\n !E | S("<<sn<<","<<sm<<") cnt="<<cnt<<"\n\t I("<<in<<","<<im<<")";
            if(cbc(in+1,0,n-1))
            {
                dbg.push_back(pair<pll, pll >(pll(in,im), pll(sn,sm)));
                in+=1;
                sn+=nn[in];
            }
            else
            {
                flgn=false;break;
            }
        }
        while(sn>sm)
        {
            cout<<"\n !E | S("<<sn<<","<<sm<<") cnt="<<cnt<<"\n\t I("<<in<<","<<im<<")";
            if(cbc(im+1,0,m-1))
            {
                dbg.push_back(pair<pll, pll >(pll(in,im), pll(sn,sm)));
                im+=1;sm+=mm[im];
            }
            else
            {
                flgm=false;break;
            }
        }
        while(sn==sm)
        {
            cout<<"\n E | S"<<sn<<" cnt="<<cnt<<"\n\t I("<<in<<","<<im<<")";
            cnt+=1;
            dbg1.push_back(pll(in,im));
            dbg.push_back(pair<pll, pll >(pll(in,im), pll(sn,sm)));

            if(cbc(in+1,0,n-1))
            {
                dbg.push_back(pair<pll, pll >(pll(in,im), pll(sn,sm)));
                in+=1;
                sn+=nn[in];
            }
            else
            {
                flgn=false;break;
            }
            if(cbc(im+1,0,m-1))
            {
                dbg.push_back(pair<pll, pll >(pll(in,im), pll(sn,sm)));
                im+=1;sm+=mm[im];
            }
            else
            {
                flgm=false;break;
            }
        }

    }

    cout<<"\n";print(dbg1);
    cout<<"\n";print(dbg);
    cout<<cnt;
	return 0 ;
}

