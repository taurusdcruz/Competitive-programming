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
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
const LD EPS=1e-12;
const LD INF=1e100;




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

struct impinfo
{
    vector< vector< string > > p;

    //storing index of
    vector< vector<pair<ll, ll> > > indx;

    ll n_s_initially;
    impinfo()
    {
         p.resize(5);
         p={ { "...", "-..","..-"}, {"P.-","-.P"}, {"P.P", "S.-", "-.S"}, {"P.S", "S.P"}, {"S.S"} };
         indx.resize(5);
         n_s_initially=0;
    }


};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions

void calcc( vector<string> &sr, impinfo &ipif, ll row, ll col)
{
    //substring
    string ss;

    ss= sr[row].substr(col-1,3);
    cout<<ss;
    bool isS;
    if(sr[row][col]=='S') {isS=true;ss[1]='.'; }

    tr(ipif.p, it)
    {
         auto it1=find((*it).begin(), (*it).end(), ss);
        if(it1 != (*it).end())
        {
            ll i_it=(ll)(it-ipif.p.begin());
            *it1=i_it;
            pair<ll,ll> pr(row, col);
            ipif.indx[i_it].push_back(pr);
            if(isS)ipif.n_s_initially+=i_it;
            break;
        }


    }


}





int main ( )
{
    freopen("in.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output


    ll n, k;
    //seatrows
    cin>>n>>k;
    vector< string> sr(n, "-...-....-...-");
    impinfo ipif;
    ll cnt=k;

    rep(i,0,n) rep(j,1,13) cin>>sr[i][j];

    rep(row,0,n)
    {
        rep(col,1,13)
        {
            calcc(sr,ipif,row,col);
        }
    }

    rep(i,0,5)
    {
         cout<< ipif.indx[i].size()<<" ";
         tr(ipif.indx[i], it)
         {
             cout<<"("<<(*it).first<<","<<(*it).second<<"), ";
         }
         cout<<endl;
    }
    cout<<ipif.n_s_initially;




	return 0 ;
}
