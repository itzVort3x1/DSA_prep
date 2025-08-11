#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
// observer pattern
struct Message {
    string timestamp;
    string payload;
};

class Subscriber {
    public:
        void onMessage(Message message) {};
};

class AlertSubscriber: public Subscriber {
    private:
        string id;
    public:
        void onMessage(Message message) {};
};

class NewsSubscriber: public Subscriber {
    private:
        string id;
    public:
        void onMessage(Message message) {};
};

class Topic {
    private:
        string name;
        unordered_set<Subscriber> st;
    public:
        void addSubscriber(Subscriber subscriber) {};
        void removeSub(Subscriber, Subscriber) {};
        void broadcase(Message message) {};
};

class PubSubService {
    private:
        unordered_map<string, Topic> topics;
    public:
        void createTopic(string topicName) {};
        void publish(string name, Message message) {};
        void subscribe(string name, Subscriber subscriber) {};
        void unsubscribe(string name, Subscriber subscriber) {};
};