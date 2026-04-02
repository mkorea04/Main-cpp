#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;





class Student {
public:
    int id;
    string name;
    string course;
    float marks;

    string getGrade() const {
        if (marks >= 80) return "A";
        else if (marks >= 70) return "B";
        else if (marks >= 60) return "C";
        else if (marks >= 50) return "D";
        else return "F";
    }

    string getStatus() const {
        return (marks >= 50) ? "PASS" : "FAIL";
    }

    void display() const {
             cout << "ID: " << id;
             cout<< " | Name: " << name<<endl;
             cout<< " | Course: " << course<<endl;
             cout<< " | Marks: " << marks<<endl;
             cout<< " | Grade: " << getGrade() <<endl;
             cout<< " | Status: " << getStatus()<<endl;
    }
};

vector<Student> students = {
    {03541, "Faustine Ndimila",  "BDTS", 85},
    {03542, "Helieth Onesmo", "BDTS", 72},
    {03543, "Nasri kijuu", "BASE", 60},
    {03544, "Criss Daudi", "BBSE", 55},
    {03545, "Magnus Shayo", "BOS", 40},
    {03546, "Shalfat Juma",  "BOS", 60},
    {03547, "John Fuko", "BASE", 47},
    {03533, "Neema Mitimingi", "BBSE", 58},
    {03534, "Groly Godson", "BDTS",85},
    {03550,"Gwiyena Dotto","BDTS",90},
    {03551,"Gedalia Wayaga","BDTS",76}



  };

bool validCourse(string c) {
    return (c=="BOS"||c=="BDTS"||c=="BASE"||c=="BBSE");
}

void addStudent() {
    Student s;
    cout<<"Enter student ID: ";
    cin>>s.id;
    cin.ignore();

    cout<<"Enter name (two names): ";
    getline(cin,s.name);


    cout<<"Enter course (BOS,BDTS,BASE,BBSE): ";
    getline(cin,s.course);

    if(!validCourse(s.course)){
        cout<<"Invalid course\n";
        return;
    }

    cout<<"Enter marks: ";
    cin>>s.marks;

    students.push_back(s);
    cout<<"Student added successfully\n";
}

void displayStudents() {
    for(const auto &s:students)
        s.display();
}

void searchStudent() {
    int id;
    cout<<"Enter student ID: ";
    cin>>id;

    for(const auto &s:students){
        if(s.id==id){
            s.display();
            return;
        }
    }
    cout<<"Invalid ID\n";
}

void updateMarks() {
    int id;
    cout<<"Enter student ID to update: ";
    cin>>id;

    for(auto &s:students){
        if(s.id==id){
            cout<<"Enter new marks: ";
            cin>>s.marks;
            cout<<"Marks updated successfully\n";
            return;
        }
    }
    cout<<"Invalid ID\n";
}

void sortStudents() {
    int choice;
    cout<<"1. Ascending\n2. Descending\nSelect: ";
    cin>>choice;

    if(choice==1){
        sort(students.begin(),students.end(),
        [](Student a,Student b){ return a.marks<b.marks; });
    }else{
        sort(students.begin(),students.end(),
        [](Student a,Student b){ return a.marks>b.marks; });
    }

    cout<<"Sorting completed\n";
}

void statistics() {
    if(students.empty()){
        cout<<"No data available\n";
        return;
    }

    float total=0;
    float highest=students[0].marks;
    float lowest=students[0].marks;

    for(const auto &s:students){
        total+=s.marks;
        if(s.marks>highest) highest=s.marks;
        if(s.marks<lowest) lowest=s.marks;
    }

    cout<<"Average: "<<total/students.size()<<endl;
    cout<<"Highest: "<<highest<<endl;
    cout<<"Lowest: "<<lowest<<endl;
    cout<<"Total Students: "<<students.size()<<endl;
}

void saveToFile() {
    ofstream file("students.txt");

    for(const auto &s:students){
           file<<s.id<<endl;
           file <<s.name<<endl;
           file<<s.course<<endl;
           file <<s.marks<<endl;
           file<<s.getGrade()<<endl;
           file<<s.getStatus()<<endl;
    }

    file.close();
    cout<<"Records saved successfully\n";
}

int main() {
    int choice;

    while(true){
        cout<<"\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout<<"1. Display student\n";
        cout<<"2. Search student\n";
        cout<<"3. Add student\n";
        cout<<"4. Update Marks\n";
        cout<<"5. Sort Students\n";
        cout<<"6. Statistics\n";
        cout<<"7. Save Records\n";
        cout<<"8. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1: displayStudents(); break;
            case 2: searchStudent(); break;
            case 3: addStudent(); break;
            case 4: updateMarks(); break;
            case 5: sortStudents(); break;
            case 6: statistics(); break;
            case 7: saveToFile(); break;
            case 8: return 0;
            default: cout<<"Invalid choice\n";
        }
    }
}
/*FAUSTINE NDIMILA MAKARANGA       EASTC/BDTS/26/03941
  GWIYENA DOTTO CHARLES            EASTC/BDTS/26/03760
  GROLY GODSON MARKALOS            EASTC/BDTS/26/04597
  FRAVIUS DONATUS AUDAX            EASTC/BDTS/26/04207
  HUSNA KASSM CHIRUMA              EASTC/BDTS/26/04490
  MALEGI MATAGULWA                 EASTC/BDTS/26/03751
  GEDALIA SAMSON WAYAGA            EASTC/BDTS/26/03949
  HELIETH ONESMO MWANGILI          EASTC/BDTS/26/03770
  ERICKSON CASTRO WILIAM           EASTC/BDTS/26/04310
  HASSAN HAMADA KHATIBU            EASTC/BDTS/26/04024*/
