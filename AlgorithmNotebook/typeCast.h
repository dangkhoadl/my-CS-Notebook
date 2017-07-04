
/*---------------------------------------------------------------------------------------------------------*/
bool areSame(double a, double b) {
	return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}

/*---------------------------------------------------------------------------------------------------------*/
const double EPSILON = 1e-6; // for x <= 10^6;
inline const bool areSame(double a, double b) {return fabs(a - b) < EPSILON;}   
inline int d2i(double x) {return x >= 0 ? x + EPSILON : x - EPSILON;}
inline double sfloor(double x) {return x >= 0 ? floor(x + EPSILON) : floor(x - EPSILON);}
inline double sceil(double x) {return x >= 0 ? ceil(x - EPSILON) : ceil(x + EPSILON);};
