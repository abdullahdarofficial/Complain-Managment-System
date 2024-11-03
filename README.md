# Complain Managment System

The **Complaint Management System (CMS)** project is a structured C++ application designed to streamline complaint handling in an organization. It provides an organized way for administrators, managers, employees, and other stakeholders to manage complaints from initiation to resolution, offering insights and workflow tracking. 

### Project Structure
The system's structure is well-organized with multiple files and classes, each handling specific roles and functionalities. Key files include:
- **Administer, Assigned, Closed, New, and Resolved Modules**: These modules track various stages of a complaint. Complaints start as new, and move through states like "assigned" (when an employee is tasked with resolving it) and "closed" (when the complaint has been addressed). 
- **Complaint Class**: This core component defines the attributes and methods for managing complaints, including capturing the details of each complaint, tracking its status, and storing necessary information.
- **Employee, Manager, Director, and Teacher Classes**: Each class represents different stakeholders in the system, enabling role-specific functionalities. For example, managers and administrators have higher-level controls, such as assigning complaints to employees or marking them as resolved.
- **Department Class**: This class defines various departments, allowing complaints to be routed based on department-specific expertise or jurisdiction. Each department handles a subset of complaints related to its field, making the system scalable for larger organizations.
- **State Class**: It manages the current state of a complaint, making it easier to update, track, and display the complaint's progress at any given time.

### Key Functionalities
1. **Complaint Lifecycle Management**: The system covers the entire lifecycle of a complaint, from logging a new complaint to assigning it, handling responses, and finally closing it. Each phase is represented by different states managed by specific classes like `New`, `Assigned`, and `Closed`.
   
2. **Role-Based Access and Responsibilities**: The CMS is designed with multiple stakeholders in mind. Administrators oversee the entire system, managers monitor complaints within their purview, and employees are assigned specific complaints to address. Teachers and directors can also be assigned based on the complaint’s nature.
   
3. **Data Management**: Data files such as `administers.txt`, `complaints.txt`, `employees.txt`, `managers.txt`, and `teachers.txt` store essential information. These files help track user information, complaint details, and employee records, allowing for consistent and centralized data access.

4. **Assignment and Tracking**: Through the `AssignedJob` class, administrators and managers can allocate specific complaints to employees, promoting accountability and effective follow-ups. Employees update the complaint status, with all changes logged and visible for managerial review.

5. **Scalability**: The system supports multiple departments, employees, and managers. It can easily scale as more departments or roles are added to the organization, allowing complaints to be managed across a wide range of issues or concerns.

### Summary
The Complaint Management System (CMS) is a comprehensive application designed for structured complaint handling within an organization. With its modular C++ implementation, role-based access control, and lifecycle management features, it provides an efficient and scalable way to address and resolve complaints systematically. The use of multiple classes for different roles, combined with state-tracking and data file storage, makes it a robust solution for any institution looking to enhance accountability, streamline complaint handling, and improve transparency in the resolution process.
