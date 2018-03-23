
/*---------------------------------------------------------------------------------------------------------*/
// check if a == b
bool areSame(double a, double b) {
    return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}

// check if a > b
bool isBigger(double a, double b) {
    if(a > b && !(std::fabs(a - b) < std::numeric_limits<double>::epsilon()))
        return true;
    return false;
}
// check if a >= b
bool isBiggerEqual(double a, double b) {
    if(a > b || (std::fabs(a - b) < std::numeric_limits<double>::epsilon()))
        return true;
    return false;
}

// check if a < b
bool isSmaller(double a, double b) {
    if(a < b && !(std::fabs(a - b) < std::numeric_limits<double>::epsilon()))
        return true;
    return false;
}
// check if a <= b
bool isSmallerEqual(double a, double b) {
    if(a < b || (std::fabs(a - b) < std::numeric_limits<double>::epsilon()))
        return true;
    return false;
}

/*---------------------------------------------------------------------------------------------------------*/
const double EPSILON = 1e-6; // for x <= 10^6;
inline double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); } 
inline int d2i(double x) {return x >= 0 ? x + EPSILON : x - EPSILON;}
inline double sfloor(double x) {return x >= 0 ? floor(x + EPSILON) : floor(x - EPSILON);}
inline double sceil(double x) {return x >= 0 ? ceil(x - EPSILON) : ceil(x + EPSILON);};
