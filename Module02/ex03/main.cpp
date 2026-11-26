#include <iostream>
#include "Point.hpp"

static int g_total = 0;
static int g_failed = 0;

static void check(char const *name, Point const &a, Point const &b,
		Point const &c, Point const &p, bool expected)
{
	bool const result = bsp(a, b, c, p);

	g_total++;
	if (result != expected)
		g_failed++;
	std::cout << (result == expected ? "[ OK ] " : "[FAIL] ") << name
		<< " (expected " << (expected ? "true" : "false")
		<< ", got " << (result ? "true" : "false") << ")" << std::endl;
}

static void title(char const *text)
{
	std::cout << std::endl << "--- " << text << " ---" << std::endl;
}

int main(void)
{
	Point const a(0.0f, 0.0f);
	Point const b(4.0f, 0.0f);
	Point const c(0.0f, 4.0f);

	title("inside");
	check("middle", a, b, c, Point(1.0f, 1.0f), true);
	check("near corner a", a, b, c, Point(0.1f, 0.1f), true);
	check("just above edge ab", a, b, c, Point(2.0f, 0.01f), true);
	check("just below edge bc", a, b, c, Point(1.99f, 1.99f), true);

	title("outside");
	check("far away", a, b, c, Point(5.0f, 5.0f), false);
	check("just below edge ab", a, b, c, Point(2.0f, -0.01f), false);
	check("just beyond edge bc", a, b, c, Point(2.01f, 2.01f), false);
	check("left of edge ca", a, b, c, Point(-1.0f, 1.0f), false);

	title("on an edge");
	check("edge ab", a, b, c, Point(2.0f, 0.0f), false);
	check("edge bc (negative slope)", a, b, c, Point(2.0f, 2.0f), false);
	check("edge ca", a, b, c, Point(0.0f, 2.0f), false);

	title("on a corner");
	check("corner a", a, b, c, a, false);
	check("corner b", a, b, c, b, false);
	check("corner c", a, b, c, c, false);

	title("in line with an edge, past a corner");
	check("past b on line ab", a, b, c, Point(6.0f, 0.0f), false);
	check("past c on line ca", a, b, c, Point(0.0f, 6.0f), false);
	check("past b on line bc", a, b, c, Point(6.0f, -2.0f), false);

	title("clockwise corner order");
	check("inside", a, c, b, Point(1.0f, 1.0f), true);
	check("outside", a, c, b, Point(5.0f, 5.0f), false);
	check("on edge", a, c, b, Point(2.0f, 0.0f), false);

	title("negative coordinates");
	Point const d(-5.0f, -1.0f);
	Point const e(-1.0f, -2.0f);
	Point const f(-3.0f, -6.0f);
	check("inside", d, e, f, Point(-3.0f, -3.0f), true);
	check("outside", d, e, f, Point(0.0f, 0.0f), false);

	title("degenerate triangles");
	check("flat, point on the line", a, Point(2.0f, 2.0f), Point(4.0f, 4.0f),
		Point(1.0f, 1.0f), false);
	check("flat, point off the line", a, Point(2.0f, 2.0f), Point(4.0f, 4.0f),
		Point(1.0f, 3.0f), false);
	check("all corners equal", a, a, a, a, false);

	std::cout << std::endl << (g_total - g_failed) << "/" << g_total
		<< " tests passed" << std::endl;
	return (g_failed == 0 ? 0 : 1);
}
