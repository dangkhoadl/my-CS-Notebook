//Find the Rectangle(R3) interseted by 2 other rec (R1, R2)
// Rec defined by 2 vertices: Bottom Left and Top Right
struct vertice {
	int x_;
	int y_;
	vertice(int x, int y) : x_(x), y_(y) {}
};

struct rectangle {
	vertice botLeft_;
	vertice topRight_;
	rectangle(int x1, int y1, int x2, int y2) : botLeft_(x1, y1), topRight_(x2, y2) {}
};

bool findIntersectRec(const rectangle &R1, const rectangle &R2, rectangle &R3) {
	if (max(R1.botLeft_.x_, R2.botLeft_.x_) > min(R1.topRight_.x_, R2.topRight_.x_))
		return false;
	if(max(R1.botLeft_.y_, R2.botLeft_.y_) > min(R1.topRight_.y_, R2.topRight_.y_))
		return false;

	R3.botLeft_.x_ = max(R1.botLeft_.x_, R2.botLeft_.x_);
	R3.botLeft_.y_ = max(R1.botLeft_.y_, R2.botLeft_.y_);
	R3.topRight_.x_ = min(R1.topRight_.x_, R2.topRight_.x_);
	R3.topRight_.y_ = min(R1.topRight_.y_, R2.topRight_.y_);
	return true;
}
/*---------------------------------------------------------------------------------------------------------------*/