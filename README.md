# College Managment System



## Requirement

Use the C++14 or newer versions of C++

```bash
g++ main.cpp -o main
g++ viewBinaryFiles.cpp -o viewBinaryFiles
```

## Usage

```cpp
#include <iostream>          
#include <fstream>          
#include <iomanip>          
#include <string.h>          
#include <stdio.h>          
#include <cstdlib>
#include <conio.h>
#include <typeinfo>
```
## File System Used
#### Binary files

## Names of the files used
#### 1) studentDetails.dat
###### This file stores the user details of the Student
#### 2) loginCredentials.dat
###### This file stores the login Credentials of all users
#### 3) employeeDetails.dat
###### This file stores the user details of the Employee's
#### 4) academicReport.dat
###### This file stores the Academic reports of all Student's

## Contribution
#### It is a group Project :
```
L S Yaswanth Kumar [19/11/EC/059]
L Jeya Suriya [19/11/Ec/032]
Sattaru Harshavardhan reddy [19/11/EC/029]
```
## Instructions for running of the Project
```
 ---------------------------------------------------------
|	SecurityLevel 	        |	UserType	  |
|---------------------------------------------------------|
|		0	        |	Admin		  |
|		7	        |	Student	          |
|		4	        |	Teaching Staff	  |
|	     1,2,3,5            |	Non-Teaching Staff|
 ---------------------------------------------------------

#       Admin        => can have the privilege to make changes such as add, remove, update, and view over all other user and files that are present in the Project and payments can only be done be admin.

#      Student       => can have can have the privilege to make changes such as update, and view his own Details, he can also view his academic report.

#   Teaching Staff   => can have the privilege to make changes such as add, remove, update, and view over all other student files and can view, update his own details. ha can also make academic reports

# Non-Teaching Staff => can have can have the privilege to make changes such as update, and view his own Details.
```
### Admin login Credentials :
	User ID  : 7777777
	password : admin

### Classes used in the Project
#### 1) loginCredentials
```cpp
class loginCredentials
```
#### 2) employeeUserDetails 
######   loginCredentials
```cpp
class employeeUserDetails : public loginCredentials
```
#### 3) studentUserDetails
###### loginCredentials
```cpp
class studentUserDetails : public loginCredentials
```
#### 4) academicReport 
###### studentUserDetails
```cpp
class academicReport : public studentUserDetails
```

## Concepts Used in the Project
###### 1) Objects | 2) Classes | 3) Inheritance | 4) Polymorphism | 5) Abstraction | 6) Encapsulation | 7) Templates

### Functions used in the Project
```cpp
unsigned long long int generateId(int subCode,int depCode);
int loginAuthentication(unsigned long long int un,char pw[]);
void viewStudentData();
void viewEmployeeData();
void viewLoginCredentialsData();
void viewAcademicReportsData();
void viewMyAcademicReport(unsigned long long int inputId);
void updateAcademicReport(unsigned long long int inputId);
void addAcademicReport(unsigned long long int inputId);

# Functions with Templates
template <typename T>
void viewMyself(const string filePath,T memberClass,unsigned long long int inputId)
template <typename T>
void removeMyself(const string filePath, const string tempFilePath, T memberClass,unsigned long long int inputId)
template <typename T>
unsigned long long int updateMyself(const string filePath, T memberClass,unsigned long long int inputId)
template <typename T>
void removeMember(const string filePath, const string tempFilePath, T memberClass)
template <typename T>
void addMember(const string filePath, T memberClass)
template <typename T>
void viewData(const string filePath, T memberClass)
template <typename T>
unsigned long long int updateMemberData(const string filePath, T memberClass)
template <typename T>
void updateMoney(const string filePath,T classMember,unsigned long long int inputId,unsigned long long int payment)

```

#### NOTE : 
viewBinaryFiles.cpp is used to view all the Binary files used in the Project

### Run
```cpp
 complie and run main.cpp to see thr Project
```