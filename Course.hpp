#ifndef LOC_TIME
#define LOC_TIME
#include "Time.hpp"
#endif

#ifndef STD_STRING
#define STD_STRING
#include<string>
#endif

class PCourse{
    public:
        PCourse(const std::string &Name, const int& Id){
            _Name_  = Name;
            _Id_    = Id;
        }
        //Return
        std::string name(){
            return _Name_;
        }
        int id(){
            return _Id_;
        }
        virtual std::string repr(){
            return _Name_ + " " + std::to_string(_Id_);
        }
        //Get Stuff
        void setName(const std::string &Name){
            _Name_  = Name;
        }
        void setId(const int&Id){
            _Id_    = Id;
        }

        PCourse operator = (const PCourse &a){
            this -> _Name_  = a._Name_;
            this -> _Id_    = a._Id_;
            return *this;
        }
    protected:
        std::string _Name_;
        int _Id_;
};

class SCourse{
    public:
        SCourse(PCourse* Base){
            _Base_      = Base;
            _LGrade_    = "0";
            _NGrade_    = 0;
        }
        //Get
        std::string lGrade(){
            return _LGrade_;
        }
        int nGrade(){
            return _NGrade_;
        }
        std::string name(){
            return _Base_ -> name();
        }
        int id(){
            return _Base_ -> id();
        }

        //Set
        void setGrade(const int& NGrade){
            _NGrade_ = NGrade;
        }
        void setGrade(const std::string &LGrade){
            _LGrade_ = LGrade;
        }
        void setGrade(const int& NGrade, const std::string& LGrade){
            _NGrade_ = NGrade;
            _LGrade_ = LGrade;
        }
        void setBase(PCourse* Base){
            _Base_  = Base;
        }

        void reset(){
            _NGrade_    = 0;
            _LGrade_    = "0";
        }
        std::string repr(){
            return _Base_ -> repr() + " " + _LGrade_ + " " + std::to_string(_NGrade_);
        }

        SCourse operator = (const SCourse& a){
            this -> _Base_      = a._Base_;
            this -> _NGrade_    = a._NGrade_;
            this -> _LGrade_    = a._LGrade_;
            return *this;
        }
    private:
        PCourse* _Base_;
        int _NGrade_;
        std::string _LGrade_;
};