/* 
See "version.h" for version info and copyright information
This file was last modified on 05.16.1999
*/

#ifndef COLORS_H
#define COLORS_H

#include "version.h"

#include<map>


class color {

//friend ofstream & operator<<(ofstream&fOut, const color& clr); // overloading << operator to write color in file directly
//friend ifstream & operator>>(ifstream&fIn,color & clr); // overloading >> operator to read color directly
private:
	
	string Color_Name; // added new paramerter as color name
	static map<string, color*> Colors_map; // map colorsnames to its adresses
public:
	
    // Default constructor creates black
	color(unsigned char Red = 0, unsigned char Green = 0, unsigned char Blue = 0, string Name = "abcd");


    // Color components.  0 = no intensity, 255 = full intensity
    unsigned char ucRed;
    unsigned char ucGreen;
    unsigned char ucBlue;

	bool operator==(color b);
	bool operator!=(color b);

	string getColorName()const; // geting color name
	color& getColorObject(const string& clr_name) const;// this func taking color name al big back aliasof object
};





/*

  Predefine some color objects...  Data was liberally borrowed from the
  Open Group's X11 rbg.txt file

  $XConsortium: rgb.txt,v 10.41 94/02/20 18:39:36 rws Exp 

*/

const color SNOW = color(255, 250, 250, "SNOW");
const color GHOSTWHITE = color(248, 248, 255, "GHOSTWHITE");
const color WHITESMOKE = color(245, 245, 245, "WHITESMOKE");
const color GAINSBORO = color(220, 220, 220, "GAINSBORO");
const color FLORALWHITE = color(255, 250, 240, "FLORALWHITE");
const color OLDLACE = color(253, 245, 230, "OLDLACE");
const color LINEN = color(250, 240, 230, "LINEN");
const color ANTIQUEWHITE = color(250, 235, 215, "ANTIQUEWHITE");
const color PAPAYAWHIP = color(255, 239, 213, "PAPAYAWHIP");
const color BLANCHEDALMOND = color(255, 235, 205, "BLANCHEDALMOND");
const color BISQUE = color(255, 228, 196, "BISQUE");
const color PEACHPUFF = color(255, 218, 185, "PEACHPUFF");
const color NAVAJOWHITE = color(255, 222, 173, "NAVAJOWHITE");
const color MOCCASIN = color(255, 228, 181, "MOCCASIN");
const color CORNSILK = color(255, 248, 220, "CORNSILK");
const color IVORY = color(255, 255, 240, "IVORY");
const color LEMONCHIFFON = color(255, 250, 205, "LEMONCHIFFON");
const color SEASHELL = color(255, 245, 238, "SEASHELL");
const color HONEYDEW = color(240, 255, 240, "HONEYDEW");
const color MINTCREAM = color(245, 255, 250, "MINTCREAM");
const color AZURE = color(240, 255, 255, "AZURE");
const color ALICEBLUE = color(240, 248, 255, "ALICEBLUE");
const color LAVENDER = color(230, 230, 250, "LAVENDER");
const color LAVENDERBLUSH = color(255, 240, 245, "LAVENDERBLUSH");
const color MISTYROSE = color(255, 228, 225, "MISTYROSE");
const color WHITE = color(255, 255, 255, "WHITE");
const color BLACK = color(0, 0, 0, "BLACK");
const color DARKSLATEGRAY = color(47, 79, 79, "DARKSLATEGRAY");
const color DARKSLATEGREY = color(47, 79, 79, "DARKSLATEGREY");
const color DIMGRAY = color(105, 105, 105, "DIMGRAY");
const color DIMGREY = color(105, 105, 105, "DIMGREY");
const color SLATEGRAY = color(112, 128, 144, "SLATEGRAY");
const color SLATEGREY = color(112, 128, 144, "SLATEGREY");
const color LIGHTSLATEGRAY = color(119, 136, 153, "LIGHTSLATEGRAY");
const color LIGHTSLATEGREY = color(119, 136, 153, "LIGHTSLATEGREY");
const color GRAY = color(190, 190, 190, "GRAY");
const color GREY = color(190, 190, 190, "GREY");
const color LIGHTGREY = color(211, 211, 211, "LIGHTGREY");
const color LIGHTGRAY = color(211, 211, 211, "LIGHTGRAY");
const color MIDNIGHTBLUE = color(25, 25, 112, "MIDNIGHTBLUE");
const color NAVY = color(0, 0, 128, "NAVY");
const color NAVYBLUE = color(0, 0, 128, "NAVYBLUE");
const color CORNFLOWERBLUE = color(100, 149, 237, "CORNFLOWERBLUE");
const color DARKSLATEBLUE = color(72, 61, 139, "DARKSLATEBLUE");
const color SLATEBLUE = color(106, 90, 205, "SLATEBLUE");
const color MEDIUMSLATEBLUE = color(123, 104, 238, "MEDIUMSLATEBLUE");
const color LIGHTSLATEBLUE = color(132, 112, 255, "LIGHTSLATEBLUE");
const color MEDIUMBLUE = color(0, 0, 205, "MEDIUMBLUE");
const color ROYALBLUE = color(65, 105, 225, "ROYALBLUE");
const color BLUE = color(0, 0, 255, "BLUE");
const color DODGERBLUE = color(30, 144, 255, "DODGERBLUE");
const color DEEPSKYBLUE = color(0, 191, 255, "DEEPSKYBLUE");
const color SKYBLUE = color(135, 206, 235, "SKYBLUE");
const color LIGHTSKYBLUE = color(135, 206, 250, "LIGHTSKYBLUE");
const color STEELBLUE = color(70, 130, 180, "STEELBLUE");
const color LIGHTSTEELBLUE = color(176, 196, 222, "LIGHTSTEELBLUE");
const color LIGHTBLUE = color(173, 216, 230, "LIGHTBLUE");
const color POWDERBLUE = color(176, 224, 230, "POWDERBLUE");
const color PALETURQUOISE = color(175, 238, 238, "PALETURQUOISE");
const color DARKTURQUOISE = color(0, 206, 209, "DARKTURQUOISE");
const color MEDIUMTURQUOISE = color(72, 209, 204, "MEDIUMTURQUOISE");
const color TURQUOISE = color(64, 224, 208, "TURQUOISE");
const color CYAN = color(0, 255, 255, "CYAN");
const color LIGHTCYAN = color(224, 255, 255, "LIGHTCYAN");
const color CADETBLUE = color(95, 158, 160, "CADETBLUE");
const color MEDIUMAQUAMARINE = color(102, 205, 170, "MEDIUMAQUAMARINE");
const color AQUAMARINE = color(127, 255, 212, "AQUAMARINE");
const color DARKGREEN = color(0, 100, 0, "DARKGREEN");
const color DARKOLIVEGREEN = color(85, 107, 47, "DARKOLIVEGREEN");
const color DARKSEAGREEN = color(143, 188, 143, "DARKSEAGREEN");
const color SEAGREEN = color(46, 139, 87, "SEAGREEN");
const color MEDIUMSEAGREEN = color(60, 179, 113, "MEDIUMSEAGREEN");
const color LIGHTSEAGREEN = color(32, 178, 170, "LIGHTSEAGREEN");
const color PALEGREEN = color(152, 251, 152, "PALEGREEN");
const color SPRINGGREEN = color(0, 255, 127, "SPRINGGREEN");
const color LAWNGREEN = color(124, 252, 0, "LAWNGREEN");
const color GREEN = color(0, 255, 0, "GREEN");
const color CHARTREUSE = color(127, 255, 0, "CHARTREUSE");
const color MEDIUMSPRINGGREEN = color(0, 250, 154, "MEDIUMSPRINGGREEN");
const color GREENYELLOW = color(173, 255, 47, "GREENYELLOW");
const color LIMEGREEN = color(50, 205, 50, "LIMEGREEN");
const color YELLOWGREEN = color(154, 205, 50, "YELLOWGREEN");
const color FORESTGREEN = color(34, 139, 34, "FORESTGREEN");
const color OLIVEDRAB = color(107, 142, 35, "OLIVEDRAB");
const color DARKKHAKI = color(189, 183, 107, "DARKKHAKI");
const color KHAKI = color(240, 230, 140, "KHAKI");
const color PALEGOLDENROD = color(238, 232, 170, "PALEGOLDENROD");
const color LIGHTGOLDENRODYELLOW = color(250, 250, 210, "LIGHTGOLDENRODYELLOW");
const color LIGHTYELLOW = color(255, 255, 224, "LIGHTYELLOW");
const color YELLOW = color(255, 255, 0, "YELLOW");
const color GOLD = color(255, 215, 0, "GOLD");
const color LIGHTGOLDENROD = color(238, 221, 130, "LIGHTGOLDENROD");
const color GOLDENROD = color(218, 165, 32, "GOLDENROD");
const color DARKGOLDENROD = color(184, 134, 11, "DARKGOLDENROD");
const color ROSYBROWN = color(188, 143, 143, "ROSYBROWN");
const color INDIAN = color(205, 92, 92, "INDIAN");
const color INDIANRED = color(205, 92, 92, "INDIANRED");
const color SADDLEBROWN = color(139, 69, 19, "SADDLEBROWN");
const color SIENNA = color(160, 82, 45, "SIENNA");
const color PERU = color(205, 133, 63, "PERU");
const color BURLYWOOD = color(222, 184, 135, "BURLYWOOD");
const color BEIGE = color(245, 245, 220, "BEIGE");
const color WHEAT = color(245, 222, 179, "WHEAT");
const color SANDYBROWN = color(244, 164, 96, "SANDYBROWN");
const color TAN = color(210, 180, 140, "TAN");
const color CHOCOLATE = color(210, 105, 30, "CHOCOLATE");
const color FIREBRICK = color(178, 34, 34, "FIREBRICK");
const color BROWN = color(165, 42, 42, "BROWN");
const color DARKSALMON = color(233, 150, 122, "DARKSALMON");
const color SALMON = color(250, 128, 114, "SALMON");
const color LIGHTSALMON = color(255, 160, 122, "LIGHTSALMON");
const color ORANGE = color(255, 165, 0, "ORANGE");
const color DARKORANGE = color(255, 140, 0, "DARKORANGE");
const color CORAL = color(255, 127, 80, "CORAL");
const color LIGHTCORAL = color(240, 128, 128, "LIGHTCORAL");
const color TOMATO = color(255, 99, 71, "TOMATO");
const color ORANGERED = color(255, 69, 0, "ORANGERED");
const color RED = color(255, 0, 0, "RED");
const color HOTPINK = color(255, 105, 180, "HOTPINK");
const color DEEPPINK = color(255, 20, 147, "DEEPPINK");
const color PINK = color(255, 192, 203, "PINK");
const color LIGHTPINK = color(255, 182, 193, "LIGHTPINK");
const color PALEVIOLETRED = color(219, 112, 147, "PALEVIOLETRED");
const color MAROON = color(176, 48, 96, "MAROON");
const color MEDIUMVIOLETRED = color(199, 21, 133, "MEDIUMVIOLETRED");
const color VIOLETRED = color(208, 32, 144, "VIOLETRED");
const color MAGENTA = color(255, 0, 255, "MAGENTA");
const color VIOLET = color(238, 130, 238, "VIOLET");
const color PLUM = color(221, 160, 221, "PLUM");
const color ORCHID = color(218, 112, 214, "ORCHID");
const color MEDIUMORCHID = color(186, 85, 211, "MEDIUMORCHID");
const color DARKORCHID = color(153, 50, 204, "DARKORCHID");
const color DARKVIOLET = color(148, 0, 211, "DARKVIOLET");
const color BLUEVIOLET = color(138, 43, 226, "BLUEVIOLET");
const color PURPLE = color(160, 32, 240, "PURPLE");
const color MEDIUMPURPLE = color(147, 112, 219, "MEDIUMPURPLE");
const color THISTLE = color(216, 191, 216, "THISTLE");
const color DARKGREY = color(169, 169, 169, "DARKGREY");
const color DARKGRAY = color(169, 169, 169, "DARKGRAY");
const color DARKBLUE = color(0, 0, 139, "DARKBLUE");
const color DARKCYAN = color(0, 139, 139, "DARKCYAN");
const color DARKMAGENTA = color(139, 0, 139, "DARKMAGENTA");
const color DARKRED = color(139, 0, 0, "DARKRED");
const color LIGHTGREEN = color(144, 238, 144, "LIGHTGREEN");


#endif //COLOR_H
