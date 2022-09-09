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



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions
class MinimizeAbsoluteDifferenceDiv2
{
    ll x0, x1, x2;
public:
    void input()
    {
        cin>>x0>> x1 >> x2;

    }
    vector <int> findTriple(int x0, int x1, int x2)
    {



        auto f= [](vector<int> x, int i)-> LD{ return ((LD)x[(1+i)%3]/(LD)x[(2+i)%3] -(LD)x[(0+i)%3]) ;} ;
        vector<int> y, y1, res(3);
        y.pb(x0); y.pb(x1); y.pb(x2);
        y1.pb(x0); y1.pb(x2); y1.pb(x1);

        LD cc=f(y,0);

        for(int i=0; i<3; i++)
        {

            vector<int> tmp;
            tmp.pb(y[(0+i)%3]); tmp.pb(y[(1+i)%3]);   tmp.pb(y[(2+i)%3]);
             if(f(y,i) < cc) {cc=f(y,i); res=tmp;}
        }

        for(int i=0; i<3; i++)
        {

            vector<int> tmp;
            tmp.pb(y1[(0+i)%3]); tmp.pb(y1[(1+i)%3]);   tmp.pb(y1[(2+i)%3]);
             if(f(y,i) < cc) {cc=f(y1,i); res=tmp;}
        }


        return res;

    }


};


int main ( )
{
	//freopen("in.txt","r",stdin);//redirects standard input
	//freopen("out.txt","w",stdout);//redirects standard output

	MinimizeAbsoluteDifferenceDiv2 test;
	test.input();
	vector<int> y(3);
	 y=test.findTriple(0,1,2);
	 prall(" ",y);




	return 0 ;
}

