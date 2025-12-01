#include "evoting.h"

VoterNode* voterHead = NULL;
CandidateNode* candidateHead = NULL;
VoteRecord votes[1000];
int voteCount = 0;
int totalVoters = 0;
int totalCandidates = 0;

void registerVoter(void) {
    VoterNode* newVoter = (VoterNode*)malloc(sizeof(VoterNode));
    if(!newVoter) { printf("[ERROR] Memory allocation failed!\n"); return; }

    printf("\n=== VOTER REGISTRATION ===\n");
    printf("Enter Voter ID: ");
    scanf("%d", &newVoter->voter.voter_id);
    clearInputBuffer();

    if(findVoter(newVoter->voter.voter_id)) {
        printf("[ERROR] Voter ID already exists!\n");
        free(newVoter);
        return;
    }

    printf("Enter Voter Name: ");
    fgets(newVoter->voter.name, 100, stdin);
    newVoter->voter.name[strcspn(newVoter->voter.name, "\n")] = 0;
    newVoter->voter.has_voted = false;

    newVoter->next = voterHead;
    voterHead = newVoter;
    totalVoters++;

    printf("[SUCCESS] Voter registered!\n");
}

VoterNode* findVoter(int voter_id) {
    VoterNode* cur = voterHead;
    while(cur) {
        if(cur->voter.voter_id == voter_id) return cur;
        cur = cur->next;
    }
    return NULL;
}

void displayVoters(void) {
    if(!voterHead) { printf("[INFO] No voters found!\n"); return; }

    VoterNode* cur = voterHead;
    printf("\n=== VOTERS LIST ===\n");
    while(cur) {
        printf("ID: %d | Name: %s | Status: %s\n",
            cur->voter.voter_id,
            cur->voter.name,
            cur->voter.has_voted ? "Voted":"Not Voted"
        );
        cur = cur->next;
    }
}

void registerCandidate(void) {
    CandidateNode* newC = (CandidateNode*)malloc(sizeof(CandidateNode));
    if(!newC) { printf("[ERROR] Memory error!\n"); return; }

    printf("\n=== CANDIDATE REGISTRATION ===\n");
    printf("Enter Candidate ID: ");
    scanf("%d", &newC->candidate.candidate_id);
    clearInputBuffer();

    if(findCandidate(newC->candidate.candidate_id)) {
        printf("[ERROR] Candidate ID exists!\n");
        free(newC);
        return;
    }

    printf("Enter Candidate Name: ");
    fgets(newC->candidate.name, 100, stdin);
    newC->candidate.name[strcspn(newC->candidate.name, "\n")] = 0;

    printf("Enter Party Name: ");
    fgets(newC->candidate.party, 100, stdin);
    newC->candidate.party[strcspn(newC->candidate.party, "\n")] = 0;

    newC->candidate.vote_count = 0;
    newC->next = candidateHead;
    candidateHead = newC;
    totalCandidates++;

    printf("[SUCCESS] Candidate registered!\n");
}

CandidateNode* findCandidate(int id) {
    CandidateNode* cur = candidateHead;
    while(cur) {
        if(cur->candidate.candidate_id == id) return cur;
        cur = cur->next;
    }
    return NULL;
}

void displayCandidates(void) {
    if(!candidateHead) { printf("[INFO] No candidates found!\n"); return; }

    CandidateNode* cur = candidateHead;
    printf("\n=== CANDIDATES ===\n");
    while(cur) {
        printf("ID: %d | Name: %s | Party: %s\n",
            cur->candidate.candidate_id,
            cur->candidate.name,
            cur->candidate.party
        );
        cur = cur->next;
    }
}

void clearInputBuffer(void) {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
