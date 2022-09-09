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
        class PUMPWAT
        {
            ll N;
            vll h;
            ll res;
        public:
            PUMPWAT()
            :N()
            ,h()
            ,res()
            {
                cin>>N;
                h.resize(N);
                res=N;
                rep(i,0,N)
                {
                    cin>>h[i];
                }
                /**
                debug("",N)
                debug("",h)
                /**/
            }
            void f(ll l, ll r, ll tres)
            {
                ll mx=-1,m=-1;
                for(ll i=l;i<r+1;++i)
                {
                    if(mx<h[i]) mx=h[i],m=i;
                }
                if(m==l || m==r)
                {
                    tres+=1;
                    res=min(res,tres);
                    return;
                }
                f(l,m-1, tres+1);
                f(m+1,r,tres+1);
                return;
            }
            void solve()
            {
                f(0,N-1,0);
                cout<<res<<endl;
            }
        };
        int main ( )
        {
            freopen("in.txt","r",stdin);//redirects standard input
            ll T,N;
            cin>>T;
            rep(t,0,T)
            {
                PUMPWAT().solve();
            }
            return 0 ;
        }

