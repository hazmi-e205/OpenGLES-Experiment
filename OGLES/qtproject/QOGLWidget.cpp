#include "QOGLWidget.h"
#include "Mystic.h"

QOGLWidget::QOGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

QOGLWidget::~QOGLWidget()
{
}

void QOGLWidget::initializeGL()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void QOGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void QOGLWidget::paintGL()
{

}

void QOGLWidget::resizeEvent(QResizeEvent *event)
{

}

void QOGLWidget::paintEvent(QPaintEvent *event)
{

}
