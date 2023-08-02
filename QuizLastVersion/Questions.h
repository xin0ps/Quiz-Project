#pragma once
class Question {
	string _question;

public:

	Question() = default;
	Question(string newquestion) {
		_question = newquestion;

	}

	// Acsessors

	// Setters

	 void setQuestion(string question) { _question = question; }

	// Getters

	 string getQuestion() { return _question; }


	// Operator Overloading

	friend ostream& operator<<(ostream& print, const Question other) {
		cout << other._question << endl;

		return print;
	}

};

class Questions {
	map<Question*, Answers*> questions;

public:

	Questions() = default;
	Questions(map<Question*, Answers*> questions) {
		this->questions = questions;
	}

	// Acsessors

	// Setters

	void setQuestions(map<Question*, Answers*> questions) { this->questions = questions; }
	void setQuestion(Question* question, Answers* answers) { this->questions[question] = answers; }

	// Getters

	map<Question*, Answers*>& getQuestions() { return questions; }
	vector<Answer>& getAnswer() { return questions[0]->getAnswers(); }
	 int size() { return questions.size(); }

	// Functions



	// Operator Overloading
    
        
         
     
     friend ostream& operator<<(ostream& print, Questions& other) {
         int Correct = 0;
         int False = 0;
         int Empty = 0;
         const int QueCount = other.size();
         cout << QueCount;

         string Ans;
         bool run = true;
         auto pair = other.questions.begin();  // Initialize the iterator

         while (run) {
             system("cls");
             cout << "Next question-[n]" << endl;
             cout << "Prev question-[p]" << endl;
             cout << "End Quiz-[e]" << endl;

             if (pair == other.questions.end()) {
                 cout << "No more questions!" << endl;
                 break;
                 
             }

             Question& question = *pair->first;
             Answers& answer = *pair->second;

             cout << question << endl;
             cout << answer << endl;
             cout << "Answer: ";
             
             cin >> Ans;
             cin.ignore();  // Clear the input buffer

             if (Ans == (answer.getTrueAnswer())) {
                 Correct++;
                 pair = other.questions.erase(pair);  // Remove the question and move iterator to the next
             }
             else if (Ans != "n" && Ans != "p"&&Ans!="e") {
                 False++;
                 pair = other.questions.erase(pair);  // Remove the question and move iterator to the next
             }
             else if (Ans == "n" && next(pair) != other.questions.end()) {
                 ++pair;  // Move to the next question if not at the end
             }
             else if (Ans == "p" && pair != other.questions.begin()) {
                 --pair;  // Move to the previous question if not at the beginning
             }
             else if (Ans == "e") {
                 break;
             }
             else { cout << "Daxiletme yanlisdir!" << endl; }
         }

         Empty = QueCount - (Correct + False);
         if (LoginedUser != nullptr) {
             cout << LoginedUser->getName() + " Sizin Neticeniz:" << endl;
         }
         if (LoginedAdmin != nullptr) {
             cout << LoginedAdmin->getAdminName() + " Sizin Neticeniz:" << endl;
         }
         cout << "Correct: " << Correct << endl;
         cout << "False: " << False << endl;
         cout << "Empty: " << Empty << endl;
         string txt;
         if (LoginedUser != nullptr) {
             txt =LoginedUser->getName()+"|"+"Quizname:"+ quiznameGlobal + "|" + "Correct:" + to_string(Correct) + "|" + "False:" + to_string(False) + "|" + "Empty:" + to_string(Empty) + "\n";

         }
         if (LoginedAdmin != nullptr) {
            txt = LoginedAdmin->getAdminName() + "|"+"Quizname:" + quiznameGlobal + "|" + "Correct:" + to_string(Correct) + "|" + "False:" + to_string(False) + "|" + "Empty:" + to_string(Empty) + "\n";
         }
         ofstream file("HighScore/highScore.txt", ios::app);
             if (!file) throw exception("File couldnt be opened\n");
         if (!file.is_open()) throw exception("File couldnt be opened\n");
         file << txt;
         file.close();


         

         return print;
     }

};