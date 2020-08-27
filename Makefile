all: passwordgenerator

passwordgenerator: passwordgenerator.c
        gcc passwordgenerator.c -o passwordgenerator
