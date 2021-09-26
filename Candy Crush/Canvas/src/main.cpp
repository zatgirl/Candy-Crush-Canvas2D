#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"

//#include "Bola.h"
#include "Bmp.h"


int screenWidth = 800, screenHeight = 800; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.

void render(){


}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{

}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou: %d" , key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{

}

int main(void)
{
   CV::init(&screenWidth, &screenHeight, "Bomberman 2D");
   if (lose != 1){
     CV::run();
   }
}
