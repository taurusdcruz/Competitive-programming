
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
#define prall(arr) cout<<"\n";for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " ";
#define prrange(c,l,r) cout<<"\n";for (auto b = next(c.begin(),l),i=b, e=next(c.begin(),r); i != e; ++i) cout << *i << " ";
#define debug(m,x) cout <<"\n"<<m<< x;
#define debug2(m,x,y) cout <<"\n"<<m<<" "<< x << " " << y;
#define debug3(m,x,y,z) cout <<"\n"<<m<< x << " " << y << " " << z;
const LD EPS=1e-12;
const LD INF=1e100;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

//Overriding < operator
template< class T, class U >
 bool operator<(const pair<T,U>& a, const pair<T,U>& b)
{
  if (a.first < b.first) return true;
  else if ( (a.first == b.first) && (a.second < b.second) ) return true;
  else return false;
}


//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions
bool isTri(vll &aa,const vll &s)
{
    rep(i,0,3) if(aa[s[i%3]]+aa[s[(i+1)%3]]<=aa[s[(i+2)%3]]) {return false;}
    return true;
}
ll peri(vll &aa,const vll &s)
{
    if(isTri(aa,s))
    {
        return(aa[s[0]]+aa[s[1]]+aa[s[2]]);
    }
    return 0;
}

int main()
{

    freopen("inPSHTRG.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll N, Q;

    cin>>N>>Q;
    vll a(N+1,-1);
    //val,pos
    rep(i,1,N+1)
    {
        cin>>a[i];
    }

    ll QT;
    ll pos, val;
    ll l, r;
    rep(i,0,Q)
    {
        cin>>QT;

        if(QT==1)
        {
            cin>>pos>>val;
            a[pos]=val;
        }
        else if( QT==2)
        {
            cin>>l>>r;
            if(r-l <2)
            {
                cout<<((i==0)?"":"\n")
                <<0;
                continue;
            }
            /*
            cout<<"\nsides";prrange(a,l,r+1);
            */
            ll mxp=0;
            ll p=0;
            vll s={l,l+1,l+2};

            mxp=peri(a,s);
            /*
            debug("is tri",isTri(a,s));
            */

            rep(i,l+3,r+1)
            {
                ll sri=-1;
                /*
                debug3("\ts",s[0],s[1],s[2]);
                */
                ll tp=(a[s[0]]+a[s[1]]+a[s[2]]);
                rep(j,0,3)
                {
                    bool flg=true;
                    ll tp1=tp-a[s[j]]+a[i];
                    rep(k,0,3)
                    {
                        if(!(tp1- 2*((k==j)?a[i]:a[s[k]]) >0))
                        {
                            flg=false;break;
                        }
                    }
                    /*
                    debug("\t\ttp",tp)
                    */
                    if(tp1>mxp && flg ) mxp=tp1,sri=j;
                }
                if(sri !=-1)
                {
                    s[sri]=i;
                }
            }
            cout<<((i==0)?"":"\n")
            <<mxp;


        }
    }
    return 0;

}
