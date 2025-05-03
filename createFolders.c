//
// Created by Bodo Schönfeld on 05.03.25.
//

#include "createFolders.h"

#include <stdio.h>
#include <errno.h>
#include <_stdlib.h>
#include <sys/stat.h>

int create_dir(const char *dirName, const char *subDirName) {

    char path[512];

    snprintf(path, sizeof(path), "%s/%s", dirName, subDirName);

    // Create a directory
    if (mkdir(path, 0755) == -1) {
        if (errno != EEXIST) {
            perror("Error creating directory!");
            return EXIT_FAILURE;
        }
    }
    printf("Created directory %s\n", path);

    return EXIT_SUCCESS;
}
