#include <iostream>

#ifdef __APPLE__
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib")
#endif
using namespace std;

//float a = 40.0; // متغیر گلوبال
//// تابع برای رسم خطوط برای y^2 = 4ax.
//void sahmi_dahane_rast() {
//    glBegin(GL_LINE_STRIP);
//    for (float y = -50.0; y <= 50.0; y++) {
//        float x =y * y / (4.0 * a);
//        glColor3f(0.65, 0.1, 0.6); // تنظیم رنگ
//        glVertex3f(x, y, 0.0);
//    }
//    glEnd();
//}
//
//// تابع برای رسم خطوط برای y^2 = 4ax (با چرخش 90 درجه).
//void sahmi_dahane_chap() {
//    glBegin(GL_LINE_STRIP);
//    for (float y = -70.0; y <= 70.0; y++) {
//        float x = y * y / (-4.0 * a);
//        glColor3f(1.0, 0.0, 0.0); // تنظیم رنگ
//        glVertex3f(x, y, 0.0);
//    }
//    glEnd();
//}

// تابع رسم اصلی.
void drawScene(void) {
    int numPoints = 200; // تعداد نقاط
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // تنظیم رنگ
    // رسم تابع مربعی اول: ax^2 + bx + c.
    glBegin(GL_LINE_STRIP);
    for (int i = -numPoints; i <= numPoints; ++i) {
        float x = i + 50.0 * (float)i / numPoints;
        float y = 1.0 * x * x - 69; // معادله منحنی اول
        glVertex3f(x, y, 0.0);
    }
    glEnd();

    // رسم تابع مربعی دوم: -ax^2 + bx + c.
    glBegin(GL_LINE_STRIP);
    for (int i = -numPoints; i <= numPoints; ++i) {
        float x = i + 50.0 * (float)i / numPoints;
        float y = -1.0 * x * x + 69; // معادله منحنی دوم (a = -1)
        glColor3f(0.0, 0.9, 0.0);
        glVertex3f(x, y, 0.0);
    }
    glEnd();

    // سهمی با دهانه به سمت راست 
    glBegin(GL_LINE_STRIP);
    for (int i = -numPoints; i <= numPoints; ++i) {
        float y = i + 50.0 * (float)i / numPoints;
        float x = 0.0095 * y * y - 14; // معادله منحنی دوم (a = -1)
        glColor3f(0.4, 0.5, 0.5);
        glVertex3f(x, y, 0.0);
    }
    glEnd();

    // سهمی با دهانه به سمت چپ 
    glBegin(GL_LINE_STRIP);
    for (int i = -numPoints; i <= numPoints; ++i) {
        float y = i + 50.0 * (float)i / numPoints;
        float x = -0.0095 * y * y + 14; // معادله منحنی دوم (a = -1)
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(x, y, 0.0);
    }
    glEnd();

    //// رسم پارابولای سوم: y^2 = 4ax.
    //sahmi_dahane_rast();
    //sahmi_dahane_chap();
    glFlush();
}

// تابع مقدماتی.
void setup(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0); // تنظیم رنگ پس زمینه
}

// تابع تغییر اندازه پنجره OpenGL.
void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-15, 15, -70.0, 70.0, -1.0, 1.0); // تنظیم حجم نمایش
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// تابع اصلی.
int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("sahmi 4 tarafe");


    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutMainLoop();
    return 0;
}
