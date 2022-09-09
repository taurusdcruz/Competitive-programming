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
#define debug(m,x) cout <<"\n"<<(m)<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
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
  out<<"\n( "<<a.first<<", "<<a.second<<") ";
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
    os << "]\n";
    return os;
}///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

int main()
{

    freopen("inVAIMIN.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    string line_test, line_1, line_2;
    //getline(cin, line_test) ;
    /*
    cout<<line_test;
    */

    ll t=-1;
    while (1)
    {
        t+=1;
        getline(cin, line_1) ;
        if(cin.eof()) break;
        /*
        debug("line_1",line_1);
        */

        istringstream iss1(line_1);
        ll g, b, c, nM;
        iss1>>g>>b>>c>>nM;
        c+=1;//increasing val so gi-bi>=ci
        /*
        debug4("pqcM",g,b,c,nM)
        */

        //if(g-b<c) {cout<<0;return 0;}

        set< pll > PAM;
        vector< vll > dp_(2, vll(g+1,0));
        vector< vll > dp;
        rep(i,0,nM)
        {
            getline(cin, line_2);
            istringstream iss2(line_2);
            pll tmp;
            iss2>>tmp.first>>tmp.second;
            ll b_=tmp.second, g_ =tmp.first;
            ll r=g_-b_;
            if((r >= c) && (g_<=g && b_<=b) ) PAM.insert(tmp);

        }

        /*
        prall("PAM",PAM );
        prall("dp_", dp_);
        */
        dp_[0][0]=1;

        rep(gi,1,g+1)
        {
            pll tmp; tmp.first=gi, tmp.second=0;
            if(present(PAM,tmp) ) dp_[0][gi]=0;
            else
            {
                dp_[0][gi]=dp_[0][gi-1];
            }
        }
        //dp.pb(dp_[0]);


        /*
        prall("dp_", dp_);
        */

        ll res=0;
        rep(bi,1,b+1)
        {
            ll bip=bi-1;//bi previous
            ll bip_=bip%2;
            ll bi_=bi%2;
            //fill(all(dp_[bi_]), 0);
            //debug("bi",bi);

            dp_[bi_][bi+c-2]=0;
            rep(gi,bi+c-1,g+1)
            {
                pll tmp;
                tmp.first=gi, tmp.second=bi;
                if(present(PAM,tmp)) {dp_[bi_][gi]==0; continue;}

                ll r_01= gi-(bi-1);// reputation previous to doing the bad deed
                ll r_10=(gi-1) -(bi);
                //ll ep= rp-c;//excess prev
                //ll nbd=rp-c+1;//no of possible bad deeds which can be done with current reputation
                //debug("nbd", nbd);


                //debug("\t|gi\n\t|>>", gi);
                dp_[bi_][gi]= (dp_[bip_][gi])+ dp_[bi_][gi-1] ;

                //debug3("\t|r_01, r_10, dp_[bi_][gi]\n\t|>>", r_01, r_10, dp_[bi_][gi]);
                /*
                cout<<"\n\tdp_["<<bi_<<"]["<<gi<<"]"<<dp_[bi_][gi]<<"+=dp_["<<bip_<<"]["<<gi<<"]"
                <<dp_[bip_][gi]<<"+ ("<<(gi>0)<<")?("<<"dp_["<<bi_<<"]["<<gi-1<<"] "<<dp_[bi_][gi-1] <<"):("<<0<<")";
                */
            }
            //dp.pb(dp_[bi_]);
            /*
            prall("dp_",dp_[bi_]);
            */
            if(bi==b) res=dp_[bi_][g];
        }
        /*
        prall("dp_", dp_);
        debug("res", res);
        */
        cout<<res%(mod);
        //prall("dp",dp);
        //debug("res", res);


    }
    return 0;

}
