#pragma once
class Person
{
private:
	string _name;
public:
	Person() = default;
	Person(const string name) { setName(name); }
	//setter and getter
	void setName(const string name)
	{
		try
		{
			if (name.size() > 0) {
				_name = name;
			}
			else { throw exception("name yanlisdir"); }
		}
		catch (const exception& ex)
		{
			cout << ex.what();
		}
	}

	string getName()const {
		return _name;
	}


	friend ostream& operator<<(ostream& print, const Person& other) {
		cout << other._name << endl;
		return print;
	}
};

class User;

vector<User*> users;
class User :public Person
{
	string _username;
	string _password;
public:

	User() = default;
	User(string name, string username, string password) {
		setName(name);
		_username = username;
		_password = password;
	}


	// Acsessors

	// Setters

	void setUsername(string username) { _username = username; }
	void setPassword(string password) { _password = password; }

	// Getters

	string getUsername() { return _username; }
	string getPassword() { return _password; }

	// Functions

	void writeFile() {
		try {

			ofstream file("RegisterLogin/users.txt", ios::app);
			if (!file) throw exception("File couldnt be opened\n");
			if (!file.is_open()) throw exception("File couldnt be opened\n");

			file << _username << '-' << _password << '-' << this->getName() << '-' << endl;
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}

	void readFile() {
		try {

			ifstream file("RegisterLogin/users.txt", ios::in);
			if (!file) throw exception("File couldnt be opened\n");
			if (!file.is_open()) throw exception("File couldnt be opened\n");

			string name, username, password, s;

			while (!file.eof()) {
				getline(file, username, '-');
				getline(file, password, '-');
				getline(file, name, '-');
				getline(file, s, '\n');
				User* newuser = new User(name, username, password);
				users.push_back(newuser);
			}
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}

	// Operator Overloading

	friend ostream& operator<<(ostream& print, const User& other) {
		cout << Person(other);
		cout << other._username << endl
			<< other._password << endl;

		return print;
	}

	bool operator==(const User& u1) {
		return (_username == u1._username && _password == u1._password);
	}
};


class Admin;

vector<Admin*> admins;

class Admin : private Person {
	string _adminname;
	string _password;
public:

	Admin() = default;
	Admin(string name, string adminname, string password) {
		setName(name);
		_adminname = adminname;
		_password = password;
	}


	// Acsessors

	// Setters

	void setAdminName(string adminame) { _adminname = adminame; }
	void setPassword(string password) { _password = password; }

	// Getters

	string getAdminName() { return _adminname; }
	string getPassword() { return _password; }

	// Functions

	void writeFile() {
		try {
			ofstream file("RegisterLogin/admins.txt", ios::app);
			if (!file) throw exception("File couldnt be opened\n");
			if (!file.is_open()) throw exception("File couldnt be opened\n");

			file << _adminname << '-' << _password << '-' << this->getName() << '-' << endl;
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}

	void readFile() {
		try {

			ifstream file("RegisterLogin/admins.txt", ios::in);
			if (!file) throw exception("File couldnt be opened\n");
			if (!file.is_open()) throw exception("File couldnt be opened\n");

			string name, username, password, s;

			while (!file.eof()) {
				getline(file, username, '-');
				getline(file, password, '-');
				getline(file, name, '-');
				getline(file, s, '\n');
				Admin* newadmin = new Admin(name, username, password);
				admins.push_back(newadmin);
			}
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}

	// Operator Overloading

	friend ostream& operator<<(ostream& print, const Admin& other) {
		cout << Person(other);
		cout << other._adminname << endl
			<< other._password << endl;

		return print;
	}

	bool operator==(const Admin& u1) {
		return (_adminname == u1.getName() && _password == u1._password);
	}
};



User* newUser;
Admin* newAdmin;

void signUpUser() {
	cin.ignore();
	string name, username, password;
	cout << "Please enter the name : ";
	getline(cin, name);
	cout << "Please enter username : ";
	getline(cin, username);
	cout << "Please enter password : ";
	getline(cin, password);
	for (auto i : users) {

		if (i->getUsername() == username)
		{
			cout << "Bu Username movcuddur";
			return;
		}

	}
	newUser = new User(name, username, password);
	newUser->writeFile();
	users.push_back(newUser);


}
void signUpAdmin() {
	string name, username, password;
	cout << "Please enter the name : ";
	getline(cin, name);
	cout << "Please enter username : ";
	getline(cin, username);
	cout << "Please enter password : ";
	getline(cin, password);
	for (auto i : admins) {

		if (i->getAdminName() == username)
		{
			cout << "Bu Username movcuddur";
			return;
		}

	}
	newAdmin = new Admin(name, username, password);
	newAdmin->writeFile();
	admins.push_back(newAdmin);

}



User* LoginedUser = nullptr;
Admin* LoginedAdmin = nullptr;

bool signInUser() {
	string username, password;
	cout << "Please enter username : ";
	getline(cin, username);
	cout << "Please enter password : ";
	getline(cin, password);

	for (auto i : users) {
		if ((i->getUsername() == username) && (i->getPassword() == password))
		{
			LoginedUser = i;
			return true;
		}
	}
	cout << "Incorrect username or password. Please try again.\n";
	return false;
}

bool signInAdmin() {
	string username, password;
	cout << "Please enter username : ";
	getline(cin, username);
	cout << "Please enter password : ";
	getline(cin, password);

	for (auto i : admins) {
		if ((i->getAdminName() == username) && (i->getPassword() == password))
		{
			LoginedAdmin = i;
			return true;
		}
	}
	cout << "Incorrect username or password. Please try again.\n";
	return false;
}


