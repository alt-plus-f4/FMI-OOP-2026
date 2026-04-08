#include <iostream>
#include "../lib/ezlib.h"

class Beverage{
    public:
        Beverage(){
            setName("Ben 10");
            mIsAlcoholic = true;
            mPrice = 6.7;
        }
        Beverage(const char* name, bool isAlcoholic, float Price){
            setName(name);
            mIsAlcoholic = isAlcoholic;
            mPrice = Price;
        }
        Beverage (const Beverage& other){
            setName(other.mName);
            mIsAlcoholic = other.mIsAlcoholic;
            mPrice = other.mPrice;
        }
        Beverage& operator=(const Beverage& other){
            if(this == &other) return *this;
            
            setName(other.mName);
            mIsAlcoholic = other.mIsAlcoholic;
            mPrice = other.mPrice;

            return *this;
        }
        ~Beverage(){
            delete [] mName;
        }
        void printBeverage(){
            std::cout << "-- Beverage -- " << std::endl;
            std::cout << "Name: " << mName << std::endl;
            std::cout << "Birth IsAlcoholic: " << mIsAlcoholic << std::endl;
            std::cout << "Price: " << mPrice << std::endl;
        }
        void setName(const char *name) {
            if(!name) throw std::invalid_argument("Name can't be empty");
            
            delete [] mName;
            mName = new char[strlen_t(name)];

            strcpy_t(mName, name);
        }
        void setIsAlcoholic(bool isAlcoholic) {mIsAlcoholic = isAlcoholic;} 
        void setPrice(float Price) {mPrice = Price;}
        const char* getName() const {return mName;}
        bool getIsAlcoholic() const {return mIsAlcoholic;} 
        float getPrice() const {return mPrice;}
    private:
        bool mIsAlcoholic;
        float mPrice;
        char *mName;
};

int main(void){
    
    return 0;
}