
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
template< class T>
 bool operator<(const pair<T,T>& a, const pair<T,T>& b)
{
  pair<T,T> c=a-b;
  if (c.first <(T)0) return true;
  else return false;
}

//Overriding <= operator
template< class T>
 bool operator<=(const pair<T,T>& a, const pair<T,T>& b)
{
  pair<T,T> c=a-b;
  if (c.first <=(T)0) return true;
  else return false;
}

//Overriding >= operator
template< class T>
 bool operator>=(const pair<T,T>& a, const pair<T,T>& b)
{
  pair<T,T> c=a-b;
  if (c.first >=(T)0) return true;
  else return false;
}
//Overriding << operator
template< class T, class U >
ostream&  operator<<(ostream& out,const pair<T,U>& a)
{
  out<<"( "<<a.first<<", "<<a.second<<") ";
  return out;
}

//Overriding + operator
template< class T >
 pair<T,T> operator+(const pair<T,T>& a, const pair<T,T>& b)
{
    T num=a.first* b.second+ b.first*a.second;
    T den=a.second *b.second;
    T g=(T)gcd((ll)num,(ll)den);
     pair<T,T> p(num/g, den/g);
     return p;
}

//Overriding - operator
template< class T >
 pair<T,T> operator-(const pair<T,T>& a, const pair<T,T>& b)
{
    T num=a.first* b.second- b.first*a.second;
    T den=a.second *b.second;
    T g=(T)gcd((ll)num,(ll)den);
    pair<T,T> p(num/g, den/g);
    return p;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions
template< class T >
T div(pair<T,T> &p)
{
    return p.first/p.second ;
}
int main()
{

    freopen("inHIGHWAYC.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output
    ll T;
    cin>>T;
    rep(i,0,T)
    {
        ll N, S, Y;
        cin>>N>>S>>Y;
        vector<LD> V(N), D(N), P(N), C(N);

        rep(i,0,N) cin>>V[i];
        rep(i,0,N) {cin>>D[i]; if(D[i]==0.0)D[i]=-1.0;}
        rep(i,0,N) cin>>P[i];
        rep(i,0,N) cin>>C[i];
        /*
        prall(V);
        prall(D);
        prall(P);
        prall(C);
        */

        //pair<LD,LD> def(-1.0,-1.0);
        //vector<pair<pair<LD,LD>,pair<LD,LD> > > DETH(N,pair<pair<LD,LD>,pair<LD,LD> >(def,def));
        vector<pair<LD,LD> > DDETH(N);
        //pair<LD,LD> t_cross((LD)Y,(LD)S);
        //pair<LD,LD> pv(abs(P[i]),V[i]) ;
        //pair<LD,LD> cv(C[i],V[i]) ;


        LD delta=0.000001;
        rep(i,0,N)
        {
            if((P[i] +C[i] >=0.0 && D[i]==-1.0)||(P[i]-C[i] <=0.0 && D[i]==1.0) )
            {

                //DETH[i]=pair<pair<LD,LD>,pair<LD,LD> >(pv - t_cross , pv + cv );
                DDETH[i]=pair<LD,LD>((abs(P[i])/V[i]) -(LD)Y/(LD)S-delta/V[i],(abs(P[i])/V[i]) +(abs(C[i])/V[i]) );
            }
            else
            {
                //(-1,-1)
            }
        }
        /*
        prall(DDETH);
        prall(DETH);
        */

        LD t=0.0;
        //vector<LD > tt(N);
        ll cnt=0;
        rep(i,0,N)
        {
            //tt[i]=t;

            //if(t>= div(DETH[i].first) && t<= div(DETH[i].second) )
            if(t>= (DDETH[i].first) && t<= DDETH[i].second)
            {
               // t=div(DETH[i].second);
               t=(DDETH[i].second);

               cnt=0;
            }
            t-=(LD)(cnt*Y)/(LD)(S);
            cnt+=1;

            t= t+(LD)(cnt*Y)/(LD)(S);

        }
        /*
        prall(tt);
        */
        cout<<setprecision(15)<<t;
        cout<<((i<=T-2)?"\n":"");

    }
    return 0;

}
