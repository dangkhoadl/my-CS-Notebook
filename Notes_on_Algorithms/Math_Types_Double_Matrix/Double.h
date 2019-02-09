
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
