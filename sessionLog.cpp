// Created by PARSA on 11/11/2022.
//

#include "sessionLog.h"
#include "workout.h"
#include "triWorkout.h"
#include "hiit.h"
#include "fitSet.h"
#include <iostream>
#include <sstream>
#include <random>

SessionLog ::SessionLog(int arrSize)
{
    if (arrSize > 0) {
        arr = new Workout*[arrSize];
        count = 0;
        size = arrSize;
        sessionValid = true ;
    }
}



void SessionLog ::copy(const SessionLog &src)
{
    size = src.size ;
    count = src.count ;
    arr = new Workout*[size] ;
    for (int i = 0 ; i < count ; i++)
        arr[i] = src.arr[i]->copy() ;
}



SessionLog ::SessionLog(const SessionLog& src)
{
    copy (src) ;
}



SessionLog& SessionLog :: operator=(const SessionLog& src)
{
    if(this == &src)
        return *this ;
    delete [] arr ;
    copy(src) ;
    return *this ;
}



SessionLog :: SessionLog(SessionLog&& src)
{
    size = src.size ;
    count = src.count ;
    sessionValid = src.sessionValid ;
    date = src.date ;
    arr = src.arr ;
    src.size = 0 ;
    src.count = 0 ;
    src.sessionValid = false ;
    src.date = "" ;
    src.arr = nullptr ;
}


SessionLog& SessionLog :: operator=(SessionLog&& src)
{
    swap(size, src.size) ;
    swap(count, src.count) ;
    swap(date, src.date) ;
    swap(sessionValid, src.sessionValid) ;
    swap(arr, src.arr) ;
    return *this ;
}


void SessionLog ::addSet(Workout* obj)
{
     if (sessionValid) {
         if (date == obj->getDate())
         {
             arr[count] = obj;
            count++;
         }

     }
}

//precondition : object is defined and is constructed
//PostCondition :
int SessionLog :: exists(Workout obj)
{
    for (int i=0 ; i < size ; i++)
    {
        if (obj.getValues() == arr[i]->getValues())
            return i;
    }
    return -1 ;
}


void SessionLog :: removeSet(Workout removeThis)
{
    if(sessionValid) {
        int i = exists(removeThis);
        if (i == -1)
            return;
        else {
          count -= 1 ;
          //          Workout* temp = arr[i] ;
          for (int j = i; j < count; j++)
            arr[j] = arr[j + 1] ;
          // g++ compiler does not allow this
          // and it leads to error but clion is fine
          // with it, this would not cause any problems
          // : delete temp ;
        }
    }
}


void SessionLog :: increaseSize()
{
    size *= 2;
    Workout** temp = new Workout*[size];
    for (int i = 0; i < count; i++)
    {
        temp[i] = arr[i]->copy() ;
    }
    delete [] arr ;
    arr = temp;
}

void SessionLog :: justDoIt()
{
    sessionValid = false ;
}


const string SessionLog :: shareSession()
{
    string toReturn = "";
    if (arr != nullptr) {
        for (int i = 0; i < count; i++) {
            string temp = arr[i]->getValues();
            toReturn += "\n\n" + temp;
        }
    }
    return toReturn;
}

void SessionLog :: buildSession(SessionLog newSession)
{
    if(sessionValid)
    {
        if(newSession.arr)
        {
            int newSize = newSession.size + size;
            while (size <= newSize)
                increaseSize();
            int i = 0;
            while (i < newSession.count)
                arr[count++] = newSession.arr[i++]->copy();
        }
    }
}


SessionLog :: ~SessionLog()
{
    delete [] arr ;
}

SessionLog& SessionLog :: operator+=(SessionLog& src)
{
buildSession(src) ;
return *this ;
}


SessionLog SessionLog :: operator+(const SessionLog& b)
{
    SessionLog newSession(b.size + size) ;
    if(arr)
    {
        for (int i = 0 ; i < count ; i++)
        {
            newSession.addSet(arr[i]->copy()) ;
        }
    }
    if(b.arr)
    {
        for (int j = 0 ; j < b.count ; j++)
        {
            newSession.addSet(b.arr[j]->copy()) ;
        }
    }
    return newSession ;
}

SessionLog& SessionLog :: operator++(int y)
{
    for(int i = 0 ; i < count ; i++)
    {
        arr[i]->increment() ;
    }
    return *this ;
}



SessionLog& SessionLog ::operator--(int y)
{
    for (int i; i < count; i++) {
        arr[i]->decrement();
    }
    return *this ;
}

