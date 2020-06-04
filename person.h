#ifndef person_H
#define student_H

#pragma once
#include <iostream>
#include <string>
using namespace std;
class person 
{
	string person_name;
	string spec;
	int age;
	int exp;
public:
	person();
	person(string name, string s, int a, int e);//s-spec, a-age, e-exp
	~person();
	string get_name();
	string get_spec();
	int get_age();
	int get_exp();
	void set_name(string new_name);
	void set_spec(string new_spec);
	void set_age(int new_age);
	void set_exp(int new_exp);
	friend std::ostream& operator<<(std::ostream& output, person& H);
	//VVVV 3 домашнее задание VVVV
};

#endif

