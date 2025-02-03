#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

struct Course {
        string courseName;
        float grade;
    };

    struct Student {
        string name;
        int id;
        vector<Course> courses;
    };



    vector<Student> students;




                    void RegisterStudent(){
                        Student student;

                        cout<<"Enter student name: "<<"\t";
                        cin>>student.name;

                        cout<<"Enter Student ID: "<<"\t";
                        cin>>student.id;

                        students.push_back(student);
                        cout<<"Student registered!"<<"\n";
                    }


                    void RegisterCourse(){
                        int id;
                        cout<<"Enter Student id: "<<"\t";
                        cin>>id;

                        for (auto& student : students){
                            if(student.id == id){
                                Course course;
                                cout<<"Enter Course name: "<<"\t";
                                    cin>>course.courseName;

                                cout<<"Enter Course grade: "<<"\t";
                                    cin>>course.grade;

                                student.courses.push_back(course);
                                cout<<"Course Registered!"<<"\n";
                                return;
                            }
                            else 
                                cout<<"Student not found!"<<"\n";
                        }
            
                    }


                    void ListStudents(){
                        if(students.empty()){
                            cout << "Not Found!!!"<<"\n";
                            return;
                        }
                        for(const auto& student : students){
                            cout << "Student Name: " << student.name<<"\n";
                            cout << "ID: " << student.id <<"\n";
                            }
                    }


                    void PrintReportCard(){
                            int id;
                            cout<<"Enter Student id: "<<"\t";
                            cin>>id;

                            for(const auto& student : students){
                                if (student.id == id){
                                    cout << "Report Card for " << student.name << " (ID: " << student.id << ")\n"; 
                            for (const auto& course : student.courses) {
                                      cout << "Course: " << course.courseName << ", Grade: " << course.grade << "\n";
                                }
                                return;
                            }
                            else 
                            cout<<"Student not Found!";
                        }
                    }

int main(){
    int choice;
    while (true) {
        cout << "\n1. Register Student\n";
        cout << "2. Register Courses\n";
        cout << "3. List Students\n";
        cout << "4. Generate Report Card\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                RegisterStudent();
                break;
            case 2:
                RegisterCourse();
                break;
            case 3:
                ListStudents();
                break;
            case 4:
                PrintReportCard();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
     }
  }
return 0;
}