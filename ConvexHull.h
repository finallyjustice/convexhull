/** File:		ConvexHull.h
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


#ifndef __CONVEXHULL_H__
#define __CONVEXHULL_H__

#include "PointSet.h"

class Edge
{
public:
	int v[2];
	bool used;
public:
	Edge(){ used = false; }
	Edge(int v1, int v2){ v[0]=v1; v[1]=v2; used=false; }
};

class ConvexHull
{
private:
	PointSet *ps;

public:
	void setPS(PointSet *ps){ this->ps = ps; }
	void compConvexHull();
};

#endif
