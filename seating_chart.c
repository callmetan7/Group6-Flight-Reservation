#include <stdio.h>


// Test Case: 
// void init_seating(char seats[][6], int total_rows, int bus_rows, int bus_cols, int econ_cols);
// void display_seating(char seats[][6], int total_rows, int bus_rows, int bus_cols, int econ_cols);

// Data for Boeing 737: Business - (ABCD x 3), Economy - (ABCDEF x 28)
void init_seating(char seats[][6], int total_rows, int bus_rows, int bus_cols, int econ_cols){       
    for(int r = 0; r < total_rows; r++){
        for(int c = 0; c < econ_cols; c++){
            if(r < bus_rows){
                if(c < bus_cols){
                    seats[r][c] = 'O';
                }
                else {
                    seats[r][c] = '-';
                }
            }
            else {
                seats[r][c] = 'O';
            }
        }
    }
}

void display_seating(char seats[][6], int total_rows, int bus_rows, int bus_cols, int econ_cols) {
    printf("\n=== AIRCRAFT SEATING CHART ===\n");
    printf("Legend: [O] Available   [X] Booked\n\n");

    for (int r = 0; r < total_rows; ++r) {
        if (r == 0 && bus_rows > 0) {
            printf("--- BUSINESS CLASS ---\n");
            printf("     ");
            for (int c = 0; c < bus_cols; ++c) {
                if (c == bus_cols / 2) {
                    printf("   "); 
                }
                printf(" %c ", 'A' + c);
            }
            printf("\n");
        } else if (r == bus_rows) {
            printf("\n--- ECONOMY CLASS ---\n");
            printf("     ");
            for (int c = 0; c < econ_cols; ++c) {
                if (c == econ_cols / 2) {
                    printf("   ");
                }
                printf(" %c ", 'A' + c);
            }
            printf("\n");
        }

        printf("%2d   ", r + 1);

        int active_cols = (r < bus_rows) ? bus_cols : econ_cols;
        for (int c = 0; c < econ_cols; ++c) {
            if (seats[r][c] == '-') {
                continue;
            }
            if (c == active_cols / 2) {
                printf("   ");
            }

            printf("[%c]", seats[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}