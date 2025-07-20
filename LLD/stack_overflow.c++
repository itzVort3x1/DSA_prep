#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum class VoteType {UPVOTE, DOWNVOTE};

// ----- Base Class for Question and Answer -----
class Post {
protected:
    int id;
    string content;
    int userId;
    vector<Comment> comments;
    int upVotes;
    int downVotes;
    string createdAt;
    string updatedAt;

public:
    Post(int id, string content, int userId);

    void addComment(Comment comment);
    void vote(VoteType type);
    void editContent(string newContent);
};

// ----- Comment -----
class Comment {
private:
    string commentText;
    int userId;
    string createdAt;

public:
    Comment(string commentText, int userId);
};

// ----- Answer -----
class Answer : public Post {
public:
    Answer(int id, string content, int userId);
};

// ----- Question -----
class Question : public Post {
private:
    vector<Answer> answers;

public:
    Question(int id, string content, int userId);

    void addAnswer(Answer answer);
    vector<Answer> getAllAnswers();
};

// ----- User -----
class User {
private:
    string name;
    int id;
    vector<int> questionIds;
    vector<int> answerIds;

public:
    User(string name, int id);

    void askQuestion(Question question);
    void answerQuestion(Question& question, Answer answer);
};


int main() {

}