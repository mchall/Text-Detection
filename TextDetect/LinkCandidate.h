#ifndef _LINK_CANDIDATE_
#define _LINK_CANDIDATE_

#include <vector>
#include"Candidate.h"
#include "PolyGroundTruth.h"
#include "Tools.h"
#include "LinkCandidateUtil.h"

using namespace std;

class LinkCandidate{
public:
	LinkCandidate(){ this->Iq = new Iqueue; relation = vector<vector<bool>>(3000, vector<bool>(3000, true)); }
	PolyGroundTruthSet run(vector<Candidate>& allCandidate);
	void findPairRegion(int i, int j);
	void finalresult();
	void link();
private:
	vector<Candidate> candidateStore;
	int CandidateNum;
	vector<vector<bool>> relation;
	Iqueue* Iq;
	PolyGroundTruthSet cgts;
};

#endif