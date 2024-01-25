#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

const int SIZE = 50;

struct studInfo {
    string name;
    string matric;
    double exam;
    double quiz1, quiz2, quiz3, quiz4;
    double marks;
    string grade;
};

void readDatafromfile(studInfo recordStud[], int &i);
void calculateGrade(studInfo &student);
// void Display(studInfo recordStud[], int i);
void Display(studInfo *, int i);

int main() {
    studInfo recordStud[SIZE];
    int i = 0;

    readDatafromfile(recordStud, i);
    Display(recordStud, i);

    //return 0; 
}

void readDatafromfile(studInfo recordStud[], int &i) {
    fstream myfile("test.txt", ios::in); // Open file
    
   // if (!myfile.is_open()) {
   while (!myfile.eof())
    
   while (i < SIZE && getline(myfile, recordStud[i].name)) 
   {
        myfile >> recordStud[i].matric;
        myfile >> recordStud[i].quiz1;
        myfile >> recordStud[i].quiz2;
        myfile >> recordStud[i].quiz3;
        myfile >> recordStud[i].quiz4;
        myfile >> recordStud[i].exam;

        // Calculate overall mark as 60% of the average quiz score + 40% of the exam score
        recordStud[i].marks = 0.6 * ((recordStud[i].quiz1 + recordStud[i].quiz2 + recordStud[i].quiz3 + recordStud[i].quiz4) / 4.0)
                                   + 0.4 * recordStud[i].exam;

        // Calculate grade based on the overall mark
        calculateGrade(recordStud[i]);


        i++; // Number of records / next subscript
   }

    myfile.close(); // Close file
}

void calculateGrade(studInfo &student) {
    // Adjust the grading criteria based on your institution's system
if (student.marks >= 80) {
        student.grade = 'A';
    } else if (student.marks >= 75) {
        student.grade = "A-";
    } else if (student.marks >= 70) {
        student.grade = "B+";
    } else if (student.marks >= 65) {
        student.grade = 'B';
    } else if (student.marks >= 60) {
        student.grade = "B-";
    } else if (student.marks >= 55) {
        student.grade = "C+";
    } else if (student.marks >= 50) {
        student.grade = "C";
    } else if (student.marks >= 45) {
        student.grade = "C-";
    } else if (student.marks >= 40) {
        student.grade = "D+";
    } else if (student.marks >= 35) {
        student.grade = 'D';
    } else {
        student.grade = 'F';
    }
}



void Display(studInfo recordStud[], int i) {
    
    cout << setw(50) << right << "REPORT" << endl;
    cout << setw(51) << right << "========" << endl;
    cout << "                "<< endl;
    cout << "Statistical analysis for a class of students for subject Computer Programming" << endl;
    cout << "                "<< endl;
    cout << "list of students with their grades" << endl;
    cout << "__________________________________" << endl;
    cout << setw(30) << left << "Name" << setw(15) << right << "Matric"
         << setw(8) << right << "Quiz1" << setw(7) << right << "Quiz2"
         << setw(7) << right << "Quiz3" << setw(7) << right << "Quiz4"
         << setw(7) << right << "Exam" << setw(9) << right << "Marks"
         << setw(10) << right << "Grade" << endl;
    cout << "__________________________________" << endl;

    for (int j = 0; j < i; j++)
        cout << setw(30) << left << recordStud[j].name << setw(15) << right << recordStud[j].matric
             << setw(7) << right << recordStud[j].quiz1 << setw(7) << right << recordStud[j].quiz2
             << setw(7) << right << recordStud[j].quiz3 << setw(7) << right << recordStud[j].quiz4
             << setw(7) << right << recordStud[j].exam 
             << setw(10) << right << recordStud[j].marks
             << setw(9) << right << recordStud[j].grade << endl;
cout << "\n\n__________________________________" << endl;
    cout << setw(30) << left << "Score" << setw(15) << right << ""
         << setw(8) << right << "Quiz1" << setw(7) << right << "Quiz2"
         << setw(7) << right << "Quiz3" << setw(7) << right << "Quiz4"
         << setw(7) << right << "Exam" << setw(9) << endl;
    cout << "__________________________________" << endl;
    double highest_score[5] = {};
    double lowest_score[5] = {};
    double ave[i] = {};
    double q1_data[i] = {};
    double q2_data[i] = {};
    double q3_data[i] = {};
    double q4_data[i] = {};
    double exam_data[i] = {};
    for (int j = 0; j< i; j++)  {
        q1_data[j] = recordStud[j].quiz1;
        q2_data[j] = recordStud[j].quiz2;
        q3_data[j] = recordStud[j].quiz3;
        q4_data[j] = recordStud[j].quiz4;
        exam_data[j] = recordStud[j].exam;
    }
    double* all_data[5] = {q1_data, q2_data, q3_data, q4_data, exam_data};
    for (int data_id = 0; data_id < 5; data_id++)   {
            int max = 0;
            int min = 101;
            for (int id = 0; id < i; id++)  {
            if (all_data[data_id][id] > max)    {
                highest_score[data_id] = all_data[data_id][id];
                max = all_data[data_id][id];
            } 
            if (all_data[data_id][id] < min)    {
                lowest_score[data_id] = all_data[data_id][id];
                min = all_data[data_id][id];
            } 
            ave[data_id] = ave[data_id] + all_data[data_id][id];
        } 
    }

    cout << "Highest" << setw(44) << highest_score[0] << setw(7) << highest_score[1] << setw(7) << highest_score[2] << setw(7) << highest_score[3] << setw(7) << highest_score[4] << endl;
    cout << "Lowest" << setw(45) << lowest_score[0] << setw(7) << lowest_score[1] << setw(7) << lowest_score[2] << setw(7) << lowest_score[3] << setw(7) << lowest_score[4] << endl;
    cout << "Average" << setw(45) << ave[0] / 4 << setw(7) << ave[1] / 4 << setw(7) << ave[2] / 4 << setw(6) << ave[3] / 4 << setw(7) << ave[4] / 4 <<endl;

string total_grades[i] = {};
    for (int j = 0; j < i; j++) {
        total_grades[j] = recordStud[j].grade;
    }
    map<string, int> duplicate_grades= {
        {"A", 0},
        {"A-",0},
        {"B+",0},
        {"B",0},
        {"B-",0},
        {"C",0},
        {"C+",0},
        {"D+",0},
        {"D",0},
        {"F",0},
    };
    for (auto key : duplicate_grades)  {
        int duplicate_times = 1;
        for (int j = 0; j < i; j++) {
            if (recordStud[j].grade == key.first)  {
                duplicate_grades[key.first] = duplicate_times;
                duplicate_times++;
            }
            // duplicate_times = 0;
        }
    }
    cout << "\n\nGrade" << setw(47) << "Number of Students" << endl;
    for (auto key : duplicate_grades)  {
        if (key.first.length() != 1) {
        cout << key.first << setw(40) << key.second << endl;
        }   else    {
            cout << key.first << setw(41) << key.second << endl;
        }
    }
}