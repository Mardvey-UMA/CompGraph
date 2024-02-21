#pragma once

namespace Razinov2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	float lines[] = { // стороны клоуняры
				8.f,29.f,10.f,29.f,
				8.f,29.f,7.f,28.f,
				7.f,28.f,6.f,26.f,
				6.f,26.f,7.f,24.f,
				7.f,24.f,5.f,23.f,
				5.f,23.f,5.f,22.f,
				5.f,22.f,6.f,21.f,
				6.f,21.f,8.f,22.f,
				8.f,22.f,10.f,22.f,
				5.f,22.f,1.f,17.f,
				1.f,17.f,1.f,15.f,
				1.f,15.f,2.f,16.f,
				2.f,16.f,1.f,14.f,
				1.f,14.f,2.f,13.f,
				2.f,13.f,3.f,15.f,
				3.f,15.f,2.f,12.f,
				2.f,12.f,4.f,10.f,
				4.f,10.f,4.f,15.f,
				4.f,15.f,5.f,17.f,
				5.f,17.f,5.f,19.f,
				5.f,19.f,7.f,21.f,
				7.f,21.f,9.f,21.f,
				9.f,21.f,10.f,18.5f,
				10.f,18.5f,9.f,16.f,
				9.f,16.f,7.f,16.f,
				7.f,16.f,5.f,17.f,
				7.f,19.f,8.f,19.f,
				8.f,19.f,9.f,17.f,
				9.f,17.f,8.f,16.f,
				8.f,16.f,8.f,17.f,
				8.f,17.f,7.f,17.f,
				7.f,17.f,7.f,16.f,
				7.f,16.f,6.f,17.f,
				6.f,17.f,7.f,19.f,
				9.f,16.f,7.f,15.f,
				7.f,15.f,6.f,13.f,
				6.f,13.f,5.f,13.f,
				5.f,13.f,4.f,12.f,
				6.f,13.f,7.f,12.f,
				7.f,12.f,10.f,11.f,
				6.f,12.f,5.f,11.f,
				6.f,11.f,7.f,10.f,
				7.f,10.f,10.f,9.f,
				10.f,8.f,7.f,9.f,
				7.f,9.f,5.f,11.f,
				10.f,6.f,9.f,6.f,
				9.f,6.f,5.f,8.f,
				5.f,8.f,4.f,10.f,
				10.f,16.f,9.f,16.f,
				10.f,5.f,6.f,1.f,
				6.f,1.f,6.f,7.f,
				6.f,7.f,10.f,3.f
	};
		float uzor[] = {
			8.f,4.f,7.f,4.f,
			7.f,4.f,7.f,3.f,
			7.f,3.f,8.f,3.f,
			8.f,3.f,8.f,4.f,
			7.f,2.f,6.f,3.f,
			7.f,2.f,6.f,1.f,
			6.f,4.f,7.f,5.f,
			7.f,5.f,6.f,6.f
		};
	float star[] = { // звездочка
				12.f,23.f,15.f,25.f,
				15.f,26.f,16.f,27.f,
				16.f,27.f,16.f,26.f,
				16.f,26.f,17.f,25.f,
				17.f,25.f,16.f,25.f,
				16.f,25.f,15.f,24.f,
				15.f,24.f,15.f,25.f,
				15.f,25.f,14.f,26.f,
				14.f,26.f,15.f,26.f,
				15.f,26.f,16.f,26.f,
				16.f,26.f,16.f,25.f,
				16.f,25.f,15.f,25.f,
				15.f,25.f,15.f,26.f
	};
	float mouse[] = { // мышка
				0.5f,3.f,1.f,4.5f, 
				1.f,4.5f,0.5f,6.f, 
				0.5f,6.f,0.5f, 7.5f,
				0.5f, 7.5f,1.f,8.f,
				1.f,8.f,1.5f,8.f, 
				1.5f,8.f,2.f,7.5f,
				2.f,7.5f,1.5f, 6.f, 
				1.5f, 6.f,1.5f,4.5f,
				1.5f,4.5f,3.f,4.5f, 
				3.f,4.5f,3.f,6.f, 
				3.f,6.f,2.5f,7.5f,
				2.5f,7.5f,3.f,8.f, 
				3.f,8.f,3.5f,8.f, 
				3.5f,8.f,4.f,7.5f, 
				4.f,7.5f,4.f,6.f, 
				4.f,6.f,3.5f,4.5f, 
				3.5f,4.5f,4.f,3.f, 
				4.f,3.f,3.5f,1.5f, 
				3.5f,1.5f,2.5f,1.f, 
				2.5f,1.f,2.f,1.f, 
				2.f,1.f,1.f,1.5f, 
				1.f,1.5f,0.5f,3.f, 
				4.f,3.f,5.5f,3.5f, 
				5.5f,3.5f,7.f,3.5f, 
				7.f,3.5f,7.5f,2.5f, 
				7.5f,2.5f,8.f,2.5f, 
				8.f,2.5f,8.f,2.f, 
				8.f,2.f,7.5f,2.f, 
				7.5f,2.f,7.5f,0.5f, 
				7.5f,0.5f,6.5f,0.5f, 
				6.5f,0.5f,6.5f,1.f, 
				6.5f,1.f,6.f,1.f, 
				6.f,1.f,6.f,0.5f, 
				6.f,0.5f,5.f,0.5f, 
				5.f,0.5f,5.f,1.f,
				5.f,1.f,4.f,1.f, 
				4.f,1.f,4.f,0.5f,
				4.f,0.5f,3.f,0.5f, 
				3.f,0.5f,3.f,1.f, 
				3.f,1.f,2.5f,1.f,
				2.5f,1.f,2.5f,0.5f, 
				2.5f,0.5f,1.5f,0.5f, 
				1.5f,0.5f,1.5f,1.25f, 
				1.5f,3.5f,1.5f,3.f, 
				1.5f,3.f,2.f,3.f, 
				2.f, 3.f,2.f,3.5f, 
				2.f,3.5f,1.5f,3.5f, 
				2.5f,3.5f,2.5f,3.f,
				2.5f,3.f,3.f, 3.f, 
				3.f,3.f,3.f,3.5f, 
				3.f,3.5f,2.5f,3.5f, 
				1.f,5.5f,1.f,7.f, 
				3.5f,5.5f,3.5f,7.f, 
				2.f,2.5f,2.5f,2.5f, 
				2.5f,2.5f,2.25f,2.f, 
				2.25f,2.f,2.f,2.5f
	};
	unsigned int arrayLength = sizeof(lines) / sizeof(float);
	unsigned int arrayLength2 = sizeof(uzor) / sizeof(float);
	unsigned int arrayLength3 = sizeof(star) / sizeof(float);
	unsigned int arrayLength4 = sizeof(mouse) / sizeof(float);
	float Vx;
	float Vy;
	float aspectFig;
	mat3 T = mat3(1.f); // матрица, в которой накапливаются все преобразования
	mat3 initT; // матрица начального преобразования
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
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
		Vx = 20.f;
		Vy = 30.f;
		if (printMouse) {
			Vx = 8.5f;
			Vy = 8.5f;
		}
		aspectFig = Vx / Vy;
		float Wx = ClientRectangle.Width; 
		float Wy = ClientRectangle.Height; 
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
		Pen^ redPen = gcnew Pen(Color::Red);
		redPen->Width = 2;
		initT = translate(0.f, Ty) * scale(Sx, -Sy);
		mat3 M = T * initT;
		if (!printMouse) {
			// рисуем клоуняру
			for (int i = 0; i < arrayLength; i += 4) {
				vec3 A1 = vec3(lines[i], lines[i + 1], 1.f);
				vec3 B1 = vec3(lines[i + 2], lines[i + 3], 1.f);
				vec3 A2 = vec3((20 - lines[i]), lines[i + 1], 1.f);
				vec3 B2 = vec3((20 - lines[i + 2]), lines[i + 3], 1.f);
				vec2 a1 = normalize(M * A1);
				vec2 b1 = normalize(M * B1);
				vec2 a2 = normalize(M * A2);
				vec2 b2 = normalize(M * B2);
				g->DrawLine(redPen, a1.x, a1.y, b1.x, b1.y);
				g->DrawLine(redPen, a2.x, a2.y, b2.x, b2.y);
				//g->DrawLine(redPen, Sx * lines[i], Ty - Sy * lines[i + 1]
				//	, Sx * lines[i + 2], Ty - Sy * lines[i + 3]);
				//g->DrawLine(redPen, Sx * (20 - lines[i]), Ty - Sy * (lines[i + 1])
				//	, Sx * (20 - lines[i + 2]), Ty - Sy * (lines[i + 3]));
			}
			
			for (int i = 0; i < arrayLength2; i += 4) {
				g->DrawLine(redPen, Sx * uzor[i], Ty - Sy * uzor[i + 1]
					, Sx * uzor[i + 2], Ty - Sy * uzor[i + 3]);
				g->DrawLine(redPen, Sx * (10 - uzor[i] + 10), Ty - Sy * (1+uzor[i + 1])
					, Sx * (10 - uzor[i + 2] + 10), Ty - Sy * (1+uzor[i + 3]));
			}

			for (int i = 0; i < arrayLength3; i += 4) {
				g->DrawLine(redPen, Sx * star[i], Ty - Sy * star[i + 1]
					, Sx * star[i + 2], Ty - Sy * star[i + 3]);
			}
		}
		else {
			// рисовать мышку
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
		keepAspectRatio = true; 
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