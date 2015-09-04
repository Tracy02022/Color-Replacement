#include "StdAfx.h"
#include "TimelyStatus.h"
//copy from my teahcer

/**
 * Author:      Dr. S. Gothard
 * Date:        1/24/2011
 * Purpose:     Written for 2011 Fall CS 400/600 Project 4.
 * Description: Prints status information after regular intervals.
 */

/**
 * Sets the interval and output loation
 */
TimelyStatus::TimelyStatus (int i, ostream &os) : interval (i), out (os) {}

/**
 * Counts the number of digits that the print will need
 */
void TimelyStatus::createBackspace (int max)
{
   backspace = "";
   while (max > 0)
   {
      max /= 10;
      backspace += "\b";
   }
}

/**
 * Prints the current number at the defined interval.
 */
void TimelyStatus::printStatus (status stat, int number) const
{
   static int count = 0;
   ++count;

   if (stat == FIRST)
   {
      out.width (backspace.length());
      out << number;
      out.flush();
   }
   else if (count >= interval || stat == LAST)
   {
      out << backspace;
      out.width (backspace.length());
      out << number;
      out.flush();
      count = 0;
      if (stat == LAST) out << endl;
   }
}



