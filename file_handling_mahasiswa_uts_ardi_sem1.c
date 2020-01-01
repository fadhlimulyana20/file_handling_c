#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int append(){
    FILE *filepointer;

    char NIM[10], nama[50], gender[2], alamat[100];

    printf("Nama\t: ");
    gets(nama);

    printf("NIM\t: ");
    gets(NIM);

    printf("Gender(L/P)\t: ");
    gets(gender);

    printf("Alamat\t:");
    gets(alamat);
    //fgets(alamat, 50, stdin);
    
    filepointer = fopen("data_mhs.csv", "a");

    if (filepointer == NULL)
    {
        printf("Failed to open file");
    }else
    {
        //fputs("Nama : ", filepointer);
        fputs(nama, filepointer);
        fputs(";", filepointer);

        //fputs("NIM : ", filepointer);
        fputs(NIM, filepointer);
        fputs(";", filepointer);

        //fputs("Gender : ", filepointer);
        fputs(gender, filepointer);
        fputs(";", filepointer);

        //fputs("Alamat : ", filepointer);
        fputs(alamat, filepointer);
        fputs("\n", filepointer);

        //fputs("---------------------------------------------------------------\n", filepointer);

        fclose(filepointer);
    } 
}

int show_data(){
    FILE *filepointer;

    char dataToBeRead[1024];
    int row_count = 0;
    int field_count = 0;

    filepointer = fopen("data_mhs.csv", "r");

    if (filepointer == NULL)
    {
        printf("Failed to open data_mhs.txt");
    }else
    {
        while (fgets(dataToBeRead, 1024, filepointer))
        {
            field_count = 0;
            row_count++;
            //printf("%s", dataToBeRead);

            char *field = strtok(dataToBeRead, ";");
            while (field)
            {
                if (field_count == 0)
                {
                    printf("Nama\t:");
                }

                if (field_count == 1)
                {
                    printf("NIM\t:");
                }

                if (field_count == 2)
                {
                    printf("Gender\t:");
                }

                if (field_count == 3)
                {
                    printf("Alamat\t:");
                }

                printf("%s\n", field);
                field = strtok(NULL, ";");

                field_count++;  
            }
            printf("\n");  
        }
        
        fclose(filepointer);
    }    
}

int show_even_nim_data(){
    FILE *filepointer;

    char dataToBeRead[1024];
    int row_count = 0;
    int field_count = 0;

    filepointer = fopen("data_mhs.csv", "r");

    if (filepointer == NULL)
    {
        printf("Failed to open data_mhs.txt");
    }else
    {
        while (fgets(dataToBeRead, 1024, filepointer))
        {
            field_count = 0;
            row_count++;
            //printf("%s", dataToBeRead);

            char *field = strtok(dataToBeRead, ";");
            while (field != NULL)
            {
                char nama_buff[1024], NIM_buff[1024], NIM_buff_temp[1024], gender_buff[1024], alamat_buff[1024];
                int check_nim;

                if (field_count == 0)
                {
                    strcpy(nama_buff, field);
                }

                if (field_count == 1)
                {
                    strcpy(NIM_buff, field);
                    strcpy(NIM_buff_temp, field);
                    //printf("Debug %s\n", NIM_buff_temp);
                    for (int i = 0; i < NIM_buff_temp[i] != '\0'; i++)
                    {
                        while (((NIM_buff_temp[i] >= 'a' && NIM_buff_temp[i] <= 'z') || (NIM_buff_temp[i] >= 'A' && NIM_buff_temp[i] <= 'Z') || NIM_buff_temp[i] == '\0')) {
                            for (int j = i; NIM_buff_temp[j] != '\0'; ++j) {
                                NIM_buff_temp[j] = NIM_buff_temp[j + 1];
                            }
                            //NIM_buff_temp[j] = '\0';
                        }
                        
                    }
                    
                    check_nim = atoi(NIM_buff_temp);
                    //printf("Debug %d\n", check_nim);
                }

                if (field_count == 2)
                {
                    strcpy(gender_buff, field);
                }

                if (field_count == 3)
                {
                    
                    strcpy(alamat_buff, field);
                }

                field = strtok(NULL, ";");
                //printf("Debug %s\n", field);

                field_count++;
                if (field_count == 4)
                {
                    if (check_nim%2 != 0)
                    {
                        continue;
                    }

                    printf("Nama\t: ");
                    printf("%s\n", &nama_buff);

                    printf("NIM\t: ");
                    printf("%s\n", &NIM_buff);

                    printf("Gender\t: ");
                    printf("%s\n", &gender_buff);

                    printf("Alamat\t: ");
                    printf("%s", &alamat_buff);
                }       
            }
            printf("\n");  
        }
        
        fclose(filepointer);
    }   
}

int show_odd_nim_data(){
    FILE *filepointer;

    char dataToBeRead[1024];
    int row_count = 0;
    int field_count = 0;

    filepointer = fopen("data_mhs.csv", "r");

    if (filepointer == NULL)
    {
        printf("Failed to open data_mhs.txt");
    }else
    {
        while (fgets(dataToBeRead, 1024, filepointer))
        {
            field_count = 0;
            row_count++;
            //printf("%s", dataToBeRead);

            char *field = strtok(dataToBeRead, ";");
            while (field != NULL)
            {
                char nama_buff[1024], NIM_buff[1024], NIM_buff_temp[1024], gender_buff[1024], alamat_buff[1024];
                int check_nim;

                if (field_count == 0)
                {
                    strcpy(nama_buff, field);
                }

                if (field_count == 1)
                {
                    strcpy(NIM_buff, field);
                    strcpy(NIM_buff_temp, field);
                    //printf("Debug %s\n", NIM_buff_temp);
                    for (int i = 0; i < NIM_buff_temp[i] != '\0'; i++)
                    {
                        while (((NIM_buff_temp[i] >= 'a' && NIM_buff_temp[i] <= 'z') || (NIM_buff_temp[i] >= 'A' && NIM_buff_temp[i] <= 'Z') || NIM_buff_temp[i] == '\0')) {
                            for (int j = i; NIM_buff_temp[j] != '\0'; ++j) {
                                NIM_buff_temp[j] = NIM_buff_temp[j + 1];
                            }
                            //NIM_buff_temp[j] = '\0';
                        }
                        
                    }
                    
                    check_nim = atoi(NIM_buff_temp);
                   // printf("Debug %d\n", check_nim);
                }

                if (field_count == 2)
                {
                    strcpy(gender_buff, field);
                }

                if (field_count == 3)
                {
                    
                    strcpy(alamat_buff, field);
                }

                field = strtok(NULL, ";");
                //printf("Debug %s\n", field);

                field_count++;
                if (field_count == 4)
                {
                    if (check_nim%2 == 0)
                    {
                        continue;
                    }

                    printf("Nama\t: ");
                    printf("%s\n", &nama_buff);

                    printf("NIM\t: ");
                    printf("%s\n", &NIM_buff);

                    printf("Gender\t: ");
                    printf("%s\n", &gender_buff);

                    printf("Alamat\t: ");
                    printf("%s", &alamat_buff);
                }       
            }
            printf("\n");  
        }
        
        fclose(filepointer);
    }   
}

int show_male_data(){
    FILE *filepointer;

    char dataToBeRead[1024];
    int row_count = 0;
    int field_count = 0;

    filepointer = fopen("data_mhs.csv", "r");

    if (filepointer == NULL)
    {
        printf("Failed to open data_mhs.txt");
    }else
    {
        while (fgets(dataToBeRead, 1024, filepointer))
        {
            field_count = 0;
            row_count++;
            //printf("%s", dataToBeRead);

            char *field = strtok(dataToBeRead, ";");
            while (field != NULL)
            {
                char nama_buff[1024], NIM_buff[1024], gender_buff[1024], alamat_buff[1024];

                if (field_count == 0)
                {
                    strcpy(nama_buff, field);
                }

                if (field_count == 1)
                {
                    strcpy(NIM_buff, field);
                    
                }

                if (field_count == 2)
                {
                    strcpy(gender_buff, field);
                }

                if (field_count == 3)
                {
                    
                    strcpy(alamat_buff, field);
                }

                field = strtok(NULL, ";");
                //printf("Debug %s\n", field);

                field_count++;
                if (field_count == 4)
                {
                    char gender_buff_temp = gender_buff[0];
                    if (gender_buff_temp == 'P')
                    {
                        continue;
                    }
                                        

                    printf("Nama\t: ");
                    printf("%s\n", &nama_buff);

                    printf("NIM\t: ");
                    printf("%s\n", &NIM_buff);

                    printf("Gender\t: ");
                    printf("%s\n", &gender_buff);

                    printf("Alamat\t: ");
                    printf("%s", &alamat_buff);
                }       
            }
            printf("\n");  
        }
        
        fclose(filepointer);
    }   
}

int show_female_data(){
    FILE *filepointer;

    char dataToBeRead[1024];
    int row_count = 0;
    int field_count = 0;

    filepointer = fopen("data_mhs.csv", "r");

    if (filepointer == NULL)
    {
        printf("Failed to open data_mhs.txt");
    }else
    {
        while (fgets(dataToBeRead, 1024, filepointer))
        {
            field_count = 0;
            row_count++;
            //printf("%s", dataToBeRead);

            char *field = strtok(dataToBeRead, ";");
            while (field != NULL)
            {
                char nama_buff[1024], NIM_buff[1024], gender_buff[1024], alamat_buff[1024];

                if (field_count == 0)
                {
                    strcpy(nama_buff, field);
                }

                if (field_count == 1)
                {
                    strcpy(NIM_buff, field);
                    
                }

                if (field_count == 2)
                {
                    strcpy(gender_buff, field);
                }

                if (field_count == 3)
                {
                    
                    strcpy(alamat_buff, field);
                }

                field = strtok(NULL, ";");
                //printf("Debug %s\n", field);

                field_count++;
                if (field_count == 4)
                {
                    char gender_buff_temp = gender_buff[0];
                    if (gender_buff_temp == 'L')
                    {
                        continue;
                    }
                                        

                    printf("Nama\t: ");
                    printf("%s\n", &nama_buff);

                    printf("NIM\t: ");
                    printf("%s\n", &NIM_buff);

                    printf("Gender\t: ");
                    printf("%s\n", &gender_buff);

                    printf("Alamat\t: ");
                    printf("%s", &alamat_buff);
                }       
            }
            printf("\n");  
        }
        
        fclose(filepointer);
    }   
}

int main(){
    bool condition = true;
    char yesno[2];
    int opt;

    //menu
    while(opt != 7){
        printf("Menu\n");
        printf("1. Tambah Data\n");
        printf("2. Tampilkan Data\n");
        printf("3. Tampilkan Data Mahasiswa NIM genap\n");
        printf("4. Tampilkan Data Mahasiswa NIM ganjil\n");
        printf("5. Tampilkan Data Mahasiswa Laki-laki\n");
        printf("6. Tampilkan Data Mahasiswa Perempuan\n");
        printf("7. Keluar\n");
        printf("Masukkan Piliham : ");

        scanf("%d", &opt);

        if (opt == 1)
        {
            condition = true;
            while (condition)
            {
                fflush(stdin);
                append();
                printf("Menambah Data Lagi (y/n) : ");
                gets(yesno);
                if (*yesno == 'n' || *yesno == 'N') 
                {
                    condition = false;
                }
                    
            }
        }else if (opt == 2)
        {
            printf("\n");
            show_data();
        }else if (opt == 3)
        {
            printf("\n");
            show_even_nim_data();
        }else if (opt == 4)
        {
            printf("\n");
            show_odd_nim_data();
        }else if (opt == 5)
        {
            printf("\n");
            show_male_data();
        }else if (opt == 6)
        {
            printf("\n");
            show_female_data();
        }
             
    }    
}