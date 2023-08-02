#pragma once
class Answer {
	bool isTrue = false;
	string _answer;
public:
	Answer() = default;
	Answer(const string answer) { _answer = answer; }
	Answer(const string answer, bool correct)
	{
		_answer = answer; 
		isTrue = correct;
	}
	void setAnswer(const string answer) { _answer = answer; }
	string getAnswer() {
		return _answer;
	}
	bool correct() {
		return isTrue;
	}
	friend ostream& operator<<(ostream& print, const Answer& other) {
		cout << other._answer << endl;

		return print;
	}
};

class Answers {
	vector<Answer>answers;
public:
	
	Answers() = default;
	Answers(vector<Answer>answers) { this->answers = answers; }
	void setAnswers(vector<Answer>answers) { this->answers = answers; }
	void setAnswer(Answer answer) { answers.push_back(answer); }
	vector<Answer>& getAnswers() { return answers; }
	string getTrueAnswer() {
		for (auto& i : answers) {
			if (i.correct()) return i.getAnswer();
			
		}
	}

	void shuffleAnswers() {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(answers.begin(), answers.end(), std::default_random_engine(seed));
	}


	friend ostream& operator<<(ostream& print, const Answers& other) {
		Answers shuffledAnswers = other.answers;  // Copy the Answers object
		shuffledAnswers.shuffleAnswers();  // Shuffle the answers
		cout << "a) " << shuffledAnswers.answers[0] << endl;
		cout << "b) " << shuffledAnswers.answers[1] << endl;
		cout << "c) " << shuffledAnswers.answers[2] << endl;
		cout << "d) " << shuffledAnswers.answers[3] << endl;

		return print;
	}
};