#ifndef VOTE_H
#define VOTE_H

#include <vector>
#include <algorithm>
typedef unsigned int candidate; //Candidate's assigned number.

//Representing the preference of one voter.
class vote {
	std::vector<candidate> preferences;

public:
	vote(const std::vector<candidate> &prefs); //Constructor which sets up a vote with a sequence of candidate identifiers in preference order (first preference first).
	bool spent() const; //Returns true if the vote has no preferences left.
	candidate first_preference() const; //Returns the current first preference of the vote. Clients may only call this member function if spent() is false.
	void discard(candidate c); //Removes any occurrence of the named candidate from the vote.
};

#endif