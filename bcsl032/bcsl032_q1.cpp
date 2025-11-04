#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Employee {
    int empID;
    string name;
    int day, month, year;  // Date of Birth
    string department;
    int retirementAge;
};

// Calculate age on given date
int calculateAge(int dobDay, int dobMonth, int dobYear, int checkDay, int checkMonth, int checkYear) {
    int age = checkYear - dobYear;
    
    if (checkMonth < dobMonth || (checkMonth == dobMonth && checkDay < dobDay)) {
        age--;
    }
    
    return age;
}

// Check if employee retires on this date
bool isRetiring(Employee emp, int checkDay, int checkMonth, int checkYear) {
    int currentAge = calculateAge(emp.day, emp.month, emp.year, checkDay, checkMonth, checkYear);
    
    // Check if reaching retirement age on their birthday
    if (currentAge == emp.retirementAge && checkDay == emp.day && checkMonth == emp.month) {
        return true;
    }
    
    return false;
}

// Parse date from dd/mm/yyyy format
bool parseDate(string dateStr, int &day, int &month, int &year) {
    stringstream ss(dateStr);
    char delimiter;
    
    ss >> day >> delimiter >> month >> delimiter >> year;
    
    // Validate date
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) {
        return false;
    }
    
    return true;
}

// Read employees from CSV file
vector<Employee> readEmployeesFromFile(string filename) {
    vector<Employee> employees;
    ifstream file(filename.c_str());
    
    if (!file.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        cout << "Make sure the file exists in the same folder as your program!" << endl;
        return employees;  // Return empty vector
    }
    
    string line;
    
    // Skip header line
    getline(file, line);
    
    // Read employee data
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        Employee emp;
        
        // Read EmpID
        getline(ss, temp, ',');
        emp.empID = atoi(temp.c_str());
        
        // Read Name
        getline(ss, emp.name, ',');
        
        // Read Day
        getline(ss, temp, ',');
        emp.day = atoi(temp.c_str());
        
        // Read Month
        getline(ss, temp, ',');
        emp.month = atoi(temp.c_str());
        
        // Read Year
        getline(ss, temp, ',');
        emp.year = atoi(temp.c_str());
        
        // Read Department
        getline(ss, emp.department, ',');
        
        // Read Retirement Age
        getline(ss, temp, ',');
        emp.retirementAge = atoi(temp.c_str());
        
        employees.push_back(emp);
    }
    
    file.close();
    cout << "Successfully loaded " << employees.size() << " employees!" << endl;
    return employees;
}

// Load sample data as backup
vector<Employee> loadSampleData() {
    vector<Employee> employees;
    
    employees.push_back({101, "Rajesh Kumar", 15, 11, 1965, "IT Department", 60});
    employees.push_back({102, "Priya Sharma", 22, 3, 1968, "HR Department", 58});
    employees.push_back({103, "Amit Patel", 15, 11, 1964, "Finance", 60});
    employees.push_back({104, "Sunita Desai", 10, 7, 1967, "Marketing", 58});
    employees.push_back({105, "Vijay Singh", 28, 9, 1966, "Operations", 59});
    employees.push_back({106, "Meena Reddy", 15, 11, 1963, "Admin", 60});
    employees.push_back({107, "Ravi Verma", 5, 1, 1969, "Sales", 58});
    employees.push_back({108, "Kavita Joshi", 18, 6, 1965, "IT Department", 60});
    employees.push_back({109, "Suresh Iyer", 12, 12, 1964, "Finance", 60});
    employees.push_back({110, "Anita Gupta", 25, 8, 1967, "HR Department", 58});
    employees.push_back({111, "Deepak Rao", 30, 10, 1965, "Operations", 60});
    employees.push_back({112, "Sneha Nair", 15, 11, 1966, "Marketing", 59});
    
    cout << "Using sample data (" << employees.size() << " employees)" << endl;
    return employees;
}

// Generate retirement report
void generateReport(vector<Employee> &employees, int checkDay, int checkMonth, int checkYear) {
    cout << "\n============================================================" << endl;
    cout << "              EMPLOYEE RETIREMENT REPORT" << endl;
    cout << "============================================================" << endl;
    cout << "Check Date: " << setfill(' ') << setw(2) << checkDay << "/" 
         << setw(2) << checkMonth << "/" << checkYear << endl;
    cout << "============================================================\n" << endl;
    
    vector<Employee> retiringEmployees;
    
    // Find all retiring employees
    for (int i = 0; i < employees.size(); i++) {
        if (isRetiring(employees[i], checkDay, checkMonth, checkYear)) {
            retiringEmployees.push_back(employees[i]);
        }
    }
    
    if (retiringEmployees.empty()) {
        cout << "\n  ** No employees are retiring on this date **" << endl;
    } else {
        cout << left;
        cout << setw(10) << "EmpID" 
             << setw(25) << "Name" 
             << setw(20) << "Department" 
             << setw(15) << "DOB"
             << setw(5) << "Age" << endl;
        cout << "------------------------------------------------------------" << endl;
        
        for (int i = 0; i < retiringEmployees.size(); i++) {
            Employee emp = retiringEmployees[i];
            int age = calculateAge(emp.day, emp.month, emp.year, 
                                  checkDay, checkMonth, checkYear);
            
            cout << setw(10) << emp.empID
                 << setw(25) << emp.name
                 << setw(20) << emp.department;
            
            cout << setfill('0') << setw(2) << emp.day << "/"
                 << setw(2) << emp.month << "/"
                 << setw(4) << setfill(' ') << emp.year << "    "
                 << setw(5) << age << endl;
        }
        
        cout << "------------------------------------------------------------" << endl;
        cout << "\nTotal Employees Retiring: " << retiringEmployees.size() << endl;
    }
    
    cout << "============================================================\n" << endl;
}

int main() {
    vector<Employee> employees;
    
    cout << "============================================================" << endl;
    cout << "        EMPLOYEE RETIREMENT REPORT SYSTEM" << endl;
    cout << "============================================================\n" << endl;
    
    // Try to read from file
    cout << "Reading employee data from 'employees.csv'..." << endl;
    employees = readEmployeesFromFile("employees.csv");
    
    // If file not found, use sample data
    if (employees.empty()) {
        cout << "\nFile not found. Using sample data instead...\n" << endl;
        employees = loadSampleData();
    }
    
    // Input date in dd/mm/yyyy format
    string dateInput;
    int checkDay, checkMonth, checkYear;
    
    cout << "\nEnter date to check for retirements (dd/mm/yyyy): ";
    cin >> dateInput;
    
    // Parse the date
    if (!parseDate(dateInput, checkDay, checkMonth, checkYear)) {
        cout << "\nError: Invalid date format! Please use dd/mm/yyyy" << endl;
        cout << "Example: 15/11/2025" << endl;
        return 1;
    }
    
    // Generate report
    generateReport(employees, checkDay, checkMonth, checkYear);
    
    return 0;
}