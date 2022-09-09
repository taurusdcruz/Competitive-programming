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

        // Overloading << operator for vectors
        template < class T >
        ostream& operator << (ostream& os, const vector< vector<T> >& v)
        {
            os << "[";
            for (auto ii = v.begin(); ii != v.end(); ++ii)
            {
                os << ((ii != v.begin() )?(", ") :(" ") )<< *ii;
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
            ll T;cin>>T;
            string s;
            rep(t,0,T)
            {
                cin>>s;
                ll nim_sum=0;//identity element for xor is 0
                ll onlyA=0, onlyB=0;
                bool towards=false;
                vector<pair<char,ll>> vcll;
                string path="";
                string AoB={'A','.','B'};
                string BoA={'B','.','A'};
                string AoA={'A','.','A'};
                string BoB={'B','.','B'};
                string Box={'B','.','x'};
                string Aox={'A','.','x'};
                string xoB={'x','.','B'};
                string xoA={'x','.','A'};
                char pch,cch,nch;
                string winner;
                //s.size() <=2
                if(s.size()==1)
                {
                    cout<<'B'<<endl;
                    continue;
                }
                else if(s.size()==2)
                {
                    if(s[1]== '.')
                    {
                        if(s[0]=='A')
                        {
                            cout<<'A'<<endl;
                            continue;
                        }
                    }
                    cout<<'B'<<endl;
                    continue;
                }
		//s.size()>2
                s="x"+s+"x";
                for(char cch : s)
                {
                    if( vcll.empty() || vcll.back().first!=cch)
                    {
                        vcll.emplace_back(cch,1);
                    }
                    else
                    {
                        vcll.back().second+=1;
                    }
                }
                vll vnim, vonlyA, vonlyB;
                auto at=[&](ll i){return vcll[i];};
                for(ll i=1; i<vcll.size()-1;++i)
                {
                    pch=at(i-1).first, cch=at(i).first, nch=at(i+1).first;
                    string ss=string{pch,cch,nch};

                    if(cch !='.')
                    {
                        towards=(towards+at(i).second)%2;
                    }
                    else if(cch =='.')
                    {
                        if(towards)
                        {
                            if( ss== AoB || ss==BoA)
                            {
                                nim_sum=nim_sum ^ at(i).second;
                            }
                            else if( ss==AoA || ss==Aox || ss==xoA )
                            {
                                onlyA+=at(i).second;
                            }
                            else if (ss==BoB || ss==Box || ss==xoB)
                            {
                                onlyB+=at(i).second;
                            }
                        }
                    }
                }
                ll d=onlyA-onlyB;
                winner=
                (d>0)
                ?('A')
                :(
                	(d<0)
                	?('B')
                	:(
                		(nim_sum==0)
                		?('B')
                		:('A')
                	)
                );
                cout<<winner<<endl;
            }
            return 0 ;
        }

