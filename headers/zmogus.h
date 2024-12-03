#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>

class Zmogus {
	protected:
  	std::string vardas;
  	std::string pavarde;

	public:
		virtual std::string get_vardas() = 0;
		virtual std::string get_pavarde() = 0;

		Zmogus() { std::cout << "Zmogus sukurtas"; };
		virtual ~Zmogus() { std::cout << "Zmogus istrintas"; };

		void set_vardas(std::string vardas) { this->vardas = vardas; };
		void set_pavarde(std::string pavarde) { this->pavarde = pavarde; };
};

#endif