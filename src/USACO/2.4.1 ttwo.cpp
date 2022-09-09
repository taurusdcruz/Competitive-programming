/*
ID: taurusd1
TASK: ttwo
LANG: C++14
CONCEPTS: 
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

/**Ttwo**
The Tamworth Two
BIO '98 - Richard Forster
A pair of cows is loose somewhere in the forest. Farmer John is lending his expertise to their capture. Your task is to model their behavior.

The chase takes place on a 10 by 10 planar grid. Squares can be empty or they can contain:

an obstacle,
the cows (who always travel together), or
Farmer John.
The cows and Farmer John can occupy the same square (when they `meet') but neither the cows nor Farmer John can share a square with an obstacle.
Each square is
represented
as follows:

. Empty square
* Obstacle
C Cows
F Farmer
Here is a sample grid:
*...*.....
......*...
...*...*..
..........
...*.F....
*.....*...
...*......
..C......*
...*.*....
.*.*......
The cows wander around the grid in a fixed way. Each minute, they either move forward or rotate. Normally, they move one square in the direction they are facing. If there is an obstacle in the way or they would leave the board by walking `forward', then they spend the entire minute rotating 90 degrees clockwise.

Farmer John, wise in the ways of cows, moves in exactly the same way.

The farmer and the cows can be considered to move simultaneously during each minute. If the farmer and the cows pass each other while moving, they are not considered to have met. The chase ends when Farmer John and the cows occupy the same square at the end of a minute.

Read a ten-line grid that represents the initial state of the cows, Farmer John, and obstacles. Each of the ten lines contains exactly ten characters using the coding above. There is guaranteed to be only one farmer and one pair of cows. The cows and Farmer John will not initially be on the same square.

Calculate the number of minutes until the cows and Farmer John meet. Assume both the cows and farmer begin the simulation facing in the `north' direction. Print 0 if they will never meet.

PROGRAM NAME: ttwo
INPUT FORMAT
Lines 1-10:	Ten lines of ten characters each, as explained above
SAMPLE INPUT (file ttwo.in)
*...*.....
......*...
...*...*..
..........
...*.F....
*.....*...
...*......
..C......*
...*.*....
.*.*......
OUTPUT FORMAT
A single line with the integer number of minutes until Farmer John and the cows meet. Print 0 if they will never meet.
SAMPLE OUTPUT (file ttwo.out)
49
/**/

/**/
//class Ttwo
//About members of the class:
/*
Member variables:
task---------------------------------->name of task

Member functions:
void Ttwo(ll task)------------------>Constructor
void open_streams()------------------->Open stream/'s
void read()--------------------------->Read from stream/'s
void solve()-------------------------->Implement logic to solve task(Non-Boiler-plate Code Here:P)
void write()-------------------------->Write to stream/'s
void close_streams()------------------>Close stream/'s

Additional Member functions(Non-Boiler-plate):

*/
template<typename T=LD>/*default value for template argument*/
class PT{


    public:
    T x,y;
    PT():x(T()),y(T()){};
    PT(T _x,T _y):x((T)_x),y((T)_y){};

    template<typename U>
    PT<T>& operator=(const PT<U>& rhs){
        return PT<T>(rhs.x,rhs.y);
    }

    PT<T>& operator+=(const PT<T>& rhs){
        //adding correspponding x and y coordinates
        this->x+=rhs.x;
        this->y+=rhs.y;
        return *this;
    }
    friend PT<T>& operator+(const PT<T>& lhs,const PT<T>& rhs){
        //adding correspponding x and y coordinates
        lhs.x+=rhs.x;
        lhs.y+=rhs.y;
        return lhs;
    }
};

//Class to do direction(N,S,E,W) calculations
template<typename T=long long, typename U=long long, typename BULL=long long >
class direction{
    public:
    //dir_indx2coord:   0-N,1-E,2-S,3-W
    //inline definition of static member(no need to define the declared static member outside the class)
    inline static vector<pair<T,T>> dir_indx2coord={pair<T,T>(1,0),pair<T,T>(0,1),pair<T,T>(-1,0),pair<T,T>(0,-1)};
    inline static map<pair<T,T>,T> dir_coord2indx{ pair<pair<T,T>,T>(pair<T,T>(1,0),0)
                                        ,pair<pair<T,T>,T>(pair<T,T>(0,1),1)
                                        ,pair<pair<T,T>,T>(pair<T,T>(-1,0),2)
                                        ,pair<pair<T,T>,T>(pair<T,T>(0,-1),3)  };
    // State<>::dir_indx2coord=dir_indx2coord;
    // State<>::dir_coord2indx=dir_coord2indx;
    inline static map<T,char> dirindx2arrow{ pair<T,char>(0,'^')
                                ,pair<T,char>(1,'>')
                                ,pair<T,char>(2,'v')
                                ,pair<T,char>(3,'<')   };

    //member functions
    // template<typename U=long long>
    inline T get_dir_indx(U dy, U dx){

        if(!((((ll)abs(dx))^((ll)abs(dy))) == 1)){ return -1;}
        return dir_coord2indx[pair<T,T>(dy,dx)];
    }
    
    // template<typename U=long long>
    inline pair<T,T> get_dir_coord(U&& idir){
        if(idir<0 or idir>3){ return pair<T,T>(-1,-1);}
        return dir_indx2coord[idir];
    }
    // template<typename U=long long>
    inline T rotate_90(U&& indx){
        indx=(indx+1)%(T)4;
        return (T)indx;
    }

    // template<typename U=long long>
    inline pair<T,T> rotate_90(pair<U,U>&& dir_coord){
        auto&& [dy,dx]=dir_coord;
        auto indx=move(direction<T,U>::get_dir_indx(dy,dx));
        rotate_90(indx);
        dir_coord=move(direction<T,U>::get_dir_coord(indx));
        return pair<T,T>(dir_coord);//reconstruct a pair from another pair
    }

    //Rotate a complex number clockwise by 90deg
    // template<typename U=long double>
    complex<long double> rotate_90(complex<U> z){
        auto z1=complex<U>(exp(-(PI/2)*1il));
        z1*=z;
        auto rad2deg=180.0l/PI;
        auto deg2rad=PI/180.0l;
        auto theeta= round((PI+arg(z1))*(rad2deg))*deg2rad;//round to the nearest degree
        z1=exp(theeta*1il);
        //z1=round(real)
        return complex<long double>(z1);
    }

    // //specialization of member functions
    // private:
    // inline void free_specializer(){

    // }

};


//Class to store the state at each point in the forest of the the Farmer/Cow
template<typename T=long long, typename U=long long>  //!!!T is the type which most of the functions return by !!!
class State : public direction<T,U>{     //using direction<T> in member functions of State to return values in T
    public:
    //store coordinates, direction & time
    T x
    ,y
    ,dx
    ,dy
    ,t
    ,idir
    ;
    //static variables for this problem

    //constructor
    State():State(-1,-1,-1,-1,-1){};
    State(T _x,T _y,T _dx,T _dy,T _t)
    :x(_x)
    ,y(_y)
    ,dx(_dx)
    ,dy(_dy)
    ,t(_t)
    {};

    // template<typename U=long long>
    //note: for the constructor the template arguments will be deduced  using template argument deduction
    State(State<U> rhs)
    :x(rhs.x)
    ,y(rhs.y)
    ,dx(rhs.dx)
    ,dy(rhs.dy)
    ,t(rhs.t)
    {};

    //member functions
    template<typename T1=long long,typename T2=long long>
    friend bool operator== ( State<T1> lhs,State<T2> rhs){
        // auto lhs=*this;
        return (   make_tuple(lhs.x,lhs.y,lhs.dx,lhs.dy)
                    == make_tuple(rhs.x,rhs.y,rhs.dx,rhs.dy)  );
    }

    template<typename T1=long long,typename T2=long long >
    friend bool operator< (State<T1> lhs,const State<T2>& rhs){
        // auto lhs=*this;
        return (   make_tuple(lhs.x,lhs.y,lhs.dx,lhs.dy)
                    <make_tuple(rhs.x,rhs.y,rhs.dx,rhs.dy)  );
    }

    //operator=() must be a non static member function
    // template<typename U=long long >
    State operator= ( const State<U> rhs){
        this->x=rhs.x;
        this->y=rhs.y;
        this->dx=rhs.dx;
        this->dy=rhs.dy;
        this->t=rhs.t;
        return *this;
    }

    // template<typename U=long long>
    inline T get_dir_indx(State<U> s){
        return direction<T>::get_dir_indx(s.dy,s.dx);
    }

    // template<typename U=long long>
    inline pair<T,T> get_dir_coord(State<U> s){
        return direction<T>::get_dir_coord(get_dir_indx(s));
    }
    
    // template<typename U=long long>
    inline State<T> rotate_90(State<U>& s){
        tie(s.y,s.x)=direction<T>::rotate_90(pair<T,T>(s.y,s.x));
        return State<T>(s);
    }    

    // // specialization of member functions
    // private:
    // inline void free_specializer(){
        
    // }


};

// //helper class to initialize all the template function
// template<typename T,typename U, typename BULL>
// class Helper{
//     public:
//     void inline specialize_direction(){
//         template<>
//         T direction<T>::get_dir_indx<U>(U , U );
//         template<>
//         pair<T,T> direction<T>::get_dir_coord<U>(U&& );
//         template<>
//         T direction<T>::rotate_90<U>(U&& );
//         template<>
//         pair<T,T> direction<T>::rotate_90<U>(pair<U,U>&& );
//         template<>
//         complex<long double> direction<T>::rotate_90<U>(complex<U> );
//     }
    
//     void inline specialize_State(){
//         template<>
//         T State<T>::get_dir_indx<U>(State<U> );
//         template<>        
//         pair<T,T> State<T>::get_dir_coord<U>(State<U> );
//         template<>
//         State<T> State<T>::rotate_90<U>(State<U>& );        
//     }
// };

template<typename T,typename FUNC>
bool test_bi_op(T s1, T s2, FUNC bi_op){
    return s1.bi_op(s2);
}
template<typename T=long long, typename U=long long >
class Ttwo:public State<T,U>{//Using State<T> in member functions of Ttwo to return in T!
//By default data members are private
//
string task;
vector<vector<char>> frst;//forest where FJ has lost his cow
vector<vector<char>> path;//path taken
ll res;
State<T> sFRM_init,sCW_init;//initial state of FRM & CW
set<pair<State<T>,State<T>>> vis_simulation_state;//set of visited states pair<State<>,State<>>

// //typedef's for readability
// using State = State<T,U>;
// using direction = direction<T,U>;

public:
    //constructor
    Ttwo(string _task):
        task(_task)
        {
            //specialize template methos of classes
            // Helper<T,U,ll>

            //Open streams
            open_streams();
            //read input and initialize class member variables
            read();
            //solve
            solve();
            //write output after solving
            write();
            //close streams
            close_streams();
        };
    //member functions
    void open_streams(){
        //open streams
	    freopen((task+".in").c_str(),"r",stdin);//redirects standard input
        freopen((task+".out").c_str(),"w",stdout);//redirects standard output
    }
    void close_streams(){
        //close streams
        fclose(stdin);
        fclose(stdout);
    }
    inline void read(){
        //initialize class global variables
        //read input
        frst=vector<vector<char>>(12,vector<char>(12,'*'));
        path=vector<vector<char>>(12,vector<char>(12,'*'));
        //reading rows(top to bottom), columns(left to right)
        for(ll ry=10;ry>=1;--ry){
            for(ll cx=1;cx<11;++cx){
                cin>>frst[ry][cx];
                if(frst[ry][cx]=='F'){ 
                    auto [dy,dx]=direction<T,U>::get_dir_coord(0l);
                    sFRM_init=State<T>(cx,ry,dx,dy,0);}
                if(frst[ry][cx]=='C'){ 
                    auto [dy,dx]=direction<T,U>::get_dir_coord(0l);
                    sCW_init = State<T>(cx,ry,dx,dy,0);}
            }
        }
        path=frst;
        //initialize class global variables

    }
    void write(){
        //write output
        cout<<res<<endl;
    }
    void solve()
    {
        //Logic to solve the problem

        //check if operator< works for State class
        //====>
        // State<ll> s1=State<ll>(0,0,0,1,1),s2=State<ll>(1,0,0,0,0);
        
        // auto less12=s1<s2;//test_bi_op(s1,s2,Ttwo<T>::operator<);
        // cout<<(less12)?"Y":"N";
        res=iterative();
        //End of Logic
    }
    // template<typename U=long long>
    char get_frst_cell(State<T> s){
        if  (   !(      (s.y>=0 && s.y<frst.size()) 
                    &&  (s.x>=0 && s.x<frst[s.y].size()) 
                )   
            ){
                return 'X';
            }
        return frst[s.y][s.y];
    }
    //If number of consecutive rotations = 4
    //Means we were initially trapped    
    bool check_initially_trapped(State<T> s){
        bool flag_trapped=true;
        ll idir=0;
        //check if not all directions are blocked
        for(ll i=0;i<4;++i){
            flag_trapped = flag_trapped && (get_frst_cell(s) == '*');
            this->rotate_90(s);//rotate 90 deg clk-wise
        }
        return flag_trapped;
    }

    //print member varable path
    void print_path(){
        for(ll ry=path.size()-1;ry>=0;--ry){
            for(ll cx=0;cx<path[ry].size();++cx){
                cout<<path[ry][cx]<<' ';
            }
            cout<<endl;
        }
        cout<<"^^^"<<endl;        
    }

    //checking neighbouring cells for a freeway ahead
    // template<typename U=long long>
    void move_forward(  State<T>& s ){
        // increase time by 1
        s.t+=1;
        //Check if we need to rotate in-case of an obstacle ahead...
        State<T> s1(s.x+s.dx,s.y+s.dy,s.dx,s.dy,s.t);
        if(get_frst_cell(s1) == '*'){
            this->rotate_90(s);//rotate 90 deg clk-wise
            path[s.y][s.x]='@';
        //Guess no obstacles in this direction...Found the way ahead!!
        }else{
            //Move forward in direction(dx,dy)
            s=move(s1);
            path[s.y][s.x]=this->dirindx2arrow[this->get_dir_indx(s)];
        }
    }

    //iterative approach
    ll iterative(){
        if( check_initially_trapped(sFRM_init) 
            or check_initially_trapped(sCW_init) ){
            return 0;
        }
        auto [sFRM,sCW]=make_pair(sFRM_init,sCW_init);
         
        while(true){
            //checking neighbouring cells for a freeway ahead
            //updates state of FRM & CW to time one second later
            // rewind(stdin);  
            move_forward(sFRM);
            move_forward(sCW);

            print_path();
            cout<<"^v^v^v"<<endl;
            
            //If we havent got the result and we are revisiting a state in a simulation that means we cant achieve the desirable state in the simulation as the simulation is cyclic in nature
            auto tmp=make_pair(sFRM,sCW);
            if(cpresent(vis_simulation_state,tmp)){
                //not possible
                return 0;
            }else{
                //mark new state as visited
                vis_simulation_state.emplace(sFRM,sCW);
                //check if we have achieved the desired state
                //i.e. both are in the same cells
                if(sFRM.x==sCW.x && sFRM.y==sCW.y){
                    //Success!
                    return sFRM.t;
                }
            }
        }
    }


};
template<typename T=long long, typename U=long long >
class A{
    public:
    template<typename U1>
    void f(U1 var){
        cout<<"C1:"<<var<<endl;
    }
};

template<typename T=long long, typename U=long long>
class B:public A<T,U>{
    public:
    template<typename U1,typename U2>
    void f(pair<U1,U2> var){
        cout<<"C2:"<<var.first<<" "<<var.second<<endl;
    }
    //
};
namespace NS_DECLARATIONS{
    template<typename U1>
    void f(U1);
    template<typename U1, typename U2>
    void f(pair<U1,U2>);
}
template<typename T=long long, typename U=long long >
class Tester:public B<T,U>{
    public:
    void run_your_test(){
        ll x1=1;
        pair<ll,LD> x2=make_pair(1,1.0);

        // A<T,U>::f(x1);
        // B<T,U>::f(x2);
    }
};
int main( )
{
    // cout<<(State<>(0,0,0,0,0)<State<>(0,0,0,1,0)?("Y"):("N"))<<endl;
    //construct a class object and immediately call a function on it
    //instead of instantiating a class object and then calling a function using that object
    cout<<"xxxxx"<<endl;
    // Tester<ll,ll>().run_your_test();
    // Ttwo<ll>("ttwo");
    using x=int;
    x y1;
    cout<<typeid(x).name()<<endl;
    using x=x;
    int x=1;
    cout<<x<<endl;
	return 0;
}

/**
TO DO:
store the time at which a cell was visited and print it out to see the paths the farmer and cow were taking in the simulation and if the intersected.

Clear up the simulation by keep track of time and restore cells in 'path' member variable if time passed since anyone was on that cell is greater than 5 seconds.
---
Proposed Algo:
---
Observations:
Need to do multiple levels 
---
    
/**/
