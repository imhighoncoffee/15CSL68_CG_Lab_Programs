#include<GL/glut.h>
#include<stdio.h>

void draw_tri(float *a,float *b,float *c){

	glBegin(GL_TRIANGLES);
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
	glEnd();
	
}

void display(){

	float v[3][2] = {{-80,20},{-20,20},{-40,60}};
	glColor3f(1,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	draw_tri(v[0],v[1],v[2]);
	
	glPushMatrix();
	glColor3f(0,1,0);
	glRotatef(180,0,0,1);
	draw_tri(v[0],v[1],v[2]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20,20,0);
	glRotatef(90,0,0,1);
	glTranslatef(20,-20,0);
	glColor3f(0,0,1);
	draw_tri(v[0],v[1],v[2]);
	glPopMatrix();

	int i ;
	glColor3f(0,1,0);
	glRasterPos2i(-60,-70);
	
	char a[50] = "Rotated about origin ";

	for(i=0;i<50;i++){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,a[i]);
	}
	glRasterPos2i(-1,10);
	
	char b[50] = "Rotated About fixed point";
	
	for(i=0;i<50;i++){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,b[i]);
	}

	glRasterPos2i(0,0);
	
	char c[10] = "X";
	glColor3f(1,1,1);
	for(i=0;i<5;i++){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,c[i]);
	}

	glFlush();
	
}

void MyInit(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100,100,-100,100,-100,100);
	glMatrixMode(GL_MODELVIEW);

}

void main(int argc , char **argv){
	int n;


	
	glutInit(&argc,argv);	
	glutInitWindowSize(500,500);
	glutCreateWindow("-Triangle-");

	MyInit();

	glutDisplayFunc(display);

	glutMainLoop();


}
