#include <windows.h>
#include <GL/freeglut.h>
#include <iostream>
#include <GL/gl.h>
#include "gui/gui.h"

#define NUM_DEVICES 16
#define NUM_CURSORS 64

using namespace std;

typedef struct cursor {
    char on;
    float x;
    float y;
} *Cursor;
struct cursor cursors[NUM_DEVICES][NUM_CURSORS];

void display(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

    // Draw a Red 1x1 Square centered at origin
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 1.0f, 1.0f); // Red
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
    glEnd();

    glFlush();  // Render now
}

void onMouse(int button, int state, int x, int y) {
    if (button == 0) {
        cursors[0][0].on = (state == GLUT_DOWN);
        cursors[0][0].x = (float)x;
        cursors[0][0].y = (float)y;
        cout<<"normal click\n";
    }
}

int main(int argc,char **argv){
    cout<<"Running...\n";

    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("Graphic User Interface"); // Create a window with the given title
    glutInitWindowSize(800, 600);   // Set the window's initial width & height
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMouseFunc(onMouse);
    glutMainLoop();

    return 0;
}
