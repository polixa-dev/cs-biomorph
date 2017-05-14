#pragma once

namespace biomorph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Label^  labelSign;
	private: System::Windows::Forms::Panel^  panelShow;

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
			this->panelLeft = (gcnew System::Windows::Forms::Panel());
			this->panelBottom = (gcnew System::Windows::Forms::Panel());
			this->textboxString = (gcnew System::Windows::Forms::TextBox());
			this->textboxLower = (gcnew System::Windows::Forms::TextBox());
			this->textboxUpper = (gcnew System::Windows::Forms::TextBox());
			this->labelString = (gcnew System::Windows::Forms::Label());
			this->labelLower = (gcnew System::Windows::Forms::Label());
			this->labelUpper = (gcnew System::Windows::Forms::Label());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->labelSign = (gcnew System::Windows::Forms::Label());
			this->panelShow = (gcnew System::Windows::Forms::Panel());
			this->groupboxSelect = (gcnew System::Windows::Forms::GroupBox());
			this->radioClear = (gcnew System::Windows::Forms::RadioButton());
			this->radioCell = (gcnew System::Windows::Forms::RadioButton());
			this->radioSpider = (gcnew System::Windows::Forms::RadioButton());
			this->radioShip = (gcnew System::Windows::Forms::RadioButton());
			this->radioLyapunov = (gcnew System::Windows::Forms::RadioButton());
			this->panelLeft->SuspendLayout();
			this->panelBottom->SuspendLayout();
			this->groupboxSelect->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelLeft
			// 
			this->panelLeft->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top
				| System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panelLeft->BackColor = System::Drawing::Color::White;
			this->panelLeft->Controls->Add(this->groupboxSelect);
			this->panelLeft->Controls->Add(this->textboxString);
			this->panelLeft->Controls->Add(this->textboxLower);
			this->panelLeft->Controls->Add(this->textboxUpper);
			this->panelLeft->Controls->Add(this->labelString);
			this->panelLeft->Controls->Add(this->labelLower);
			this->panelLeft->Controls->Add(this->labelUpper);
			this->panelLeft->Controls->Add(this->buttonStart);
			this->panelLeft->Controls->Add(this->panelBottom);
			this->panelLeft->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(201)),
				static_cast<System::Int32>(static_cast<System::Byte>(123)));
			this->panelLeft->Location = System::Drawing::Point(0, 0);
			this->panelLeft->Margin = System::Windows::Forms::Padding(2);
			this->panelLeft->Name = L"panelLeft";
			this->panelLeft->Size = System::Drawing::Size(180, 461);
			this->panelLeft->TabIndex = 0;
			// 
			// textboxString
			// 
			this->textboxString->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->textboxString->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)),
				static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(167)));
			this->textboxString->Location = System::Drawing::Point(50, 280);
			this->textboxString->Name = L"textboxString";
			this->textboxString->Size = System::Drawing::Size(80, 21);
			this->textboxString->TabIndex = 9;
			// 
			// textboxLower
			// 
			this->textboxLower->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->textboxLower->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)),
				static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(167)));
			this->textboxLower->Location = System::Drawing::Point(50, 220);
			this->textboxLower->Name = L"textboxLower";
			this->textboxLower->Size = System::Drawing::Size(80, 21);
			this->textboxLower->TabIndex = 8;
			// 
			// textboxUpper
			// 
			this->textboxUpper->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->textboxUpper->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)),
				static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(167)));
			this->textboxUpper->Location = System::Drawing::Point(50, 160);
			this->textboxUpper->Name = L"textboxUpper";
			this->textboxUpper->Size = System::Drawing::Size(80, 21);
			this->textboxUpper->TabIndex = 7;
			// 
			// labelString
			// 
			this->labelString->AutoSize = true;
			this->labelString->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->labelString->Location = System::Drawing::Point(72, 260);
			this->labelString->Name = L"labelString";
			this->labelString->Size = System::Drawing::Size(35, 13);
			this->labelString->TabIndex = 6;
			this->labelString->Text = L"String";
			// 
			// labelLower
			// 
			this->labelLower->AutoSize = true;
			this->labelLower->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->labelLower->Location = System::Drawing::Point(72, 200);
			this->labelLower->Name = L"labelLower";
			this->labelLower->Size = System::Drawing::Size(36, 13);
			this->labelLower->TabIndex = 5;
			this->labelLower->Text = L"Lower";
			// 
			// labelUpper
			// 
			this->labelUpper->AutoSize = true;
			this->labelUpper->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelUpper->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(147)),
				static_cast<System::Int32>(static_cast<System::Byte>(81)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->labelUpper->Location = System::Drawing::Point(71, 140);
			this->labelUpper->Name = L"labelUpper";
			this->labelUpper->Size = System::Drawing::Size(37, 13);
			this->labelUpper->TabIndex = 4;
			this->labelUpper->Text = L"Upper";
			// 
			// buttonStart
			// 
			this->buttonStart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->buttonStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStart->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(201)),
				static_cast<System::Int32>(static_cast<System::Byte>(123)));
			this->buttonStart->Location = System::Drawing::Point(50, 327);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(80, 80);
			this->buttonStart->TabIndex = 3;
			this->buttonStart->Text = L"Go";
			this->buttonStart->UseVisualStyleBackColor = false;
			// 
			// panelBottom
			// 
			this->panelBottom->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)),
				static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(167)));
			this->panelBottom->Controls->Add(this->labelSign);
			this->panelBottom->Location = System::Drawing::Point(0, 421);
			this->panelBottom->Name = L"panelBottom";
			this->panelBottom->Size = System::Drawing::Size(180, 40);
			this->panelBottom->TabIndex = 1;
			// 
			// labelSign
			// 
			this->labelSign->AutoSize = true;
			this->labelSign->Font = (gcnew System::Drawing::Font(L"Lato Light", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSign->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->labelSign->Location = System::Drawing::Point(50, 6);
			this->labelSign->Name = L"labelSign";
			this->labelSign->Size = System::Drawing::Size(76, 26);
			this->labelSign->TabIndex = 0;
			this->labelSign->Text = L"0.2-alfa\r\nby paul polikha";
			this->labelSign->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panelShow
			// 
			this->panelShow->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(62)));
			this->panelShow->Location = System::Drawing::Point(205, 25);
			this->panelShow->Name = L"panelShow";
			this->panelShow->Size = System::Drawing::Size(455, 410);
			this->panelShow->TabIndex = 1;
			// 
			// groupboxSelect
			// 
			this->groupboxSelect->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)),
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
			// radioClear
			// 
			this->radioClear->AutoSize = true;
			this->radioClear->Location = System::Drawing::Point(6, 11);
			this->radioClear->Name = L"radioClear";
			this->radioClear->Size = System::Drawing::Size(53, 17);
			this->radioClear->TabIndex = 0;
			this->radioClear->TabStop = true;
			this->radioClear->Text = L"(clear)";
			this->radioClear->UseVisualStyleBackColor = true;
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
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->panelShow);
			this->Controls->Add(this->panelLeft);
			this->Font = (gcnew System::Drawing::Font(L"Lato Light", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"mainForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Biomorph";
			this->panelLeft->ResumeLayout(false);
			this->panelLeft->PerformLayout();
			this->panelBottom->ResumeLayout(false);
			this->panelBottom->PerformLayout();
			this->groupboxSelect->ResumeLayout(false);
			this->groupboxSelect->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
};
}
