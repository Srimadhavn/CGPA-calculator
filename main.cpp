#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    int creditHours;
    double grade;
};

double calculateGPA(const Course& course) {
    return course.grade / course.creditHours;
}

double calculateCGPA(const vector<Course>& courses) {
    double totalGPA = 0.0;
    int totalCreditHours = 0;
    
    for (const Course& course : courses) {
        totalGPA += calculateGPA(course) * course.creditHours;
        totalCreditHours += course.creditHours;
    }
    
    if (totalCreditHours != 0) {
        return totalGPA / totalCreditHours;
    } else {
        return 0.0;
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    
    vector<Course> courses(numCourses);
    
    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter the name of course " << i + 1 << ": ";
        cin.ignore();
        getline(cin, courses[i].name);
        
        cout << "Enter the credit hours for course " << i + 1 << ": ";
        cin >> courses[i].creditHours;
        
        cout << "Enter the grade for course " << i + 1 << ": ";
        cin >> courses[i].grade;
    }
    
    cout << "\nGPA for each course:" << endl;
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << i + 1 << ": " << fixed << setprecision(2) << calculateGPA(courses[i]) << endl;
    }
    
    double cgpa = calculateCGPA(courses);
    cout << "\nCGPA: " << fixed << setprecision(2) << cgpa << endl;
    
    return 0;
}
//comment addeddd