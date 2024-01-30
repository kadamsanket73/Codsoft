#include <iostream>
#include <vector>

using namespace std;

class ToDoList
{
	private:
		vector<string> tasks;
		vector<bool> checked;
    public:
	    void addTask(const string& task)
		{
	        if (task.empty()) 
			{
	            cout << "Error: Task cannot be empty. Please enter a valid task.\n";
	        } 
			else
			{
	            tasks.push_back(task);
	            checked.push_back(false); // Initialize the checked status to false
	            cout << "Task added: " << task << endl;
	        }
	    }
	
	    void toggleTask(int index) 
		{
	        if (index >= 0 && index < tasks.size())
			{
	            checked[index] = (!checked[index]);
	            cout << "Task status toggled.\n";
	        } 
			else 
			{
	            cout << "Error: Invalid task index. Please enter a valid index.\n";
	        }
	    }
	
	    void deleteTask(int index)
		{
	        if (index >= 0 && index < tasks.size()) 
			{
	            tasks.erase(tasks.begin() + index);
	            checked.erase(checked.begin() + index);
	            cout << "Task deleted.\n";
	        } 
			else
			{
	            cout << "Error: Invalid task index. Please enter a valid index.\n";
	        }
	    }
	
	    void showTasks()
		{
	        if (tasks.empty())
			{
	            cout << "No tasks found. Your to-do list is empty.\n";
	        }
			else
		    {
	            cout << "Your To-Do List:\n";
	            for (size_t i = 0; i < tasks.size(); ++i) 
				{
	                cout << i + 1 << ". ";
	                if (checked[i])
					{
	                    cout << "[X] ";
	                }
					else
					{
	                    cout << "[ ] ";
	                }
	                cout << tasks[i] << endl;
	            }
	        }
	    }


};

int main() 
{
    ToDoList toDoList;

    char choice;
    do 
		{
        cout << "1. Add Task\n";
        cout << "2. Toggle Task Status\n";
        cout << "3. Delete Task\n";
        cout << "4. Show Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string task;
                cout << "Enter the task you want to add: ";
                cin.ignore();
                getline(cin, task);
                toDoList.addTask(task);
                break;
            }
            case '2': {
                int index;
                cout << "Enter the task index to toggle its status: ";
                cin >> index;
                toDoList.toggleTask(index - 1);
                break;
            }
            case '3': {
                int index;
                cout << "Enter the task index to delete: ";
                cin >> index;
                toDoList.deleteTask(index - 1);
                break;
            }
            case '4':
                toDoList.showTasks();
                break;
            case '5':
                cout << "Exiting the to-do list application. Goodbye!\n";
                break;
            default:
                cout << "Error: Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != '5');

    return 0;
}
