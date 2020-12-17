#define LOC_TIME
#include "CMS.hpp"

using namespace std;

int main(){
    vector <Course> CourseList;
    vector <Student> StudentList;
    vector <Lecturer> LecturerList;
    
    StudentList.push_back(Student("JohnSmith", 0, true));
    StudentList.push_back(Student("JaneSmith", 1, true));
    StudentList.push_back(Student("EricaCordelia", 2, true));
    for(int i = 0; i < StudentList.size(); i++){
        StudentList[i].addCourse(&CourseList[0]);
        cout<<StudentList[i].repr()<<endl;
        StudentList[i].printCourse();
    }
}