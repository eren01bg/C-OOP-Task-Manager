#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Task {
	
	public:
		int getPriority() { return priority; }
		string getName() { return name; }
		string getDueDate() { return due_date; }
		bool getIsCompleted() { return is_completed; }

		void setIsCompleted() {
			is_completed = true;
		}

		Task(string task_name, string date, int task_priority)
			: name(std::move(task_name)), due_date(std::move(date)), priority(task_priority) { };

	private:
		string name;
		string due_date;
		int priority;
		bool is_completed = false;

};

class TaskList {

	public:

		void add_task() {
			
			string name = "", due_date = "";
			int priority = 0;

			while (name.empty()) {

				cout << "Enter a name for your task: ";
				getline(cin, name);
			
			}

			while (due_date.empty()) {

				cout << "Enter a due date for your task (DD-MM-YYYY): ";
				cin >> due_date;
			
			}

			while (priority > 5 || priority < 1) {

				cout << "Enter a priority for your task | 1 (lowest) - 5 (highest) |: ";
				cin >> priority;

			}
			
			cin.ignore();
			tasks.emplace_back(name, due_date, priority);

		}
		
		void delete_task() {

			view_tasks();
			
			int task_index = 0;

			while (task_index <= 0 || task_index > static_cast<int>(tasks.size())) {
				cout << "Which task do you want to delete?: ";
				cin >> task_index;
			}

			tasks.erase(tasks.begin() + task_index - 1);
			view_tasks();
			

		}

		void search_task() {

		}

		void mark_task_as_completed() {

			view_tasks();
			
			int task_index = 0;

			while (task_index <= 0 || task_index > static_cast<int>(tasks.size())) {
				cout << "Which task do you want to mark as completed? ";
				cin >> task_index;
			}

			tasks[task_index - 1].setIsCompleted();

			view_tasks();

		}

		void view_tasks() {

			if (tasks.empty()) {
				cout << "Can't show you anything if you don't add some tasks...";
			}
			else {
				for (size_t i = 0; i < tasks.size(); i++) {
					cout << "[" << (tasks[i].getIsCompleted() ? "C" : " ") << "] " << i + 1 << ". " << tasks[i].getName() << " Due: " << tasks[i].getDueDate() << " Priority: " << tasks[i].getPriority() << "\n";
				}
			}


		}


	private:
		vector<Task> tasks;


		

};

int main() {

	TaskList taskList;

	taskList.add_task();
	taskList.view_tasks();
	taskList.mark_task_as_completed();
	taskList.delete_task();

	return 0;
}