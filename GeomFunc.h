/** File:		GeomFunc.h
 ** Author:		Dongli Zhang
 ** Contact:	dongli.zhang0129@gmail.com
 **
 ** Copyright (C) Dongli Zhang 2013
 **
 ** This program is free software;  you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation; either version 2 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY;  without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 ** the GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program;  if not, write to the Free Software 
 ** Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */


#ifndef __GEOMFUNC_H__
#define __GEOMFUNC_H__

#include "Vector2D.h"
#include <stdio.h>

class GeomFunc
{
public:
	enum {LEFT=0, RIGHT, MIDDLE, OTHER};

public:
	static int turnDirTest(Vec2f& v1, Vec2f& v2, Vec2f& v3);
};

int GeomFunc::turnDirTest(Vec2f& v1, Vec2f& v2, Vec2f& v3)
{
	Vec2f P31 = v3 - v1;
	Vec2f P21 = v2 - v1;
	float dotProduct = P31.Cross(P21);
	if(dotProduct < 0.0f) return LEFT;
	else if(dotProduct > 0.0f) return RIGHT;
	else return MIDDLE;
}

#endif
