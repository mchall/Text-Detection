#ifndef _GET_CANDIDATE_
#define _GET_CANDIDATE_

#include <vector>
#include "headline.h"
#include "Candidate.h"
#include "swt.h"

using namespace std;
using namespace cv;
using namespace cv::ml;

class GetCandidate{
public:
	vector<Candidate> run(Mat& Image);
	void featureExtract();
	void swtprocess();
	void ExtractCCfeatures();
	void Filter();

private:
	Swt swt;
	Ptr<RTrees> CharacterClassifier;
	Mat oriBgrImage_8UC3;
	Mat gray_source_image;
	vector< vector<Point2i> > strVectorStore;
	vector<Candidate> ccStore;
	vector<Candidate> candidateStore;
};

#endif