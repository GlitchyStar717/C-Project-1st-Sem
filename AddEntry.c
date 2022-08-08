#include <stdio.h>
struct students {
    int roll_no;
    int rating[11];
} S[48];

void studentsWhoHaveRated(int arr[48]) {
    int i = 0, var, count = 0;
    char ch[5], tmp;
    FILE *fp;

    fp = fopen("Student.txt", "r+");

    for (i = 0; i < 48; i++) arr[i] = 0;

    i = 0;
    while (!feof(fp)) {
        count = 0;
        var = 0;
        fgets(ch, 5, fp);
        while (ch[count] != ' ') {
            tmp = ch[count++];
            var = var * 10;
            var += (tmp - '0');

            if (ch[count] == ' ') {
                arr[i] = var;
                i++;

                var = 0;
            }
        }
    }
    i = 0;
    printf("\nCurrently These students have already rated. \n");
    while (arr[i] != 0) {
        printf("%d\t", arr[i]);
        i++;
    }

    fclose(fp);
}

int checkIfAlreadyRated(int arr[48], int roll) {
    int i = 0;
    while (arr[i] != 0) {
        if (arr[i] == roll) return 1;
        i++;
    }
    return 0;
}

void printTeachersName() {
    int i = 0, j = 1;
    int no[11], average[11], total[11];

    char teachers[150] = "(Comp)GGsir (Maths)GGsir PAmaam Hgsir SDBmaam (Physics)GNLsir KPsir (Mechanics)AKmaam GSBsir (Electrical)SKsir (Drawing)PGsir";
    printf("\n\n");
    while (teachers[i] != '\0') {
        if (teachers[i] != '(' && teachers[i] != ' ' && teachers[i] != '\0') printf("%d) ", j++);
        while (teachers[i] != '(' && teachers[i] != ' ' && teachers[i] != '\0') {
            {
                printf("%c", teachers[i]);
                i++;
            }
        }

        switch (teachers[i]) {
            case '(':
                printf("\n");
                while (teachers[i] != ')') {
                    printf("%c", teachers[i]);
                    i++;
                    ;
                }
                printf("%c", teachers[i]);

            case ' ':

                printf("\n");
                i++;
                break;
        }
    }
    printf("\n\n");

    // while (teachersl)
}

void printTeachersName2() {
    int i = 0, j = 1, k, rating;
    int no[11], average[11], total[11];

    char teachers[150] = "(Comp)GGsir (Maths)GGsir PAmaam Hgsir SDBmaam (Physics)GNLsir KPsir (Mechanics)AKmaam GSBsir (Electrical)SKsir (Drawing)PGsir";
    while (teachers[i] != '\0') {
        if (teachers[i] == '(') {
            printf("\n");
            printf("\n");

        } else if (teachers[i] == ')') {
            printf("\n");
            printf("%d.)", j);
            j++;
        } else {
            if (teachers[i] == ' ') {
                printf("\t");
                if (teachers[i + 1] != '(') {
                    printf("%d.)", j);
                    j++;
                }
                k = i;
                while (teachers[k] != ' ') {
                    printf("%c", teachers[i]);
                    k++;
                    i = k - 1;
                }
            } else {
                printf("%c", teachers[i]);
            }
        }
        i++;
    }
    printf("\n\n");
}

void printTeachersName3() {
    int i, j, k, c = 1;
    char arr[50][50][50] = {{{"KPsir"}, {"GNLsir"}}, {{"GGsir"}, {"PAmaam"}, {"Hgsir"}, {"SDBmaam"}}, {{"AKmaam"}, {"GSBsir"}}, {{"PGsir"}}, {{"GGsir"}}, {{"SKsir"}}};
    char subjects[6][15] = {
        {"Physics"}, {"Maths"}, {"Mechanics"}, {"Drawing"}, {"Computer"}, {"Electrical"},
    };
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 15; j++) {
            printf("%c", subjects[i][j]);
        }
        printf("\n");
        for (j = 0; j < 4; j++) {
            if (arr[i][j][0] != '\0') printf("%d.) ", c++);
            for (k = 0; k < 7; k++) {
                printf("%c", arr[i][j][k]);
            }
            if (arr[i][j][0] != '\0') printf("\n");
        }
        if (arr[i][0][0] != '\0') printf("\n");
    }
}

void printTeachersNameTab() {
    int i, j;
    char arr[11][50] = {{"KPsir"}, {"GNLsir"}, {"GGsir"}, {"PAmaam"}, {"HGsir"}, {"SDmaam"}, {"AKmaam"}, {"GSBsir"}, {"PGsir"}, {"GGsir"}, {"SKsir"}};

    for (i = 0; i < 11; i++) {
        printf("%d.)", (i + 1));
        for (j = 0; j < 7; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int extractFromDB(int no[11], int rate[11]) {
    int i, var, count, arr[2][11], row = 0, column;
    char ch[150], tmp;
    FILE *fp;

    fp = fopen("rating_data.txt", "r+");
    if (fp == NULL) return 0;
    while (!feof(fp)) {
        i = 0, var = 0, column = 0;
        ;
        fgets(ch, 150, fp);
        while (ch[i] != '.') {
            tmp = ch[i++];
            var = var * 10;
            var += (tmp - '0');

            if (var == 0) return 0;
            if (ch[i] == ' ') {
                i++;
                arr[row][column] = var;

                var = 0;
                column++;
            }
        }
        row++;
    }

    for (i = 0; i < 11; i++) {
        no[i] = arr[0][i];
        rate[i] = arr[1][i];
    }

    fclose(fp);
    return 0;
}

void addEntry(int *roll, int *rating) {
    int i, j = 0, count=0;
    int no[11], rate[11], StudentsWhoHaveRated[48];
    char ch[150];

    FILE *student_data;
    FILE *real_rating_data;
    student_data = fopen("Student.txt", "a+");

    for (int i = 0; i < 11; i++) {
        no[i] = 0;
        rate[i] = 0;
    }

    extractFromDB(no, rate);
    studentsWhoHaveRated(StudentsWhoHaveRated);

    do {
        if(count > 3) printf("\nWhat the hellll.. Enter properly.. Why you spammin' brooo..!!");
        printf("\n\nKindly, Enter your roll no please (49-96): ");
        scanf("%d", roll);
        j = checkIfAlreadyRated(StudentsWhoHaveRated, *roll);
        if (j == 1) 
        {
            printf("Sorry, but I think you have already entered your rating. Please let others rate now.");
            count++;
        }
        if (*roll < 49 || *roll > 96)
        {
            printf("You must belong to CD section with roll no between 49 and 96 to rate.");
            count++;
        }
    } while (*roll < 49 || *roll > 96 || j == 1);
    fprintf(student_data, "%d ", *roll);

    printf("\n\n");
    printTeachersNameTab();
    for (i = 0; i < 11; i++) {
        do {
            printf("Enter your rating(1-9) for teacher no %d : ", (i + 1));
            scanf("%d", rating + i);
        } while (*(rating + i) < 1 || *(rating + i) > 9);

        fprintf(student_data, "%d ", *(rating + i));

        rate[i] += *(rating + i);
        no[i] = no[i] + 1;
    }
    fprintf(student_data, ".\n");

    real_rating_data = fopen("rating_data.txt", "w");
    for (i = 0; i < 11; i++) {
        fprintf(real_rating_data, "%d ", no[i]);
    }
    fprintf(real_rating_data, ".\n");
    for (i = 0; i < 11; i++) {
        fprintf(real_rating_data, "%d ", rate[i]);
    }
    fprintf(real_rating_data, ".");

    fclose(student_data);
    fclose(real_rating_data);
}

int countStudent() {
    int i = 0;
    char ch[30];
    FILE *student_data;
    student_data = fopen("Student.txt", "r+");

    if (student_data == NULL) return 0;
    while (!feof(student_data)) {
        fgets(ch, 30, student_data);
        i++;
    }
    return (i - 1);
}

void main()

{
    unsigned choice = 1;
    int i, j;

    printf("Hey there, Nice to have you fellow pulchowkian.\n I would be grateful if you tell us your opinion about our teachers. Our faculty as of now stands as :\n");
    printTeachersName3();
    while (choice != 2) {
        printf("\n\nDo you want to add your rating for our teachers: \n");
        printf("1.) Yes\n");
        printf("2.) No\n\n");
        scanf("%d", &choice);

        if (choice == 1) {
            j = countStudent();
            struct students S[j];

            addEntry(&S[j].roll_no, S[j].rating);

        } else if (choice == 2)
            printf("Thank you . Have a good day sir.\n");
    }
}