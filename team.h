#ifndef team_H
#define team_H

#include "person.h"
#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
class team 
{
	string team_name;
	vector<person> pers;
	int qty;
	vector<string> all_spec;
	int SumExp;
public:
	team();
	team(string name, vector<person> p);
	~team();
	string get_team_name();
	int get_qty();
	int get_SumExp();
	void set_team_name(string NewName);
	void add_person(person& p);
	void delete_person(person& p);
	void print_spec();
	friend ostream& operator<<(ostream& out, team& t);
	team operator+(person& p);
	//vvvv Домашнее задание №3 vvvv 
	void search(string Name, string Spec, int Age, int Exp);
	void edit_person(string Name, string NewName, string NewSpec, int NewAge, int NewExp);
	friend ofstream& operator<<(ofstream& out, team& t);
	friend ifstream& operator>>(ifstream& in, team& t);
	void sort_name();
	void sort_exp();
	void DeletePerson(string Name);
};

#endif