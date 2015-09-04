// project3.cpp : Defines the entry point for the console application.
//
//Dongyu Li
#include "stdafx.h"
#include"ColorReplacement.h"

//Dongyu Li
int _tmain(int argc, _TCHAR* argv[])
{
   ColorReplacement processor;

   if (!processor.isValidP6 () || !processor.readImage ())
   {
      cerr << "Error reading image \"" << processor.inputFile() 
             << "\"." << endl;
      return EXIT_FAILURE;
   }
   processor.GetNumberandHeigh();
   processor.performRequestedModifications();
   if (!processor.printChangedImage ())
   {
      cerr << "Unable to create output image." << endl;
      return EXIT_FAILURE;
   }

   cout << "Output image created." << endl;
   return EXIT_SUCCESS;
	return 0;
}

