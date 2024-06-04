#include "CGioco.h"

CGioco::CGioco()
{
	//alla creazione dell'oggetto, lo inizilizzo e imposto livello e lo stato a 0
	inizializzazione();
	livello = 0;
	stato = 0;
}

void CGioco::inserimentoRandom()
{
	srand(time(NULL));
	//imposto N=livello numero di celle randomiche ad 1
	for (int i = 0; i < livello; i++)
	{
		//scelgo una cella casuale della matrice
		int colonne = rand() % 7;
		int righe = rand() % 4;
		//assicuro che la cella non sia già impostata a 1
		//se si, sceglo di nuovo una casella casuale
		while (matrice[colonne][righe] == 1) {
			colonne = rand() % 7;
			righe = rand() % 4;
		}
		//se no, imposto la cella randomica a uno
		matrice[colonne][righe] = 1;
	}
}

void CGioco::inizializzazione()
{
	//imposto tutte le celle della matrice a 0
	for (int i = 0; i < MAX_COLONNE; i++)
		for (int j = 0; j < MAX_RIGHE; j++)
			matrice[i][j] = 0;
}

void CGioco::DrawInizializzata()
{
	//stampo la matrice con tutttle celle riempite di rosso ì con i bordi gialli
	for (int i = 0; i < MAX_COLONNE; i++) {
		for (int j = 0; j < MAX_RIGHE; j++) {
			DrawRectangle(i * 100, j * 100, 100, 100, Red, Yellow);
		}
	}
}

int CGioco::returnLivello()
{
	//per ritornare il livello
	return livello;
}

int CGioco::returnStato()
{
	//per ritornare il stato
	return stato;
}

void CGioco::setLivello(int livello)
{
	//per impostare il livello
	this->livello = livello;
}

void CGioco::Draw()
{
	//scorro le caselle tutte le caselle della matrice
	//se casella = 0; allora la riempio di rosso con i bordi gialli
	//se casella = 1; allora la riempio di giallo
	for (int i = 0; i < MAX_COLONNE; i++) {
		for (int j = 0; j < MAX_RIGHE; j++) {
			if (matrice[i][j] == 0)
				DrawRectangle(i * 100, j * 100, 100, 100, Red, Yellow);
			else
				DrawRectangle(i * 100, j * 100, 100, 100, Yellow);
		}
	}
}

void CGioco::DrawSequenzaEsatta()
{
	//stampo la matrice base con interno rosso e bordi gialli
	DrawInizializzata();
	//scorro la matrice e coloro di marrone le celle che andavano indovinate
	for (int i = 0; i < MAX_COLONNE; i++)
		for (int j = 0; j < MAX_RIGHE; j++) {
			if (matrice[i][j] != 0)
				DrawRectangle(i * 100, j * 100, 100, 100, Brown, Brown);
		}
}

bool CGioco::controllo(int x, int y)
{
	//controllo se la cella selezionata è quella randomica
	//se non lo è esco subito e ritorno falso
	//faccio diviso 100 perchè le celle hanno dimensione 100x100
	if (matrice[x / 100][y / 100] != 0){
		//controlla se la cella selezionata già stata selezionata precedentemente
		if (matrice[x / 100][y / 100] != 2)
		{
			//aggiorno lo stato(che indica i quadrati cliccati giusti
			stato++;
			//disegno un rettangolo di colore blu sulla cella selezionata
			DrawRectangle((x / 100) * 100, (y / 100) * 100, 100, 100, LightBlue, LightBlue);
			//imposto la cella selezionata a 2
			matrice[x / 100][y / 100] = 2;
		}
		return true;
	}
	return false;
}

bool CGioco::condizioneVittoria()
{
	//controllo quante celle giuste sono state selezionate
	//se il numero di celle giustamente cliccate corrisponde al numero del livello, vittoria quindi riotrno trueù
	//altrimenti false
	int cont = 0;
	for (int i = 0; i < MAX_COLONNE; i++)
		for (int j = 0; j < MAX_RIGHE; j++)
			if (matrice[i][j] == 2)
				cont++;
	if (cont == livello)
		return true;
	return false;
}
