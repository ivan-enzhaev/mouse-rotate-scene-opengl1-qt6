#include "scene.h"
#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
    // Must be CompatibilityProfile for OpenGL 1.x fixed-function calls
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(1, 1);
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    QApplication a(argc, argv);

    Scene scene;
    scene.setWindowTitle("Qt 6 - OpenGL 1.1 Fixed-Function Scene");
    scene.resize(800, 600);
    scene.show();

    return a.exec();
}
