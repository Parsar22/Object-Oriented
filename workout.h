// Workout.h
// Created by PARSA on 11/11/2022.
// class invariants
// class invariant : class workout is the parent for subtype workouts,
// FitSet,TriWorkout, and Hiit workouts, name and date and other private and public
// attributes of Workout is inherited by the child classes
//
// interface invariant :
// workout offers different functionalities to observe the score,
//      completeness, date and name and other specific
//      information about each workout, also there are three
//      different subtypes that client can use to store their workouts
//      at while the workout is valid and is done on the same date as the session
//      the workouts are stored in.

#include <string>
#ifndef P4_WORKOUT_H
#define P4_WORKOUT_H


using namespace std ;
class Workout
{
protected :
    string name ;
    bool completed ;
    bool valid = true ;
    string date  ;
    void switchValid() ;
public:
    //default Constructor
    Workout() {} ;
    //constructor
    Workout(string eName) ;
    // precondition : some attributes of workout object
    //               are not initialized however the object
    //               is constructed .
    // postcondition : once these objects are  initialized
    //                 these attributes can not be changed
    //                 and only some operators can
    //                 change the target metrics even tho
    //                 the object is invalid.
    virtual bool setValues(double a, double b) ;
    // preconditino : object is constructed and needed attributed are
    //                initialized.
    // PostCondition : return the percent workout done, no change to the function
    virtual double percent();
    // preconditino : object is constructed and needed attributed are
    //                initialized.
    // PostCondition : return the Score workout done, no change to the function
    virtual double Score() ;
    // precondition : na
    // postcondition : na, returns bool true or false.
    bool isValid() ;
    // preconditon : object is constructed
    // postcondition : returns a string with information of workouts,
    //                 no change to the object.
    virtual string getValues() ;
    string getDate() ;
    // precondition : object is constructed
    // postcondition : makes a copy of
    //                 the object and return it.
    // explanation : this method is needed to
    //              prevent memory leak , while copying a sessionLog
    //              and identified each subtype to copy the correct values.
    virtual Workout* copy(){return nullptr ;} ;
    virtual bool checkComp() ;
    // explanation : this method is needed to
    //              identify each subtype and increment the
    //              correct values for sessionLog operators
    virtual bool increment() { return false;}
    // explanation : this method is needed to
    //              identify each subtype and decrements the
    //              correct values for sessionLog operators
    virtual bool decrement() { return false;}
};



#endif //P4_WORKOUT_H

//Implementation invariants : for showcase
//   some contractual decisions have been made.
//   such as a global date with each workout so they
//   can all be added to the same session to test the session objects
//   virtual functions to appropriately edit each subtype or at some
//   situations identify one subtype from another such as copy() or
//   increment and decrement. copy will act as a copy constructor and
//    for that reason I decided to not include a copy constructor
//   or assignment operator.
//   theres also no dynamic memory allocation in workout, so no destructor was needed.

