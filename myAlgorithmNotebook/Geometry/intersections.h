
/*------------------------------------------ Rectangle intersection ---------------------------------------------------------------------*/
struct point {
	double x;
	double y;
	point(double x, double y) : x(x), y(y) {}
};
struct rectangle {
	point botLeft;
	point topRight;
	rectangle(const point &bL, const point &tR) : botLeft(bL), topRight(tR) {}
};

//Find the Rectangle(R3) interseted by 2 other rec (R1, R2)
// Rec defined by 2 points: Bottom Left and Top Right
bool findIntersectRec(const rectangle &R1, const rectangle &R2, rectangle &R3) {
	if (max(R1.botLeft.x, R2.botLeft.x) > min(R1.topRight.x, R2.topRight.x))
		return false;
	if (max(R1.botLeft.y, R2.botLeft.y) > min(R1.topRight.y, R2.topRight.y))
		return false;

	R3.botLeft.x = max(R1.botLeft.x, R2.botLeft.x);
	R3.botLeft.y = max(R1.botLeft.y, R2.botLeft.y);
	R3.topRight.x = min(R1.topRight.x, R2.topRight.x);
	R3.topRight.y = min(R1.topRight.y, R2.topRight.y);
	return true;
}

/*--------------------------------------------- Line intersection ------------------------------------------------------------------*/
struct point {
	double x;
	double y;
	point(double x, double y) : x(x), y(y) {}
};

struct line {
	double A;
	double B;
	double C;
};

// A1x + B1y = C1
// A2x + B2y = C2
// find point intersect by line 1 and line 2
bool findLineIntersect(const line &l1, const line &l2, point &intersect) {
	double det = l1.A * l2.B - l2.A * l1.B;
	if (det == 0)
		//Lines are parallel
		return false;
	
	intersect.x = (l2.B * l1.C - l1.B * l2.C) / det;
	intersect.y = (l1.A * l2.C - l2.A * l1.C) / det;
}

/*--------------------------------------------- Circle intersection ------------------------------------------------------------------*/
struct point {
	double x;
	double y;
	point() {}
	point(double x, double y) : x(x), y(y) {}
};

// Ax + By = C
struct line {
	double A;
	double B;
	double C;
	line(const double a, const double b, const double c) : A(a), B(b), C(c) {}
	line(const point &p1, const point &p2) {
		A = p2.y - p1.y;
		B = p1.x - p2.x;
		C = p1.x * p2.y - p1.y * p2.x;
	}
};

bool findLineIntersect(const line &l1, const line &l2, point &intersect) {
	double det = l1.A * l2.B - l2.A * l1.B;
	if (det == 0)
		//Lines are parallel
		return false;

	intersect.x = (l2.B * l1.C - l1.B * l2.C) / det;
	intersect.y = (l1.A * l2.C - l2.A * l1.C) / det;
}

//To find the perpendicular bisector of XY, find the line from X to Y, in the form Ax + By = C.
//A line perpendicular to this line will be given by the equation - Bx + Ay = D, for some D.
//To find D for the particular line we are interested in, 
//find the midpoint between X and Y by taking the midpoint of the x and y components independently.
//Then, substitute those values into the equation to find D.
//If we do the same thing for Y and Z, we end up with two equations for two lines, 
//and we can find their intersections.
point findCircleFrom3Points(const point &X, const point &Y, const point &Z) {
	//find perpendicular line of XY
	point mXY((double)0.5 * (X.x + Y.x), (double)0.5 * (X.y + Y.y)); //mXY = mid point of X and Y;
	line XY(X, Y);
	line pXY( (-1.0) * XY.B, XY.A, (-1.0) * XY.B * mXY.x + XY.A * mXY.y);

	//find perpendicular line of YZ
	point mYZ((double)0.5 * (Y.x + Z.x), (double)0.5 * (Y.y + Z.y)); //mYZ = mid point of Y and Z;
	line YZ(Y, Z);
	line pYZ((-1.0) * YZ.B, YZ.A, (-1.0) * YZ.B * mYZ.x + YZ.A * mYZ.y);

	point centre;
	if (findLineIntersect(pXY, pYZ, centre))
		return centre;
	
	// X,Y,Z are in the same line
	return{ (double)inf, (double)inf };
}
