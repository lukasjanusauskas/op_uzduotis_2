#include <algorithm>
#include <list>
#include <functional>
#include "studentas.h"
#include "skaiciavimai.h"

bool compareVardas(const Studentas&, const Studentas&);
bool comparePavarde(const Studentas&, const Studentas&);
bool compareEgza(const Studentas&, const Studentas&);

template <typename f>
void rikiuoti_studentus(std::vector<Studentas>& stud, f func) {
	std::sort(stud.begin(), stud.end(), func);
}

template <typename f>
void rikiuoti_studentus(std::list<Studentas>& stud, f func) {
	stud.sort(func);
}

template <typename container>
void kategorizuoti(container &stud, container  &vargsai, container &galvos) {
	// Partition
	auto it = std::partition(stud.begin(), stud.end(),
													 [](Studentas &s) { return s.galutinis < 5; });

	// Copy 
	vargsai.insert (vargsai.begin(), stud.begin(), it);
	galvos.insert (galvos.begin(), it, stud.end());

	stud.clear();
}