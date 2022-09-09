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
#define fi first
#define se second
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

//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
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

//class holding state
template <class T>
class state
{
public:
    state(int size): s(size, 0) {}

    vll s;

     friend ostream& operator<<( ostream& os , state<T> &st)
    {
        os<<st.s;
        return os;
    }
};

/*vector<vll >*/ void BS(vll& A, map<ll,ll> & Aindx, map<ll,ll> & Asindx, ll x, ll & nswaps)
{
    ll l,h,m;//low,high,mid
    vector< vll > indxtrv(2), indxtrvcr(2);
    l=1,h=A.size();
    if(!present(Aindx,x)) {nswaps=-1; return ; /*indxtrv;*/}
    ll indx=Aindx[x];
    ll sindx=Asindx[x];
    ll A_sz=A.size(),lsr_sz=0, crlsr_sz=0,gr_sz=0, crgr_sz=0;

    nswaps=0;

    ll gr=1, lsr=0; // greater, lesser, correct

    while(l<=h)
    {
        m=(l+h)/2;
        /*
        debug3("\t\t",l,m,h)
        */

        if(m-1== indx)
        {
            /*
            debug("\t\t","FOUND");
            */
            break;
        }
        else if(m-1 < indx)
        {
            l=m+1;
            if(A[m-1]>= x)
            {
                 /*
                 indxtrv[lsr].pb(A[m-1]);

                 debug4("\t\t|lsr|", m-1,indx, A[m-1],x)
                 */
                 lsr_sz+=1;
            }
            else
            {
                /*
                indxtrvcr[lsr].pb(A[m-1]);

                debug4("\t\t|crlsr|", m-1,indx, A[m-1],x)
                */
                crlsr_sz+=1;
            }
        }
        else
        {
            h=m-1;
            if(A[m-1] < x)
            {
                /*
                indxtrv[gr].pb(A[m-1]);

                debug4("\t\t|gr|", m-1,indx, A[m-1],x)
                */
                gr_sz+=1;
            }
            else
            {
                /*
                indxtrvcr[gr].pb(A[m-1]);

                debug4("\t\t|crgr|", m-1,indx, A[m-1],x)
                */
                crgr_sz+=1;
            }
        }


    }
    /*
    A_sz=A.size(), lsr_sz=indxtrv[lsr].size(), gr_sz=indxtrv[gr].size(), crlsr_sz=indxtrvcr[lsr].size(), crgr_sz=indxtrvcr[gr].size();

    debug3("\t\t", lsr_sz, crlsr_sz,sindx)
    debug3("\t\t",  gr_sz, crgr_sz,((A_sz-1)-sindx) )
    */


    if( (lsr_sz +crlsr_sz<=sindx) && (gr_sz+ crgr_sz<=( (A_sz-1)-sindx) ) )
    {
        /*
        debug("\t\t",(lsr_sz +crlsr_sz<sindx) && (gr_sz+ crgr_sz<( (A_sz-1)-sindx) ))
        */
        nswaps=max(lsr_sz, gr_sz);

    }
    else
    {
        nswaps=-1;
    }
    /*
    debug("\t\t", indxtrv)
    debug("\t\t", indxtrvcr)
    */

    /*return indxtrv;*/
}

int main()
{
    freopen("inFAKEBS.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll T, N, Q, X;
    cin>>T;

    rep(t,0,T)
    {
        cin>>N>>Q;
        /*
        debug2("",N,Q)
        */

        vll A(N);
        vll As(N);
        map<ll,ll> Aindx;
        map<ll,ll> Asindx;
        rep(i,0,N) { cin>>A[i]; Aindx[A[i] ]=i; }
        As=A;
        sort(all(As));
        rep(i,0,N) Asindx[As[i] ]=i;
        /*
        debug("", A)
        debug("", As)
        debug("",Aindx)
        debug("", Asindx)
        */

        rep(q,0,Q)
        {
            cin>>X;
            /*
            debug("\t|",X)
            */

            ll nswaps=0;
            /*auto v=*/BS(A,Aindx,Asindx,X,nswaps);
            /*
            prall("",v)
            debug("\t", nswaps)
            */

            cout<<((t==0&&q==0)?(""):("\n"))<<nswaps;


        }
    }

    return 0;
}
