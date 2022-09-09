
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
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i,a,b)	for( long long int i=a;i<b;i++)
#define MAX(x,y) ((x>y)?x:y)
#define MIN(x,y) ((x<y)?x:y)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
const LD EPS=1e-12;
const LD INF=1e100;
#define CORRECT( i, N ) ((i) +(((i)>(N)-1)?-((N)):(i)<0?+((N)):0))
#define SIGN(i) ((i)>0?+1:(i)<0?-1:0)
#define ADJ(i1,i2,i3,delta,ad) ((i1==0 || i1% i3==0 )?SIGN(delta):ad)



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//structures

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//functions
class C1{
    public:

    //function to initially populate the a istream's stream buffer using a custom_string
    //so as to save entering input in the console
    void test_populate_cin_buffer(){
        //format for raw sting literal:R"delimiter( raw_characters )delimiter"
        string custom_input=
            R"(
            1 2 3 4 5 6 7 8 9 10 
            xxxxxxDonexxxxx
            )";
        
        istringstream iss1(custom_input);   //istringstream to read and interpret input from sequences of characters
                                            //Note: istringstream is istream for strings
        ostringstream oss1;                 //ostringstream to write sequences of characters and represent other kinds of data
                                            //Note: ostrinstream is ostream for strings
        //simulating taking input from istringstream( instead of from cin) and writing to ostringsteam(instaad of cout)

        //read() operation
        string tmp;
        vector<string> vs;        
        while(iss1>>tmp){
            vs.push_back(tmp);            
        }

        //write() operation
        oss1<<"custom input ";
        for(auto tmp: vs){
            oss1<<tmp<<endl;
        }

        //printing oss1 to cout
        cout<<oss1.str()<<endl;

    }   
};

int main(){
    C1().test_populate_cin_buffer();
    return 0;
}




