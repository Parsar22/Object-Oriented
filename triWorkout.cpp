// Created by PARSA on 11/11/2022.
//

#include "triWorkout.h"

TriWorkout ::TriWorkout(string eName,  double EDistance,
double ETime, double EPace) : Workout(eName)
{
    ExTime = ETime;
    ExDistance = EDistance;
    ExPace = EPace;
    valid = true;
}



double TriWorkout :: paceCalculator()
{
    if (time > 0)
    {
        if (name == "running")
            return distance / time ;

        if (name == "cycling")
            if (time != 0)
                return distance / (time);

        if (name == "swimming")
            return (distance/100) / time;
    }
    return 0;
}



double TriWorkout :: percent()
{
    double PacePerc = 0;
    double distancePerc = 0;
    if (ExPace > 0 && ExDistance > 0)
    {
        PacePerc = (pace / ExPace) * 100;
        distancePerc = (distance / ExDistance) * 100;
        if (PacePerc >= 100)
            PacePerc = 100;
        if (distancePerc >= 100)
            distancePerc = 100;

    }
    return ((distancePerc + PacePerc) / 2) ;

}


double TriWorkout :: Score()
{
    double PaceScore = 0;
    double distanceScore = 0;
    if (ExPace > 0 && ExDistance > 0 )
    {
        PaceScore = (pace / ExPace);
        distanceScore = (distance / ExDistance);
    }
    if (PaceScore >= 1)
        PaceScore = 1;
    if (distanceScore >= 1)
        distanceScore = 1;
    return ((distanceScore + PaceScore) / 2);
}



bool TriWorkout :: checkComp()
{
    if (ExDistance - distance <= 0 && ExPace - pace <= 0)
        return completed = true;
    return completed = false;
}




bool TriWorkout :: setValues(double Atime, double Adistance)
{
    if(isValid())
    {
        time = Atime;
        distance = Adistance;
        pace = paceCalculator();
        checkComp();
        switchValid();
        return true ;
    }
    return false ;
}

string TriWorkout :: getValues()
{
    string toReturn =  " name :" + name + " target interval : " + to_string(ExTime)  + "completed : "
            + to_string(time) +  "target distance : " + to_string(ExDistance) +
            " Completed : " +to_string(distance)
            + " targeted pace :" + to_string(ExPace) + " completed pace : " + to_string(pace)
                       + " score : " + to_string(Score()) +
                       " percent : " + to_string(percent()) +" completed : " + to_string(completed);
    return toReturn;
}

bool TriWorkout ::increment()
{
    ExTime++ ;
    ExDistance++ ;
    ExPace++ ;
    return true;
}


bool TriWorkout :: decrement()
{
    ExDistance-- ;
    ExTime-- ;
    ExPace-- ;
    return true ;
}

Workout* TriWorkout ::copy()
{
    TriWorkout* hitC = new TriWorkout(name, ExDistance, ExTime, ExPace) ;
    hitC->setValues(time,distance) ;
    return hitC ;
}
