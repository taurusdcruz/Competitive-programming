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

bool bfs(vvll &rG,ll V, ll s, ll t, vll &PARENT)
{
    //modifies PARENT and returns true if path exists from s to t
    vector<bool> VIS(V,false);queue <ll> q;
    q.push(s);VIS[s] = true,
    fill(all(PARENT),-1);
    debug2("BEGIN_BFS",s,t)

    while (!q.empty())
    {
        ll u = q.front();q.pop();// save and pop the oldest element

        rep(v,0,V)
        {
            if (VIS[v]==false && rG[u][v] > 0)
            {
                q.push(v);
                PARENT[v] = u;
                VIS[v] = true;
            }
        }
    }

    if(VIS[t])
    {
        vll path;
        for (ll v=t; v!=s; v=PARENT[v])
        {
            path.pb(v);
        }
        path.pb(s);
        reverse(all(path));

        debug2("FOUND_PATH: ",PARENT, path )
    }
    else
    {
        cout<<"\nCOULDNT_FIND_PATH: ";
    }
    debug2("END_BFS",s,t)

    return (VIS[t] == true);
}

ll E_K(vvll &G,ll V, ll s, ll t)
{
    ll u, v;
    vvll rG(V, vll(V,0));rG=G;
    debug2("BEGIN_E_K",s,t)

    vll PARENT(V,0);
    ll max_flow = 0;
    while (bfs(rG,V, s, t, PARENT))
    {
        ll path_flow = LLONG_MAX;
        cout<<"\n"<<"1.Finding path_flow...";
        for (v=t; v!=s; v=PARENT[v])
        {
            u = PARENT[v];
            path_flow = min(path_flow, rG[u][v]);
        }
        debug("",path_flow)
        cout<<"\n"<<"2.Augmenting rG with path_flow...";
        for (v=t; v != s; v=PARENT[v])
        {
            u = PARENT[v];
            rG[u][v] -= path_flow;
            rG[v][u] += path_flow;
            debug4("Augmenting", u, v,rG[u][v], rG[v][u])
            debug("partially augmented rG",rG)
        }
        debug("Augmented rG",rG)

        max_flow += path_flow;
        debug("Temp", max_flow)
    }

    debug("Final",rG);
    debug("Final",max_flow);
    debug2("END_E_K",s,t)
    return max_flow;
}
int main()
{
    freopen("inSTMINCUT.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    ll T, N;
    cin>>T;
    rep(t,0,T)
    {
        cin>>N;
        _(N)
        vvll A(N, vll(N,-1));
        vvll resA(N, vll(N, 0));

        rep(i,0,N)
        {
            rep(j,0,N)
            {
                cin>>A[i][j];
            }
        }
        ll res=0;
        /*
         rep(i,0,N)
        {
            rep(j,i+1,N)
            {
                ll c=max( A[i][j], A[j][i]);
                res+= 2*c -( A[i][j] + A[j][i]);
                A[i][j]=c;
                A[j][i]=c;

            }
        }
        */
        debug("resInit ",res)
        debug("Corrected ",A)
        rep(i,0,N)
        {
            rep(j,i+1,N)
            {
                ll c=E_K(A,N,i, j);
                //debug2("\t",i,j)

               // debug4("\t",res, c , A[i][j], A[j][i])
                ll res_= 2*c -( A[i][j] + A[j][i]);
                res+=res_;
                //debug3("\t",i,j,res)
                resA[i][j]=res_;
                resA[j][i]=res_;
            }
        }
        debug("", resA);

        cout<< res;


    }


    return 0;
}
