/*
  Andrew Alagna
  November 9th, 2018
  Hunter College
  CSCI 135/136 Lab 10

  */

  #include <iostream>
  using namespace std;

  struct Time {
      int h;
      int m;
  }; //structs end in a semicolon

  void printTime(Time time) {
      cout << time.h << ":" << time.m;
  }

  //Time is the struct and time is the parameter
  //Task A

  int minutesSinceMidnight(Time time);
  bool test_minutesSinceMidnight();

  int minutesUntil(Time earlier, Time later);
  bool test_minutesUntil();


  int main() {

      cout << "TESTING_minutesSinceMidnight" << endl;
      bool resMinutesSinceMidnight = test_minutesSinceMidnight();//define booleon to run test

      cout << "TESTING_minutesUntil" << endl;
      bool resMinutesUntil = test_minutesUntil();

      if ((!resMinutesSinceMidnight)&&(!resMinutesUntil)){  //if result is not true
          cout << "FAILED_TESTS" << endl;
      } else {    //if result is true
          cout << "PASSED_TESTS" << endl;
      }

      cout << minutesSinceMidnight( {8,10} ) << endl;
      cout << minutesUntil( {8,10}, {8, 15} ) << endl;

  }

  int minutesSinceMidnight(Time time){
      //midnight = 0,0
      //time since midnight in h, m
      //mins = time.h*60 + time.m
      //return int minutes

      int mins = 0;
      mins = (time.h * 60) + time.m;
      return mins;
  }

  bool test_minutesSinceMidnight(){
      const int LEN=3;    //length of array = 3 bc we are testing three cases
      Time test_a[LEN]={{8,10},{12,00},{23,59}};
      int res[LEN] = {490, 720, 1439};
      bool pass = false;  //if one cases passes, it is false
      bool allpass = true;    //if all cases pass, it is ture
      for(int i=0; i<LEN; i++){ //iterate through each array
          pass = minutesSinceMidnight(test_a[i]) == res[i];
          allpass = allpass && pass;
          if(!pass){  //if there is an error, print it
              cout << "tIn:" << test_a[i].h << ":" << test_a[i].m
                   << "tResult" << minutesSinceMidnight(test_a[i])
                  << "texpected:" << res[i] << endl;
          }
      }
      return allpass; //return the value of all pass
  }

  int minutesUntil(Time earlier, Time later){
      //turn both times into minutes
      int earlierMins = minutesSinceMidnight(earlier);
      int laterMins = minutesSinceMidnight(later);
      int diff = 0;

      diff = laterMins - earlierMins;

      return diff;
  }

  bool test_minutesUntil(){
      const int LEN=3;    //length of array = 3 bc we are testing three cases
      Time test_a[LEN]={{8,10},{13,40},{10,30}};
      Time test_b[LEN]={{12,00},{10,30},{13,40}};
      int res[LEN] = {230, -190, 190};
      bool pass = false;  //if one cases passes, it is false
      bool allpass = true;    //if all cases pass, it is ture
      for(int i=0; i<LEN; i++){ //iterate through each array
          pass = minutesUntil(test_a[i], test_b[i]) == res[i];
          allpass = allpass && pass;
          if(!pass){  //if there is an error, print it
              cout << "ta:" << test_a[i].h << ":" << test_a[i].m
                  << "\ttb:" << test_b[i].h << ":" << test_b[i].m
                  << "\ntResult" << minutesUntil(test_a[i], test_b[i])
                  << "\ntexpected:" << res[i] << endl;
          }
      }
      return allpass; //return the value of all pass
  }
