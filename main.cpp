#include <GL/glut.h>
#include <math.h>

void dibujaCuadro(){
    //CUADRADO blanco
    glColor3f(135.0/255.0,189.0/255.0,187.0/255.0);
    glBegin(GL_POLYGON);
    glVertex2f(394,138);
    glVertex2f(621,138);
    glVertex2f(621,364);
    glVertex2f(393,364);
    glEnd();
}
void dibujaCirculo(float cx, float cy, float r, float num_segments){//hecho con la ayuda de https://stackoverflow.com/questions/22444450/drawing-circle-with-opengl
    glColor3f(68.0/255.0,141.0/255.0,136.0/255.0);
    glLineWidth(50);
    glBegin(GL_LINE_LOOP);
    for(float ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * ii /num_segments;

        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void dibujaMedioCirculo(float cx, float cy, float r, float num_segments,float dir, bool vertical){
    glColor3f(68.0/255.0,141.0/255.0,136.0/255.0);
    glLineWidth(40.0);
    glBegin(GL_LINE_LOOP);
    for(float ii = 0; ii < num_segments; ii++)
    {
        float theta = dir*3.1415926f * ii /num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);

        if(vertical){
            float temp = x;
            x = y;
            y = temp;
        }
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void draw(){
    float matrizDeDibujo[][2] = {{508.0,192.0},//0: gran circulo central inferior
                                 {508.0,312.0},//1: gran circulo central superior
                                 {448.0,251.0},//2: gran circulo izquierdo
                                 {566.0,251.0},//3: gran circulo derecho
                                 {450.0,135.0},//4: medio circulo inferior izquierdo
                                 {567.0,135.0},//5: medio circulo inferior derecho
                                 {450.0,368.0},//6: medio circulo superior izquierdo
                                 {567.0,368.0},//7: medio circulo superior derecho
                                 {390.0,313.0},//8: medio circulo lateral izquierdo superior
                                 {390.0,198.0},//9: medio circulo lateral izquierdo inferior
                                 {624.0,313.0},//10: medio circulo lateral derecho superior
                                 {624.0,198.0},//11: medio circulo lateral derecho inferior
    };
    float radioCirculos = 62.0;
    float segmentosStdr = 100;

    glClear( GL_COLOR_BUFFER_BIT);
    dibujaCuadro();
    dibujaCirculo(matrizDeDibujo[0][0],matrizDeDibujo[0][1],radioCirculos,segmentosStdr);//central inferior
    dibujaCirculo(matrizDeDibujo[1][0],matrizDeDibujo[1][1],radioCirculos,segmentosStdr);//central superior
    dibujaCirculo(matrizDeDibujo[2][0],matrizDeDibujo[2][1],radioCirculos,segmentosStdr);//izquierdo
    dibujaCirculo(matrizDeDibujo[3][0],matrizDeDibujo[3][1],radioCirculos,segmentosStdr);//derecho
    dibujaMedioCirculo(matrizDeDibujo[4][0],matrizDeDibujo[4][1],radioCirculos,segmentosStdr,1.0,0);
    dibujaMedioCirculo(matrizDeDibujo[5][0],matrizDeDibujo[5][1],radioCirculos,segmentosStdr,1.0,0);
    dibujaMedioCirculo(matrizDeDibujo[6][0],matrizDeDibujo[6][1],radioCirculos,segmentosStdr,-1.0,0);
    dibujaMedioCirculo(matrizDeDibujo[7][0],matrizDeDibujo[7][1],radioCirculos,segmentosStdr,-1.0,0);
    dibujaMedioCirculo(matrizDeDibujo[8][0],matrizDeDibujo[8][1],radioCirculos,segmentosStdr,1.0,1);
    dibujaMedioCirculo(matrizDeDibujo[9][0],matrizDeDibujo[9][1],radioCirculos,segmentosStdr,1.0,1);
    dibujaMedioCirculo(matrizDeDibujo[10][0],matrizDeDibujo[10][1],radioCirculos,segmentosStdr,-1.0,1);
    dibujaMedioCirculo(matrizDeDibujo[11][0],matrizDeDibujo[11][1],radioCirculos,segmentosStdr,-1.0,1);


    glFlush();
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(1024,512);
    glutCreateWindow ("miniproyecto1");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1024.0, 0.0, 512.0);

    glutDisplayFunc(draw);
    glutMainLoop();

    return 0;
}