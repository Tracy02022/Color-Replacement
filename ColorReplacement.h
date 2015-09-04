//Ming Chen &Dongyu Li
/* copy teacher's methods to match this project
   readImage(),printChangedImage()
   and performRequestedModifications() 
   have been changed */
#pragma once

#include "StdAfx.h"
#include"TimelyStatus.h"
using std::cout;
using std::cin;
using std::cerr;
#include <cctype>
#include <fstream>
using std::ifstream;
using std::ofstream;
#include"KDTree.h"
#include<vector>

class ColorReplacement
{
private:
	 KDTree T;
	 Pixel pix,oldpix,newpix;;
	 vector<Pixel*> pixelvector; //store pix pointers
	 ifstream file;
	 int width, height;
     string inputName;
	 TimelyStatus status;
	 int range;
	 char n;
	 int n1,n2,n3,n4,n5,n6;
     static const int STATUS_INTERVAL = 50000;
     static void fileFormatError ();
     void skipCommentsSpaces ();
     bool readInt (int &);
     bool readInt (int &, int);
public:
	
	//add the data to let users input pix
	 ColorReplacement(void);
	 bool isValidP6 (void);
     bool readImage (void);
	 void GetNumberandHeigh(void);
     void performRequestedModifications (void);
     bool printChangedImage (void);
     const string &inputFile(void) const;
	~ColorReplacement(void);
};

