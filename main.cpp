#include<iostream>
#include<fstream>
using namespace std;

class rewardProg {
	private:
		int rewardId;
		char name[50];
    char email[50];
		int points = 150;
	public:
		void insertStudent();
    void pointDecreaser(int n);
    void displayStudents();
		int getId();
    int getPoints();
};

void rewardProg::insertStudent() {
	cout << "\nEnter student's name: ";
	cin.ignore();
	cin.getline(name,50);
	cout << "\n\nEnter an ID#: ";
	cin >> rewardId;
	cout << "\nEnter student's email: ";
	cin.ignore();
	cin.getline(email,50);
}
void rewardProg::displayStudents() {
	cout << "\nRewardsId#: " << rewardId;
	cout << "\nStudent name : " << name;
	cout << "\nStudent's email : "<< email;
  cout << "\nTotal Points : " << points;
}
void rewardProg::pointDecreaser(int n){
  points -= n;
}
int  rewardProg::getId() {
	return rewardId;
}
int rewardProg::getPoints(){
  return points;
}

void addStudent();
void viewStudent(int);
void displayAllStudents();
void redeemPoints(int);
void updateStudent(int);
void deleteStudent(int);
void foodmenu();

int main() {
	char ch;
	int num;
	do {		
    //print menu
		system("clear");
		cout << "\n\n\n========== MENU ==========";
		cout << "\n\n\t1.View Points";
		cout << "\n\n\t2.Redeem Points";
		cout << "\n\n\t3.Add New Student";
		cout << "\n\n\t4.Update Student";
		cout << "\n\n\t5.Delete Student";
		cout << "\n\n\t6.View All Students";
		cout << "\n\n\t7.Exit";
		cout << "\n\n\nEnter a number from above (1 - 7) ";
		cin >> ch;
		system("clear");
		switch(ch){
      
     // View Points
			case '1': 	cout << "\n\n\tEnter student's rewardsID: "; 
						cin >> num;
						viewStudent(num); 
						break;

     //Redeem Points
			case '2':  	cout << "\n\n\tEnter student's rewardsID: "; 
						cin >> num;
						foodmenu();
            redeemPoints(num);
						break;

     //Add New Student
     case '3':   addStudent(); 
						break;

     //Update Student
			case '4': 	cout << "\n\n\tEnter student's rewardsID:  "; 
						cin >> num;
						updateStudent(num);
						break;

      //Delete Student
			case '5': 	cout << "\n\n\tEnter student's rewardsID: "; 
						cin >> num;
						deleteStudent(num);
						break;

     //View all students
     case '6':   displayAllStudents(); 
						break;

     //menu goes bye bye 
			case '7': 	cout << "Exiting, Thank you!";
						exit(0);
		}
	}while(ch!='7');
	return 0;
}

// //functions
// Add Student
void addStudent() {
	rewardProg stud;
	stud.insertStudent();
	ofstream oFile;
	oFile.open("student.dat",ios::binary|ios::app);	
	oFile.write(reinterpret_cast<char *> (&stud), sizeof(rewardProg));
	oFile.close();
	cout<<"\n\nNew student added. \nPress Enter key to return to the menu. ";
	cin.ignore();
	cin.get();
}

//List the Food Menu
void foodmenu(){
  cout << "\n\n\t========== FOOD MENU ==========" << endl;
  cout << "\nThe menu and its point cost/gains is as follows:\n\n";
  cout << "Cheeseburger (c) - Cost: 50 points - Gain 20 points!\n";
  cout << "Pizza (p) - Cost: 35 points - Gain 15 points!\n";
  cout << "Salad (s) - Cost: 30 points - Gain 10 points!\n";
  cout << "Daily Special (d) - Cost 60 points - Gain 30 points!\n";
}

//Redeem Point
void redeemPoints(int n){
  rewardProg stud;
	fstream file;
  char food;
    file.open("student.dat",ios::binary|ios::in|ios::out);
	if(!file) {
		cout<<"\n\nFile could not be opened! \nPress Enter key to return to the menu.";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag = false;
	while(file.read(reinterpret_cast<char *> (&stud), sizeof(rewardProg))) {
		if(stud.getId() == n) {
       cout << "\n\nEnter a letter from above [c, p, s, or d]: \n";
      cin >> food;
      //cheeseburger
      if(food == 'c' || food == 'C'){
        stud.pointDecreaser(30);
        int pos=(-1)*sizeof(stud);
			  file.seekp(pos,ios::cur);
			  file.write(reinterpret_cast<char *> (&stud), sizeof(rewardProg));
        cout << "\nYou chose Cheeseburger.\n";
      }
      //pizza
      else if (food == 'p'|| food == 'P'){
        stud.pointDecreaser(20);
        int pos=(-1)*sizeof(stud);
			  file.seekp(pos,ios::cur);
			  file.write(reinterpret_cast<char *> (&stud), sizeof(rewardProg));
        cout << "\nYou chose Pizza.\n"; 
      }
      //salad
      else if (food == 's'|| food == 'S'){
        stud.pointDecreaser(20);
        int pos=(-1)*sizeof(stud);
			  file.seekp(pos,ios::cur);
			  file.write(reinterpret_cast<char *> (&stud), sizeof(rewardProg));
        cout << "\nYou chose Salad\n"; 
      }
      //Daily Special
      else if (food == 'd'|| food == 'D'){
        stud.pointDecreaser(30);
        int pos=(-1)*sizeof(stud);
			  file.seekp(pos,ios::cur);
			  file.write(reinterpret_cast<char *> (&stud), sizeof(rewardProg));
        cout << "\nYou chose the Daily Special\n"; 
      }
      //Invalid
      else {
        cout << "You entered choice incorrectly. Press Enter key to return to the menu.\n"; 
        cin.ignore();
		    cin.get();
      }
      cout << "Points have been successfully redeemed. Points Value Currently: " << stud.getPoints(); 
    flag = true;
    }
  }
   if(flag == false)
	    cout << "\n\nStudent does not exist in our directory!";
    cout << "\nPress Enter key to return to the menu. ";
	  file.close();
	  cin.ignore();
	  cin.get();
}

//Search by RewardsNo
void viewStudent(int n) {
	rewardProg stud;
	ifstream iFile;
	iFile.open("student.dat",ios::binary);
	if(!iFile) {
		cout<<"\n\nFile could not be opened! \nPress Enter key to return to the menu.";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag = false;
	while(iFile.read(reinterpret_cast<char *> (&stud), sizeof(rewardProg))) {
		if(stud.getId() == n) {
			stud.displayStudents();
			cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			flag = true;
		}
	}
    if(flag == false)
	    cout << "\n\nStudent does not exist in our directory!";
	cout << "\nPress Enter key to return to the menu. ";
	iFile.close();
	cin.ignore();
	cin.get();
}

//Display All Students
void displayAllStudents() {
	rewardProg stud;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile) {
		cout<<"\n\nFile could not be opened! \nPress Enter key to return to the menu.";
		cin.ignore();
		cin.get();
    return;
	}
	cout<<"\n\n\n\t\tDIRECTORY\n\n";
	while(inFile.read(reinterpret_cast<char *> (&stud), sizeof(rewardProg))) {
		stud.displayStudents();
		cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}
  inFile.close();
	cout << "\nPress Enter key to return to the menu. ";
	cin.ignore();
	cin.get();
  return;
}

//Update Student
void updateStudent(int n) {
	bool found = false;
	rewardProg stud;
	fstream file;
	file.open("student.dat",ios::binary|ios::in|ios::out);
	if(!file) {
		cout << "\n\nFile could not be opened! \nPress Enter key to return to the menu.";
		cin.ignore();
		cin.get();
		return;
	}
    while(!file.eof() && found==false) {
		file.read(reinterpret_cast<char *> (&stud), sizeof(rewardProg));
		if(stud.getId() == n) {
			stud.displayStudents();
			cout << "\n\nEnter new student details:" << endl;
			stud.insertStudent();
			int pos=(-1)*sizeof(stud);
			file.seekp(pos,ios::cur);
			file.write(reinterpret_cast<char *> (&stud), sizeof(rewardProg));
			cout << "\n\nStudent Updated. \nPress Enter key to return to the menu. ";
			found = true;
		}
	}
	file.close();
	if(found == false)
		cout<<"\n\nRecord not found in our directory. \nPress Enter key to return to the menu. ";
	cin.ignore();
	cin.get();
}

//Delete Student
void deleteStudent(int n) {
	rewardProg stud;
	ifstream iFile;
	iFile.open("student.dat",ios::binary);
	if(!iFile) {
		cout << "\n\nFile could not be opened! \nPress Enter key to return to the menu.";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream oFile;
	oFile.open("Temp.dat",ios::out);	
	while(iFile.read(reinterpret_cast<char *> (&stud), sizeof(rewardProg))) {
		if(stud.getId() != n) {
			oFile.write(reinterpret_cast<char *> (&stud), sizeof(rewardProg));
		}
	}
	oFile.close();
	iFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\nStudent Deleted. \nPress Enter key to return to the menu. ";
	cin.ignore();
	cin.get();
}