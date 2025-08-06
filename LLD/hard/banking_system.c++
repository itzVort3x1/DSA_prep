#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>
using namespace std;

struct ScheduledPayment {
    int timestamp;
    int from_id;
    int to_id;
    int amount;
    int scheduledFor;
    bool executed = false;

    ScheduledPayment(int timestamp, int from_id, int to_id, int amount, int scheduledFor) {
        this->timestamp = timestamp;
        this->from_id = from_id;
        this->to_id = to_id;
        this->amount = amount;
        this->scheduledFor = scheduledFor;
    }
};

class Account {
    private:
        int id;
        string name;
        string createdAt;
        string updatedAt;
        int balance;
        int totalOutgoing;
        bool isMergedFlag;
    public:
        Account(string name, int timestamp, int account_id) {
            id = account_id;
            this->name = name;
            createdAt = timestamp;
            balance = 0;
            totalOutgoing = 0;
        }

        int getBalance() {
            return balance;
        }

        int getTotalOutgoing() {
            return totalOutgoing;
        }

        bool isMerged() const { return isMergedFlag; }

        void deposit(int amount) {
            balance += amount;
        }

        bool withdraw(int amount) {
            if(balance >= amount) {
                balance -= amount;
                totalOutgoing += amount;
                return true;
            }

            return false;
        }

        void markMerged() {
            isMergedFlag = true;
        }

        void absorb(const Account* other) {
            balance += this->getBalance();
            totalOutgoing += this->getTotalOutgoing();
        }
};

class BankingSystem {
    private:
        unordered_map<int, Account*> accounts;
        vector<ScheduledPayment> scheduledPayments;
        int nextMergedId = 1000;
    
    public:
        BankingSystem() {};
        bool create_account(int timestamp, int account_id) {
            if(accounts.find(account_id) != accounts.end()) {
                return false;
            }

            accounts[account_id]  = new Account("Hello", timestamp, account_id);

            return true;
        }

        int deposit(int timestamp, int account_id, int amount) {
            if(accounts.find(account_id) == accounts.end()) {
                return -1;
            }

            accounts[account_id]->deposit(amount);

            return accounts[account_id]->getBalance();
        }

        int transfer(int timestamp, int account_id, int target_account_id, int amount) {
            if(account_id == target_account_id) return -1;
            if (accounts.find(account_id) == accounts.end() || accounts.find(target_account_id) == accounts.end()) return -1;

            if(!accounts[account_id]->withdraw(amount)) return -1;

            accounts[target_account_id]->deposit(amount);

            return accounts[account_id]->getBalance();
        }

        bool isValid(int account_id) {
            return accounts.find(account_id) != accounts.end() && !accounts[account_id]->isMerged();
        }

        vector<pair<int, int>> rank_accounts_by_outgoing() {
            vector<pair<int, int>> ranking;

            for(auto& [id, acc]: accounts) {
                ranking.push_back({id, acc->getTotalOutgoing()});
            }

            sort(ranking.begin(), ranking.end(), [](auto& a, auto& b) {
                return a.second > b.second; // descending order
            });

            return ranking;
        }

        bool schedule_payment(int timestamp, int from_id, int to_id, int amount, int scheduled_for) {
            if(from_id == to_id || accounts.find(from_id) == accounts.end() || accounts.find(to_id) == accounts.end()) {
                return false;
            }
            if (scheduled_for <= timestamp) return false;

            ScheduledPayment payment(timestamp, from_id, to_id, amount, scheduled_for);
            scheduledPayments.push_back(payment);
            return true;
        }

        vector<ScheduledPayment*> check_scheduled_payments(int timestamp) {
            vector<ScheduledPayment*> due;

            for(auto &payment: scheduledPayments) {
                if(!payment.executed && payment.scheduledFor <= timestamp) {
                    due.push_back(&payment);
                }
            }

            return due;
        }

        void process_due_payments(int timestamp) {
            auto due = check_scheduled_payments(timestamp);
            for(auto* payment: due) {
                int result = transfer(timestamp, payment->from_id, payment->to_id, payment->amount);
                if(result != -1) {
                    payment->executed = true;
                    cout << "✅ Executed scheduled payment from " << payment->from_id
                     << " to " << payment->to_id << " of " << payment->amount << endl;
                }else {
                    cout << "❌ Failed to execute scheduled payment from " << payment->from_id
                        << " to " << payment->to_id << endl;
                }
            }
        }

        bool merge_accounts(int timestamp, int acc1_id, int acc2_id) {
            if (acc1_id == acc2_id || !isValid(acc1_id) || !isValid(acc2_id))
                return false;

            int newId = nextMergedId++;
            Account* merged = new Account("Merge Acc",newId, timestamp);
            merged->absorb(accounts[acc1_id]);
            merged->absorb(accounts[acc2_id]);

            accounts[acc1_id]->markMerged();
            accounts[acc2_id]->markMerged();
            accounts[newId] = merged;

            // Reassign scheduled payments
            for (auto& payment : scheduledPayments) {
                if (!payment.executed) {
                    if (payment.from_id == acc1_id || payment.from_id == acc2_id)
                        payment.from_id = newId;
                    if (payment.to_id == acc1_id || payment.to_id == acc2_id)
                        payment.to_id = newId;
                }
            }

            cout << "✅ Merged accounts " << acc1_id << " and " << acc2_id << " → New ID: " << newId << endl;
            return true;
        }
};

int main () {

    BankingSystem* bank = new BankingSystem();

    cout << bank->create_account(1, 100) << endl;
    cout << bank->create_account(2, 100) << endl;
    cout << bank->create_account(3, 101) << endl;

    cout << bank->deposit(4, 400, 2700) << endl;
    cout << bank->deposit(5, 100, 2700) << endl;
    cout << bank->transfer(6, 100, 101, 2701) << endl;
    cout << bank->transfer(7, 100, 101, 200) << endl;
    cout << bank->transfer(8, 300, 101, 500) << endl;

    bank->create_account(1, 100);
    bank->create_account(2, 101);
    bank->create_account(3, 102);

    bank->deposit(4, 100, 5000);
    bank->deposit(5, 101, 3000);
    bank->deposit(6, 102, 7000);

    bank->transfer(7, 100, 101, 1000);   // A -> B
    bank->transfer(8, 100, 102, 500);    // A -> C
    bank->transfer(9, 101, 102, 300);    // B -> C
    bank->transfer(10, 102, 100, 2000); 

    bank->schedule_payment(4, 100, 101, 1000, 7);  // valid
    bank->schedule_payment(5, 100, 101, 2000, 10); // valid
    bank->schedule_payment(6, 100, 100, 500, 9);   // invalid (same account)

    bank->merge_accounts(6, 100, 101); 

    cout << "\n🏆 Account Ranking by Outgoing Total:" << endl;
    auto ranks = bank->rank_accounts_by_outgoing();

    for (auto& [id, total] : ranks) {
        cout << "Account " << id << " => Outgoing Total: " << total << endl;
    }

    cout << "\nProcessing scheduled payments at t=10...\n";
    bank->process_due_payments(10); // processes both

    return 0;
}