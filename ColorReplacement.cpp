//Ming Chen &Dongyu Li
/* copy teacher's methods to match this project
   readImage(),printChangedImage()
   and performRequestedModifications() 
   have been changed */

#include"stdafx.h"
#include "ColorReplacement.h"
ColorReplacement::ColorReplacement():width  (-1), height (-1), 
                                      status(50000, cout) {}
void ColorReplacement::skipCommentsSpaces () 
{
   string buffer;
   int ch = file.peek();
   while (ch == '#' || isspace(ch)) 
   {
      // ignore comment line
      if (ch == '#') getline (file, buffer);
      else
      {
         // ignore whitespace
         while (isspace(ch))
         {
            // skip character and check the next
            file.get();
            ch = file.peek();
         }
      }
      ch = file.peek();
   }
}

void ColorReplacement::fileFormatError ()
{
   cerr << "Incorrect file format" << endl;
}
bool ColorReplacement::isValidP6 ()
{
   int maxVal, ch;
   cout<<"Enter the input file name: "<<endl;
   // Get the name of the input file to read from.
   cin>>inputName ;
   file.open(inputName.c_str(), std::ios::in | std::ios::binary);
   // Check for failure
   if (file.fail()) return false;
   ch = file.get();
   if (toupper(ch) != 'P' || file.get() != '6') 
   {
      cerr << "Incorrect Magic Number" << endl;
      file.close();
      return false;
   }
   // Read in the width, height, and maximum value.
   if (!readInt (width) || !readInt (height) || !readInt (maxVal, 255)) 
   {
      file.close();
      return false;
   }
   status.createBackspace (height);
   // read in the single whitespace character
   ch = file.get();
   return true;
}
bool ColorReplacement::readInt (int &num)
{
   // skip any comments and spaces and read the number
   skipCommentsSpaces (); 
   file >> num;
   if (file.fail() || num < 1) 
   {
      fileFormatError();
      return false;
   }
   return true;
}
bool ColorReplacement::readInt (int &num, int max)
{
   bool wasSuccessful = readInt (num);
   if (wasSuccessful)
   {
      if (num <= max) return true;
      else
      {
         fileFormatError();
         return false;
      }
   }
   return wasSuccessful;
}

bool ColorReplacement::readImage ()
{ 
   cout << "Reading row ";
   status.printStatus (TimelyStatus::FIRST, 1);
   // read in the image data as Pixel objects
   for (int i = 0; !file.fail() && i < height * width; ++i)
   {      
	   pix.red = file.get();
	   pix.green = file.get();
	   pix.blue = file.get();			
	   Pixel *temp;
	   temp=T.insert(pix,T.GetNode(),T.GetD());
       status.printStatus (TimelyStatus::MIDDLE, i/width);
      //store the pointer of the pix in a vector
       pixelvector.push_back (temp);   
   }
   if (file.fail()) return false;
   status.printStatus (TimelyStatus::LAST, height);
   file.close();
   return true;
}

const string &ColorReplacement::inputFile (void) const
{
   return inputName;
}

bool ColorReplacement::printChangedImage (void)
{
   vector<Pixel *>::iterator iter;
   // Get the name to save the file to.
   cout<<"Enter the output file name: "<<endl;
   string outputName ;
   cin>>outputName;
   ofstream output (outputName, std::ios::out | std::ios::binary);
   if (output.fail() || width <= 0 || height <= 0) return false;
   output << "P6" << endl << width << " " << height << endl << "255" << endl;
   cout << "Printing row ";
   status.printStatus (TimelyStatus::FIRST, 1);
   // Print the image with status messages
   int i=0;
   for (iter= pixelvector.begin(); iter != pixelvector.end(); iter++)
   {
      output <<(*iter)->red<<(*iter)->green<<(* iter)->blue;
      status.printStatus (TimelyStatus::MIDDLE, i/width);
	  i++;
   }
   output << endl;
   output.close();
   status.printStatus (TimelyStatus::LAST, height);
   return true;
}
//Get the number of nodes and the heigh of the tree
void ColorReplacement::GetNumberandHeigh()
{
	cout<<"The number of nodes is : "<<T.GetNumNode()<<endl;
	cout<<"The height of the tree is : "<<T.GetHeight()<<endl;
}
// change teacher's method which has the same name to match this project
void ColorReplacement::performRequestedModifications ()
{
	cout<<"Do you want to change a color Y/N?"<<endl;
	cin>>n;	
	if(n=='Y'||n=='y')
	{
		do{
			cout<<"COLOR CHANGE:input 3 integers in the range [0, 255]"<<endl;
			cin>>n1>>n2>>n3;
			cout<<"Input the RANGE of color values "<<endl;
			cin>>range;
			cout<<"COLOR REPLACE:input 3 integers in the range [0, 255]"<<endl;
			cin>>n4>>n5>>n6;
			cout << "Finding now "<<endl;
			 oldpix.red=n1-48+'0'; 
			 oldpix.green=n2-48+'0';
			 oldpix.blue=n3-48+'0';
			 newpix.red=n4-48+'0'; 
			 newpix.green=n5-48+'0';
			 newpix.blue=n6-48+'0';
			 T.ChangeColor(oldpix,newpix,T.GetNode(),range);
			 cout<<T.GetChangedPixNum()<<" pixel(s) is(are) replaced"<<endl;
			 if(T.GetChangedPixNum()==0)
				{
					cout<<"Do you want to replace another color Y/N?"<<endl;
					cin>>n;
				}
		}while(T.GetChangedPixNum()==0&&(n=='Y'||n=='y'));
	}
}

ColorReplacement::~ColorReplacement(void)
{
}
