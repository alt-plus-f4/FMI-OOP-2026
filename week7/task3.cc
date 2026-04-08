#include <iostream>
#include "../lib/ezlib.h"

class Phone{
    public:
        Phone(){
            mBattery = 100; // 0 - 100
            mVolume = 10; // 0 - 10
            mOsVersion = 67; 
            mModel = new char[32]; // max
            strcpy_t(mModel, "Iphone 67");
        }

        Phone(
            unsigned short battery,
            unsigned short volume,
            unsigned int osVersion,
            char *model
        ){
            if(battery > 100 || volume > 10 || !model)
                clear(std::invalid_argument("Invalid args"));

            clear();

            mBattery = battery;
            setVolume(volume);
            mOsVersion = osVersion;
            
            mModel = new char[strlen_t(model)];
            strcpy_t(mModel, model);
        }

        void printPhone(){
            std::cout << "-- Phone --";
            std::cout << "Model : " << mModel; 
            std::cout << "Battery : " << mBattery; 
            std::cout << "Volume : " << mVolume; 
            std::cout << "OsVer : " << mOsVersion; 
        }

        void watchReels(int min){
            while(hasBattery() && min-- > 0)
                mBattery--;
        }
        void playClash(int min){
            while(hasBattery() && min-- > 0)
                mBattery -= 3;
        }
        void takePhoto(){
            if(hasBattery()) mBattery--;
        }
        void charge(int min){
            mBattery += min;
            if(min + mBattery >= 100) mBattery = 100;
        }

        // -- setters and getters --;

        void update() {
            if(hasBattery()) this->mOsVersion++;
        }

        void setVolume(unsigned short volume) {
            if(volume > 10)  clear(std::invalid_argument("Volume should be 0-10"));
            mVolume = volume;
        }
        
        unsigned short getBattery() const {
            return mBattery;
        }
        unsigned short getVolume() const {
            return mVolume;
        }
        unsigned int getOsVersion() const {
            return mOsVersion;
        }
        const char *getModel() const {
            return mModel;
        }

        ~Phone(){
            clear();
        }
    private:
        bool hasBattery(){
            return mBattery > 0;
        }

        void clear(){
            delete[] mModel;
            mBattery = 0;
            mVolume = 0;
            mOsVersion = 0;
        }
        void clear(std::exception e){
            delete [] mModel;
            throw e;
        }

        char *mModel;                       // -- 8  
        unsigned int mOsVersion;            // -- 4
        unsigned short mBattery; // 0 - 100 // -- 2
        unsigned short mVolume; // 0 - 10   // -- 2
};
 
int main(void){
    
    return 0;
}