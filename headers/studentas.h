#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

class Studentas {
	private:
  	std::string vardas;
  	std::string pavarde;

  	double egz_pazymys;
  	std::vector<double> nd_pazymiai;
		float galutinis;

	public:
		Studentas ();
		Studentas (std::stringstream& buffer);
		void isvesti_studenta (std::stringstream& buffer);

		std::string get_vardas() { return vardas; };
		std::string get_pavarde() { return pavarde; };
		float get_galutinis() { return galutinis; };

		void set_vardas(std::string vardas) { this->vardas = vardas; };
		void set_pavarde(std::string pavarde) { this->pavarde = pavarde; };
		void set_galutinis(float galutinis) { this->galutinis = galutinis; };

		bool compareVardas(const Studentas&, const Studentas&);
		bool comparePavarde(const Studentas&, const Studentas&);
		bool compareEgza(const Studentas&, const Studentas&);
};

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