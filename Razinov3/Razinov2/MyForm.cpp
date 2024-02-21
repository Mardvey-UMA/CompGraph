#include "Matrix.h"
#include "MyForm.h"
#include "Transform.h"
#include <math.h>
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^> ^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Razinov2::MyForm form;
	Application::Run(% form);
}
