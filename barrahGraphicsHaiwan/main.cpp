


#include <iostream>

#include <freeglut\include\GL\freeglut.h>

using namespace std;

//
void animate(int);
void disk_padl();

//void quit(unsigned char, int, int);
//
int delay=10, N=64;
double Dtheta = 2*3.1415926/N;
double centerx = 0.0, centery = 0.0, radius = 0.1;
double Dx = 0.02, Dy=0.01;
void padl(int,int);
//void padl(void);

//int win;
//
double posX=0.3,posX1=0.7;
double const posY=-0.9,posY1=-0.7;

//
//void mouse(int,int,int,int);



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("Ping Pong C++");
	glClearColor(0.9,0.5,0.2,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutTimerFunc(delay, animate, 0);
	glutMainLoop();

	return 0;
}
/*********************************************************************/
void padl(int posX,int y){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	double center=0.3;

	
	glColor4f(0.9,0.5,0.2,1.0);
	glRectf(posX,posY,posX+0.5,posY1);

	/*posX=x-center;
	posX1=x+center;*/

	glColor3f(0.0f,0.0f,0.0f);
	glRectf(posX,-0.9,0.3,-0.7);

	glEnd();
	glFlush();
}




//void mouse(int button,int state,int x,int y){
//	if(button==GLUT_LEFT_BUTTON||button==GLUT_RIGHT_BUTTON)
//		if(state==GLUT_DOWN)glutMotionFunc(padl);
//}



void animate(int code)
{	
	disk_padl();
	glutTimerFunc(delay, animate, 0);
	glutSwapBuffers();
}


void disk_padl()
{	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f,0.0f,0.0f);
	
	centerx = centerx+Dx;
	centery = centery+Dy;
	if(centerx+radius > 1.0) Dx = - Dx;
	if(centerx-radius < -1.0) Dx = - Dx;
	if(centery+radius > 1.0) Dy = - Dy;
	if(centery-radius <-1.0) Dy = - Dy;

	if(centery-radius < posY1) Dy = - Dy;


	/*while(centery-radius == posY1) {
		Dy = - Dy;){*/

	glRectf(posX,posY,posX1,posY1);
	glutMotionFunc(padl);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(centerx, centery);

	for (int i=0; i <= N; i++)
	{
		double angle = i*Dtheta;
		glVertex2f(centerx+cos(angle)*radius,centery+sin(angle)*radius);
	}

	
	glEnd();
}






