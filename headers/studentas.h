#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h"

#include <string>
#include <vector>

class Studentas : public Zmogus {
	private:
  	double egz_pazymys;
  	std::vector<int> nd_pazymiai;
		float galutinis;

	public:
		int n_pazymiu;

		Studentas ();
		Studentas (int n_paz) : n_pazymiu(n_paz) {};
		Studentas (std::stringstream& buffer, int nd_skaicius);

		~Studentas();
		Studentas(const Studentas& s);
		Studentas& operator=(const Studentas& s);

		std::string get_vardas() { return vardas; };
		std::string get_pavarde() { return pavarde; }

		float get_galutinis() { return galutinis; };
		float get_egz() { return egz_pazymys; };

		std::vector<int> get_nd_pazymiai() { return nd_pazymiai; };

		void set_galutinis(float galutinis) { this->galutinis = galutinis; };

		static bool compareVardas(const Studentas&, const Studentas&);
		static bool comparePavarde(const Studentas&, const Studentas&);
		static bool compareEgza(const Studentas&, const Studentas&);
		
		friend std::stringstream& operator<<(std::stringstream& s, const Studentas& stud);
		friend std::stringstream& operator>>(std::stringstream& s, Studentas& stud);
};

void isvesti_studenta (Studentas s, std::stringstream& buffer);

template <typename container>
void nuskaityti_faila(const container &stud, std::string failas);

template <typename container>
void irasyti_studentus(container &sarasas);
void spausdinti_stud_duom(Studentas stud);

template <typename container>
void spausdinti_rezultatus(container &stud);

template <typename container>
void isvesti_faila(const container &stud, std::string file_path);

#endif