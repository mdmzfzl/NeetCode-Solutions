#!/bin/bash

# Loop through each topic folder in the C++ directory
for cpp_folder in "./C++/"*/; do
    # Get the topic folder name without the path and remove trailing slash
    topic_folder_name=$(basename "${cpp_folder%/}")

    # Create a new directory with the same name as the topic folder
    mkdir -p "$topic_folder_name"

    # Loop through each .cpp file in the topic folder
    for cpp_file in "$cpp_folder"*.cpp; do
        # Get the file name without the path and extension
        file_name=$(basename "${cpp_file%.*}")

        # Create a directory with the same name as the file (without the extension)
        mkdir -p "$topic_folder_name/$file_name"

        # Copy the .cpp file to the new directory
        cp "$cpp_file" "$topic_folder_name/$file_name"
    done

    # Loop through each .py file in the topic folder
    for py_file in "$cpp_folder"*.py; do
        # Get the file name without the path and extension
        file_name=$(basename "${py_file%.*}")

        # Copy the .py file to the existing or newly created directory
        cp "$py_file" "$topic_folder_name/$file_name"
    done
done

# Loop through each topic folder in the Python directory
for python_folder in "./Python/"*/; do
    # Get the topic folder name without the path and remove trailing slash
    topic_folder_name=$(basename "${python_folder%/}")

    # Create a new directory with the same name as the topic folder
    mkdir -p "$topic_folder_name"

    # Loop through each .py file in the topic folder
    for py_file in "$python_folder"*.py; do
        # Get the file name without the path and extension
        file_name=$(basename "${py_file%.*}")

        # Create a directory with the same name as the file (without the extension)
        mkdir -p "$topic_folder_name/$file_name"

        # Copy the .py file to the new directory
        cp "$py_file" "$topic_folder_name/$file_name"
    done

    # Loop through each .cpp file in the topic folder
    for cpp_file in "$python_folder"*.cpp; do
        # Get the file name without the path and extension
        file_name=$(basename "${cpp_file%.*}")

        # Copy the .cpp file to the existing or newly created directory
        cp "$cpp_file" "$topic_folder_name/$file_name"
    done
done
