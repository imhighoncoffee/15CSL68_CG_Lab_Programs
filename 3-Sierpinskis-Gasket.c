#include<GL/glut.h>
#include<stdio.h>

int m;

void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10,10,-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}

void draw_triangle(float *a , float *b, float *c)
{
	glBegin(GL_TRIANGLES);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
	glFlush();
}
void draw_tetra(float *a , float *b, float *c,float *d)
{
	glColor3f(1.0,1.0,1.0);
	draw_triangle(a,b,d);

	glColor3f(0,1.0,1.0);
	draw_triangle(a,d,c);

	glColor3f(1,1,0.4);
	draw_triangle(b,d,c);
	
	glColor3f(0.8,0.0,0.4);
	draw_triangle(a,b,c);
	
}

void div_tetra(float *a , float *b, float *c, float *d , int m)
{
	float mid[6][3];
	if(m>0)
	{
		int i;
		for(i=0;i<3;i++)
		{
			mid[0][i] = (a[i]+b[i])/2;
			mid[1][i] = (b[i]+c[i])/2;
			mid[2][i] = (a[i]+c[i])/2;
			mid[3][i] = (d[i]+b[i])/2;
			mid[4][i] = (d[i]+c[i])/2;
			mid[5][i] = (a[i]+d[i])/2;
		}
		div_tetra(mid[0],b,mid[1],mid[3],m-1);
		div_tetra(mid[5],mid[3],mid[4],d,m-1);
		div_tetra(a,mid[0],mid[2],mid[5],m-1);
		div_tetra(mid[2],mid[1],c,mid[4],m-1);
		
	}
	else
	{
		draw_tetra(a,b,c,d);
	}

}
void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	float vertices[4][3] = {{-7,-7,-5},{7,-7,-5},{0,0,7},{0,7,-5}};
	div_tetra(vertices[0],vertices[1],vertices[2],vertices[3],m);
}

void main(int argc , char **argv)
{

	printf("Enter m value\n");
	scanf("%d",&m);
	glutInit(&argc,argv);	
	glutInitWindowSize(1000,1000);
	glutCreateWindow("gasquet");
	myInit();
	
	glutDisplayFunc(display);
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();

}