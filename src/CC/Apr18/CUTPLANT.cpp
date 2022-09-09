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
    os << "]";
    return os;
}

// Overloading << operator for vectors
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions

int main()
{

    freopen("inCUTPLANT.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    string line_test, line_N, line_A, line_B;
    ll T;
    getline(cin, line_test) ;
    /*
    cout<<line_test;
    */

    ll t=-1;
    while (1)
    {
        t+=1;
        ll N;
        //cin>>N;//
        getline(cin, line_N) ;
        /*
        cout<<"\n"<<line_N;
        */
        getline(cin, line_A) ;
        getline(cin, line_B);
        if(cin.eof()) break;

        vll A_, B_;//original
        vll Bpk, Avlly, Advlly;//Bpeaks, Avalleys, deepest Avalley between consecutive Bpeaks
        vll AvBp;
        bool B_greater_A=false;

        istringstream issA(line_A);
        ll n;
        istringstream issB(line_B);

        while (issA >> n){ A_.pb(n); }
        while (issB >> n){ B_.pb(n); ll i=B_.size()-1; if(B_[i]>A_[i]) {B_greater_A=true; } }
        /*
        if(A_.size()!= B_.size()) cout<<"\nI/p Error";
        */
        N=A_.size();

        /*
        prall("A_",A_);
        prall("B_",B_);
        */


        //rep(i,0,N) {cin>>A_[i]; }
        //rep(i,0,N) {cin>>B_[i];  if(B_[i]>A_[i]) B_greater_A=true;}
        if(B_greater_A) {cout<<((t!=0)?("\n"):(""))<<-1; continue;}


        //Bpk, Avlly, Advlly population
        Avlly.pb(0);
        Bpk.pb(0);
        ll av=A_[0];
        rep(i,1,N)
        {


            ll prv=B_[i-1], curr=B_[i], nxt=(i<N-1) ?B_[i+1]: nxt;

            {//scope manipulation to avoid redefining separate set of variables
                ll prv=A_[i-1], curr=A_[i], nxt=(i<N-1) ?A_[i+1]: nxt;
                if((i<N-1)?(prv>curr && curr<=nxt):1){Avlly.pb(i);}
                if(av>curr) av=curr;
            }

            if((i<N-1)?(prv<curr && curr>=nxt):1 )
            {
                Bpk.pb(i);
                Advlly.pb(av);
                av=A_[i];
            }
        }
        insert_iterator < vll > it(AvBp, AvBp.end()) ;
        merge(all(Avlly), all(Bpk), it );
        AvBp.erase( unique(all(AvBp)), AvBp.end());


        /*
        prall("Bpk",Bpk);
        prall("Advlly",Advlly);
        prall("AvBp", AvBp);
        */

        //
        set<ll> cntnue;
        ll cnt=0;

        if(B_[0] < A_[0] ) { cntnue.insert(B_[0]); }
        rep(i,1,AvBp.size())
        {
            ll p_vp=AvBp[i-1], c_vp=AvBp[i];
            /*
            debug4("\t|(p_vp, c_vp) , (B_p_vp, B_c_vp) \n\t|",p_vp, c_vp, B_[p_vp], B_[c_vp]);
            */
            rep(i,p_vp+1, c_vp+1)
            {
                if(B_[i] < A_[i]) cntnue.insert(B_[i] );
            }
            /*
                debug("\t\t|", B_[i]);
                */
            // remove elements from cntnue < B_[c_vp]  && >A_[c_vp]
            //Lower bound(elem): first element >=elem
            auto itlb= cntnue.lower_bound(B_[c_vp]);
            if(itlb != cntnue.begin())
            {
                cnt+=distance(cntnue.begin(),itlb);
                /*
                debug("\t|del\n\telem<B_c_vp",B_[c_vp]);
                prrange("\t|>>",cntnue,0,distance(cntnue.begin(),itlb) );
                */
                cntnue.erase(cntnue.begin(),itlb);
            }

            //Upper bound(elem): first element>elem
            auto itub=cntnue.upper_bound(A_[c_vp]);
            if(itub != cntnue.end())
            {
                cnt+=distance(itub, cntnue.end());
                /*
                debug("\t|del\n\telem>A_c_vp",A_[c_vp]);
                prrange("\t|>>",cntnue,distance(cntnue.begin(),itlb),cntnue.size() );
                */
                cntnue.erase(itub, cntnue.end());
            }

            /*
            prall ("\t|c",cntnue);
            */

            /*
            cout<<"\n\t/\\";
            prall ("\t|c",cntnue);
            debug("\t|cnt", cnt);
            cout<<"\n\t|__________";
            */



        }
        cnt+=cntnue.size();
        cntnue.clear();
        /*
        debug("cnt", cnt);
        cout<<"\n|_____________";
        */
        cout<<((t>0)?("\n"):(""))<<cnt;




    }
    return 0;

}
