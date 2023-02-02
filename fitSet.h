//
// Created by PARSA on 11/11/2022.
//

#ifndef P4_FITSET_H
#define P4_FITSET_H
#include "workout.h"


class FitSet : public Workout
{
private :
    string classification;
    double weight; // expected weight to be lifted
    double Cweight;
    double Crep; // completed repetition
    int prep ;
    Workout* copy() override ;
public :
    FitSet() : Workout() { } ;
    FitSet(string eName, string eclass, double eWeight, int eprep) ;
    string getValues()  override;
    double percent() override;
    double Score() override;
    bool setValues(double newRep, double wt) override ;
    bool checkComp() override;
    bool increment() override ;
    bool decrement() override ;
};


#endif //P4_FITSET_H
