#include <iostream>
#include "../lib/ezlib.h"

class Product{
    public:
        Product(){
            setName("Big black horse c");
            setDescription("o ck"); 
            setPrice(6.7);
            setIsAvailable(true);
        }

        Product(
            const char *name,
            const char *description,
            float price,
            bool isAvailable
        ){
            if(price < 0 || !name || !description)
                clear(std::invalid_argument("Invalid args"));

            clear();

            setName(name);
            setDescription(description); 
            setPrice(price);
            setIsAvailable(isAvailable);
        }

        bool canBuy(float availableMoney){
            return mIsAvailable && availableMoney >= mPrice;
        }

        void printProduct(){
            std::cout << "-- Product --";
            std::cout << "name : " << mName; 
            std::cout << "description : " << mDescription; 
            std::cout << "price : " << mPrice; 
            std::cout << "isAvailable : " << mIsAvailable; 
        }
     
        // -- setters and getters --;

        void setName(const char *name){
            delete[] mName;

            mName = goodMalloc(name);
            if(mName) strcpy_t(mName, name);
        }
        void setDescription(const char *description){
            delete[] mDescription;

            mDescription = goodMalloc(description);
            if(mDescription) strcpy_t(mDescription, description);
        }
        void setPrice(float price) {
            if(price < 0)  clear(std::invalid_argument("Price should be > 0"));
            mPrice = price;
        }
        void setIsAvailable(bool isAvailable) {
            mIsAvailable = isAvailable;
        }
 
        const char *getName() const {
            return mName;
        }
        const char *getDescription() const {
            return mDescription;
        }
        float getPrice() const {
            return mPrice;
        }
        bool getIsAvailable() const {
            return mIsAvailable;
        }
        ~Product(){
            clear();
        }
    private:
        void clear(){
            delete[] mName;
            delete[] mDescription;
            mPrice = 0.0;
            mIsAvailable = false;
        }
        void clear(std::exception e){
            delete [] mName;
            delete [] mDescription;
            throw e;
        }

        char *mName;
        char *mDescription;
        float mPrice;
        bool mIsAvailable;
};
 
int main(void){
    
    return 0;
}