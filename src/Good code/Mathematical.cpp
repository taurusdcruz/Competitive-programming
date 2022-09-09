/*
ID: taurusd1
TASK: wormhole
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

/*FACTORIAL*/
ll factorial(ll n)
{
    if(n<0) return -1;
    else if(n==0) return 1;
    else if(n>0)
    {
        ll res=1;
        for(ll i=n; i>=1; i-=1)
        {
            res*=i;
        }
        return res;
    }
}

/* n CHOOSE r*/
ll combination(ll n, ll r)
{
    ll res=1;
    for(ll i=n;i>=n-r+1;i--)
    {
        res*=i;
    }
    for(ll i=r;i>=1;i--)
    {
        res/=i;
    }
    return res;
}

/*print all combinations n choose r*/
void print_all_combinations(ll&n , ll& r, vector<string>& indx2symbol, vector<bool> ischoosen, vector<string> curr_combination, ll last_indx)
{
    if(last_indx!=-1)
    {
        ischoosen[last_indx]=true;
        curr_combination.push_back(indx2symbol[last_indx]);
    }

    if(r==0)
    {
        cout<<"PHI, the NULL set"<<endl;
        return;
    }
    if(curr_combination.size()>=r)
    {
        rep(i,0,curr_combination.size())
        {
            cout<<curr_combination[i]<<", ";
        }
        cout<<endl;
    }
    else
    {
        rep(indx,last_indx+1,n)
        {
            print_all_combinations(n,r,indx2symbol,ischoosen,curr_combination,indx);
        }
    }
    return;
}

/*****************
*primes_upto*
******************/
/*Return a sorted (ascending order) vector of all primes upto a given number, N*/
vector<ll> primes_upto(ll N)
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
    return PUN;
}


//Primality test
bool isPrime(ll N)
{
    if(N <= 1) return 0; // <- 1 is not prime
    for (ll i = 2; i * i <= N; ++i)
        if (N % i == 0) return 0;
    return 1;
}

/*checking palindrome without using strings*/
bool ispal(ll N)
{
    ll l=pow(10,floor(log10(N)));
    ll r=1LL;
    for(;l>r;l/=10,r*=10)
    {
        ll ld=N/l %10;
        ll rd=N/r %10;
        if(ld!=rd)
        {
            //debug("X",N)
            return false;
        }
    }
    return true;
}


int main ( )
{
	//freopen("in.txt","r",stdin);//redirects standard input
    //freopen("wormhole.out","w",stdout);//redirects standard output

    /**********************************************
    *Printing all combinations 5 choose 3
    **********************************************/

    /*  *"Delete Me to run demo"/
    ll n=5 ; ll  r=3; vector<string>  indx2symbol; vector<bool>  ischoosen(n,false); vector<string>  curr_combination; ll  last_indx;
    //cout<<"enter n, r";cin>>n>>r;
    rep(i,0,n)
    {
        ostringstream oss;
        oss<<i;
        indx2symbol.push_back("_"+ oss.str() );
    }
    last_indx=-1;
    print_all_combinations(n,r,indx2symbol,ischoosen, curr_combination,last_indx);

    /**/
    /*****************************
    *XXXENDOFDEMOXXX*
    *****************************/

    /************************************
    *Printing all primes upto 1000
    ************************************/
    /*  *"Delete Me to run demo"/

    cout<<primes_upto(1000)<<endl;
    /**/
    /*****************************
    *XXXENDOFDEMOXXX*
    *****************************/
	return 0;
}
