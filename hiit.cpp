//
// Created by PARSA on 11/11/2022.
//

#include <iostream>
#include "hiit.h"
#include "workout.h"

Hiit :: Hiit(string eName, double EATime, double ERestTime, int ExRep) : Workout(eName)
{

    ExActiveTime = EATime;
    ExRestTime = ERestTime;
    eprep = ExRep ;
    valid = true;
}


double Hiit ::  percent()
{
    if (ExActiveTime > 0 && ExRestTime > 0)
    {
        double ActivePerc = (ActiveTime / ExActiveTime) * 100;
        double RestPerc = (RestTime / ExRestTime) * 100;
        double repPrerc = (eprep/crep) * 100;
        if (repPrerc > 100)
            repPrerc  = 100 ;
        if (ActivePerc > 100)
            ActivePerc = 100;
        if (RestPerc > 100)
            RestPerc = 100;
        double sum = ActivePerc + RestPerc+ repPrerc;
        return (sum / 3) ;
    }
    return 0;
}


double Hiit ::Score()
{
    double ActivePerc = (ActiveTime / ExActiveTime) ;
    double RestPerc = (RestTime / ExRestTime);
    double repPrerc = (eprep/crep) ;
    if (ExRestTime > 0 && ExActiveTime > 0)
    {
        if(repPrerc > 1)
            repPrerc = 1;
        if(ActivePerc > 1)
            ActivePerc = 1;
        if(RestPerc > 1)
            RestPerc = 1;
        return ((RestPerc + ActivePerc + repPrerc) / 3);
    }
    return 0;
}


bool Hiit :: checkComp()
{
    if (this->Score() == 1)
        return completed = true;
    return completed = false;
}


bool Hiit :: setValues(double Active, double rest, int Exrep)
{
    if (isValid()) {
        if (ExActiveTime > 0 && ExRestTime > 0) {
            ActiveTime = Active;
            RestTime = rest;
            crep = Exrep ;
            completed = checkComp();
            switchValid();
            return true ;

        }
    }
    return false ;
}


bool Hiit ::increment()
{
    ExActiveTime++;
    ExRestTime++;
    eprep++ ;
    return true;
}

bool Hiit :: decrement()
{
    ExActiveTime--;
    ExRestTime--;
    eprep-- ;
    return true;
}

Workout* Hiit ::copy()
{
    Hiit* hitC = new Hiit(name, ExActiveTime, ExRestTime, eprep) ;
    hitC->setValues(ActiveTime,RestTime,crep) ;
    return hitC ;
}



string Hiit :: getValues()
{
    string toReturn = " name :" + name + " time : " + to_string(ExActiveTime) + " rest : " + to_string(RestTime)
                      + " score : " + to_string(Score()) + " percent : " + to_string(percent()) + " completed : " + to_string(completed);
    return toReturn;
}
