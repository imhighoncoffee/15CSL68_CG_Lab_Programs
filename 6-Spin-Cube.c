#include<GL/glut.h>
#include<stdio.h>

float a = 0;
void myInit(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30,30,-30,30,-30,30);
	glMatrixMode(GL_MODELVIEW);

}
void spin_cube(){

	a+=0.05;
	if(a>360){
		a-=360;
	} 
	glutPostRedisplay();


}
void draw_cube(float *a,float *b,float *c,float *d){

	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(d);
	glEnd();
}
void draw_recursive_cube(float *a,float *b,float *c,float *d,float *e,float *f,float *g,float *h){

	glColor3f(1,1,0);
	draw_cube(a,b,c,d);
	
	glColor3f(0,1,0);
	draw_cube(a,e,f,b);
	
	glColor3f(1,0,0);
	draw_cube(f,b,c,h);
	
	glColor3f(1,0,1);
	draw_cube(g,d,c,h);
	
	glColor3f(0,0,1);
	draw_cube(a,e,g,d);
	
	glColor3f(1,1,0.5);
	draw_cube(e,f,h,g);

}
void display(){

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	float v[8][3]={{-10,10,10},{10,10,10},{10,-10,10},{-10,-10,10},{-10,10,-10},{10,10,-10},{-10,-10,-10},{10,-10,-10}};
	glLoadIdentity();
	glRotatef(a,1,1,0);
	draw_recursive_cube(v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]);
	glFlush();
	//glutPostRedisplay();
}
int main(int argc,char **argv){

	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutCreateWindow("Spin_cube");
	myInit();
	glutDisplayFunc(display);
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutIdleFunc(spin_cube);
	glutMainLoop();
}
