#pragma once
#include "Matrix.h"
#include "Transform.h"
#include <math.h>
#include <sstream>
#include <algorithm>
#include "Clip.h"
using namespace std;

namespace Razinov2 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	vector<model> models;
	float Vx;
	float Vy;
	float aspectFig;
	mat3 T; // матрица, в которой накапливаются все преобразования
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
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	protected:
	private: System::Windows::Forms::Button^ btnOpen;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// btnOpen
			// 
			this->btnOpen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnOpen->Location = System::Drawing::Point(984, 12);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(225, 32);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"Открыть";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MyForm::btnOpen_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1221, 685);
			this->Controls->Add(this->btnOpen);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(155, 120);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: float left = 30, right = 100, top = 20, bottom = 50;
		   float minX = left, maxX; // диапазон изменения координат x
		   float minY = top, maxY; // диапазон изменения координат y
		   float Wcx = left, Wcy; // координаты левого нижнего угла прямоугольника
		   float Wx, Wy; // ширина и высота прямоугольника
	private: System::Void rectCalc() {
		maxX = ClientRectangle.Width - right; // диапазон изменения координат x
		maxY = ClientRectangle.Height - bottom; // диапазон изменения координат y
		Wcy = maxY; // координаты левого нижнего угла прямоугольника
		Wx = maxX - left; // ширина прямоугольника
		Wy = maxY - top; // ширина и высота прямоугольника
	}

	private: bool keepAspectRatio;
	private: bool printMouse;
private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics ^ g = e->Graphics;
	g->Clear(Color::White);
	
	Pen ^ rectPen = gcnew Pen(Color::Black, 2);
	g->DrawRectangle(rectPen, left, top, Wx, Wy);
	for (int k = 0; k < models.size(); k++) { // цикл по рисункам
		 vector<path> figure = models[k].figure; // список ломаных очередного рисунка
		 mat3 TM = T * models[k].modelM; // матрица общего преобразования рисунка
		 for (int i = 0; i < figure.size(); i++) {
			 path lines = figure[i]; // lines - очередная ломаная линия
			 Pen ^ pen = gcnew Pen(Color::FromArgb(lines.color.x, lines.color.y, lines.color.z));
			 pen->Width = lines.thickness;
			
				 vec2 start = normalize(TM * vec3(lines.vertices[0], 1.0)); // начальная точка первого отрезка
			for (int j = 1; j < lines.vertices.size(); j++) { // цикл по конечным точкам (от единицы)
				 vec2 end = normalize(TM * vec3(lines.vertices[j], 1.0)); // конечная точка
				 vec2 tmpEnd = end; // продублировали координаты точки для будущего использования
				 if (clip(start, end, minX, minY, maxX, maxY)) { // если отрезок видим
					 // после отсечения, start и end - концы видимой части отрезка
						 g->DrawLine(pen, start.x, start.y, end.x, end.y); // отрисовка видимых частей
				
				}
				start = tmpEnd; // конечная точка неотсеченного отрезка становится начальной точкой следующего
				
			}
		}
	}
}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
		Refresh();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		rectCalc();
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		float Wcx = ClientRectangle.Width / 2.f; // координаты центра
		float Wcy = ClientRectangle.Height / 2.f; // текущего окна
		switch (e->KeyCode) {
		case Keys::Escape:
			T = initT;
			break;
		case Keys::Q:
			T = translate(-(Wx - left - right) / 2, -(Wy - bottom - top) / 2) * T; // перенос начала координат в (Wcx, Wcy)
			T = rotate(0.01f) * T; // поворот на 0.01 радиан относительно
			// нового центра
			T = translate((Wx - left - right) / 2, (Wy - bottom - top) / 2) * T; // перенос начала координат обратно
			break;
		case Keys::W:
			T = translate(0.f, -1.f) * T;
			break;
		case Keys::E: // поворот на 0.01 радиан по часовой стрелке
			// 
			T = translate(-(Wx - left - right) / 2, -(Wy - bottom - top) / 2) * T; // перенос начала координат в (Vx, Vy)
			T = rotate(-0.01f) * T; // поворот на 0.01 радиан относительно
			T = translate((Wx - left - right) / 2, (Wy - bottom - top) / 2) * T;
			break;
		case Keys::S: // свдиг вниз на 1 px
			//
			T = translate(0.f, 1.f) * T;
			break;
		case Keys::A: // свдиг влево на 1 px
			//
			T = translate(-1.f, 0.f) * T;
			break;
		case Keys::D: // свдиг вправо на 1 px
			//
			T = translate(1.f, 0.f) * T;
			break;
		case Keys::R: // поворот по часовой на 0.05 радиан
			//
			//T = translate(-Vx / 2, -Vy / 2) * T;
			//T = translate(Wx / 2 + Wcx, Wcy - Wy / 2) * T; // перенос начала координат в (Vx, Vy)
			T = translate(-(Wx - left - right) / 2, -(Wy - bottom - top) / 2) * T;
			T = rotate(-0.05f) * T; // поворот на 0.01 радиан относительно
			T = translate((Wx - left - right) / 2, (Wy - bottom - top) / 2) * T;
			//T = translate(-(Wx / 2 + Wcx), -(Wcy - Wy / 2)) * T;
			//T = translate(Vx / 2, Vy / 2) * T;
			break;
		case Keys::Y: // поврот против часовой на 0.05 радиан
			//
			T = translate(-(Wx - left - right) / 2, -(Wy - bottom - top) / 2) * T; // перенос начала координат в (Vx, Vy)
			T = rotate(0.05f) * T; // поворот на 0.01 радиан относительно
			T = translate((Wx - left - right) / 2, (Wy - bottom - top) / 2) * T;
			break;
		case Keys::T: // сдвиг вверх на 10 px
			//
			T = translate(0.f, -10.f) * T;
			break;
		case Keys::G: // сдвиг вниз на 10 px
			//
			T = translate(0.f, 10.f) * T;
			break;
		case Keys::F: // сдвиг влево на 10 px
			//
			T = translate(-10.f, 0.f) * T;
			break;
		case Keys::H: // сдвиг вправо на 10 px
			//
			T = translate(10.f, 0.f) * T;
			break;
		case Keys::Z: // увеличение в 1.1 раза
			//
			T = translate(-(Wx - left - right) / 2, -(Wy - bottom - top) / 2) * T;
			T = scale(1.1f) * T;
			T = translate((Wx - left - right) / 2, (Wy - bottom - top) / 2) * T;
			break;
		case Keys::X: // уменьшение в 1.1 раз
			//
			T = translate(-(Wx - left - right) / 2, -(Wy - bottom - top) / 2) * T;
			T = scale((1 / 1.1f)) * T;
			T = translate((Wx - left - right) / 2, (Wy - bottom - top) / 2) * T;
			break;
		case Keys::U: // отражение отн Ox центр
			//
			T = translate(-(Wx - left - right) / 2, -(Wy - bottom - top) / 2) * T;
			T = mirrorX() * T;
			T = translate((Wx - left - right) / 2, (Wy - bottom - top) / 2) * T;
			break;
		case Keys::J: // отражение отн Oy центр
			//
			T = translate(-(Wx - left - right) / 2, -(Wy - bottom - top) / 2) * T;
			T = mirrorY() * T;
			T = translate((Wx - left - right) / 2, (Wy - bottom - top) / 2) * T;
			break;
		case Keys::I: // растяжение по X в 1.1 раз
			T = translate(-(Wx - left - right) / 2, -(Wy - bottom - top) / 2) * T;
			T = scale(1.1f, 1.f) * T;
			T = translate((Wx - left - right) / 2, (Wy - bottom - top) / 2) * T;
			break;
		case Keys::K: // сжатие по X в 1.1 раз
			//
			T = translate(-(Wx - left - right) / 2, -(Wy - bottom - top) / 2) * T;
			T = scale((1/1.1f), 1.f) * T;
			T = translate((Wx - left - right) / 2, (Wy - bottom - top) / 2) * T;
			break;
		case Keys::O: // растяжение по Y в 1.1 раз
			//
			T = translate(-(Wx - left - right) / 2, -(Wy - bottom - top) / 2) * T;
			T = scale(1.f, 1.1f) * T;
			T = translate((Wx - left - right) / 2, (Wy - bottom - top) / 2) * T;
			break;
		case Keys::L: // сжатие по Y в 1.1 раз
			//
			T = translate(-(Wx - left - right) / 2, -(Wy - bottom - top) / 2) * T;
			T = scale(1.f, (1 / 1.1f)) * T;
			T = translate((Wx - left - right) / 2, (Wy - bottom - top) / 2) * T;
			break;
		default:
			break;
		}
		Refresh();
	}
		   ///
	private: System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// в файловом диалоге нажата кновка OK
			// перезапись имени файла из openFileDialog->FileName в fileName
			wchar_t fileName[1024]; // переменная, в которой посимвольно сохраним имя файла
			for (int i = 0; i < openFileDialog->FileName->Length; i++)
				fileName[i] = openFileDialog->FileName[i];
			fileName[openFileDialog->FileName->Length] = '\0';
			// объявление и открытие файла
			ifstream in;
			in.open(fileName);
			if (in.is_open()) {
				// файл успешно открыт
				models.clear(); // очищаем имеющийся список ломаных
				// временные переменные для чтения из файла
				mat3 M = mat3(1.f); // матрица для получения модельной матрицы
				mat3 initM; // матрица для начального преобразования каждого рисунка
				vector<mat3> transforms; // стек матриц преобразований
				vector<path> figure; // список ломаных очередного рисунка
				float thickness = 2; // толщина со значением по умолчанию 2
				float r, g, b; // составляющие цвета
				r = g = b = 0; // значение составляющих цвета по умолчанию (черный)
				string cmd; // строка для считывания имени команды
				// непосредственно работа с файлом
				string str; // строка, в которую считываем строки файла
				getline(in, str); // считываем из входного файла первую строку
				while (in) { // если очередная строка считана успешно
					// обрабатываем строку
					if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#')) {
						// прочитанная строка не пуста и не комментарий
						stringstream s(str); // строковый поток из строки str
						s >> cmd;
						if (cmd == "frame") { // размеры изображения
							s >> Vx >> Vy; // считываем глобальные значение Vx и Vy
							aspectFig = Vx / Vy; // обновление соотношения сторон
							
							float aspectRect = Wx / Wy; // соотношение сторон окна рисования
							// коэффициент увеличения при сохранении исходного соотношения сторон
							mat3 T1 = translate(-Vx / 2, -Vy / 2);
							float S = aspectFig < aspectRect ? Wy / Vy : Wx / Vx;
							mat3 S1 = scale(S, -S);
							mat3 T2 = translate(Wx / 2 + Wcx, Wcy - Wy / 2);
							float Tx = left;
							float Ty = S * Vy + top; // смещение в положительную сторону по оси Oy после смены знака
							initT = T2 * (S1 * T1); // преобразования применяются справа налево
							T = initT;
						}
						else if (cmd == "color") { // цвет линии
							s >> r >> g >> b; // считываем три составляющие цвета
						}
						else if (cmd == "thickness") { // толщина линии
							s >> thickness; // считываем значение толщины
						}
						else if (cmd == "path") { // набор точек
							vector<vec2> vertices; // список точек ломаной
							int N; // количество точек
							s >> N;
							string str1; // дополнительная строка для чтения из файла
							while (N > 0) { // пока не все точки считали
								getline(in, str1); // считываем в str1 из входного файла очередную строку
								// так как файл корректный, то на конец файла проверять не нужно
								if ((str1.find_first_not_of(" \t\r\n") != string::npos) && (str1[0] != '#')) {
									// прочитанная строка не пуста и не комментарий
									// значит в ней пара координат
									float x, y; // переменные для считывания
									stringstream s1(str1); // еще один строковый поток из строки str1
									s1 >> x >> y;
									vertices.push_back(vec2(x, y)); // добавляем точку в список
									N--; // уменьшаем счетчик после успешного считывания точки
								}
							}
							// все точки считаны, генерируем ломаную (path) и кладем ее в список figure
							figure.push_back(path(vertices, vec3(r, g, b), thickness));
						}
						else if (cmd == "model") { // начало описания нового рисунка
							float mVcx, mVcy, mVx, mVy; // параметры команды model
							s >> mVcx >> mVcy >> mVx >> mVy; // считываем значения переменных
							float S = mVx / mVy < 1 ? 2.f / mVy : 2.f / mVx;
							// сдвиг точки привязки из начала координат в нужную позицию
							// после которого проводим масштабирование
							initM = scale(S) * translate(-mVcx, -mVcy);
							figure.clear();
						}
						else if (cmd == "figure") { // формирование новой модели
							models.push_back(model(figure, M * initM)); // добавляем рисунок в список
						}
						else if (cmd == "translate") { // перенос
							float Tx, Ty; // параметры преобразования переноса
							s >> Tx >> Ty; // считываем параметры
							M = translate(Tx, Ty) * M; // добавляем перенос к общему преобразованию
						}
						else if (cmd == "scale") { // масштабирование
							float S; // параметр масштабирования
							s >> S; // считываем параметр
							M = scale(S) * M; // добавляем масштабирование к общему преобразованию
						}
						else if (cmd == "rotate") { // поворот
							float theta; // угол поворота в градусах
							s >> theta; // считываем параметр
							M = rotate(-theta / 180.f * Math::PI) * M; // добавляем поворот к общему преобразованию
						}
						else if (cmd == "pushTransform") { // сохранение матрицы в стек
							transforms.push_back(M); // сохраняем матрицу в стек
						}
						else if (cmd == "popTransform") { // откат к матрице из стека
							M = transforms.back(); // получаем верхний элемент стека
							transforms.pop_back(); // выкидываем матрицу из стека
						}
					}
					// считываем очередную строку
					getline(in, str);
				}
				Refresh();
			}
		}
	}
		   ///
	};
}