class Time{
    public:
        Time(const int& Second, const int& Minute, const int& Hour){
            _Second_    = Second;
            _Minute_    = Minute;
            _Hour_      = Hour;
            _Day_       = nullptr;
            _Total_     = nullptr;
        }
        Time(const int& Second, const int& Minute, const int&Hour, const int& Day){
            _Second_    = Second;
            _Minute_    = Minute;
            _Hour_      = Hour;
            _Day_       = new int;
            *_Day_      = Day;
            _Total_     = nullptr;
        }
        Time(){
            _Second_    = 0;
            _Minute_    = 0;
            _Hour_      = 0;
            _Day_       = nullptr;
            _Total_     = nullptr;
        }
        ~Time(){
            if(_Day_ != nullptr){
                delete _Day_;
            }
            if(_Total_ != nullptr){
                delete _Total_;
            }
        }

        //init Uninit variable
        void initTotal(){
            if(_Total_ == nullptr){
                _Total_     = new int;
            }
            if(_Day_ != nullptr){
                *_Total_     = _Second_ + _Minute_ * 60 + _Hour_ * 3600 + *_Day_ * 24 * 3600;
            }
            else{
                *_Total_     = _Second_ + _Minute_ * 60 + _Hour_ * 3600;
            }
        }
        void initDay(const int& Day){
            if(_Day_ == nullptr){
                _Day_   = new int;
            }
            *_Day_   = Day;
        }

        //Change stuff
        void setSecond(const int& Second){
            _Second_    = Second;
        }   
        void setMinute(const int& Minute){
            _Minute_    = Minute;
        }
        void setHour(const int& Hour){
            _Hour_      = Hour;
        }
        void setDay(const int& Day){
            *_Day_      = Day;
        }
        void resetTotal(){
            if(_Total_ != nullptr){
                *_Total_     = _Second_ + _Minute_ * 60 + _Hour_ * 3600 + *_Day_ * 24 * 3600;
            }
        }
        void setMultiple(const int&Second, const int& Minute, const int& Hour){
            setSecond(Second);
            setMinute(Minute);
            setHour(Hour);
        }

        //get stuff
        int second(){
            return _Second_;
        }
        int minute(){
            return _Minute_;
        }
        int hour(){
            return _Hour_;
        }
        int day(){
            if(_Day_ != nullptr){
                return *_Day_;
            }
            return -1;
        }
        int total(){
            if(_Total_ != nullptr){
                return *_Total_;
            }
            return -1;
        }
        
        //Operations
        Time operator + (const Time&a){
            this -> _Second_    = a._Second_ + this -> _Second_;
            this -> _Minute_    = a._Minute_ + this -> _Minute_ + this -> _Second_ / 60;
            this -> _Hour_      = a._Hour_   + this -> _Hour_   + this -> _Minute_ / 60;
            this -> _Second_    %= 60;
            this -> _Minute_    %= 60;
            this -> _Hour_      %= 24;
            return *this;
        }
        Time operator - (const Time &a){
            //Assume that the no negative Time exist : 
            this -> _Second_    = this -> _Second_ - a._Second_ + 60;
            this -> _Minute_    = this -> _Minute_ - a._Minute_ + 60 - 1;
            this -> _Hour_      = this -> _Hour_   - a._Hour_ - 1;      
        }
        Time operator = (const Time &a){
            if(a._Day_ != nullptr){
                this -> _Day_       = new int;
                *(this -> _Day_)    = *(a._Day_);
            }
            if(a._Total_ != nullptr){
                this -> _Total_     = new int;
                *(this -> _Total_)  = *(a._Total_);
            }
            this -> _Hour_          = a._Hour_;
            this -> _Minute_        = a._Minute_;
            this -> _Second_        = a._Second_;
            return *this;
        }
    private:
        int _Second_;
        int _Minute_;
        int _Hour_;
        int* _Day_;
        int* _Total_;
};

class Period{
    public:
        Period(const Time& Start, const Time& End){
            _Start_     = Start;
            _End_       = End;
            _Period_    = _End_ - _Start_;
        }
        Time start(){
            return _Start_;
        }
        Time end(){
            return _End_;
        }
        Time duration(){
            return _Period_;
        }
    private:
        Time _Start_;
        Time _End_;
        Time _Period_;
};