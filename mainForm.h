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
			this->labelSign = (gcnew System::Windows::Forms::Label());
			this->panelLeft->SuspendLayout();
			this->panelBottom->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelLeft
			// 
			this->panelLeft->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top
				| System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panelLeft->BackColor = System::Drawing::Color::White;
			this->panelLeft->Controls->Add(this->panelBottom);
			this->panelLeft->Location = System::Drawing::Point(0, 0);
			this->panelLeft->Margin = System::Windows::Forms::Padding(2);
			this->panelLeft->Name = L"panelLeft";
			this->panelLeft->Size = System::Drawing::Size(180, 461);
			this->panelLeft->TabIndex = 0;
			this->panelLeft->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &mainForm::panelLeft_Paint);
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
			this->labelSign->Font = (gcnew System::Drawing::Font(L"Lato Light", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSign->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->labelSign->Location = System::Drawing::Point(50, 6);
			this->labelSign->Name = L"labelSign";
			this->labelSign->Size = System::Drawing::Size(76, 26);
			this->labelSign->TabIndex = 0;
			this->labelSign->Text = L"0.1-alfa\r\nby paul polikha";
			this->labelSign->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelSign->Click += gcnew System::EventHandler(this, &mainForm::label1_Click);
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->ClientSize = System::Drawing::Size(684, 461);
			this->Controls->Add(this->panelLeft);
			this->Font = (gcnew System::Drawing::Font(L"Corbel", 8.25F));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"mainForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Biomorph";
			this->panelLeft->ResumeLayout(false);
			this->panelBottom->ResumeLayout(false);
			this->panelBottom->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panelLeft_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
