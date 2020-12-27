#ifndef LOC_PEOPLE
#define LOC_PEOPLE
#include "People.hpp"
#endif

#ifndef LOC_COURSE
#define LOC_COURSE
#include "Course.hpp"
#endif

#ifndef LOC_TIME
#define LOC_TIME
#include "Time.hpp"
#endif

#ifndef STD_VECTOR
#define STD_VECTOR
#include<vector>
#endif

#ifndef STD_ITERATOR
#define STD_ITERATOR
#include<iterator>
#endif

#ifndef STD_IOSTREAM
#define STD_IOSTREAM
#include<iostream>
#endif

class Student : public People{
    public:
        Student(const std::string &Name, const int& Id, const bool& International) : People(Name, Id){
            _Inter_ = International;
        };
        bool addCourse(SCourse& Course){
            //duplicate check
            if(!_DuplicateCheck_(Course)){
                _CourseList_.push_back(Course);
                _CourseList_[_CourseList_.size() - 1].reset();
                return true;
            }
            return false;
        }
        bool addCourse(PCourse* Base){
            SCourse a(Base);
            if(!_DuplicateCheck_(a)){
                _CourseList_.push_back(a);
                return true;
            }
            return false;
        }
        bool removeCourse(SCourse& Course){
            auto pos = _CoursePos_(Course);
            if(pos != _CourseList_.end()){
                _CourseList_.erase(pos);
                return true;
            }
            return false;
        }
        bool removeCourse(PCourse& Base){
            auto pos = _CoursePos_(Base.id());
            if(pos != _CourseList_.end()){
                _CourseList_.erase(pos);
                return true;
            }
            return false;
        }
        bool removeCourse(const int& Id){
            auto pos = _CoursePos_(Id);
            if(pos != _CourseList_.end()){
                _CourseList_.erase(pos);
                return true;
            }
            return false;
        }
        bool removeCourse(const std::string &Name){
            auto pos = _CoursePos_(Name);
            if(pos != _CourseList_.end()){
                _CourseList_.erase(pos);
                return true;
            }
            return false;
        }
        
        void setStatus(const bool &International){
            _Inter_     = International;
        }

        std::string repr(){
            return "Student " + _Name_ + " " + std::to_string(_Id_);
        }
        void printCourse(){
            for(auto i = _CourseList_.begin(); i < _CourseList_.end();i++){
                std::cout<<i -> repr()<<std::endl;
            }
        }
        Student operator = (const Student& a){
            this -> _CourseList_ = a._CourseList_;
            this -> _Id_    = a._Id_;
            this -> _Name_  = a._Name_;
            this -> _Phone_ = a._Phone_;
            this -> _Age_   = a._Age_;   
            return *this;
        }
    
    private:
        std::vector <SCourse> _CourseList_;
        bool _Inter_;
        bool _DuplicateCheck_ (SCourse& Course){
            for(auto i = _CourseList_.begin(); i < _CourseList_.end(); i++){
                if(Course.id() == i -> id()){
                    return true;
                }
            }
            return false;
        }
        std::vector<SCourse>::iterator _CoursePos_(SCourse& Course){
            for(auto i = _CourseList_.begin(); i < _CourseList_.end(); i++){
                if(Course.id() == i -> id()){
                    return i;
                }
            }
            return _CourseList_.end();
        }
        std::vector<SCourse>::iterator _CoursePos_(const int& Id){
            for(auto i = _CourseList_.begin(); i < _CourseList_.end(); i++){
                if(Id == i -> id()){
                    return i;
                }
            }
            return _CourseList_.end();
        }
        std::vector<SCourse>::iterator _CoursePos_(const std::string &Name){
            for(auto i = _CourseList_.begin(); i < _CourseList_.end(); i++){
                if(Name == i -> name()){
                    return i;
                }
            }
            return _CourseList_.end();
        }

};

class Lecturer : public People{ 
    public:
        Lecturer(const std::string &Name, const int &Id) : People(Name, Id){}; 

        std::string repr(){
            return "Lecturer " + _Name_ + " " + std::to_string(_Id_);
        }           
        
        Lecturer operator = (const Lecturer& a){
            this -> _CourseList_ = a._CourseList_;
            this -> _Id_    = a._Id_;
            this -> _Name_  = a._Name_;
            this -> _Phone_ = a._Phone_;
            this -> _Age_   = a._Age_;   
            return *this;
        }
    private:
        std::vector <PCourse*> _CourseList_;
};

class Course : public PCourse{
    public:
        Course(const std::string Name, const int &Id) : PCourse(Name, Id){};
        bool addStudent(Student* Object){
            if(!_CheckDuplicate_(*Object, 0)){
                _StudentList_.push_back(Object);
                return true;
            }
            return true;
        }
        bool addLecturer(Lecturer* Object){
            if(!_CheckDuplicate_(*Object, 1)){
                _LecturerList_.push_back(Object);
                return true;
            }
            return false;
        }
        bool removeStudent(Student* Object){
            auto i = _PeoplePos_(*Object, 0);
            if(i != _StudentList_.end()){
                _StudentList_.erase(i);
                return true;
            }
            return false;
        }
        bool removeStudent(const int&Id){
            auto i = _PeoplePos_(Id, 0);
            if(i != _StudentList_.end()){
                _StudentList_.erase(i);
                return true;
            }
            return false;
        }
        bool removeStudent(const std::string &Name){
            auto i = _PeoplePos_(Name, 0);
            if(i != _StudentList_.end()){
                _StudentList_.erase(i);
                return true;
            }
            return false;
        }
        bool removeLecturer(Lecturer* Object){
            auto i = _PeoplePos_(*Object, 1);
            if(i != _LecturerList_.end()){
                _LecturerList_.erase(i);
                return true;
            }
            return false;
        }
        bool removeLecturer(const int& Id){
            auto i = _PeoplePos_(Id, 1);
            if(i != _LecturerList_.end()){
                _LecturerList_.erase(i);
                return true;
            }
            return false;
        }
        bool removeLecturer(const std::string &Name){
            auto i = _PeoplePos_(Name, 1);
            if(i != _LecturerList_.end()){
                _LecturerList_.erase(i);
                return true;
            }
            return false;
        }

        Course operator = (Course& a){
            this -> _Id_    = a._Id_;
            this -> _Name_  = a._Name_;
            this -> _StudentList_   = a._StudentList_;
            this -> _LecturerList_  = a._LecturerList_;
            return *this;
        }
    private:
        std::vector <People*> _StudentList_;
        std::vector <People*> _LecturerList_;

        bool _CheckDuplicate_(People& Value, const int &Ind){
            std::vector <People*>::iterator i;
            std::vector <People*>::iterator j;
            if(Ind == 0){
                i = _StudentList_.begin();
                j = _StudentList_.end();
            }
            else{
                i = _LecturerList_.begin();
                j = _LecturerList_.end();
            }
            for( ;i < j;i++){
                if((*i) -> id() == Value.id()){
                    return true;
                }
            }
            return false;
        }
        std::vector <People*>::iterator _PeoplePos_(People &Value, const int &Ind){
            std::vector<People*>::iterator i, j;
            if(Ind == 0){
                i = _StudentList_.begin();
                j = _StudentList_.end();
            }
            else{
                i = _LecturerList_.begin();
                j = _LecturerList_.end();
            }
            for(; i < j;i++){
                if(Value.id() == (*i) -> id()){
                    return i;
                }
            }
            return j;
            
        }
        std::vector <People*>::iterator _PeoplePos_(const int& Id, const int &Ind){
            std::vector<People*>::iterator i, j;
            if(Ind == 0){
                i = _StudentList_.begin();
                j = _StudentList_.end();
            }
            else{
                i = _LecturerList_.begin();
                j = _LecturerList_.end();
            }
            for(; i < j;i++){
                if(Id == (*i) -> id()){
                    return i;
                }
            }
            return j;
            
        }
        std::vector <People*>::iterator _PeoplePos_(const std::string &Name, const int &Ind){
            std::vector<People*>::iterator i, j;
            if(Ind == 0){
                i = _StudentList_.begin();
                j = _StudentList_.end();
            }
            else{
                i = _LecturerList_.begin();
                j = _LecturerList_.end();
            }
            for(; i < j;i++){
                if(Name == (*i) -> name()){
                    return i;
                }
            }
            return j;
            
        }
};

class School{
    public:
        School(){
            _CourseId_      = 0;
            _StudentId_     = 0;
            _LecturerId_    = 0;
        }
        Course course(const long& Index){
            return _CourseList_[Index];
        }
        Student student(const long& Index){
            return _StudentList_[Index];
        }
        Lecturer lecturer(const long& Index){
            return _LecturerList_[Index];
        }

        void addCourse(const Course& course){
            _CourseList_.push_back(course);
            _CourseId_ += 1;
        }
        void addLecturer(const Lecturer& lecturer){
            _LecturerList_.push_back(lecturer);
            _LecturerId_ += 1;
        }
        void addStudent(const Student& student){
            _StudentList_.push_back(student);
            _StudentId_   += 1;
        }

        void deleteStudent(const int& Id){
            _StudentList_.erase(_StudentList_.begin() + Id);
        }
        void deleteCourse(const int& Id){
            _CourseList_.erase(_CourseList_.begin() + Id);
        }
        void deleteLecturer(const int& Id){
            _LecturerList_.erase(_LecturerList_.begin() + Id);
        }
    private:
        std::vector <Course> _CourseList_;
        std::vector <Lecturer> _LecturerList_;
        std::vector <Student> _StudentList_;

        int _CourseId_;
        int _LecturerId_;
        int _StudentId_;
};