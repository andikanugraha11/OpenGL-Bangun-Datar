
/**
	Name	: OpenGL Hello World
	Author 	: Andika Nugraha
	Year	: 2016
**/


#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
float dikaMx,dikaMy;
float koordinatX[10];
float koordinatY[10];
int i =0;



void Gambar(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES); //Garis
		//KARTESIUS 
		//Vertikal
		glVertex3f(0.5,1,0.0); //X,Y titik atas
		glVertex3f(0.5,0.0,0.0); //titik bawah
		//Horizontal
		glVertex3f(0.0,0.5,0.0); // titik kiri
		glVertex3f(1.0,0.5,0.0); //titik kanan
	glEnd();

	glBegin(GL_LINE_LOOP); //GL_LINE_LOOP GL_QUADS
		glVertex3f(0.6,0.6,0.0); // Titik A
		glVertex3f(0.9,0.6,0.0); // Titik B
		glVertex3f(0.9,0.9,0.0); // Titik c
		glVertex3f(0.6,0.9,0.0); // Titik d
	glEnd();

	glBegin(GL_LINE_LOOP); //GL_LINE_LOOP GL_TRIANGLE
		glVertex3f(0.1,0.6,0.0); // Titik A
		glVertex3f(0.4,0.6,0.0); // Titik B
		glVertex3f(0.25,0.9,0.0); // Titik C
	glEnd();

	glBegin(GL_LINE_LOOP);//GL_LINE_LOOP GL_POLYGON
	float jari=0.2;
	float banyak=360;
    for(int i = 0; i < banyak; i++)
    {
        float theta = 2.0f * 3.1415926f * i / banyak;//get the current angle

        float x = 0.2 * cosf(theta);//calculate the x component
        float y = 0.2 * sinf(theta);//calculate the y component

        glVertex2f(x + 0.75, y + 0.25);//output vertex

    }
    glEnd();

	glFlush();
}



void pakekeyboard(unsigned char key, int mouseX, int mouseY){
	switch(key){
		case 'q':
			exit(EXIT_SUCCESS);
			break;
	}
}

void pakemouse(int button, int state, int Mx, int My){

	if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN){

		dikaMx=Mx*2;
		koordinatX[i]=dikaMx/1000;
		dikaMy=My*2;
		koordinatY[i]=dikaMy/100;
		i=i+1;
		// if(i=3)
		// {

		// 	return(koordinatX,koordinatY);
		// 	glutPostRedisplay();
		// }
	}


	// switch(button){
	// 	case GLUT_LEFT_BUTTON:
		
	// 		if(state == GLUT_DOWN)
	// 		{

	// 			// for(int i=0;i<3;i++){
	// 				dikaMx=Mx*2;
	// 				koordinatX[i]=dikaMx/1000;
	// 				i=i+1;
	// 			// }
	// 			// printf("%f %f %f\n",koordinatX[0],koordinatX[1],koordinatX[2] );
	// 			// dikaMx=Mx*2;
	// 			// koordinatX = dikaMx/1000;
	// 			// printf("%f\n", koordinatX );
	// 		}

	// }

}


// void GambarSegiEmpat(){
// 	glClear(GL_COLOR_BUFFER_BIT);
// 	glColor3f(1.0,1.0,1.0);
// 	glBegin(GL_QUADS); //Segi Empat
// 		glVertex3f(0.6,0.6,0.0); // Titik A
// 		glVertex3f(0.9,0.6,0.0); // Titik B
// 		glVertex3f(0.9,0.9,0.0); // Titik c
// 		glVertex3f(0.6,0.9,0.0); // Titik d
// 	glEnd();
// 	glFlush();
// }

void Inisialisasi(){
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}

int main(int iArgc, char** cppArgv){
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(400,100);
	glutCreateWindow("Andika Nugraha");
	Inisialisasi();
	glutDisplayFunc(Gambar);
	glutKeyboardFunc(pakekeyboard);
	glutMouseFunc(pakemouse);
	glutMainLoop();
	return 0;
}

// CATATAN
// GL_POINTS 			: Membuat Titik (1 titik)
// GL_LINES 			: Membuat Garis (2 titik)
// GL_TRIANGLES 		: Membuat Segitiga (3 titik)
// GL_TRIANGLE_STRIP 	: Membuat segitiga bisa nyambug (Banyak titik)
// GL_QUAD_STRIP
// GL_LINE_STRIP
// GL_LINE_LOOP
// GL_QUADS 			: Membuat Persegi atau apa aja yang penting 4 titik
// GL_POLYGON
// GL_TRIANGLE_FAN