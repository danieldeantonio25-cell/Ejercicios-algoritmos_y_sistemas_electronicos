#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Twitter {
private:
    
    struct Tweet {
        int id;
        int time;
    };

    int timestamp;
    unordered_map<int, vector<Tweet>> userTweets;     
    unordered_map<int, unordered_set<int>> following; 

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({tweetId, timestamp++});
    }

    vector<int> getNewsFeed(int userId) {
        
        following[userId].insert(userId);
        
        
        priority_queue<pair<int, int>> pq;

        for (int followeeId : following[userId]) {
            const auto& tweets = userTweets[followeeId];
            
            int n = tweets.size();
            for (int i = n - 1; i >= 0 && i >= n - 10; --i) {
                pq.push({tweets[i].time, tweets[i].id});
            }
        }

        vector<int> res;
        for (int i = 0; i < 10 && !pq.empty(); ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};

int main() {
    Twitter* twitter = new Twitter();

    cout << "--- Ejecutando Ejemplo ---" << endl;
    
    twitter->postTweet(1, 5);
    cout << "User 1 posteó 5" << endl;

    cout << "Feed User 1: ";
    for (int id : twitter->getNewsFeed(1)) cout << id << " "; 
    cout << endl;

    twitter->follow(1, 2);
    twitter->postTweet(2, 6);
    cout << "User 1 siguió a 2. User 2 posteó 6" << endl;

    cout << "Feed User 1: ";
    for (int id : twitter->getNewsFeed(1)) cout << id << " "; 
    cout << endl;

    twitter->unfollow(1, 2);
    cout << "User 1 dejó de seguir a 2" << endl;

    cout << "Feed User 1: ";
    for (int id : twitter->getNewsFeed(1)) cout << id << " ";
    cout << endl;

    delete twitter;
    return 0;
}

