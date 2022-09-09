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
#define prall(arr) {cout<<"\n";for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(c,l,r) {cout<<"\n";for (auto b = next(c.begin(),l),i=b, e=next(c.begin(),r); i != e; ++i) cout << (*i) << " ";}
#define debug(m,x) cout <<"\n"<<(m)<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<< (x) << " " << (y) << " " << (z);
const LD EPS=1e-12;
const LD INF=1e100;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions

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

int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll T, X, N;

    cin>>T;

    rep(i,0,T)
    {
        cin>>N>>X;
        vector<pair<LD,LD> > SC(N);
        vector<pair<LD,LD> > RES(X,pair<LD,LD>(-1.0,-1.0));
        rep(i,0,N)
        {
            cin>>SC[i].first;
            SC[i].second=(LD)(i+1);


        }
        //sort(SC.begin(), SC.end(), greater<pair<LD,LD> >());
        //prall(SC);

        pair<LD,LD> sm(0.0, 0.0);
        pair<LD,LD> tsm(0.0, 0.0);
        pair<LD,LD> mxsm(0.0, 0.0);
        ll indx_mxsm;
        rep(i,0,X)
        {
            sm.first+=SC[i].first*SC[i].second;
            sm.second+=SC[i].second;
            RES[i]=SC[i];

        }
        rep(i,X,N)
        {

            mxsm=sm;
            indx_mxsm=-1;//index to replace to maximize
            rep(j,0,X)
            {

                tsm.first=sm.first - RES[j].first*RES[j].second +SC[i].first*SC[i].second ;
                tsm.second=sm.second -RES[j].second +SC[i].second;
                if(tsm.first*mxsm.second > tsm.second * mxsm.first) {mxsm=tsm; indx_mxsm=j;}
            }
            if(indx_mxsm!=)
            {
                sm=mxsm;
            }
        }
        cout<<setprecision(20)<<sm.first/sm.second;
        cout<<((i<=T-2)?"\n":"");

    }
	return 0 ;
}

