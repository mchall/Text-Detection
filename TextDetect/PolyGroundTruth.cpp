#include "Stdafx.h"
#include"PolyGroundTruth.h"

using namespace std;

PolyGroundTruth::PolyGroundTruth(string s, double xupdate, double yupdate)
{
	vector<Point> vex;
	vector<string> ret = Tools::split(s, " ");
	Point pt = Point(atoi(ret[0].c_str())*xupdate, atoi(ret[1].c_str())*yupdate);
	vex.push_back(pt);
	Point pt1 = Point(atoi(ret[2].c_str())*xupdate, atoi(ret[3].c_str())*yupdate);
	vex.push_back(pt1);
	rr = boundingRect(vex);
}

PolyGroundTruth::PolyGroundTruth(const Rect& r)
{
	this->rr = r;
}

void PolyGroundTruthSet::display(Mat& image)
{
	Scalar s = Scalar(0, 0, 255);
	for (int i = 0; i < this->sets.size(); i++)
	{
		Rect rec = sets[i].rr;
		rectangle(image, rec, s, 3, 8, 0);
	}
}