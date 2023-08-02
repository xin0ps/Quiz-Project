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

	friend ostream& operator<<(ostream& print, const Answers& other) {
		cout << "a) " << other.answers[0];
		cout << "b) " << other.answers[1];
		cout << "c) " << other.answers[2];
		cout << "d) " << other.answers[3];

		return print;
	}
};