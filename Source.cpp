#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>


int globalpatientnumb = 0; // to follow all the patients's number

using namespace std;

class human {
	string name;
	int age;
	bool x; //if it's a disabled one, program will get it as a priority
public:

	human();
	human(string name, int age, bool x);
	string callname();
	
};

//consturcters

human::human() {
	// empty consturcter
}


human::human(string name, int age, bool x){ 
	this->name = name;
	this->age = age;
	this->x = x;
}

string human::callname() {
	return name;
}

class patient : public human {
	double patientno;
	int priorityorder;
	int* destructor;

public:

	patient();
	patient(string name, int age, bool x, double patientno, int priorityorder = 0) : human(name, age = 0, x = false)
	{
		this->patientno = patientno; // this operator ->
		this->priorityorder = priorityorder;
		destructor = new int;
	};


	// destructing but when we ask for.

	void destruct() {
		cout << "The patient '" << callname() << "' with ID number of " << patientno << " has been treated." << endl << endl;
		delete destructor;
	} 
};

patient::patient() {

	destructor = new int;
	patientno = 0;
	priorityorder = 0;
}



patient globalpatient[45]; // global patient list to get them in queue almost 45 people can be assigned

queue <patient> normalpeople;
queue <patient> disabledpeople; // establishin queue classes

void patientorder() {
	string name;
	int b;
	int age;
	double id;
	bool x;

	cout << "Welcome, please enter your name: ";

	cin >> ws; // quarantee for usage of getline

	getline(cin, name);
	cout << "Your age? ";
	cin >> age;
	cout << "Please write your ID numb: ";
	cin >> id;
	cout << "Are you officially disabled? 1)Yes 2)No: " ;
	cin >> b;
	if (b == 1) { x = 1; }
	else if (b == 2) { x = 0; }
	else { cout << "Sorry,we can't help you. Returning main page. " << endl << endl; return; }

	cout << "Your queue is being constructed." << endl << endl;



	patient copy(name, age, x, id, globalpatientnumb);
	globalpatient[globalpatientnumb] = copy;

	if (x == 1) disabledpeople.push(globalpatient[globalpatientnumb]); //loading into queue
	else  normalpeople.push(globalpatient[globalpatientnumb]);
	globalpatientnumb++;

	return;
	// the patient adding function has been constructed lets get into treating function by the queue
}


void treat() {
	
	if (normalpeople.empty() && disabledpeople.empty()) {
		cout << "There is no patient in any queue." << endl << endl;
		return;
	}

	else if (!(disabledpeople.empty())) {
		disabledpeople.front().destruct();
		disabledpeople.pop();
		return;
	}

	else if (!(normalpeople.empty())) {
		normalpeople.front().destruct();
		normalpeople.pop();
		return;
		//the first one has been destructed by using .front() operator. normalpeople.front().destruct(); is enough.
	}


}



void showqueue() {
	if (normalpeople.empty() && disabledpeople.empty()) {
		cout << "There is no patient in any queue." << endl << endl;
		return;
	}

	else if (!(disabledpeople.empty())) {
		cout << "PRIORITY PATIENTS IN QUEUE " << disabledpeople.size() << endl << endl;
		return;
	}

	else if (!(normalpeople.empty())) {
		cout << "PATIENTS IN QUEUE " << normalpeople.size() << endl << endl;
		return;
	}
	else cout << "ERROR" << endl << endl;
	return;
}





int main() {

	int q = 0;
	cout << "WELCOME TO OKAMAN HISPITAL" << endl << endl; 

	do {
		cout << "What would you like to do?" << endl << "1)Patient Registration" << endl 
			<< "2)Treatment Update" << endl << "3)Queue Query " << endl;

		cin >> q;
		cout << endl; 
		switch (q)
		{
		
		case 1:
			patientorder();
			continue;
		case 2:
			treat();
			continue;
		case 3:

			showqueue();
			continue;
		default:

			cout << " Pleaase enter a valid value" << endl;

		}


	} while (q != 9);
	

	return 1;
	
	// Thanks for reading, OKAMANOSM
}