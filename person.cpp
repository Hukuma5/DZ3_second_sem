#include "person.h"

person::person()
{
	person_name = spec = nullptr;
	age = exp = 0;
}

person::person(string name, string s, int a, int e)
{
	person_name = name;
	spec = s;
	age = a;
	exp = e;
}

string person::get_name()
{
	return person_name;
}

string person::get_spec()
{
	return spec;
}

int person::get_age()
{
	return age;
}

int person::get_exp()
{
	return exp;
}

void person::set_name(string new_name)
{
	person_name = new_name;
}

void person::set_spec(string new_spec)
{
	spec = new_spec;
}

void person::set_age(int new_age)
{
	age = new_age;
}

void person::set_exp(int new_exp)
{
	exp = new_exp;
}

ostream& operator<<(std::ostream& out, person& H)
{
	out << "Student:" << endl <<
		"Name = " << H.get_name() << ";" << endl <<
		"Specialty = " << H.get_spec() << ";" << endl <<
		"Age = " << H.get_age() << ";" << endl <<
		"Experience = " << H.get_exp() << "." << endl;
	return out;
}

person::~person()
{

}
