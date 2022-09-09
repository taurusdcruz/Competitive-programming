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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") \n";
  return out;
}

// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const vector<T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for vectors
template < class T >
ostream& operator << (ostream& os, const vector< vector<T> >& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << ((ii != v.begin() )?("\n") :("\n") )<< *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for maps
template < class T, class U >
ostream& operator << (ostream& os, const map<T, U>& mp)
{
    os << "mp:[";
    for (auto ii = mp.begin(); ii != mp.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}
// Overloading operator+ for vectors
template < class T >
vector<T> operator+ (const vector<T>& v1, const vector<T>& v2)
{
    vector<T> res(v1.size());
    rep(i,0,v1.size())
    {
        res[i]=v1[i]+v2[i];
    }
    return res;
}

// Overloading operator- for vectors
template < class T >
vector<T> operator- (const vector<T>& v1, const vector<T>& v2)
{
    vector<T> res(v1.size());
    rep(i,0,v1.size())
    {
        res[i]=v1[i]-v2[i];
    }
    return res;
}

int main()
{
    freopen("inSBSTR.txt","r",stdin);//redirects standard input
    ll T;
    string s;
    ll K;
    cin>>T;
    rep(t,0,T)
    {
        cin>>s>>K;
        //debug3("",T,s,K)
        ll cnt=0;
        ll s_sz=s.size();
        vll dp(26,0);
        vvll dp_p(s_sz, vll(26,0)), dp_s(s_sz, vll(26,0));
        vll dp_all(26,0);
        auto f=[=](ll i)->ll{return (ll)(s[i]-'a');};
        auto sp=
        [=](vll& a)
        {
            set<ll> b(all(a));b.erase(0);
            ll k1=0; rep(i,0,26) if(a[i]!=0) k1+=1;
            if(b.size()==1 && k1>=K) return true; else return false;
        };
        auto delta=
        [=](vll a)->ll
        {
            set<ll> b(all(a));b.erase(0);
            return (ll)( *(b.rbegin()) - *(b.begin()) );
        };

        rep(i,0,s_sz)
        {
            if(i>0) dp_p[i]=dp_p[i-1];
            dp_p[i][f(i)]+=1;
        }
        dp_all=dp_p[s_sz-1];
        for(ll i=s_sz-1; i>=0;i--)
        {
            if(i<s_sz-1) dp_s[i]=dp_s[i+1];
            dp_s[i][f(i)]+=1;
        }



        rep(i,0,s_sz)
        {
            dp=dp_p[i];
            //debug("", dp_all)
            for(ll j=s_sz-1; j>=i;j--)
            {
                ll pref=i-1, suff=j+1;
                debug4("", i,j,pref,suff)
                if(pref<0 && suff<=s_sz-1)
                {
                    debug2("",1,dp)
                    dp=(dp_all - dp_s[suff]);

                }
                else if(pref>=0 && suff>s_sz-1)
                {
                    debug2("",2,dp)
                    dp=(dp_all-dp_p[pref]);

                }
                else if(pref<0 && suff>s_sz-1)
                {
                    debug2("",3,dp)
                    dp=dp_all;

                }
                else
                {
                    debug2("",4,dp)
                    dp=(dp_all-dp_s[suff])-dp_p[pref];

                }
                debug("",dp)
                //debug("",dp)

                if(sp(dp))
                {
                    cnt+=1;
                    debug2("",sp(dp),cnt)
                    //debug3("",i,j,dp)
                }
                else
                {
                    debug3("",delta(dp), i,j-delta(dp))
                    j=max(i, j-delta(dp));

                }
            }
        }
        cout<<((t==0)?(""):("\n"))<<cnt;


    }

    return 0;
}
