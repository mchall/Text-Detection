#ifndef _SWT_H_
#define _SWT_H_

#include <iostream>
#include <vector>
#include <set>
#include "swtUtil.h"
#include "Candidate.h"
#include "headline.h"

using namespace std;
using namespace cv;

class Swt{
public:
	Swt();
	void initialize(Mat& image, vector<vector<Point2i>>& cc);
	void getStrokeWidth(vector<Point2i>& component, Candidate& cad);
	void gradient();
	void inversegradient();
	void Edges(vector<vector<Point2i>>& cc);
	void td_findPairLine();
	void displayStrokeWidth(vector<vector<Point2i>>& cc);

private:
	Mat StrokeImage;
	Mat GrayImage;
	Mat EdgeImage;
	Mat max_x;
	Mat max_y;
	int height;
	int width;
	Qqueue* qbtc;
	Qqueue* qb; ///for rgb
};

#endif