/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    
    int calculateImportance(vector<Employee*>& employees, int id) {
        int sum = 0;
        for (auto& employee: employees) {
            if (employee->id == id) {           
                sum += employee->importance;
                for (int i = 0; i < employee->subordinates.size(); i++) {
                    cout << employee->subordinates[i] << endl;
                    sum += calculateImportance(employees, employee->subordinates[i]);
                }
                break;
                
            }
        }
        return sum;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        return calculateImportance(employees, id);
    }
};