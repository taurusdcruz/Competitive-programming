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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

struct person
{
    //In structs members are public by default
    string name;
    ll M, NG;// Money, No of Gifts he got for Christmas
    //Default constructor
    person()
    :name("NA")
    , M(-1)
    , NG(-1)
    {}
    //Parameterized constructor
    person(string _name, ll _M, ll _NG) : name(_name), M(_M), NG(_NG) { }
    //Overloading operator= for struct person
    person& operator = (const person& p) ;
    //ostream& operator<< ( ostream& os) ; if you declare here, you will have to do (obj<< cout) which is non intuitive

};

person& person::operator= (const person& p)
{
    if(this == &p ) return *this;
    this->name=p.name;
    this->M=p.M;
    this->NG=p.NG;
    return *this;
}
//Overloading operator<< for struct person as a free function
ostream& operator<< ( ostream& os, const person& p) // if i do (person:: operator<<) then this will automatically be appended as a third argument and hence will have to remove person& p
{
    os << "( "<<(p.name)<<", "<<(p.M )<<", "<< (p.NG)<<" ) ";
    return os;
}

//Overloading operator>> for struct person
istream& operator>> ( istream& is, /*Not const*/ person& p) // if i do (person:: operator>>) then this will automatically be appended as a third argument and hence will have to remove person& p
{
    is >>(p.name)>>(p.M )>>(p.NG);
    return is;
}

// Overloading  operator<< for vectors
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

int main()
{
    vector<person>P(5);
    person p;

    rep(i,0,5)
    {
        auto to_string=[](ll i){ stringstream ss; ss<<i; string s; ss>>s; return s; };
        string s="person"+to_string(i);
        p= person(s, i*1000, (i*100)%49);
        P[i]=p;
    }

    debug("",P)
    //P[ ( person0, 0, 0 )  ( person1, 1000, 2 )  ( person2, 2000, 4 )  ( person3, 3000, 6 )  ( person4, 4000, 8 ) ]




    return 0;
}
