#include<sstream>
#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>
#include<cmath>
using namespace std;

//GLOBAL VARIABLE CAN BE USED INSIDE MAIN ANYWHERE
int fromGlobal=0;

//Function for valid course code.

bool isValidCourseCode(string course)
{
    bool flag=0 ,Flag=0,flag1=0;
	for (int i = 0; i <2 ; i++)
	{
		if((course[i] >= 'A'&& course[i] <= 'Z'))
		{
		flag=1;
		}
	}
	for (int i = 2; i <=4 ; i++)
	{	
		if((course[i]>='0'&&course[i] <= '9'))
		{
			Flag=1;
		}
	}
	if (flag==1&&Flag==1)
	{
	
	 flag1=1;
}
return flag1;
}

 
// Function for valid course name

bool isValidCourseName(string courseName)
 {
	bool flag = 0;
	int i = 0;
	if (((courseName[i] >= 'A') && (courseName[i] <= 'Z')) || ((courseName[i] >= 'a') && (courseName[i] <= 'z')) || (courseName[i] == ' '))
	{
	
	}		flag = 1;
	
	return flag;
}

// function for valid credit hours
bool isValidCreditHours(int crdHrs)
{

 bool flag=0;
 
	if ((crdHrs >= 1) && (crdHrs <= 3))
	{
	
		flag= 1;
}
		return flag;
}

// function for valid semester		
bool isValidSemester(int semester){
	
			if ((semester >= 1 && semester <= 8))
				return 1;
			else	return 0;
			}

// function for add course
void addCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], string courseCode, string courseName, int crdHrs, int semester)
 {
	codeList[fromGlobal] = courseCode;
	crtHrsList[fromGlobal] = crdHrs;
	semList[fromGlobal] =  semester ;
	nameList[fromGlobal] = courseName;
	cout << "Course has been added successfully! " << endl;
	fromGlobal++;
}

// function for editing of course
void editCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], string courseCode, string courseName, int crdHrs, int semester)
 {
	int editing;
	for (int i = 0; i < sizeof (codeList); i++) 
	{
		if (codeList[i] == courseCode) 
		{
			editing = i;
			break;
		}
	}

codeList[editing] = courseCode;
	nameList[editing] = courseName;
	crtHrsList[editing] =crdHrs;
	semList[editing] = semester;
	cout << "Course has been edited successfully!" << endl;
}		

// function for deleting course
void deleteCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], string courseCode) 
{
	int  find;
	if (isValidCourseCode(courseCode)) 
	{
		for (int i = 0; i <sizeof(codeList); i++) 
		{
			if (codeList[i] == courseCode) 
			{
				find = i;
				break;
			}
		}
		for (int c = find; c <sizeof(codeList); c++)
		 {
			codeList[c] = codeList[c + 1];
			nameList[c] = nameList[c + 1];
			crtHrsList[c] = crtHrsList[c + 1];
			semList[c] = semList[c + 1];
		}
		cout << "Course has been deleted successfully!" << endl;
	}
}

// function for view courses
void viewCourses(string codeList[], string nameList[], int crtHrsList[], int semList[]) 
{
	cout << setw(5) << "Course Code" << setw(15) << "Credit Hours" << setw(20) << "Semester" << setw(20) << "Name" << endl;
	for (int i = 0; i <=fromGlobal; i++) 
	{
		cout << setw(5) << codeList[i] << setw(15) << crtHrsList[i] << setw(25) << semList[i] << setw(30) << nameList[i] << endl;
	}
}

// function for view semester course
void viewSemesterCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int semester) {
	cout << setw(5) << "Course Code" << setw(15) << "Name" << setw(30) << "Credit Hours" << endl;
	int index;
	for (int i = 0; i < fromGlobal; i++) 
	{
		if (semList[i] == semester)
		 {
			index = i;
			cout << setw(5) << codeList[index] << setw(35) << nameList[index] << setw(15) << crtHrsList[index] << endl;
		}
	}
}
// function for valid registration number
bool isValidRegistrationNum(string regNo) 
{
	bool flag = 0;
	int length=regNo.length();
	if ((regNo[5] >= 'A' && regNo[5] <= 'Z' ) && (regNo[6]>='A' && regNo[6] <= 'Z' ) && regNo[4]=='-' && regNo[7]=='-' && (length<=11 || length<=10)) 
	{
		flag = 1;
	}
	
	return flag;
}

// function for valid student name
bool isValidStudentName(string studentName) 
{
	bool flag = 0;
	int length=studentName.length();
	for(int i=0;i<length;i++)
	{
	if (((studentName[i] >= 'A') && (studentName[i] <= 'Z')) || ((studentName[i] >= 'a') && (studentName[i] <= 'z')) || (studentName[i] == ' '))
		flag = 1;
	else {
		flag=0;
		break;
	}
	}
	if (flag == 0)
		cout << "Invalid student name" << endl;
	return flag;
}

// function for Save courses.
bool saveCourses(string codeList[], string nameList[], int crtHrsList[], int semList[])
 {
	bool flag = 0;
	int i = 0;
	ofstream file;
	file.open("Courses.txt");
	if (file.is_open())
	 {
		while (fromGlobal != 0) 
		{
			file << codeList[i] << "," << nameList[i] << "," << crtHrsList[i] << "," << semList[i] << endl;
			i++;
			fromGlobal--;
		}
		file.close();
		flag = 1;
	}
	else cout << "File does not open to save" << endl;
	return flag;
}

// function to load courses
bool loadCourses(string codeList[], string nameList[], int crtHrsList[], int semList[])
 {
	bool flag = 0;
	ifstream inFile;
	inFile.open("Courses.txt");
	string myString, myString1, a, b;
	string line;
	if (inFile.is_open())
	 {
		while (!inFile.eof()) 
		{
			while (getline(inFile, line))
			 {
				stringstream  ss(line);
				getline(ss, a, ',');
				codeList[fromGlobal] = a;
				getline(ss, b, ',');
				nameList[fromGlobal] = b;
				getline(ss, myString, ',');
				getline(ss, myString1, ',');

				fromGlobal++;
			}
		}
		inFile.close();
		flag = 1;
	}
	else cout << "File does not open to load courses" << endl;
	return flag;
}
// function to Load user for admin
bool loadUser(string userList[], string passwordList[]) 
{
	bool flag = 0;
	int i = 0;
	ifstream inFile;
	inFile.open("Users.txt");
	string line, a, b;
	if (inFile.is_open())
	 {
		while (!inFile.eof()) 
		{
			while (getline(inFile, line)) 
			{
				stringstream  ss(line);
				getline(ss, a, ',');
				userList[i] = a;
				getline(ss, b, ',');
				passwordList[i] = b;
				i++;
			}
		}
		inFile.close();
		flag = 1;
	}
	return flag;
}

// function to Match username & password for Admin
bool matchUser(string userList[], string passwordList[], string userName, string password) 
{
	bool flag = 0;
	int i = 0;
	while (!flag) 
	{
		if (userList[i - 1] == userName)
		 {
			if (passwordList[i - 1] == password) 
			{
				flag = 1;
			}
		}
		i++;
	}
	if (flag == 0)
		cout << "Invalid username & password!" << endl;
	return flag;
}



// function to add student
void addStudent(string stdNamesList[], string stdRegNoList[], string studentName, string regNo)
 {
		stdNamesList[fromGlobal] = studentName;
		stdRegNoList[fromGlobal] = regNo;
		cout << "Student has been added successfully " << endl;
	fromGlobal++;
}

// function to update student
void updateStudent(string stdNamesList[], string stdRegNoList[], string studentName, string regNo)
 {
	int index, sstdRegNoList = sizeof(stdRegNoList);
	for (int i = 0; i <= fromGlobal; i++) {
		if (stdRegNoList[i] == regNo) 
		{
			index = i;
			break;
		}
	}
	if (isValidRegistrationNum(regNo) && isValidStudentName(studentName)) 
	{
		stdNamesList[index] = studentName;
		stdRegNoList[index] = regNo;
		cout << "Student has been edited successfully" << endl;
	}
	else cout << "Invalid Data. Kindly check your data." << endl;
}

// function for Deleting student
void deleteStudent(string stdNamesList[], string stdRegNoList[], string (&stdCourseList)[1000][2], string regNo)
 {
	int index, sregList = sizeof(stdRegNoList) / sizeof(stdRegNoList[0]);
		for (int i = 0; i < fromGlobal; i++)
		 {
			if (stdRegNoList[i] == regNo) 
			{
				index = i;
				break;
			}
		}
		for (int c = index; c < sregList; c++) {
			stdNamesList[c] = stdNamesList[c + 1];
			stdRegNoList[c] = stdRegNoList[c + 1];
			for(int i=0;i<10;i++)
			{
			for(int j=0;j<2;j++)
			{
			stdCourseList[i][j]=stdCourseList[i][j+1];
		}
	}
		}
		cout << "Student has been deleted successfully!" << endl;
}

// function for  View all students
void viewStudents(string stdNamesList[],string stdRegNoList[],string stdCourseList[][2]) 
{
	int n = 0;
	cout << setw(25) << "Students Names" << setw(25) << "Registration numbers" << setw(20)<<"Courses" <<endl;
	for (int i = 0; i <= fromGlobal; i++) 
	{
		cout << setw(15) << stdNamesList[i] << setw(25) << stdRegNoList[i] << setw(20);
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<stdCourseList[i][j];
		}
	}
}

// function to Unregistered course
void unRegisterCourse(string stdRegNoList[], string(&stdCourseList)[1000][2], string regNo, string courseCode) 
{
	static int c=0;
	bool flag=0;
	int sstdRegNoList = sizeof(stdRegNoList);
	for (int i = 0; i < fromGlobal; i++) 
	{
		for (int i = 0; i < sstdRegNoList; i++) 
		{
			if (stdRegNoList[i] == regNo) 
			{
				for(int i=0;i<10;i++)
				{
		for(int j=0;j<2;j++)
		{
			stdCourseList[i][j]=stdCourseList[i][j+1];
			cout<<"You are successfully unregistered from this course."<<endl;
		}
	}
			}
		}
	}
	if(flag==0)
	cout<<"Course is not present in your course List."<<endl;
	c++;
}

// function for Register Course
void registerCourse(string stdRegNoList[], string(&stdCourseList)[1000][2], string courseCodeList[], string regNo, string courseCode)
 {
	static int c = 0;
	bool flag=0;
	for (int i = 0; i < fromGlobal; i++) 
	{
		if (courseCodeList[i] == courseCode)
		 {
			for (int i = 0; i < fromGlobal; i++) 
			{
				if (stdRegNoList[i] == regNo) 
				{
					stdCourseList[fromGlobal][fromGlobal + 1] = courseCode;
					flag=1;
					cout<<"You are successfully registered in this course."<<endl;
				}
			}
		}
	}
	if(flag==0){
	cout << "Course is not present in course list." << endl;
	}
}
	// function to Load users for students
bool loadSUser(string userList[], string passwordList[])
 {
	bool flag = 0;
	int i = 0;
	ifstream inFile;
	inFile.open("SUsers.txt");
	string line, a, b;
	if (inFile.is_open()) 
	{
		while (!inFile.eof()) 
		{
			while (getline(inFile, line)) {
				stringstream  ss(line);
				getline(ss, a, ',');
				userList[i] = a;
				getline(ss, b, ',');
				passwordList[i] = b;
				i++;
			}
		}
		inFile.close();
		flag = 1;
	}
	return flag;
}

// function to Match username & password for Students
bool matchSUser(string userList[], string passwordList[], string userName, string password) 
{
	bool flag = 0;
	int i = 0;
	while (!flag) 
	{
		if (userList[i - 1] == userName)
		 {
			if (passwordList[i - 1] == password) 
			{
				flag = 1;
			}
		}
		i++;
	}
	if (flag == 0)
		cout << "Invalid username & password!" << endl;
	return flag;
}


// function for Specific Student Courses
void viewSpecificStd(string userName,string RegNoList[],string StdCourseList[][2])
{
	int index;
	for(int i=0;i<fromGlobal;i++)
	{
		if(RegNoList[i]==userName)
		{
			index=i;
			break;
		}
	}
	for(int i=0;i<fromGlobal;i++)
	{
		for(int j=0;j<fromGlobal;j++)
		{
			cout<<StdCourseList[i][j]<<",";
		}
	}
	
	
}


// function to Save students
bool saveStudents(string RegNoList[],string StdNameList[],string StdCourseList[][2])
{
	bool flag = 0;
	int i = 0;
	ofstream file;
	file.open("Students.txt");
	if (file.is_open()) {
		while (fromGlobal != 0)
		 {
			file << RegNoList[i] << "," << StdNameList[i] <<endl;
			i++;
			for(int a=0;a<5;a++)
			{
				for(int b=0;b<=a;b++)
				{
					file<<StdCourseList[a][b]<<endl;
				}
			}
			fromGlobal--;
		}
		file.close();
		flag = 1;
	}
	else cout << "File does not open to save student data!" << endl;
	return flag;
	
	
}

// function for LOAD STUDENTS
bool loadStudents(string RegNoList[],string StdNameList[],string StdCourseList[][2]){
	bool flag = 0;
	ifstream inFile;
	inFile.open(".txt");
	string myString, myString1, a, b;
	string line;
	if (inFile.is_open()) {
		while (!inFile.eof()) {
			while (getline(inFile, line)) {
				stringstream  ss(line);
				getline(ss, a, ',');
				RegNoList[fromGlobal] = a;
				getline(ss, b, ',');
				StdNameList[fromGlobal] = b;
				getline(ss, myString, ',');
				for(int i=0;i<fromGlobal;i++){
					for(int j=0;j<fromGlobal;j++){
						StdCourseList[i][j]=myString;
					}
				}
				fromGlobal++;
			}
		}
		inFile.close();
		flag = 1;
	}
	else cout << "File does not open to load Student file" << endl;
	return flag;
}




	int main()
	{
		
		string codeList[100], userList[100], passwordList[100];
	string nameList[100];
	string stdNamesList[100], stdRegNoList[100], studentName, regNo;
	string stdCourseList[1000][2];
	int crtHrsList[3];
	int semList[8];
	int selectedOption = 0,choose, semester, crdHrs;
	string courseCode, courseName, userName, password;
c:	cout << "*** Welcome to University Learning Management System ***" << endl;
	cout << "Dear User, current software is intended for authorized users only." << endl;
	cout<<"Choose the option for Login "<<endl
			<<"(1) For Admin "<<endl<<"(2) For student"<<endl;
	cin>>choose;
	 if (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
    }
	switch(choose)
	{
		case 1:
		{
	cout << "Login to the system to get access." << endl;
	cout << "Username : ";
	cin >> userName;
	cout << "Password : ";
	cin >> password;
	if (loadUser(userList, passwordList)) 
	{
		if (matchUser(userList, passwordList, userName, password)) 
		{
			cout << "You have successfully logged into the system" << endl << endl;
m:	cout << "Choose the following option" << endl;
			cout << "1    " << "Add Course" << endl;
			cout << "2    " << "Update Course" << endl;
			cout << "3    " << "Delete Course" << endl;
			cout << "4    " << "View All Course" << endl;
			cout << "5    " << "View Courses of a Semester" << endl;
			cout << "6    " << "Add new Student" << endl;
			cout << "7    " << "Update Student" << endl;
			cout << "8    " << "Delete Student" << endl;
			cout << "9    " << "View all Students" << endl;
			cout << "10    " << "Registered the course for student" << endl;
			cout << "11    " << "Unregister the course for student" << endl;
			cout << "12    " << "Logout of the system" << endl;
			cout << "13    " << "Exit Program" << endl;
			if (loadCourses(codeList, nameList, crtHrsList, semList))
			 {
				while (selectedOption != 13)
				{	cout<<endl;
					cout << "Choose the option: ";
					cin >> selectedOption;
					 if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
					// enter option 1 by 1
					switch (selectedOption)
					 {
					case 1:
					{
						cout << "Enter the Details of the course: ";
						cin >> courseCode;											// enter course code
						 if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
						cout<<endl<<"Enter credit Hours: ";
						cin >> crdHrs;												// enter credit hours of that course
						 if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
						cout<<endl<<"Enter semester: ";
						cin >> semester;											// enter semester
						 if (cin.fail())
							    {
							        cin.clear();
							        cin.ignore(100, '\n');
							    }
						cout<<endl<<"Enter the course name: ";
						cin.ignore(1,' ');
						getline(cin,courseName);											// enter name of course you want to add
						cout << endl;
						if (cin.fail())
   							 {
        						cin.clear();
        						cin.ignore(100, '\n');
    						}
						if (isValidCourseCode(courseCode) && isValidCreditHours(crdHrs) && isValidSemester(semester) && isValidCourseName(courseName)) 
						{
							addCourse(codeList, nameList, crtHrsList, semList, courseCode, courseName, crdHrs, semester);		// add new course
						}
						else cout << "Invalid Data entered!" << endl;
						cout << "Press Enter to continue...";
					    if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
					    goto m;
						break;
					}
					case 2:
					{
						cout << "Enter the course code to edit: ";
						cin >> courseCode;
						cout << endl;
						{
							cout << "Enter the new details of the course code: ";
							cin >> courseCode;
						 if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
							cout<<endl<<"Enter new credit hours: ";
							cin >> crdHrs;
						 if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
							cout<<endl<<"Enter new semester number: ";
							cin >> semester;
						 if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
							cout<<endl<<"Enter new course name: ";
							cin.ignore(1,' ');
							getline(cin,courseName);
						 if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
							cout << endl;
						}
						if ((isValidCourseCode(courseCode)) && (isValidCourseName(courseName)) && (isValidCreditHours(crdHrs)) && (isValidSemester(semester)))
							editCourse(codeList, nameList, crtHrsList, semList, courseCode, courseName, crdHrs, semester);	// edit previous course
						else cout << "Invalid Data. Kindly check your Data." << endl;
						cout << "Press Enter to continue...";
					    if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
						goto m;
						break;
					}
					case 3:
					{cout << "Enter the course code to delete: ";
					cin >> courseCode;																	// enter course code you want to delete
					 if (cin.fail())
				    {
				        cin.clear();
				        cin.ignore(100, '\n');
				    }
					cout << endl;
					deleteCourse(codeList, nameList, crtHrsList, semList, courseCode);					// delete existing course
					cout << "Press Enter to continue...";
					    if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
					    goto m;
					break;
					}
					case 4:
						viewCourses(codeList, nameList, crtHrsList, semList);								// view all courses
						cout << "Press Enter to continue...";
					    if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
					    goto m;
						break;
					case 5: {
						cout << "Enter Semester: ";
						cin >> semester;																	// enter specific semester
						 if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
						cout << endl;
						if (isValidSemester(semester))
							viewSemesterCourses(codeList, nameList, crtHrsList, semList, semester);				// view specific semester course
						else cout << "Invalid semester" << endl;
						cout << "Press Enter to continue...";
					    if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
					    goto m;
						break;
					}
					case 6: {
						cout << "Enter registration number of Student: ";									// enter registration number and name of student
						cin >> regNo;
						 if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
						cout<<endl<<"Enter student name: ";
						cin.ignore(1,' ');
						getline(cin,studentName);
						 if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
						if (isValidRegistrationNum(regNo) && (isValidStudentName(studentName))) {
						addStudent(stdNamesList, stdRegNoList, studentName, regNo);
						}
						else cout << "Invalid registration number and student name" << endl;
						cout << "Press Enter to continue...";
					    if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
					    goto m;
						break;
					}
					case 7:
					 {
						cout << "Enter registration number of the student to edit:";			// enter registration number
						cin >> regNo;
						 if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
						if (isValidRegistrationNum(regNo)) 
						{
							cout << "Enter registration number of the Student: ";								// enter new details of student
							cin >> regNo;
							cout<<endl<<"Enter student name: ";
							cin.ignore(1,' ');
							getline(cin,studentName);
							updateStudent(stdNamesList, stdRegNoList, studentName, regNo);
						}
						else cout << "Invalid Registration number" << endl;
						cout << "Press Enter to continue...";
					    if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
					    goto m;
						break;
					}
					case 8: {
						cout << "Enter the registration of student to delete: ";				// enter registration number to delete
						cin >> regNo;
						 if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
						if(isValidRegistrationNum(regNo)){
						deleteStudent(stdNamesList, stdRegNoList, stdCourseList, regNo);
						}
						else cout<<"Invalid registration number"<<endl;
						cout << "Press Enter to continue...";
					    if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(10000, '\n');
					    }
					    goto m;
						break;
					}
					
					case 9:{
						viewStudents(stdNamesList,stdRegNoList,stdCourseList);
						cout << "Press Enter to continue...";
					    if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
					    goto m;
						break;
					}
					case 10: {
						cout << "Enter registration of student for course registration: ";	// enter registration number
						cin >> regNo;
						if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
						cout << endl << "Enter course code to register: ";						// enter course code
						cin >> courseCode;
						if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
						if(isValidRegistrationNum(regNo) && isValidCourseCode(courseCode)){
						registerCourse(stdRegNoList, stdCourseList, codeList, regNo, courseCode);	// To register the student
						}
						else cout<<"Invalid registration number and course code"<<endl;
						cout << "Press Enter to continue...";
					    if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
					    goto m;
						break;
					}
					case 11: {
						cout << "Enter the registration of the student: ";				// To unregister the student
						cin >> regNo;
						if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
						cout << endl <<"Enter Course Code to unregister : ";
						cin >> courseCode;
						if (cin.fail())
						    {
						        cin.clear();
						        cin.ignore(100, '\n');
						    }
						    cout<<endl;
						if(isValidRegistrationNum(regNo) && isValidCourseCode(courseCode)){
						unRegisterCourse(stdRegNoList, stdCourseList, regNo, courseCode);
						}
						else cout<<"Invalid registration number and course code"<<endl;
						cout << "Press Enter to continue...";
					    if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
					    goto m;
						break;
					}

					case 12: {
						cout << "You are logged out from the system" << endl << endl;
						if (saveCourses(codeList, nameList, crtHrsList, semList)) {					// exit from program and save courses
							cout << "Data is successfully save in course file" << endl;
						}
						else cout << "Data is not save in file" << endl;
						if (saveStudents(stdRegNoList, stdNamesList, stdCourseList)){
							cout<<"Data is successfully save in Students File"<<endl;
						}
						else cout<<"Data is not Save in Student File."<<endl;
						goto c;
						break;
					}
					default:
						{
						cout << "Exit the Program" << endl;
						if (saveCourses(codeList, nameList, crtHrsList, semList)) {					// exit from program and save courses
							cout << "Data is successfully save in course file" << endl;
						}
						else cout << "Data is not save in file" << endl;
						if (saveStudents(stdRegNoList, stdNamesList, stdCourseList)){
							cout<<"Data is successfully save in Students File"<<endl;
						}
						else cout<<"Data is not Save in Student File."<<endl;
					}
					}
				}
			}
			else cout << "File does not exist to load courses." << endl;
		}
	}
	else cout << "Sorry, we are unable to run the program, as user data does not exist." << endl;
	break;
	}
	case 2:{
		cout<<"Enter your registration number : "<<endl;
		cin>>userName;
		cout<<"Password : "<<endl;
		cin>>password;
		if (loadSUser(userList, passwordList)) {
		if (matchSUser(userList, passwordList, userName, password)){
		cout<<"Enter 1 to view registered course : "<<endl
			<<"Enter 2 to logout of the system : "<<endl
			<<"Enter 3 to exit : "<<endl;
		cin>>selectedOption;
		if (cin.fail())
		 {
	        cin.clear();
	        cin.ignore(100, '\n');
		}
		switch(selectedOption)
		{
			case 1:{
				viewSpecificStd(userName,stdRegNoList,stdCourseList);
				cout << "Press Enter to continue...";
			    if (cin.fail())
			    {
			        cin.clear();
			        cin.ignore(100, '\n');
			    }
			    goto m;
				break;
				} 
			
			case 2:{
				cout<<"You are logged out from the system"<<endl;
				goto c;
				break;
				}
			default:
				cout<<"Exit the Program."<<endl;
			}
		}
		else cout<<"Username and Password does not match."<<endl;
		}
		else cout<<"File username for student unable to load."<<endl;
		break;
		}
		default: {
		cout<<"This option is not present in this system."<<endl<<endl;
		cout << "Press Enter to continue..."<<endl;
					    if (cin.fail())
					    {
					        cin.clear();
					        cin.ignore(100, '\n');
					    }
					    goto c;
		}
		}
	return 0;
}
