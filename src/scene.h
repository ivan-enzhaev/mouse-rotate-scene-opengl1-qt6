#ifndef SCENE_H
#define SCENE_H

#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QPoint>
#include <QWheelEvent>

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>

class Scene : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit Scene(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    void scalePlus();
    void scaleMinus();

    GLfloat m_xRotation;
    GLfloat m_yRotation;
    GLfloat m_zRotation;
    GLfloat m_scale;
    GLfloat m_zTranslation;
    QPoint m_mousePosition;
};

#endif // SCENE_H
