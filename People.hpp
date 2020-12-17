#ifndef STD_STRING
#define STD_STRING
#include<string>
#endif

class People{
    public:
        People(const std::string &Name, const int &Id){
            _Name_      = Name;
            _Id_        = Id;
        }
        People(const std::string &Name, const int &Id, const std::string &Phone){
            _Name_      = Name;
            _Id_        = Id;
            _Phone_     = Phone;
        }
        People(const std::string &Name, const int &Id, const std::string &Phone, const int &Age){
            _Name_      = Name;
            _Id_        = Id;
            _Phone_     = Phone;
            _Age_       = Age;
        }

        //Return Declaration, You can change this in child classes
        std::string name(){
            return _Name_;
        }
        int id(){
            return _Id_;
        }
        std::string phone(){
            return _Phone_;
        }
        int age(){
            return _Age_;
        }

        //Stuff
        virtual std::string repr()  = 0;
        //Value Change Declaration
        void setName(const std::string &Name){
            _Name_  = Name;
        }
        void setId(const int &Id){
            _Id_    = Id;
        }
        void setPhone(const std::string &Phone){
            _Phone_ = Phone;
        }
        void setAge(const int &Age){
            _Age_   = Age;
        }

    protected:
        int             _Id_;
        std::string     _Name_;
        std::string     _Phone_;
        int             _Age_;
};