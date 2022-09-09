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
#define repc(c,i,l,r) for (auto b = next(c.begin(),l),i=b, e=next(c.begin(),r); i!=e; ++i)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(arr) {cout<<"\n";for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(c,l,r) {cout<<"\n";for (auto b = next(c.begin(),l),i=b, e=next(c.begin(),r); i != e; ++i) cout << (*i) << " ";}
#define debug(m,x) cout <<"\n"<<(m)<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
const LD EPS=1e-12;
const LD INF=1e100;

//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}


//Overriding < operator
template< class T, class U >
 bool operator<(const pair<T,U>& a, const pair<T,U>& b)
{
  if (a.first < b.first) return true;
  else if ( (a.first == b.first) && (a.second < b.second) ) return true;
  else return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

int main()
{

    freopen("inAVGPR.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll T;
    cin>>T;

    rep(i,0,T)
    {
        ll N;

        cin>>N;
        map<ll,ll> flg;
        ll c;

        rep(i,0,N) {cin>>c; flg[c]+=1;}
        //prall(flg);
        ll cnt=0;
        ll key, keyl, keyr, val, vall, valr;
        auto jl=flg.rbegin();
        auto jr=flg.begin();

        repc(flg,i,0,flg.size())
        {
            key=(*i).first;
            val=(*i).second;


            if(val>=2){cnt+=(val*(val-1))/2; }
            //debug2("key, cnt init", key, cnt);
            jr=next(i,1), jl= next(flg.rbegin(),flg.size() -distance(flg.begin(),i));
            keyl=(*jl).first;
            keyr=(*jr).first;
            while(distance(jl, flg.rend())>0 && distance(jr,flg.end())>0)
            {



                ll c=(key-keyl) -(keyr-key);
                if(c==0)
                {
                    vall=(*jl).second;
                    valr=(*jr).second;
                    cnt+= vall * valr;
                    //debug3("\tkeyl, keyr, cnt", keyl, keyr, cnt);
                     jr=next(jr,1), jl= next(jl,1);
                     keyl=(*jl).first;
                     keyr=(*jr).first;

                }
                else if(c>0)
                {
                    jr=next(jr,1);
                    keyr=(*jr).first;
                }
                else
                {
                    jl= next(jl,1);
                    keyl=(*jl).first;
                }



            }
        }
        //debug(">>>>cnt",cnt);
        cout<<cnt;
        cout<<((i<=T-2)?"\n":"");


    }
    return 0;

}
