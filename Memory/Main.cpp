#define IMM2D_WIDTH 801
#define IMM2D_HEIGHT 501
#define IMM2D_SCALE 1

#define IMM2D_IMPLEMENTATION
#include "immediate2d.h"
#include "CGioco.h"
#define MAX_LEVEL 25

using namespace std;


void run()
{
	bool nextlevel = true;
	int livello = 1;
	DrawString(400, 200, "gioco basato su 25 livelli.", "Arial", 50, Yellow, true);
	Wait(5000);
	while(nextlevel)
	{
		CGioco gioco;
		gioco.setLivello(livello);
		gioco.inserimentoRandom();
		gioco.Draw();
		Wait(1500);
		gioco.DrawInizializzata();
		bool var = true;
		bool condizione = false;
		int cont = 0;
		while (var && gioco.returnStato() != gioco.returnLivello()) // fino a quando lo stato e' diverso dal livello continua a richiedere un ipput
		{
			if (LeftMousePressed()) {
				int x = MouseX();
				int y = MouseY();
				var = gioco.controllo(x, y);
			}
		}
		Wait(1000);
		Clear();
		if (gioco.condizioneVittoria())
		{
			//se vinco stampo "Livello completato"
			DrawString(400, 200, "Livello completato", "Arial", 50, Yellow, true);
			//incremento il livello
			livello++;
			//se il livello è diverso dal 25 ovvero livello massimo
			//stampo "Inizio nuovo livello tra:"
			if(livello!= MAX_LEVEL+1)
				DrawString(400, 260, "Inizio nuovo livello tra:", "Arial", 50, Yellow, true);
		}
		else
		{
			//se perdo stampo la sequanza giusta che andava cliccata
			gioco.DrawSequenzaEsatta();
			Wait(1500);
			Clear();
			//stampo "Game over"
			DrawString(400, 200, "Game over", "Arial", 50, Yellow, true);
			//imposto il livello a 1
			livello = 1;
			//stampo "Rinizio del livello 1 tra:"
			DrawString(400, 260, "Rinizio dal livello 1 tra:", "Arial", 50, Yellow, true);
		}
		Wait(2000);
		Clear();
		//se non ho raggiunto il livello massimo ovvero 25 stampo il timer per passare al livello successivo o ritorare al livello 1
		if (livello != MAX_LEVEL+1)
			for (int i = 3; i > 0; i--)
			{
				//CONVERTO CONTATORE I IN STRINGA E POI iN CHAR
				DrawString(400, 200, to_string(i).c_str(), "Arial", 50, Yellow, true);
				Wait(1000);
				Clear();
			}
		//se ho finito il livello finale 25, non stampo timer e imposto nextlevel a false
		else 
			nextlevel = false;
	}
	Wait(2000);
	Clear();
	DrawString(400, 200, "Gioco completato", "Arial", 50, Yellow, true);
	
	
}