#include "scene.h"
#include <QDebug>

Scene::Scene(QWidget *parent)
    : QOpenGLWidget(parent)
    , m_xRotation(0.0f)
    , m_yRotation(0.0f)
    , m_zRotation(0.0f)
    , m_scale(1.0f)
    , m_zTranslation(0.0f)
{
}

void Scene::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0f, 1.0f, 1.0f);

    glScalef(m_scale, m_scale, m_scale);

    glTranslatef(0.0f, m_zTranslation, 0.0f);

    glRotatef(m_xRotation, 1.0f, 0.0f, 0.0f);
    glRotatef(m_yRotation, 0.0f, 1.0f, 0.0f);
    glRotatef(m_zRotation, 0.0f, 0.0f, 1.0f);

    // OpenGL 1.x quad
    glRectf(-25.5f, 25.5f, 25.5f, -25.5f);
}

void Scene::resizeGL(int w, int h)
{
    if (h == 0)
    {
        h = 1;
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat aspectRatio = static_cast<GLfloat>(w) / static_cast<GLfloat>(h);

    if (w <= h)
    {
        glOrtho(-100.0, 100.0,
            -100.0 / aspectRatio, 100.0 / aspectRatio,
            -100.0, 100.0);
    }
    else
    {
        glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio,
            -100.0, 100.0,
            -100.0, 100.0);
    }

    glViewport(0, 0, w, h);
}

void Scene::wheelEvent(QWheelEvent *event)
{
    // Qt 6 replacement for event->delta()
    int delta = event->angleDelta().y();
    if (delta > 0)
    {
        scalePlus();
    }
    else if (delta < 0)
    {
        scaleMinus();
    }

    update(); // Replaces updateGL()
}

void Scene::scalePlus()
{
    m_scale *= 1.1f;
}

void Scene::scaleMinus()
{
    m_scale /= 1.1f;
}

void Scene::mousePressEvent(QMouseEvent *event)
{
    m_mousePosition = event->pos();
}

void Scene::mouseMoveEvent(QMouseEvent *event)
{
    // Updated for Qt 6 position()
    m_xRotation += 180.0f / m_scale * static_cast<GLfloat>(event->position().y() - m_mousePosition.y()) / height();
    m_zRotation += 180.0f / m_scale * static_cast<GLfloat>(event->position().x() - m_mousePosition.x()) / width();

    m_mousePosition = event->pos();

    update();
}
