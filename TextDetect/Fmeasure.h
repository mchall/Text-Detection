#ifndef _FMEASURE_
#define _FMEASURE_

#include<string>
#include<vector>
#include "PolyGroundTruth.h"
#include "headline.h"

class Fmeasure{
public:
	string run(PolyGroundTruthSet& cgts, PolyGroundTruthSet& pgts);
	double PrecisionRecall(PolyGroundTruthSet& cgts, PolyGroundTruthSet& pgts);
	double getPrecisionRecall(PolyGroundTruthSet& cgts, PolyGroundTruthSet& pgts);
	double intersection(const Rect& r1, const Rect& r2);
};

#endif