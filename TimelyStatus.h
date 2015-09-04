#pragma once

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

