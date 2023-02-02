//
// Created by PARSA on 11/11/2022.
//

#ifndef P4_HIIT_H
#define P4_HIIT_H
#include "workout.h"


class Hiit : public Workout
{
private :
    double ActiveTime = 0;
    double RestTime = 0;
    double ExActiveTime  ;
    double ExRestTime  ;
    int eprep  ;
    int crep  = 0 ;
    Workout* copy() override ;
public :
    Hiit() : Workout() { } ;
    Hiit(string eName, double EATime, double ERestTime, int ExRep) ;
    double percent() override;
    double Score() override;
    bool checkComp() override;
    bool setValues(double Active, double rest, int ExRep) ;
    string getValues() override;
    bool increment() override;
    bool decrement() override ;
 //   friend istream &operator>>(istream& in,Hiit &dt) ;
};


#endif //P4_HIIT_H
