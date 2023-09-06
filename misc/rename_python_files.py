import os
import re

# Define the source directory containing subdirectories with Python files
source_directory = "path/to/this/repo"

# Define a regular expression pattern to extract the problem number and name
pattern = r"Problem: LeetCode (\d+) - (.+)\n"


# Function to rename Python files based on problem number and name
def rename_python_files(root, subdirs):
    for subdir in subdirs:
        sub_path = os.path.join(root, subdir)
        if os.path.isdir(sub_path):
            for filename in os.listdir(sub_path):
                file_path = os.path.join(sub_path, filename)
                if filename.endswith(".py"):
                    with open(file_path, "r") as file:
                        content = file.read()
                        match = re.search(pattern, content)
                        if match:
                            problem_number = match.group(1).zfill(4)
                            problem_name = (
                                match.group(2).strip().replace(" ", "-").lower()
                            )
                            new_filename = f"{problem_number}-{problem_name}.py"
                            new_path = os.path.join(sub_path, new_filename)
                            os.rename(file_path, new_path)
                            print(f"Renamed {filename} to {new_filename}")


# Recursively walk through the source directory and its subdirectories
for root, dirs, _ in os.walk(source_directory):
    rename_python_files(root, dirs)
