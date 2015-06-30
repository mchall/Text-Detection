#ifndef _TEXT_DETECTION_
#define _TEXT_DETECTION_

#include <iostream>
#include <vector>
#include <string>
#include "headline.h"
#include "GroundDetect.h"

using namespace std;
using namespace cv;

class TextDetection{
public:
	string detectText(const Mat& image, const vector<string> gt = vector<string>(), bool isshow = true);
private:
	GroundDetect gd;
};

#endif 