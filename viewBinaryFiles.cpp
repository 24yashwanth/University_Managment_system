#include <iostream>          
#include <fstream>          
#include <iomanip>          
#include <string.h>          
#include <stdio.h>          
#include <cstdlib>
#include<conio.h>
#include <typeinfo>



using namespace std;

#define PASSWORD_LENGTH 20
#define NAME_LENGTH 30
#define PHONENUMBER_LENGTH 10
#define SUBJECT_LENGTH 20
#define DEPARTEMENT_LENGTH 30
#define QUALIFICATION_LENGTH 20
#define BRANCH_LENGTH 30
#define NUMBER_OF_SUBJECTS 6



unsigned long long int generateId(int subCode,int depCode);
int loginAuthentication(unsigned long long int un,char pw[]);
void viewStudentData();
void viewEmployeeData();
void viewLoginCredentialsData();
void viewAcademicReportsData();
void viewMyAcademicReport(unsigned long long int inputId);
void updateAcademicReport(unsigned long long int inputId);
void addAcademicReport(unsigned long long int inputId);

/*
	1.Programming Language
	2.Maths
	3.English
	4.Operating Systems
	5.Object Oriented Programming
	6.Data Structures and Algorithms
*/

class loginCredentials
{
	public:
		unsigned long long int username;
		char password[PASSWORD_LENGTH];
		int securityLevel;
		unsigned long long int getId(){	return username; }
		char * getPassword()
		{
			char *pw=(char *)malloc(sizeof(char )*20);
			strcpy(pw,password);
			return pw;
		}
		int loginAuthentication(unsigned long long int un,char *pw)
		{
			short flag=0; loginCredentials login;
			fstream reader("loginCredentials.dat",ios::in | ios::out | ios::app | ios::binary);
			while(reader.read((char *)&login,sizeof(login)))
			{
				if((login.getId()==un) && (strcmp(login.getPassword(),pw)==0))
				{
					flag++;
					return login.securityLevel;
				}
			}
			if(flag==0)
			{
				cout<<"\n\nError : Invalid Username and/or Password !!\n\npress any key....";
				getch();
				system("cls");
				return -1;
			}	
		}
		void inputLoginCredentials(unsigned long long int userName,int sL)
		{
			username=userName;
			char *password1=(char *)malloc(sizeof(char)*20);
			do
			{
				cout<<"\nEnter password : ";
				cin>>password;
				cout<<"Re-Enter password : ";
				cin>>password1;
				if(strcmp(password,password1)==0)
					break;
			}
			while(strcmp(password,password1)!=0);
			securityLevel=sL;
			return;
		}
		
		void createAdmin()
		{
			username=7777777;
			strcpy(password,"admin");
			securityLevel=0;
			return;
		}
		
		void viewDetails(){cout<<"\n\tUserName : "<<username<<"\n\tPassword : "<<password<<"\n\tSecurity Level : "<<securityLevel<<endl;	return;}
		
};

class employeeUserDetails : public loginCredentials
{
	protected:
		char name[NAME_LENGTH];
		char phoneNumber[PHONENUMBER_LENGTH];
		char subject[SUBJECT_LENGTH];
		char departement[DEPARTEMENT_LENGTH];
		int workExperience;
		char qualification[QUALIFICATION_LENGTH];		
		unsigned long long int id;
	public:
		unsigned long long int money;
		using loginCredentials :: username;
		unsigned long long int getId(){ return id; }
		void payment(unsigned long long int amount)
		{
			if(amount<=money)
			{
				money=money-amount;
				cout<<"\nPayment Successfull..!!\n";
			}
			if(amount==0)
				cout<<"\npayment Successfull....\nFull amount paid....!!\n";		
		}
		void inputDetails()
		{						
			int empSubjectCode,empDepartementCode=0;
 //			system("cls");	
			cout<<"Enter Name : ";
			cin>>name;
			cout << "\n\nDepartment Code\t\tName of Department\n\t1\t\tCleaning\n\t2\t\tManagement\n\t3\t\tOffice work\n\t4\t\tTeaching\n\t5.\t\tOthers";
			cout << "\n\nEnter department code : ";
			cin >> empDepartementCode;
			while (empDepartementCode > 5 || empDepartementCode < 1)
			{
				cout << "\nSorry, we received a wrong department code. Please enter valid department code viz. 1, 2, 3, 4 or 5: ";
			    cin >> empDepartementCode;
			}
			switch (empDepartementCode)
			{
				case 1:
				    strcpy(departement, "Cleaning");
				    break;
				case 2:
				    strcpy(departement, "Management");
				    break;
				case 3:
				    strcpy(departement, "Office Work");
				    break;
				case 4:
					strcpy(departement, "Teaching");
					break;
				case 5:
				    strcpy(departement, "Others");
				    break;
			}
			if(empDepartementCode==4)
			{
				cout << "\nSubject Code\tSubject\n\t1\t\tProgramming Language\n\t2\t\tMaths\n\t3\t\tEnglish\n\t4\t\tOperating Systems\n\t5\t\tObject Oriented Programming\n\t6\t\tData Structures and Algorithms\n";
				cout << "\nEnter the subject code : ";
				cin >> empSubjectCode;
				while (empSubjectCode > 6 || empSubjectCode < 1)
				{
					cout << "\nSorry, we received a wrong subject code. Please enter valid subject code viz. 1, 2, 3, 4, 5, 6 or 7 : ";
				    cin >> empSubjectCode;
				}
			
				switch (empSubjectCode)
				{
					case 1:
						strcpy(subject, "Programming Language");
				    	break;
				  	case 2:
				    	strcpy(subject, "Maths");
				    	break;
					case 3:
					    strcpy(subject, "English");
					    break;
					case 4:
					    strcpy(subject, "Operating Systems");
					    break;
					case 5:
					    strcpy(subject, "Object Oriented Programming");
					    break;
					case 6:
						strcpy(subject, "Data Structures and Algorithms");
						break;
					default:
						cout<<"\nError : Invalid Subject Code....!!\n";
						break;
				}
			}
			else
			{
				empSubjectCode=0;
				strcpy(subject,"None");
			}
				
	
			cout<<"\nEnter emp PhoneNumber (max 10 Digits) : ";
			cin>>phoneNumber;
			cout << "\nEnter emp annual salary (in Rs.): ";
			cin >> money;
			cout << "\nEnter emp work experience (in years): ";
			cin >> workExperience;
			cout << "\nEnter emp educational qualification (max. 20 characters): ";
			cin>>qualification;
			id=generateId(empSubjectCode,empDepartementCode);
			username=id;
			
			loginCredentials login;
			login.inputLoginCredentials(id,empDepartementCode);
			
			fstream writer("loginCredentials.dat",ios::in | ios::out | ios::app | ios::binary);
			writer.write((char *)&login,sizeof(login));
			writer.close();
			return;
		}
	
		void viewDetails()
		{
			cout<<"\tEmployee ID : "<<id<<endl;
			cout<<"\tName : "<<name<<endl;
			cout<<"\tPh.No : "<<phoneNumber<<endl;
			cout<<"\tSubject : "<<subject<<endl;
			cout<<"\tDepartement : "<<departement<<endl;
			cout<<"\tRemaining Salary to be paid(Anually): "<<money<<endl;
			cout<<"\tWork Experience : "<<workExperience<<endl;
			cout<<"\tQualification : "<<qualification<<"\n"<<endl;
			return;			
		}
		
};


class studentUserDetails : public loginCredentials
{
	protected:
		char name[NAME_LENGTH];
		char phoneNumber[PHONENUMBER_LENGTH];
		char branch[BRANCH_LENGTH];
		unsigned long long int id;
		int subjectsOpted[NUMBER_OF_SUBJECTS];

	public:
		unsigned long long int money;
		using loginCredentials :: username;
		unsigned long long int getId(){ return id; }
		int * getSubjectsOpted()
		{
			int *x=(int *)malloc(sizeof(int)*NUMBER_OF_SUBJECTS);
			for(int i=0;i<NUMBER_OF_SUBJECTS;i++)
				x[i]=subjectsOpted[i];
			return x;
		}
		void payment(unsigned long long int amount)
		{
			if(amount<=money)
			{
				money=money-amount;
				cout<<"\nPayment Successfull..!!\n";
			}
			if(amount==0)
				cout<<"\npayment Successfull....\nFull amount paid....!!\n";		
		}
		void inputDetails()
		{		
			int studentBranchCode;
 //			system("cls");
			cout<<"Enter Name : ";
			cin>>name;
			cout<<"\nStudent Phone Number : ";
			cin>>phoneNumber;
			
			cout << "\nBranch Code\t\tName of Branch\n\t1\t\tCSE\n\t2\t\tECE\n\t3\t\tMechanical\n\t4\t\tChemicalEngineering";
			cout << "\n\nEnter department code : ";
			cin>>studentBranchCode;
			while (studentBranchCode > 4 || studentBranchCode < 1)
			{
				cout << "\nSorry, we received a wrong Branch code. Please enter valid department code viz. 1, 2, 3 or 4: ";
			    cin >> studentBranchCode;
			}
			switch (studentBranchCode)
			{
				case 1:
					strcpy(branch, "CSE");
			    	break;
			  	case 2:
			    	strcpy(branch, "ECE");
			    	break;
				case 3:
				    strcpy(branch, "Mechanical");
				    break;
				case 4:
				    strcpy(branch, "ChemicalEngineering");
				    break;
				default:
					cout<<"ERROR : Enter valid Branch Code !!";
					break;
			}
			
			int count,option;
			cout<< "\nNumber of Subjects Opted : ";
			cin>> count;
			cout<<"\nSelect the Opted Subjects one by one :\n";
			cout<<"\t1.Programming Language\n\t2.Maths\n\t3.English\n\t4.Operating Systems\n\t5.Object Oriented Programming\n\t6.Data Structures and Algorithms\n\nEnter your choices(one bu one) :\n";
			for(int i=0;i<NUMBER_OF_SUBJECTS;i++)
				subjectsOpted[i]=0;
			for(int i=0;i<count;i++)
			{
				cin>>option;
				subjectsOpted[option-1]=1;
			}
			
			cout << "\nEnter Student annual Fee (in Rs.): ";
			cin >> money;
			id=generateId(studentBranchCode,0);
			username=id;
			
			loginCredentials login;
			login.inputLoginCredentials(id,7);
			
			fstream writer("loginCredentials.dat",ios::in | ios::out | ios::app | ios::binary);
			writer.write((char *)&login,sizeof(login));
			writer.close();
			return;
		}
		void viewDetails()
		{
			cout<<"\nStudent ID : "<<id<<endl;
			cout<<"Name : "<<name<<endl;
			cout<<"Ph.No : "<<phoneNumber<<endl;
			cout<<"Branch : "<<branch<<endl;
			cout<<"Choose the following Subjects :\n\n";
			for(int i=0;i<NUMBER_OF_SUBJECTS;i++)
			if(subjectsOpted[i]==1)
			{
				cout<<"\t"<<1+i<<".";
				if(i==0)
					cout<<"Programming Language"<<endl;
				else if(i==1)
					cout<<"Maths"<<endl;
				else if(i==2)
					cout<<"English"<<endl;
				else if(i==3)
					cout<<"Operating Systems"<<endl;
				else if(i==4)
					cout<<"Object Oriented Programming"<<endl;
				else if(i==5)
					cout<<"Data Structures and Algorithms"<<endl;
			}
					
			cout<<"\nFee : "<<money<<"\n"<<endl;
			return;			
		}	
};

class academicReport : public studentUserDetails
{
	protected:
		unsigned long long int id;
		int programmingLanguageMarks;
		int mathsMarks;
		int englishMarks;
		int operatingSystemsMarks;
		int ObjectOrientedProgrammingMarks;
		int DataStructuresAndAlgorithmsMarks;
		int noOfSubjectsElected;
	public:
		unsigned long long int getId(){return id;}
		void viewDetails()
		{
			cout<<"\n\tUser ID : "<<id<<"\t\tNumber of Subjects Opted : "<<noOfSubjectsElected<<endl;
			cout<<"\n----------------------------------------------------------\n| Subject\t\t\t\t|\tMarks\t |\n----------------------------------------------------------";
			if(programmingLanguageMarks!=-1)
				cout<<"\n| Programming Language\t\t\t|\t"<<programmingLanguageMarks<<"\t |"<<endl;
			if(mathsMarks!=-1)
				cout<<"\n| Maths\t\t\t\t\t|\t"<<mathsMarks<<"\t |"<<endl;
			if(englishMarks!=-1)
				cout<<"\n| English\t\t\t\t|\t"<<englishMarks<<"\t |"<<endl;
			if(operatingSystemsMarks!=-1)
				cout<<"\n| Operating Systems\t\t\t|\t"<<operatingSystemsMarks<<"\t |"<<endl;
			if(ObjectOrientedProgrammingMarks!=-1)
				cout<<"\n| Object Oriented Programming\t\t|\t"<<ObjectOrientedProgrammingMarks<<"\t |"<<endl;
			if(DataStructuresAndAlgorithmsMarks!=-1)
				cout<<"\n| Data Structures and Algorithms  \t|\t"<<DataStructuresAndAlgorithmsMarks<<"\t |"<<endl;
			cout<<"----------------------------------------------------------\n"<<endl;
			return;
		}
		
		void inputDetails(unsigned long long int inputId)
		{
			id=inputId; short flag=0;
			int *subjectsOpted;
			studentUserDetails student;
			fstream reader("studentDetails.dat", ios::in | ios::out | ios::app | ios::binary);
			while(reader.read((char *)&student,sizeof(student)));
			if(student.getId()==inputId)
				subjectsOpted=student.getSubjectsOpted();
			
			programmingLanguageMarks=-1;
			mathsMarks=-1;
			englishMarks=-1;
			operatingSystemsMarks=-1;
			ObjectOrientedProgrammingMarks=-1;
			DataStructuresAndAlgorithmsMarks=-1;
			for(int i=0;i<6;i++)
				if(subjectsOpted[i]==1)
					flag++;
			noOfSubjectsElected=flag;
			for(int i=0;i<6;i++)
			if(subjectsOpted[i]==1)
			{
				if(i==0)
				{
					cout<<"\nMarks in Programming Language : ";
					cin>>programmingLanguageMarks;
				}
				if(i==1)
				{
					cout<<"\nMarks in Maths : ";
					cin>>mathsMarks;
				}
				if(i==2)
				{
					cout<<"\nMarks in English : ";
					cin>>englishMarks;
				}
				if(i==3)
				{
					cout<<"\nMarks in Operating Systems : ";
					cin>>operatingSystemsMarks;	
				}
				if(i==4)
				{
					cout<<"\nMarks in Object Oriented Programming : ";
					cin>>ObjectOrientedProgrammingMarks;	
				}
				if(i==5)
				{
					cout<<"\nMarks in Data Structures and Algorithms : ";
					cin>>DataStructuresAndAlgorithmsMarks;
				}
			}
			return;
		}
};


template <typename T>
void viewMyself(const string filePath,T memberClass,unsigned long long int inputId)
{
 //  system("cls");
	int flag=0;
  	ifstream reader(filePath.c_str(), ios::binary);
  	reader.seekg(0);
  	while (reader.read((char *)&memberClass, sizeof(memberClass)))
  	{
    	if (inputId == memberClass.getId())
    	{	
      		++flag;
      		memberClass.viewDetails();
      		break;
    	}
  	}
  	if(flag==0)
    	cout << "No match found.";
    return;
}

template <typename T>
void removeMyself(const string filePath, const string tempFilePath, T memberClass,unsigned long long int inputId)
{
 //  system("cls");
	short flag = 0;
  	
	fstream reader(filePath.c_str(), ios::in | ios::out | ios::app | ios::binary);
	reader.seekg(0);

	fstream writer(tempFilePath.c_str(), ios::in | ios::out | ios::app | ios::binary);
  
	while (reader.read((char *)&memberClass, sizeof(memberClass)))
	{
		if (inputId == memberClass.getId()) 
	    	flag++;
	    else
	    	writer.write((char *)&memberClass, sizeof(memberClass));
  	}
	if (flag == 0)
    	cout << "Sorry, No Match found.";
  	else
    	cout << "Data of ID " << inputId << " has been removed from "<<filePath<<endl;;
  	reader.close();
  	writer.close();
 	remove(filePath.c_str());
  	rename(tempFilePath.c_str(), filePath.c_str());
  	return;
}

template <typename T>
unsigned long long int updateMyself(const string filePath, T memberClass,unsigned long long int inputId)
{
 //  system("cls");
  	short flag = 0;
  	long filePosition = 0;	loginCredentials login;
  	fstream file(filePath.c_str(), ios::in | ios::out | ios::binary);
  	if (file)
  	{
    	file.seekg(0);
    	while (!file.eof())
    	{
      		filePosition = file.tellg();
      		file.read((char *)&memberClass, sizeof(memberClass));
      		if (inputId == memberClass.getId())
      		{
        		++flag;
        		break;
      		}
    	}
	    if (flag > 0)
	    {
	      	memberClass.inputDetails();
	      	file.seekg(filePosition);
	      	file.write((char *)&memberClass, sizeof(memberClass));
	      	cout << "\nFile has been successfully updated.";
	      	removeMyself("loginCredentials.dat","temp_loginCredentials.dat",login,inputId);
	      	cout<<"\nNew User ID : "<<memberClass.getId()<<"\nPress any key...."<<endl;
	      	getch();
	    }
	    else
	      	cout << "Sorry, no match found.";
  	}
  	else
    	cout << "\nOops! There's something wrong with file "<< filePath << ". Please, make sure it exists.\n";
    return memberClass.getId();
}


template <typename T>
void removeMember(const string filePath, const string tempFilePath, T memberClass)
{
 //  system("cls");
	short flag = 0;
  	unsigned long long int inputId;
  	cout<<"Enter the ID of Member of whom you want to remove : ";
	cin>>inputId;
	fstream reader(filePath.c_str(), ios::in | ios::out | ios::app | ios::binary);
	reader.seekg(0);

	fstream writer(tempFilePath.c_str(), ios::in | ios::out | ios::app | ios::binary);
  
	while (reader.read((char *)&memberClass, sizeof(memberClass)))
	{
		if (inputId == memberClass.getId()) 
	    	flag++;
	    else
	    	writer.write((char *)&memberClass, sizeof(memberClass));
  	}
	if (flag == 0)
    	cout << "Sorry, No Match found.";
  	else
    	cout << "Data of ID " << inputId << " has been removed from file.";
  	reader.close();
  	writer.close();
 	remove(filePath.c_str());
  	rename(tempFilePath.c_str(), filePath.c_str());
  	return;
}

template <typename T>
void addMember(const string filePath, T memberClass)
{
  	fstream file(filePath.c_str(), ios::in | ios::out | ios::app | ios::binary);
  	memberClass.inputDetails();
  	file.write((char *)&memberClass, sizeof(memberClass));
  	file.close();
  	return;
}

template <typename T>
void viewData(const string filePath, T memberClass)
{
 //  system("cls");
  
  	unsigned long long int inputId = 0;
  	short flag = 0;
  
  	cout << "Enter ID of person whose data records you want to see: ";
  	cin >> inputId;
  	ifstream reader(filePath.c_str(), ios::binary);
  	reader.seekg(0);
  	while (reader.read((char *)&memberClass, sizeof(memberClass)))
  	{
    	if (inputId == memberClass.getId())
    	{
      		++flag;
      		memberClass.viewDetails();
      		break;
    	}
  	}
  	if(flag==0)
    	cout << "No match found.";
    return;
}

template <typename T>
unsigned long long int updateMemberData(const string filePath, T memberClass)
{
 //  system("cls");
  	unsigned long long int inputId = 0;	loginCredentials login;
  	short flag = 0;
  	long filePosition = 0;
  	fstream file(filePath.c_str(), ios::in | ios::out | ios::binary);
  	if (file)
  	{
    	file.seekg(0);
    	cout << "Enter ID of person whose data has to be updated: ";
    	cin >> inputId;
    	while (!file.eof())
    	{
      		filePosition = file.tellg();
      		file.read((char *)&memberClass, sizeof(memberClass));
      		if (inputId == memberClass.getId())
      		{
        		++flag;
        		break;
      		}
    	}
    if (flag > 0)
    {
      	memberClass.inputDetails();
      	file.seekg(filePosition);
      	file.write((char *)&memberClass, sizeof(memberClass));
      	removeMyself("loginCredentials.dat","temp_loginCredentials.dat",login,inputId);
      	cout << "\nFile has been successfully updated.";
    }
    else
      	cout << "Sorry, no match found.";
  	}
  	else
    	cout << "\nOops! There's something wrong with file "<< filePath << ". Please, make sure it exists.\n";
    
    
    return memberClass.getId();
}

template <typename T>
void updateMoney(const string filePath,T classMember,unsigned long long int inputId,unsigned long long int payment)
{	
	short flag = 0;
  	long filePosition = 0;
  	fstream file(filePath.c_str(), ios::in | ios::out | ios::binary);
  	if (file)
  	{
    	file.seekg(0);
    	while (!file.eof())
    	{
      		filePosition = file.tellg();
      		file.read((char *)&classMember, sizeof(classMember));
      		if (inputId == classMember.getId())
      		{
        		++flag;
        		classMember.payment(payment);
        		file.seekg(filePosition);
    			file.write((char *)&classMember, sizeof(classMember));
        		break;
      		}
    	}
	    if (flag == 0)
	      	cout << "Sorry, no match found.";
  	}
  	else
    	cout << "\nOops! There's something wrong with file "<<filePath<<". Please, make sure it exists.\n";
	
	return;
}

int main()
{
	viewEmployeeData();
	viewStudentData();
	viewAcademicReportsData();
	viewLoginCredentialsData();	
}

void addAcademicReport(unsigned long long int inputId)
{	
	academicReport report;
  	fstream writer("academicReport.dat",  ios::in | ios::out | ios::app | ios::binary);
  	report.inputDetails(inputId);
	writer.write((char *)&report, sizeof(report));
	writer.close();
	cout << "\nFile has been successfully updated.";
	return;
}

void viewMyAcademicReport(unsigned long long int inputId)
{
	academicReport report;
	fstream reader("academicReport.dat", ios::in | ios::out | ios::app | ios::binary);
	reader.seekg(0);
	int flag=0;
	while (reader.read((char *)&report, sizeof(report)))
	{	
		if(inputId==report.getId())
		{
			cout<<"Academic Report of "<<inputId<<" :"<<endl;
			report.viewDetails();	flag++;
		}
	}
	reader.close();
	if(flag==0)
		cout<<"\nNo Academic Report found...\n";
	return;
}

void updateAcademicReport(unsigned long long int inputId)
{	
	short flag = 0;
  	long filePosition = 0;	academicReport report;
  	fstream file("academicReport.dat", ios::in | ios::out | ios::binary);
  	if (file)
  	{
    	file.seekg(0);
    	while (!file.eof())
    	{
      		filePosition = file.tellg();
      		file.read((char *)&report, sizeof(report));
      		if (inputId == report.getId())
      		{
        		++flag;
        		break;
      		}
    	}
	    if (flag > 0)
	    {
	      	report.inputDetails(inputId);
	      	file.seekg(filePosition);
	      	file.write((char *)&report, sizeof(report));
	      	cout << "\nFile has been successfully updated.";
	    }
	    else
	      	cout << "Sorry, no match found.";
  	}
  	else
    	cout << "\nOops! There's something wrong with file acdemicReport.dat. Please, make sure it exists.\n";
	
	return;
}

unsigned long long int generateId(int subCode,int depCode=0)
{
	int flag=0;	loginCredentials login;
	unsigned long long int id;
	fstream reader("loginCredentials.dat", ios::in | ios::out | ios::app | ios::binary);
	while (reader.read((char *)&login, sizeof(login)))
		++flag;
	reader.close();

	if (flag == 0)
	{
		fstream writer("loginCredentials.dat",ios::in | ios::out | ios::app | ios::binary);
		login.createAdmin();
		writer.write((char *)&login, sizeof(login));
		flag++;
		writer.close();
	}
	if(subCode==0)
	subCode=7;
	if(depCode==0)
	depCode=7;
	id = (depCode * 1000) + (subCode * 100) + flag;
							
	return id;
}

void viewStudentData()
{
	studentUserDetails student;
 //	system("cls");
	fstream fileToRead("studentDetails.dat", ios::in | ios::out | ios::app | ios::binary);
	fileToRead.seekg(0);
	int flag=0;
	while (fileToRead.read((char *)&student, sizeof(student)))
	{
		cout<<"\n\n\nStudent "<<++flag<<" :"<<endl;
		student.viewDetails();
	}
	fileToRead.close();
	return;
}

void viewEmployeeData()
{
	employeeUserDetails employee;
 //	system("cls");
	fstream fileToRead("employeeDetails.dat", ios::in | ios::out | ios::app | ios::binary);
	fileToRead.seekg(0);
	int flag=0;
	while (fileToRead.read((char *)&employee, sizeof(employee)))
	{
		cout<<"\n\n\nEmployee "<<++flag<<" :"<<endl;
		employee.viewDetails();
	}
	fileToRead.close();
	return;
}

void viewLoginCredentialsData()
{
	loginCredentials login;
 //	system("cls");
	fstream fileToRead("loginCredentials.dat", ios::in | ios::out | ios::app | ios::binary);
	fileToRead.seekg(0);
	int flag=0;
	while (fileToRead.read((char *)&login, sizeof(login)))
	{
		cout<<"\n\n\nLogin Credential "<<++flag<<" :"<<endl;
		login.viewDetails();
	}
	fileToRead.close();
	return;
}

void viewAcademicReportsData()
{
	academicReport report;
 //	system("cls");
	fstream reader("academicReport.dat", ios::in | ios::out | ios::app | ios::binary);
	reader.seekg(0);
	int flag=0;
	while (reader.read((char *)&report, sizeof(report)))
	{
		cout<<"\n\n\nAcademic Report "<<++flag<<" :"<<endl;
		report.viewDetails();
	}
	reader.close();
	return;
}
