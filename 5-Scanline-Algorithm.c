#include<GL/glut.h>
#include<stdio.h>

int  n;
float v[50][50];

void edgedetect(float x1,float y11,float x2,float y2,int *le,int *re)
{

	float mx,x,temp;
	int i;
	if((y2-y11)<0)
	{
		temp =y11;
		y11 = y2;
		y2 = temp;
		temp = x1;
		x1 = x2;
		x2 = temp;

	}
	if((y2-y11)!=0)
	{
		mx= (x2-x1)/(y2-y11);	
		
	}
	else{

		mx = x2-x1;
	}
	x=x1;
	
	for(i=y11;i<=y2;i++)
	{
		if(x<(float)le[i])
			le[i] = (int)x;
		if(x>(float)re[i])
			re[i]=(int)x;
		x+=mx;

	}
}

void drawpixel(int x,int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();	
}

void scanfill(){

	int le[500],re[500];
	int i,j;
	for(i=0;i<500;i++){
		le[i] = 500;
		re[i] = 0;

	}
	for(i=0;i<n-1;i++){
		edgedetect(v[i][0],v[i][1],v[i+1][0],v[i+1][1],le,re);
	}
	edgedetect(v[n-1][0],v[n-1][1],v[0][0],v[0][1],le,re);
	for(j=0;j<500;j++){
		if(le[j]<=re[j]){
			for(i=(int)le[j];i<(int)re[j];i++){
				drawpixel(i,j);			
			}
		}
	}

}
void mymenu(int id){

	if(id==1){
		glColor3f(1,0,0);
	}
	else if(id==2){
		glColor3f(0,1,0);
	}

	else if(id==3){
		glColor3f(0,1,1);
	}

	else if(id==4){
		glColor3f(1,0,0);
	}

	else if(id==5){
		glColor3f(1,1,0);
	}

	else{
		glColor3f(1,0,1);
	}
	glutPostRedisplay();
}

void display(){

	int i;
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	//glPointSize(1.0);
	glBegin(GL_LINE_LOOP);
	 for(i=0;i<n;i++){
	 
	 	glVertex2f(v[i][0],v[i][1]);
	 }
	 glEnd();
	 scanfill();
	 glFlush();
}
void myInit(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,50,0,50, 0, 50);
	glMatrixMode(GL_MODELVIEW);

}

void main(int argc,char **argv){

	int i;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	printf("Enter vertices\n");
	for(i=0;i<n;i++){
		scanf("%f%f",&v[i][0],&v[i][1]);
		
	}
	glutInit(&argc,argv);
	glutCreateWindow("-scanline-");
	myInit();
	glutDisplayFunc(display);
	glutCreateMenu(mymenu);
	glutAddMenuEntry("Red",1);
	glutAddMenuEntry("Blue",2);
	glutAddMenuEntry("Green",3);
	glutAddMenuEntry("Cyan",4);
	glutAddMenuEntry("Yellow",5);
	glutAddMenuEntry("Magenta",6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	

}
