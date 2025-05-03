//
// Created by Bodo Schönfeld on 04.03.25.
//

#ifndef CREATEFILES_H
#define CREATEFILES_H

void create_mypy_file(unsigned char *input, const char *fileName);
void create_and_write_readme(const char *fileName, const char *projectDirName);
void create_and_write_pyproject(const char *fileName);
void create_and_write_setup(const char *fileName);

int create_init_file(const char *projectDirName, const char *subDirName);
int create_main_file(const char *projectDirName, const char *subDirName);

#endif //CREATEFILES_H
