#include "team.h"

team::team()
{
	team_name = nullptr;
	qty = SumExp = 0;
}

team::team(string name, vector<person> p)
{
	for (int i = 0; i < p.size(); i++) {
		add_person(p[i]);
		SumExp += p[i].get_exp();
		all_spec[i] = p[i].get_spec();
	}
	team_name = name;
	qty = p.size();
}

team::~team()
{

}

string team::get_team_name()
{
	return team_name;
}

int team::get_qty()
{
	return qty;
}

int team::get_SumExp()
{
	return SumExp;
}

void team::set_team_name(string NewName)
{
	team_name = NewName;
}

void team::add_person(person& p)
{
	pers.push_back(p);
	qty++;
	all_spec.push_back(p.get_spec());
	SumExp += p.get_exp();
}

void team::delete_person(person& p)
{
	if (pers.empty())
	{
		cout << "This group is empty";
	}
	else
	{
		pers.pop_back();
		qty--;
		all_spec.pop_back();
		SumExp -= p.get_exp();
	}
}

void team::print_spec()
{
	for (auto i : pers) {
		cout << i.get_spec();
		cout << endl;
	}
}

team team::operator+(person& p)
{
	add_person(p);
	return *this;
}

ostream& operator<<(ostream& out, team& t)
{
	out << "Group:" <<
		"name of group - " << t.get_team_name() << ";" << endl <<
		"amount of workers = " << t.get_qty() << ";" << endl <<
		"cumulative experience =" << t.get_SumExp() << "." << endl <<
		"All specialties of this team:" << endl;
	t.print_spec();
	out << endl;
	return out;
}

void team::search(string Name, string Spec, int Age, int Exp)
{
	int counter = 0;
	for (auto i : pers)
	{
		if (Name == "null") Name = i.get_name();
		if (Spec == "null") Spec = i.get_spec();
		if (Age == 0) Age = i.get_age();
		if (Exp == 0) Exp = i.get_exp();
		if ((Name == i.get_name()) && (Spec == i.get_spec()) && (Age == i.get_age()) && (Exp == i.get_exp()))
		{
			cout << i << endl;
			counter++;
		}
	}
	if (counter == 0) cout << "There is no such person" << endl;
}

void team::edit_person(string Name, string NewName, string NewSpec, int NewAge, int NewExp)
{
	int counter = 0;
	for (auto& i : pers)
	{
		if (i.get_name() == Name)
		{
			i.set_name(NewName);
			i.set_spec(NewSpec);
			i.set_age(NewAge);
			i.set_exp(NewExp);
			counter++;
		}
	}
	if (counter == 0) cout << "There is no such person" << endl;
}

ofstream& operator<<(ofstream& out, team& t)
{
	for (auto i : t.pers)
	{
		out << i.get_name() << endl;
		out << i.get_spec() << endl;
		out << i.get_age() << endl;
		out << i.get_exp() << endl;
	}
	return out;
}

ifstream& operator>>(ifstream& in, team& t)
{
	string Name;
	string Spec;
	int Age;
	int Exp;
	while (in) {
		in >> Name;
		in >> Spec;
		in >> Age;
		in >> Exp;
		if (!in) break;//мб ненужная строка
		person x(Name, Spec, Age, Exp);
		t + x;
	}
	return in;
}

void team::sort_name() 
{
	sort(pers.begin(), pers.end(), [](person& a, person& b) { return a.get_name() < b.get_name(); });
}

void team::sort_exp() 
{
	sort(pers.begin(), pers.end(), [](person& a, person& b) { return a.get_exp() < b.get_exp(); });
}

void team::DeletePerson(string Name)
{
	if (pers.empty()) {
		cout << "List is empty";
	}
	else
	{
		int ind = 0;
		for (auto i : pers)
		{
			ind++;
			if (i.get_name() == Name)
			{
				break;
			}
		}
		vector<person>::iterator it = pers.begin();
		advance(it, ind - 1);
		pers.erase(it);
	}
}