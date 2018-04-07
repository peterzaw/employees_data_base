#include <iostream>
#include "employee.h"

using namespace std;

Employee::Employee()
{
    salary = 0;
	year_started = 0;
	id_number = 0;
	
}
Employee::Employee(std::string new_name, int new_id, std::string new_address, double new_salary, int new_years_worked)
{
	name = new_name;
	id_number = new_id;
	address = new_address;
	salary = new_salary;
	year_started = new_years_worked;
}
void Employee::output(ostream& outs)
{
	if(outs == cout)
	{
		outs << "Imie i nazwisko: " << name << endl;
		outs << "Numer ID: " << id_number << endl;
		outs << "Adres: " << address << endl;
		outs << "Wynagrodzenie: " << salary << endl;
		
	}
	else
{
		outs << name << endl;
		outs << id_number << endl;
		outs << address << endl;
		outs << salary << endl;

	}
}
void Employee::input(istream& ins)
{
		if (ins == cin)
        {
                if(ins.peek() == '\n')ins.ignore();
                cout << "Podaj imie i nazwisko: ";
                getline(ins,name);
                cout << "Podaj numer ID: ";
                ins >> id_number;
                cout << "Podaj adres: ";
                if(ins.peek() == '\n')ins.ignore();
                getline(ins,address);
                cout << "Podaj wynagrodzenie: ";
                ins >> salary;

        }
        else
{
        		if(ins.peek() == '\n')ins.ignore();
                getline(ins,name);
                if(ins.peek() == '\n')ins.ignore();
                ins >> id_number;
                if(ins.peek() == '\n')ins.ignore();
                getline(ins,address);
                ins >> salary;

        }

}
ostream& operator <<(ostream& outs, Employee& tmp)
{
	tmp.output(outs);
	return outs;
}
istream& operator >>(istream& ins, Employee& tmp)
{
	tmp.input(ins);
	return ins;
}
