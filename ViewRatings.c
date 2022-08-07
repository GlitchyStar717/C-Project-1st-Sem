#include <stdio.h>
void printTeachersName3() {
    int i, j, k, c = 1;
    char arr[50][50][50] = {{{"KPsir"}, {"GNLsir"}}, {{"GGsir"}, {"PAmaam"}, {"Hgsir"}, {"SDmaam"}}, {{"AKmaam"}, {"GSBsir"}}, {{"PGsir"}}, {{"GGsir"}}, {{"SKsir"}}};
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
    char arr[11][50] = {{"KPsir"}, {"GNLsir"}, {"GGsir"}, {"PAmaam"}, {"Hgsir"}, {"SDmaam"}, {"AKmaam"}, {"GSBsir"}, {"PGsir"}, {"GGsir"}, {"SKsir"}};

    for (i = 0; i < 11; i++) {
        for (j = 0; j < 7; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\t");
    }
    printf("\n");
}

void printTeachersList() {
    int j;
    for (j = 0; j < 11; j++) printf("%d\t", (j + 1));
    printf("\n");
    printTeachersNameTab();
}

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

    fclose(fp);
}

void displayStudentsWhoHaveRated(int arr[48]) {
    int i = 0;
    studentsWhoHaveRated(arr);
    while (arr[i] != 0) {
        printf("%d\t", arr[i]);
        i++;
    }
    printf("\n");
}

int countStudent() {
    int i = 0;
    char ch[150];
    FILE *student_data;
    student_data = fopen("Student.txt", "a+");

    if (student_data == NULL) return 0;
    while (!feof(student_data)) {
        fgets(ch, 150, student_data);
        i++;
    }
    return (i - 1);
}

int displayStudentsRating(int roll) {
    int i, var, arr[11], column = 0, loop = 0, StudentsWhoHaveRated[48], len;
    char ch[150], tmp;
    FILE *fp;

    studentsWhoHaveRated(StudentsWhoHaveRated);
    len = countStudent();

    fp = fopen("Student.txt", "r+");
    if (fp == NULL) return 0;

    while ((roll > 96 || roll < 49) && roll != 717) {
        printf("We only have students from 49 to 96. Sorry to disappoint you. Re-enter your roll no among : \n");
        displayStudentsWhoHaveRated(StudentsWhoHaveRated);
        printf(" OR Enter 717 for printing ratings of all students.\n\n");
        scanf("%d", &roll);
        return displayStudentsRating(roll);
    }

    for (i = 0; i < len; i++) {
        if (roll == StudentsWhoHaveRated[i]) {
            loop = 1;
        }
    }
    if (roll == 717) loop = 1;
    if (loop == 0) {
        printf("Our record does not find any student with the matching record. Please enter another roll no among : \n");
        displayStudentsWhoHaveRated(StudentsWhoHaveRated);
        printf("Enter 717 for printing ratings of all students.\n\n");
        scanf("%d", &roll);
        return displayStudentsRating(roll);
    }
    if (roll != 717) {
        while (!feof(fp)) {
            i = 0, var = 0;
            fgets(ch, 150, fp);
            while (ch[i] != ' ') {
                tmp = ch[i++];
                var = var * 10;
                var += (tmp - '0');
            }
            if (var == roll) {
                loop = 0;

                i++;

                var = 0;
                column = 0;
                while (ch[i] != '.') {
                    tmp = ch[i++];
                    var = var * 10;
                    var += (tmp - '0');

                    if (ch[i] == ' ') {
                        i++;
                        arr[column] = var;

                        var = 0;
                        column++;
                    }
                }
            }
        }
        printf("The rating for the teachers by %d roll no is : \n", roll);

        for (i = 0; i < 11; i++) {
            printf("Rating of teacher %d is : %d\n", (i + 1), arr[i]);
        }
    } else {
        printf("Roll\t");
        printTeachersNameTab();
        while (!feof(fp)) {
            i = 0, var = 0, column = 0;
            ;
            fgets(ch, 150, fp);
            while (ch[i] != '.') {
                printf("%c", ch[i++]);
                if (ch[i] == ' ') {
                    i++;
                    printf("\t");
                }
                if (ch[i] == '.') printf("\n");
            }
        }
    }

    fclose(fp);
    return 0;
}

int extractAverage(float average[11]) {
    int i, var, count, arr[2][11], row = 0, column, no[11], rate[11];
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
    for (i = 0; i < 11; i++) {
        average[i] = rate[i] / no[i];
    }

    fclose(fp);
    return 0;
}

void teachersRatingArray(int arr[48][11]) {
    int i = 0, var, count = 0, row = 0, column = 0, j;
    char ch[150], tmp;
    FILE *fp;

    fp = fopen("Student.txt", "r+");

    for (i = 0; i < 48; i++) {
        for (j = 0; j < 11; j++) arr[i][j] = 0;
    }

    i = 0;
    while (!feof(fp)) {
        i = 0, column = 0, var = 0;
        fgets(ch, 150, fp);
        while (ch[i] != ' ') {
            i++;
        }
        i++;
        while (ch[i] != '.') {
            tmp = ch[i++];
            var = var * 10;
            var += (tmp - '0');

            if (ch[i] == ' ') {
                i++;
                arr[row][column] = var;

                var = 0;
                column++;
            }
        }
        row++;
    }

    fclose(fp);
}

void displayTeachersRating(int index) {
    int i = 0, arr[48][11], j = 0;
    float arrAverage[11];
    teachersRatingArray(arr);
    extractAverage(arrAverage);

    while ((index > 11 || index < 1) && index != 717) {
        printf("We only have 11 teachers in our record. Please Re-Enter the index of the teacher among : \n");
        printTeachersList();
        printf("OR Enter 717 to print the rating of all teachers. \n\n");
        scanf("%d", &index);
        return displayTeachersRating(index);
    }
    i = 0;
    if (index == 717) {
        while (arr[i][j] != 0) {
            for (j = 0; j < 11; j++) printf("%d\t", arr[i][j]);
            printf("\n");
            i++;
        }

        for (i = 0; i < 11; i++) {
            printf("%.2f\t", arrAverage[i]);
        }
        printf("Averages.\n");
    } else {
        while (arr[(i + 1)][j] != 0) {
            printf("%d\t", arr[i][(index - 1)]);
            printf("\n");
            i++;
        }
        printf("Average is : %f.", arrAverage[index - 1]);
    }
}

void printStudentsRating() {
    int roll, j = 0, StudentsWhoHaveRated[48];
    printf("\n");
    printf("Enter the roll no of student of student whose rating you want to view.\n");
    printf("Currently, these students have rated.\n");
    displayStudentsWhoHaveRated(StudentsWhoHaveRated);
    printf("Enter 717 for printing ratings of all students.\n");
    scanf("%d", &roll);
    displayStudentsRating(roll);
}

void printTeachersRating() {
    int index, j = 0, TeachersRating[48][11];
    printf("\n");
    printf("Enter the index no of the teacher whose rating you want to view.\n");
    printTeachersList();
    printf("Enter 717 for printing ratings of all teachers.\n");
    scanf("%d", &index);
    displayTeachersRating(index);
}

void main() {
    unsigned choice = 1;
    int o1, i = 0, ti, j = 1, k, StudentsWhoHaveRated[48];

    printf("Our section CD was blessed with exceptional teachers.\n");
    printTeachersName3();
    printf("\n\nBut what are the thoughts of the students on these teachers.");
    while (choice != 0) {
        printf("\nDo you want to view the ratings?\n");
        printf("1.) yes (of a particular student)\n");
        printf("2.) yes (of a particular teacher)\n");
        printf("3.) no\n");
        scanf("%d", &o1);

        switch (o1) {
            case 1:
                printStudentsRating();
                break;
            case 2:
                printTeachersRating();
                break;

            case 3:
                printf("Thank you so much for using our service. You can try our other services too. ");
                choice = 0;  // go to previous menu
        }
    }
}
