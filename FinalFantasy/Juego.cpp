#include "Juego.h"

#include <algorithm>
#include <iterator>

#include "Juego.h"
#include "Constantes.h"
#include "Imagenes.h"
//#include "Escenas.h"

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

	Juego::Juego(void) {
		inicializarComponentes();
		InitializeComponent();
		myform = this;

		graphics = this->CreateGraphics();
		context = BufferedGraphicsManager::Current;
		aleatorio = gcnew Random();

		//Inicializamos las escenas
		//ESCENAS::introduccion = gcnew IntroduccionEscena();
		//ESCENAS::campus = gcnew CampusEscena();
		//ESCENAS::tienda = gcnew TiendaEscena();

		//Empezar el juego
		//Escena::EmpezarConEscena(ESCENAS::campus);
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

		// Fondos
		IMAGENES::INTRODUCCION_FONDO = Image::FromFile("Imagenes\\Interfaces\\Introduccion.png");

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

	bool noHayONoExsite(Object^ objeto) {
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