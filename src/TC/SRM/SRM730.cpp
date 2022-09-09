
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
const LD EPS=1e-12;
const LD INF=1e100;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures
struct intrvl
{
    int l,r;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions
template<class T>
inline void swapp(T &x, T &y)
{
    T tmp = x;
    x = y; y = tmp;
}
class IntervalIntersections
{
    intrvl in1, in2;
    int res;
public:
    void input()
    {
        cin>>in1.l>>in1.r>>in2.l>>in2.r;
    }
    int minLength( int a, int b, int c, int d)
    {
        in1.l=a, in1.r=b, in2.l=c, in2.r=d;
         if(in1.l >in2.l) {
            swapp(in1.l, in2.l);
            swapp(in1.r,in2.r);
            }

    //cout<<" "<<in1.l<<" "<<in1.r<<" "<<in2.l<<" "<<in2.r;

    if(in1.r < in2.l) res=in2.l-in1.r; else res=0;
    return res;

    }
    int minLength( )
    {

         if(in1.l >in2.l) {
            swapp(in1.l, in2.l);
            swapp(in1.r,in2.r);
            }

    //cout<<" "<<in1.l<<" "<<in1.r<<" "<<in2.l<<" "<<in2.r;

    if(in1.r < in2.l) res=in2.l-in1.r; else res=0;
    return res;

    }


};


int main ( )
{
	freopen("in.txt","r",stdin);//redirects standard input
	//freopen("out.txt","w",stdout);//redirects standard output


    IntervalIntersections  Test;
    Test.input();
    cout<<Test.minLength();



	return 0 ;
}

