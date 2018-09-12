//****** Real Bit Level Boolean Utilisation Macro Definitions  ***********
//****** Created by Trevor D.BEYDAG 09 May 2016                ***********
//****** http://lab.dejaworks.com                              ***********
//****** Please keep credits intact when using and/or reproducing ********
//************************************************************************
#ifndef BITBOOL_H
#define BITBOOL_H

#define BB_TRUE(bp,bb)    bp |= bb
#define BB_FALSE(bp,bb)   bp &= ~(bb)
#define BB_READ(bp,bb)    bool(bp & bb)

#define BB_0 1
#define BB_1 2
#define BB_2 4
#define BB_3 8
#define BB_4 16
#define BB_5 32
#define BB_6 64
#define BB_7 128

inline void BB_SET(byte bp,byte bb, byte d)
{
	if(d == true)
	{
		BB_TRUE(bp,bb);
	}
	else
	{
		BB_FALSE(bp,bb);
	}
}

#endif