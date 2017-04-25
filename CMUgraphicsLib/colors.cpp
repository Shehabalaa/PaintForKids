#include"colors.h"
#include <fstream>

map <string ,color *> color::Colors_map;

color::color(unsigned char Red , unsigned char Green , unsigned char Blue , string Name):Color_Name(Name)
{
	ucRed = Red;  ucGreen = Green;  ucBlue = Blue;
	if (Name!= "" && Name != "NULL")
		Colors_map[Name]=this;
}


bool color::operator==(color b)
{
	return (ucRed == b.ucRed && ucBlue == b.ucBlue && ucGreen == b.ucGreen);
}

bool color::operator!=(color b)
{
	return !(ucRed == b.ucRed && ucBlue == b.ucBlue && ucGreen == b.ucGreen);
}

string color::getColorName()const // geting color name
{
	return Color_Name;
}
color& color::getColorObject(const string& clr_name)   // this static func taking color name al big back aliasof object
{
	return *(Colors_map[clr_name]);
}

/*
ofstream & operator<<(ofstream&fOut, const color & clr)
{
	fOut << clr.Color_Name;
	return fOut;
}

ifstream & operator >> (ifstream& fIn, color & clr)
{
	string clr_name;
	fIn >> clr_name;
	clr = *color::Colors_map[clr_name];
	return fIn;
}

*/
