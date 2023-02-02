//Parsa Rahimiderimi
//11/13/2022
//PA4.cpp
// overview : this program demonstrates the use
//     of operators in sessionLog and Workout classes




#include <iostream>
#include "sessionLog.h"
#include "workout.h"
#include "triWorkout.h"
#include "hiit.h"
#include "fitSet.h"
#include <fstream>
#include <vector>
#include <memory>

#include <random>
//used in pa3 to demonstrate sessionLog objects but im using files insted
//  in PA4
void addTriSets(SessionLog& obj) ;
void addHiit(SessionLog& obj) ;
ostream& addFitSetToFile(ofstream& os) ;
ostream& addHiitToFile(ofstream& os) ;
ostream& addTriSetsToFile(ofstream& os) ;




//random number generator.
int random(int low, int high)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(low, high);
    return dist(gen);
}

string randomFile(int) ;

int main()
{
    vector<SessionLog> newVector ; // using std type : vectors
    unique_ptr<vector<SessionLog>> vec ;//using unique ptr
    shared_ptr<vector<SessionLog>> vect ;// using shareptr
    SessionLog obj1(10) ;
    SessionLog obj2(10) ;
    string fileName = "session2.txt"  ;
    ifstream input1  ;
    input1.open(fileName)  ;
    input1 >> obj1 ;
    input1.close() ;
    string fileName2 = "session4.txt" ;
    input1.open(fileName2) ;
    input1 >> obj2 ;
    SessionLog obj3 ;
    obj3 = obj1 + obj2 ;
    cout << obj3 ;
    ofstream output1 ;
    string fname3 = "new.txt" ;
    output1.open(fname3) ;
    output1 << obj3 ; // storing values in another file.
    output1.close() ;
    input1.open(fileName2) ;
    obj2++ ; // reading from files and increasing targer metrics.
    cout << obj2 ;
    obj1 += obj2 ; // extra feature : += operator that adds the second object
    //               to the end of the first object
    cout << obj1 ;
    
    
    return 0 ;
}

void addTriSets(SessionLog& obj)
{
    string arr[3] = { "running", "cycling", "swimming" };
    int rndInt = random(0,2) ;
    string newName = arr[rndInt];
    TriWorkout* TriObj= new TriWorkout(newName, random(1,100), random(1,120), random(1,8));
    TriObj->setValues(random(1,100), random(1,120));
    obj.addSet(TriObj);
}


void addHiit(SessionLog& obj)
{
    string arr[5] = { "jumping jacks", "box-jumps", "burpees", "a", "b" };
    int rndInt = random(0,4) ;
    string newName = arr[rndInt];
    Hiit* HiitObj = new Hiit(newName, random(1, 100), random(1,120), random(1,8)) ;
    HiitObj->setValues(random(1,100), random(1, 120), random(1,8)) ;
    obj.addSet(HiitObj) ;
}





istream &operator>>(istream& in, SessionLog &dt) {
    int temp;
    in >> temp ;
    string type ;
    string cat ;
    string namee;
    double weightt ;
    int reps;
    double interval;
    double resTTime;
    double distancee ;
    for (int i = 0 ; i < temp ; i++)
    {
        in >> type ;
        if (type == "HIIT")
        {
            in >> namee >> reps >> interval >> resTTime ;
            Hiit *Hiitptr = new Hiit(namee, interval, resTTime,reps);
            //random values for completed atributes since they are not
            //  given by the client.
            Hiitptr->setValues(random(1,20),random(1,10), random(1,8)) ;
            dt.addSet(Hiitptr);
        }
        if (type == "TriWorkout") {
            in >> namee >> interval >> distancee;
            // random value for target pace since it's not given
            TriWorkout *triPtr = new TriWorkout(namee, interval, distancee, random(1,3));
            //random values for performed times since they are not given by client
            triPtr->setValues(random(1,5), random(1,2));
            dt.addSet(triPtr);
        }
        if(type == "FitSet")
        {
            in >> namee >> cat >> weightt >> reps ;
            FitSet *Fitptr = new FitSet(namee, cat, weightt, reps) ;
            //random values for performed reps and weight since they are not given by client
            Fitptr->setValues(random(1,12), random(1,20)) ;
            dt.addSet(Fitptr) ;
        }
    }
    return in ;
}

ostream& operator<<(ostream& os, const SessionLog& dt)
{
    os << "\n\n\n::::::SessionLog::::" ;
    string toWrite = "" ;
    os << "\n" << dt.count << "\n" ;
    for (int i = 0; i < dt.count; i++) {
        string temp = dt.arr[i]->getValues();
        toWrite += "\n\n" + temp;
    }
    os << toWrite ;
    return os ;
}
