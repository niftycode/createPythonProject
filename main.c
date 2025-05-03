#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include "createFiles.h"
#include "createFolders.h"

void create_virtualenv(unsigned char *input, const char *directory) {
    // Change to the specified directory
    if (chdir(directory) != 0) {
        perror("Error changing directory!");
        return;
    }

    if (input[0] == '\n') {
        input[0] = 'y';
    } else {
        input[0] = tolower(input[0]);
    }

    if (input[0] == 'y') {
        // Run the Python command to create a virtual environment
        const int result = system("python3 -m venv .venv");

        if (result == 0) {
            printf("Virtual environment successfully created in %s/.venv\n", directory);
        } else {
            fprintf(stderr, "Error creating virtual environment!\n");
        }
    }
}

int main() {
    // user input: project name
    char projectDirName[56];
    printf("Enter the project name: ");
    scanf("%55s", projectDirName);

    // user input: mypy.ini file
    unsigned char inputMypy[2];
    printf("Do you need a mypy.ini file? (y/n): ");
    scanf("%1s", inputMypy);

    // user input: virtual environment
    unsigned char inputVenv[2];
    printf("Do you need a virtual environment? (y/n): ");
    scanf("%1s", inputVenv);

    char pyprojectFile[512];
    // With snprintf, strings can be put together.
    // For this purpose, a buffer with the name pyprojectFile is created here.
    snprintf(pyprojectFile, sizeof(pyprojectFile), "%s/pyproject.toml", projectDirName);

    // Create the project directory
    if (mkdir(projectDirName, 0755) == -1) {
        if (errno != EEXIST) {
            perror("Error creating project directory!");
            return 1;
        }
    }

    create_and_write_pyproject(pyprojectFile);

    char setupFile[512];
    snprintf(setupFile, sizeof(setupFile), "%s/setup.cfg", projectDirName);
    create_and_write_setup(setupFile);

    char readmeFile[512];
    snprintf(readmeFile, sizeof(readmeFile), "%s/README.md", projectDirName);
    create_and_write_readme(readmeFile, projectDirName);

    const char docsDirName[5] = "docs";
    create_dir(projectDirName, docsDirName);

    const char testsDirName[6] = "tests";
    create_dir(projectDirName, testsDirName);

    const char srcDirName[4] = "src";
    create_dir(projectDirName, srcDirName);

    create_init_file(projectDirName, srcDirName);
    create_init_file(projectDirName, testsDirName);
    create_main_file(projectDirName, srcDirName);

    char mypyFile[512];
    snprintf(mypyFile, sizeof(mypyFile), "%s/mypy.ini", projectDirName);
    create_mypy_file(inputMypy, mypyFile);

    create_virtualenv(inputVenv, projectDirName);

    return EXIT_SUCCESS;
}
