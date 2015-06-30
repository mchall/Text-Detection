#ifndef _GROUND_DETECT_
#define _GROUND_DETECT_

#include <string>
#include "Candidate.h"
#include "PolyGroundTruth.h"
#include "GetCandidate.h"
#include "LinkCandidate.h"
#include "VericaficationTextLine.h"
#include "Fmeasure.h"
#include "headline.h"

using namespace std;
using namespace cv;

///Main class for text detection
class GroundDetect{
public:
	void readImageGroundTruth(const Mat& image, const vector<string> gt);
	void run();
	void showPolyGroundTruthSet();
	string calculateResult();
private:
	GetCandidate getCandidate;///class for get all characters from input image
	LinkCandidate linkCandidate;///class for link characters into text lines
	VericaficationTextLine vericaficationTextLine;///class for text line vericafication
	Fmeasure fmeasure;//class for calculating the F-measure based on cgts and pgts

	Mat oriBgrImage_8UC3;///Copy of the input Image
	vector<Candidate> candidateStore;///Character set calculated by the system
	PolyGroundTruthSet cgts;///The Rect region calculdated by the system
	PolyGroundTruthSet pgts;///The Rect region transform by gt
	string PRF;///precision,recall,F-measure
};

#endif