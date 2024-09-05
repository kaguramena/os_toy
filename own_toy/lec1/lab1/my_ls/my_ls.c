#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

int main(int argc,char** argv)
{ 
    DIR* dir;
    struct dirent* entry;
    char* path = argv[1] ? argv[1] : ".";
    dir = opendir(path);

    if(dir == NULL)
    {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name,".")==0||strcmp(entry->d_name,"..")==0)
        {
            continue;
        }
        switch (entry->d_type)
        {
        case 4:
            printf("%s/    ",entry->d_name);
            break;
        case 8:
            printf("%s    ",entry->d_name);
        default:
            break;
        }
        
        
    }
    closedir(dir);
    return EXIT_SUCCESS;
}