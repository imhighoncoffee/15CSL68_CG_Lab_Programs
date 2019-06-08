#include<GL/glut.h>
#include<stdio.h>

float viewer[3] = {0,0,200};

void draw_square(float *a , float *b , float *c , float *d){

	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(d);
	glEnd();


}

void draw_cube(float *a,float *b ,float *c,float *d,float *e,float *f ,float *g,float *h){

	glColor3f(1,0.5,1.0);
	draw_square(a,b,c,d);
	glColor3f(1,0.36,0.35);
	draw_square(a,e,h,d);
	glColor3f(0.69,0.89,1.0);
	draw_square(d,h,g,c);
	glColor3f(0.25,1.0,0.23);
	draw_square(f,b,c,g);
	glColor3f(0.56,0.33,0.78);
	draw_square(e,h,g,f);
	glColor3f(0.3,0.5,0.89);
	draw_square(a,e,f,b);
}

void display(){

	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	float v[8][3]={{-80,-80,80},{80,-80,80},{80,80,80},{-80,80,80},{-80,-80,-80},{80,-80,-80},{80,80,-80},{-80,  80,-80}};
	//glColor3f(0,1,0);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,1.0,0,0);
	draw_cube(v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]);
	glFlush();

}

void move(unsigned char key , int x, int y){

	if(key=='x')
		viewer[0] = viewer[0]+10;
		
	if(key == 'X')
		viewer[0] = viewer[0]-10;
		
	if(key == 'y')
		viewer[1] = viewer[1]+10;
		
	if(key == 'Y')
		viewer[1] = viewer[1]-10;
		
	if(key == 'z')
		viewer[2] = viewer[2]+10;
		
	if(key == 'Z')
		viewer[2] = viewer[2]-10;
		
	glutPostRedisplay();

}

void myInit(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-100,100,-100,100,100,800);
	glMatrixMode(GL_MODELVIEW);

}

void main(int argc,char *argv[]){

	glutInit(&argc,argv);
	glutCreateWindow("camcube");
	myInit();
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutKeyboardFunc(move);
	glutMainLoop();

}
