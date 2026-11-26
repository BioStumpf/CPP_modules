#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {

	// create vectors for each triangle side in the same direction
	const Point ab = b - a;
	const Point bc = c - b;
	const Point ca = a - c;

	//create vectors from each triangle edge to the point
	const Point ap = point - a;
	const Point bp = point - b;
	const Point cp = point - c;

	//compute the z direction for each side using cross product (denoted by ^)
	const Fixed z_ab = ab ^ ap;
	const Fixed z_bc = bc ^ bp;
	const Fixed z_ca = ca ^ cp;

	//check if we have either only positive or negative z direction
	const bool only_neg_z = z_ab < 0 && z_bc < 0 && z_ca < 0;
	const bool only_pos_z = z_ab > 0 && z_bc > 0 && z_ca > 0;
	return only_neg_z || only_pos_z;
}
