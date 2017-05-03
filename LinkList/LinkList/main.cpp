#include "List.h"
//#include <string>
//using namespace std;

struct Student 
{
	int id;
	float score;
	Student(int _id, float _score) : id(_id), score(_score){}
	Student(){}
	friend bool operator !=(const Student &left, const Student &right);
};
bool operator !=(const Student &left, const Student &right)
{
	return (left.id == right.id && left.score == right.score)? false : true;
}

int main()
{
	CList<Student> list;
	Student s1(1, 22);
	Student s2(2, 33);
	Student s3(3, 44);

	list.Append(s1);
	list.Append(s2);
	list.Append(s3);
	list.Insert(s1, 2);

	Student s = list[2];

	list.Remove(s1);

	return 0;
}