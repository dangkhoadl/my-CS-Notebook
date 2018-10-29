
/*******************************************************************************************************************/
typedef double C;
typedef complex<C> P;
#define X real()
#define Y imag()

const double EPSILON = 1e-9;
bool areSame(double a, double b) {
	return fabs(a - b) < EPSILON;
}


/***************************************************************************************************************/
// point u(x,y)
P a = { 3,1 };
P b = { 2,3 };
// Point u(|modulus|, arg)
P a = polar(1,0.2);				// (moulus, arg in rad)


// Print u(x,y)
cout << a.X << ' ' << a.Y << endl;

// Modulus |u|
abs(a);
// argument or angle
arg(a); 				// Radiant
arg(a)*180/PI;			//Degree

// Cross product c = a x b = ax*by - bx*ay
C c = (conj(a)*b).Y;

