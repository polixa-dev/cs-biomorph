#include "windows.h"
#pragma once
namespace biomorph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		Graphics ^gr;
		Bitmap ^bmap;
		Color clr;
	private:
		SolidBrush ^br;
	public:
		int upper, lower, n, centerX, centerY;
		PointF u, uI, v, vI;
		double lmt;
		array<double, 2> ^arra;
		String ^s;
		String ^ver = "v0.8 - unstable_release_candidate";
			 
	public:
		mainForm(void)
		{
			InitializeComponent();
		}

	public:
		void grInit(void) {
			bmap = gcnew Bitmap(pictureboxFirst->Width, pictureboxFirst->Height);
			gr = Graphics::FromImage(bmap);
			gr->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
		}

		void pictureShow(void) {
			pictureboxFirst->BackgroundImage = bmap;
			if (!pictureboxFirst->Visible) {
				pictureboxFirst->Visible = true;
			}
		}
		
		int coordinateMutation(float a, int isY)
		{
			if (isY == 1)
			{
				return safe_cast<int>(centerY - a * 150);
			}
			return safe_cast<int>(centerX + a * 150);
		}

		void drawCell(void) {
			v.X = 0.5f;
			v.Y = 0.0f;

			for (float x = -2; x <= 2; x += 0.002f)
			{
				for (float y = -2; y <= 2; y += 0.002f)
				{
					u.X = x;
					u.Y = y;
					n = 0;

					while ((Math::Abs(u.X) < lower) && (Math::Abs(u.Y) < lower) && (n < upper))
					{
						uI.X = u.X;
						uI.Y = u.Y;
						n++;
						u.X = uI.X * uI.X * uI.X - 3 * uI.X * uI.Y * uI.Y + v.X;
						u.Y = 3 * uI.X * uI.X * uI.Y - uI.Y * uI.Y * uI.Y + v.Y;
					}

					if ((Math::Abs(u.X) >= 300) || (Math::Abs(u.Y) >= 10000))
					{
						br = gcnew SolidBrush(Color::Indigo);
						int xt = coordinateMutation(x, 0);
						int yt = coordinateMutation(y, 1);
						gr->FillRectangle(br, xt, yt, 1, 1);
						pictureboxFirst->BackgroundImage = bmap;
					}
					else
					{
						br = gcnew SolidBrush(Color::Crimson);
						int xt = coordinateMutation(x, 0);
						int yt = coordinateMutation(y, 1);
						gr->FillRectangle(br, xt, yt, 1, 1);
						pictureboxFirst->BackgroundImage = bmap;
					}
				}
			}
		}
		
		void drawSpider(void) {
			for (int y = -centerY; y <= centerY; y++)
			{
				for (int x = -centerX; x <= centerX; x++)
				{
					u.X = x * 0.01f;
					u.Y = y * 0.01f;
					v.X = u.X;
					v.Y = u.Y;
					n = 0;

					while (((u.X * u.X + u.Y * u.Y) < lower) && (n < upper))
					{
						uI.X = u.X;
						uI.Y = u.Y;
						vI.X = v.X;
						vI.Y = v.Y;
						n++;
						
						u.X = (uI.X * uI.X) - (uI.Y * uI.Y) + v.X;
						u.Y = (2 * uI.X * uI.Y) + v.Y;
						v.X = (vI.X / 2) + u.X;
						v.Y = (vI.Y / 2) + u.Y;
						n++;
					}

					if (n < upper)
					{
						int g = (500 * n) % 255;
						int b = (400 * n) % 255;
						
						clr = Color::FromArgb(0, g, b);
						br = gcnew SolidBrush(clr);
						gr->FillRectangle(br, centerX + x, centerY + y, 1, 1);
						pictureboxFirst->BackgroundImage = bmap;
					}
				}
			}
		}

		void drawShip(void) {
			for (int y = -centerY; y <= centerY; y++)
			{
				for (int x = -centerX; x <= centerX; x++)
				{
					n = 0;

					v.X = x * 0.01f - 0.2f;
					v.Y = y * 0.01f - 0.3f;

					u.X = 0.0f;
					u.Y = 0.0f;

					while (((Math::Pow(u.X, 2) + Math::Pow(u.Y, 2)) < lower) && (n < upper))
					{
						uI = u;
						u.X = safe_cast<float>(Math::Pow(uI.X, 2) - Math::Pow(uI.Y, 2) + v.X);
						u.Y = 2 * Math::Abs(uI.X * uI.Y) + v.Y;
						n++;
					}

					if (n < upper)
					{
						int rg = (300 * n) % 255;
						int b = (10 * n) % 255;
						clr = Color::FromArgb(rg, rg, b);
						br = gcnew SolidBrush(clr);

						gr->FillRectangle(br, centerX + x, centerY + y, 1, 1);
					}
				}
			}

			pictureboxFirst->BackgroundImage = bmap;
		}

		void drawLyapunov(void) {
			for (int a = 1; a < pictureboxFirst->Width; a++)
			{
				for (int b = 1; b < pictureboxFirst->Height; b++)
				{
					float x = a / 125.0f,
						y = b / 125.0f,
						xn = 0.5f, rn;

					lmt = 0;

					for (int i = 0; i < 1000; i++)
					{
						int j = i % s->Length;

						if (s[j] == 'A') rn = x;
						else rn = y;

						xn = rn * xn * (1 - xn);
						lmt += Math::Log(Math::Abs(rn * (1.f - 2.f * xn)));
					}

					lmt /= 500;

					if (lmt < -1000000000) lmt = -50.0;
					if (lmt > 1000000000) lmt = 50.0;

					arra[a, b] = lmt;
				}
			}

			for (int a = 1; a < centerX * 2; a++)
			{
				for (int b = 1; b < centerY * 2; b++)
				{
					if (arra[a, b] > 0)
					{
						gr->FillRectangle(gcnew SolidBrush(Color::FromArgb((Math::Abs(safe_cast<int>(arra[a, b])) * 25 + 10) % 255,
							(Math::Abs(safe_cast<int>(arra[a, b])) * 200 + 5) % 255, 0)), a, b, 1, 1);
					}
					else
					{
						gr->FillRectangle(gcnew SolidBrush(Color::FromArgb(Math::Abs(250 - ((Math::Abs(safe_cast<int>(arra[a, b]) * 20) + 30) % 255)),
							(Math::Abs(255 - (Math::Abs(safe_cast<int>(arra[a, b]) * 5) + 200) % 255)), 0)), a, b, 1, 1);
					}
				}
			}
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panelLeft;
	private: System::Windows::Forms::Panel^  panelBottom;
	private: System::Windows::Forms::Panel^  panelShow;
	private: System::Windows::Forms::Label^  labelSign;
	
	private: System::Windows::Forms::Button^  buttonAnimate;
	private: System::Windows::Forms::Button^  buttonStart;

	private: System::Windows::Forms::Label^  labelString;
	private: System::Windows::Forms::Label^  labelLower;
	private: System::Windows::Forms::Label^  labelUpper;
	private: System::Windows::Forms::TextBox^  textboxString;
	private: System::Windows::Forms::TextBox^  textboxLower;
	private: System::Windows::Forms::TextBox^  textboxUpper;

	private: System::Windows::Forms::GroupBox^  groupboxSelect;
	private: System::Windows::Forms::RadioButton^  radioLyapunov;
	private: System::Windows::Forms::RadioButton^  radioShip;
	private: System::Windows::Forms::RadioButton^  radioSpider;
	private: System::Windows::Forms::RadioButton^  radioCell;
	private: System::Windows::Forms::RadioButton^  radioClear;

	private: System::Windows::Forms::PictureBox^  pictureboxFirst;
	private: System::Windows::Forms::PictureBox^  pictureboxSecond;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mainForm::typeid));
			this->panelLeft = (gcnew System::Windows::Forms::Panel());
			this->buttonAnimate = (gcnew System::Windows::Forms::Button());
			this->groupboxSelect = (gcnew System::Windows::Forms::GroupBox());
			this->radioLyapunov = (gcnew System::Windows::Forms::RadioButton());
			this->radioShip = (gcnew System::Windows::Forms::RadioButton());
			this->radioSpider = (gcnew System::Windows::Forms::RadioButton());
			this->radioCell = (gcnew System::Windows::Forms::RadioButton());
			this->radioClear = (gcnew System::Windows::Forms::RadioButton());
			this->labelString = (gcnew System::Windows::Forms::Label());
			this->textboxString = (gcnew System::Windows::Forms::TextBox());
			this->textboxLower = (gcnew System::Windows::Forms::TextBox());
			this->textboxUpper = (gcnew System::Windows::Forms::TextBox());
			this->labelLower = (gcnew System::Windows::Forms::Label());
			this->labelUpper = (gcnew System::Windows::Forms::Label());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->panelBottom = (gcnew System::Windows::Forms::Panel());
			this->labelSign = (gcnew System::Windows::Forms::Label());
			this->panelShow = (gcnew System::Windows::Forms::Panel());
			this->pictureboxFirst = (gcnew System::Windows::Forms::PictureBox());
			this->pictureboxSecond = (gcnew System::Windows::Forms::PictureBox());
			this->panelLeft->SuspendLayout();
			this->groupboxSelect->SuspendLayout();
			this->panelBottom->SuspendLayout();
			this->panelShow->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxFirst))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxSecond))->BeginInit();
			this->SuspendLayout();
			// 
			// panelLeft
			// 
			this->panelLeft->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panelLeft->BackColor = System::Drawing::Color::White;
			this->panelLeft->Controls->Add(this->buttonAnimate);
			this->panelLeft->Controls->Add(this->groupboxSelect);
			this->panelLeft->Controls->Add(this->labelString);
			this->panelLeft->Controls->Add(this->textboxString);
			this->panelLeft->Controls->Add(this->textboxLower);
			this->panelLeft->Controls->Add(this->textboxUpper);
			this->panelLeft->Controls->Add(this->labelLower);
			this->panelLeft->Controls->Add(this->labelUpper);
			this->panelLeft->Controls->Add(this->buttonStart);
			this->panelLeft->Controls->Add(this->panelBottom);
			this->panelLeft->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(201)),
				static_cast<System::Int32>(static_cast<System::Byte>(123)));
			this->panelLeft->Location = System::Drawing::Point(0, 0);
			this->panelLeft->Margin = System::Windows::Forms::Padding(2);
			this->panelLeft->Name = L"panelLeft";
			this->panelLeft->Size = System::Drawing::Size(180, 511);
			this->panelLeft->TabIndex = 0;
			// 
			// buttonAnimate
			// 
			this->buttonAnimate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->buttonAnimate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAnimate->Font = (gcnew System::Drawing::Font(L"Lato Light", 10.25F));
			this->buttonAnimate->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(223)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->buttonAnimate->Location = System::Drawing::Point(50, 385);
			this->buttonAnimate->Name = L"buttonAnimate";
			this->buttonAnimate->Size = System::Drawing::Size(80, 80);
			this->buttonAnimate->TabIndex = 10;
			this->buttonAnimate->Text = L"vivify";
			this->buttonAnimate->UseVisualStyleBackColor = false;
			this->buttonAnimate->Visible = false;
			this->buttonAnimate->Click += gcnew System::EventHandler(this, &mainForm::buttonAnimate_Click);
			// 
			// groupboxSelect
			// 
			this->groupboxSelect->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->groupboxSelect->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->groupboxSelect->Controls->Add(this->radioLyapunov);
			this->groupboxSelect->Controls->Add(this->radioShip);
			this->groupboxSelect->Controls->Add(this->radioSpider);
			this->groupboxSelect->Controls->Add(this->radioCell);
			this->groupboxSelect->Controls->Add(this->radioClear);
			this->groupboxSelect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupboxSelect->Location = System::Drawing::Point(50, -6);
			this->groupboxSelect->Name = L"groupboxSelect";
			this->groupboxSelect->Size = System::Drawing::Size(80, 125);
			this->groupboxSelect->TabIndex = 0;
			this->groupboxSelect->TabStop = false;
			// 
			// radioLyapunov
			// 
			this->radioLyapunov->AutoSize = true;
			this->radioLyapunov->Location = System::Drawing::Point(6, 103);
			this->radioLyapunov->Name = L"radioLyapunov";
			this->radioLyapunov->Size = System::Drawing::Size(71, 17);
			this->radioLyapunov->TabIndex = 4;
			this->radioLyapunov->TabStop = true;
			this->radioLyapunov->Text = L"Lyapunov";
			this->radioLyapunov->UseVisualStyleBackColor = true;
			this->radioLyapunov->CheckedChanged += gcnew System::EventHandler(this, &mainForm::radioLyapunov_CheckedChanged);
			// 
			// radioShip
			// 
			this->radioShip->AutoSize = true;
			this->radioShip->Location = System::Drawing::Point(6, 80);
			this->radioShip->Name = L"radioShip";
			this->radioShip->Size = System::Drawing::Size(44, 17);
			this->radioShip->TabIndex = 3;
			this->radioShip->TabStop = true;
			this->radioShip->Text = L"ship";
			this->radioShip->UseVisualStyleBackColor = true;
			// 
			// radioSpider
			// 
			this->radioSpider->AutoSize = true;
			this->radioSpider->Location = System::Drawing::Point(6, 57);
			this->radioSpider->Name = L"radioSpider";
			this->radioSpider->Size = System::Drawing::Size(54, 17);
			this->radioSpider->TabIndex = 2;
			this->radioSpider->TabStop = true;
			this->radioSpider->Text = L"spider";
			this->radioSpider->UseVisualStyleBackColor = true;
			// 
			// radioCell
			// 
			this->radioCell->AutoSize = true;
			this->radioCell->Location = System::Drawing::Point(6, 34);
			this->radioCell->Name = L"radioCell";
			this->radioCell->Size = System::Drawing::Size(40, 17);
			this->radioCell->TabIndex = 1;
			this->radioCell->TabStop = true;
			this->radioCell->Text = L"cell";
			this->radioCell->UseVisualStyleBackColor = true;
			// 
			// radioClear
			// 
			this->radioClear->AutoSize = true;
			this->radioClear->Location = System::Drawing::Point(6, 11);
			this->radioClear->Name = L"radioClear";
			this->radioClear->Size = System::Drawing::Size(65, 17);
			this->radioClear->TabIndex = 0;
			this->radioClear->TabStop = true;
			this->radioClear->Text = L"(clear all)";
			this->radioClear->UseVisualStyleBackColor = true;
			// 
			// labelString
			// 
			this->labelString->AutoSize = true;
			this->labelString->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->labelString->Location = System::Drawing::Point(73, 245);
			this->labelString->Name = L"labelString";
			this->labelString->Size = System::Drawing::Size(34, 13);
			this->labelString->TabIndex = 6;
			this->labelString->Text = L"string";
			this->labelString->Visible = false;
			// 
			// textboxString
			// 
			this->textboxString->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->textboxString->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(167)));
			this->textboxString->Location = System::Drawing::Point(50, 260);
			this->textboxString->MaxLength = 100;
			this->textboxString->Name = L"textboxString";
			this->textboxString->Size = System::Drawing::Size(80, 21);
			this->textboxString->TabIndex = 9;
			this->textboxString->Visible = false;
			this->textboxString->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &mainForm::textboxString_KeyPress);
			// 
			// textboxLower
			// 
			this->textboxLower->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->textboxLower->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(167)));
			this->textboxLower->Location = System::Drawing::Point(50, 210);
			this->textboxLower->Name = L"textboxLower";
			this->textboxLower->Size = System::Drawing::Size(80, 21);
			this->textboxLower->TabIndex = 8;
			this->textboxLower->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &mainForm::textboxLower_KeyPress);
			// 
			// textboxUpper
			// 
			this->textboxUpper->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->textboxUpper->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(167)));
			this->textboxUpper->Location = System::Drawing::Point(50, 160);
			this->textboxUpper->Name = L"textboxUpper";
			this->textboxUpper->Size = System::Drawing::Size(80, 21);
			this->textboxUpper->TabIndex = 7;
			this->textboxUpper->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &mainForm::textboxUpper_KeyPress);
			// 
			// labelLower
			// 
			this->labelLower->AutoSize = true;
			this->labelLower->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->labelLower->Location = System::Drawing::Point(73, 195);
			this->labelLower->Name = L"labelLower";
			this->labelLower->Size = System::Drawing::Size(33, 13);
			this->labelLower->TabIndex = 5;
			this->labelLower->Text = L"lower";
			// 
			// labelUpper
			// 
			this->labelUpper->AutoSize = true;
			this->labelUpper->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelUpper->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(81)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->labelUpper->Location = System::Drawing::Point(72, 145);
			this->labelUpper->Name = L"labelUpper";
			this->labelUpper->Size = System::Drawing::Size(35, 13);
			this->labelUpper->TabIndex = 4;
			this->labelUpper->Text = L"upper";
			// 
			// buttonStart
			// 
			this->buttonStart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->buttonStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStart->Font = (gcnew System::Drawing::Font(L"Lato Light", 10.25F));
			this->buttonStart->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(201)),
				static_cast<System::Int32>(static_cast<System::Byte>(123)));
			this->buttonStart->Location = System::Drawing::Point(50, 299);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(80, 80);
			this->buttonStart->TabIndex = 3;
			this->buttonStart->Text = L"go";
			this->buttonStart->UseVisualStyleBackColor = false;
			this->buttonStart->Click += gcnew System::EventHandler(this, &mainForm::buttonStart_Click);
			// 
			// panelBottom
			// 
			this->panelBottom->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(167)));
			this->panelBottom->Controls->Add(this->labelSign);
			this->panelBottom->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panelBottom->Location = System::Drawing::Point(0, 471);
			this->panelBottom->Name = L"panelBottom";
			this->panelBottom->Size = System::Drawing::Size(180, 40);
			this->panelBottom->TabIndex = 1;
			// 
			// labelSign
			// 
			this->labelSign->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->labelSign->Font = (gcnew System::Drawing::Font(L"Lato Light", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSign->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->labelSign->Location = System::Drawing::Point(0, 0);
			this->labelSign->Margin = System::Windows::Forms::Padding(0);
			this->labelSign->Name = L"labelSign";
			this->labelSign->Size = System::Drawing::Size(180, 40);
			this->labelSign->TabIndex = 0;
			this->labelSign->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panelShow
			// 
			this->panelShow->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(62)));
			this->panelShow->Controls->Add(this->pictureboxFirst);
			this->panelShow->Controls->Add(this->pictureboxSecond);
			this->panelShow->Location = System::Drawing::Point(205, 25);
			this->panelShow->Name = L"panelShow";
			this->panelShow->Size = System::Drawing::Size(455, 460);
			this->panelShow->TabIndex = 1;
			// 
			// pictureboxFirst
			// 
			this->pictureboxFirst->Location = System::Drawing::Point(9, 10);
			this->pictureboxFirst->Name = L"pictureboxFirst";
			this->pictureboxFirst->Size = System::Drawing::Size(436, 440);
			this->pictureboxFirst->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureboxFirst->TabIndex = 0;
			this->pictureboxFirst->TabStop = false;
			this->pictureboxFirst->Visible = false;
			this->pictureboxFirst->WaitOnLoad = true;
			// 
			// pictureboxSecond
			// 
			this->pictureboxSecond->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureboxSecond.BackgroundImage")));
			this->pictureboxSecond->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureboxSecond->Location = System::Drawing::Point(9, 10);
			this->pictureboxSecond->Name = L"pictureboxSecond";
			this->pictureboxSecond->Size = System::Drawing::Size(436, 440);
			this->pictureboxSecond->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureboxSecond->TabIndex = 1;
			this->pictureboxSecond->TabStop = false;
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->ClientSize = System::Drawing::Size(684, 511);
			this->Controls->Add(this->panelLeft);
			this->Controls->Add(this->panelShow);
			this->Font = (gcnew System::Drawing::Font(L"Lato Light", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"mainForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"biomorph";
			this->Load += gcnew System::EventHandler(this, &mainForm::mainForm_Load);
			this->panelLeft->ResumeLayout(false);
			this->panelLeft->PerformLayout();
			this->groupboxSelect->ResumeLayout(false);
			this->groupboxSelect->PerformLayout();
			this->panelBottom->ResumeLayout(false);
			this->panelShow->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxFirst))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureboxSecond))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void buttonStart_Click(System::Object^  sender, System::EventArgs^  e) {
	grInit();
	
	if (textboxUpper->Text != "") {
		upper = Convert::ToInt32(textboxUpper->Text) % 1111;
		if (upper < 1) upper = 20;
	}
	else upper = 50;

	if (textboxLower->Text != "") {
		lower = Convert::ToInt32(textboxLower->Text) % 2222;
		if (lower < 1) lower = 80;
	}
	else lower = 100;
	
	if (radioClear->Checked) {
		pictureboxFirst->Visible = false;
		textboxLower->Text = "";
		textboxUpper->Text = "";
		textboxString->Text = "";
	}
	else {
		if (radioCell->Checked) {
			drawCell();
		}
		else if (radioSpider->Checked) {
			drawSpider();
		}
		else if (radioShip->Checked) {
			drawShip();
		}

		pictureShow();
	}
}

private: System::Void radioLyapunov_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (radioLyapunov->Checked) {
		labelLower->Visible =  false;
		textboxLower->Visible = false;
		labelUpper->Visible = false;
		textboxUpper->Visible = false;
		buttonStart->Visible = false;

		buttonAnimate->Visible = true;
		labelString->Visible = true;
		textboxString->Visible = true;
	}
	else {
		buttonAnimate->Visible = false;
		labelString->Visible = false;
		textboxString->Visible = false;

		labelLower->Visible = true;
		textboxLower->Visible = true;
		labelUpper->Visible = true;
		textboxUpper->Visible = true;
		buttonStart->Visible = true;
	}
}

private: System::Void textboxString_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (e->KeyChar != 65 && e->KeyChar != 66 && e->KeyChar > 31) {
		e->Handled = true;
	}
}

private: System::Void textboxUpper_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if ((e->KeyChar < 48 || e->KeyChar > 57) && e->KeyChar > 31) {
		e->Handled = true;
	}
}

private: System::Void textboxLower_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if ((e->KeyChar < 48 || e->KeyChar > 57) && e->KeyChar > 31) {
		e->Handled = true;
	}
}

private: System::Void mainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	grInit();
	centerX = pictureboxFirst->Width / 2;
	centerY = pictureboxFirst->Height / 2;
	labelSign->Text = ver + "\r\nby paul polikha";
}

private: System::Void buttonAnimate_Click(System::Object^  sender, System::EventArgs^  e) {
	grInit();
	
	if (textboxString->Text != "") {
		s = textboxString->Text;
	}
	else s = "AB";

	arra = gcnew array<double, 2>(pictureboxFirst->Width, pictureboxFirst->Height);
	lmt = 0.0;

	drawLyapunov();
	pictureShow();
}
};
}
