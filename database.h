#pragma once

#include "date.h"

#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

class Database {
public:
	void Add(const Date& date, const string& event);

	ostream& Print(ostream& os) const;

	template <typename F>
	int RemoveIf(const F& predicate) {
		int count = 0;
		events.clear();

		for (auto iter = events_vec.begin(); iter != events_vec.end(); ) {
			auto del = stable_partition(iter->second.begin(), iter->second.end(), [predicate, iter](const string& s) {
				return !predicate(iter->first, s);
			});
      
			count += distance(del, iter->second.end());
			iter->second.erase(del, iter->second.end());

			if (iter->second.size() == 0) {
				//events.erase(iter->first);
				iter = events_vec.erase(iter);
			}
			else {
				++iter;
			}
		}

		for (const auto& x : events_vec) {
			for (const auto& y : x.second) {
				events[x.first].insert(y);
			}
		}

		return count;
	}

	template <typename F>
	vector<pair<Date, string>> FindIf(const F& predicate) const {
		vector<pair<Date, string>> result;

		for (auto iter = events_vec.begin(); iter != events_vec.end(); ++iter) {
			for (auto del = iter->second.begin(); del != iter->second.end(); ++del) {
				auto temp = del;
				del = find_if(del, iter->second.end(), [predicate, iter](const string& s) {
					return predicate(iter->first, s);
				});
				if (del < iter->second.end()) {
					result.push_back(make_pair(iter->first, *del));
				}
				else {
					del = temp;
				}
			}
		}

		return result;
	}

	pair<Date, string> Last(const Date& date) const;

private:
	map <Date, set<string>> events;
	map <Date, vector<string>> events_vec;
};
