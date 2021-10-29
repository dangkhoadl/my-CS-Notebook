
/*---------------------------------------------------------------------------------------------------------*/
// check if a == b
bool is_eq(double a, double b) {
    return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}

// check if a > b
bool is_greater(double a, double b) {
    if(a > b && !(std::fabs(a - b) < std::numeric_limits<double>::epsilon()))
        return true;
    return false;
}
// check if a >= b
bool is_greater_eq(double a, double b) {
    if(a > b || (std::fabs(a - b) < std::numeric_limits<double>::epsilon()))
        return true;
    return false;
}

// check if a < b
bool is_lesser(double a, double b) {
    if(a < b && !(std::fabs(a - b) < std::numeric_limits<double>::epsilon()))
        return true;
    return false;
}
// check if a <= b
bool is_lesser_eq(double a, double b) {
    if(a < b || (std::fabs(a - b) < std::numeric_limits<double>::epsilon()))
        return true;
    return false;
}
