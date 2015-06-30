#ifndef _POLYGROUNDTRUTH_
#define _POLYGROUNDTRUTH_

#include <string>
#include <vector>
#include <fstream>
#include "headline.h"
#include "Tools.h"

using namespace std;
using namespace cv;

class PolyGroundTruth{
public:
	PolyGroundTruth(){}
	PolyGroundTruth(string s, double xratio, double yratio);
	PolyGroundTruth(const Rect& r);
private:
	Rect rr;
	friend class PolyGroundTruthSet;
	friend class VericaficationTextLine;
	friend class Fmeasure;
};

class PolyGroundTruthSet{
public:
	void display(Mat& image);
	void push_back(PolyGroundTruth pgt){ sets.push_back(pgt); }
	void clear(){ sets.clear(); }
private:
	vector<PolyGroundTruth> sets;
	friend class VericaficationTextLine;
	friend class Fmeasure;
};

#endif