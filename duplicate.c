# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// function to find least in array
int least(int arr[], int n)
{
    int i, min = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}



int main()
{
    int num;
    char file[100], id[100];
    int counter = 0;
    int trials = 0;
    FILE * fpointer = fopen("file.in.txt", "r");
    FILE * buffer = fopen ("standard_output.txt", "w");
    /* Reading the first two lines of the file. */
    fscanf(fpointer, "%d", &num);
    fscanf(fpointer, "%d", &num);
    char num_files[3][50];
    char total_id[3][50];

    while (trials != 2)
    {
        while (num != counter)
        {    
        /* Reading the file and storing the values in the array. */
        fscanf(fpointer, "%s", file);    
        strcpy(num_files[counter], file);

        fscanf(fpointer, "%s", id);
        strcpy(total_id[counter], id);
        
        counter++;
        }
        counter = 0;

        int total_id_int[3];
        /* This is converting the string values in the array to integers. */
        for (int i = 0; i < 3; i++)
        {
            total_id_int[i] = atoi(total_id[i]);
        }
        int len_id = sizeof(total_id_int)/sizeof(total_id_int[0]);
        int len_file = sizeof(num_files)/sizeof(num_files[0]);
        int valid = 0;
        
        //sort the total_id_int array
        for (int i = 0; i < len_id -1; i++)
        {
            for (int j = i + 1; j < len_id - 1; j++)
            {
                if (total_id_int[i] > total_id_int[j])
                {
                    int temp = total_id_int[i];
                    total_id_int[i] = total_id_int[j];
                    total_id_int[j] = temp;
                }
            }
        }

        // compare all values in num_files    
        for (int i = 0; i < len_file - 1; i++)
        {
            for (int j = i + 1; j < len_file - 1; j++)
            {
                if (strcmp(num_files[i], num_files[j]) == 0)
                {
                    printf("\n"); 
                }
                else
                { 
                    for (int i = 0; i < len_id - 1; i++)
                    {
                        printf("%d ", total_id_int[i]);
                       /* Writing the values in the array to the file. */
                        fprintf(buffer, "%d ", total_id_int[i]);
                        
                        valid = 1;
                    }

                }
            }
        }
        
        //if all the values are the same, then print the least id   
         
        if (least(total_id_int, len_id - 1 ) == total_id_int[0])
        {
            if (valid == 1)
            {
                valid = 0;   
            }
            else
            {
                printf("%d\n", least(total_id_int, len_id ));
                fprintf(buffer, "\n");
                fprintf(buffer, "%d\n", least(total_id_int, len_id ));
            }
            
        }
    trials++;
    fscanf(fpointer, "%d", &num);
    }
    fclose(fpointer);
    fclose(buffer);
    return 0;
}



    
