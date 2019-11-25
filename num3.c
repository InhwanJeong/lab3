#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h> 

DIR *pdir;
struct dirent *pde;
char *argg;

void getargs(char *cmd){
    int narg = 0;

    while (*cmd){
        if(*cmd == ' ' || *cmd == '\t')
            *cmd++ = '\0';
        else{
            argg[narg++] = cmd++;
            while(*cmd != '\0' && *cmd != ' ' && *cmd != '\t') cmd ++;
        }
    }

    argg[narg] = NULL;
}

void recursion_dir(char *arg){
    if ((pdir = opendir(arg)) < 0 ) {}
    else if(strcmp("..", arg) == 0){}
    else if(strcmp(".", arg) == 0){}
    else{
        printf("%s:\n", arg);
        while ((pde = readdir(pdir)) != NULL){
            if(strcmp("..", arg) == 0){}
            else if(strcmp(".", arg) == 0){}
            else printf("%3s ", pde->d_name);
        }
        printf("\n\n");
    }
//    argg = strtok(pde->d_name, " ");
//    while (argg != NULL){
//       recursion_dir(argg);
//       argg = strtok(NULL, " ");
//    }
}

int main(int argc, char *argv[]){
    if (argc < 2) {
        fprintf(stderr, "Usage: file_dir dirname\n");
        exit(1);
    }

    // object dir    
    if ((pdir = opendir(argv[1])) < 0 ) {}

    printf("%s:\n", argv[1]);
    while ((pde = readdir(pdir)) != NULL){
        printf("%3s ", pde->d_name);
    }
    printf("\n\n");

    // subject dir
    recursion_dir(argv[1]);

    closedir(pdir);
    return 0;
}
