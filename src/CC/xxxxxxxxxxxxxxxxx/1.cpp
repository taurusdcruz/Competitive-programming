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
        int main ( )
        {
            freopen("in.txt","r",stdin);//redirects standard input
            ll T,n,m,u,v;
            cin>>T;
            rep(t,0,T)
            {
                cin>>n>>m;
                vector<vector<bool>> edges(n, vector<bool>(n, false));
                vector< vector<ll> > vvrtx2vrtx(n);
                rep(i,0,m)
                {
                    cin>>u>>v;
                    u+=-1,v+=-1;
                    edges[u][v]=edges[v][u]=true;
                    vvrtx2vrtx[u].push_back(v);
                    vvrtx2vrtx[v].push_back(u);
                }
                //debug("",edges)
                //debug("",vvrtx2vrtx)
                ll res=0;
                string path="";
                rep(i,0,m)
                {
                    ll vv2v_sz=vvrtx2vrtx[i].size();
                    if(vv2v_sz==0) continue;

                    if(vv2v_sz<6 && vv2v_sz>1)
                    {
                        path+="\n"+to_string(vv2v_sz)+" is (1,6)";
                        ll base=0;
                        ll cnt=0;
                        ll v1,v2,v3;
                        if(vv2v_sz==2)
                        {
                            base=2;
                            v1=vvrtx2vrtx[i][0], v2=vvrtx2vrtx[i][1];
                            cnt=max(cnt,( edges[v1][v2]+0ll));
                        }
                        else if(vv2v_sz>=3)
                        {
                            base=3;
                            rep(i1,0,vv2v_sz-3+1)
                            {
                                v1=vvrtx2vrtx[i][i1];
                                rep(i2,i1+1,vv2v_sz-2+1)
                                {
                                    v2=vvrtx2vrtx[i][i2];
                                    rep(i3,i2+1,vv2v_sz-1+1)
                                    {
                                        v3=vvrtx2vrtx[i][i3];
                                        path+="\n\t v1,v2,v3"+to_string(v1)+" "+to_string(v2)+" "+to_string(v3);
                                        path+="-->>> base+ v1v2+v2v3+v3v1="+to_string(base+edges[v1][v2]+edges[v2][v3]+edges[v3][v1]);
                                        cnt= max(cnt, (edges[v1][v2]+edges[v2][v3]+edges[v3][v1]+0ll));
                                    }
                                }
                            }
                        }
                        res=max(res, max(base+cnt, vv2v_sz) );
                    }
                    else
                    {
                        path+="\n"+to_string(vv2v_sz)+" is ==1 or >=6";
                        res=max(res,vv2v_sz);
                    }
                }
                //debug("",path)
                cout<<res<<endl;

            }
            return 0 ;
        }

