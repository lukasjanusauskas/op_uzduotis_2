#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h"

#include <string>
#include <vector>

/// @brief Pagrindinė šios programos klasė, studentų klasė.
class Studentas : public Zmogus {
	private:
  	double egz_pazymys;
  	std::vector<int> nd_pazymiai;
		float galutinis;

	public:
		int n_pazymiu;

		Studentas ();

		/// @brief Inicializuoti, žinant tik namų adrbų pažymių skaičių
		/// @param n_paz 
		Studentas (int n_paz) : n_pazymiu(n_paz) {};

		/// @brief 
		/// @param buffer stringstream buffer'is, per kurį įrašome duomenis
		/// @param nd_skaicius 
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
		
		/// @brief Išvesties operatorius
		/// @param s stringstream buffer'is į kurį įrašysim studentą
		/// @param stud 
		/// @return 
		friend std::stringstream& operator<<(std::stringstream& s, const Studentas& stud);

		/// @brief Įvesties operatorius
		/// @param s stringstream buffer'is iš kurio gausim studento duomenis
		/// @param stud 
		/// @return 
		friend std::stringstream& operator>>(std::stringstream& s, Studentas& stud);

	/// @brief Nuskaityti studentus į kokį nors konteinerį.
	/// @tparam container
	/// @param stud  Studentų konteineris, į kurį išvesime duomenis
	/// @param failas Failo path
	template <typename container>
	friend void nuskaityti_faila(const container &stud, std::string failas);

	/// @brief Studentų įrašymas į kokį nors konteinerį
	/// @tparam container 
	/// @param stud  Studentų konteineris, į kurį išvesime duomenis
	template <typename container>
	friend void irasyti_studentus(container &sarasas);

	/// @brief Išvesti studentų konteinerį į failą
	/// @tparam container 
	/// @param stud  Studentų konteineris, į kurį išvesime duomenis
	/// @param file_path Failo path
	template <typename container>
	friend void isvesti_faila(const container &stud, std::string file_path);
};

#endif