#include <GL/glew.h>
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <bits/stdc++.h>
#include "estruturasPrincipais.h"
#include "tela.h"
using namespace std;

//constutor para telas
Tela::Tela(vector<string>endTexturas){
	for(int i=0; i<endTexturas.size(); i++){
		this->texturas[i] = SOIL_load_OGL_texture(
		    endTexturas[i].c_str(),
			SOIL_LOAD_AUTO,
	    	SOIL_CREATE_NEW_ID,
	    	SOIL_FLAG_INVERT_Y
 		);
 		if (this->texturas[i] == 0 ) {
    		printf("Erro carregando textura: '%s'\n", SOIL_last_result());
    		cout<<endTexturas[i]<<endl;
  		}
	}
	this->telaAtual = ABERTURA;
	this->posicaoTexturaMenu = 0;
}

//desenha tela normal
void Tela::desenhaTela(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->texturas[this->telaAtual]);
	glPushMatrix();
		glTranslatef(FUNDO_TELA, FUNDO_TELA,0);
		glBegin(GL_POLYGON);
			glTexCoord2f(0, 0); 			glVertex2f(0,0);
			glTexCoord2f(1, 0);				glVertex2f(2*TOPO_TELA,0);
			glTexCoord2f(1, 1); 			glVertex2f(2*TOPO_TELA,2*TOPO_TELA);
			glTexCoord2f(0, 1);				glVertex2f(0,2*TOPO_TELA);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}

void Tela::desenhaTela(float limInferiorY, float limSuperiorY){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->texturas[this->telaAtual]);
	glPushMatrix();
		glTranslatef(FUNDO_TELA, FUNDO_TELA, 0);
		glBegin(GL_POLYGON);
			glTexCoord2f(0, 0); 			glVertex2f(0,limInferiorY);
			glTexCoord2f(1, 0);				glVertex2f(2*TOPO_TELA,limInferiorY);
			glTexCoord2f(1, 1); 			glVertex2f(2*TOPO_TELA,limSuperiorY);
			glTexCoord2f(0, 1);				glVertex2f(0,limSuperiorY);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}


//desenha tela com sprite
void Tela::desenhaTelaSprite(float spriteBegin, float spriteEnd){
	glPushMatrix();
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->texturas[this->telaAtual]);
	glTranslatef(FUNDO_TELA, FUNDO_TELA, 0);
    glBegin(GL_POLYGON);
		glTexCoord2f(spriteBegin, 0); 			glVertex2f(0,0);
		glTexCoord2f(spriteEnd, 0);				glVertex2f(2*TOPO_TELA,0);
		glTexCoord2f(spriteEnd, 1); 			glVertex2f(2*TOPO_TELA,2*TOPO_TELA);
		glTexCoord2f(spriteBegin, 1);			glVertex2f(0,2*TOPO_TELA);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
    glPopMatrix();
}

//set para mudar de tela
void Tela::setTela(int novaTela){
	this->telaAtual = novaTela;
}

//get para que retorna a tela atual
int Tela::getTela(){
	return this->telaAtual;
}

float Tela::getPosicaoTexturaMenu(){
	return this->posicaoTexturaMenu;
}

void Tela::setPosicaoTexturaMenu(float pos){
	this->posicaoTexturaMenu = pos;
}
