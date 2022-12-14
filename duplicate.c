// DUPLICATE FILE FINDER
// COURSE CODE: CSC 235
// NAME: OLUWADAMILARE IYANUOLUWA SAMUEL
// MATRIC NUMBER: 222505

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declaring all the variables that will be used in the program.
int file_check = 0;
int number_of_files;
int store = 0;
int lowest_value = 0;
char name_of_file[100][50];
int file_id[100];


// It compares the file names and if they are the same, it compares each file ID and if the file ID of
// the first file is greater than the file ID of the second file, it assigns the file ID of the second
// file to the lowest_value variable.

void duplicate_checker(void){
    for (int j = 0; j< number_of_files; j++) {
        for (int i = j + 1; i < number_of_files; i++) {
            file_check = strcmp(name_of_file[j], name_of_file[i]);
            // if file_check returns 0 then they are equal
            if(file_check == 0 &&  (file_id[j] > file_id[i])){
                lowest_value = file_id[i];
            }
            else if(file_check != 0 && (file_id[j] > file_id[i])){
                store = file_id[j];
                file_id[j] = file_id[i];
                file_id[i] = store;
            }
        }
    }
}


int main(){
    int trials;
    FILE * file = fopen("file.in.txt", "r");

    fscanf(file, "%d", &trials);

    // A for loop that is used to iterate through the number of trials.
    for (int i = 0; i< trials; i++) {

        // Reading the number of files from the file.
        fscanf(file, "%d",&number_of_files);
        int j = 0;
       
        // A while loop to go through the number of files.
        while (j<number_of_files) {
            fscanf(file,"%s %d", name_of_file[j], &file_id[j]);
            j++;
        }
        // Calling the duplicate_checker function.
        duplicate_checker();

        for (int j = 0; j< number_of_files; j++) {
            if (file_check != 0){
                printf("%d ", file_id[j]);
            }
        }
        printf("\n");
        // Checking if the files are the same
        if (file_check == 0){
            printf("%d\n", lowest_value);
        }
    }
    fclose(file);
}
