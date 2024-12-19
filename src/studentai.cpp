#define DOCTEST_CONFIG_IMPLEMENT 

#include "studentas.h"
#include "skaiciavimai.h"
#include "util.h"

#include "stud_random.cpp"
#include "studentas_io.cpp"
#include "stud_rikiavimas.cpp"
#include "timer.cpp"

#include <chrono>
#include <cmath>

template <typename container>
void testas(std::string file_path, container &stud);

template<typename container>
void pasirinkti_rikiavima(container &stud, std::string file_path);

std::string pasirinkti_faila();
template <typename container>
void konsoles_dialogas(container& stud);

void testuoti_generavima();
void test_pasirinkti();
void demonstracija();

int main(int argc, char** argv) {
	// generuoti_penkis();

	std::vector<Studentas> stud;
	konsoles_dialogas(stud);

	return 0;
}

void testuoti_generavima(){
	for(int i = 0; i < 3; i++){
		generuoti_penkis();
	}
}

template <typename container>
void testas(std::string file_path, container& stud){
	container vargsai, galvos;

	Timer t;
	// Ivedimas
	t.start_timer();
	nuskaityti_faila(stud, file_path);
	std::cout << "Nuskaitymas failo " << file_path << " užtruko " << t.get_time() << " s\n";

	// Rikiavimas
	pasirinkti_rikiavima(stud, file_path);

	// Kategorizavimas
	t.restart_timer();
	kategorizuoti(stud, vargsai, galvos);
	std::cout << "Skirstymas " << file_path << " užtruko " << t.get_time() << " s\n";

	// Isvedimas
	t.restart_timer();
	isvesti_faila(vargsai, "vargsai.txt");
	isvesti_faila(galvos, "galvos.txt");
	std::cout << "Išvedimas " << file_path << " užtruko " << t.get_time() << " s\n";

	std::cout << std::endl;

	stud.clear(); galvos.clear(); vargsai.clear();
}

std::string pasirinkti_faila() {
	std::cout << "Pasirinkti faila" << std::endl;

	int size = 1000; std::string input;
	for (int i = 1; i <= 5; i ++){
		std::cout << "Failas " << i << " studentai" << size <<".txt\n";
		size *= 10;
	}

	int choice;
	while(true){
		std::cin >> input;
		try {
			choice = std::stoi(input);
			break;
		} catch (std::exception& e) {
			continue;
		}
	}

	std::string size_str = std::to_string((int)(1000 * pow(10, choice - 1)));
	return "studentai" + size_str + ".txt";
}

// void demonstracija() {
// 	try{
// 		Zmogus zmogus;

// 	} catch (std::exception& e) {
// 		std::cout << "C++ neleidžia";
// 	}
// }

template <typename container>
void konsoles_dialogas(container& stud){
	char input;

input_option:
	std::cout << "Kaip įvesti studentus? Terminale - (t), Faile - (f)\n";
	std::cin >> input;

	std::string path;

	switch (input)
	{
	case 't':
		irasyti_studentus(stud);
		break;

	case 'f':
		for(int i = 0; i < 5; i++) {
			path = pasirinkti_faila();
	 		testas(path, stud);
		}
		break;
	
	default:
	 	goto input_option;
	}
}

template <typename container>
void pasirinkti_rikiavima(container& stud, std::string file_path){
	char input;
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed;

 sort_option:
	std::cout << "Rikiuoti pagal: (v)ardus, (p)avardes ar (g)alutinį pažymį?\n";
	std::cin >> input;

	switch (input)
	{
	case 'v':
		start = std::chrono::system_clock::now();

		rikiuoti_studentus(stud, Studentas::compareVardas);

		end = std::chrono::system_clock::now();
		elapsed = end - start;
		break;

	case 'p':
		start = std::chrono::system_clock::now();

		rikiuoti_studentus(stud, Studentas::comparePavarde);

		end = std::chrono::system_clock::now();
		elapsed = end - start;
		break;

	case 'g':
		start = std::chrono::system_clock::now();

		rikiuoti_studentus(stud, Studentas::compareEgza);

		end = std::chrono::system_clock::now();
		elapsed = end - start;
		break;
	
	default:
	 	goto sort_option;
	}

	std::cout << "Rikiavimas studentų iš failo " << file_path << " užtruko " << elapsed.count() << " s\n";
}

void test_pasirinkti(){
	for(int i = 0; i < 3; i++) {
		std::string path = pasirinkti_faila();
		std::cout << path;
	}
}