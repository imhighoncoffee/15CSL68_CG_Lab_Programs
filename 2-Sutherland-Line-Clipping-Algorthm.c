#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<stdbool.h>

float xmin,ymin,xmax,ymax,x1,y11,x2,y2,x,y;

float vx1,vx2,vy1,vy2,sx,sy;

float vxmin;
float vymin;

float vxmax;
float vymax;

int top=8,bottom=4,left=1,right=2;
float line[10][4];
int n, i, j;

void suth_clip(float x1,float y11,float x2,float y2);


void display()
{

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0,1.0,0.0);

   glBegin(GL_LINE_LOOP);
   glVertex2i(xmin,ymin);
   glVertex2i(xmax,ymin);
   glVertex2i(xmax,ymax);
   glVertex2i(xmin,ymax);
   glEnd();

   glColor3f(1.0,0.0,0.0);
   glBegin(GL_LINES);
   for(i = 0; i < n; i++){
	glVertex2i(line[i][0], line[i][1]);
	glVertex2i(line[i][2], line[i][3]);
   }
   glEnd();
   
   for(i = 0; i < n; i++)
   	suth_clip(line[i][0], line[i][1], line[i][2], line[i][3]);

   glFlush();

}

int code(float x,float y)
{
    int c=0;
    if(y>ymax)c=c|top;
    if(y<ymin)c=c|bottom;
    if(x>xmax)c=c|right;
    if(x<xmin)c=c|left;
    return c;
}

void suth_clip(float x1,float y11,float x2,float y2)
{
	int outcode1=code(x1,y11);
	int outcode2=code(x2,y2);
	int nonzeroend;
	bool accept=false;
	bool done = false;

	do{
		if(outcode1==0 && outcode2==0)
		{
			accept=true;
			done = true;
		}
		else if(outcode1 & outcode2)
		{
			done=true;
		}

		else
		{
			nonzeroend=(outcode1!=0)?outcode1:outcode2;
			float m = (y2-y11)/(x2-x1);
			if(nonzeroend & top)
			{
				y=ymax;
				x=x1+ (1/m)*(y-y11);
			}
			if(nonzeroend & bottom )
			{
				y=ymin;
				x=x1+(1/m)*(y-y11);
			}
			if(nonzeroend & left)
			{
			   	x=xmin;
			   	y=y11+m*(x-x1);
			}
	
			if(nonzeroend & right)
			{
			   	x=xmax;
			   	y=y11+m*(x-x1);
			}

			if(outcode1==nonzeroend)
			{
			   x1=x;
			   y11=y;
			   outcode1=code(x1,y11);
			}

			else
			{
			   x2=x;
			   y2=y;
			   outcode2=code(x2,y2);
			}
		}
	}while(!done);
	if(accept)
	{  
		vxmax = xmax + 600;
		vxmin = xmin + 600;
		vymax = ymax;
		vymin = ymin;

		sx=(vxmax-vxmin)/(xmax-xmin);
		sy=(vymax-vymin)/(ymax-ymin);

		vx1=vxmin+(x1-xmin)*sx;
		vy1=vymin+(y11-ymin)*sy;
		vx2=vxmin+(x2-xmin)*sx;
		vy2=vymin+(y2-ymin)*sy;

		glColor3f(0.0,0.0,1.0);

		glBegin(GL_LINE_LOOP);

		glVertex2i(vxmin,vymin);
		glVertex2i(vxmax,vymin);
		glVertex2i(vxmax,vymax);
		glVertex2i(vxmin,vymax);
		
		glEnd();

		glColor3f(0.0,1.0,0.0);

		glBegin(GL_LINES);

		glVertex2i(vx1,vy1);
		glVertex2i(vx2,vy2);
		glEnd();
		//glFlush();
	}

}
	

void myinit(void)
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1000,1000,-1000,1000,-1000,1000);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char** argv)
{
	//int i, j;
   /* printf("Enter xmax,ymax,xmin,ymin:");
    scanf("%f",&xmax);
    scanf("%f",&ymax);
    scanf("%f",&xmin);
    scanf("%f",&ymin);
	*/
	printf("Enter the number of lines: ");
	scanf("%d", &n);

	printf("Enter line co-ordinates:\n");
	for(i = 0; i < n; i++){
		printf("Enter initial points (x1, y1) and end points (x2, y2) \n ");
		scanf("%f%f%f%f", &line[i][0], &line[i][1], &line[i][2], &line[i][3]);

		//printf("Enter end points (x, y): ");
		//scanf("%f%f",);
	}


	xmax=-200;
	ymax=600;
	xmin=-600;
	ymin=200;

	

    glutInit(&argc,argv);
    glutCreateWindow("Cohen Sutherland");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
}
