#ifndef _LINK_CANDIDATE_
#define _LINK_CANDIDATE_
#include"Candidate.h"
#include "PolyGroundTruth.h"
#include "Tools.h"
#include "LinkCandidateUtil.h"
#include <vector>

class LinkCandidate{
public:
	LinkCandidate(){this->Iq = new Iqueue;relation = std::vector< std::vector<bool> >(3000,std::vector<bool>(3000,true)); }
	PolyGroundTruthSet run(std::vector<Candidate>& allCandidate);
	void findPairRegion(int i, int j);
	void finalresult();
	void link();
private:
	std::vector<Candidate> candidateStore;
	int CandidateNum;
	std::vector< std::vector<bool> > relation;
	Iqueue* Iq;
	PolyGroundTruthSet cgts;
};

#endif