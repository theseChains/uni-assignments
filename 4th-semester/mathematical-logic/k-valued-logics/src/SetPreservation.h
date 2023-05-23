#ifndef SET_PRESERVATION_H
#define SET_PRESERVATION_H

#include <unordered_set>
#include <vector>

std::unordered_set<int> getUserSet(int numberOfValues);
bool setHasProperValues(const std::unordered_set<int>& set, int numberOfValues);
void checkForSetPreservation(const std::vector<int>& values, int numberOfValues);

#endif
