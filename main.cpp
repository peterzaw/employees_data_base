#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "employee.h"
#include "database.h"

using namespace std;

int menu()
{
	int wybor;
	cout << "1. Dodaj nowego pracownika" << endl;
	cout << "2. Szukaj pracownika po imieniu i nazwisku" << endl;
	cout << "3. Szukaj pracownika po numerze ID" << endl;
	cout << "4. Pokaz wszystkich pracownikow" << endl;
	cout << "5. Usun pracownika z bazy danych" << endl;
	cout << "6. Pokaz pracownikow wg wynagrodzenia" << endl;
	cout << "7. Pokaz pracownikow wg imienia i nazwiska" << endl;
	cout << "8. Wyjscie" << endl;
	cout <<"\n"<<endl;
	cin >> wybor;
	return wybor;
}

int main()
{
    menu();
	Database bazad;
	Employee pracownik;
	string filename;
	filename ="plikzapisu.txt";
	ifstream fin(filename.c_str());
	if(!fin.fail())
	{
		bazad.load(fin);
		fin.close();
		int wybor;
		while(wybor!=8)

		{
			wybor = menu();
			switch (wybor)
			{
				case 1:{
					cin >> pracownik;
					bazad.add(pracownik);
					break;
				}
				case 2:{
					system("cls");
					string name;
					cout << "Szukaj pracownika po imieniu i nazwisku";
					if(cin.peek() == '\n')cin.ignore();
					getline(cin,name);
					bazad.search(name);
					break;
				}
				case 3:{
					system ("cls");
					int id;
					cout << "Szukaj pracownika po numerze ID";
					cin >> id;
					bazad.search_id(id);
					break;
				}
				case 4:{
					system("cls");
					cout << "Pokaz wszystkich pracownikow:" << endl;
					bazad.display_all();
					break;
				}
				case 5:{
					system("cls");
					string name;
					cout << "Usun pracownika z bazy danych";
					if(cin.peek() == '\n')cin.ignore();
					getline(cin,name);
					bazad.remove(name);
					break;
				}
				case 6:{
					system("cls");
					bazad.sort_salary();
					cout << "Pokaz pracownikow wg wynagrodzenia:" << endl;
					bazad.display_all();
					break;
				}
				case 7:{
					system("cls");
					bazad.sort_name();
					cout << "Pokaz pracownikow wg imienia i nazwiska:" <<endl;
					bazad.display_all();
					break;
				}
				case 8:{
					break;
				}
				default:{
					system("cls");
					cout << "Niepoprawne wejscie" << endl;
					break;
				}
			}
		}
		ofstream fout(filename.c_str());
		if(!fout.fail())
		{
			bazad.save(fout);
		}
		else{
			cout << "Nie mozna otworzyc pliku" << endl;
		}
		fout.close();
		cout << "Employees data base by peterzaw" << endl;
	}
	
	return 0;
}

