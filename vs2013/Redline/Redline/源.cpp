#include<GL\glut.h>

void init(void)
{
	glClearColor(0.3, 0.3, 0.3, 0.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);

}
class pointx
{
public:float x, y;
};
void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	int point1 [ ] = {50,100};
	pointx ponit2;
	ponit2.x = 10.2;
	ponit2.y = 50.8;
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(180 ,15);
	glVertex2f(ponit2.x, ponit2.y);
	glVertex2iv(point1);
	glVertex2i(10,145);
	glEnd();

	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitWindowPosition(50, 100);
	//glutInitWindowSize(400,300);
	glutCreateWindow("RedLine");

	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}