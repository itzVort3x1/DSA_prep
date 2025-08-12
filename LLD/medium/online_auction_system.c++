#include <string>
#include <vector>
#include <map>
#include <set>
#include <chrono>

using namespace std;

// Forward declarations to avoid circular dependencies
class Auction;
class User;
class Bid;
class AuctionObserver;

// -------------------- ENUM --------------------
// Represents the status of an auction
enum class AuctionStatus {
    CLOSED,   // Auction has ended
    PENDING,  // Auction created but not yet started
    ACTIVE    // Auction is currently accepting bids
};

// -------------------- INTERFACE --------------------
// Observer interface for receiving auction updates
class AuctionObserver {
public:
    // Called when an auction changes (e.g., new bid, auction ends)
    virtual void onUpdate(Auction* auction, const string& message) = 0;
    virtual ~AuctionObserver() {}
};

// -------------------- USER --------------------
// A user in the system, also acts as an observer for auctions
class User : public AuctionObserver {
private:
    string id;    // Unique user ID
    string name;  // Display name

public:
    User(const string& id, const string& name);

    string getId() const;   // Returns user ID
    string getName() const; // Returns user name

    // From AuctionObserver: receive updates about auctions
    void onUpdate(Auction* auction, const string& message) override;
};

// -------------------- BID --------------------
// Represents a bid placed by a user on an auction
class Bid {
private:
    User* bidder;  // The user who placed the bid
    double amount; // Bid amount
    chrono::system_clock::time_point timestamp; // Time bid was placed

public:
    Bid(User* bidder, double amount);

    User* getBidder() const;   // Returns bidder
    double getAmount() const;  // Returns bid amount
    chrono::system_clock::time_point getTimestamp() const; // Returns bid time

    // Compare two bids (e.g., for finding highest)
    int compareTo(const Bid& other) const;
};

// -------------------- AUCTION --------------------
// Represents an auction with item details, bids, and observers
class Auction {
private:
    string id;        // Unique auction ID
    string itemName;  // Name of the item being auctioned
    string description; // Description of the item
    double startingPrice; // Minimum starting bid
    chrono::system_clock::time_point endTime; // Auction end time
    AuctionStatus state; // Current status (ACTIVE, PENDING, CLOSED)
    vector<Bid> bids;    // All bids placed in this auction
    set<AuctionObserver*> observers; // Users observing this auction

public:
    Auction(const string& id,
            const string& itemName,
            const string& description,
            double startingPrice,
            chrono::system_clock::time_point endTime);

    bool isActive() const;               // Check if auction is active
    vector<Bid> getBidHistory() const;   // Get all bids
    Bid getHighestBid() const;           // Get the highest bid

    void placeBid(User* user, double amount); // Place a new bid
    void endAuction();                        // End the auction

    void addObserver(AuctionObserver* observer);              // Add an observer
    void notifyObserver(AuctionObserver* observer, const string& message); // Notify one observer
    void notifyAllObservers(const string& message);            // Notify all observers
};

// -------------------- AUCTION SERVICE --------------------
// Service to manage auctions and users (Singleton pattern)
class AuctionService {
private:
    map<string, User> users;     // All users in system
    map<string, Auction> auctions; // All auctions in system

    static AuctionService* instance; // Singleton instance

    AuctionService(); // Private constructor (singleton)

public:
    static AuctionService* getInstance(); // Get singleton instance

    User* createUser(const string& name); // Create a new user
    User* getUser(const string& id);      // Get a user by ID

    Auction* createAuction(const string& itemName,
                           const string& description,
                           double startingPrice,
                           chrono::system_clock::time_point endTime); // Create a new auction
    Auction* getAuction(const string& id); // Get an auction by ID

    void placeBid(const string& userId, const string& auctionId, double amount); // Place a bid
    vector<Auction*> viewActiveAuctions() const; // List active auctions
    void endAuction(const string& auctionId);    // End an auction

    void shutdown(); // Stop service (cleanup if needed)
};
