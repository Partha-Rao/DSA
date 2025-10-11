#include <stdio.h>

#define DAYS 30
#define MEMBERS 150

struct Member {
    char name[50];
    int steps[DAYS];
};

void analyzeSteps(struct Member members[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 0, max = 0;

        for (int j = 0; j < DAYS; j++) {
            if (members[i].steps[j] > 10000)
                count++;
            if (members[i].steps[j] > max)
                max = members[i].steps[j];
        }

        printf("Member: %s\n", members[i].name);
        printf("Days exceeding 10000 steps: %d\n", count);
        printf("Maximum step count of a member: %d\n", max);
    }
}

int main() {
    struct Member members[MEMBERS] = {
        {"Anup", {9500, 12000, 9800, 15000, 8000, 10200, 11000, 8700, 9000, 13000,
                   8900, 10000, 10500, 9500, 10800, 11200, 8700, 9600, 11400, 23400,
                   10000, 9800, 8800, 15000, 13000, 9000, 9500, 9400, 10000, 10300}},
        {"Harry", {8500, 9000, 9200, 9700, 8800, 9500, 11000, 11100, 12000, 12300,
                 13000, 9900, 9700, 8800, 8900, 8700, 9100, 9300, 9400, 9500,
                 9600, 9700, 9800, 9900, 10000, 10100, 10200, 10300, 17400, 10500}},
        {"Ronny", {15000, 14000, 13500, 13000, 12500, 12600, 11500, 11000, 10000, 9500,
                     9000, 8500, 8000, 7500, 7000, 6500, 6000, 5500, 16700, 4500,
                     4000, 3500, 3000, 2500, 2000, 1500, 1000, 12000, 13000, 14000}}
    };

    analyzeSteps(members, MEMBERS);
    return 0;
}
