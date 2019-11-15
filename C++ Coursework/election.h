#ifndef ELECTION_H
#define ELECTION_H

#include <istream>
#include <vector>
#include <sstream>
#include <map>
#include "vote.h"

//A class holding many votes.
class election {
	std::vector<vote> vote_collection;

public:
	election();
	void add_vote(const vote &v); //Adds a vote to the collection.
	int vote_count() const; //Returns the number of votes currently left.
	void eliminate(candidate c); //Removes any occurrence of the named candidate from each vote, and removes any votes that are now spent.
	std::vector<std::pair<candidate, int>> ranked_candidates() const; //Returns a collection of candidates left in the election paired with the number of first preferences each has, in decreasing order of that number. (If two candidates have the same number of first preferences, either order will do.)
};

//Reads the votes of an election.
election read_votes(std::istream &in);

#endif