#include "evoting.h"

void displayMenu(void) {
    printf("\n");
    printf("===============================================================\n");
    printf("                      MAIN MENU                                \n");
    printf("===============================================================\n");
    printf("  1. Register Voter                                            \n");
    printf("  2. Register Candidate                                        \n");
    printf("  3. Display All Voters                                        \n");
    printf("  4. Display All Candidates                                    \n");
    printf("  5. Cast Vote                                                 \n");
    printf("  6. Compute and Display Results                               \n");
    printf("  7. Save Results to File                                      \n");
    printf("  8. Save Data                                                 \n");
    printf("  9. Exit                                                      \n");
    printf("===============================================================\n");
    printf("\n");
}

int main(void) {
    int choice;

    printf("\n");
    printf("===============================================================\n");
    printf("        E-VOTING AND ELECTION RESULT MANAGEMENT SYSTEM         \n");
    printf("===============================================================\n");
    printf("\n");

    loadData();

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice) {
            case 1: registerVoter(); break;
            case 2: registerCandidate(); break;
            case 3: displayVoters(); break;
            case 4: displayCandidates(); break;
            case 5: castVote(); break;
            case 6: computeResults(); displayResults(); break;
            case 7: saveResultsToFile(); break;
            case 8: saveData(); printf("\n[SUCCESS] Data saved successfully!\n"); break;
            case 9: saveData(); printf("\nThank you for using the E-Voting System!\n"); break;
            default: printf("\n[ERROR] Invalid choice! Please try again.\n");
        }

        if(choice != 9) {
            printf("\nPress Enter to continue...");
            getchar();
        }

    } while(choice != 9);

    return 0;
}
