#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
	public:
		Employee();
		Employee(std::string new_name, int new_id, std::string new_address, double new_salary, int new_years_worked);
		std::string get_name()const{return name;}
		int get_id_number()const{return id_number;}
		std::string get_address()const{return address;}
		double get_salary()const{return salary;}
		int get_years_started()const{return year_started;}
    void input(std::istream& ins);		
    void output(std::ostream& outs);
		
	private:
		std::string name;
		int id_number;
		std::string address;
		double salary;
		int year_started;
};
std::ostream& operator <<(std::ostream& outs, Employee& tmp);
std::istream& operator >>(std::istream& ins, Employee& tmp);
#endif
