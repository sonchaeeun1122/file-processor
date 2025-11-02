#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include<time.h>
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    char *input_file = argv[1];
    char *mode = argv[2];
    char buffer[MAXLINE];
    char result[MAXLINE];
    int line_count = 0;

    FILE *fp = fopen(input_file, "r");
    if (fp == NULL) {
        fprintf(stderr,"File not found : %s\n", input_file);
        return -1;
    }

    int fd1 = open("clntTOsvr", O_WRONLY);
    if (fd1 < 0) {
        fprintf(stderr,"Error opening client socket\n");
        fclose(fp);
        return 1;
    }
    int fd2 = open("svrTOclnt", O_RDONLY);
    if (fd2 < 0) {
        fprintf(stderr,"Error opening client socket\n");
        close(fd1);
        fclose(fp);
        return 1;
    }

    time_t start = time(NULL);

    write(fd1, mode, strlen(mode)+1);

    while (fgets(buffer, MAXLINE, fp)) {
        line_count++;
        printf("%d번째 줄 전송...\n", line_count);

        write(fd1, buffer, strlen(buffer)+1);

        read(fd2, result, MAXLINE);
        printf("%d번째 줄 결과 수신: Line %d: %s\n", line_count, line_count, result);
    }

    time_t end = time(NULL);

    write(fd1, "END", 4);

    printf("\n=== 처리 통계 ===\n");
    printf("처리 모드: %s\n", mode);
    printf("처리한 줄 수: %d\n", line_count);
    printf("소요 시간: %.2f초\n", difftime(end, start));

    close(fd1);
    close(fd2);
    fclose(fp);

    return 0;
}
