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
class TeleportationMaze
{
     vector< string > a;
     int r1, c1, r2, c2;
public:
    void in()
    {
        cin>>r1>>c1>>r2>>c2;
    }
     int pathLength(vector <string> a, int r1, int c1, int r2, int c2)
     {

     }
    void f(vector<string> a, int r1, int c1, int r2, int c2, int& res)
    {
        int dr=r2-r1, dc=c2-c1;//dir row, dir col
        if(r== r2 && c==c2) return ;
        auto w=[=,&a](int r, int c)
        {

            if(a[r][c]=='.') return false;
            if(a[r][c]=='#') return true;
        };

        if(w(r+dr,c) && w(r,c+dc))
        {
            tr=r, tc=c;//temp row, temp col
            while(w(tr,c)) tr+=dr;
            while(w(r,tc)) tc+=dc;
            if(abs(tr-r)< abs(tc-c) )
            {
                c=tc, res+=min(abs(tc-c),2); f(a,r,tc,r2,c2,res)
            }else
            {
                r=tr, res+=min(abs(tr-r),2); f(a,tr,c,r2,c2,res)
            };
        }

        return ;
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

