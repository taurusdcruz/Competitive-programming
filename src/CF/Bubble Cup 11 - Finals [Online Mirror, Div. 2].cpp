
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


class robot
{
    public:
    ll x,r,q;
};
//Overloading operator<< for class as a free function
ostream& operator<< ( ostream& os, robot& p) // if i do (class_name:: operator<<) then this will automatically be appended as a third argument and hence will have to remove class_name& some_var
{
    os << "( "<<(p.x)<<", "<<(p.r )<<", "<< (p.q)<<" ) ";
    return os;
}
istream& operator>> ( istream& is, robot& p) {
    is >>p.x>>p.r>>p.q;
    return is;
}

robot& robot::operator= (const robot& p)
{
    if(this == &p ) return *this;
    this->x=p.x;
    this->r=p.r;
    this->q=p.q;
    return *this;
}


// Overloading << operator for vectors
ostream& operator << (ostream& os, const vector<robot>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os <<  *ii;
    }
    os << "]";
    return os;
}
int main ( )
{
    freopen("in.txt","r",stdin); //redirects standard input
    //freopen("out.txt","w",stdout); //redirects standard output
    ll N,K;cin>>N>>K;
    vector<robot > vr(N);//vector of robots
    rep(i,0,N)
    {
        cin>>vr[i];
    }
    sort(all(vr),[](robot l, robot r){ return l.x<r.x;});
    cout<<vr;
    ll cnt=0;
    for(ll i=0; i<N; i++)
    {
        for(ll j=i+1;(j<N) ? (vr[j].x-vr[i].x<min(vr[i].r,vr[j].r)):(0) ; j++)
        {
            if(abs(vr[i].q-vr[j].q)<K+1 ) cnt+=1;
            debug2(" ",i,j)
        }

    }
    cout<<cnt<<endl;
    return 0 ;
}

