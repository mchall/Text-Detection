#include "Stdafx.h"
#include "TextDetection.h"

string TextDetection::detectText(const Mat& image, const vector<string> gt, bool isshow)
{
	gd.readImageGroundTruth(image, gt);
	gd.run();
	if (isshow == true){
		gd.showPolyGroundTruthSet();
	}
	if (gt.size() == 0){
		return "";
	}
	else{
		return gd.calculateResult();
	}
}