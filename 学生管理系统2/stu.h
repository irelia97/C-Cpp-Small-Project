#include <string>

#ifndef _Student_H_
#define _Student_H_
using std::string;

class Score
{
	private:
		string sno;
		string course;
		int score;
	public:
	   ~Score(){}
	    Score(){}
	    Score(string _sno, string _course, int _score):sno(_sno), course(_course), score(_score){}
	    
	    string GetCourseName() {return course;}
	    int    GetCourseScore(){return score;}
	    void   NewScore(const int _score){score = _score;}
};
	    
typedef class Student STU;
class Student
{
	private:
		string sno;
		string sname;
		string room;
		string tel;
		Score  sco;
	public:
		static int num;
		Student *next;
	   ~Student(){--num;}
	   	Student(){next = NULL;}
		Student(string _no, string _name, string _room, string _tel, string course, int score)
		:sno(_no), sname(_name), room(_room), tel(_tel)
		{
			++num;
			sco = Score(sno, course, score);
			next = NULL;
		}
	   	
	   	string GetSno(){return sno;}
	   	string GetSname(){return sname;}
	   	string GetRoom(){return room;}
	   	string GetTel(){return tel;}
	   	
	   	void NewSno(const string  _sno)  {sno = _sno;} 
	   	void NewName(const string _sname) {sname = _sname;} 
	   	void NewRoom(const string _room) {room = _room;} 
	   	void NewTel(const string _tel)  {tel = _tel;} 
	   	Score& GetSco() {return sco;} 	   	
		void PrintInf();   	
};



#endif
