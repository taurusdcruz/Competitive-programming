
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
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) cout<<"\n"; for (auto it = arr.begin(); it != arr.end(); ++it) cout <<((it != arr.begin())?" ":"")<< *it ;
#define debug(m,x) cout <<"\n"<<m<< x;
#define debug2(m,x,y) cout <<"\n"<<m<<" "<< x << " " << y;
#define debug3(m,x,y,z) cout <<"\n"<<m<< x << " " << y << " " << z;
const LD EPS=1e-12;
const LD INF=1e100;
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions


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


int main()
{
    freopen("inMINVOTE.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll T, N;

    vll s;
    vll sum;
    vll rs;
    vector<pair<pair<ll,ll>, ll> > rrr;
    pair<pair<ll,ll>, ll> tmp;
    cin>>T;


    rep(i,0,T)
    {
        cin>>N;
        //if(N==1) {cin>>cout<<"\n"<<0; continue;}
        s.resize(N);
        sum.resize(N);
        rs.resize(N);
        rrr.clear();
        fill(rs.begin(),rs.end(),0);

        rep(i,0,N)
        {
            cin>>s[i];
            if(i==0)sum[i]=s[i];
            else sum[i]=sum[i-1]+s[i];
        }
        //c_b
        cout<<"\ns";
        print(s);
        cout<<"\nsum";
        print(sum);
        //c_e
        ll sm=-1;
        rep(i,0,N-1)
        {
            rep(j,i+1,N)
            {

                sm=sum[j]-sum[i]-s[j];
                tmp.second=sm;

                if(s[i]>=sm)
                {
                    rs[j]+=1;
                    //c_b
                    tmp.first.first=j, tmp.first.second=i, rrr.push_back(tmp);
                    //c_e
                }
                if(s[j]>=sm)
                {
                    rs[i]+=1;
                    //c_b
                    tmp.first.first=i, tmp.first.second=j, rrr.push_back(tmp);
                    //c_e
                }
                //c_b
                debug3("\n",s[i],s[j],sm);
                print(rs);
                //c_e
                if(s[i]<sm && s[j]<sm) break;


            }
        }
        //c_b
        sort(rrr.begin(),rrr.end());
        cout<<"\nrrr";
        print(rrr);
        cout<<"\nres";
        //c_e
        print(rs);
    }


    return 0;



}
