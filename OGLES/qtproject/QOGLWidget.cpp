#include "QOGLWidget.h"
#include "Implement.h"

QOGLWidget::QOGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

QOGLWidget::~QOGLWidget()
{
}

void QOGLWidget::initializeGL()
{
    setDataDir("../app/src/main/assets");
    native_init();
    native_gl_init(this->width(), this->height());
}

void QOGLWidget::resizeGL(int w, int h)
{
}

void QOGLWidget::paintGL()
{
    native_gl_draw();
}

void QOGLWidget::resizeEvent(QResizeEvent *event)
{

}

void QOGLWidget::paintEvent(QPaintEvent *event)
{

}
