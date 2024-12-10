#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>

/// @brief  Abstrakti klasė, skirta galimam praplėtimui ateityje
class Zmogus {
	protected:
  	std::string vardas;
  	std::string pavarde;

	public:
		/// Vardo getter'is
		virtual std::string get_vardas() = 0; 
		/// Pavardės getter'is
		virtual std::string get_pavarde() = 0; 

		Zmogus() {};
		virtual ~Zmogus() {};

		/// Virtualus vardo setter'is
		void set_vardas(std::string vardas) { this->vardas = vardas; }; 		
		/// Virtualus pavardės setter'is
		void set_pavarde(std::string pavarde) { this->pavarde = pavarde; }; 
};

#endif