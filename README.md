# createPythonProject

With this program written in C it is possible to create a new Python project.

Compile the code for your system and then copy the executable file to a directory that's part of your PATH environment variable. Now you can run the program:

```Shell
createPythonProject
```

After starting the program, the following options are requested:

* project name
* mypy.ini file
* virtual environment

The program then creates a new directory named after the project. This project has the following folder structure:

```Shell
.
├── docs
├── mypy.ini
├── pyproject.toml
├── README.md
├── setup.cfg
├── src
│   ├── __init__.py
│   └── main.py
└── tests
    ├── __init__.py
    └── pytest.ini
```

By executing `cd <project name>` and `code .`, this project directory can be opened in Visual Studio Code. You can now customize the files to your needs.

