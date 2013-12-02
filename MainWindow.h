/** File:		MainWindow.h
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


#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include "GeneratedFiles\ui_MainWindow.h"
#include "PointSet.h"
#include "ConvexHull.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT

private:
	PointSet *ps;

public:
	MainWindow();
	PointSet* getPointSet(){ return ps; }
	void updateNumLabel();
	void findConvexHull();

protected:
	void resizeEvent(QResizeEvent *e);

public slots:
	void setPosLabelValue(Vec2f& p);
	void addNewPoint(Vec2f& p);
	void clearPointSet();
	void showInput();
	void showOutput();
};

#endif
