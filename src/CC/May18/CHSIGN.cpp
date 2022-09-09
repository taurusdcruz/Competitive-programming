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
#define prall(m,arr) {cout<<""<<(m) ; for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m) ;for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}
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

struct haha
{

    ll A_indx, mns_m1, mns_p1;

public:
    void ass(ll, ll, ll) ;


};

void haha::ass( ll param1, ll param2, ll param3)
    {
        A_indx=param1, mns_m1=param2, mns_p1=param3;
    }


ostream& operator << (ostream& os, haha& h)
{
    os << " ("<<h.A_indx<<", "<<h.mns_m1<<", "<<h.mns_p1<<") ";
    return os;
}

int main()
{
    freopen("inCHSIGN.txt","r",stdin);//redirects standard input
    //freopen("out.txt","w",stdout);//redirects standard output

    ll T, N;
    cin>>T;

    rep(t,0,T)
    {
        cin>>N;
        vll A(N);
        vector< pll > Avlly;
        vll Asmhll ; //A sum of heigths over hill
        ll smhll=0;
        rep(i, 0, N)
        {
            cin>>A[i];
            //A[0] check
            if(i==1) if(A[0]<A[1]) { Avlly.pb(pll(0,-A[0])); Asmhll.pb(smhll); A[0]*=-1;smhll=0;} else {smhll=A[0];/*Avlly.pb(pll(-1,0);*/}
            if(i>1)
            {
                if(A[i-2]> A[i-1] && A[i-1]<A[i]) { Avlly.pb(pll(i-1,-A[i-1])), Asmhll.pb(smhll); A[i-1]*=-1;smhll=0;} else smhll+=A[i-1];
            }

            //A[N-1] check
            if(i>=N-1) if(A[N-1]<A[N-2]) { Avlly.pb(pll(N-1,-A[N-1])), Asmhll.pb(smhll); A[N-1]*=-1;smhll=0;} else {smhll+=A[N-1];Asmhll.pb(smhll);smhll=-1; /*Avlly.pb(pll(-1,0));*/}
        }
        //debug("aft", A)
        //debug("aft", Avlly)
        //debug("", Asmhll)

        ll Ai, Av, Aip, Avp;//curr, prev vlly

        ll m1=0, p1=1;
        rep(i,1,Avlly.size())
        {
            vector< pll > tmp;//Avlly[i]
            if(Asmhll[i]<=abs(Avlly[i-1].se) + abs(Avlly[i].se) )
            {

                while( Asmhll[i]<=abs(Avlly[i-1].se) + abs(Avlly[i].se) )
                {
                     //debug3("\t|",Asmhll[i], abs(Avlly[i-1].se), abs(Avlly[i].se) )
                     if(tmp.empty()) tmp.pb(Avlly[i-1]);  tmp.pb(Avlly[i]);  i+=1; if(i>=Avlly.size()) break;
                }

                //debug("", tmp)
                vector< haha > mns;// triplet( Aindx, mns_m1, mns_p1)
                haha mns_tmp;
                mns_tmp.ass(tmp[0].fi, -abs(tmp[0].se), abs(tmp[0].se) );
                mns.pb(mns_tmp);

                //vll mtp(1,1), mtn(1,-1); // mask tmp positive, mask tmp negative . Mask of +1's, -1's
                rep(i,1, tmp.size())
                {
                    ll A_indx=tmp[i].fi;
                    ll mns_p1=abs(A[A_indx]) + min(mns[i-1].mns_m1, mns[i-1].mns_p1);
                    ll mns_m1= -abs(A[A_indx]) + mns[i-1].mns_p1 ;
                    mns_tmp.ass(tmp[i].fi, mns_m1, mns_p1 );
                    mns.pb(mns_tmp);
                    //debug("\t", mns_tmp)
                }
                ll mns_sz=mns.size();
                //prall("\nmns", mns)

                ll sgn;
                for(ll i= mns_sz-1; i>0; i-=1)
                {
                    ll A_indx=mns[i-1].A_indx;
                    ll A_abs=abs(A[A_indx]);
                    if(i==mns_sz-1)
                    {
                        sgn=(mns[i].mns_p1 <=  mns[i].mns_m1)?(p1):(m1) ;
                        if(sgn==p1) A[mns[i].A_indx]=abs(A[mns[i].A_indx]); else if(sgn==m1) A[mns[i].A_indx]=-abs(A[mns[i].A_indx]);
                        //debug4("\t<- |",i,  mns[i], A[mns[i].A_indx], sgn);
                    }

                    if(sgn==p1)
                    {
                        if(mns[i-1].mns_p1 <= mns[i-1].mns_m1) {  A[A_indx]=A_abs; sgn=p1;}
                        else { A[A_indx]=-A_abs; sgn=m1;}
                        //debug4("\t<-p1|",i-1,  mns[i-1], A[A_indx], sgn);
                    }
                    else
                    {
                        A[A_indx]=A_abs; sgn=p1;
                        //debug4("\t<-m1|",i-1,  mns[i-1], A[A_indx], sgn);
                    }
                }

            }


        }
        prall(((t>0)?("\n"):("")),A)
        //debug("res", A)

    }

    return 0;
}
