#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int x00,y00,x11,y11;

void drawLine(){
    float pk,yi,xi,dy,dx,x,y;
    int i;
    dx=x11-x00;
    dy=y11-y00;
    x=x00;
    y=y00;
    glBegin(GL_POINTS);
    glColor3f(0.0,1.0,0.0);
    glVertex2i(fabs(x),fabs(y));
    glEnd();

    if(fabs(dx)>fabs(dy)){
        if(dx>0){
            xi=1;
        }
        else
        {
            xi=-1;
        }
        if (dy>0)
        {
            yi=1;
        }
        else
        {
            yi=-1;
        }
        pk = 2*fabs(dy)-fabs(dx);
        for(i=0;i<fabs(dx);i++){
            if (pk>0)
            {
                y+=yi;
                pk += 2*fabs(dy) - 2*fabs(dx);
            }
            else
            {
                pk+=2*fabs(dy);
            }
            x+=xi;
            glBegin(GL_POINTS);
            glColor3f(0.0,1.0,0.0);
            glVertex2i(fabs(x),fabs(y));
            glEnd();
        }
    }
    else
    {
        if(dx>0){
            xi=1;
        }
        else
        {
            xi=-1;
        }
        if (dy>0)
        {
            yi=1;
        }
        else
        {
            yi=-1;
        }
        pk = 2*fabs(dx)-fabs(dy);
        for(i=0;i<fabs(dy);i++){
            if (pk>0)
            {
                x+=xi;
                pk += 2*fabs(dx) - 2*fabs(dy);
            }
            else
            {
                pk+=2*fabs(dx);
            }
            y+=yi;
            glBegin(GL_POINTS);
            glColor3f(0.0,1.0,0.0);
            glVertex2i(fabs(x),fabs(y));
            glEnd();
        }
    }
    
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0.0);
    drawLine();
    glFlush();
}

void myinit(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
    glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char *argv[]){
    glutInit(&argc,argv);
    printf("Enter x00,y00,x11,y11:\n");
    scanf("%d%d%d%d",&x00,&y00,&x11,&y11);
    glutCreateWindow("Bresenshams Line Drawing Algo");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    
}