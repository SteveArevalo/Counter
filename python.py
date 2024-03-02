import subprocess

# Function to create a file and write the items and the quantities purchased to frequency.dat
def create_file(file_name):
    input_file = open(file_name, "w")
    for item in grocery_items:
        input_file.write("\n" + item + " " + str(grocery_items[item]))
    input_file.close()

# Function to open and read the input file
grocery_items = {}
input_file = open("CS210_Project_Three_Input_File.txt", "r")
for line in input_file:
    line = line.strip()
    words = line.split(" ")
    for word in words:
        if word in grocery_items:
            grocery_items[word] = grocery_items[word] + 1
        else:
            grocery_items[word] = 1
input_file.close()

# Call the C++ program with appropriate arguments
subprocess.run(["./frequency_counter", "print_all"], check=True)

# Create a file for backup purposes
create_file("frequency.dat")
