#pragma once 

class Quiz {
	string _quizname;
	Questions _questions;

public:

	Quiz() = default;
	Quiz(string quizname) {
		if (quizname[quizname.size() - 4] != '.') quizname.append(".txt");
		_quizname = quizname;
		ofstream file("Quizs/QuizNames.txt", ios::app);
		if (!file)cout << "file coudnt open!";
		file << quizname << "\n";
		file.close();
	}

	// Acsessors

	// Setters

 void setQuizName(string quizname) {
		if (quizname[quizname.size() - 4] != '.') quizname.append(".txt");
		_quizname = quizname;

	}
 void setQuestions(Questions questions) {
		_questions = questions;
	
	}

	// Getters

	 string getQuizName() { return _quizname; }
	Questions getQuestion() { return _questions; }

	// Functions

	
	

	// Operator Overloading


	void WriteFile() {
		try {
			ofstream file("Quizs/" + _quizname, ios::app);

			if (!file) throw exception("File couldnt be opened\n");
			if (!file.is_open()) throw exception("File couldnt be opened\n");

			for (auto& i : _questions.getQuestions()) {
				file << i.first->getQuestion() << endl;
				file << (i.second->getAnswers()[0]).getAnswer() << endl;
				for (int j = 1; j < 4; j++) file << (i.second->getAnswers()[j]).getAnswer() << "-";
				file << endl;
			}file.close();
		}
		catch (exception& ex) {
			cout << ex.what() << endl;
		}
	}

	void ReadFromFile(const string _quizname) {
		ifstream file("Quizs/" + _quizname+".txt", ios::in);
		if (!file) throw exception("File couldnt be found\n");
		if (!file.is_open()) throw exception("File couldnt be opened\n");

		string quest;
		string correct;
		string answer;
		string st = "";

		while (!file.eof()) {
			getline(file, quest);
			Question* question = new Question;
			question->setQuestion(st+quest);
			getline(file, correct);
			Answer correctans(correct, true);
			Answers* answers = new Answers;
			answers->setAnswer(correctans);
			for (int i = 0; i < 3; i++) {
				getline(file, answer, '-');
				Answer _answer(answer);
				answers->setAnswer(_answer);
			}file >> st;
			_questions.setQuestion(question, answers);
		} file.close();
	}



	friend ostream& operator<<(ostream& print, 
		Quiz& quiz) {
		cout << quiz._quizname << endl;
		cout << quiz._questions;
		

		return print;
	}
};