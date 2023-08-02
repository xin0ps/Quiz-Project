#pragma once


void startQuiz() {
	system("cls");
	ifstream file("Quizs/QuizNames.txt", ios::in);
	string line1;
	while (getline(file, line1)) {
		cout << line1.substr(0, line1.length() - 4) << endl;
	}
	string choice;
	cout << "Baslamaq Istediyiniz Quizi secin: ";
	cin >> choice;
	quiznameGlobal = choice;
	Quiz newquiz;
	newquiz.ReadFromFile(choice);
	
	cout << newquiz;

	
	s

	//for ( auto i: newquiz.getQuestion().getQuestions())
	//{
	//	cout << "ll" << endl;
	//	//cout << *i.first;
	//}
		
	


}

void highScore() {
	system("cls");
	string txt = "HighScore/highScore.txt";
	ifstream file(txt, ios::in);

	if (!file.is_open()) {
		cerr << "Error: Could not open the file." << endl;
		return;
	}

	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}

	file.close();
	getchar();
}

void deleteQuiz(string wordToRemove = "def", string str = "Quizs/QuizNames.txt") {
	system("cls");
	ifstream inputFile(str);
	ofstream outputFile("Quizs/temp.txt");
	string line1;
	while (getline(inputFile, line1)) {
		cout << line1.substr(0, line1.length() - 4) << endl;
	}

	inputFile.clear();
	inputFile.seekg(0, ios::beg); 

	cout << "silmek istediyiniz quiz:";
	getline(cin, wordToRemove);
	std::string tmp = wordToRemove + ".txt";
	if (!inputFile) {
		cout << "File acila bilmir" << endl;
		return;
	}

	string line;
	while (getline(inputFile, line)) {
		size_t pos = line.find(tmp);
		if (pos == string::npos) {
			outputFile << line << endl;
		}
	}

	inputFile.close();
	outputFile.close();

	std::string f = "Quizs/" + tmp;
	remove(str.c_str());
	rename("Quizs/temp.txt", str.c_str());
	remove(f.c_str());
	cout << "quiz silindi" << endl;
	getchar();
}
Quiz* createQuiz() {
	string quizName, quest, ans;
	int questionCount;
	cout << "Enter Quiz name : ";
	getline(cin, quizName);
	cout << "Please enter the question count : ";
	cin >> questionCount;
	Questions questions;
	cin.ignore();

	while (questionCount--) {
		system("cls");
		Question* question = new Question;
		Answers* answers = new Answers;


		cout << "Please enter the question : ";
		getline(cin, quest);
		question->setQuestion(quest);
		cout << "Please enter the correct answer : ";
		getline(cin, ans);
		Answer corans(ans, true);
		answers->setAnswer(corans);

		for (int i = 0; i < 3; i++) {
			cout << "Please enter the wrong answer : ";
			getline(cin, ans);
			Answer answer(ans);
			answers->setAnswer(answer);
		}questions.setQuestion(question, answers);
	}
	Quiz* quiz = new Quiz(quizName);
	quiz->setQuestions(questions);
	quiz->WriteFile();
	return quiz;
}

void quizMenuUser() {
	while (true) {
		system("cls");
		cout << "[1]-Start Quiz" << endl;
		cout << "[2]- High score" << endl;
		cout << "[3]- Exit" << endl;
		int quizchoose;
		cout << "Your choice: ";
		cin >> quizchoose;
		cin.ignore();
		if (quizchoose == 1) {
			startQuiz();
		}
		if (quizchoose == 2) {
			highScore();
		}
		if (quizchoose == 3) {
			break;
		}
	}
}
Quiz quiz;
void quizMenuAdmin() {
	while (true)
	{
		system("cls");
		cout << "[1]-Create Quiz" << endl;
		cout << "[2]-Start Quiz" << endl;
		cout << "[3]-Delete Quiz" << endl;
		cout << "[4]- High score" << endl;
		cout << "[5]- Exit" << endl;
		int quizchoose;
		cout << "Your choice: ";
		cin >> quizchoose;
		cin.ignore();
		if (quizchoose == 1) {
		   createQuiz();
		}
		if (quizchoose == 2) {
			startQuiz();
		}
		if (quizchoose == 3) {
			deleteQuiz();
		}
		if (quizchoose == 4) {
			highScore();
		}
		if (quizchoose == 5) {
			break;
		}
	}
}



void start()
{

	User userInstance;
	userInstance.readFile();
	Admin adminInstance;
	adminInstance.readFile();
	while (true)
	{
		cout << "[1]-SignUp" << endl;
		cout << "[2]-SignIn" << endl;
		cout << "Your Choice: ";
		int choose1;
		cin >> choose1;
		cin.ignore();

		if (choose1 == 1)
		{
			system(("cls"));
			cout << "[1]-Admin" << endl;
			cout << "[2]-User" << endl;
			cout << "Your Choice: ";
			int signup;
			cin >> signup;
			cin.ignore();

			if (signup == 1)
				signUpAdmin();
			else if (signup == 2)
				signUpUser();
		}
		else if (choose1 == 2)
		{
			system(("cls"));
			cout << "[1]-Admin" << endl;
			cout << "[2]-User" << endl;
			cout << "Your Choice: ";
			int signin;
			cin >> signin;
			cin.ignore();

			if (signin == 1)
				if (signInAdmin()) {
					quizMenuAdmin();
				}

			if (signin == 2)
			{
				if (signInUser()) {
					quizMenuUser();
				}
			}
		}
	}
}