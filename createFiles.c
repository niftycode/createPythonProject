//
// Created by Bodo Schönfeld on 04.03.25.
//
#include "createFiles.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_mypy_file(unsigned char *input, const char *fileName) {

    if (input[0] == '\n') {
        input[0] = 'y';
    } else {
        input[0] = tolower(input[0]);
    }

    if (input[0] == 'y') {
        FILE *file = fopen(fileName, "w");
        if (file == NULL) {
            perror("Error creating file \'mypy.ini\' file!");
            exit(1);
        }

        fprintf(file, "[mypy]\n");
        fprintf(file, "disable_error_code = import-untyped\n");
        fprintf(file, "ignore_missing_imports = True\n");
        fclose(file);

        printf("File created successfully: %s\n", fileName);
    } else if (input[0] == 'n') {
        printf("Didn't create mypy.ini file.\n");
    } else {
        printf("");
        printf("Didn't create mypy.ini file because of invalid user input!\n");
    }
}

void create_and_write_readme(const char *fileName, const char *projectDirName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error creating file \'README.md\'!");
        exit(1);
    }

    fprintf(file, "# %s", projectDirName);
    fclose(file);

    printf("File created successfully: %s\n", fileName);
}

void create_and_write_pyproject(const char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error creating file \'pyproject.toml\'!");
        exit(1);
    }

    fprintf(file, "[build-system]\n");
    fprintf(file, "requires = [\"setuptools>=70.0\"]\n");
    fprintf(file, "build-backend = \"setuptools.build_meta\"\n");
    fclose(file);

    printf("File created successfully: %s\n", fileName);
}

void create_and_write_setup(const char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error creating file \'setup.cfg\'!");
        exit(1);
    }

    fprintf(file, "[metadata]\n");
    fprintf(file, "name = \n");
    fprintf(file, "version = \n");
    fprintf(file, "author = \n");
    fprintf(file, "author_email = \n");
    fprintf(file, "url = \n");
    fprintf(file, "description = \n");
    fprintf(file, "long_description = file: README.md\n");
    fprintf(file, "long_description_content_type = text/markdown\n");
    fprintf(file, "license = MIT\n");
    fprintf(file, "license_file = LICENSE\n");
    fprintf(file, "requires_python = >= 3.13\n");
    fprintf(file, "classifiers = \n");
    fprintf(file, "    License :: OSI Approved :: MIT License\n");
    fprintf(file, "    Operating System :: OS Independent\n");
    fprintf(file, "    Programming Language :: Python :: 3\n");
    fprintf(file, "    Programming Language :: Python :: 3.12\n");
    fprintf(file, "    Programming Language :: Python :: 3.13\n");
    fprintf(file, "    Programming Language :: Python :: Implementation :: CPython");

    fclose(file);

    printf("File created successfully: %s\n", fileName);
}

int create_init_file(const char *projectDirName, const char *subDirName) {
    char pathToInitFile[512];
    char pathToPytestFile[512];
    const char testsDir[] = "tests";

    snprintf(pathToInitFile, sizeof(pathToInitFile), "%s/%s/__init__.py", projectDirName, subDirName);
    snprintf(pathToPytestFile, sizeof(pathToPytestFile), "%s/%s/pytest.ini", projectDirName, subDirName);

    FILE *file = fopen(pathToInitFile, "w");
    if (file == NULL) {
        perror("Error creating __init__.py file.");
        return EXIT_FAILURE;
    }

    fclose(file);
    printf("File created successfully: %s\n", pathToInitFile);

    if (strcmp(subDirName, testsDir) == 0) {
        FILE *pytestFile = fopen(pathToPytestFile, "w");
        if (pytestFile == NULL) {
            perror("Error creating pytest.ini file.");
            return EXIT_FAILURE;
        }

        fprintf(pytestFile, "[pytest]\n");
        fprintf(pytestFile, "norecursedirs = .* src *.egg dist build\n");
        fprintf(pytestFile, "addopts = -rsxX -l --tb=short --strict-markers\n");
        fclose(pytestFile);

        printf("File created successfully: %s\n", pathToPytestFile);
    }
    return EXIT_SUCCESS;
}

int create_main_file(const char *projectDirName, const char *subDirName) {
    char path[512];
    snprintf(path, sizeof(path), "%s/%s/main.py", projectDirName, subDirName);

    FILE *file = fopen(path, "w");
    if (file == NULL) {
        perror("Error creating main.py file.");
        return EXIT_FAILURE;
    }

    fprintf(file, "#!/usr/bin/env python3\n");
    fprintf(file, "\n");
    fprintf(file, "\"\"\"\n");
    fprintf(file, "Description goes here...\n");
    fprintf(file, "Version: 1.0\n");
    fprintf(file, "Python 3.12+\n");
    fprintf(file, "Date created: \n");
    fprintf(file, "Date modified: -\n");
    fprintf(file, "\"\"\"\n");
    fprintf(file, "\n");
    fprintf(file, "import logging\n");
    fprintf(file, "\n");
    fprintf(file, "logging.basicConfig(level=logging.DEBUG)\n");
    fprintf(file, "logger = logging.getLogger()\n");
    fprintf(file, "\n");
    fprintf(file, "def main() -> None:\n");
    fprintf(file, "    pass\n");
    fprintf(file, "\n");
    fprintf(file, "if __name__ == '__main__':\n");
    fprintf(file, "    main()\n");
    fclose(file);

    printf("File created successfully: %s\n", path);

    return EXIT_SUCCESS;
}
