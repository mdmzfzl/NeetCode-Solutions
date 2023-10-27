import os

directory = "../"
output_file = "output.txt"

with open(output_file, "w") as f:
    for root, dirs, files in os.walk(directory):
        for file in files:
            relative_path = os.path.relpath(os.path.join(root, file), directory)
            relative_path = "./" + relative_path
            f.write(relative_path + "\n")
