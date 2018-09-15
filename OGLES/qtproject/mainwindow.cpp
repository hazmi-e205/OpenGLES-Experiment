#include "mainwindow.h"
#include "../Sources/Mystic.h"

MainWindow::MainWindow(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::initializeGL()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void MainWindow::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void MainWindow::paintGL()
{

}

void MainWindow::resizeEvent(QResizeEvent *event)
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{

}
