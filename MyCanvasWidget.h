/** File:		MyCanvasWidget.h
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


#ifndef __MYCANVASWIDGET_H__
#define __MYCANVASWIDGET_H__

#include <QtOpenGL/QGLWidget>
#include <GL\glut.h>
#include <QtGui>
#include "Vector2D.h"

class MainWindow;

class MyCanvasWidget : public QGLWidget
{
	Q_OBJECT

private:
	int winW;
	int winH;
	float drawW;
	float drawH;
	MainWindow *mw;

public:
	MyCanvasWidget(QWidget *parent = 0);
	void setMainWindow(MainWindow *mw){ this->mw = mw; }

protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);

signals:
	void canvasMouseMove(Vec2f& p);
	void canvasAddPoint(Vec2f& p);
};

#endif
