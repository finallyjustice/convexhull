/** File:		MyCanvasWidget.cpp
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


#include "MyCanvasWidget.h"
#include "MainWindow.h"

MyCanvasWidget::MyCanvasWidget(QWidget *parent)
	: QGLWidget(parent)
{
	setFormat(QGLFormat(QGL::DoubleBuffer));
	setFocusPolicy(Qt::StrongFocus);
	setMouseTracking(true);

	drawW = 100.0f;
	drawH = 100.0f;
}

void MyCanvasWidget::initializeGL()
{
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluOrtho2D(0.0f, drawW, 0.0f, drawH);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
}

void MyCanvasWidget::resizeGL(int width, int height)
{
	winW=width;
	winH=height;
	glViewport(0, 0, winW, winH);
}

void MyCanvasWidget::paintGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.2f, 0.2f, 0.8f);
	glPointSize(6.0f);

	PointSet *ps = mw->getPointSet();
	glBegin(GL_POINTS);
		for(vector<Vec2f>::size_type i=0; i<ps->inSet.size(); i++)
		{
			glVertex2f(ps->inSet[i].x, ps->inSet[i].y);
		}
	glEnd();
	if(ps->setType == PointSet::OUTPUT)
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_POINTS);
			for(vector<int>::size_type i=0; i<ps->outSet.size(); i++)
			{
				glVertex2f(ps->inSet[ps->outSet[i]].x, ps->inSet[ps->outSet[i]].y);
			}
		glEnd();
		glColor3f(0.3f, 0.3f, 0.3f);
		glBegin(GL_LINE_LOOP);
			for(vector<int>::size_type i=0; i<ps->outSet.size(); i++)
			{
				glVertex2f(ps->inSet[ps->outSet[i]].x, ps->inSet[ps->outSet[i]].y);
			}
		glEnd();
	}
}

void MyCanvasWidget::mouseMoveEvent(QMouseEvent *event)
{
	int x = event->x();
	int y = event->y();
	float xPos = (float)x/winW*drawW;
	float yPos = (float)(winH-y)/winH*drawH;
	emit canvasMouseMove(Vec2f(xPos, yPos));
}

void MyCanvasWidget::mousePressEvent(QMouseEvent *event)
{
	if(event->button() == Qt::LeftButton)
	{
		int x = event->x();
		int y = event->y();

		float xPos = (float)x/winW*drawW;
		float yPos = (float)(winH-y)/winH*drawH;

		emit canvasAddPoint(Vec2f(xPos, yPos));
	}
}
