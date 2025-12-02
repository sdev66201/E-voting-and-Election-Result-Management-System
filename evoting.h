#ifndef EVOTING_H
#define EVOTING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int voter_id;
    char name[100];
    bool has_voted;
} Voter;

typedef struct {
    int candidate_id;
    char name[100];
    char party[100];
    int vote_count;
} Candidate;

typedef struct VoterNode {
    Voter voter;
    struct VoterNode* next;
} VoterNode;

typedef struct CandidateNode {
    Candidate candidate;
    struct CandidateNode* next;
} CandidateNode;

typedef struct {
    int voter_id;
    int candidate_id;
    char timestamp[50];
} VoteRecord;

extern VoterNode* voterHead;
extern CandidateNode* candidateHead;
extern VoteRecord votes[1000];
extern int voteCount;
extern int totalVoters;
extern int totalCandidates;

void displayMenu(void);

void registerVoter(void);
VoterNode* findVoter(int voter_id);
void displayVoters(void);

void registerCandidate(void);
CandidateNode* findCandidate(int candidate_id);
void displayCandidates(void);

void castVote(void);
bool validateVote(int voter_id, int candidate_id);
void recordVote(int voter_id, int candidate_id);
void computeResults(void);
void displayResults(void);
void saveResultsToFile(void);

void clearInputBuffer(void);
void getCurrentTimestamp(char* buffer);
void loadData(void);
void saveData(void);

#endif
