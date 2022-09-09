
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

template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}

template< class T, class U >
 pair<T,U> operator/( pair<T,U>& a, const pair<T,U>& b)
{
    a.first/=b.first;
    a.second/=b.second;
    return a;
}


template< class T, class U >
 pair<T,U> operator*(pair<T,U>& a, const pair<T,U>& b)
{
    a.first*=b.first;
    a.second*=b.second;
    return a;
}

template< class T >
ll gcdp(pair<T,T> &a)
{
   return  __gcd((ll)(a.first) ,(ll)(a.second));
}

template< class T, class U >
 pair<T,U> operator+(const pair<T,U>& a, const pair<T,U>& b)
{
    pll res(a.first*b.second + b.first*a.second, a.second* b.second);
    ll gc= gcdp<ll>(res);
    return res/pll(gc,gc);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

int main()
{
    freopen("inBIGSALE.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    ll T, N;
    pll  tmp, lss(0,1);
    ll gc;
    ll lss1;
    LD p, q, d;
    LD rs;
    cin>>T;
    rep(i,0,T)
    {
        cin>>N;
        lss= pll(0,1);
        lss1=0;
        rep(i,0,N)
        {
            cin>>p>>q>>d;
            tmp=pll(p*q*d*d,10000);
            gc=gcdp(tmp);
            tmp= tmp/pll(gc,gc);
            lss =lss+tmp;
            lss1+=p*q*d*d/ 10000;
            //cout<<"\n\t"<<lss<<" "<<((LD)lss.first)/((LD)lss.second)<<"is equal to"<<lss1;


        }
        rs=((LD)lss.first)/((LD)lss.second);
        cout<<((i==0)?"":"\n");
        cout<<std::setprecision (15)<<rs;
    }


    return 0;



}
