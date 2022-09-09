/*
ID: taurusd1
TASK: HMAPPY
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
#define debug(m,x) cout <<"\n"<<(m)<<" "<<#x<<" "<< (x);
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

struct lala
{
    ll a,b,x;
    ll indx;

public:
    ll axb(){ return a*b;}
    //Overloading operator<< for struct person as a free function
     ostream& operator<< ( ostream& os) ;// if i do (person:: operator<<) then this will automatically be appended as a third argument and hence will have to remove person& p

};
ostream& operator<< ( ostream& os, lala l) // if i do (person:: operator<<) then this will automatically be appended as a third argument and hence will have to remove person& p
    {
        os << "( "<<(l.a)<<", "<<(l.b )<<", "<< ( l.x)<<" ) ";
        return os;
    }

//my lower_bound function
template<class T, class Compare>
T my_lower_bound(vector<lala> vlala,T first, T last, const T& value, Compare comp)
{
    /*NOTE: range is [first,last)*/

    /********************
    *About Variables:
    *********************
    *first-------->first indx
    *last-------->last indx
    *count----->no of elements i.e. last-first
    *step-------> no of elements/2 i.e. count/2
    *indx------->middle indx
    ***********************/
    ll indx;//ForwardIt it;
    ll count, step;//typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = last-first;//std::distance(first,last);

    while (count > 0) {

        step = count / 2;
        indx=first+step;//std::advance(it, step);
        //debug4("*lower_bound",count, first,indx, step)
        if (comp(indx, value)) {//if (comp(*it, value)) {
            first = ++indx;//means
            count -= step + 1;
            //debug4("*lower_bound",count, first,indx, step)
        }
        else
        {
            count = step;
            //debug4("*lower_bound",count, first,indx, step)
        }

    }
    return first;//the answer is basically in first
}

class HMAPPY
{
    //By default data members are private
    ll N,M;
    vector<ll> A,B;
    vector<lala> vlala;

public:
    //constructor
    HMAPPY()
        :N
            (
             //Lambda for taking input and returning the value
                [=](){
                    ll N;cin>>N;
                    A.resize(N);B.resize(N);vlala.resize(N);
                    return N;
                }
                ()//calling the lambda
            )
        ,M
            (
             //Lambda for taking input and returning the value
                [=](){
                    ll M;
                    cin>>M;
                    return M;
                }
                ()//calling the lambda
            )
        ,A
        (
            //Lambda for accepting a vector
            [=]()
            {
                vll A(N);
                rep(i,0,N)
                {
                    cin>>A[i];
                }
                return A;
            }
            ()//calling lambda
        )
        ,B
        (
            //Lambda for accepting a vector
            [=]()
            {
                vll B(N);
                rep(i,0,N)
                {
                    cin>>B[i];
                }
                return B;
            }
            ()//calling lambda
        )
        ,vlala
            (
                //Lambda accepting a vector
                [=]()
                {
                    vector<lala> vlala(N);
                    rep(i,0,N)
                    {
                    vlala[i]=lala{A[i],B[i],0};
                    }
                    return vlala;
                }
                ()//calling the lambda
            )
        {
        };

    void solve()
    {
        /*
        APPROACH:
        -sort vlala based on a*b in asc
        -initially assume all candies are distributed. We have M balloons to distribute.
        -in th range of no_candies[0, max(a[i]*b[i] for all i) +1),
         preform binary search on the specified range and find the lower_bound value(denoted by _lb)  in range which satisfies
         (required_balloons for getting max_candies_distributed on any day < =M)
        - the answer is _lb
        */

        /****************
        *cmp function*
        ******************
        sorting vlala based on:
        asc a*b===>asc b===> asc a
        ******************/
        auto cmp=
        [](lala l, lala r)
        {
            if(l.a *l.b < r.a*r.b)
            {
                return true;
            }
            else if(l.a*l.b == r.a*r.b)
            {
                 if(l.b<r.b)
                 {
                     return true;
                 }
                 else if(l.b==r.b)
                 {
                     if(l.a<r.a)
                     {
                         return true;
                     }
                 }
            }
             return false;
        };
        //sort vlala
        sort(all(vlala),cmp);

        /**********************
        *compare function*
        ***********************
        Return the first element greater_than/equal to bounding_value(bv)
        ***********************/
        auto cmp_less_than=
        [&](ll indx, ll bv)
        {
            //debug2("", indx,bv)
            /**********************
            *About Variables:
            ***********************
            *note: bv in this case is M
            *note: indx is the value to which we want to reduce the no of candies to
            *max_candies-------------->upper bound to the no of candies that would be given out on any day
            *balloons required-------->balloons required to reduce the no of candies by delta_c
            *delta_c---------------------->intended reduction in no. of candies
            *equivalent_delta_b------>no of balloons we would give to reduce the no of candies given by delta_c
            *******************************/
            ll max_candies,j, balloons_required;
            for( max_candies=indx, j =vlala.size()-1, balloons_required=0; vlala[j].axb()>=max_candies ; --j)
            {
                //vlala[j].x+=min(vlala[j].a, rM);
                ll WOAH=( vlala[j].b-1);// factor  so that  no_of_candies given on any day<=max_candies
                ll delta_c=vlala[j].axb()-max_candies +WOAH;
                ll equivalent_delta_b=delta_c/vlala[j].b ;
                balloons_required+=equivalent_delta_b;
                //debug4("\t",j,delta_c,equivalent_delta_b, balloons_required)
            }

            //debug3("cmp returns:",balloons_required,bv,balloons_required>=bv)
            return balloons_required>bv;
        };

        ll ___lb=my_lower_bound(vlala,0LL, vlala.back().axb()+1,M,cmp_less_than);
        cout<<___lb<<endl;
    }
};

int main ( )
{
	freopen("inHMAPPY.txt","r",stdin);//redirects standard input
    HMAPPY().solve();
	return 0;
}
