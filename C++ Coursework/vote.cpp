#include "vote.h"
#include <iostream>
#include <string>

using namespace std;

vote::vote(const vector<candidate>& prefs)
{
	preferences = prefs;
}

bool vote::spent() const
{
	return preferences.size() == 0;
}

candidate vote::first_preference() const
{
	return preferences[0];
}

void vote::discard(candidate c)
{
	preferences.erase(remove(preferences.begin(), preferences.end(), c), preferences.end());
}
