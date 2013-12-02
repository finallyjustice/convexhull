/** File:		MainWindow.cpp
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


#include "MainWindow.h"

MainWindow::MainWindow()
{
	setupUi(this);
	setMinimumSize(750, 600);
	canvasWidget->setMainWindow(this);

	ps = new PointSet();
	updateNumLabel();

	QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(canvasWidget, SIGNAL(canvasMouseMove(Vec2f&)), this, SLOT(setPosLabelValue(Vec2f&)));
	QObject::connect(canvasWidget, SIGNAL(canvasAddPoint(Vec2f&)), this, SLOT(addNewPoint(Vec2f&)));
	QObject::connect(resetButton, SIGNAL(clicked()), this, SLOT(clearPointSet()));
	QObject::connect(showInputButton, SIGNAL(clicked()), this, SLOT(showInput()));
	QObject::connect(showSolutionButton, SIGNAL(clicked()), this, SLOT(showOutput()));
}

void MainWindow::updateNumLabel()
{
	QString numString;
	numString.sprintf("Total PointS: %d", ps->inSet.size());
	pnumLabel->setText(numString);
}

void MainWindow::findConvexHull()
{
	ConvexHull ch;
	ch.setPS(ps);
	ch.compConvexHull();
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
	int sizeX = centralWidget()->width()-canvasWidget->pos().x();
	int sizeY = centralWidget()->height()-canvasWidget->pos().y();
	if(sizeX >= sizeY) sizeX = sizeY;
	else sizeY = sizeX;
	canvasWidget->resize(sizeX, sizeY);
}

void MainWindow::setPosLabelValue(Vec2f& p)
{
	QString xString;
	QString yString;
	xString.sprintf("X: %f", p.x);
	yString.sprintf("Y: %f", p.y);
	xPosLabel->setText(xString);
	yPosLabel->setText(yString);
}

void MainWindow::addNewPoint(Vec2f& p)
{
	if(addPointButton->isChecked())
	{
		Vec2f point = p;
		ps->inSet.push_back(point);
		updateNumLabel();
		canvasWidget->updateGL();
	}
}

void MainWindow::clearPointSet()
{
	ps->inSet.clear();
	ps->outSet.clear();
	updateNumLabel();
	canvasWidget->updateGL();
}

void MainWindow::showInput()
{
	ps->setType = PointSet::INPUT;
	canvasWidget->updateGL();
}

void MainWindow::showOutput()
{
	findConvexHull();
	ps->setType = PointSet::OUTPUT;
	canvasWidget->updateGL();
}
