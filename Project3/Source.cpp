#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Employee {
	double salary;
	int id;
	string name;
	void setID(int id) {
		if (id > 0) {
			this->id = id;
		}
		else {
			throw string("Line: " + to_string(__LINE__) + "ID 0dan voyuk olmalidir!");
		}
	}
public:
	Employee(string name, double salary, int id) {
		setName(name);
		setID(id);
		setSalary(salary);
	}

	string getName() const {
		return name;
	}
	double getSalary() const {
		return salary;
	}
	int getId() const {
		return id;
	}

	void setName(string name) {
		if (name.length() < 3) {
			throw string("Line: " + to_string(__LINE__) + "\n" + "ad 3 xarakterden cox olmalidir!");
		}
		this->name = name;
	}

	void setSalary(double salary) {
		if (salary < 400) {
			throw string("Line: " + to_string(__LINE__) + "Maas 400den az ola bilmez!");
		}

		this->salary = salary;
	}

	virtual void show() = 0 {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Salary: " << salary << endl;
	}

};

class Developer : public Employee {
	vector<string> programmingLanguagies;
public:

	Developer(string name, double salary, int id) : Employee(name, salary, id) {};

	void addLanguage(string Language) {
		for (size_t i = 0; i < programmingLanguagies.size(); i++)
		{
			if (programmingLanguagies[i] == Language) {
				throw string("Line: " + to_string(__LINE__) + "Bu Proqram dili artiq var!");
			}
		}
		
		programmingLanguagies.push_back(Language);
	}


	void show() override {
		Employee::show();
		cout << "Langueages: " << endl;
		for (size_t i = 0; i < programmingLanguagies.size(); i++)
		{
			cout << programmingLanguagies[i] << '  ';
		}
	}
};

class Manager : Employee {
	int teamSize;
public:

	Manager(string name, double salary, int id, int teamSize) : Employee(name, salary, id) {
		setTeamSize(teamSize);
	};

	int getTeamSize() const {
		return teamSize;
	}

	void setTeamSize(int teamSize) {
		if (teamSize < 2) {
			throw string("Line: " + to_string(__LINE__) + "Team minimum 2 neferden ibaret olmalidir!");
		}
		this->teamSize = teamSize;
	}

	void show() override {
		Employee::show();
		cout << getTeamSize() << endl;
	}
};

class Company {
	vector<Employee*> employees;
public:

	void addEmployee(Employee* employee) {
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i]->getId() == employee->getId()) {
				throw string("Line: " + to_string(__LINE__) + "Bu ID istifade olunub!");
			}
		} 
		employees.push_back(employee);
	}

	void ShowAllEmployee() const {
		for (int i = 0; i < employees.size(); i++)
		{
			employees[i]->show();
		}
	}
	void UpdateDeveloperProgrammingLanguage(int id, string programmingLanguage) {
		for (int i = 0; i < employees.size(); i++)
		{
			if (employees[i]->getId() == id) {
				Developer* dev = dynamic_cast<Developer*>(employees[i]);
				if (dev != nullptr) {
					dev->addLanguage(programmingLanguage);
				}
				else {
					throw string("Developer not found...");
				}
			}
		}
		throw string("Employee not found...");
	}
};



void main() {

	//const int* data = new int(55);
	//*(const_cast<int*> (data)) = 99;
	//cout << *data << endl;
	////*data = 88;
	///////////////////////////////////////////////////////



	/*
Employee=>int id, string name, double salary
method- Show()

Developer=> Employee, vector<string> programmingLanguagies
method- Show(), AddLanguage(string lang)-yoxlasin o dil yoxdursa pushback


Manager=> Employee, int teamSize
method- Show()

Company=> vector<Employe*> employees
methods- AddEmployee(Employee e)= throw-lari yazin,
ViewAllEmployee(), UpdateDeveloperProgrammingLanguage(int id,string programmingLanguage)

*/


}