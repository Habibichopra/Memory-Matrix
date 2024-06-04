#pragma once
#include "immediate2d.h"
#define MAX_COLONNE 8
#define MAX_RIGHE 5
using namespace std;
#include <iostream>

class CGioco
{
private:
	int matrice[MAX_COLONNE][MAX_RIGHE];
	int livello;
	int stato;
public:
	CGioco();
	void inserimentoRandom();
	void inizializzazione();
	void DrawInizializzata();
	int returnLivello();
	int returnStato();
	void setLivello(int livello);
	void Draw();
	void DrawSequenzaEsatta();
	bool controllo(int x, int y);
	bool condizioneVittoria();
};

