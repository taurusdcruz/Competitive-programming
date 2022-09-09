
#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
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
#define some(c,l,r) next((c).begin(),l),next((c).begin(),r-1) //Range:[l.r)
#define rall(c) (c).rbegin(),(c).rend()
#define rsome(c,l,r) next((c).rbegin(),l),next((c).rbegin(),r-1) //Range:[l.r)
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define repc(c,i,l,r) for (auto b = next(c.begin(),(l)),i=b, e=next((c).begin(),(r)); i!=e; ++i)//Range:[l.r)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(m,arr) {cout<<"\n"<<(m); for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m);for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}//Range:[l/r)
#define debug(m,x) cout <<"\n"<<(m)<<#x<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<<#x << ", "<<#y<<"| "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<<" "<<#x<<", "<<#y<<", "<<#z<<"| "<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<#w<<", "<<#x<<", "<<#y<<", "<<#z<<"| "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
#define _(x) cout <<"\n"<< (#x) <<" "<< (x) ;


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

// Overloading << operator for sets
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

// Overloading << operator for vector<vector>
template < class T >
ostream& operator << (ostream& os, const vector< vector<T> >& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << ((ii != v.begin() )?("\n") :("\n") )<< *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for maps
template < class T, class U >
ostream& operator << (ostream& os, const map<T, U>& mp)
{
    os << "mp:[";
    for (auto ii = mp.begin(); ii != mp.end(); ++ii)
    {
        os << "\n" << *ii;
    }
    os << "]";
    return os;
}

//print a set of variables in one line
void pline(string message, ll indent_variable/*variable nof parameters*/)
{

}
vector<bool> primes_upto(ll N)
{
    vector<bool> IP(N,true);//IsPrime
    vector<ll> PUN;//PrimesUptoNow
    for(ll i=2;i*i<N+1;++i)
    {
        if(!IP[i]) continue;

        //possibly prime
        for(ll j=0;j<PUN.size();++j)//traversing all the primes numbers found upto now
        {
            if( i%PUN[j]==0)
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
            for(ll k=i;k*i<N+1;++k)
            {
                if(IP[k*i])
                IP[k*i]=false;
            }
        }
    }
    // Note: PUN contains primes only up to sqrt(N)
    //Hence, we have to populate PUN  with  remaining primes (i.e where, sqrt(N) < primes <= N) )
    rep(i,floor(sqrt(N)),IP.size())
    {
        if(IP[i])
        {
            PUN.push_back(i);
        }
    }
    return IP;
}

int main()
{
    freopen("in.txt","r",stdin);//redirects standard input
    ll T,N;
    cin>>T;
    vector<bool> IP=primes_upto((ll)(1e5+1));
    rep(t,0,T)
    {
        cin>>N;
        vll A(N);
        vll ip(N);
        vll A1,A2;
        vll prime_cnt(1e5+1,0);
        rep(i,0,N)
        {
            cin>>A[i];
            ip[i]=IP[A[i] ];
            if(ip[i] )
            {
                //prime
                if(prime_cnt[A[i]]==0)
                    A1.push_back(A[i]);
                prime_cnt[A[i]]+=1;
            }
            else
            {
                //non primes
                A2.push_back(A[i]);
            }

        }
        //debug3("",A,A1,A2)
        vll no_noprimes_a_prime_divides(A2.size(),0);
        ll res=0;
        rep(i1,0,A1.size())
        {
            rep(i2,0,A2.size())
            {
                if(A2[i2]%A1[i1]==0)
                {
                    no_noprimes_a_prime_divides[i1]+=1;
                }
            }
            res=max(res, prime_cnt[A1[i1]]*no_noprimes_a_prime_divides[i1]);
        }
        //debug("",cnt)


        cout<<res<<endl;
    }
    return 0;
}
