#include "MapGenerator.h"


MapGenerator::MapGenerator(int _anchoPantalla, int _altoPantalla)
{
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;


	pacmanTexture.push_back(new Texture());
	pacmanTexture[0]->loadFromImage(pathPacman);
	fantasmaTexture.push_back(new Texture());
	fantasmaTexture[0]->loadFromImage(pathFantasma1);
	fantasmaTexture.push_back(new Texture());
	fantasmaTexture[1]->loadFromImage(pathFantasma2);
	fantasmaTexture.push_back(new Texture());
	fantasmaTexture[2]->loadFromImage(pathFantasma3);
	fantasmaTexture.push_back(new Texture());
	fantasmaTexture[3]->loadFromImage(pathFantasma4);
	frutaTexture.push_back(new Texture());
	frutaTexture[0]->loadFromImage(pathFruta1);
	frutaTexture.push_back(new Texture());
	frutaTexture[1]->loadFromImage(pathFruta2);
	frutaTexture.push_back(new Texture());
	frutaTexture[2]->loadFromImage(pathFruta3);
	frutaTexture.push_back(new Texture());
	frutaTexture[3]->loadFromImage(pathFruta4);
	frutaTexture.push_back(new Texture());
	frutaTexture[4]->loadFromImage(pathFruta5);
	monedaTexture.push_back(new Texture());
	monedaTexture[0]->loadFromImage(pathMoneda);
	monedaTexture.push_back(new Texture());
	monedaTexture[1]->loadFromImage(pathSuperMoneda);
	muroTexture.push_back(new Texture());
	muroTexture[0]->loadFromImage(pathPared);
}

bool MapGenerator::load(string path)
{
	// Crea un flujo a un archivo
	fstream file;

	// Abre el archivo y verifica si tuvo exito
	file.open(path.c_str(), ios::in);

	// Retorna false si falla la apertura del archivo
	if (file.is_open() == false)
		return false;

	string line;

	int x = 0;
	int y = 0;

	// Lee el archivo línea por línea
	while (getline(file, line)) {
		// Divide la línea leída y la guarda en un vector de carácteres
		vector<char> chars(line.begin(), line.end());
		srand(time(NULL));
		for (int x = 0; x < chars.size(); x++) {
			GameObject* newObject = nullptr;

			int xf = 1 + rand() % (anchoPantalla - 1);
			int yf = 1 + rand() % (altoPantalla - 1);
			int t = rand() % 5;

			// Se verifica la letra que se lee y se crea un tipo de objeto
			switch (chars[x])
			{
			case 'x':
				newObject = new Muro(x * 25, y * 25, 0, muroTexture);
				break;
			case '.':
				newObject = new Moneda(x * 25 + 8, y * 25 + 8, 0, 100, monedaTexture, true, 0, 0, 180, 180);
				break;
			case '+':
				newObject = new Moneda(x * 25, y * 25, 1, 100, monedaTexture, true, 0, 0, 25, 25);
				break;
			case 'P':
				newObject = new Pacman(x * 25, y * 25, 5, pacmanTexture, true, 0, 0, 100, 100);
				break;
			case 'b':
				newObject = new Fantasma(x * 25, y * 25, xf, yf, 0, fantasmaTexture, true, 0, 0, 30, 30);
				break;
			case 'c':
				newObject = new Fantasma(x * 25, y * 25, xf, yf, 1, fantasmaTexture, true, 0, 0, 30, 30);
				break;
			case 'i':
				newObject = new Fantasma(x * 25, y * 25, xf, yf, 2, fantasmaTexture, true, 0, 0, 30, 30);
				break;
			case 'p':
				newObject = new Fantasma(x * 25, y * 25, xf, yf, 3, fantasmaTexture, true, 0, 0, 30, 30);
				break;
			case 'F':
				newObject = new Fruta(x * 25, y * 25, t, frutaTexture, true, 0, 0, 100, 100);
				break;
			}

			// Si el objeto fue creado, añadir al vector
			if (newObject != nullptr)
				pilaObjects.Insertar(newObject);
			//vectorObjetosJuego.push_back(newObject);
		}

		y++;
	}
	// Cerrar el archivo
	file.close();

	return true;
}

void MapGenerator::populate(list<GameObject*>& _vectorObjetosJuegoGM)
{
	for (unsigned int i = 0; !pilaObjects.Vacia(); i++) {
		_vectorObjetosJuegoGM.push_back(pilaObjects.Sacar());
		//_vectorObjetosJuegoGM.push_back(vectorObjetosJuego[i]);
	}
}