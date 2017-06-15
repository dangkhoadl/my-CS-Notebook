double safe_sqrt(double x) {
	return sqrt(max((double)0.0, x));
}
#define sq(x) ((x) * (x))

struct point {
	double x;
	double y;
	point(double x, double y) : x(x), y(y) {}
};

struct vect {
	double x;
	double y;

	vect(double x, double y) : x(x), y(y) {}
	vect(const point &a, const point &b) : x(b.x - a.x), y(b.y - a.y) {}
};

//dot product
// A ⋅ B = |A||B|Cos(θ)
double dot(const vect &A,const vect &B) {
	return A.x * B.x + A.y * B.y;
}

//cross product
// |A x B| = |A||B|Sin(θ)  
double cross(const vect &A, const vect &B) {
	return A.x * B.y - A.y * B.x;
}

//Point - Point distance
double distance(const point &A, const point &B) {
	return safe_sqrt(sq(A.x - B.x) + sq(A.y - B.y));
}

//Line Point distance
//if isSegment is true, AB is a segment, not a line.
double linePointDist(const point &A, const point &B, const point &C, bool isSegment) {
	double dist = cross({ A,B }, { A,C }) / distance(A, B); // |AB x AC| / AB
	if (isSegment) {
		double dot1 = dot({ A,B }, { B,C });		// AB . BC
		if (dot1 > 0)
			return distance(B, C);

		double dot2 = dot({ B,A }, { A,C });		//  BA . AC
		if (dot2 > 0)
			return distance(A, C);
	}
	return abs(dist);
}
