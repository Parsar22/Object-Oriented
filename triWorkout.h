// Created by PARSA on 11/11/2022.
// TriWorkout.h
// class invariants
// class invariant : inherited attributes from workout
//      and time and distance and other attributes
//      related to each triworkout is provided
//      and methods have been overwritten to
//      suit client expectations of a triworkout.

// interface invariant :that lets the customer add three different types of workout
//   running, cycling and swimming. each type of triworkout has
//   different units but same attributes. and triworkout offers
//   the same methods as workout but overwritten to suit client's
//   expectations.


#ifndef P4_TRIWORKOUT_H
#define P4_TRIWORKOUT_H
#include "workout.h"

class TriWorkout : public Workout
{
private :
    double time;
    double distance;
    double ExTime;
    double ExDistance;
    double ExPace ;
    double pace;
    Workout* copy() override ;
public:
    TriWorkout() : Workout() { } ; // default constructor
    TriWorkout(string eName,  double EDistance,
                  double ETime, double EPace) ; //constructor
    //precondition : pace is not initialized
    //postcondition : pace is calculated and initialized.
    double paceCalculator() ;
    double percent() override;
    double Score() override ;
    bool checkComp() override ;
    bool setValues(double Atime, double Adistance) override;
    bool increment() override;
    bool decrement() override ;
    string getValues()  override;
};


#endif //P4_TRIWORKOUT_H


// implementation invariants :
// same date is applied to all objects to show the functionality
// of objects but can be changed by client's request.
// virtual functions are overwritten to suit client's
//  expectation's of triworkout objects