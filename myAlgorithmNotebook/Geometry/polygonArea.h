
/*------------------------------------------------ LATTICE POLYGON -------------------------------------------------------------*/
// Find area of a lattice polygon (polygon w/ int coordinates vertices)
//  Pick’s Theorem
//		B = number of lattice points on the boundary of the polygon
//		I = number of lattice points in the interior of the polygon
double calArea(int B, int I) {
	return (double)B / 2 + I - 1;
}

/*------------------------------------------------ TRIANGLE -------------------------------------------------------------*/
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

//cross product
// |A x B| = |A||B|Sin(θ)  
double cross(const vect &A, const vect &B) {
	return A.x * B.y - A.y * B.x;
}

double calTriangleArea(const point &A, const point &B, const point &C) {
	return (double)0.5 * abs(cross({A,B}, {B,C}));
}

/*------------------------------------------------ POLYGON -------------------------------------------------------------*/
struct point {
	double x;
	double y;
	point(double x, double y) : x(x), y(y) {}
};

//vector<p>: poylygon points
double calArea(const vector<point> &p) {
	double area = 0;
	//We will triangulate the polygon
	//into triangles with points p[0],p[i],p[i+1]

	for (int i = 1; i < p.size() - 1; ++i) {
		int x1 = p[i].x - p[0].x;
		int y1 = p[i].y - p[0].y;
		int x2 = p[i + 1].x - p[0].x;
		int y2 = p[i + 1].y - p[0].y;
		int cross = x1*y2 - x2*y1;
		area += cross;
	}
	return (double)0.5 * abs(area);
}
/*---------------------------------------------------------------------------------------------------------------------*/
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

//cross product
// |A x B| = |A||B|Sin(θ)  
double cross(const vect &A, const vect &B) {
	return A.x * B.y - A.y * B.x;
}

//vector<p>: poylygon points
double calArea(const vector<point> &p) {
	double area = 0;
	for (int i = 1; i < p.size() - 1; ++i) 
		area += cross({p[i], p[0]}, {p[0], p[i+1]});
	
	return (double)0.5 * abs(area);
}
