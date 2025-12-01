#include "evoting.h"

void castVote(void) {
    int voter_id, candidate_id;

    printf("\n=== CAST VOTE ===\n");
    printf("Enter Voter ID: ");
    scanf("%d", &voter_id);
    clearInputBuffer();

    if(!findVoter(voter_id)) {
        printf("[ERROR] Invalid voter!\n");
        return;
    }

    displayCandidates();
    printf("Enter Candidate ID: ");
    scanf("%d", &candidate_id);
    clearInputBuffer();

    if(!validateVote(voter_id, candidate_id)) return;

    recordVote(voter_id, candidate_id);
    printf("[SUCCESS] Vote recorded!\n");
}

bool validateVote(int voter_id, int candidate_id) {
    VoterNode* v = findVoter(voter_id);
    if(!v) { printf("[ERROR] Voter not found!\n"); return false; }

    if(v->voter.has_voted) { printf("[ERROR] Already voted!\n"); return false; }

    if(!findCandidate(candidate_id)) { printf("[ERROR] Invalid candidate!\n"); return false; }

    return true;
}

void recordVote(int voter_id, int candidate_id) {
    VoterNode* v = findVoter(voter_id);
    CandidateNode* c = findCandidate(candidate_id);

    v->voter.has_voted = true;
    c->candidate.vote_count++;

    votes[voteCount].voter_id = voter_id;
    votes[voteCount].candidate_id = candidate_id;
    getCurrentTimestamp(votes[voteCount].timestamp);
    voteCount++;
}

void computeResults(void) {
    printf("[INFO] Results computed!\n");
}

void displayResults(void) {
    CandidateNode* cur = candidateHead;
    if(!cur) { printf("[INFO] No candidates!\n"); return; }

    int total = 0;
    CandidateNode* winner = cur;

    while(cur) {
        total += cur->candidate.vote_count;
        if(cur->candidate.vote_count > winner->candidate.vote_count)
            winner = cur;
        cur = cur->next;
    }

    printf("\n=== RESULTS ===\n");
    cur = candidateHead;
    while(cur) {
        double pct = total ? (cur->candidate.vote_count*100.0)/total : 0;
        printf("%s (%s) - %d votes (%.2f%%)\n",
            cur->candidate.name,
            cur->candidate.party,
            cur->candidate.vote_count,
            pct
        );
        cur = cur->next;
    }

    printf("\nWinner: %s (%s)\n", winner->candidate.name, winner->candidate.party);
}

void saveResultsToFile(void) {
    FILE* f = fopen("election_results.txt", "w");
    if(!f) { printf("[ERROR] File write failed!\n"); return; }

    fprintf(f, "Election Results\n\n");

    CandidateNode* cur = candidateHead;
    int total = 0;
    CandidateNode* winner = cur;

    while(cur) {
        total += cur->candidate.vote_count;
        if(cur->candidate.vote_count > winner->candidate.vote_count)
            winner = cur;
        cur = cur->next;
    }

    cur = candidateHead;
    while(cur) {
        double pct = total ? (cur->candidate.vote_count*100.0)/total : 0;
        fprintf(f, "%s - %d votes (%.2f%%)\n",
            cur->candidate.name,
            cur->candidate.vote_count,
            pct
        );
        cur = cur->next;
    }

    fprintf(f, "\nWinner: %s (%s)\n", winner->candidate.name, winner->candidate.party);
    fclose(f);

    printf("[SUCCESS] Results saved to election_results.txt\n");
}

void getCurrentTimestamp(char* buf) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(buf, 50, "%Y-%m-%d %H:%M:%S", t);
}

void loadData(void) {}
void saveData(void) {}
