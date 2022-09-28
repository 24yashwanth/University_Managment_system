#include <iostream>          
#include <fstream>          
#include <iomanip>          
#include <string.h>          
#include <stdio.h>          
#include <cstdlib>
#include <conio.h>
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

/*
Admin login Credentials :
	User ID  : 7777777
	password : admin
*/

//	loginCredentials
//	It stores userid, password and their level of security

/*
 -------------------------------------------
|	SecurityLevel 	|	UserType			|
|-------------------------------------------|
|		0			|	Admin				|
|		7			|	Student				|
|		4			|	Teaching Staff		|
|	 1,2,3,5		|	Non-Teaching Staff	|
 -------------------------------------------
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
			cout << "\n\nDepartment Code\t\tName of Department\n\n\t1\t\tCleaning\n\t2\t\tManagement\n\t3\t\tOffice work\n\t4\t\tTeaching\n\t5.\t\tOthers";
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
			cout<<"Subjects Opted :\n\n";
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
  	
  	academicReport  report;
  	fstream file(filePath.c_str(), ios::in | ios::out | ios::binary);
  	if (file)
  	{
    	file.seekg(0);
    	cout << "Enter ID of person whose data has to be updated: ";
    	cin >> inputId;
    	removeMyself("academicReport.dat","temp_academicReport.dat",report,inputId);
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
	unsigned long long int username;	char *password=(char *)malloc(sizeof(char)*PASSWORD_LENGTH);		int loginChoice,securityLevel;
	loginCredentials login;
	studentUserDetails student;
	employeeUserDetails employee;
	academicReport report;
	
	while(loginChoice!=5)
	{
		cout<<"\t1\tLogin as a Employee \n\t2\tLogin as a Student \n\t3\tSignup as a Employee\n\t4\tSignup as a Student\n\t5\tExit\n";
		cout<<"\n\t\tEnter Choice : ";
		cin>>loginChoice;
		if(loginChoice==1)
		{
			system("cls");
			cout<<"Enter Login Credentials (E)) :\n\n\tUSER ID : ";
			cin>>username;
			int size=0;
			do
			{
				size=0;
				cout<<"\tPASSWORD : ";
				cin>>password;
				for(int i=0;password[i]!='\0';i++)
					size++;
				if(size>20)
					cout<<"\nError : Input password....Re-enter the password..!!\n";
			}
			while(size>20);
			
			securityLevel=login.loginAuthentication(username,password);
			unsigned long long int inputId=username;
			if(securityLevel>=1 && securityLevel<=6 && securityLevel!=-1)
			{
				//Employee Successfully logged in
				if(securityLevel==4)
				{
					//Teaching Staff verified
					int choice=0;
					while(choice!=9)
					{
 						system("cls");
						cout<<"User ID : "<<username<<"\n";
						cout<<"\n1. To remove any existing Student\n2. To add any Student\n3. To view any Member Details\n4. Update any Student Data\n5. View Whole Data files of Student and Employee\n6. Update Academic Report\n7. View Academic Report\n8. Add Academic Report\n9. Logout\n\n\tChoice : ";
						cin>>choice;
						switch(choice)
						{
							case 1:
								unsigned long long int inputId;
								cout<<"\nEnter the ID of Member of whom you want to remove : ";
								cin>>inputId;
								removeMyself("studentDetails.dat", "temp_studentDetails.dat", student,inputId);
								removeMyself("loginCredentials.dat", "temp_loginCredentials.dat", login,inputId);
								removeMyself("academicReport.dat","temp_academicReport.dat",report,inputId);
								cout<<"\nPress any key....";
								getch();
								system("cls");
								break;
							case 2:
								addMember("studentDetails.dat",student);
								break;
							case 3:
								char opt;
								cout<<"\nA. View a student\nB. View a employee\nQ. quit\n\tChoice : ";
								cin>>opt;
								if(tolower(opt)=='a')
									viewData("studentDetails.dat",student);
								else if(tolower(opt)=='b')
									viewData("employeeDetails.dat",employee);
								else if(tolower(opt)=='q')
								{
									system("cls");
									break;
								}
									
								break;
							case 4:
								username=updateMemberData("studentDetails.dat",student);
								cout<<"\nStudent's new userName : "<<username;
								cout<<"\nPress any key....";
								getch();
								system("cls");
								break;
							case 5:
								cout<<"\nA. View a student\nB. View a employee\nQ. quit\n\tChoice : ";
								cin>>opt;
								if(tolower(opt)=='a')
									viewData("studentDetails.dat",student);
								else if(tolower(opt)=='b')
									viewData("employeeDetails.dat",employee);
								else if(tolower(opt)=='q')
								{
									system("cls");
									break;
								}
								break;
							case 6:
								unsigned long long int id;
								cout<<"Enter the ID of Student of whom you want to update the Academic Report : ";
								cin>>id;
								updateAcademicReport(id);
								system("cls");
								cout<<"Updated Report of "<<id<<" :\n\n";
								viewMyAcademicReport(id);
								cout<<"\n\nPress any key.....";
								getch();
								system("cls");
								break;
							case 7:
								cout<<"Enter the ID of Student of whom you want to see the Academic Report : ";
								cin>>id;
								viewMyAcademicReport(id);
								cout<<"\n\nPress any key.....";
								getch();
								system("cls");
								
								break;
							case 8:
								cout<<"Enter the ID of Student of whom you want to add the Academic Report : ";
								cin>>id;
								addAcademicReport(id);
								cout<<"Added Report of "<<id<<" :\n\n";
								viewMyAcademicReport(id);
								cout<<"\n\nPress any key.....";
								getch();
								system("cls");
								
							default:
								break;
						}
					}
				}
				if(securityLevel!=4)
				{
					// Non-Teachinh Staff(Cleaning,Management,Office work,Others) verified
					int choice;
 //					system("cls");
					cout<<"User ID : "<<username<<"\n\n"; 
					while(choice!=4)
					{
						cout<<"\n1. View my Details\n2. Update my Details\n3. View my login Credetials\n4. Logout\n\tChoice : ";
						cin>>choice;
						switch(choice)
						{
							case 1:
								system("cls");
								viewMyself("employeeDetails.dat",employee,username);
								cout<<"\npress any key....\n";
								getch();
								system("cls");
								break;
							case 2:
								system("cls");
								cout<<"Updating Employee Details :\n\n";
								removeMyself("academicReport.dat","temp_academicReport.dat",report,inputId);
								username=updateMyself("employeeDetails.dat",employee,username);
								cout<<"\n\npress any key....";
								getch();
								system("cls");
								break;
							case 3:
								system("cls");
								cout<<"Employee Login Credentials :\n\n";
								viewMyself("loginCredentials.dat",login,username);
								getch();
								system("cls");
								break;
							default:
								break;
						}
					}
				}
			}
			else if(securityLevel==0)
			{
				//admin
				
				int choice=0,ch=0;
				while(choice!=8)
				{
					system("cls");
					cout<<"User ID: 7777777\tUser : Admin\n\n";
					cout<<"1. Remove any existing Member\n2. Add any Member\n3. View any Member\n4. Update any MemberData\n5. View Whole Data Files\n6. Handle Finances\n7. Handle Academic Report of students\n8. Logout\n\n\tChoice : ";
					cin>>choice;
					char opt;
					switch(choice)
					{
						case 1:
							cout<<"\nA. Remove a student\nB. Remove a employee\nQ. Exit\n\tChoice : ";
							cin>>opt;
							if(tolower(opt)=='a')
							{
								unsigned long long int inputId;
								cout<<"Enter the ID : ";
								cin>>inputId;
								removeMyself("studentDetails.dat", "temp_studentDetails.dat", student,inputId);
								removeMyself("loginCredentials.dat", "temp_loginCredentials.dat", login,inputId);
								removeMyself("academicReport.dat","temp_academicReport.dat",report,inputId);

							}
							else if(tolower(opt)=='b')
							{
								unsigned long long int inputId;
								cout<<"Enter the ID : ";
								cin>>inputId;
								removeMyself("employeeDetails.dat", "temp_employeeDetails.dat", employee,inputId);
								removeMyself("loginCredentials.dat", "temp_loginCredentials.dat", login,inputId);
							}
							else if(tolower(opt)=='q')
							{
								system("cls");
								break;
							}	
							else
								cout<<"\nError : Invalid Choice !!\n";
							cout<<"\npress any key....\n";
							getch();
							system("cls");
							break;
								
						case 2:
							cout<<"\nA. Add a student\nB. Add a employee\nQ. Exit\n\tChoice : ";
							cin>>opt;	
							if(tolower(opt)=='a')
								addMember("studentDetails.dat",student);
							else if(tolower(opt)=='b')
								addMember("employeeDetails.dat",employee);
							else if(tolower(opt)=='q')
							{
								system("cls");
								break;
							}
							cout<<"\npress any key....\n";
							getch();
							system("cls");
							break;
									
						case 3:
							cout<<"\nA. View a student\nB. View a employee\nC. View LoginCredentials\nQ. Exit\n\tChoice : ";
							cin>>opt;
							if(tolower(opt)=='a')
								viewData("studentDetails.dat",student);
							else if(tolower(opt)=='b')
								viewData("employeeDetails.dat",employee);
							else if(tolower(opt)=='c')
								viewData("loginCredentials.dat",login);
							else if(tolower(opt)=='q')
							{
								system("cls");
								break;
							}
							cout<<"\npress any key....\n";
							getch();
							system("cls");
							break;
								
						case 4:
							cout<<"\nA. Upgrade a student\nB. Upgrade a employee\nQ. Exit\n\tChoice : ";
							cin>>opt;
							if(tolower(opt)=='a')
								username=updateMemberData("studentDetails.dat",student);
							else if(tolower(opt)=='b')
								username=updateMemberData("employeeDetails.dat",employee);
							else if(tolower(opt)=='q')
							{
								system("cls");
								break;
							}
							cout<<"\npress any key....\n";
							getch();
							system("cls");
							break;
						case 5:
							while(ch!=5)
							{
								ch=0;
								cout<<"\n\nViewData of which file:\n  1. Employee Details File\n  2. Student Details File\n  3. Login Credentials File\n  4. Academic Report File\n  5. Exit\n\n\tChoice : ";
								cin>>ch;
								switch(ch)
								{
									case 1:
										viewEmployeeData();
										break;
									case 2:
										viewStudentData();
										break;
									case 3:
										viewLoginCredentialsData();
										break;
									case 4:
										viewAcademicReportsData();
										break;
									default:
										cout<<"\nError : Enter a valid input !!\n";
										break;
								}
								
							}

							system("cls");
							break;
						case 6:
							
							while(ch!=3)
							{
								unsigned long long int inputId,payment;
								cout<<"\n1. Pay Employee Salary\n2. pay Student fee\n3. Exit\n\tchoice : ";
								cin>>ch;
								if(ch!=3)
								{
									cout<<"Enter the ID : ";
									cin>>inputId;
									cout<<"Enter the amount : ";
									cin>>payment;
									if(ch==1)
										updateMoney("employeeDetails.dat",employee,inputId,payment);
									else if(ch==2)
										updateMoney("studentDetails.dat",student,inputId,payment);
								}
							}
							system("cls");
							break;
						case 7:
							// academic reports
							unsigned long long int id;
							while(ch!=4)
							{
								cout<<"\n1. View Academic Reports\n2. Add Academic Reports\n3. Update Academic Report\n4. Exir\n\tchoice: ";
								cin>>ch;
								if(ch==4)
									break;
								cout<<"Enter the ID of Student : ";
								cin>>id;
								if(ch==1)
									viewMyAcademicReport(id);
								else if(ch==2)
									addAcademicReport(id);
								else if(ch==3)
									updateAcademicReport(id);
								else if(ch!=4)
									cout<<"\nError : Invalid Choice !!\n";
								ch=0;

							}
							
							system("cls");
							break;
						default:
							system("cls");
							break;
					}
				}
			}
		}
		if(loginChoice==2)
		{
			//Student
			int choice,size=0;
			system("cls");
			cout<<"Enter Login Credentials (E)) :\n\n\tUSER ID : ";
			cin>>username;
			do
			{
				size=0;
				cout<<"\tPASSWORD : ";
				cin>>password;
				for(int i=0;password[i]!='\0';i++)
					size++;
				if(size>20)
					cout<<"\nError : Input password is too long....Re-enter the password..!!\n";
			}
			while(size>20);
			securityLevel=login.loginAuthentication(username,password);
			unsigned long long int inputId=username;
			if(securityLevel==7 && securityLevel!=-1)
			{
				//Student verified
 				system("cls");
				cout<<"User ID : "<<username<<"\n"; 
				while(choice!=5)
				{
					cout<<"\n1. View my Details\n2. Update my Details\n3. View my Academic Report\n4. View my login Credetials\n5. Logout\n\t\tChoice : ";
					cin>>choice;
					switch(choice)
					{
						case 1:
							system("cls");
							viewMyself("studentDetails.dat",student,username);
							cout<<"\npress any key....\n";
							getch();
							system("cls");
							break;
						case 2:
							system("cls");
							cout<<"Details Updating :\n\n";
							removeMyself("academicReport.dat","temp_academicReport.dat",report,inputId);
							username=updateMyself("studentDetails.dat",student,username);
							cout<<"\npress any key....\n";
							getch();
							system("cls");
							break;
						case 3:
							system("cls");
							viewMyAcademicReport(username);
							cout<<"\npress any key....\n";
							getch();
							system("cls");
							break;
						case 4:
							system("cls");
							viewMyself("loginCredentials.dat",login,username);
							cout<<"\n\npress any key....\n";
							getch();
							system("cls");
							break;
						default:
							system("cls");
							break;
					}
				}
			}
			
		}
		else if(loginChoice==3)
		{
			system("cls");
			cout<<"Employee SignUp :\n"<<endl;
			employeeUserDetails writeEmployee;
			writeEmployee.inputDetails();
			cout<<"\n\nSignUp Details :\n"<<endl;
			writeEmployee.viewDetails();
			
			fstream writer("employeeDetails.dat",ios::in | ios::out | ios::app | ios::binary);
			writer.write((char *)&writeEmployee,sizeof(writeEmployee));
			writer.close();
			cout<<"\nSignup Successfull..!!\n\nPress any key.....";
			getch();
			system("cls");
		}
		else if(loginChoice==4)
		{
			system("cls");
			cout<<"Student SignUp :\n"<<endl;
			studentUserDetails writeStudent;
			writeStudent.inputDetails();
			cout<<"\n\nSignUp Details :"<<endl;
			writeStudent.viewDetails();
			
			fstream writer("studentDetails.dat",ios::in | ios::out | ios::app | ios::binary);
			writer.write((char *)&writeStudent,sizeof(writeStudent));
			writer.close();
			cout<<"\nSignup Successfull..!!\n\nPress any key.....";
			getch();
			system("cls");
		}
		else if(loginChoice==5)
			return 0;
		else if(loginChoice>5)
		{
			cout<<"Invalid Choice\n\n";
			cout<<"press any key.....";
			getch();
			system("cls");
		}
			
	}
	return 0;
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
