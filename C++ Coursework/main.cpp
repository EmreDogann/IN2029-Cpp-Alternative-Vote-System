#include "election.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* g++ compile command.
	g++ main.cpp vote.cpp election.cpp -o Alternative_Vote_System
*/

int main() {
	election elec;
	fstream data ("votes.txt");
	if (data.is_open()) {
		elec = read_votes(data);
	}
	else {
		cout << "Unable to open file.";
	}
	data.close();

	int round = 0;
	int voteCount = 0;

	vector<pair<candidate, int>> results;

	while (true) {
		++round;
		voteCount = elec.vote_count();
		cout << "Round " << round << ": " << voteCount << " votes" << '\n';
		cout << "First preferences:" << '\n';

		results = elec.ranked_candidates();
		
		for (auto result : results) {
			cout << "  Candidate " << result.first << ": " << result.second << '\n';
		}

		int vote_majority = voteCount / 2;

		const pair<candidate, int> winner = results[0];

		if (winner.second >= vote_majority) {
			cout << "Candidate " << winner.first << " is selected." << '\n';
			cin.get();
			return 0;
		}
		else {
			const pair<candidate, int> smallest = results[results.size()-1];
			elec.eliminate(smallest.first);
			cout << "Candidate " << smallest.first << " is eliminated." << '\n' << '\n';
		}
	}
}