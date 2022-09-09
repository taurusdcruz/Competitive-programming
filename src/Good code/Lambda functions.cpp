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
#define repc(c,i,l,r) for (auto b = next(c.begin(),(l)),i=b, e=next((c).begin(),(r)); i!=e; ++i)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(m,arr) {cout<<"\n"<<(m); for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m);for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}
#define debug(m,x) cout <<"\n"<<(m)<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
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


// Overloading << operator for maps
template < class T, class U >
ostream& operator << (ostream& os, const map<T, U>& mp)
{
    os << "mp:[";
    for (auto ii = mp.begin(); ii != mp.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

int main()
{
   // calculating a[i]= b[i] + c[i]*d[i], where a,b,c,d are vectors of same length
   vll a(10), b(10), c(10), d(10);
   //populating b, c, d
   ll i=0;
   transform(all(b), b.begin(), [=, &i](ll elem)->ll{return i++;});
   //b:[ 0 1 2 3 4 5 6 7 8 9]
   debug("",b)

   transform(all(c), c.begin(), [=, &i](ll elem)->ll{return 10;});
   //c:[ 10 10 10 10 10 10 10 10 10 10]
    debug("",c)

    transform(all(d), d.begin(), [=, &i](ll elem)->ll{return i++;});
    //d:[ 10 11 12 13 14 15 16 17 18 19]
    debug("",d)

    //Lambda function, f(ll,ll,ll)->ll to calc (b[i] + c[i]*d[i] )
    auto f= [](ll elem1, ll elem2, ll elem3)->ll{return (elem1+ elem2*elem3) ;};

    //Custom_transform
    //transform vector pointed to by d_first iterator
    auto custom_transform=
    [](vll::iterator first1, vll::iterator last1, vll::iterator first2, vll::iterator first3, vll::iterator d_first, function<ll (ll,ll,ll)> predicate)
    {
        while(first1!=last1)
        {
            *d_first++=predicate(*first1++, *first2++, *first3++);
        }
        return d_first;
    };

    custom_transform(all(b), c.begin(), d.begin(), a.begin(), f);
    debug("",a)
    //a:[ 100 111 122 133 144 155 166 177 188 199]

    return 0;
}
