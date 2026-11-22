TaskCreate – Intelligent Task Management and Optimization System

Project Description

TaskCreate is a C++-based task management and scheduling system designed to help users organize their tasks, prioritize important activities, manage deadlines, and track progress efficiently. The system provides features for task creation, modification, deletion, categorization, and status tracking.
The project incorporates task prioritization, conflict detection, task replanning, deadline reminders, scheduling, and workload balancing to support better time management. It also includes user registration, login, and data storage to maintain user and task information. The project applies Data Structures and Algorithms (DSA) and Object-Oriented Programming (OOP) concepts through a modular design.

Problem Statement:

Managing academic and personal tasks can become difficult when users have multiple activities, different deadlines, and varying levels of priority. Poor task organization may lead to missed deadlines, scheduling conflicts, and an uneven workload.
TaskCreate aims to address these problems by providing a centralized system for managing tasks, identifying scheduling conflicts, prioritizing important activities, and reorganizing tasks when necessary.

Objectives

- To provide an organized system for creating, updating, deleting, and categorizing tasks.
- To prioritize tasks according to their importance and deadlines.
- To identify potential scheduling conflicts.
- To support task replanning when schedules change.
- To provide deadline reminders and task scheduling.
- To balance workload and improve time management.
- To maintain user accounts and task information.
- To apply OOP, DSA, and modular programming concepts in a practical C++ project.

Team Members:

- Aditi Jain – Team Lead; Prioritization, Conflict Detection, and Task Replanning
- Payal Kumari – Deadline Reminders, Scheduling, and Workload Balancing
- Anshika Badoni – Task Management and Categorization
- Yatharth Phogat– User Management and Data Storage

Technologies and Tools Used:

- Programming Language: C++
- Core Concepts: Data Structures and Algorithms (DSA), Object-Oriented Programming (OOP)
- Data Structures: Arrays and Priority Queues
- Libraries: Standard C++ libraries, including `iostream` and `string`
- Version Control: Git and GitHub
- Development Environment: Visual Studio Code
- Compiler: GCC/G++

Major Features and Modules:

 1. Task Management
- Add, update, and delete tasks.
- View and search task details.
- Categorize tasks according to their type.
- Track task status, such as Pending and Completed.

 2. Task Prioritization
- Organize tasks according to priority levels.
- Retrieve the highest-priority task.
- Use an array-based priority queue for priority-based processing.

 3. Conflict Detection
- Identify potential conflicts between tasks based on the scheduling information available.
- Find tasks that may require schedule adjustments.

 4. Task Replanning
- Rearrange affected tasks when deadlines or schedules change.
- Help maintain a more manageable task schedule.

 5. Deadline Reminders
- Set reminders for upcoming deadlines.
- Identify tasks whose reminders are due.

 6. Scheduling
- Generate and display an organized task schedule.
- Arrange tasks using relevant priority and deadline information.

 7. Workload Balancing
- Review the number and distribution of tasks.
- Identify periods with a high workload and support better task distribution.

 8. User Management and Data Storage
- Register new users and support login functionality.
- Manage user profile information.
- Save and load user and task records.

## Data Structures and OOP Concepts

The project demonstrates the practical application of the following concepts:

- Classes and Objects: Represent tasks and organize their associated operations.
- Encapsulation:Manage task information using data members and getter/setter functions.
- Arrays: Store and process task records.
- Priority Queue: Arrange tasks according to their priority.
- Searching and Sorting: Retrieve and organize task information.
- Modular Programming: Separate functionalities into header (`.h`) and source (`.cpp`) files.
- File Handling: Support persistent storage of task and user information, where implemented.

 Project Setup and Installation:

 Prerequisites:

- Git installed on your system.
- Visual Studio Code or another C++ IDE.
- A configured C++ compiler, such as GCC/G++.
 Steps to Run:

1. Clone the repository:

   ```bash
   git clone https://github.com/aditijainrke/TaskPilot.git
   ```

2. Open the project folder in Visual Studio Code:

   ```bash
   cd TaskPilot
   ```

3. Ensure that the required C++ compiler is installed and configured.

4. Compile the source files according to the project's directory structure. For example:

   ```bash
   g++ main.cpp src/*.cpp -I include -o taskcreate
   ```

5. Run the generated executable.

   
   ```bash
   .\taskcreate.exe
   ```


   Adjust the compilation command if some source files are stored elsewhere or if the project has a different entry point.

Current Project Status

The project is being developed in phases. The basic Task class and task prioritization module have been developed, while the remaining modules are being implemented and refined. The current development work focuses on completing task management, conflict detection, replanning, reminders, scheduling, workload balancing, user management, and data storage.

Module integration, testing, and validation are important parts of the remaining development process.

 Future Scope:

- Develop a web page or application, add ChatBox 
