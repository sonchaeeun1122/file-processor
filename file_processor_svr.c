#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 1024

int count (char *line) { //문자 수 및 단어 수 계산
    int words = 0;
    int in_word = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t') {
            in_word = 0;
        }
        else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    return words;
}

void upper(char *line) { //대문자 변환
    for (int i = 0; line[i] != '\0'; i++) {
        line[i] = toupper(line[i]);
    }
}

void lower(char *line) { //소문자 변환
    for (int i = 0; line[i] != '\0'; i++) {
        line[i] = tolower(line[i]);
    }
}

void reverse(char *line) { //문자열 뒤집기
    int len = strlen(line);
    for (int i = 0; i < len/2 ; i++) {
        char tmp = line[i];
        line[i] = line[len - i - 1];
        line[len - i - 1] = tmp;
    }
}

void process_line (char *line, char *mode, char *result) {
    char tmp[MAXLINE];
    strcpy(tmp, line); //문자열 복사

    if (strcmp(mode, "count") == 0) {
        int char_count = strlen(line)-1; //문자열 길이 계산
        int word_count = count(line);
        sprintf(result, "%d chars, %d words", char_count, word_count);
    }

    else if (strcmp(mode, "upper") == 0) {
        upper(tmp);
        strcpy(result, tmp);
    }

    else if (strcmp(mode, "lower") == 0) {
        lower(tmp);
        strcpy(result, tmp);
    }

    else if (strcmp(mode, "reverse") == 0) {
        reverse(tmp);
        strcpy(result, tmp);
    }
}


int main() {
    char mode[20];
    char buffer[MAXLINE];
    char result[MAXLINE];
    int line_count = 0;

    unlink("clntTOsvr");
    unlink("svrTOclnt");
    mkfifo("clntTOsvr",0666);
    mkfifo("svrTOclnt",0666);
    int fd1 = open("clntTOsvr",O_RDONLY);
    if (fd1 < 0) {
        perror("Error opening client socket");
        exit(1);
    }
    int fd2 = open("svrTOclnt",O_WRONLY);
    if (fd2 < 0) {
        perror("Error opening client socket");
        exit(1);
    }

    read(fd1, mode, sizeof(mode));

    while (read(fd1, buffer, MAXLINE) > 0) {
        if (strcmp(buffer, "END") == 0) {
            printf("프로세스 종료\n");
            break;
        }

        line_count++;
        printf("%d번째 줄 처리 중...\n", line_count);

        process_line(buffer, mode, result);

        write(fd2, result, strlen(result)+1);
    }
    close(fd1);
    close(fd2);

    return 0;
}