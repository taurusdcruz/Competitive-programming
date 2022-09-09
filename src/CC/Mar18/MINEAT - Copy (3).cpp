
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


//Overriding < operator
template< class T, class U >
 bool operator<(const pair<T,U>& a, const pair<T,U>& b)
{
  if (a.first < b.first) return true;
  else if ( (a.first == b.first) && (a.second < b.second) ) return true;
  else return false;
}

//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}

ll time(ll pilelen,ll k)
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

ll ttime(vector< pair<ll,ll> > &ac, ll k)
{
    ll tt=0;
    rep(i,0,ac.size())
    {
        tt+= ac[i].second * time(ac[i].first, k);
    }
    return tt;
}
ll calcbix(vector< pair<ll,ll> > &ac, ll bixl, ll k)
{
    rep(i,bixl,ac.size())
    {
        if(ac[i].first>=k ) {return i;}
    }
}


int main()
{
    freopen("inMINEAT.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll T, N, H;
    ll res;
    cin>> T;
    vll a;
    //vector of pairs(val, cnt)
    vector< pair<ll,ll> > ac;
    // vector of time(ttime , k)
    set< pair<ll,ll> > rs;


    ll tt, k;
    ll kl, kr;
    ll ttl, ttr;
    ll bix, bixl,bixr;
    ll tot;
    rep(i,0,T)
    {
        cin>>N>>H;
        /*
        cout<<"\n\n"<<N<<" "<<H;
        */

        //init
        a.resize(N);
        ac.resize(0);
        // total, timetaken, time taken kl, timetaken r , begin indx, begin indxl, begin indxr
        tot=0;
        tt=0, ttl=0, ttr=0;
        bix=0, bixl =0, bixr=N-1;

        rep(i,0,N)
        {
            cin>>a[i];
            tot+= a[i];
        }


        sort(a.begin(), a.end());
        ll j=-1;
        rep(i,0,N)
        {
            if(j==-1 ||ac[j].first!=a[i]) {ac.push_back(pair<ll,ll>(a[i],1));j++;}
            else if(ac[j].first==a[i]) ac[j].second +=1;
        }
        /*
        print(ac);
        */
        //calculating initial value of bixl

        k=1;
        // calculating the initial value of bixr, kl, kr, k, bix
        kl= 1;
        kr=(*(ac.rbegin())).first +1;
        k=(kl+kr)/2;

        /*
        debug("tt/H",tot/H);
        debug3("k", k, kl, kr)
        debug3("bix",bix, bixl, bixr);
        */

        while(kl<kr)
        {
            tt=ttime(ac,k);

            if(tt<=H)
            {
                /*
                debug3("\ttt<=H,tt,k",(tt<H),tt,k);
                */
                kr=k;

            }
            else if(tt>H)
            {

                /*
                debug3("\ttt>H,tt,k",(tt>H),tt,k);
                */
                kl=k+1;
            }

            k= (kl +kr)/2;\
            /*
            debug3("\tk", k, kl, kr)
            debug3("\tbix",bix,bixl, bixr);
            */
        }

        cout<<((i==0)?"":"\n")<<kl;
    }

    return 0;



}
