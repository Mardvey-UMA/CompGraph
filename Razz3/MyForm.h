#pragma once

namespace Razinov2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(640, 875);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: bool keepAspectRatio;
	private: bool printMouse;
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		float Vx = 18.f; // размер рисунка по горизонтали
		float Vy = 28.f; // размер рисунка по вертикали
		if (printMouse) {
			Vx = 8.5f;
			Vy = 8.5f;
		}
		float Wx = ClientRectangle.Width; // размер окна по горизонтали
		float Wy = ClientRectangle.Height; // размер окна по вертикали
		float aspectFig = Vx / Vy; // соотношение сторон рисунка
		float aspectForm = Wx / Wy;
		float Sx, Sy;
		if (keepAspectRatio) {
			Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
		}
		else {
			Sx = Wx / Vx;
			Sy = Wy / Vy;
		}
		float Ty = Sy * Vy;
		g->Clear(Color::White);
		Pen ^ redPen = gcnew Pen(Color::Red);
		redPen->Width = 2;
		if (!printMouse){
		float lines[] = { // лицо + бант, левая половина
			8.f,1.f,10.f,1.f,
			8.f,1.f,7.f,2.f,
			7.f,2.f,6.f,4.f,
			6.f,4.f,7.f,6.f,
			7.f,6.f,5.f,7.f,
			5.f,7.f,5.f,8.f,
			5.f,8.f,6.f,9.f,
			6.f,9.f,8.f,8.f,
			8.f,8.f,10.f,8.f,
			5.f,8.f,1.f,13.f,
			1.f,13.f,1.f,15.f,
			1.f,15.f,2.f,14.f,
			2.f,14.f,1.f,16.f,
			1.f,16.f,2.f,17.f,
			2.f,17.f,3.f,15.f,
			3.f,15.f,2.f,18.f,
			2.f,18.f,4.f,20.f,
			4.f,20.f,4.f,15.f,
			4.f,15.f,5.f,13.f,
			5.f,13.f,5.f,11.f,
			5.f,11.f,7.f,9.f,
			7.f,9.f,9.f,9.f,
			9.f,9.f,10.f,11.5f,
			10.f,11.5f,9.f,14.f,
			9.f,14.f,7.f,14.f,
			7.f,14.f,5.f,13.f,
			7.f,11.f,8.f,11.f,
			8.f,11.f,9.f,13.f,
			9.f,13.f,8.f,14.f,
			8.f,14.f,8.f,13.f,
			8.f,13.f,7.f,13.f,
			7.f,13.f,7.f,14.f,
			7.f,14.f,6.f,13.f,
			6.f,13.f,7.f,11.f,
			9.f,14.f,7.f,15.f,
			7.f,15.f,6.f,17.f,
			6.f,17.f,5.f,17.f,
			5.f,17.f,4.f,18.f,
			6.f,17.f,7.f,18.f,
			7.f,18.f,10.f,19.f,
			6.f,18.f,5.f,19.f,
			6.f,19.f,7.f,20.f,
			7.f,20.f,10.f,21.f,
			10.f,22.f,7.f,21.f,
			7.f,21.f,5.f,19.f,
			10.f,24.f,9.f,24.f,
			9.f,24.f,5.f,22.f,
			5.f,22.f,4.f,20.f,
			10.f,14.f,9.f,14.f,
			10.f,25.f,6.f,29.f,
			6.f,29.f,6.f,23.f,
			6.f,23.f,10.f,27.f
		};
		unsigned int arrayLength = sizeof(lines) / sizeof(float);
		for (int i = 0; i < arrayLength; i += 4) {
			g->DrawLine(redPen, Sx * lines[i], Sy * lines[i + 1]
				, Sx * lines[i + 2], Sy * lines[i + 3]);
			g->DrawLine(redPen, Sx * (10 - lines[i] + 10), Sy * (lines[i + 1])
				, Sx * (10 - lines[i + 2] + 10), Sy * (lines[i + 3]));
		// относительно прямой x = 10, отражаем лицо и бант
		}
		// узор на банте левая половина
		float uzor[] = {
			//квадр
			8.f, 26.f, 7.f, 26.f,
			7.f, 26.f, 7.f, 27.f,
			7.f, 27.f, 8.f, 27.f,
			8.f, 27.f, 8.f, 26.f,
			//тр низ
			7.f, 28.f, 6.f, 27.f,
			7.f, 28.f, 6.f, 29.f,
			//тр верх
			6.f, 26.f, 7.f, 25.f,
			7.f, 25.f, 6.f, 24.f
		};
		unsigned int arrayLength2 = sizeof(uzor) / sizeof(float);
		for (int i = 0; i < arrayLength2; i += 4) {
			g->DrawLine(redPen, Sx * uzor[i], Sy * uzor[i + 1]
				, Sx * uzor[i + 2], Sy * uzor[i + 3]);
			g->DrawLine(redPen, Sx * (10-uzor[i]+10), Sy *(-1 + uzor[i + 1])
				, Sx * (10-uzor[i + 2]+10), Sy * (-1 + uzor[i + 3]));
		// отражаем узор относительно x = 10 и относительно y = 26
		}
		// бантик звездочка
		float star[] = {
			12.f, 7.f, 15.f, 5.f,
			15.f, 4.f, 16.f, 3.f,
			16.f, 3.f, 16.f, 4.f,
			16.f, 4.f, 17.f, 5.f,
			17.f, 5.f, 16.f, 5.f,
			16.f, 5.f, 15.f, 6.f,
			15.f, 6.f, 15.f, 5.f,
			15.f, 5.f, 14.f, 4.f,
			14.f, 4.f, 15.f, 4.f,
			15.f, 4.f, 16.f, 4.f,
			16.f, 4.f, 16.f, 5.f,
			16.f, 5.f, 15.f, 5.f,
			15.f, 5.f, 15.f, 4.f
		};
		unsigned int arrayLength3 = sizeof(star) / sizeof(float);
		for (int i = 0; i < arrayLength3; i += 4) {
			g->DrawLine(redPen, Sx* star[i], Sy * star[i + 1]
				, Sx* star[i + 2], Sy * star[i + 3]);
		}
		}
		else {
			float mouse[] = {
				0.5f,3.f,1.f,4.5f, // от левой щеки вверх до уха
				1.f,4.5f,0.5f,6.f, // левое ухо слева снизу вверх
				0.5f,6.f,0.5f, 7.5f, // левое ухо слева
				0.5f, 7.5f,1.f,8.f, // левое ухо верх слева
				1.f,8.f,1.5f,8.f, // левое ухо верх середина
				1.5f,8.f,2.f,7.5f, // левое ухо верх справа
				2.f,7.5f,1.5f, 6.f, // левое ухо справа сверху вниз
				1.5f, 6.f,1.5f,4.5f, // левое ухо справа до макушки
				1.5f,4.5f,3.f,4.5f, // макушка
				3.f,4.5f,3.f,6.f, // правое ухо слева снизу вверх
				3.f,6.f,2.5f,7.5f, // правое ухо слева
				2.5f,7.5f,3.f,8.f, // правое ухо верх слева
				3.f,8.f,3.5f,8.f, // правое ухо верх середина
				3.5f,8.f,4.f,7.5f, // правое ухо верх справа
				4.f,7.5f,4.f,6.f, // правое ухо сверху вниз
				4.f,6.f,3.5f,4.5f, // правое ухо справа
				3.5f,4.5f,4.f,3.f, // от правого уха вниз до щеки
				4.f,3.f,3.5f,1.5f, // правая скула
				3.5f,1.5f,2.5f,1.f, // подбородок справа
				2.5f,1.f,2.f,1.f, // подбородок снизу
				2.f,1.f,1.f,1.5f, // подбородок слева
				1.f,1.5f,0.5f,3.f, // левая скула
				// туловище
				4.f,3.f,5.5f,3.5f, // спина от головы вправо
				5.5f,3.5f,7.f,3.5f, // спина верх
				7.f,3.5f,7.5f,2.5f, // спина сверху до хвоста
				7.5f,2.5f,8.f,2.5f, // хвост сверху
				8.f,2.5f,8.f,2.f, // хвост справа
				8.f,2.f,7.5f,2.f, // хвост низ справа налево
				7.5f,2.f,7.5f,0.5f, // задняя нога справа сверху вниз
				7.5f,0.5f,6.5f,0.5f, // задняя нога низ
				6.5f,0.5f,6.5f,1.f, // задняя нога слева
				6.5f,1.f,6.f,1.f, // между задних ног
				6.f,1.f,6.f,0.5f, // левая задняя нога справа
				6.f,0.5f,5.f,0.5f, // левая задняя нога низ
				5.f,0.5f,5.f,1.f, // левая задняя нога слева
				5.f,1.f,4.f,1.f, // между задними и передними ногами
				4.f,1.f,4.f,0.5f, // правая передняя нога справа
				4.f,0.5f,3.f,0.5f, // правая передняя нога низ
				3.f,0.5f,3.f,1.f, // правая передняя нога слева
				3.f,1.f,2.5f,1.f, // между передних ног
				2.5f,1.f,2.5f,0.5f, // передняя нога справа
				2.5f,0.5f,1.5f,0.5f, // передняя нога низ
				1.5f,0.5f,1.5f,1.25f, // передняя нога слева
				1.5f,3.5f,1.5f,3.f, // левый глаз слева сверху вниз
				1.5f,3.f,2.f,3.f, // левый глаз низ
				2.f, 3.f,2.f,3.5f, // левый глаз справа
				2.f,3.5f,1.5f,3.5f, // левый глаз верх
				// правый глаз
				2.5f,3.5f,2.5f,3.f, // правый глаз слева
				2.5f,3.f,3.f, 3.f, // правый глаз снизу
				3.f,3.f,3.f,3.5f, // правый глаз справа
				3.f,3.5f,2.5f,3.5f, // правый глаз сверху
				// ушные раковины
				1.f,5.5f,1.f,7.f, // левая ушная раковина
				3.5f,5.5f,3.5f,7.f, // правая ушная раковина
				// нос
				2.f,2.5f,2.5f,2.5f, // нос сверху
				2.5f,2.5f,2.25f,2.f, // нос справа
				2.25f,2.f,2.f,2.5f // нос слева
			};
			unsigned int arrayLength4 = sizeof(mouse) / sizeof(float);
			for (int i = 0; i < arrayLength4; i += 4) {
				g->DrawLine(redPen, Sx * mouse[i], Ty - Sy * mouse[i + 1]
					, Sx * mouse[i + 2], Ty - Sy * mouse[i + 3]);
			}
		}
	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		Refresh();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		keepAspectRatio = true; // начальное значение: сохранять соотношение сторон рисунка
		printMouse = true;
	}
private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode) {
	case Keys::M:
		keepAspectRatio = !keepAspectRatio;
		break;
	case Keys::N:
		printMouse = !printMouse;
		break;
	default:
		break;
	}
	Refresh();

}
};
}
