
/*---------------------------------------------------------------------------------------------------------*/
bool areSame(double a, double b) {
	return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}

/*---------------------------------------------------------------------------------------------------------*/
const double EPSILON = 1e-6;
bool areSame(double a, double b) {
	return std::fabs(a - b) < EPSILON;
}
