/*
Problem: LeetCode 355 - Design Twitter

Description:
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and see the 10 most recent tweets in the user's news feed.

Intuition:
To design Twitter, we need to efficiently handle the following operations:
1. Posting a tweet: We need to store the tweets along with their timestamps.
2. Following/Unfollowing a user: We need to maintain a data structure to track the followers and followees of each user.
3. Retrieving the news feed: We need to combine the tweets from the user's own timeline along with the tweets from the users they follow.

Approach:
1. Implement the `User` class to store the user's information, including their tweets and the users they follow.
2. Use an unordered_map to store the user ID as the key and the corresponding `User` object as the value.
3. Implement the `Tweet` class to store the tweet's information, including the tweet ID and the timestamp.
4. Use a deque to store the tweets in the user's timeline, with the most recent tweet at the front.
5. To post a tweet:
   - Get the `User` object corresponding to the user ID.
   - Create a new `Tweet` object with the tweet ID and the current timestamp.
   - Add the tweet to the user's timeline and update the timestamp.
6. To follow a user:
   - Get the `User` objects corresponding to the follower and followee IDs.
   - Add the followee ID to the follower's list of followees.
7. To unfollow a user:
   - Get the `User` objects corresponding to the follower and followee IDs.
   - Remove the followee ID from the follower's list of followees.
8. To retrieve the news feed:
   - Get the `User` object corresponding to the user ID.
   - Create a priority_queue to store the tweets from the user's timeline and the timelines of the users they follow.
   - Iterate over the tweets in the user's timeline and add them to the priority queue.
   - Iterate over the followees of the user and add their tweets to the priority queue.
   - Pop the top 10 tweets from the priority queue and return them in reverse order.

Time Complexity:
The time complexity of posting a tweet, following/unfollowing a user, and retrieving the news feed is O(log n), where n is the number of tweets. This is because we use a priority queue to retrieve the top 10 tweets in the news feed.

Space Complexity:
The space complexity is O(m + n), where m is the number of users and n is the number of tweets. We store the user information in the unordered_map and the tweets in the deque.
*/

class Twitter {
  private:
    struct Tweet {
        int tweetId;
        int timestamp;
        Tweet(int id, int time) : tweetId(id), timestamp(time) {}
    };

    unordered_map<int, vector<Tweet>> userTweets;  // Store tweets of each user
    unordered_map<int, unordered_set<int>> userFollowees;  // Store followees of each user
    int time;  // Keep track of the timestamp

  public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].emplace_back(tweetId, time++);  // Add the tweet with the current timestamp
    }

    void follow(int followerId, int followeeId) {
        userFollowees[followerId].insert(followeeId);  // Add followee to the follower's set of followees
    }

    void unfollow(int followerId, int followeeId) {
        userFollowees[followerId].erase(followeeId);  // Remove followee from the follower's set of followees
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        priority_queue<pair<int, int>> pq;  // Use a priority queue to sort tweets by timestamp (max-heap)

        // Add the user's own tweets to the priority queue
        for (const auto &tweet : userTweets[userId]) {
            pq.push({ tweet.timestamp, tweet.tweetId });
        }

        // Add tweets from the user's followees to the priority queue
        for (int followeeId : userFollowees[userId]) {
            for (const auto &tweet : userTweets[followeeId]) {
                pq.push({ tweet.timestamp, tweet.tweetId });
            }
        }

        // Retrieve the top 10 tweets from the priority queue
        while (!pq.empty() && newsFeed.size() < 10) {
            newsFeed.push_back(pq.top().second);  // Add the tweet ID to the news feed
            pq.pop();
        }

        return newsFeed;
    }
};