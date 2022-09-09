/*
ID: taurusd1
TASK: sprime
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



/**sprime**/
/*
Superprime Rib
Butchering Farmer John's cows always yields the best prime rib. You can tell prime ribs by looking at the digits lovingly stamped across them, one by one, by FJ and the USDA. Farmer John ensures that a purchaser of his prime ribs gets really prime ribs because when sliced from the right, the numbers on the ribs continue to stay prime right down to the last rib, e.g.:

     7  3  3  1
The set of ribs denoted by 7331 is prime; the three ribs 733 are prime; the two ribs 73 are prime, and, of course, the last rib, 7, is prime. The number 7331 is called a superprime of length 4.

Write a program that accepts a number N 1 <=N<=8 of ribs and prints all the superprimes of that length.

The number 1 (by itself) is not a prime number.

PROGRAM NAME: sprime
INPUT FORMAT
A single line with the number N.
SAMPLE INPUT (file sprime.in)
4
OUTPUT FORMAT
The superprime ribs of length N, printed in ascending order one per line.
SAMPLE OUTPUT (file sprime.out)
2333
2339
2393
2399
2939
3119
3137
3733
3739
3793
3797
5939
7193
7331
7333
7393
/**/

/*ABOUT VARIABLES USED*
N------------------------> As Defined in input format
/**/

//class SPrime
//About members of the class:
/*
Member variables:
N----------------------------->As Defined in
vll pal_a2b;------------------>vector storing all Odd(length) Palindromes between a and b
vll primes;-------------------->vector storing all primes upto sqrt(max_b)
vll vpri_pal;------------------->vector storing primes nos in the range:[a,b]

Member functions:

vll primes_upto(ll)----------->Return a sorted (ascending order) vector of all primes upto a given number, N
bool ispal(ll)------------------->checking if the number passed is a palindrome( without using strings)
string rev_str(string)-------->Returns the reverse of the passed string
ll stoll(string)------------------>std::stoll with error handling(empty string passed are converted to 0)
bool in_range(string, ll, ll)-> in_range(s,a,b) will checks if the string s, is in the allowed range:[a,b+1)
void solve()-------------------> Self Explanatory

*/
class SPrime
{
//By default data members are private
//
ll N;
vll primes;// vector storing all primes upto sqrt(max_b)

public:
SPrime()
    :N
        (
         //Lambda for taking input and returning the value
            [=](){
                ll _R;cin>>_R;
                return _R;
            }
            ()//calling the lambda
        )
    ,primes()
    {
    };

    /*****************
    *primes_upto*
    ******************/
    /*Return a sorted (ascending order) vector of all primes upto a given number, N*/
    vector<ll> primes_upto(ll N)
    {
        vector<bool> IP(N,true);//IsPrime
        vector<ll> PUN;//PrimesUptoNow
        for(ll i=2;i*i<N+1;++i)
        {
            if(!IP[i]) continue;

            //possibly prime
            for(ll j=0;j<PUN.size();++j)//traversing all the primes numbers found upto now
            {
                if( i%PUN[j]==0)
                {
                    IP[i]=false;
                }
            }
            if(IP[i])//definitely prime as undergone checking
            {
                PUN.push_back(i);
                //all multiples of numbers less than i have been marked as non prime so,
                // if k<i, then k*i being a multiple of  k(which is <i ) ===>IP[k*i] would have been marked as false before
                //choose k>i such that k is prime(possibly) and if IP[k*i] ==true, mark IP[k*i] as false
                for(ll k=i;k*i<N+1;++k)
                {
                    if(IP[k*i])
                    IP[k*i]=false;
                }
            }
        }
        // Note: PUN contains primes only up to sqrt(N)
        //Hence, we have to populate PUN  with  remaining primes (i.e where, sqrt(N) < primes <= N) )
        rep(i,floor(sqrt(N)),IP.size())
        {
            if(IP[i])
            {
                PUN.push_back(i);
            }
        }
        return PUN;
    }

    void solve()
    {
        /*
        APPROACH:

            1.Possible suffixes for super primes of length >=2 {1,3,7,9}
            2.Generate a sorted vector, primes of all primes less than sqrt(1e8) (or better up to sqrt( max_b))

            3.Let us store all the super primes of length, len in res[len]
            Initially, res[1]={2,3,5,7}
             repeat Vlen s.t. len E sequence{2 ... N}
                repeat Vr s.t. r E res[len-1]
                    repeat Vsf s.t. sf E suffx
                        let super_prime<-res[len-1]*10+sf
                        let is_super<-true
                        repeat Vp s.t.
                                {
                                    p E sequence( x | x E primes)
                                    , p*p< super_prime
                                }
                            if(super_prime%p==0)
                                is_super<-false
                        if(is_super)
                            res[len] = res[len] U {super_prime}


            4.Print out result


        */
        //1.
        vll suffx={1,3,7,9};

        //2.
        primes=primes_upto(1e4);

        //3.
        vector<vll >res(N+1);
        res[1]={2,3,5,7};
        /**
        debug("",primes)
        debug("",res)
        /**/
        for(ll i_n=2; i_n<=N;++i_n)
        {
            for(ll j=0;j<res[i_n-1].size(); ++j)
            {
                /**
                debug("\t", res[i_n-1][j])
                /**/
                for(ll jj=0; jj<suffx.size();++jj)
                {
                    ll poss_super=res[i_n-1][j]*10 +suffx[jj] ;
                    /**
                    debug("\t\t", poss_super)
                    /**/
                    bool is_super=true;
                    for(ll k=0; primes[k]*primes[k]<poss_super+1;++k)
                    {
                        /**
                        debug("\t\t\t", (vll{primes[k]}))
                        /**/
                        if(poss_super% primes[k]==0)
                        {
                            is_super=false;
                            break;
                        }
                    }
                    /**
                    debug("\t\t\t",(vll{i_n,j,jj,poss_super, is_super}))
                    /**/
                    if(is_super)
                    {
                        res[i_n].push_back(poss_super);
                    }
                }
            }
            /**
            debug("after",res[i_n])
            /**/
        }

        //4.
        //printing out result
        rep(i,0,res[N].size())
        {
            cout<<res[N][i]<<endl;
        }
    }
};

int main ( )
{
    /**
    freopen("in.txt","r",stdin);//redirects standard input
    /**/
	freopen("sprime.in","r",stdin);//redirects standard input
    freopen("sprime.out","w",stdout);//redirects standard output
    /**/
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object
    SPrime().solve();
	return 0;
}
