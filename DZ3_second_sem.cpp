#include <iostream>
#include "person.h"
#include "team.h"

int main()
{
	string teamname;
	cout << "Enter name of team: ";
	cin >> teamname;
	cout << endl;
	team T(teamname, {});
	string command = "";
	cout << "enter <<commands>> to see the list of cammands: ";
	while (command != "stop")
	{
		int co=0;
		cin >> command;
		if (command == "commands")
		{
			cout << "stop" << endl;
			cout << "add (<name> <specialty> <age> <working experience>)"<<endl;
			cout << "search (<name or nothing> <specialty or nothing> <age or 0> <working experience or 0>)"<<endl;
			cout << "edit (<name> <new name> <new specialty> <new age> <new working experience>)" << endl;
			cout << "save to file" << endl;
			cout << "read from file" << endl;
			cout << "sort (<by what parameter-(name or experience)>)"<<endl;
			cout << "delete (<name>)"<<endl;
			cout << "print" << endl;
			co++;
		}
		if (command == "add")
		{
			string Person_name;
			string Spec;
			int Age;
			int Exp;
			cin >> Person_name >> Spec >> Age >> Exp;
			person P(Person_name, Spec, Age, Exp);
			T + P;
			co++;
		}
		if (command == "search")
		{
			string Person_name;
			string Spec;
			int Age;
			int Exp;
			cin >> Person_name >> Spec >> Age >> Exp;
			T.search(Person_name, Spec, Age, Exp);
			co++;
		}
		if (command == "edit")
		{
			string Person_name;
			string NewPerson_name;
			string Spec;
			int Age;
			int Exp;
			cin >> Person_name >> NewPerson_name >> Spec >> Age >> Exp;
			T.edit_person(Person_name, NewPerson_name, Spec, Age, Exp);
			co++;
		}
		if (command == "save to file")
		{
			ofstream out("team.txt");
			out << T;
			out.close();
			co++;
		}
		if (command == "read from file")
		{
			ifstream in("team.txt");
			in >> T;
			in.close();
			co++;
		}
		if (command == "sort")
		{
			string param;
			cin >> param;
			if (param == "name") T.sort_name();
			else T.sort_exp();
			co++;
		}
		if (command == "delete")
		{
			string Name;
			cin >> Name;
			T.DeletePerson(Name);
			co++;
		}
		if (command == "print")
		{
			cout << T;
			co++;
		}
		if (co == 0)
		{
			cout << "wrong command" << endl;
		}
	}
}