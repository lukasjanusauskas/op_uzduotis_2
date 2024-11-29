#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

class Zmogus {
	protected:
  	std::string vardas;
  	std::string pavarde;

	public:
		virtual std::string get_vardas() { return vardas; };
		virtual std::string get_pavarde() { return pavarde; };

		void set_vardas(std::string vardas) { this->vardas = vardas; };
		void set_pavarde(std::string pavarde) { this->pavarde = pavarde; };
};

#endif