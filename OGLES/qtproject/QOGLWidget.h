#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>

class QOGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    QOGLWidget(QWidget *parent = 0);
    ~QOGLWidget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
