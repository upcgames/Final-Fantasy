#include "Juego.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;

namespace FinalFantasy {

	const bool DEBUG_MODE = false;

	[STAThread]
	void main() {

		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		Juego^ juego = gcnew Juego();
		Application::Run(juego);
	}
}