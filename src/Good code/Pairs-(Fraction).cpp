
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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
const LD EPS=1e-12;
const LD INF=1e100;
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

//--------------------------------------------------------------------------
//FRACTIONS
//---------------------------------------------------------------------------

//Overriding < operator
template< class T>
 bool operator<(const pair<T,T>& a, const pair<T,T>& b)
{
  pair<T,T> c=a-b;
  if (c.first <(T)0) return true;
  else return false;
}

//Overriding > operator
template< class T>
 bool operator>(const pair<T,T>& a, const pair<T,T>& b)
{
  pair<T,T> c=a-b;
  if (c.first >(T)0) return true;
  else return false;
}

//Overriding <= operator
template< class T>
 bool operator<=(const pair<T,T>& a, const pair<T,T>& b)
{
  pair<T,T> c=a-b;
  if (c.first <=(T)0) return true;
  else return false;
}

//Overriding >= operator
template< class T>
 bool operator>=(const pair<T,T>& a, const pair<T,T>& b)
{
  pair<T,T> c=a-b;
  if (c.first >=(T)0) return true;
  else return false;
}
//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<"/ "<<a.second<<") ";
  return out;
}

//Overriding + operator
template< class T >
 pair<T,T> operator+(const pair<T,T>& a, const pair<T,T>& b)
{
    T num=a.first* b.second+ b.first*a.second;
    T den=a.second *b.second;
    T g=gcd(num,den);
    return pair<T,T>(num/g, den/g);
}

//Overriding - operator
template< class T >
 pair<T,T> operator-(const pair<T,T>& a, const pair<T,T>& b)
{
    T num=a.first* b.second- b.first*a.second;
    T den=a.second *b.second;
    T g=gcd(num,den);
    return pair<T,T>(num/g, den/g);
}

int main()
{
    return 0;
}
