/*
See "version.h" for version info and copyright information
This file was last modified on 05.16.1999
*/

#ifndef COLORS_H
#define COLORS_H
#include "mousequeue.h"
#include "keyqueue.h"
#include "image.h"
#include<map>


class color {

	//friend ofstream & operator<<(ofstream&fOut, const color& clr); // overloading << operator to write color in file directly
	//friend ifstream & operator>>(ifstream&fIn,color & clr); // overloading >> operator to read color directly
private:
	string Color_Name; // added new paramerter as color name
	static  map<string, color *> Colors_map; // map colorsnames to its adresses
public:

	// Default constructor creates black
	color(unsigned char Red = 0, unsigned char Green = 0, unsigned char Blue = 0, string = "NULL");

	// Color components.  0 = no intensity, 255 = full intensity
	unsigned char ucRed;
	unsigned char ucGreen;
	unsigned char ucBlue;

	bool operator==(color b);
	bool operator!=(color b);

	string getColorName()const; // geting color name
	static color& getColorObject(const string& clr_name);// this func taking color name al big back aliasof object
};


#endif //COLOR_H

