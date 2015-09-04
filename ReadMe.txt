1.	Find a partner to work with. You will fit best with someone you perceive to be your equal who has the same goals for the course. Email the instructor once you have found someone.
2.	Create a 3D KD Tree that stores pixel colors. 
o	The first level of the KD tree is sorted by the red channel, the second level by the green channel, the third level by the blue channel, the fourth by the red channel, the fifth by the green channel, etc.
o	The KD tree must have an insert method that inserts a new color only if the color is not already in the tree. In either case, the insert method returns the address of the color in the KD tree.
o	The KD tree must have a replace method that replaces a specified color with a provided color.
o	The KD tree must have a destructor that correctly deallocates all memory dynamically allocated by the KD Tree.
o	The KD Tree must have a method to return the height of the tree and a method to return the number of nodes in the tree. I recommend recursively computing these.
3.	Prompt the user for the input file name.
4.	Open the image file, and read the image header and store the dimensions of the image.
5.	Read the image data. Insert each pixel color from the image file into the 3D-KD Tree. Store the pointers returned by the insert method in order in a collection.
6.	As you are reading and storing the image, print status messages at least once every 5 seconds. These messages can be the current row being read, for example.
7.	Allow the user to perform one color replacement: 
a.	Ask the user whether he/she wishes to replace a color.
b.	As long as the user responds with something that starts with a y (upper or lower case) or until a valid replacement has been made, 
i.	Prompt the user for 3 integers in the range [0, 255] representing the target color.
ii.	Read in the 3 integers.
iii.	Prompt for 3 more integers in the range [0, 255] for the replacement color.
iv.	Read in the 3 integers.
v.	Perform the replacement of the color.
vi.	Print the number of unique colors replaced. (Unless you do the extra credit, the number will be 0 or 1.)
vii.	If the number replaced was 0, ask whether to replace another color.
	Prompt the user for an output file name.
	Using the collection of color pointers, write the image data in PPM format to the specified file. The resulting image should look like the original, except for any color replacements done by the user.
	Print to standard out the number of nodes in the tree and the height of the tree, clearly identifying which is which.
