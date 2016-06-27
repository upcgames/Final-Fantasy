#include "Juego.h"

#include <algorithm>
#include <iterator>

#include "MonedaObjeto.h"
#include "Juego.h"
#include "Constantes.h"
#include "Controles.h"
#include "Fuentes.h"
#include "Imagenes.h"
#include "Escenas.h"
#include "Salaverry.cpp"

namespace FinalFantasy {

	//Definicion de las constantes
	const int MYFORM_WIDTH = 16;
	const int MYFORM_HEIGHT = 10;
	const int RESOLUCION_X = 56;
	const int RESOLUCION_Y = 56;
	const int MYFORM_SIZE_WIDTH = MYFORM_WIDTH * RESOLUCION_X;
	const int MYFORM_SIZE_HEIGHT = MYFORM_HEIGHT * RESOLUCION_Y;
	const float TAMANIO_LETRAS = 20.0f;
	const int VELOCIDAD_TIMER = 50;

	Terreno TERRENOS_COLISIONANTES[] = { Maceta, Agua };

	void inicializarMapas() {
		MAPAS::lista = gcnew List<Mapa^>(5);

		for (int i = 0; i < 5; i++) {
			MAPAS::lista->Add(gcnew Mapa(nullptr, nullptr, nullptr));
		}

		MAPAS::lista[0]->cambiarPuertas(nullptr, MAPAS::lista[1], MAPAS::lista[2]);
		MAPAS::lista[1]->cambiarPuertas(MAPAS::lista[0], MAPAS::lista[2], MAPAS::lista[3]);
		MAPAS::lista[2]->cambiarPuertas(MAPAS::lista[1], MAPAS::lista[3], MAPAS::lista[4]);
		MAPAS::lista[3]->cambiarPuertas(MAPAS::lista[2], MAPAS::lista[4], MAPAS::lista[0]);
		MAPAS::lista[4]->cambiarPuertas(MAPAS::lista[3], MAPAS::lista[0], MAPAS::lista[1]);


		MAPAS::lista[0]->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Pasto, Pasto, Pasto, Agua, Agua, Agua, Agua, Pasto, Pasto, Pasto, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Granito, Granito, Granito, Granito, Pasto, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		MAPAS::lista[0]->objetos = gcnew List<Objeto ^>();
		MAPAS::lista[0]->generarCapaTerreno();

		MAPAS::lista[1]->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Agua, Agua, Agua, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Granito, Granito, Granito, Granito, Granito, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Tierra, Tierra, Tierra, Tierra, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		MAPAS::lista[1]->objetos = gcnew List<Objeto ^>();
		MAPAS::lista[1]->generarCapaTerreno();

		MAPAS::lista[2]->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Arena, Arena, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Hielo, Pasto, Pasto, Hielo, Hielo, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Hielo, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Hielo, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Hielo, Pasto, Pasto, Pasto, Hielo, Hielo, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		MAPAS::lista[2]->objetos = gcnew List<Objeto ^>();
		MAPAS::lista[2]->generarCapaTerreno();

		MAPAS::lista[3]->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Tierra, Tierra, Tierra, Granito, Arena, Arena, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Granito, Arena, Arena, Arena, Granito, Agua, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Granito, Granito, Arena, Arena, Arena, Granito, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Arena, Arena, Arena, Arena, Arena, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Granito, Arena, Tierra, Tierra, Tierra, Tierra, Arena, Granito, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Agua, Agua, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Agua, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		MAPAS::lista[3]->objetos = gcnew List<Objeto ^>();
		MAPAS::lista[3]->generarCapaTerreno();

		MAPAS::lista[4]->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Pasto, Pasto, Pasto, Pasto, Pasto, Pasto, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Agua, Roca, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Roca, Agua, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Tierra, Tierra, Tierra, Tierra, Tierra, Arena, Arena, Arena, Arena, Tierra, Tierra, Tierra, Tierra, Tierra, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};
		MAPAS::lista[4]->objetos = gcnew List<Objeto ^>();
		MAPAS::lista[4]->generarCapaTerreno();
	}

	Juego::Juego(void) {
		
		aleatorio = gcnew Random();
		Mapa::puerta1 = gcnew Posicion(0, 3, true);
		Mapa::puerta2 = gcnew Posicion(12, 0, true);
		Mapa::puerta3 = gcnew Posicion(12, 9, true);

		inicializarComponentes();
		InitializeComponent();
		myform = this;

		graphics = this->CreateGraphics();
		context = BufferedGraphicsManager::Current;


		inicializarMapas();

		//Inicializamos las escenas
		ESCENAS::introduccion = gcnew IntroduccionEscena();
		ESCENAS::mapa = gcnew MapaEscena();

		

		//Empezar el juego
		Escena::EmpezarConEscena(ESCENAS::introduccion);
	}

	Juego::~Juego() {
		if (components)	{
			delete components;
		}
	}

	void Juego::InitializeComponent(void) {
		this->components = (gcnew System::ComponentModel::Container());
		System::ComponentModel::ComponentResourceManager ^resources = (gcnew System::ComponentModel::ComponentResourceManager(Juego::typeid));
		this->timer = (gcnew System::Windows::Forms::Timer(this->components));
		this->SuspendLayout();
		// 
		// timer
		// 
		this->timer->Enabled = true;
		this->timer->Interval = VELOCIDAD_TIMER;
		// 
		// Myform
		// 
		this->DoubleBuffered = true;
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(MYFORM_WIDTH * RESOLUCION_X, MYFORM_HEIGHT * RESOLUCION_Y);
		this->MaximumSize = System::Drawing::Size(MYFORM_WIDTH * RESOLUCION_X + 16, MYFORM_HEIGHT * RESOLUCION_Y + 39);
		this->MinimumSize = System::Drawing::Size(MYFORM_WIDTH * RESOLUCION_X + 16, MYFORM_HEIGHT * RESOLUCION_Y + 39);
		this->Name = L"Final Fantasy";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Final Fantasy";
		this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
		this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyUp);
		this->ResumeLayout(false);

	}

	System::Void Juego::Juego_KeyDown(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e) {
		;
	}

	System::Void Juego::Juego_KeyUp(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e) {
		;
	}

	void Juego::inicializarComponentes() {
		// Sprites
		IMAGENES::MARCO_SPRITE = Image::FromFile("Imagenes\\Personajes\\Marco_Sprite.png");
		IMAGENES::MONEDA_SPRITE = Image::FromFile("Imagenes\\Objetos\\Moneda_Sprite.png");

		// Fondos
		IMAGENES::INTRODUCCION_FONDO = Image::FromFile("Imagenes\\Interfaces\\Introduccion.png");
		IMAGENES::PUERTA = Image::FromFile("Imagenes\\Objetos\\PUERTA.png");

		// Objetos
		IMAGENES::LOCETA = Image::FromFile("Imagenes\\Objetos\\LOCETA.png");
		IMAGENES::AGUA = Image::FromFile("Imagenes\\Objetos\\AGUA.png");
		IMAGENES::ARENA = Image::FromFile("Imagenes\\Objetos\\ARENA.png");
		IMAGENES::GRANITO = Image::FromFile("Imagenes\\Objetos\\GRANITO.png");
		IMAGENES::HIELO = Image::FromFile("Imagenes\\Objetos\\HIELO.png");
		IMAGENES::LAVA = Image::FromFile("Imagenes\\Objetos\\LAVA.png");
		IMAGENES::LODO = Image::FromFile("Imagenes\\Objetos\\LODO.png");
		IMAGENES::MACETA = Image::FromFile("Imagenes\\Objetos\\MACETA.png");
		IMAGENES::PASTO = Image::FromFile("Imagenes\\Objetos\\PASTO.png");
		IMAGENES::ROCA = Image::FromFile("Imagenes\\Objetos\\ROCA.png");
		IMAGENES::TEJADO = Image::FromFile("Imagenes\\Objetos\\TEJADO.png");
		IMAGENES::TIERRA = Image::FromFile("Imagenes\\Objetos\\TIERRA.png");

		// Controles
		CONTROLES::CAMBIO_ESCENA = Keys::E;
		CONTROLES::SALIR = Keys::Escape;
		CONTROLES::MOVER_ARRIBA_1 = Keys::W;
		CONTROLES::MOVER_ABAJO_1 = Keys::S;
		CONTROLES::MOVER_IZQUIERDA_1 = Keys::A;
		CONTROLES::MOVER_DERECHA_1 = Keys::D;
		CONTROLES::MOVER_ARRIBA_2 = Keys::Up;
		CONTROLES::MOVER_ABAJO_2 = Keys::Down;
		CONTROLES::MOVER_IZQUIERDA_2 = Keys::Left;
		CONTROLES::MOVER_DERECHA_2 = Keys::Right;

		FUENTES::SUBTITULOS = gcnew System::Drawing::Font("ARIAL", TAMANIO_LETRAS - 2, FontStyle::Regular, GraphicsUnit::Point);
		FUENTES::DIALOGOS = gcnew System::Drawing::Font("Lucida Console", TAMANIO_LETRAS, FontStyle::Regular, GraphicsUnit::Point);
		FUENTES::DINERO = gcnew System::Drawing::Font("Lucida Console", TAMANIO_LETRAS - 8, FontStyle::Regular, GraphicsUnit::Point);
	}

	void IMAGENES::mostarFondo(Image ^imagen, Graphics ^graphics) {
		graphics->DrawImage(imagen, Rectangle(0, 0, MYFORM_SIZE_WIDTH, MYFORM_SIZE_HEIGHT));
	}

	Direccion obtenerDireccionInvertida(Direccion direccion) {
		switch (direccion) {
		case Arriba:
			return Abajo;
			break;
		case Abajo:
			return Arriba;
			break;
		case Izquierda:
			return Derecha;
			break;
		case Derecha:
			return Izquierda;
			break;
		default:
			return Abajo;
		}
	}

	bool noHayONoExsite(Object ^objeto) {
		if (objeto == nullptr)
			return true;
		else
			return false;
	}

	bool Colisiona(Terreno terreno) {
		Terreno* indice_terreno = std::find(
			std::begin(TERRENOS_COLISIONANTES),
			std::end(TERRENOS_COLISIONANTES),
			terreno
		);

		bool impide = indice_terreno != std::end(TERRENOS_COLISIONANTES);

		return impide;
	}



}