#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
using namespace std;

// función para trazar una línea utilizando el algoritmo de Bresenham
void bresenham(int x0, int y0, int x1, int y1) {
    // calcular las diferencias en x y y
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    // calcular las direcciones en x e y
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    // calcular el error inicial
    int error = dx - dy;

    // dibujar la línea punto por punto
    while (x0 != x1 || y0 != y1) {
        glBegin(GL_POINTS);
        glVertex2i(x0, y0);
        glEnd();

        int e2 = error * 2;

        if (e2 > -dy) {
            error -= dy;
            x0 += sx;
        }

        if (e2 < dx) {
            error += dx;
            y0 += sy;
        }
    }
}


// función para mostrar la ventana gráfica
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    // dibujar una línea utilizando el algoritmo de Bresenham
    bresenham(50, 10, 100, 300);
    glFlush();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Bresenham");
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
    glutMainLoop();
    return 0;
}