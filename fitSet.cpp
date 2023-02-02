//
// Created by PARSA on 11/11/2022.
//

#include <iostream>
#include "fitSet.h"
#include "workout.h"



FitSet :: FitSet(string eName, string eclass, double eWeight, int eprep)
: Workout(eName)
{
    classification = eclass ;
    weight = eWeight;
    prep = eprep; // expeted rep
    valid = true;
}


double FitSet ::  percent()
{
    if (prep > 0 && weight > 0)
    {
        double repPerc = 0;
        double WeightPerc = 0;
        if (Crep / prep >= 1)
            repPerc = 100;
        if (Cweight / weight >= 1)
            WeightPerc = 100;
        return ((WeightPerc + repPerc) / 2) ;
    }
    return 0;
}

double FitSet :: Score()
{
    if (prep > 0 && weight > 0)
    {
        double repPerc = 0;
        double WeightPerc = 0;
        if (Crep / prep >= 1)
            repPerc = 1;
        if (Cweight / weight >= 1)
            WeightPerc = 1;
        return ((WeightPerc + repPerc) / 2) * 100;
    }
    return 0;
}


bool FitSet :: setValues(double newRep, double wt)
{
    if (isValid())
    {
        Cweight = wt;
        Crep = newRep;
        switchValid();
        return true ;
    }
    return false ;
}


bool FitSet ::checkComp()
{
    if(this->percent() == 100)
        return completed = true;
    return  completed = false;
}


bool FitSet ::increment()
{
    weight++ ;
    prep++ ;
    return true ;
}

bool FitSet :: decrement()
{
    weight-- ;
    prep-- ;
    return true ;
}


string FitSet :: getValues()
{
    string toReturn = " name :" + name + " Completed Reps : " + to_string(Crep) + " Completed Weight : " + to_string(Cweight)
                      + " score : " + to_string(Score()) + " percent : " + to_string(percent()) + " completed : " + to_string(completed);
    return toReturn;
}


Workout* FitSet :: copy()
{
    FitSet* hi = new FitSet(name, classification, weight, prep ) ;
    hi->setValues(Cweight,Crep) ;
    return hi ;
}