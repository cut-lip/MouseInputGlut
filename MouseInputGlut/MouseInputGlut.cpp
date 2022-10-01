#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <iostream>
#include <GL/glut.h>

GLfloat t = 0;

void init()
{
    glClearColor(0, 1, 0, 0);
    glMatrixMode(GL_MODELVIEW);
    glOrtho(-100, 100, -100, 100, -10, 10);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(t, 0, 0);
    glutSolidSphere(10, 20, 20);
    glFlush();

}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        t += -5;
    }
    else if (button == GLUT_RIGHT_BUTTON)
    {
        t += 5;
    }
    else
    {

    }

    glutPostRedisplay();

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(1100, 650);
    glutCreateWindow("Mouse event handling");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

}

