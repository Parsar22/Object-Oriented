//
// Created by PARSA on 11/11/2022.
//

#include "workout.h"
#include <iostream>


Workout ::Workout(string ename)
{
    name = ename;
    date = "11/13/2022";
}

bool Workout :: setValues(double a, double b)
{
    return false ;
}

void Workout :: switchValid()
{
    valid = false;
}

double Workout ::  percent()
{
    return 0;
}

double Workout :: Score()
{
    return 0;
}

bool Workout :: isValid()
{
    return valid;
}

bool Workout :: checkComp()
{
    return completed = false;
}


string Workout :: getDate()
{
    return date;
}

string Workout :: getValues()
{
    return "empty";
}


