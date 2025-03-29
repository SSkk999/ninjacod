using namespace std;
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
int perev = 0;
string namelogin;
string nameuser;

//string chifrovka(string name)
//{
//	for (size_t i = 0; i < name.length(); i++)
//	{
//		name[i] = name[i] + 1;
//	}
//	return name;
//}
//string roschifrovka(string name)
//{
//	for (size_t i = 0; i < name.length(); i++)
//	{
//		name[i] = name[i] - 1;
//	}
//	return name;
//}
struct usersamarks
{
	string namelog;
	vector<string>section;
	vector<string>test;
	vector<int>marks;
	usersamarks(string namelog) :namelog(namelog) {

	}
	void getresults(string section1, string test1, int mark) {
		section.push_back(section1);
		test.push_back(test1);
		marks.push_back(mark);
	}
	string getnamelog()
	{
		return namelog;
	}
	void readuser(ofstream& file)
	{
		file << "log: " << namelog << endl;
		for (int i = 0; i < section.size(); i++)
		{
			file << "section:" << section[i] << endl;
			file << "test:" << test[i] << endl;
			file << "marks: " << marks[i] << endl;
		}
	}
	void dalateusermaeks(string name) {

	}
	void dalate()
	{
		section.clear();
		test.clear();
		marks.clear();
	}
	void readuseruser1()
	{
		cout << "log: " << namelog << endl;
		for (int i = 0; i < section.size(); i++)
		{
			cout << "section:" << section[i] << endl;
			cout << "test:" << test[i] << endl;
			cout << "marks: " << marks[i] << endl;
		}
	}
	void readgryptestchil(string name)
	{
		name = " " + name;
		int i = 0;
		int perev = 0;
		for (i = 0; i < section.size(); i++)
		{
			if (section[i] == name)
			{
				cout << "log: " << namelog << endl;
				cout << "section:" << section[i] << endl;
				cout << "test:" << test[i] << endl;
				cout << "marks: " << marks[i] << endl;
				perev++;
				break;
			}

		}
		for (i = 0; i < section.size(); i++)
		{
			if (section[i] == name)
			{

				cout << "section:" << section[i] << endl;
				cout << "test:" << test[i] << endl;
				cout << "marks: " << marks[i] << endl;
				perev++;
				break;
			}
		}

	}

	void  readgryptestichil(string name)
	{
		name = " " + name;
		int i = 0;

		for (i = 0; i < section.size(); i++)
		{
			if (test[i] == name)
			{
				cout << "log: " << namelog << endl;
				cout << "section:" << section[i] << endl;
				cout << "test:" << test[i] << endl;
				cout << "marks: " << marks[i] << endl;
				perev++;
				break;
			}

		}
		for (i = 0; i < section.size(); i++)
		{
			if (test[i] == name)
			{

				cout << "section:" << section[i] << endl;
				cout << "test:" << test[i] << endl;
				cout << "marks: " << marks[i] << endl;
				perev++;
				break;
			}
		}

	}

	void readuseruser()
	{

		for (int i = 0; i < section.size(); i++)
		{
			cout << "section:" << section[i] << endl;
			cout << "test:" << test[i] << endl;
			cout << "marks: " << marks[i] << endl;
		}
	}
	void readutest(string names, string namet)
	{
		int s = 0;
		for (int i = 0; i < section.size(); i++)
		{
			//string s1 = section[i];
			//s1 = " " + s1;

			if (section[i] == names && test[i] == namet)
			{

				cout << "section:" << section[i] << endl;
				cout << "test:" << test[i] << endl;
				cout << "marks: " << marks[i] << endl;
				s++;
			}
		}
		if (s > 0)
		{

		}
		else
		{
			cout << "there are no results for this test or even category" << endl;
		}
	}

	void pokasisection(string namesection)
	{

		int s = 0;
		for (int i = 0; i < section.size(); i++)
		{
			//string s1 = section[i];
			//s1 = " " + s1;

			if (section[i] == namesection)
			{

				cout << "section:" << section[i] << endl;
				cout << "test:" << test[i] << endl;
				cout << "marks: " << marks[i] << endl;
				s++;
			}
		}
		if (s > 0)
		{

		}
		else
		{
			cout << "no results for this section" << endl;
		}
	}
	void setlog(string name)
	{
		this->namelog = name;
	}
};
vector<usersamarks> usersmark;

void readnextr(ifstream& iftf)
{
	string slov;
	string section;
	string test;
	int marks;
	iftf.ignore();
	getline(iftf, slov);
	usersamarks sd(slov);
	while (iftf >> slov)
	{
		if (slov == "section:")
		{
			getline(iftf, section);

		}
		else if (slov == "test:")
		{

			getline(iftf, test);

		}
		else if (slov == "marks:")
		{

			iftf >> marks;

			sd.getresults(section, test, marks);

		}
		else if (slov == "log:")
		{
			readnextr(iftf);
			usersmark.push_back(sd);
			return;
		}

	}
	usersmark.push_back(sd);

}


void read1()
{
	for (auto& sd1 : usersmark)
	{
		sd1.dalate();
	}
	usersmark.clear();
	string slov;
	string section;
	string test;
	int marks;
	ifstream iftf("usermarks.txt");
	while (iftf >> slov)
	{
		if (slov == "log:")
		{
			iftf.ignore();
			getline(iftf, slov);
			usersamarks sd(slov);
			while (iftf >> slov)
			{
				if (slov == "section:")
				{

					getline(iftf, section);

				}
				else if (slov == "test:")
				{

					getline(iftf, test);

				}
				else if (slov == "marks:")
				{

					iftf >> marks;

					sd.getresults(section, test, marks);

				}
				else if (slov == "log:")
				{
					readnextr(iftf);
					usersmark.push_back(sd);
					return;
				}

			}
			usersmark.push_back(sd);


		}


	}


}


void getfilemark()
{
	ofstream oftf("usermarks.txt");
	for (auto& sd1 : usersmark)
	{
		sd1.readuser(oftf);
	}
}


void dalateusmarks(string name)
{
	read1();
	vector<usersamarks> temp;
	for (int i = 0; i < usersmark.size(); i++)
	{

		if (usersmark[i].getnamelog() == name)
		{

		}
		else
		{
			temp.push_back(usersmark[i]);
		}
	}
	usersmark = temp;
	temp.clear();
	getfilemark();

}
void setlofnameusermarks(string thisname, string newname)
{
	read1();

	for (int i = 0; i < usersmark.size(); i++)
	{

		if (usersmark[i].getnamelog() == thisname)
		{
			usersmark[i].setlog(newname);
		}

	}

	getfilemark();
}
void enterfilemarks(string sectioname, string nametesty, int mark)
{
	read1();
	for (auto& sd1 : usersmark)
	{
		if (sd1.getnamelog() == namelogin)
		{
			sd1.getresults(sectioname, nametesty, mark);
			getfilemark();
			return;
		}
	}
	usersamarks sd(namelogin);
	sd.getresults(sectioname, nametesty, mark);
	usersmark.push_back(sd);
	getfilemark();

}





class question {
	string name;
	map<string, string>pytania;
public:
	question(string name) :name(name) {}
	void add(string pyt, string vid) {
		pytania.insert(make_pair(pyt, vid));
	}
	string getname()
	{
		return name;
	}
	void clear33()
	{

		pytania.clear();
	}
	void setvid(string key, string value)
	{
		add(key, value);
	}
	void pyt()
	{
		int i = 0;
		cout << "pyt:" << name << endl;
		for (auto sd : pytania)
		{
			cout << ++i << ":" << sd.first << " " << sd.second << " ";
		}

	}
	void corect()
	{
		int count = 0;
		string name;
		while (true)
		{
			cin.ignore();
			int count = 0;
			for (auto& sd : pytania)
			{
				cout << ++count << "pyt:" << sd.first << " vid:" << sd.second << endl;
			}

			cout << "Enter pyt which you want to change:";
			getline(cin, name);
			if (name == "00")
			{
				return;
			}
			if (pytania.find(name) != pytania.end()) {
				pytania[name] = pytania[name] == "true" ? "false" : "true";
			}
			else {
				cout << "Key not found!";
				cout << endl;
			}
			cout << "wish to continue?yes/no?";
			cin >> name;
			if (name == "yes")
			{

			}
			else if (name == "no")
			{
				return;
			}
		}

	}
	void replacesectionnametask()
	{
		cin.ignore();
		string newname;
		cout << "Enter new name:";
		getline(cin, newname);
		newname = " " + newname;
		this->name = newname;
		cout << "name changed successfully" << endl;
	}
	void replaceetestnamevid()
	{
		cin.ignore();
		int i = 0;
		string name;
		if (pytania.empty())
		{
			cout << "pytania" << endl;
		}
		for (auto sd : pytania)
		{

			cout << ++i << ":" << sd.first << " " << endl;
		}
		cout << "which answer do you want to change?";
		getline(cin, name);
		if (pytania.find(name) != pytania.end())
		{
			string temp = pytania[name];
			pytania.erase(name);
			cout << "Entet new name answer:";
			getline(cin, name);
			pytania.insert(make_pair(name, temp));

		}
		else
		{
			cout << "name answer nit found" << endl;
		}
	}
	void dalateanswer()
	{
		pytania.clear();
	}
	bool checktrue()
	{
		for (auto& sd : pytania)
		{
			if (sd.second == "true")
			{

				return true;
			}

		}
		return false;
	}
	void daleteans4()
	{
		cin.ignore();
		string namesection;
		int count = 0;
		if (pytania.size() <= 2)
		{
			cout << "few questions" << endl;
			return;
		}
		for (auto& sd : pytania)
		{
			cout << ++count << "pyt:" << sd.first << endl;
		}
		cout << "Enter pyt which you want to dalate:";
		getline(cin, namesection);
		if (pytania.find(namesection) != pytania.end())
		{
			pytania.erase(namesection);
		}
		else
		{
			cout << "not faund name answer" << endl;
		}
		if (checktrue())
		{
			cout << "response deleted successfully" << endl;
			return;
		}
		else
		{
			cin.ignore();
			string switchh;
			cout << "there is no correct answer in the test, do you want to leave it? yes/no?:" << endl;
			getline(cin, switchh);
			if (switchh == "yes")
			{
				corect();
				return;
			}
			else if (switchh == "no")
			{
				cout << "exit" << endl;
				return;
			}
			else
			{
				cout << "I think you want to go out" << endl;
				return;
			}


		}
	}
	void importqveshion(ofstream& sd)
	{
		for (auto& sd1 : pytania)
		{
			sd << sd1.first << " " << sd1.second << " ";
		}
		sd << endl;

	}
	bool takeans()
	{
		while (true)
		{
			while (true)
			{
				int count = 0;
				int i = 0;
				cout << "question" << name << endl;
				for (auto& sd1 : pytania)
				{
					cout << ++count << ":" << sd1.first << " ";
				}
				cout << "exit = -00\nenter the answer you read as correct:";
				if (cin >> count)
				{
					if (count == -00)
					{
						cout << "exit" << endl;
						return false;
					}

					if (count < 0)
					{
						cout << "num < 0" << endl;

					}
					else if (count > pytania.size())
					{
						cout << "num > size " << endl;

					}
					else
					{

						for (auto& sd1 : pytania)
						{
							i++;
							if (i == count)
							{
								return (sd1.second == "true") ? true : false;
							}
						}



					}
				}
				else {
					cout << "Enter int!!!!!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}

			}
		}

	}
	int returncountans()
	{
		int s = pytania.size();
		return s;
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////

class testy
{
	string name;
	int marks = 0;
	vector<question>question1;
public:
	testy(string name) :name(name) {}
	void add(string name)
	{
		question sd(name);
		question1.push_back(sd);


	}
	string getnametesty()
	{
		return name;
	}
	void  question2()
	{
		int i = 0;
		for (auto& ge : question1)
		{
			ge.pyt();
			cout << endl;

		}
	}
	void clear12()
	{
		for (auto& sd : question1)
		{
			sd.clear33();

		}
		question1.clear();
	}
	void addandver3(string nameanswer, string key, string value)
	{
		for (auto& sd : question1)
		{
			if (nameanswer == sd.getname())
			{
				sd.setvid(key, value);
			}

		}

	}
	bool perevirkadyblickat(string nametask)
	{
		for (auto& sd : question1)
		{
			if (nametask == sd.getname())
			{
				return false;
			}
		}
		return true;
	}
	void correctanswerstestick()
	{
		while (true) {
			while (true)
			{
				int count = 0;
				cout << "which question?\n if you want to exit, write 00." << endl;
				for (auto& sd : question1)
				{
					cout << ++count << sd.getname() << endl;
				}
				cout << "Enter num:";
				if (cin >> count)
				{

				}
				else
				{
					cout << "Enter int!!!!!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
				if (count == 00)
				{
					return;
				}
				if (count > question1.size())
				{
					cout << "num = 0" << endl;
					break;
				}
				if (count > question1.size())
				{
					cout << "num > size questions" << endl;
					break;
				}

				if (count <= question1.size())
				{
					question1[count - 1].corect();
					return;

				}
			}

		}


	}
	void replacesectionname()
	{
		cin.ignore();
		string newname;
		cout << "Enter new name:";
		getline(cin, newname);
		newname = " " + newname;
		this->name = newname;
		cout << "name changed successfully" << endl;
	}
	void replacetestnnametask()
	{
		cin.ignore();
		string namesection;
		int num = 0;
		for (auto& sd : question1)
		{
			cout << ++num << ":" << sd.getname() << endl;
		}
		cout << "enter name  question which you want to change:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : question1)
		{
			if (sd.getname() == namesection)
			{
				sd.replacesectionnametask();
				return;
			}
		}
		cout << "eror test name" << endl;
		return;
	}
	void replaceetestnamevid()
	{
		cin.ignore();
		string namesection;
		int num = 0;
		for (auto& sd : question1)
		{
			cout << ++num << ":" << sd.getname() << endl;
		}
		cout << "enter name  question which you want to change:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : question1)
		{
			if (sd.getname() == namesection)
			{
				sd.replaceetestnamevid();
				return;
			}
		}
		cout << "eror test name" << endl;
		return;
	}
	void dalatetestsectin()
	{
		for (auto& sd : question1)
		{
			sd.dalateanswer();
		}
		question1.clear();
	}
	void daletetask3()
	{
		cin.ignore();
		string namesection;
		int num = 0;
		int coutnt = 0;
		vector <question> temp;
		if (!question1.empty())
		{
			for (auto& sd : question1)
			{
				cout << ++num << ":" << sd.getname() << endl;
			}
		}
		else
		{
			cout << "empty" << endl;
			return;
		}
		cout << "enter name test which you want to dalate:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : question1)
		{
			if (sd.getname() == namesection)
			{
				sd.dalateanswer();
				for (int i = 0; i < question1.size(); i++)
				{

					if (i != coutnt)
					{
						temp.push_back(question1[i]);
					}



				}

				question1 = temp;
				temp.clear();
				return;


			}
			coutnt++;
		}
		cout << "eror test name" << endl;
		return;
	}
	void daleteans3()
	{
		cin.ignore();
		string namesection;
		int num = 0;
		if (!question1.empty())
		{
			for (auto& sd : question1)
			{
				cout << ++num << ":" << sd.getname() << endl;
			}
		}
		else
		{
			cout << "empty" << endl;
			return;
		}
		cout << "enter name task where do you want to delete the ans?:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : question1)
		{
			if (sd.getname() == namesection)
			{
				sd.daleteans4();
				return;
			}
		}
		cout << "eror task name" << endl;
		return;
	}
	void importtask(ofstream& sd)
	{
		for (auto& sd1 : question1)
		{
			sd << "task:" << sd1.getname() << endl;
			sd1.importqveshion(sd);
		}

	}
	void  takeansver()
	{
		int sd = 0;
		int prots = 0;
		if (question1.empty())
		{
			cout << "empty" << endl;
			return;
		}
		cout << "test:" << name << endl;
		for (auto& sd1 : question1)
		{
			if (sd1.takeans())
			{
				sd++;
			}
		}
		cout << "correct types:" << sd << endl;
		prots = proth(sd);

		cout << "percent:" << prots << "%" << endl;
		sd = countmarks(sd);
		if (sd == 0)
		{
			sd++;
		}
		cout << "marks:" << sd << endl;
		marks = sd;
		return;
	}
	int proth(int pr)
	{
		int kilp = question1.size();
		int s = (pr / kilp) * 100;
		return s;
	}
	int countmarks(int pr)
	{
		int ret = 0;
		int s = question1.size();
		ret = (12 / s) * pr;
		return ret;
	}
	int retmark()
	{
		return marks;
	}
	int retnum()
	{
		return question1.size();
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class section
{
	string name;
	vector<testy> testyki;
	int cilcistitestov = 0;
public:
	section(string name) :name(name) {}
	void add(string name)
	{
		testy sd(name);
		testyki.push_back(sd);
	}
	string getname()
	{
		return name;
	}
	void task(string thistask, string name)
	{
		for (auto& sd : testyki)
		{

			if (sd.getnametesty() == thistask)
			{
				sd.add(name);
			}

		}
	}
	void readnametest()
	{
		for (auto& sd : testyki)
		{

			cout << "test:" << sd.getnametesty() << endl;;
			sd.question2();
			cout << endl;
		}

	}
	void readnamequa()
	{
		int i = 0;
		for (auto& sd : testyki)
		{

			sd.question2();

		}
	}
	void clear22()
	{
		for (auto& sd : testyki)
		{
			sd.clear12();

		}

		testyki.clear();
	}

	void addansver12(string ans, string test, string key, string value)
	{
		for (auto& sd : testyki)
		{

			if (sd.getnametesty() == test)
			{
				sd.addandver3(ans, key, value);
			}
		}
	}
	bool checkdyblickatestname(string nametest)
	{
		for (auto& sd : testyki)
		{
			if (sd.getnametesty() == nametest)
			{
				return true;
			}
		}
		return false;
	}
	bool checkdyblickatestname2(string nametest)
	{
		for (auto& sd : testyki)
		{
			if (sd.getnametesty() == nametest)
			{
				return false;
			}
		}
		return true;
	}
	bool checknametask(string nametest, string nametask)
	{
		for (auto& sd : testyki)
		{
			if (nametest == sd.getnametesty()) {
				if (sd.perevirkadyblickat(nametask))
				{
					return true;
				}
			}

		}
		return false;
	}


	void correctanswerstestick()
	{
		while (true) {
			while (true)
			{
				int count = 0;
				cout << "which test?\n if you want to exit, write 00." << endl;
				for (auto& sd : testyki)
				{
					cout << ++count << sd.getnametesty() << endl;
				}
				cout << "Enter num:";

				if (cin >> count)
				{

				}
				else
				{
					cout << "Enter int!!!!!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
				if (count == 00)
				{
					return;
				}
				if (count > testyki.size())
				{
					cout << "num = 0" << endl;
					break;
				}
				if (count > testyki.size())
				{
					cout << "num > size testiv" << endl;
					break;
				}

				if (count <= testyki.size())
				{
					testyki[count - 1].correctanswerstestick();
					return;

				}
			}

		}


	}
	void replacesectionname()
	{
		cin.ignore();
		string newname;
		cout << "Enter new name:";
		getline(cin, newname);
		newname = " " + newname;
		this->name = newname;
		cout << "name changed successfully" << endl;
	}

	void replacetestnname()
	{
		cin.ignore();
		string namesection;
		int num = 0;
		for (auto& sd : testyki)
		{
			cout << ++num << ":" << sd.getnametesty() << endl;
		}
		cout << "enter name test which you want to change:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : testyki)
		{
			if (sd.getnametesty() == namesection)
			{
				sd.replacesectionname();
				return;
			}
		}
		cout << "eror test name" << endl;
		return;
	}


	void replacetestnnametask()
	{
		cin.ignore();
		string namesection;
		int num = 0;
		for (auto& sd : testyki)
		{
			cout << ++num << ":" << sd.getnametesty() << endl;
		}
		cout << "enter name test which you want to change:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : testyki)
		{
			if (sd.getnametesty() == namesection)
			{
				sd.replacetestnnametask();
				return;
			}
		}
		cout << "eror test name" << endl;
		return;
	}
	void replaceetestnamevid()
	{
		cin.ignore();
		string namesection;
		int num = 0;
		for (auto& sd : testyki)
		{
			cout << ++num << ":" << sd.getnametesty() << endl;
		}
		cout << "enter name test which you want to change:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : testyki)
		{
			if (sd.getnametesty() == namesection)
			{
				sd.replaceetestnamevid();
				return;
			}
		}
		cout << "eror test name" << endl;
		return;
	}
	void daletesection()
	{

		cout << "dalate sectin:" << endl;
		for (auto& sd : testyki)
		{
			sd.dalatetestsectin();

		}
		testyki.clear();
	}
	void dalatetest2()
	{
		cin.ignore();
		string namesection;
		int num = 0;
		int coutnt = 0;
		vector <testy> temp;
		if (!testyki.empty())
		{
			for (auto& sd : testyki)
			{
				cout << ++num << ":" << sd.getnametesty() << endl;
			}
		}
		else
		{
			cout << "empty" << endl;
			return;
		}
		cout << "enter name test which you want to dalate:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : testyki)
		{
			if (sd.getnametesty() == namesection)
			{
				sd.dalatetestsectin();
				for (int i = 0; i < testyki.size(); i++)
				{

					if (i != coutnt)
					{
						temp.push_back(testyki[i]);
					}



				}

				testyki = temp;
				temp.clear();
				return;
				sd.dalatetestsectin();

			}
			coutnt++;
		}
		cout << "eror test name" << endl;
		return;
	}
	void daletetask2()
	{
		cin.ignore();
		string namesection;
		int num = 0;
		if (!testyki.empty())
		{
			for (auto& sd : testyki)
			{
				cout << ++num << ":" << sd.getnametesty() << endl;
			}
		}
		else
		{
			cout << "empty" << endl;
			return;
		}
		cout << "enter name test where do you want to delete the ans?:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : testyki)
		{
			if (sd.getnametesty() == namesection)
			{
				sd.daletetask3();
				return;
			}
		}
	}
	void daleteans2()
	{
		cin.ignore();
		string namesection;
		int num = 0;
		if (!testyki.empty())
		{
			for (auto& sd : testyki)
			{
				cout << ++num << ":" << sd.getnametesty() << endl;
			}
		}
		else
		{
			cout << "empty" << endl;
			return;
		}
		cout << "enter name test where do you want to delete the ans?:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : testyki)
		{
			if (sd.getnametesty() == namesection)
			{
				sd.daleteans3();
				return;
			}
		}
	}
	void importtestname(ofstream& sd)
	{
		for (auto& sd1 : testyki)
		{
			sd << "test:" << sd1.getnametesty() << endl;
			sd1.importtask(sd);
		}
	}
	void taketest()
	{
		string nametest;
		if (testyki.empty())
		{
			cout << "empty" << endl;
			return;
		}
		while (true)
		{
			while (true)
			{
				int count = 0;

				for (auto& sd1 : testyki)
				{
					cout << ++count << ":" << "testy:" << sd1.getnametesty() << endl;
				}

				cout << "exit = -00 ";
				cout << "select the test  of the test you want to pass:";
				if (cin >> count)
				{
					if (count == -00)
					{
						cout << "exit" << endl;
						return;
					}
					count--;
					if (count < 0)
					{
						cout << "num < 0" << endl;

					}
					else if (count >= testyki.size())
					{
						cout << "num > size " << endl;

					}
					else
					{


						testyki[count].takeansver();
						nametest = testyki[count].getnametesty();
						string n = getname();
						cout << "name:" << n << endl;
						enterfilemarks(n, nametest, testyki[count].retmark());

					}
				}
				else {
					cout << "Enter int!!!!!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
		}

	}

	void testuser(string name)
	{
		string nametest;
		if (testyki.empty())
		{
			cout << "empty" << endl;
			return;
		}
		while (true)
		{
			while (true)
			{
				int count = 0;

				for (auto& sd1 : testyki)
				{
					cout << ++count << ":" << "testy:" << sd1.getnametesty() << endl;
				}

				cout << "exit = -00 ";
				cout << "select the test  of the test you want to pass:";
				if (cin >> count)
				{
					if (count == -00)
					{
						cout << "exit" << endl;
						return;
					}
					count--;
					if (count < 0)
					{
						cout << "num < 0" << endl;

					}
					else if (count >= testyki.size())
					{
						cout << "num > size " << endl;

					}
					else
					{


						read1();
						for (auto& sd1 : usersmark)
						{
							if (sd1.getnamelog() == namelogin)
							{
								cout << "----------------------" << endl;
								sd1.readutest(name, testyki[count].getnametesty());
								cout << "----------------------" << endl;
								return;
							}
						}

					}
				}
				else {
					cout << "Enter int!!!!!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
		}

	}

	int testnumbersq(string testname)
	{

		for (auto& sd1 : testyki)
		{
			if (sd1.getnametesty() == testname)
			{
				return sd1.retnum();
			}
		}
	}

};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Testyck {
	vector<section> section1;

public:
	void add(string name) {
		section sd(name);
		section1.push_back(sd);
	}
	void addnametest(string section22, string name)
	{
		for (auto& sd : section1)
		{
			if (sd.getname() == section22)
			{
				sd.add(name);
			}
		}

	}
	void addnametask(string test, string section22, string name)
	{
		for (auto& sd : section1)
		{
			if (sd.getname() == section22)
			{
				sd.task(test, name);
			}
		}
	}
	void read()
	{
		if (section1.empty())
		{
			cout << "pysto" << endl;
			return;
		}
		for (auto& sd : section1)
		{
			cout << "class:" << sd.getname() << endl;

			sd.readnametest();


		}
	}
	void clear1()
	{

		section1.clear();
	}
	void addansver(string ansver, string test, string section22, string key, string value)
	{
		for (auto& sd : section1)
		{
			if (sd.getname() == section22)
			{
				sd.addansver12(ansver, test, key, value);
			}
		}
	}
	bool checkdyblisection1(string newsec)
	{
		for (auto& sd : section1)
		{
			if (sd.getname() == newsec)
			{
				return false;
			}
			else
			{

			}
		}
		return true;
	}
	bool checkdyblitest(string name, string section)
	{
		int perevirka = 0;
		for (auto& sd : section1)
		{
			if (sd.getname() == section)
			{
				perevirka++;
			}
			else
			{

			}

		}
		if (perevirka == 0)
		{
			cout << "does not exist section" << endl;
			return false;
		}
		for (auto& sd : section1)
		{
			if (sd.getname() == section)
			{


				if (sd.checkdyblickatestname2(name))
				{

					return false;
				}


			}


		}
		cout << "dyblickat" << endl;
		return true;
	}
	bool  checkdyblitestTask(string section, string test, string task)
	{
		int perevirka = 0;
		int perevirka2 = 0;
		for (auto& sd : section1)
		{
			if (sd.getname() == section)
			{
				perevirka++;
			}
			else
			{

			}

		}
		if (perevirka == 0)
		{
			cout << "does not exist section" << endl;
			return false;
		}


		for (auto& sd : section1)
		{

			if (sd.checkdyblickatestname(test))
			{
				perevirka2++;
			}
			else
			{

			}

		}
		if (perevirka2 == 0)
		{
			cout << "does not exist test" << endl;
			return false;
		}


		for (auto& sd : section1)
		{
			if (sd.getname() == section)
			{


				if (sd.checknametask(test, task))
				{
					cout << "solo" << endl;
					return true;
				}
				else {
					cout << "dyblickat" << endl;
				}


			}


		}
		return false;
	}

	void correctanswerstest()
	{


		while (true) {
			while (true) {
				int count = 0;

				cout << "which section?\n if you want to exit, write 00." << endl;
				for (auto& sd : section1)
				{
					cout << ++count << sd.getname() << endl;
				}
				cout << "Enter num:";
				if (cin >> count)
				{

				}
				else
				{
					cout << "Enter int!!!!!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
				/*	try
					{
						int number = std::stoi(cs);

					}
					catch(const  invalid_argument&)
					{
						cout << "not int" << endl;
						break;
					}*/
				if (count == 00)
				{
					return;
				}
				if (count > section1.size())
				{
					cout << "num > size section" << endl;
					break;
				}
				if (count > section1.size())
				{
					cout << "num = 0" << endl;
					break;
				}
				if (count <= section1.size())
				{
					section1[count - 1].correctanswerstestick();
					return;
				}
			}

		}





	}
	void replacementvtesti()
	{
		cin.ignore();
		int num = 0;
		string namesection;
		for (auto& sd : section1)
		{
			cout << ++num << ":" << sd.getname() << endl;
		}
		cout << "enter name section which you want to change:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : section1)
		{
			if (sd.getname() == namesection)
			{
				sd.replacesectionname();
				return;
			}
		}
		cout << "eror section name" << endl;
		return;
	}
	void replaceetestnametest()
	{
		cin.ignore();
		int num = 0;
		string namesection;
		for (auto& sd : section1)
		{
			cout << ++num << ":" << sd.getname() << endl;
		}
		cout << "enter name section which you want to change:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : section1)
		{
			if (sd.getname() == namesection)
			{
				sd.replacetestnname();
				return;
			}
		}
		cout << "eror section name" << endl;
		return;
	}

	void replaceetestnametask()
	{
		cin.ignore();
		int num = 0;
		string namesection;
		for (auto& sd : section1)
		{
			cout << ++num << ":" << sd.getname() << endl;
		}
		cout << "enter name section which you want to change:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : section1)
		{
			if (sd.getname() == namesection)
			{
				sd.replacetestnnametask();
				return;
			}
		}
		cout << "eror section name" << endl;
		return;
	}
	void replaceetestnamevid()
	{
		cin.ignore();
		int num = 0;
		string namesection;
		for (auto& sd : section1)
		{
			cout << ++num << ":" << sd.getname() << endl;
		}
		cout << "enter name section which you want to change:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : section1)
		{
			if (sd.getname() == namesection)
			{
				sd.replaceetestnamevid();
				return;
			}
		}
		cout << "eror section name" << endl;
		return;

	}

	void daletesection()
	{
		cin.ignore();
		int num = 0;
		int coutnt = 0;
		int count = 0;
		string namesection;
		vector<section> temp;
		if (!section1.empty())
		{
			for (auto& sd : section1)
			{
				cout << ++num << ":" << sd.getname() << endl;
			}
		}
		else
		{
			cout << "empty" << endl;
			return;
		}
		cout << "enter name section which you want to dalate:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : section1)
		{


			if (sd.getname() == namesection)
			{


				for (int i = 0; i < section1.size(); i++)
				{

					if (i != coutnt)
					{
						temp.push_back(section1[i]);
					}



				}

				section1 = temp;
				temp.clear();
				return;

			}
			coutnt++;
		}
		cout << "eror section name" << endl;

	}
	void importtest()
	{
		ofstream testimpot("test.txt");
		for (auto& sd1 : section1)
		{
			testimpot << "section:" << sd1.getname() << endl;
			sd1.importtestname(testimpot);
		}
		cout << "everything is loaded" << endl;

	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////test

	void daletetest()
	{
		cin.ignore();
		int num = 0;
		int coutnt = 0;
		int count = 0;
		string namesection;
		vector<section> temp;
		if (!section1.empty())
		{
			for (auto& sd : section1)
			{
				cout << ++num << ":" << sd.getname() << endl;
			}
		}
		else
		{
			cout << "empty" << endl;
			return;
		}
		cout << "enter name section where do you want to delete the test?:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : section1)
		{
			if (sd.getname() == namesection)
			{
				sd.dalatetest2();
			}


		}
		cout << "eror section name" << endl;
	}

	void daletetask()
	{
		cin.ignore();
		int num = 0;
		int coutnt = 0;
		int count = 0;
		string namesection;
		vector<section> temp;
		if (!section1.empty())
		{
			for (auto& sd : section1)
			{
				cout << ++num << ":" << sd.getname() << endl;
			}
		}
		else
		{
			cout << "empty" << endl;
			return;
		}
		cout << "enter name section where do you want to delete the task?:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : section1)
		{
			if (sd.getname() == namesection)
			{
				sd.daletetask2();
				return;
			}


		}
		cout << "eror section name" << endl;
	}


	void daleteans()
	{
		cin.ignore();
		int num = 0;
		int coutnt = 0;
		int count = 0;
		string namesection;
		vector<section> temp;
		if (!section1.empty())
		{
			for (auto& sd : section1)
			{
				cout << ++num << ":" << sd.getname() << endl;
			}
		}
		else
		{
			cout << "empty" << endl;
			return;
		}
		cout << "enter name section where do you want to delete the ans?:";
		getline(cin, namesection);
		namesection = " " + namesection;
		for (auto& sd : section1)
		{
			if (sd.getname() == namesection)
			{
				sd.daleteans2();
				return;
			}


		}
		cout << "eror section name" << endl;
	}

	void taketest()
	{
		if (section1.empty())
		{
			cout << "partition is empty" << endl;
			return;
		}
		while (true)
		{
			while (true)
			{
				int count = 0;

				for (auto& sd1 : section1)
				{
					cout << ++count << ":" << "section:" << sd1.getname() << endl;
				}

				cout << "exit = -00 ";
				cout << "select the section of the test you want to take:";
				if (cin >> count)
				{
					if (count == -00)
					{
						cout << "exit" << endl;
						return;
					}
					count--;
					if (count < 0)
					{
						cout << "num < 0" << endl;

					}
					else if (count >= section1.size())
					{
						cout << "num > size " << endl;

					}
					else
					{


						section1[count].taketest();


					}
				}
				else {
					cout << "Enter int!!!!!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

		}

	}
	void checksecthion()
	{
		if (section1.empty())
		{
			cout << "secthion is empty" << endl;
			return;
		}

		while (true)
		{
			while (true)
			{
				int count = 0;

				for (auto& sd1 : section1)
				{
					cout << ++count << ":" << "section:" << sd1.getname() << endl;
				}

				cout << "exit = -00 ";
				cout << "select the section of the test you want to take:";
				if (cin >> count)
				{
					if (count == -00)
					{
						cout << "exit" << endl;
						return;
					}
					count--;
					if (count < 0)
					{
						cout << "num < 0" << endl;

					}
					else if (count >= section1.size())
					{
						cout << "num > size " << endl;

					}
					else
					{


						read1();
						for (auto& sd1 : usersmark)
						{

							if (sd1.getnamelog() == namelogin)
							{
								cout << "----------------------" << endl;
								sd1.pokasisection(section1[count].getname());
								cout << "----------------------" << endl;
								return;
							}
						}
						cout << "you have no results" << endl;


					}
				}
				else {
					cout << "Enter int!!!!!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

		}
	}



	void checktest()
	{
		if (section1.empty())
		{
			cout << "secthion is empty" << endl;
			return;
		}

		while (true)
		{
			while (true)
			{
				int count = 0;

				for (auto& sd1 : section1)
				{
					cout << ++count << ":" << "section:" << sd1.getname() << endl;
				}

				cout << "exit = -00 ";
				cout << "select the section of the test you want to take:";
				if (cin >> count)
				{
					if (count == -00)
					{
						cout << "exit" << endl;
						return;
					}
					count--;
					if (count < 0)
					{
						cout << "num < 0" << endl;

					}
					else if (count >= section1.size())
					{
						cout << "num > size " << endl;

					}
					else
					{


						read1();
						for (auto& sd1 : usersmark)
						{

							if (sd1.getnamelog() == namelogin)
							{

								section1[count].testuser(section1[count].getname());
								return;
							}
						}
						cout << "you have no results" << endl;


					}
				}
				else {
					cout << "Enter int!!!!!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}

		}
	}


	int getnumtestqvision(string nameclass, string test)
	{
		for (auto& sd1 : section1)
		{
			if (nameclass == sd1.getname())
			{
				return sd1.testnumbersq(test);
			}
		}
	}
	bool checkempty()
	{
		if (section1.empty())
		{
			return true;
		}
		return false;
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class User
{
	string Name;
	string Password;
	string Login;
public:
	User() :Name("no name"), Password("no password"), Login("No login") {}
	User(string n, string p, string l) :Name(n), Password(p), Login(l) {}
	string getName()
	{
		return Name;
	}
	string getPassword()
	{
		return Password;
	}
	string getLogin()
	{
		return Login;
	}
	void setname(string name1)
	{
		this->Name = name1;
	}
	void setPassword(string Password)
	{
		this->Password = Password;
	}
	void setLogin(string Login)
	{
		this->Login = Login;
	}

};
class Admin
{
	string Log;
	string Password;
public:
	Admin() :Log("NO"), Password("NO") {}
	Admin(string l, string pas) :Log(l), Password(pas) {}
	void setname(string  name)
	{
		this->Log = name;
	}
	void setpas(string  name)
	{
		this->Password = name;
	}
	string getname()
	{
		return Log;
	}
	string getpas()
	{
		return Password;
	}

};
class Testy
{
	vector <User> Users;
	Admin admin;
	Testyck test;

public:
	Testy()
	{
		Admin admin;
	};

	void start() {
		readfromthetestfile1();
		ifstream admin("admin.txt");
		string checklogadmin;
		admin >> checklogadmin;


		while (true) {
			int  exit = 0;
			int  exit2 = 0;
			int exitadminmenu = 0;;


			if (checklogadmin == "false" || checklogadmin == "")
			{
				while (checklogadmin != "true")
				{
					int choice = 0;

					cout << "1-log in as a user\n2-log in as a admin\n3-create a user account\n4-create a account admin\n5-exit:";
					cin >> choice;
					if (choice == 2)
					{
						cout << "there is no admin" << endl;
					}
					else if (choice == 4)
					{
						string newlogin;
						string newpassword;
						cin.ignore();
						cout << "Enter login:";
						getline(cin, newlogin);
						cout << "Enter newpassword:";
						getline(cin, newpassword);
						ofstream push("admin.txt");
						push << "true" << endl;
						push << "Name:" << " " << newlogin << endl;
						push << "Password: " << newpassword << endl;
						cout << "account created" << endl;
						checklogadmin = "true";

					}
					else if (choice == 3)
					{
						createuseracount();
					}

					else if (choice == 1) {

						if (checkenter())
						{
							cout << "esti" << endl;
							menuuser();
						}
						else
						{
							cout << "error name or password" << endl;
						}
					}


				}



			}
			if (checklogadmin == "true") {

				int choice;
				cout << "1-log in as a user\n2-log in as a admin\n3-create a user account\n4-exit:";
				cin >> choice;
				if (choice == 2)
				{
					while (true)
					{
						if (exitadminmenu > 0) {
							exitadminmenu--;
							break;
						}
						if (exit > 0) {
							exit--;
							break;
						}
						if (exit2 > 0) {
							exit2--;
							break;
						}
						cin.ignore();
						string login;
						cout << "Enter log:";
						getline(cin, login);


						if (checknameadmin(login)) {

							while (true) {
								if (exit2 > 0) {
									break;
								}

								string password;

								cout << "Enter password:";

								getline(cin, password);

								if (checkpasswordadmin(password))
								{
									cout << "good" << endl;
									menuadmin();
									exitadminmenu++;
									break;
								}
								else
								{

									string choice;
									cout << "password is not valid" << endl;
									cout << "do you want to repeat?yes/no:";
									getline(cin, choice);
									if (choice == "yes")
									{

									}
									else if (choice == "no")
									{
										exit2++;
										break;

									}
									else {


										string choicevnytr;
										while (choicevnytr != "no" || choicevnytr != "yes") {
											cout << "yes/no" << endl;
											cin >> choicevnytr;
											if (choicevnytr == "yes")
											{
												break;
											}
											else if (choicevnytr == "no")
											{
												exit2++;
												break;
											}
										}



									}


								}

							}
						}


						else {


							string choice;

							cout << " not found name" << endl;
							cout << "do you want to repeat?yes/no" << endl;
							cin >> choice;

							if (choice == "yes")
							{

							}
							else if (choice == "no")
							{

								break;

							}
							else {
								string choicevnytr;
								while (choicevnytr != "no" || choicevnytr != "yes") {
									cout << "yes/no" << endl;
									cin >> choicevnytr;
									if (choicevnytr == "yes")
									{
										break;
									}
									else if (choicevnytr == "no")
									{
										exit++;
										break;
									}
								}

							}


						}


					}




				}
				else if (choice == 4)
				{
					cout << "app close" << endl;
					return;
				}
				else if (choice == 3) {
					createuseracount();
				}
				else if (choice == 1) {


					if (checkenter())
					{
						cout << "esti" << endl;
						menuuser();
					}
					else
					{
						cout << "error name or password" << endl;
					}

				}
			}
		}
	}
	void menuadmin()
	{

		cout << "you admin" << endl;
		while (true) {
			int choice;
			cout << "1-o user management\n2-o viewing statistics\n3-o test management\n4-change password or name\n5-exit:";
			cin >> choice;
			switch (choice)
			{
			case 1:
				useusermanagement();
				break;
			case 2:
				viewingstatistics();
				break;
			case 3:
				testmanagement();
				break;
			case 4:
				changenameadminorpas();
				break;
			case 5:
				cout << "exit" << endl;
				return;
			default:
				break;
			}
		}
	}
	void changenameadminorpas()
	{

		while (true)
		{
			int sw = 0;
			cout << "1-name\n2-pas:\n3-exit" << endl;
			cin >> sw;
			if (sw == 1)
			{
				cin.ignore();
				string newname;
				cout << "enter new name:";
				getline(cin, newname);
				admin.setname(newname);
				ofstream push("admin.txt");
				push << "true" << endl;
				push << "Name:" << " " << newname << endl;
				push << "Password: " << admin.getpas() << endl;
				cout << "changed successfully" << endl;
			}
			else if (sw == 2)
			{
				cin.ignore();
				string newpas;
				cout << "enter new name:";
				getline(cin, newpas);
				admin.setpas(newpas);
				ofstream user("user.txt");
				ofstream push("admin.txt");
				push << "true" << endl;
				push << "Name:" << " " << admin.getname() << endl;
				push << "Password: " << newpas << endl;
				cout << "changed successfully" << endl;
			}
			else if (sw == 3)
			{
				cout << "exit change admin" << endl;
				return;
			}
			else
			{
				cout << "1,2,3" << endl;
			}
		}
	}
	void viewingstatistics()
	{
		while (true) {
			int choice = 0;
			cout << "1-viewing test results general\n2-by categories viewing test results \n3-by specific tests viewing test results\n4-specific users viewing test results\n5-exit:" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				read1();
				if (usersmark.empty())
				{
					cout << "empty" << endl;
					break;
				}
				cout << "-----------------------------------------------" << endl;

				for (auto& sd1 : usersmark)
				{

					sd1.readuseruser1();
				}
				cout << "-----------------------------------------------" << endl;
				break;
			case 2:
				categoriesviewintest();
				break;
			case 3:
				byspecifictestsviewingtestresults();
				break;
			case 4:
				specificusersviewingtestresults();
				break;
			case 5:
				cout << "exit viewing statistics" << endl;
				return;
				break;
			default:
				break;
			}
		}
	}
	void specificusersviewingtestresults()
	{
		read1();
		string nametest;
		if (usersmark.empty())
		{
			cout << "empty" << endl;
			return;
		}
		while (true)
		{
			while (true)
			{
				int count = 0;

				for (auto& sd1 : usersmark)
				{
					cout << ++count << ":" << sd1.getnamelog() << endl;
				}

				cout << "exit = -00 ";
				cout << "select the test  of the test you want to pass:";
				if (cin >> count)
				{
					if (count == -00)
					{
						cout << "exit" << endl;
						return;
					}
					count--;
					if (count < 0)
					{
						cout << "num < 0" << endl;

					}
					else if (count >= usersmark.size())
					{
						cout << "num > size " << endl;

					}
					else
					{
						usersmark[count].readuseruser();
					}
				}
				else {
					cout << "Enter int!!!!!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
		}

	}





	void byspecifictestsviewingtestresults()
	{
		cin.ignore();
		string namesq;
		cout << "enter test view:";
		getline(cin, namesq);
		read1();
		cout << "-----------------------------------------------" << endl;
		for (auto& sd1 : usersmark)
		{

			sd1.readgryptestichil(namesq);
		}
		if (perev > 0)
		{

		}
		else
		{
			cout << "nety" << endl;
			perev = 0;

		}
		cout << "-----------------------------------------------" << endl;
	}
	void categoriesviewintest()
	{
		cin.ignore();
		string namesq;
		cout << "enter categories view:";
		getline(cin, namesq);
		read1();
		cout << "-----------------------------------------------" << endl;
		for (auto& sd1 : usersmark)
		{

			sd1.readgryptestchil(namesq);
		}
		if (perev > 0)
		{

		}
		else
		{
			cout << "nety" << endl;
			perev = 0;
		}
		cout << "-----------------------------------------------" << endl;


	}
	void modificastionsd()
	{
		Loadvusers();
		if (Users.empty())
		{
			cout << "empty" << endl;
			return;
		}
		while (true) {
			while (true) {
				int count = 0;
				int count2 = 0;
				cout << "what do you want to change \n1-name\n2-login\n3-password\n4-all\n5-exit" << endl;
				if (cin >> count)
				{


					if (count == 1)
					{
						string newname;
						printfullusers1();
						cout << "-00:exit\nenter the account number of which you want to change the name:";
						if (cin >> count)
						{
							if (count == -00)
							{
								cout << "exit" << endl;
								return;
							}
							count--;
							if (count < 0)
							{
								cout << "num < 0" << endl;
								break;
							}
							else if (count > Users.size())
							{
								cout << "num > size " << endl;
								break;
							}
							else
							{
								cin.ignore();
								cout << "enter new name" << endl;
								getline(cin, newname);
								Users[count].setname(newname);
							}
						}
						else
						{
							cout << "Enter int!!!!!" << endl;
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							break;
						}

						cout << "changed successfully" << endl;
						pushfileuser();

					}


					else if (count == 2)
					{
						string newname;
						Loadvusers();
						for (auto& sd1 : Users)
						{
							cout << ++count2 << ":" << "Name:" << sd1.getName() << " " << "Log:" << sd1.getLogin() << endl;
						}
						cout << "-00:exit\nenter the account number of which you want to change the log:";
						if (cin >> count)
						{
							if (count == -00)
							{
								cout << "exit" << endl;
								return;
							}
							count--;
							if (count < 0)
							{
								cout << "num < 0" << endl;
								break;
							}
							else if (count > Users.size())
							{
								cout << "num > size " << endl;
								break;
							}
							else
							{

								cin.ignore();
								cout << "enter new log" << endl;
								getline(cin, newname);
								if (Users[count].getLogin() == newname)
								{
									cout << "this log" << endl;
									break;
								}
								if (checkdyblicat(newname))
								{
									string thisname = Users[count].getLogin();
									setlofnameusermarks(thisname, newname);
									Users[count].setLogin(newname);
								}
								else
								{
									cout << "this log already exists" << endl;
									break;
								}

							}
						}
						else
						{
							cout << "Enter int!!!!!" << endl;
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							break;
						}

						cout << "changed successfully" << endl;
						pushfileuser();
					}
					else if (count == 3)
					{
						string newname;
						Loadvusers();
						for (auto& sd1 : Users)
						{
							cout << ++count2 << ":" << "Name:" << sd1.getName() << " " << "Log:" << sd1.getLogin() << " " << "Pas:" << sd1.getPassword() << endl;
						}
						cout << "-00:exit\nenter the account number of which you want to change the pass:";
						if (cin >> count)
						{
							if (count == -00)
							{
								cout << "exit" << endl;
								return;
							}
							count--;
							if (count < 0)
							{
								cout << "num < 0" << endl;
								break;
							}
							else if (count > Users.size())
							{
								cout << "num > size " << endl;
								break;
							}
							else
							{
								cin.ignore();
								cout << "enter new Password" << endl;
								getline(cin, newname);
								Users[count].setPassword(newname);
							}
						}
						else
						{
							cout << "Enter int!!!!!" << endl;
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							break;
						}

						cout << "changed successfully" << endl;
						pushfileuser();
					}
					else if (count == 4)
					{
						string newname;
						string newlogin;
						string newpassword;
						Loadvusers();
						for (auto& sd1 : Users)
						{
							cout << ++count2 << ":" << "Name:" << sd1.getName() << " " << "Log:" << sd1.getLogin() << " " << "Pas:" << sd1.getPassword() << endl;
						}
						cout << "-00:exit\nenter the account number of which you want to change the pass:";
						if (cin >> count)
						{
							if (count == -00)
							{
								cout << "exit" << endl;
								break;
							}
							count--;
							if (count < 0)
							{
								cout << "num < 0" << endl;
								break;
							}
							else if (count > Users.size())
							{
								cout << "num > size " << endl;
								break;
							}
							else
							{
								cin.ignore();
								cout << "enter new name:";
								getline(cin, newname);
								cout << "enter new log";
								getline(cin, newlogin);
								if (Users[count].getLogin() == newlogin)
								{
									cout << "this log" << endl;
									break;
								}
								if (checkdyblicat(newlogin))
								{
									Users[count].setLogin(newlogin);
								}
								else
								{
									cout << "this log already exists" << endl;
									break;
								}
								cout << "enter new Password";
								getline(cin, newpassword);
								Users[count].setname(newname);
								Users[count].setPassword(newpassword);
							}
						}
						else
						{
							cout << "Enter int!!!!!" << endl;
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							break;
						}

						cout << "changed successfully" << endl;
						pushfileuser();
					}

					else if (count == 5)
					{
						cout << "exit" << endl;
						return;
					}
					else
					{
						cout << "chilim" << endl;
						break;
					}

				}
				else
				{
					cout << "Enter int!!!!!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
		}

	}

	void useusermanagement()
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		while (true)
		{
			int choicee;
			cout << "1-creation\n2-deletion\n3-modification of users\n4-All user\n5-exit:";
			if (cin >> choicee)
			{
				switch (choicee)
				{
				case 1:
					createuseracount();
					cout << "ac create" << endl;

					break;
				case 2:
					dalateuseradmin();
					break;
				case 3:
					modificastionsd();
					break;
				case 4:
					printfullusers();
					break;
				case 5:
					cout << "exit user managment" << endl;
					return;
				default:
					break;
				}
			}
			else
			{
				cout << "Enter int!!!!!" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}
		}


	}
	void printfullusers()
	{
		Loadvusers();
		if (Users.empty())
		{
			cout << "empty" << endl;
			return;
		}
		int count = 0;
		cout << "-----------------------------" << endl;
		for (auto& sd1 : Users)
		{
			cout << ++count << ":" << "Name:" << sd1.getName() << endl;

		}
		cout << "-----------------------------" << endl;

	}
	void printfullusers1()
	{
		Loadvusers();
		if (Users.empty())
		{

			return;
		}
		int count = 0;
		cout << "-----------------------------" << endl;
		for (auto& sd1 : Users)
		{
			cout << ++count << ":" << "Name:" << sd1.getName() << endl;

		}
		cout << "-----------------------------" << endl;

	}
	void pushfileuser()
	{
		ofstream user("user.txt");
		for (auto& gr : Users) {
			/*	user << gr.getLogin() << " " << gr.getName() << " " << gr.getPassword() << endl;*/
			user << gr.getLogin() << endl;
			user << gr.getName() << endl;
			user << gr.getPassword() << endl;
		}
	}
	void dalateuseradmin()
	{


		while (true) {
			while (true)
			{
				int count = 0;
				Loadvusers();
				printfullusers1();
				if (Users.empty())
				{
					cout << "empty" << endl;
					return;
				}
				cout << "exit-00\nenter number user:";
				if (cin >> count)
				{

					if (count == -00)
					{
						cout << "exit" << endl;
						return;
					}
					count--;
					if (count < 0)
					{
						cout << "num < 0" << endl;
						break;
					}
					else if (count > Users.size())
					{
						cout << "num > size " << endl;
						break;
					}
					else
					{
						vector<User> temp;
						for (int i = 0; i < Users.size(); i++)
						{
							if (i == count)
							{

							}
							else
							{
								temp.push_back(Users[i]);
							}
						}
						string name23 = Users[count].getLogin();
						Users = temp;
						temp.clear();
						pushfileuser();
						dalateusmarks(name23);
						cout << name23 << endl;
						cout << "this user has been deleted" << endl;
					}
				}
				else
				{
					cout << "Enter int!!!!!" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
		}

	}
	void dalaletetest()
	{
		int num = 0;
		while (true)
		{
			cout << "where you want to change your name?\n1-section\n2-test\n3-task\n4-answers\n5-all\n6-exit:";
			cin >> num;
			switch (num)
			{
			case 1:
				test.daletesection();
				break;
			case 2:
				test.daletetest();
				break;
			case 3:
				test.daletetask();
				break;
			case 4:
				test.daleteans();
				break;
			case 5:
				if (test.checkempty())
				{
					cout << "empty" << endl;
					return;
				}
				test.clear1();
				cout << "all clear" << endl;
				break;
			case 6:
				cout << "exit replacement" << endl;
				return;
			default:
				break;
			}
		}
	}
	void importintofile() {
		test.importtest();
	}
	void testmanagement()
	{
		cout << "test management" << endl;
		while (true) {
			int choice;
			cout << "1-add\n2-replacement\n3-put correct and incorrect answers\n4-import into the file\n5-dalete\n7-see all tests with questions in full\n8-exit:";
			cin >> choice;
			switch (choice)
			{
			case 1:
				addmanage();
				break;
			case 2:
				if (test.checkempty())
				{
					cout << "empty" << endl;
					break;
				}
				replacement();
				break;
			case 3:
				if (test.checkempty())
				{
					cout << "empty" << endl;
					break;
				}
				correctanswers();
				break;
			case 4:
				importintofile();
				break;
			case 5:
				if (test.checkempty())
				{
					cout << "empty" << endl;
					break;
				}
				dalaletetest();
				break;
			case 7:
				if (test.checkempty())
				{
					cout << "empty" << endl;
					break;
				}
				test.read();
				break;
			case 8:
				cout << "exit" << endl;
				cout << "test management" << endl;
				return;
			default:
				cout << "noy" << endl;
				break;
			}
		}
	}

	void correctanswers()
	{
		if (test.checkempty())
		{
			cout << "empty" << endl;
			return;
		}
		test.correctanswerstest();
		test.importtest();
	}
	void replacement()
	{
		int num = 0;
		while (true)
		{
			cout << "where you want to change your name?\n1-section\n2-test\n3-task\n4-answers\n5-exit:";
			cin >> num;
			switch (num)
			{
			case 1:
				test.replacementvtesti();
				test.importtest();
				break;
			case 2:
				test.replaceetestnametest();
				test.importtest();
				break;
			case 3:
				test.replaceetestnametask();
				test.importtest();
				break;
			case 4:
				test.replaceetestnamevid();
				test.importtest();
				break;
			case 5:
				cout << "exit replacement" << endl;
				return;
			default:
				break;
			}
		}
	}
	void addmanage()
	{
		while (true) {
			int choice;
			cout << "what can you add" << endl;
			cout << "1-section\n2-test\n3-task\n4-exit:";
			cin >> choice;
			switch (choice)
			{
			case 1:
				addsection();

				break;
			case 2:
				addtest();

				break;
			case 3:
				addtask();

				break;
			case 4:
				cout << "exit" << endl;
				cout << "add management" << endl;
				return;
			default:
				cout << "noy" << endl;
				break;
			}
		}
	}
	void addtest()
	{

		string nametest;
		string namesection;
		while (true)
		{
			cin.ignore();
			cout << "enter section:";
			getline(cin, namesection);
			cin.ignore();
			namesection = " " + namesection;
			cout << "enter new test:";
			getline(cin, nametest);
			nametest = " " + nametest;
			cin.ignore();
			if (!test.checkdyblitest(nametest, namesection))
			{

				cout << "add test" << endl;
				test.addnametest(namesection, nametest);
				test.importtest();
				return;
			}
			else
			{
				string vibor;
				cin.ignore();
				cout << "continue?yes/no:";
				cin >> vibor;
				cin.ignore();
				if (vibor == "yes")
				{
					return;
				}
				else if (vibor == "no")
				{
					break;
				}
				else
				{
					cout << "I think you want to go out)" << endl;
					return;
				}
			}
		}
	}
	void addsection()
	{
		string newsection;
		while (true)
		{
			cin.ignore();
			cout << "enter new section:";
			getline(cin, newsection);
			newsection = " " + newsection;
			if (test.checkdyblisection1(newsection))
			{
				cout << "add chil" << endl;
				test.add(newsection);
				test.importtest();
				return;
			}
			else
			{
				string vibor;
				cout << "dyblicat" << endl;
				cout << "continue?yes/no:";
				cin >> vibor;
				if (vibor == "yes")
				{
					return;
				}
				else if (vibor == "no")
				{
					break;
				}
				else
				{
					cout << "I think you want to go out)" << endl;
					return;
				}
			}
		}
	}
	void addtask()
	{
		string section;
		string test1;
		string newtask;
		while (true)
		{
			cin.ignore();
			cout << "enter section:";
			getline(cin, section);
			section = " " + section;
			cin.ignore();
			cout << "enter test:";
			getline(cin, test1);
			test1 = " " + test1;
			cin.ignore();
			cout << "enter task name:";
			getline(cin, newtask);
			newtask = " " + newtask;

			if (test.checkdyblitestTask(section, test1, newtask))
			{
				cout << "add task" << endl;
				test.addnametask(test1, section, newtask);
				cout << "enter question" << endl;
				Enterquestion(section, test1, newtask);
				test.importtest();
				return;
			}
			else
			{
				string vibor;
				cin.ignore();
				cout << "dyblicat" << endl;
				cout << "continue?yes/no:";
				cin >> vibor;
				cin.ignore();
				if (vibor == "yes")
				{
					return;
				}
				else if (vibor == "no")
				{
					break;
				}
				else
				{
					cout << "I think you want to go out)" << endl;
					return;
				}
			}
		}
	}
	void Enterquestion(string section, string test1, string  task)
	{
		int count = 0;
		string pyt;
		int vid;
		while (true) {
			cout << "how many answers should there be?:" << endl;
			cin >> count;
			if (count > 4)
			{
				cout << "max:4" << endl;
				break;
			}
			if (2 > count)
			{
				cout << "min:2" << endl;
				break;
			}
			for (int i = 0; i < count; i++)
			{
				cout << "Enter pyt:";
				cin.ignore();
				getline(cin, pyt);
				cout << "1-true\n2-false:";
				cin >> vid;
				if (vid == 1)
				{
					test.addansver(task, test1, section, pyt, "true");
				}
				else if (vid == 2)
				{
					test.addansver(task, test1, section, pyt, "false");
				}
				else
				{
					cout << "no matter what you choose, it will be random:";
					cin >> vid;
					if (vid == 1)
					{
						test.addansver(task, test1, section, pyt, "true");
					}
					else if (vid == 2)
					{
						test.addansver(task, test1, section, pyt, "false");
					}
					else
					{
						srand(time(nullptr));
						vid = rand() % 2 + 1;
						if (vid == 1)
						{
							test.addansver(task, test1, section, pyt, "true");
						}
						else if (vid == 2)
						{
							test.addansver(task, test1, section, pyt, "false");
						}
					}
				}
			}
			return;
		}

	}
	void menuuser()
	{
		while (true) {
			int choice;
			cout << "1-view your previous test results\n2-take a new test\n3-change name or password\n4-exit";
			cin >> choice;
			switch (choice)
			{
			case 1:
				viewtest();
				break;
			case 2:

				takenewtest();
				break;
			case 3:
				changenameuser();
				break;
			case 4:
				cout << "exit" << endl;
				return;
			default:
				break;
			}
		}

	}
	void setf()
	{
		ofstream user("user.txt");
		for (auto& gr : Users) {
			/*	user << gr.getLogin() << " " << gr.getName() << " " << gr.getPassword() << endl;*/
			user << gr.getLogin() << endl;
			user << gr.getName() << endl;
			user << gr.getPassword() << endl;
		}
	}
	void changenameuser()
	{
		Loadvusers();

		cin.ignore();
		string name;
		while (true)
		{
			int i = 0;
			int count = 0;
			cout << "1-name\n2-pasword\n3-exit:";
			cin >> count;
			switch (count)
			{
			case 1:

				cin.ignore();
				cout << "new name:";
				getline(cin, name);
				for (auto& sd1 : Users)
				{

					if (sd1.getLogin() == namelogin)
					{
						Users[i].setname(name);
						cout << "chilim" << endl;

					}
					i++;
				}
				setf();
				break;

			case 2:
				cin.ignore();
				cout << "new pas:";
				getline(cin, name);
				for (auto& sd1 : Users)
				{

					if (sd1.getLogin() == namelogin)
					{
						Users[i].setPassword(name);
						cout << "chilim" << endl;

					}
					i++;
				}

				setf();
				break;

			case 3:
				cout << "exit chance" << endl;
				return;

			default:
				break;
			}


		}


	}
	void allcout()
	{
		read1();
		if (usersmark.empty())
		{
			cout << "empty" << endl;
			return;
		}
		for (auto& sd1 : usersmark)
		{
			if (sd1.getnamelog() == namelogin)
			{
				cout << "----------------------" << endl;
				sd1.readuseruser1();
				cout << "----------------------" << endl;
				return;
			}
		}
		cout << "you have no results" << endl;

	}
	void sectioncout()
	{
		test.checksecthion();
	}
	void testcout()
	{
		test.checktest();
	}
	void viewtest()
	{
		while (true)
		{
			int ch = 0;
			cout << "1-see the results of the entire section\n2-see the results of the entire test\n3-All\n4-exit:";
			cin >> ch;
			switch (ch)
			{
			case 1:
				sectioncout();
				break;
			case 2:
				testcout();
				break;
			case 3:
				allcout();
				break;
			case 4:
				return;
			default:
				break;
			}
		}

	}
	void takenewtest()
	{

		test.taketest();

	}
	bool checknameadmin(string checkname)
	{
		ifstream admin("admin.txt");
		string checklog;

		while (admin >> checklog)
		{
			if (checklog == "Name:")
			{
				admin.ignore();
				getline(admin, checklog);


				if (checklog == "Password:")
				{

				}
				if (checklog == checkname)
				{
					cout << "well" << endl;
					return true;
				}
				else
				{
					return false;
				}

			}
		}
		return false;

	}
	void doanewtest() {
		readfromthetestfile();
		retrunfulltest();
		cout << "_________" << endl;
	}
	void readfromthetestfile()
	{
		test.clear1();
		string slov;
		string sectionname;
		string taskname;
		string testname;
		ifstream testick("test.txt");
		int exitsectio = 0;
		int testexit = 0;
		testick >> slov;
		if (slov == "")
		{
			cout << "nemaye testiv" << endl;
			return;
		}
		testick.close();
		ifstream testick1("test.txt");
		while (testick1 >> slov)
		{
			if (exitsectio > 0)
			{

				exitsectio--;
			}
			if (slov == "section:") {
				getline(testick1, slov);
				sectionname = slov;
				readingsectio();
				readingtest();
				while (testick1 >> slov)
				{
					if (exitsectio > 0)
					{

						return;
					}
					if (testexit > 0)
					{
						testexit--;

					}
					if (slov == "test:")
					{

						getline(testick1, slov);
						testname = slov;

						while (true)
						{
							if (exitsectio > 0)
							{

								return;
							}
							if (testexit > 0)
							{

								return;
							}





							while (testick1 >> slov)
							{
								int sd = 0;
								if (slov == "task:")
								{
									if (exitsectio > 0)
									{

										return;
									}
									if (testexit > 0)
									{

										return;
									}

									getline(testick1, slov);
									string taskname;
									taskname = slov;
									test.addnametask(testname, sectionname, slov);
									string ans;
									string dd;

									while (testick1 >> slov)
									{


										if (slov == "task:" || dd == "task:")
										{
											readinganswer(testick1, testname, sectionname);
											/*readansvervtest(taskname, sectionname, testname);*/
											readansver();

											return;
										}

										if (slov == "section:")
										{

										}
										if (slov == "test:")
										{

										}
									}
								}
							}

						}

					}

				}

			}

		}
		testick1.close();
	}


	void readfromthetestfile1()
	{
		test.clear1();
		string slov;
		string sectionname;
		string taskname;
		string testname;
		ifstream testick("test.txt");
		int exitsectio = 0;
		int testexit = 0;
		testick >> slov;

		testick.close();
		ifstream testick1("test.txt");
		while (testick1 >> slov)
		{
			if (exitsectio > 0)
			{

				exitsectio--;
			}
			if (slov == "section:") {
				getline(testick1, slov);
				sectionname = slov;
				readingsectio();
				readingtest();
				while (testick1 >> slov)
				{
					if (exitsectio > 0)
					{

						break;
					}
					if (testexit > 0)
					{
						testexit--;

					}
					if (slov == "test:")
					{

						getline(testick1, slov);
						testname = slov;

						while (true)
						{
							if (exitsectio > 0)
							{

								break;
							}
							if (testexit > 0)
							{

								return;
							}


							if (testick1.eof()) return;


							while (testick1 >> slov)
							{
								int sd = 0;
								if (slov == "task:")
								{
									if (exitsectio > 0)
									{

										break;
									}
									if (testexit > 0)
									{

										return;
									}

									getline(testick1, slov);
									string taskname;
									taskname = slov;
									test.addnametask(testname, sectionname, slov);
									readansver();

									string ans;
									string dd;
									ifstream file2("test.txt");
									streampos pos = testick1.tellg();
									file2.seekg(pos);
									while (testick1 >> slov)
									{



										/*readansvervtest(taskname, sectionname, testname);*/

										//cout << "pityshnia " << test.getnumtestqvision(sectionname, testname) << endl;
										//if (test.getnumtestqvision(sectionname, testname)  <= 1)
										//{
										//	readinganswer(testick1, testname, sectionname);
										//	/*readansvervtest(taskname, sectionname, testname);*/
										//	readansver();

										//	return;
										//}

										if (slov == "task:" || dd == "task:")
										{
											readinganswer(testick1, testname, sectionname);
											/*readansvervtest(taskname, sectionname, testname);*/
											readansver();

											return;
										}

										if (slov == "section:")
										{
											file2 >> slov;
											readinganswer(file2, testname, sectionname);
											/*readansvervtest(taskname, sectionname, testname);*/
											readansver();

											return;
										}
										if (slov == "test:")
										{
											file2 >> slov;
											readinganswer(file2, testname, sectionname);
											/*readansvervtest(taskname, sectionname, testname);*/
											readansver();

											return;
										}

									}
								}
							}

						}

					}

				}

			}

		}
		testick1.close();
	}







	/////////////////////////////////////
	void readingsectio()
	{
		ifstream filename1("test.txt");
		string sectionnnam;
		string slov;
		filename1 >> slov;
		getline(filename1, sectionnnam);
		test.add(sectionnnam);
		while (filename1 >> slov)
		{
			if (slov == "section:")
			{
				readsectoifile(filename1);
			}
		}
		filename1.close();

	}
	void readsectoifile(ifstream& filename)
	{
		string sectionnnam;
		string slov;

		getline(filename, sectionnnam);

		test.add(sectionnnam);
		while (filename >> slov)
		{
			if (slov == "section:")
			{

				readsectoifile(filename);
			}
		}
		filename.close();
	}


	/// //////////////////////////////////////////////////////////////

	void readingtest()
	{
		ifstream filename1("test.txt");
		string sectionnnam;
		string slov;
		string section;

		filename1 >> section;
		getline(filename1, section);
		while (filename1 >> slov)
		{
			if (slov == "test:")
			{
				readtestfile(filename1, section);
			}
		}
		filename1.close();
	}

	void readtestfile(ifstream& filename, string name)
	{
		string sectionnnam;
		string slov;

		getline(filename, sectionnnam);

		test.addnametest(name, sectionnnam);
		while (filename >> slov)
		{
			if (slov == "section:")
			{
				getline(filename, name);
			}
			if (slov == "test:")
			{

				readtestfile(filename, name);
			}
		}
		filename.close();
	}

	/////////////////////////////////////////////////////////////////////////////////////////
	void readinganswer(ifstream& filename, string testname, string  sectionname)
	{
		string sectionnnam;
		string slov;
		getline(filename, sectionnnam);
		test.addnametask(testname, sectionname, sectionnnam);
		while (filename >> slov)
		{

			if (slov == "section:")
			{
				getline(filename, sectionname);
			}

			if (slov == "test:")
			{
				getline(filename, testname);
			}
			if (slov == "task:")
			{
				readinganswer(filename, testname, sectionname);
			}
		}
		filename.close();
	}
	void readansver()
	{
		ifstream read("test.txt");
		string slovo;
		string section1;
		string test1;
		string task1;
		string pyt;
		string vid;

		while (read >> slovo)
		{
			if (slovo == "section:")
			{
				section1 = section(read);
			}
			if (slovo == "test:")
			{
				test1 = test2(read);
			}
			if (slovo == "task:")
			{
				task1 = task(read);
				while (read >> pyt)
				{


					if (pyt == "section:" || vid == "section:")
					{
						section1 = section(read);
						break;
					}
					if (pyt == "test:" || vid == "test:")
					{
						test1 = test2(read);
						break;
					}

					if (pyt == "task:" || vid == "task:")
					{
						task1 = task(read);
						continue;
					}
					read >> vid;

					test.addansver(task1, test1, section1, pyt, vid);
				}
			}


		}
	}
	string section(ifstream& filename)
	{
		string sd;
		getline(filename, sd);
		return sd;

	}
	string test2(ifstream& filename)
	{
		string sd;
		getline(filename, sd);
		return sd;

	}
	string task(ifstream& filename)
	{
		string sd;
		getline(filename, sd);
		return sd;

	}
	//void readansvervtest(string taskname,string sectioname,string testname){
	//	ifstream readvid("test.txt");
	//	string vid;
	//	string ans;
	//	string slovo;
	//	string nametak;
	//	cout << "taskname:" <<taskname<< endl;
	//	while(readvid >> slovo)
	//	{

	//		if (slovo == "task:")
	//		{
	//			getline(readvid, slovo);
	//			if (slovo == taskname)
	//			{
	//				while (true)
	//				{
	//					if (ans == "section:" || slovo == "section:")
	//					{
	//						getline(readvid, sectioname);
	//						readansvervtest(ans, sectioname, testname);
	//						return;
	//					}
	//					if (ans == "test:" || slovo == "test:")
	//					{
	//						getline(readvid, testname);
	//						readansvervtest(ans, sectioname, testname);
	//						return;

	//					}
	//					cout << "slovo: " << slovo << endl;
	//					readvid >> slovo;
	//					if (ans == "task:" || slovo == "task:")
	//					{
	//						
	//						getline(readvid, ans);
	//						cout <<"chyna:"<< ans << endl;
	//						cout << "-------------------------------" << endl;
	//						readansvervtest(ans, sectioname, testname);
	//						return;
	//					}
	//					readvid >> ans;
	//					cout << "ans:" << ans << endl;
	//					test.addansver(taskname, testname, sectioname, slovo, ans);
	//				}
	//			}
	//			else
	//			{
	//				
	//			}
	//		
	//			
	//		}
	//	}
	//	readvid.close();
	//}
	void retrunfulltest()
	{
		test.read();
	}
	bool checkpasswordadmin(string password)
	{
		ifstream admin("admin.txt");
		string checklog;

		while (admin >> checklog)
		{

			if (checklog == "Password:")
			{
				admin.ignore();
				getline(admin, checklog);

				if (checklog == password)
				{
					return true;
				}
				else
				{
					return false;
				}

			}
		}
		return false;

	}


	void createuseracount()
	{
		while (true)
		{
			string name;
			string login;
			string password;
			cin.ignore();
			cout << "login:";
			getline(cin, login);
			if (!checkdyblicat(login))
			{
				cout << "login dyblicat" << endl;

				createuseracount();

				return;
			}
			cout << "name:";
			getline(cin, name);
			cout << "password:";
			getline(cin, password);
			User use(name, password, login);
			Loadvusers();
			Users.push_back(use);
			ofstream user("user.txt");
			for (auto& gr : Users) {
				/*	user << gr.getLogin() << " " << gr.getName() << " " << gr.getPassword() << endl;*/
				user << gr.getLogin() << endl;
				user << gr.getName() << endl;
				user << gr.getPassword() << endl;
			}
			cout << "create" << endl;
			return;
		}
	}
	bool checkdyblicat(string login)
	{
		Loadvusers();
		for (auto& gr : Users) {
			if (gr.getLogin() == login)
			{
				return false;
			}
		}
		return true;

	}
	void Loadvusers() {
		Users.clear();
		string name, login, password;
		ifstream user("user.txt");
		while (getline(user, login)) {

			getline(user, name);

			getline(user, password);

			User use(name, password, login);
			Users.push_back(use);
		}
	}

	bool checkenter()
	{
		cin.ignore();
		string log, password;
		string loganalog, passwordanalog;
		cout << "Enter login:";
		getline(cin, log);
		cout << "Enter password:";
		getline(cin, password);
		Loadvusers();
		for (auto& gr : Users) {
			loganalog = gr.getLogin();
			passwordanalog = gr.getPassword();
			if (loganalog == log)
			{
				if (passwordanalog == password)
				{
					namelogin = log;
					return true;
				}

			}
			if (loganalog == log && passwordanalog != password)
			{
				string choice;
				cout << "password eror:" << endl;
				cout << "wish to continue?yes/no?:";
				cin >> choice;
				if (choice == "yes")
				{
					while (true)
					{
						string pas;
						cin.ignore();
						cout << "pas:";
						getline(cin, pas);
						if (gr.getLogin() == log && gr.getPassword() == pas)
						{
							return true;
						}
						else
						{
							string choice;
							cout << "noy" << endl;
							cout << "continue?yes/no" << endl;
							getline(cin, choice);

							if (choice == "yes") {


							}
							else if (choice == "no")
							{
								return false;
							}
							else {
								cout << "yes/no" << endl;

							}
						}
					}
				}
				else if (choice == "no")
				{

				}


			}
		}
		return false;
	}
};


int main()
{
	Testy prog;
	prog.start();


}

