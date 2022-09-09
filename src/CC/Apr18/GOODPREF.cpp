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
#define rep(i,a,b)	for( long long int i=(a);i<(b);i++)
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

int main()
{

    freopen("inGOODPREF.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll T;
    cin>>T;
    rep(t,0,T)
    {

        string s;
        ll n;
        cin>>s>>n;
        ll na=0;
        ll nb=0;
        vll d;

        rep(i,0,s.size())
        {
            if(s[i]=='a') na+=1;
            else if(s[i]=='b') nb+=1;
            d.pb(na-nb);
        }
        //debug("s",s);
        //prall("d", d);

        ll c=0;
        ll cnt=0;
        ll tot =d[d.size()-1];


        if(tot>0)
        {
            //debug("|>|tot", tot);
            rep(j, 0, s.size())
            {
                ll lb=max((ll)0, (d[j] % tot !=0)?((ll)ceil(- (LD)d[j]/(LD)tot )):(-d[j]/tot +1) ) ;
                if(lb<n) cnt+=(n-1 +1) -lb;
                //debug3("\t|j, lb, cnt",j,lb,cnt);
            }

        }
        else if(tot<0)
        {
            //debug("|<|tot", tot);
            rep(j, 0, s.size())
            {
                ll ub=min(n-1, ((d[j] % tot !=0)?((ll)floor(- (LD)d[j]/(LD)tot )):(-d[j]/tot -1)) );
                if(ub>-1) cnt+= (ub+1)-0;
                //debug3("\t|j, ub, cnt",j,ub,cnt);
            }

        }
        else if(tot==0)
        {
            //debug("|=|tot", tot);
            rep(j, 0, s.size())
            {
                if(d[j]>0) cnt+=n;
                //debug3("\t|j, ub, cnt",j,d[j],cnt);
            }
        }



        cout<<((t>0)?("\n"):(""))<<cnt;

    }

    return 0;

}
