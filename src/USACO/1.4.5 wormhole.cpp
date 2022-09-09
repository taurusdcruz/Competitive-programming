/*
ID: taurusd1
TASK: wormhole
LANG: C++14
*/

#include <bits/stdc++.h>
#include <typeinfo>
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

struct wormhole
{
    ll x,y;
    bool is_last_wormhole;// the last  wormhole among all the wormholes for a particular y coordinate

public:

    wormhole(ll x_, ll y_, bool is_last_wormhole_): x(x_), y(y_), is_last_wormhole(is_last_wormhole_) {}
    wormhole(): x(-1), y(-1), is_last_wormhole(false){ }
};
ll factorial(ll n)
{
    if(n<0) return -1;
    else if(n==0) return 1;
    else if(n>0)
    {
        ll res=1;
        for(ll i=n; i>=1; i-=1)
        {
            res*=i;
        }
        return res;
    }
}
ll combination(ll n, ll r)
{
    ll res=1;
    for(ll i=n;i>=n-r+1;i--)
    {
        res*=i;
    }
    for(ll i=r;i>=1;i--)
    {
        res/=i;
    }
    return res;
}

/*
isloop

parameters:
1.Wrmhole Reduced Grid,
2.paired wormholes

returns:
a pair<bool, vll > of <is_there_a_loop ,one_sequence_of_indices_of_wormholes _which_results_in_a_loop>
*/
pair<bool, vll> isloop(vector< vector<pll> >& WRG, vector< vector<pll > >& pairedto, vector< vector< ll > >& coord2indx)
{
    //1.Populating >traversed< with false
    //2.Traversing the destined path beginning at all the wormholes and using WRG to go to next index

    pll EOR=pll(-1,-1);//End Of Row

    //1.
    vector<vector<bool> >traversed;// represents wormholes( the jump_from_wormholes , not the jump_to_wormholes )
    //initializing traversed with false
    //using the fact that traversed is the same shape as WRG
    rep(row,0,WRG.size())
    {
        traversed.pb(vector<bool>(WRG[row].size(), false));
    }

    //2.
    rep(Y,0, WRG.size())
    {
        rep(X,0, WRG[Y].size()-1)
        {
            ll Y_=Y, X_=X;
            auto traversed_=traversed;
            vll sequence;
            //scope manipulation to not loose the value of Y,X & traversed within whileloopA
            {
                ll Y=Y_, X=X_;
                auto traversed=traversed_;
                //whileloopA:
                while(1)
                {
                    //Traversing the current wormhole and the paired wormholes
                    //Updating the boolean values( setting locations of the traversed matrix to true corresponding to the coordinates of the paired wormholes)
                    //Updating Y, X to the paired wormholes coordinates
                    traversed[Y][X]=true;
                    //sequence.push_back(coord2indx[Y][X] );//debug
                    auto nxtW=pairedto[Y][X];
                    Y=nxtW.first, X=nxtW.second;
                    //traversed[Y][X]=true;//commented out because this is a jump_to_wormhole
                    //sequence.push_back(coord2indx[Y][X] );//debug

                    //if next wormhole(ie X+1 th col) in the current row (i.e Y th row) is in the current path traversed upto now( i.e. traversed[Y][X+1]== true),
                    //then it implies that the current set of pairings of wormholes has a cycle
                    if(traversed[Y][++X])
                    {
                        //sequence.push_back(coord2indx[Y][X] );//debug
                        return pair<bool, vll >{true,sequence};
                    }

                    //checking if EOR has been reached
                    //which would mean we still need to check for possible loops beginning with other wormholes
                    if(WRG[Y][X]==EOR)
                    {
                        break;
                    }
                }
            }
        }
    }
    return pair<bool, vll >{false, vll{} };
}

/*f

parameters:
1.
set(for uniqueness)
<
    of vector(representing rows)
    <
        of vector(representing cols)
        <
            of pair(representing the coord of the wormhole paired to the wormhole at a given {row,col})
            <
                of  long long int
            >
        >
    >
>
2.
Wormhole Reduced Grid,vector of pairs (of indexes)( of  paired wormholes),
3.
vector of bools telling which wormholes have already been paired,
4.
no of pairs remaining,
5.
count of the number of combinations of pairings of wormholes which result in an infinite loop upto now

returns:
void
*/
void f( vector< vector< ll > >& coord2indx,vector<pll >& indx2coord,
       vector< vector<pll> >& WRG, ll& N, vector<vector<vector< ll > > >& pairings_upto_now_with_inf_loop,
       vector<vector<pll > > pairedto, vector< vector<bool> > ispaired,ll no_of_unpaired_wormholes, ll& cnt, ll row1, ll col1, ll row2, ll col2)
{
    string f_status;
    if(no_of_unpaired_wormholes<0)
    {
        /*DEBUG
        cout<<"\n";rep(i,0,N-no_of_unpaired_wormholes) cout<<"->F\t";cout<<"->f checks4loop"<<N-no_of_unpaired_wormholes;//debug
        */
        bool decision;


        auto decision_sequence=isloop(WRG, pairedto,coord2indx);
        if(decision=decision_sequence.first)
        {
            cnt+=1;

            /*MAINLY DEBUG CODE
            //lambda function to convert vector< vector< pair<ll,ll> > > to vector< vector< ll > >
            //using coord2indx to replace the wormhole coord( pair<ll,ll>) to  wormhole index( long long int)
            auto f_indx=
            [&WRG, &coord2indx](vector< vector< pair<ll,ll> > > pairedto)-> vector< vector< ll > >
            {
                vector< vector< ll > > pairedto_indx;
                rep(row,0,WRG.size())
                {
                    pairedto_indx.push_back(vector< ll >{});
                    rep(col,0,WRG[row].size()-1)
                    {
                        pll paired_wormhole_coord=pairedto[row][col];
                        pairedto_indx[row].push_back(coord2indx[paired_wormhole_coord.first][paired_wormhole_coord.second]);
                    }
                }
                return pairedto_indx;
            };
            pairings_upto_now_with_inf_loop.push_back(f_indx(pairedto));

            /*DEBUG
            if(decision) debug("", decision_sequence.second)
            auto tick_cross=(decision)?("v/v/v/v/v/"):("XXXXX");
            debug("", tick_cross )
            debug("",f_indx(pairedto) )
            cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
            /**/

        }
        no_of_unpaired_wormholes=-1;//exit condition for recursion
    }
    else if(no_of_unpaired_wormholes>=0)
    {
        /*DEBUG
        cout<<"\n";rep(i,0,N-no_of_unpaired_wormholes) cout<<"->F\t";cout<<"->f called"<<N-no_of_unpaired_wormholes;//debug
        /**/

        if(no_of_unpaired_wormholes== N)
        {
            //beginning case
            // ispaired need to be filled initially with the first paired wormholes
            ispaired[row1][col1]=true;

            no_of_unpaired_wormholes+=-2;
        }
        //ispaired[row1][col1]=true;
        ispaired[row2][col2]=true;
        //no_of_unpaired_wormholes%2==0 --> we are looking for the first element of the ordered pair
        if(no_of_unpaired_wormholes%2 ==0)
        {
            pairedto[row1][col1]=pll{row2,col2};
            pairedto[row2][col2]=pll{row1,col1};
        }
        /*DEBUG
        debug("", ispaired)
        debug("",pairedto)//debug
        /**/
        if(no_of_unpaired_wormholes==0) f(coord2indx,indx2coord,WRG,N, pairings_upto_now_with_inf_loop,pairedto, ispaired, no_of_unpaired_wormholes-1, cnt, -1,-1,-1,-1);
        // OP_1,...OP_n, OP_n+1...
        //if we are looking for OP_n+1 (we have found upto OP_n )
        //and within OP_n+1 we are looking for:
        //- first element ie.(OP_n+1_elem_1)
        //  then we have to satisfy the condition that  OP_n_elem_1 < OP_n+1_elem_1

        //- second element ie.(OP_n+1_elem_2)
        //  then we have to satisfy the condition that  OP_n+1_elem_1 < OP_n+1_elem_2
        ll beg_indx=(no_of_unpaired_wormholes%2==0)?(coord2indx[row1][col1]+1):(coord2indx[row2][col2]+1);
        rep(indx,beg_indx, N)
        {
            ll row=indx2coord[indx].first, col=indx2coord[indx].second;
            if(ispaired[row][col]) continue;

            /*DEBUG
            if(no_of_unpaired_wormholes%2==0)
            {
                cout<<"\n";rep(i,0,N-no_of_unpaired_wormholes)cout<<"->L\t";cout<<"inside loop"<<""<<no_of_unpaired_wormholes<<" "<<pll(row1,col1)<<pll(row2,col2) ;//debug
                debug("",no_of_unpaired_wormholes)
                debug("",indx2coord[beg_indx])
                debug2("",row,col)
            }
            /**/
            ll row1_=row2, col1_=col2;
            ll row2_=row, col2_=col;
            f(coord2indx,indx2coord,WRG,N, pairings_upto_now_with_inf_loop,pairedto, ispaired, no_of_unpaired_wormholes-1, cnt, row1_,col1_,row2_,col2_);

        }


    }
    return;
}


int main ( )
{
	freopen("wormhole.in","r",stdin);//redirects standard input
    freopen("wormhole.out","w",stdout);//redirects standard output


    /*wormhole*/
    /*PROBLEM STATEMENT(in my words)

    //N wormholes (2 <= N <= 12, N even) to materialize on FJ's farm,
    //Each located at a distinct point on the 2D map of his farm (the x,y coordinates are both integers Each coordinate is in the range 0..1,000,000,000.).
    //FJ knows that his wormholes will form N/2 connected pairs
    // If wormholes A and B are connected as a pair, then:
    //      -any object entering wormhole A will exit wormhole B moving in the same direction,
    //      -and any object entering wormhole B will similarly exit from wormhole A moving in the same direction.
    //Bessie the cow always walks in the +x direction, although FJ does not remember where Bessie is currently located.
    //count the number of distinct pairings of the wormholes such that Bessie could possibly get trapped in an infinite cycle if she starts from an unlucky position.
    //(i.e., all the different ways that N wormholes could be paired such that Bessie can, in some way, get in a cycle).
    /**/

    /*SOLUTION
    Generate all possible combinations in an efficient way by ensuring ordering of the pairs of wormholes and ordering the pairs itself using f function
    At the end when all wormholes are paired, check the particular combination of wormhole pairs for a loop using isloop function
    /**/

    /*more general problem to practice
    Generate for N(0,...9) all combinations N choose r((0<=r<=N)
    /**/

    ll N;
    map<ll,set<ll> > WMS;// Map to set of x coordinates with same y coordinate, keyed by y coordinate
    vector< vector<pll> > WRG;// Wormholes Reduced Grid

    cin>>N;
    //debug("",N)//debug
    ll tX,tY;
    rep(i,0,N) { cin>>tX>>tY; ll row=tY, col=tX; WMS[row].insert(col);}
    //debug("",WMS)//debug

    // Reduced
    // problem with each wormhole in  each y coordinate separated by unit distance along x coordinate
    // beginning with sequence (y=y,x=0) ... (y=y,x=x)and ending with y=-1,x=-1 meaning the end of wormholes for that particular y coordinate

    //Populating WRG on traversing WMS
    pll W_coordinates;
    ll W_index=-1;
    tr(WMS,it)
    {
        ll Y=distance(WMS.begin(), it);
        auto set_of_Xes=(*it).second;//set of xes in current row
        //debug("",set_of_Xes)//debug
        vector<pll > row_of_WRG;

        rep(X,0,set_of_Xes.size() )
        {
            //pushing back in 2d vector of vector of pair at row-Y the reduced coordinates of wormhole i.e. row-Y, col-X
            //NOTE: you can also push back the non reduced coordinates  if you want
            row_of_WRG.pb(pll{Y,X});
        }
        //pushing back (-1,-1) meaning end of the wormholes in the current row
        row_of_WRG.pb(pll{-1,-1});
        WRG.pb(row_of_WRG);
        //debug("",WRG[Y])//debug
    }
    //debug("", WMS)//debug

    //assigning each coord a unique index which is stored in coord2indx[row][col]
    //and
    //mapping index of wormhole to the existing wormhole coordinate
    vector< pll > indx2coord;
    vector< vector< ll > > coord2indx;
    ll indx=0;
    rep(row,0,WRG.size())
    {
        coord2indx.push_back(vector< ll >{});
        rep(col,0,WRG[row].size()-1)
        {
            indx2coord.push_back(pll(row,col));
            coord2indx[row].push_back(indx);
            indx+=1;
        }
    }

    vector< vector<bool> > ispaired;
    //initializing ispaired with false
    //using the fact that ispaired is the same shape as WRG
    rep(row,0,WRG.size())
    {
        ispaired.pb(vector<bool>(WRG[row].size(), false));
    }
    vector< vector<pll > > pairedto;
    //resizing size of pairedto to the same size as WRG
    rep(row,0,WRG.size())
    {
        pairedto.pb(vector<pll >(WRG[row].size()-1));
    }

    ll cnt=0;
    ll no_of_unpaired_wormholes=N;
    ll row1,col1,row2,col2;
    vector<vector<vector< ll > > > pairings_upto_now_with_inf_loop;

    row1=0,col1=0;
    rep(indx,1,N)
    {
        row2=indx2coord[indx].first;
        col2=indx2coord[indx].second;

        f(coord2indx, indx2coord, WRG,N,pairings_upto_now_with_inf_loop,pairedto,ispaired,no_of_unpaired_wormholes,cnt, row1,col1,row2,col2);
    }

    /*DEBUG
    set< vector<vector< ll > > > set_of_pairings_upto_now_with_inf_loop(all(pairings_upto_now_with_inf_loop));
    cnt=set_of_pairings_upto_now_with_inf_loop.size();
    /**/


    cout<<cnt<<endl;
    /*DEBUG CODE
    debug("",cnt)
    debug("", pairings_upto_now_with_inf_loop)
    /**/


	return 0;
}
