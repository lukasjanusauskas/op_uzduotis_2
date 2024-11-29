#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
#include <ios>
#include <list>

#include "studentas.h"
#include "skaiciavimai.cpp"
#include "timer.h"

Studentas::Studentas() {
	// Vieno studento irasymas
	std::cout << "Įrašyti varda ir pavarde(ivedus vardą paspausti Enter):\n";
	std::cin >> vardas >> pavarde;

	std::string ivestis;
	int paz;
	
	std::cout << "Įvesti pažymius(norėdami užbaigti, įveskite 0):\n";
	while (true) {
		std::cin >> ivestis;
		try
		{
			paz = std::stoi(ivestis);
		}
		catch (const std::exception&)
		{
			std::cout << "Prasau, iveskite normalu skaiciu, jei norite baigti, iveskite 0\n";
			continue;
		}

		if (paz == 0) // Irasoma, kol nepaspaudzia 0
			break;

		nd_pazymiai.push_back(paz);
	}

	std::cout << "Įveskite egzamino pažymį:\n";

ivesti:;
	std::cin >> ivestis;

	try
	{
		egz_pazymys = std::stoi(ivestis);
	}
	catch (const std::exception&)
	{
		std::cout << "Prasau, iveskite normalu skaiciu, jei norite baigti, iveskite 0\n";
		goto ivesti;
	}
}

std::stringstream& operator<<(std::stringstream& s, const Studentas& stud){
		s << std::setw(20) << stud.vardas
			<< std::setw(25) << stud.pavarde;
		s << std::left
			<< std::setw(17) << stud.galutinis << "\n";

		return s;
}

Studentas::Studentas (std::stringstream& buffer, int nd_skaicius){
	int tmp_paz;

	buffer >> vardas >> pavarde;

	for (int i = 0; i < nd_skaicius; i++) {
		buffer >> tmp_paz;
		nd_pazymiai.push_back(tmp_paz);
	}
	buffer >> egz_pazymys;

	galutinis = calc_galutini(vidurkis(nd_pazymiai), egz_pazymys);
}

std::stringstream& operator>>(std::stringstream& s, Studentas& stud){
	Studentas* new_stud = new Studentas(s, stud.n_pazymiu);
	stud = *new_stud;
	return s;
}

Studentas::~Studentas() {
	nd_pazymiai.clear();
}
		
Studentas::Studentas(const Studentas& s){
	vardas = s.vardas;
	pavarde = s.pavarde;

	egz_pazymys = s.egz_pazymys;
	galutinis = s.galutinis;

	copy(s.nd_pazymiai.begin(), s.nd_pazymiai.end(), std::back_inserter(nd_pazymiai));
}

Studentas& Studentas::operator=(const Studentas& s){
	this->vardas = s.vardas;
	this->pavarde = s.pavarde;

	this->egz_pazymys = s.egz_pazymys;
	this->galutinis = s.galutinis;

	copy(s.nd_pazymiai.begin(), s.nd_pazymiai.end(), std::back_inserter(this->nd_pazymiai));

	return *this;
}

template <typename container>
void irasyti_studentus(container &sarasas) {
	// Visu studentu irasimas komandineje eiluteje
	char testi{ 't' };

	while (true) {
		std::cout << "Įrašyti studentą? ";
		std::cin >> testi;

		switch (testi)
		{
		// Jei nuspaudzia 't', ivyksta irsaymas
		case 't':
		{
			Studentas* st = new Studentas();
			sarasas.push_back(*st);
		}
			break;
		// Jei nuspaudzia 'n', grazinama, nevyksta irasymas
		case 'n':
			return;
		// Jei nuspaudzia kazka kito, kartojamas klausimas
		default:
			break;
		}
	}
}

template <typename container>
void nuskaityti_faila(container &stud, std::string failas) {
	// Studentu suvedimas is failo
	std::ifstream fr(failas);

	if(fr.fail()){
		std::cout << "Nėra failo\n";
		return;
	}

	// Nuskaityti failo antraste(stulpelius)
	// Parasyta su prielaida, kad pirmi du stulpeliai: Vardas, Pavarde, o paskutinis: Egz.
	std::string header_str;
	std::getline(fr, header_str, '\n');
	
	int nd_skaicius = 0;

	// Nuskaitomas namu darbu kiekis su regex
	const std::regex reg_expr("ND\\d+");

	auto iterator = std::sregex_iterator(header_str.begin(), header_str.end(), reg_expr);
	auto empty = std::sregex_iterator();

	// Apskaičiuojame, kiek žodžių atitinka regex expression
	nd_skaicius = std::distance(iterator, empty);

	// Skaitomos eilutes, kol neprieis failo galo
	std::stringstream buffer;
	buffer << fr.rdbuf();
	fr.close();

	int tmp_paz;
	std::string line_buf;
	while (!buffer.eof()) {
		Studentas *s = new Studentas(nd_skaicius);
		buffer << s;
		stud.push_back(*s);
	}
}

template <typename container>
void isvesti_faila(const container &stud, std::string file_path) {
	Timer t;
	std::stringstream buffer;
	// Spausdinti visu studentu duomenis
	buffer << std::left << std::setw(20) << "Vardas" 
						   << std::setw(25) << "Pavardė" 
						   << "Galutinis (vid.)\n";
	buffer << "---------------------------------------------------------------\n";
	// Nustatomas tikslumas ir tik tada spausdinama
	buffer << std::fixed << std::setprecision(2);

	t.start_timer();
	for (auto& s : stud){
		buffer << s;
	}

	std::ofstream fr(file_path);
	fr << buffer.rdbuf();
	fr.close();
}