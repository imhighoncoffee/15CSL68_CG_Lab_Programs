#include<GL/glut.h>

void displaySolid(){

	glClearColor(0.5,0.5,0.1,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500, 500, -500, 500, -500, 500);
	glMatrixMode(GL_MODELVIEW);
		
	GLfloat mat_ambient1[] = {1.0f,0.0f,0.0f,1.0f};
	GLfloat mat_diffuse1[] = {1.0f,1.0f,0.0f,1.0f};
	GLfloat mat_specular1[] = {1.0f,1.0f,0.5f,1.0f};
	GLfloat mat_shininess1[] = {25.0f};
	
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient1);	 	 
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess1);
	
	GLfloat lightIntensity1[] = {0.5f,0.5f,0.5f,1.0f};
	GLfloat light_position1[] = {25.0f,50.0f,50.0f,1.0f};
	
	glLightfv(GL_LIGHT0,GL_POSITION,light_position1);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity1);

	//teapot
	glPushMatrix();
		glRotatef(30, 1, 1, 0);
		glTranslatef(0, 45, 0);
		glutSolidTeapot(50); 
	glPopMatrix();
	
	//surface
	glPushMatrix();
		glRotatef(30, 1, 1, 0);
		glTranslatef(0, 0, 0);
		glScalef(300, 20, 300);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//first leg
	
	glPushMatrix(); //save the unscaled coordinate
		glRotatef(30, 1, 1, 0);
		glTranslatef(-140, -160, -140);
		glScalef(20, 300, 20); //change the size of an object,yis stretched to300
		glutSolidCube(1.0);
	glPopMatrix();
	
		
	//second leg
	glPushMatrix();
		glRotatef(30, 1, 1, 0);
		glTranslatef(+140, -160, -140);
		glScalef(20, 300, 20);
		glutSolidCube(1.0);
	glPopMatrix();
	
		
	//third leg
	glPushMatrix();
		glRotatef(30, 1, 1, 0);
		glTranslatef(-140, -160, +140);
		glScalef(20, 300, 20);
		glutSolidCube(1.0);
	glPopMatrix();
	
	
	//fourth leg
	
	glPushMatrix();
		glRotatef(30, 1, 1, 0);
		glTranslatef(+140, -160, +140);
		glScalef(20, 300, 20);
		glutSolidCube(1.0);
	glPopMatrix();

	//back wall
	glPushMatrix();
		glRotatef(30, 1, 1, 0);
		glTranslatef(0, -90, -250);
		glScalef(500, 500, 20);
		glutSolidCube(1.0);
	glPopMatrix();

	//right wall
	glPushMatrix();
		glRotatef(30, 1, 1, 0);
		glTranslatef(250, -90, 0);
		glScalef(20, 500, 500);
		glutSolidCube(1.0);
	glPopMatrix();

	//floor
	glPushMatrix();
		glRotatef(30, 1, 1, 0);
		glTranslatef(0, -325, 0);
		glScalef(500, 20, 500);
		glutSolidCube(1.0);
	glPopMatrix();
	
	glFlush();
}

void main(int argc , char *argv[]){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Tea pot");
	glutDisplayFunc(displaySolid);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glutMainLoop();
}