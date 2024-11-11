#include <algorithm>
#include <list>
#include <functional>
#include "studentas.h"
#include "skaiciavimai.h"

bool Studentas::compareVardas(const Studentas& s1, const Studentas& s2){
	return s1.vardas.compare(s2.vardas);
}

bool Studentas::comparePavarde(const Studentas& s1, const Studentas& s2){
	return s1.pavarde.compare(s2.pavarde);
}

bool Studentas::compareEgza(const Studentas& s1, const Studentas& s2){
	return s1.galutinis > s2.galutinis;
}

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
													 [](Studentas &s) { return s.get_galutinis() < 5; });

	// Copy 
	vargsai.insert (vargsai.begin(), stud.begin(), it);
	galvos.insert (galvos.begin(), it, stud.end());

	stud.clear();
}