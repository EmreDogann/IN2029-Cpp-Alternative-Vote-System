#include "election.h"
#include <iostream>

using namespace std;

election::election()
{
}

void election::add_vote(const vote & v)
{
	vote_collection.push_back(v);
}

int election::vote_count() const
{
	return vote_collection.size();
}

void election::eliminate(candidate c)
{
	auto p = vote_collection.begin();
	while (p != vote_collection.end())  {
		p->discard(c);
		if (p->spent()) {
			swap(*p, vote_collection[vote_collection.size()-1]);
			vote_collection.pop_back();
		}
		else {
			p++;
		}
	}
}

vector<pair<candidate, int>> election::ranked_candidates() const
{
	//Hash map.
	map <candidate, int> myMap;

	//Collect and rank candidates based on votes into a hash map (hash map is sorted).
	for (auto p = vote_collection.cbegin(); p != vote_collection.cend(); ++p) {
		auto ret = myMap.emplace(p->first_preference(), 0);
		ret.first->second++;
	}

	//Convert hash map to vector.
	vector<pair<candidate, int>> rankedCandidates(myMap.begin(), myMap.end());
	
	//Invert ordering.
	sort(rankedCandidates.begin(), rankedCandidates.end(), [](const pair<candidate, int> &x, const pair<candidate, int> &y) {
		return x.second > y.second;
		});

	return rankedCandidates;
}

election read_votes(istream & in)
{
	election elec;
	string line;
	candidate temp;

	while (getline(in, line)) {
		stringstream s(line);
		vector<candidate> votePrefs;
		while (s >> temp) {
			votePrefs.push_back(temp);
		}
		vote vote(votePrefs);
		elec.add_vote(vote);
	}

	return elec;
}
