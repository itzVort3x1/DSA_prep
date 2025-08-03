#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

enum class TicketType {BUG, NEW_FEATURE, ENHANCEMENT};
enum class Tag {URGENT, BACKEND, FRONTEND};

class User {
    private:
        string id;
        string name;
    public:
        User() {};

        void modifyUser(string name){};
};

class ActivityLog {
    private:
        string id;
        string message;
        User performedBy;
        string createdAt;
        string updatedAt;
    public:
        ActivityLog() {};

        void modifyLog() {};
};

class Comment {
    private:
        string id;
        User user;
        string createdAt;
        string updatedAt;
        string message;
        int likeCount;

    public:
        Comment() {};

        void updateMessage(const string& message);
        void like();
        void unlike();
};

class Task {
    private:
        string name;
        TicketType type;
        User assignedTo;
        vector<ActivityLog> logs;
        vector<Comment> comments;
        unordered_set<Tag> tags;
    public:
        Task () {};

        void addLog(User id, ActivityLog log) {};
        void modifyTask(string name) {};
        void updateTicketType(TicketType type) {};

        void addComment(Comment comment) {};
        void deleteComment(string commentId) {};
        vector<Comment> listComments() {};
        
        void addTag(Tag tag) {};
        void removeTag(Tag tag) {};
        vector<Tag> listTags() {};

};

class TaskManager {
    private:
        vector<Task> Tasks;
    public:
        TaskManager() {};

        void getTask(string id) {};
        void addTask(string name) {};
        void updateTask(string name) {};
        void deleteTask(string name) {};
        void reAssignTask(string name) {};
};

class Project {
    private:
        TaskManager manager;
        string id;
        string name;
        vector<User> associatedUsers;
    public:
        Project() {};

        void addTasks(string id) {}
        void removeTasks(string id) {}
        void addUser(User user) {};
        void deleteUser(User user) {};
        vector<Task> listTasks() {};
        vector<User> listUsers() {};
};

int main() {
    return 0;
}