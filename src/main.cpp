#include "studentas.h"
#include "skaiciavimai.h"
#include "util.h"

#include "stud_random.cpp"
#include "studentas_io.cpp"
#include "stud_rikiavimas.cpp"
#include "timer.cpp"

#include <chrono>

template <typename container>
void testas(std::string file_path, container &stud);

template<typename container>
void pasirinkti_rikiavima(container &stud, std::string file_path);

template <typename container>
void konsoles_dialogas(container& stud);

void testuoti_eiga();
void testuoti_generavima();

int main() {
	// generuoti_penkis();

	std::list<Studentas> stud;
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
}

template <typename container>
void konsoles_dialogas(container& stud){
	char input;

input_option:
	std::string path = "studentai10000000.txt";

	std::cout << "Kaip įvesti studentus? Terminale - (t), Faile - (f)\n";
	std::cin >> input;

	switch (input)
	{
	case 't':
		irasyti_studentus(stud);
		break;

	case 'f':
		for(int i = 0; i < 3; i++)
	 		testas(path, stud);
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

	std::cout << "Rikiavimas studentų iš failo " << file_path << " užtruko " << elapsed.count() << "s\n";
}