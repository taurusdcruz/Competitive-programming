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




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions

int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    ll T;
    cin>>T;
    rep(t,0,T)
    {
        string s;
        ll n;
        cin>>s>>n;
        ll f_w= s.find_last_of("W");
        ll l_w= s.find_last_of("W");
        ll f_b=s.find_first_of("B");
        ll l_b=s.find_last_of("B");
        ll c_w_dot=0;
        ll c_b_dot=0;
        ll c_w=0;
        ll c_b=0;
        if(f_w == string::npos && f_b != string::npos) {cout<<"B"<<endl;continue;}
        if(f_w != string::npos && f_b == string::npos) {cout<<"W"<<endl;continue;}
        rep(i,f_w,l_w)
        {

            ll tmp=0;
            if(s[i]=='.')
            {
                while(s[i]=='.') {tmp+=1;i+=1;}
                c_w_dot= c_w_dot + tmp;
            }
            if(s[i]=='W') c_w+=1;
        }
        rep(i,f_b,l_b)
        {
            ll tmp=0;
            if(s[i]=='.')
            {
                while(s[i]=='.') {tmp+=1;i+=1;}
                c_b_dot= c_b_dot + tmp;

            }
            if(s[i]=='B') c_b+=1;
        }

        if(c_w_dot+ (f_b -l_w -1)%2> c_b_dot) cout<<"W"<<endl;
        if(c_w_dot+ (f_b -l_w -1)%2< c_b_dot) cout<<"B"<<endl;
        if(c_w_dot+ (f_b -l_w -1)%2== c_b_dot)
        {
            if(c_w > c_b)  cout<<"W"<<endl;
            if(c_w < c_b) cout<<"B"<<endl;
            if(c_w == c_b) cout<<"W"<<endl;

        }


    }
	return 0 ;
}

