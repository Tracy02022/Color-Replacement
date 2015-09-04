#pragma once
/**
 * Author:      Dr. S. Gothard
 * Date:        1/24/2011
 * Purpose:     Written for 2011 Fall CS 400/600 Project 4.
 * Description: Prints status information after regular intervals.
 */
//copy from my teahcer
#include <string>
using std::string;

#include <iostream>
using std::ostream;
using std::endl;

class TimelyStatus
{
   public:
      enum status {FIRST, MIDDLE, LAST};
      int interval;

      TimelyStatus (int, ostream &);
      void createBackspace (int);
      void printStatus (status, int) const;

   private:
      string backspace;
      ostream &out;
};

