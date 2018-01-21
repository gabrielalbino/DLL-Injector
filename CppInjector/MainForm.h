#pragma once
#include "Injector.h"
#include <stdlib.h>  
#include <string.h>  
#include <msclr\marshal.h>  
#include<vector>

namespace CppInjector {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private: Injector* injector;

	public:
		MainForm(void)
		{
			InitializeComponent();
			injector = new Injector();
			updateProcessNames();
			getDLLList();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  titleLabel;
	private: System::Windows::Forms::Button^  injectButton;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::ListBox^  DLLListBox;
	private: System::Windows::Forms::ListBox^  processListBox;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  deleteDLL;
	private: System::Windows::Forms::Button^  addDLL;
	private: System::Windows::Forms::Button^  updateButton;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->injectButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->DLLListBox = (gcnew System::Windows::Forms::ListBox());
			this->processListBox = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->deleteDLL = (gcnew System::Windows::Forms::Button());
			this->addDLL = (gcnew System::Windows::Forms::Button());
			this->updateButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titleLabel->Location = System::Drawing::Point(-7, -2);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(200, 50);
			this->titleLabel->TabIndex = 0;
			this->titleLabel->Text = L"CppInjector";
			this->titleLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// injectButton
			// 
			this->injectButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->injectButton->Location = System::Drawing::Point(12, 261);
			this->injectButton->Name = L"injectButton";
			this->injectButton->Size = System::Drawing::Size(75, 23);
			this->injectButton->TabIndex = 1;
			this->injectButton->Text = L"Injetar";
			this->injectButton->UseVisualStyleBackColor = true;
			// 
			// exitButton
			// 
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->exitButton->Location = System::Drawing::Point(97, 261);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(75, 23);
			this->exitButton->TabIndex = 2;
			this->exitButton->Text = L"Sair";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &MainForm::exitButton_Click);
			// 
			// DLLListBox
			// 
			this->DLLListBox->FormattingEnabled = true;
			this->DLLListBox->Location = System::Drawing::Point(12, 66);
			this->DLLListBox->Name = L"DLLListBox";
			this->DLLListBox->Size = System::Drawing::Size(160, 56);
			this->DLLListBox->TabIndex = 3;
			// 
			// processListBox
			// 
			this->processListBox->FormattingEnabled = true;
			this->processListBox->Location = System::Drawing::Point(12, 170);
			this->processListBox->Name = L"processListBox";
			this->processListBox->Size = System::Drawing::Size(160, 56);
			this->processListBox->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(158, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Selecione uma DLL para injetar:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 154);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Selecione o processo:";
			// 
			// deleteDLL
			// 
			this->deleteDLL->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->deleteDLL->Location = System::Drawing::Point(12, 128);
			this->deleteDLL->Name = L"deleteDLL";
			this->deleteDLL->Size = System::Drawing::Size(75, 23);
			this->deleteDLL->TabIndex = 7;
			this->deleteDLL->Text = L"Apagar";
			this->deleteDLL->UseVisualStyleBackColor = true;
			// 
			// addDLL
			// 
			this->addDLL->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->addDLL->Location = System::Drawing::Point(97, 128);
			this->addDLL->Name = L"addDLL";
			this->addDLL->Size = System::Drawing::Size(75, 23);
			this->addDLL->TabIndex = 8;
			this->addDLL->Text = L"Nova";
			this->addDLL->UseVisualStyleBackColor = true;
			this->addDLL->Click += gcnew System::EventHandler(this, &MainForm::addDLL_Click);
			// 
			// updateButton
			// 
			this->updateButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->updateButton->Location = System::Drawing::Point(12, 232);
			this->updateButton->Name = L"updateButton";
			this->updateButton->Size = System::Drawing::Size(160, 23);
			this->updateButton->TabIndex = 9;
			this->updateButton->Text = L"Atualizar";
			this->updateButton->UseVisualStyleBackColor = true;
			this->updateButton->Click += gcnew System::EventHandler(this, &MainForm::updateButton_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = "Dynamic-link library|*.dll";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(184, 290);
			this->ControlBox = false;
			this->Controls->Add(this->updateButton);
			this->Controls->Add(this->addDLL);
			this->Controls->Add(this->deleteDLL);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->processListBox);
			this->Controls->Add(this->DLLListBox);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->injectButton);
			this->Controls->Add(this->titleLabel);
			this->Name = L"MainForm";
			this->Text = L"CppInjector";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void titleLabel_Click(System::Object^  sender, System::EventArgs^  e) {
	}




private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
}


private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}

private: void updateProcessNames() {
	this->processListBox->Items->Clear();
	std::list<std::string> processNames = injector->getAllProcessNames();
	for each (std::string procName in processNames)
	{
		this->processListBox->Items->Add(gcnew String(procName.c_str()));
	}
}

private: System::Void updateButton_Click(System::Object^  sender, System::EventArgs^  e) {
	updateProcessNames();
}

private: void getDlls(std::string filePath, std::string extension, std::vector<std::string> & returnFileName){
	WIN32_FIND_DATA fileInfo;
	HANDLE hFind;
	std::string  fullPath = filePath + extension;
	hFind = FindFirstFile(fullPath.c_str(), &fileInfo);
	if (hFind != INVALID_HANDLE_VALUE) {
		returnFileName.push_back(fileInfo.cFileName);
		while (FindNextFile(hFind, &fileInfo) != 0) {
			returnFileName.push_back(fileInfo.cFileName);
		}
	}
}

private: void getDLLList() {
	std::string frame;
	std::vector<std::string> filesPaths;
	char dest[200];
	std::string extension = "*.dll*";
	GetFullPathName("a", 200, dest, NULL);
	dest[strlen(dest)-1] = '\0';
	std::string inputFolderPath(dest);
	getDlls(inputFolderPath,extension,filesPaths);
	for(int i = 0; i != filesPaths.size(); i++)
	{
		DLLListBox->Items->Add(gcnew String(filesPaths.at(i).c_str()));
	}

}

private: System::Void addDLL_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		char dest[200];
		pin_ptr<const wchar_t> wch = PtrToStringChars(openFileDialog1->SafeFileName);
		size_t origsize = wcslen(wch) + 1;
		const size_t newsize = origsize * 2;
		size_t convertedChars = 0;
		char *fileName = new char[newsize];
		wcstombs_s(&convertedChars, fileName, newsize, wch, _TRUNCATE);
		wch = PtrToStringChars(openFileDialog1->FileName);
		origsize = wcslen(wch) + 1;
		const size_t newsize2 = origsize * 2;
		convertedChars = 0;
		char *orig = new char[newsize2];
		wcstombs_s(&convertedChars, orig, newsize2, wch, _TRUNCATE);

		GetFullPathName(fileName, 200, dest, NULL);
		CopyFile(orig, dest, false);
		this->DLLListBox->Items->Add(gcnew String(fileName));
	}
}
};
}
