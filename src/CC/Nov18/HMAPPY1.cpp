/*
ID: taurusd1
TASK: HMAPPY1
LANG: C++14
*/

#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
using namespace std;

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

const ll mod = (ll)(1e9 + 7);
const LD PI =(LD)acos(-1);
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define some(c,l,r) next((c).begin(),l),next((c).begin(),r-1) //Range:[l.r)
#define rall(c) (c).rbegin(),(c).rend()
#define rsome(c,l,r) next((c).rbegin(),l),next((c).rbegin(),r-1) //Range:[l.r)
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define trr(c,i) for(auto i = (c).rbegin(); i != (c).rend(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define repc(c,i,l,r) for (auto b = next(c.begin(),(l)),i=b, e=next((c).begin(),(r)); i!=e; ++i)//Range:[l.r)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define prall(m,arr) {cout<<"\n"<<(m); for (auto it = arr.begin(); it != arr.end(); ++it) cout << (*it) << " ";}
#define prrange(m,c,l,r) {cout<<"\n"<<(m);for (auto b = next(c.begin(),(l)),i=b, e=next(c.begin(),(r)); i != e; ++i) cout << (*i) << " ";}//Range:[l/r)
#define debug(m,x) cout <<"\n"<<(m)<<#x<< (x);
#define debug2(m,x,y) cout <<"\n"<<(m)<<" "<<#x << ", "<<#y<<"| "<< (x) << " " << (y);
#define debug3(m,x,y,z) cout <<"\n"<<(m)<<" "<<#x<<", "<<#y<<", "<<#z<<"| "<< (x) << " " << (y) << " " << (z);
#define debug4(m,w,x,y,z) cout <<"\n"<<(m)<<" "<<#w<<", "<<#x<<", "<<#y<<", "<<#z<<"| "<<(w)<<" "<< (x) << " " << (y) << " " << (z);
#define _(x) cout <<"\n"<< (#x) <<" "<< (x) ;


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

// Overloading << operator for sets
template < class T >
ostream& operator << (ostream& os, const set<T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for deque
template < class T >
ostream& operator << (ostream& os, const deque<T>& v)
{
    os << "[";
    for (auto ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

// Overloading << operator for vector<vector>
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
        os << "\n" << *ii;
    }
    os << "]";
    return os;
}

//print a set of variables in one line
void pline(string message, ll indent_variable/*variable nof parameters*/)
{

}

/**HMAPPY1**/
/*Chef has a sequence A1,A2,…,AN; each element of this sequence is either 0 or 1.
Appy gave him a string S with length Q describing a sequence of queries. There are two types of queries:

'!': right-shift the sequence A, i.e. replace A by another sequence B1,B2,…,BN satisfying Bi+1=Ai for each valid i and B1=AN
'?': find the length of the longest contiguous subsequence of A with length ≤K such that each element of this subsequence is equal to 1
Answer all queries of the second type.

Input
The first line of the input contains three space-separated integers N, Q and K.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains a string with length Q describing queries. Each character of this string is either '?', denoting a query of the second type, or '!', denoting a query of the first type.
Output
For each query of the second type, print a single line containing one integer — the length of the longest required subsequence.

Constraints
1≤K≤N≤105
1≤Q≤3⋅105
0≤Ai≤1 for each valid i
S contains only characters '?' and '!'
Subtasks
Subtask #1 (30 points):

1≤N≤103
1≤Q≤3⋅103
Subtask #2 (70 points): original constraints

Example Input
5 5 3
1 1 0 1 1
?!?!?
Example Output
2
3
3
/**/

/**/


//class HMAPPY1
//About members of the class:
/*
Member variables:
ll N,Q,K----------------------------------------------------------->As Defined in

Member functions:

HMAPPY1()------------------------->Constructor
void solve()-------------------> Self Explanatory

*/
    struct group
    {
        ll l, r;
        bool is1;
        group()
        :l()
        ,r()
        ,is1()
        {
            l=-1, r=-2;
            is1=false;
        }
        /**
        group(ll _l, ll _r,bool  _is1)
        :l(_l)
        ,r(_r)
        ,is1(_is1)
        {
        }
        /**/
        group(ll _l, ll _r)
        :l(_l)
        ,r(_r)
        ,is1()
        {
            is1=false;
        }
        //operator =,[],->,() must be alway implemented as member functions, other operators can be implemented  as non members
        group& operator=(const group&);
        bool operator==(const group&);
        bool operator!=(const group&);
        void set_is1(ll val)
        {
            if(val==1)
            {
                is1=true;
            }
            else
            {
                is1=false;
            }
            return;
        }
        ll delta()
        {
            return r-l+1;
        }
        ll delta(ll start, ll N)
        {
            ll b=start, e=start+N-1;
            //within range of [b,e]
            ll l1=l,r1=r;
            if(l<b)
            {
                l1=b;
            }
            else if (l>e)
            {
                l1=e;
            }
            if(r<b)
            {
                r1=b;
            }
            else if(r>e)
            {
                r1=e;
            }
            return r1-l1+1;
        }
    };

    ostream& operator<< (ostream& os, const group& grp)
    {
        os << "G"+to_string(grp.is1)+"["<< grp.l<<","<<grp.r<< "]";
        return os;
    }

    group& group::operator=(const group& other)
    {
        this->l=other.l;
        this->r=other.r;

        return *this;
    }
    bool group::operator==(const group& other)
    {
        return (this->l==other.l && this->r==other.r);
    }
    bool group::operator!=(const group& other)
    {
        return !(*this == other);
    }
class HMAPPY1
{
//By default data members are private
//
ll N, Q, K;
vll A;
string strQ;
vector<vector<ll > > store;
vector<group> vg;
vector<pll > vgno ;

public:
HMAPPY1()
    :N()
    ,Q()
    ,K()
    ,A()
    ,strQ()
    ,store()
    ,vg()
    ,vgno()
    {
        cin>>N>>Q>>K;
        A.resize(2*N);
        rep(i,0,N)
        {
            cin>>A[i];
            A[i+N]=A[i];
        }
        cin>>strQ;
    };
    void test()
    {
        vector< vector<ll> > vvA
        =vector<vector<ll> >{
            /*{0},{1}
            ,{0,0},{1,1},{0,1},{1,0}
            ,{0,0,0}, {1,0,0}, {0,1,0},{0,0,1},{1,1,0},{0,1,1},{1,1,1}
            ,*/{0,0,0,0},{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1},{1,1,0,0},{1,0,1,0},{1,0,0,1},{0,1,1,0},{0,1,0,1},{0,0,1,1},{1,1,1,0},{1,1,0,1},{1,0,1,1},{0,1,1,1},{1,1,1,1}
            };
        vector<string> vstrQ(vvA.size(),"");
        rep(i,0,vvA.size())
        {
            rep(j,0,vvA[i].size())
            {
                vstrQ[i]+="?!";
            }
            N=vvA[i].size()
            ,Q=vstrQ[i].size()
            ,K=2*vvA[i].size()
            ,A=vvA[i]
            ,strQ=vstrQ[i]
            ,store.resize(0)
            ,vg.resize(0)
            ,vgno.resize(0);

            A.resize(2*N);

            rep(i,0,N)
            {
                A[i+N]=A[i];
            }
            debug3("TEST-----",(vll{i,N,Q,K}),A,strQ)
            solve();
        }

        return;
    }
    /**/
    void compute(vector<ll >& res)
    {
        ll b,e;

        b=0, e=N-1;
        ll gb=vgno[b].first, ge=vgno[e].first;
        string s="\n gb, ge:"+ to_string(gb)+" "+ to_string(ge);
        if(A[b]==0)
        {

            gb+=1;
            s+="\n new gb "+to_string(gb);
        }
        if(A[e]==0)
        {
            ge-=1;
            s+="\n new ge "+to_string(ge);
        }
        if(gb>ge)
        {
            res[b]=-1;
            s+="\n gb>ge";
        }
        else
        {
            s+="\n gb<=ge";
            ll gg=gb;
            for(ll g=gb; g<ge+1;++g)
            {
                if(vg[g].is1)
                if(vg[g].delta(0,N) >=vg[gg].delta(0,N))
                {
                    gg=g;
                }
            }
            res[b]=gg;
        }
        cout<<s<<endl;

       for(ll i=1;i<N;++i)
        {
            b=i, e=i+N-1;
            debug2("",b,e)
            gb=vgno[b].first, ge=vgno[e].first;
            ll gg=res[i-1];
            string s="\n gb, ge:"+ to_string(gb)+" "+ to_string(ge);
            if(A[b]==0)
            {

                gb+=1;
                s+="\n new gb "+to_string(gb);
            }
            if(A[e]==0)
            {
                ge-=1;
                s+="\n new ge "+to_string(ge);
            }
            if(gb>ge)
            {
                res[b]=-1;
                s+="\n gb>ge";
            }
            else
            {
                s+="\n gb<=ge";
                vector<pll > t
                =
                {
                    make_pair(vg[gb].delta(b,N),gb)
                    ,make_pair(vg[ge].delta(b,N),ge)
                    ,make_pair((gg==-1)?(-1ll):(vg[gg].delta(b,N)),gg)
                };
                cout<<s;
                debug("",t)
                sort(all(t));

                res[i]=t.back().second;

            }


        }
        debug("",res)
        return;
    }
    void compute0()
    {

        ll b,e;
        b=0, e=2*N-1;
        group XXX=group(-1,-2);
        group m, r;
        vgno.resize(e-b+1);

        store.push_back(vll{0});
        vgno[b]=pll{0,0};
        debug("",store)

       for(ll i=b+1;i<e+1;++i)
        {
            if(A[i-1])
            {
                if(A[i])
                {
                    store.back().push_back(i);
                    vgno[i]=pll{store.size()-1, store.back().size()-1};
                }
                else
                {
                    store.push_back(vll{});
                    store.back().push_back(i);
                    vgno[i]=pll{store.size()-1, store.back().size()-1};
                }
            }
            else
            {
                if(A[i])
                {
                    store.push_back(vll{});
                    store.back().push_back(i);
                    vgno[i]=pll{store.size()-1, store.back().size()-1};
                }
                else
                {
                    store.back().push_back(i);
                    vgno[i]=pll{store.size()-1, store.back().size()-1};
                }
            }

            /**
            debug2("",i,store.back())
            /**/
        }
        debug("",store)
        debug("",vgno)
        vg.resize(store.size());
        rep(i,0,store.size())
        {
            vg[i]=group(store[i].front(),store[i].back());
            vg[i].set_is1(A[store[i][0] ]);
        }
        debug("",vg)
        return;

    }
    void solve()
    {
        /**
        APPROACH:
        /**/
        debug("",A)
        /**/

        ll start=0;
        group XXX={-1,-2};
        vector<ll> res(N,-1);
        compute0();
        compute(res);
        if(N==1)
        {
            if(A[0]==1)
                res[0]=0;
        }
        for(ll q=0;q<Q;++q)
        {
            if(strQ[q]=='!')
            {
                start+=1;
                start%=N;

            }
            else if(strQ[q]=='?')
            {
                /**/

                ll ans=0;
                if(res[start] !=-1)
                    ans=min(vg[res[start] ].delta(start,N), K);
                //cout<<ans<<endl;
            }
        }
        return;
    }
    /**/

};

int main ( )
{
    /**/
    freopen("inHMAPPY1.txt","r",stdin);//redirects standard input
    /**/
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object

    /**/
    HMAPPY1().test();
    /**
    HMAPPY1().solve();
    /**/
	return 0;
}

