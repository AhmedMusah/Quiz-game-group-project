#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>

struct Question {
    char question[100];
    char options[4][50];
    char correct;
};

// Shared variables between threads
int time_up = 0;
int answered = 0;
char answer;

// Timer thread function
void* timer(void* arg) {
    int seconds = *(int*)arg;

    for (int i = seconds; i > 0; i--) {

        if (answered) break;

        printf("\r Time left: %d ", i);
        fflush(stdout);

        sleep(1);
    }

    if (!answered) {
        time_up = 1;
        printf("\n Time's up!\n");
    }

    return NULL;
}

int main() {
    struct Question q = {
        "What is 2 + 2?",
        {"A. 3", "B. 4", "C. 5", "D. 6"},
        'B'
    };

    int score = 0;
    pthread_t t;
    int seconds = 10;

    // Display question
    printf("\n==============================\n");
    printf("        QUIZ GAME \n");
    printf("==============================\n\n");

    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", q.options[i]);
    }

    // Start timer thread
    pthread_create(&t, NULL, timer, &seconds);

    // Get user input
    printf("\nYour answer: ");
    scanf(" %c", &answer);

    answered = 1; // signal timer to stop
    answer = toupper(answer);

    // Wait for timer thread to finish
    pthread_join(t, NULL);

    // Evaluate result
    if (time_up) {
        printf(" Too slow!\n");
    } else if (answer == q.correct) {
        printf(" Correct!\n");
        score++;
    } else {
        printf(" Wrong!\n");
    }

    printf("\nFinal Score: %d\n", score);

    return 0;
}
