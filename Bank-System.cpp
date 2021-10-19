#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>

using namespace std;

class account
{
	int acno;
	char name[50];
	int deposit;
	char type;
public:
	void create_account();	//function to get data from user
	void show_account()
	const;	//function to show selected account
	void modify();	//function to add new data
	void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void report()
	const;	//function to show data in tabular format
	int retacno()
	const;	//function to return account number
	int retdeposit()
	const;	//function to return balance amount
	char rettype()
	const;	//function to return type of account
};

//function to create account
void account::create_account()
{
	cout<<"\nEnter The account No. :";
	cin>>acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	cout<<"\n\n\nAccount Created..";
}
//Function to display selected account
void account::show_account() const
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}

//function to modify account details
void account::modify()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}

//function to deposit
void account::dep(int x)
{
	deposit+=x;
}

//function to withdraw
void account::draw(int x)
{
	deposit-=x;
}

//function to display account details in tabular form
void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}

//function to return account number
int account::retacno() const
{
	return acno;
}

//function to return deposit
int account::retdeposit() const
{
	return deposit;
}

//function to return account type
char account::rettype() const
{
	return type;
}


//function declaration
void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function


//Main Function
int main(){
    char ch;
	int num;
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\t\t\t\t***MAIN MENU***";
		cout<<"\n\n\t\t\t\t01. NEW ACCOUNT";
		cout<<"\n\n\t\t\t\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t\t\t\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t\t\t\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t\t\t\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t\t\t\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t\t\t\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t\t\t\t08. EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-8) ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : ";
			cin>>num;
			modify_account(num);
			break;
		 case '8':
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Thanks for using bank management system ***";
			break;
		 default :cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Enter a valid option ***";
		}
		cin.ignore();
		cin.get();
	}while(ch!='8');
}

//Function to write in file
void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

//Function to read specific record from file
void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"*** File could not be open !! Press any Key... ***";
		return;
	}
	cout<<"\n*** BALANCE DETAILS ***\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\n*** Account number does not exist***";
}

//Function to modify record of file
void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"*** File could not be open !! Press any Key...***";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t*** Record Updated ***";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n*** Record Not Found ***";
}

//Function to delete record of file
void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"*** File could not be open !! Press any Key... ***";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"*** Record Deleted .. ***";
}

//Function to display all accounts deposit list
void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"*** File could not be open !! Press any Key... ***";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

//Function to deposit and withdraw amounts
void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"*** File could not be open !! Press any Key... ***";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited"<<endl;
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw"<<endl;
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"*** Insufficient balance ***";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t*** Record Updated ***";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n\n*** Record Not Found ***";
}

//Introduction Function
void intro()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t   BANK";
	cout<<"\n\t\t\t\t\t\t\t\t\t\tMANAGEMENT";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t  SYSTEM";
	cin.get();
}
