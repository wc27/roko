import mysql.connector

# Step 1: Connect to MySQL

conn = mysql.connector.connect(
    host="localhost",
    user="nish",
    password="mypassword",
    database="student_db"
)

cursor = conn.cursor()

# Step 2: Define Menu Functions
def add_student():
    name = input("Enter student name: ")
    age = int(input("Enter student age: "))
    grade = input("Enter student grade: ")

    query = "INSERT INTO students (name, age, grade) VALUES (%s, %s, %s)"
    values = (name, age, grade)
    cursor.execute(query, values)
    conn.commit()
    print("Student added successfully!\n")

def view_students():
    cursor.execute("SELECT * FROM students")
    rows = cursor.fetchall()
    print("\n--- Student Records ---")
    for row in rows:
        print(row)
    print("-----------------------\n")

def delete_student():
    student_id = int(input("Enter student ID to delete: "))
    query = "DELETE FROM students WHERE id = %s"
    cursor.execute(query, (student_id,))
    conn.commit()
    print("Student deleted successfully!\n")

def edit_student():
    student_id = int(input("Enter student ID to edit: "))
    new_name = input("Enter new name: ")
    new_age = int(input("Enter new age: "))
    new_grade = input("Enter new grade: ")

    query = "UPDATE students SET name=%s, age=%s, grade=%s WHERE id=%s"
    values = (new_name, new_age, new_grade, student_id)
    cursor.execute(query, values)
    conn.commit()
    print("Student updated successfully!\n")

# Step 3: Menu Loop
while True:
    print("=== Student Database Menu ===")
    print("1. Add Student")
    print("2. View Students")
    print("3. Edit Student")
    print("4. Delete Student")
    print("5. Exit")
    
    choice = input("Enter your choice: ")

    if choice == '1':
        add_student()
    elif choice == '2':
        view_students()
    elif choice == '3':
        edit_student()
    elif choice == '4':
        delete_student()
    elif choice == '5':
        print("Exiting program... Goodbye!")
        break
    else:
        print("Invalid choice! Try again.\n")

# Step 4: Close connection
cursor.close()
conn.close()

______________________________________________

sudo mysql

CREATE DATABASE student_db;
CREATE USER 'nish'@'localhost' IDENTIFIED BY 'mypassword';
GRANT ALL PRIVILEGES ON student_db.* TO 'nish'@'localhost';
FLUSH PRIVILEGES;
USE student_db;

CREATE TABLE students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    age INT,
    grade VARCHAR(10)
);

SHOW TABLES;

exit; //take exist from mysql

_______________________________________

python3 --version


pip install mysql-connector-python

python3 database_connnectivity.py

______________________________________________

USE student_db;
SELECT * FROM students;


sudo apt update
sudo apt install python3 python3-pip -y




sudo journalctl --rotate && sudo journalctl --vacuum-time=1s && \
sudo truncate -s 0 /var/log/syslog /var/log/kern.log /var/log/dmesg 2>/dev/null && \
sudo rm -rf /run/udev/data/* ~/.cache/* ~/.local/share/recently-used.xbel 2>/dev/null && \
history -c && history -w