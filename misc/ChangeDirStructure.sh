#!/bin/bash

for cpp_folder in "./C++/"*/; do
    topic_folder_name=$(basename "${cpp_folder%/}")
    mkdir -p "$topic_folder_name"
    for cpp_file in "$cpp_folder"*.cpp; do
        file_name=$(basename "${cpp_file%.*}")
        mkdir -p "$topic_folder_name/$file_name"
        cp "$cpp_file" "$topic_folder_name/$file_name"
    done
    for py_file in "$cpp_folder"*.py; do
        file_name=$(basename "${py_file%.*}")
        cp "$py_file" "$topic_folder_name/$file_name"
    done
done

for python_folder in "./Python/"*/; do
    topic_folder_name=$(basename "${python_folder%/}")
    mkdir -p "$topic_folder_name"
    for py_file in "$python_folder"*.py; do
        file_name=$(basename "${py_file%.*}")
        mkdir -p "$topic_folder_name/$file_name"
        cp "$py_file" "$topic_folder_name/$file_name"
    done
    for cpp_file in "$python_folder"*.cpp; do
        file_name=$(basename "${cpp_file%.*}")
        cp "$cpp_file" "$topic_folder_name/$file_name"
    done
done
