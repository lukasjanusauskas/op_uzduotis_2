#ifndef UTIL_H
#define UTIL_H

#include "studentas.h"
#include<functional>
#include<list>

Studentas generuoti_rand_stud();
void generuoti_atsitiktinius(std::string file, unsigned int n);
std::vector<Studentas> nuskaityti_faila(std::string failas);

void rikiuoti_studentus(std::vector<Studentas>& stud,
						std::function<bool(Studentas const&, Studentas const&)> func);

void rikiuoti_studentus(std::list<Studentas>& stud,
						std::function<bool(Studentas const&, Studentas const&)> func);

template <typename container>
void kategorizuoti(container &stud, container &vargsai, container &galvos);

#endif
