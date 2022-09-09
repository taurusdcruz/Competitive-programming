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

const ll mod = 1e9 + 7;
#define sz(a) int((a).size())
#define pb push_back
#define fi first
#define se second
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


// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const vector<T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const set<T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const map<T, T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

int main()
{
    freopen("in.txt","r",stdin);//redirects standard input
    ll n;cin>>n;
    vll a(n);
    rep(i,0,n)
    {
        cin>>a[i];
    }
    ll mx_elem=*max_element(all(a));
    // check if __number__ divisible by any of the primes found upto now
    // if yes --->__number__ is not a prime
    // if No  --->__number__ is a prime

    vector<bool> IP(mx_elem,true);//IsPrime
    vector<ll> PUN;//PrimesUptoNow
    for(ll i=2;i<mx_elem+1;i++)
    {
        if(IP[i])//possibly prime
        for(ll j=0;j<PUN.size();j++)//traversing all the primes numbers found upto now
        {
            if(IP[j] && i%PUN[j]==0)
            {
                IP[i]=false;
            }
        }
        if(IP[i])//definitely prime as undergone checking
        {
            PUN.push_back(i);
            //all multiples of numbers less than i have been marked as non prime so,
            // if k<i, then k*i being a multiple of  k(which is <i ) ===>IP[k*i] would have been marked as false before
            //choose k>i such that k is prime(possibly) and if IP[k*i] ==true, mark IP[k*i] as false
            for(ll k=i;k*i<mx_elem+1;k++)
            {
                if(IP[k])
                if(IP[k*i])
                IP[k*i]=false;
            }
        }
    }
    //debug("",PUN)
    vll cnt(mx_elem+1,0);
    //debug3("",a, cnt,mx_elem)

    for(ll i=0;i<a.size();i++)
    {
        for(ll j=0;j<PUN.size();j++)
        {
            ll c=1;
            while(a[i] % (c*=PUN[j]) ==0)
            {
                if(c>a[i]) break;
                //debug2("",a[i],c)
                cnt[c]+=1;
            }
        }
    }
    //debug("",cnt)
    ll mx_cnt=0;//max count less than n(i.e. a.size() )
    rep(i,0,cnt.size())
    {
        if(cnt[i]!=n)// skips the factors which account for the current gcd
        {
            mx_cnt=max(cnt[i],mx_cnt);
        }
    }

    cout<<n-mx_cnt<<endl;


    return 0;
}
