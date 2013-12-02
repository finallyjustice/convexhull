/** File:		ConvexHull.cpp
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


#include "ConvexHull.h"
#include "GeomFunc.h"

void ConvexHull::compConvexHull()
{
	int flag;
	int tmpFlag;
	int useEdge;
	vector<Edge> edgeSet;

	for(vector<Vec2f>::size_type i=0; i<ps->inSet.size(); i++)
	{
		for(vector<Vec2f>::size_type j=i+1; j<ps->inSet.size(); j++)
		{
			flag = GeomFunc::OTHER;
			useEdge = 1;
			for(vector<Vec2f>::size_type k=0; k<ps->inSet.size(); k++)
			{
				if(k==i || k==j) continue;

				tmpFlag = GeomFunc::turnDirTest(ps->inSet[i], ps->inSet[j], ps->inSet[k]);
				if(tmpFlag == GeomFunc::MIDDLE) continue;
				if(flag == GeomFunc::OTHER)
				{
					flag = tmpFlag;
				}
				else
				{
					if(flag != tmpFlag)
					{
						useEdge = 0;
						break;
					}
				}
			}
			if(useEdge == 1)
			{
				edgeSet.push_back(Edge(i, j));
			}
		}
	}

	ps->outSet.clear();
	if(edgeSet.size() != 0) 
	{
		int ni;
		int nv;
		ni = 0;
		ps->outSet.push_back(edgeSet[ni].v[0]);
		nv = edgeSet[ni].v[1];

		while(edgeSet[ni].used == false)
		{
			edgeSet[ni].used = true;
			ps->outSet.push_back(nv);
			for(int i=0; i<edgeSet.size(); i++)
			{
				if(i == ni) continue;
				if(edgeSet[i].v[0] == nv)
				{
					nv = edgeSet[i].v[1];
					ni = i;
					break;
				}
				if(edgeSet[i].v[1] == nv)
				{
					nv = edgeSet[i].v[0];
					ni = i;
					break;
				}
			}
		}
	}
}
