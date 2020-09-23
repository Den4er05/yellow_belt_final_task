#include "date.h"
#include "database.h"

void Database::Add(const Date& date, const string& event) {
	int s = events[date].size();
	events[date].insert(event);
	if (s + 1 == events[date].size()) {
		events_vec[date].push_back(event);
	}
}

ostream& Database::Print(ostream& os) const {
	for (const auto& item : events_vec) {
		for (const string& event : item.second) {
			os << item.first << " " << event << endl;
		}
	}
	return os;
}

pair<Date, string> Database::Last(const Date& date) const {
	if (events_vec.empty() || date < events_vec.begin()->first) {
		throw invalid_argument("");
	}

	auto it = events_vec.upper_bound(date);

	auto iter = prev(it)->second;
	iter.erase(iter.begin(), prev(iter.end()));
	string x = *iter.begin();

	return make_pair(prev(it)->first, x);
}
