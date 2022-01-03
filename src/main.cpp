/*********************************************************************
// Canvas para desenho, criada sobre a API OpenGL. Nao eh necessario conhecimentos de OpenGL para usar.
//  Autor: Cesar Tadeu Pozzer
//         05/2020
//
//  Pode ser utilizada para fazer desenhos, animacoes, e jogos simples.
//  Tem tratamento de mouse e teclado
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp

//  Todos os arquivos do projeto devem ser .cpp
//
//  Versao 2.0
//
// *********************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"
#include "auxiliar.h"

#define tray 13 //Tamanho do tabuleiro definido em 13x13
#define pieceSize 50 //Tamanho de cada peça em px
#define borderTray 10

//variaveis globais
int screenWidth = 683, screenHeight = 633; //largura e altura inicial da tela. Alteram com o redimensionamento de tela.
int mouseX, mouseY, stateMouse; //variaveis globais do mouse para poder exibir dentro da render().
int passo = 0 ;

orange*candy = new orange();
centroidPieces*piece = new centroidPieces();

void base_matrix(){
   float x1,x2,y1,y2;
   for (int line = 0 ; line < tray ; line++){
       for (int col = 0 ; col < tray ; col++){
            CV::color(0,0,0);
            x1 = borderTray+(pieceSize*(line+1));
            y1 = borderTray+(pieceSize*col);
            x2 = borderTray+(pieceSize*line);
            y2 = borderTray+(pieceSize*line);
            CV::rect(x1,y1,x2,y2);
            //printf("[%d][%d] => x1=%.2f, x2=%.2f, y1=%.2f, y2=%.2f\n", line,col,x1,x2,y1,y2);
            piece->centerX[line][col] = (x1-(pieceSize/2));
            piece->centerY[line][col] = (y1-(pieceSize/2));
            if(passo == 0){
                piece->centerColor[line][col] = (1+(rand()%4));
            }
            //printf("%d, %d\n", piece->centerX[line][col], piece->centerY[line][col]);
           // CV::color(1,0,0);
           // CV::circleFill(piece->centerX[line][col], piece->centerY[line][col], 5, 20);
       }
   }passo++;


}

void Candys(){
    int k;
    for (int line = 1; line < 12; line++){
       for (int col = 2; col < 11; col++){
            k = piece->centerColor[line][col];
            if (k == 1) {
                CV::color(0,0,1);
                CV::circleFill(piece->centerX[line][col], piece->centerY[line][col], 15, 20);
            }
            if (k == 2) {
                CV::color(1,0.5,1);
                CV::circleFill(piece->centerX[line][col], piece->centerY[line][col], 15, 20);
            }
            if (k == 3) {
                CV::color(0,1,0);
                CV::circleFill(piece->centerX[line][col], piece->centerY[line][col], 15, 20);
            }
            if (k == 4) {
                CV::color(1,0,0);
                CV::circleFill(piece->centerX[line][col], piece->centerY[line][col], 15, 20);
            }

        }
    }
}

void teste(){
    float dist = sqrt((x-mx)*(x))
    if (stateMouse == 1){

   }
}

void render()
{
    base_matrix();
    Candys();
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
   printf("\nTecla: %d" , key);

}
//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou tecla: %d" , key);
}


//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
        mouseX = x;
        mouseY = y;
        stateMouse = state;
}

int main(void)
{
   CV::init(&screenWidth, &screenHeight, "CandyCrush");

   CV::run();
}
