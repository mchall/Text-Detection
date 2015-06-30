#ifndef _VERICAFICATION_TEXT_LINE_
#define _VERICAFICATION_TEXT_LINE_

#include "headline.h"
#include "PolyGroundTruth.h"
#include "FilterBox.h"

class VericaficationTextLine{
public:
	PolyGroundTruthSet run(PolyGroundTruthSet& cgts, Mat& rgb);
	void FilterBoxWithPCAandRandomForest(Mat& rgb);
	void clearInnerBox();
private:
	PolyGroundTruthSet cgts;
	FilterBox fb;
};

#endif