/*
Problem: LeetCode 355 - Design Twitter

Key Idea:
The key idea is to use a combination of data structures: a hash map to store users and their tweets, a priority queue to retrieve the most recent tweets, and a timestamp to track tweet posting times.

Approach:
1. Create two data structures: one for user-to-tweets mapping and another for user-to-following mapping.
2. Maintain a global timestamp to order tweets chronologically.
3. For each tweet, store its content and timestamp along with the user who posted it.
4. Implement a 'postTweet' function to add a tweet to a user's tweet list.
5. Implement a 'getNewsFeed' function to retrieve the most recent tweets from the user and the users they follow, sort them by timestamp, and return the top 'n' tweets.
6. Implement a 'follow' function to allow one user to follow another user.
7. Implement an 'unfollow' function to allow one user to unfollow another user.
8. Use a min-heap (priority queue) to efficiently retrieve the top 'n' tweets in 'getNewsFeed'.

Time Complexity:
- Posting a tweet: O(1)
- Retrieving the news feed: O(n * log(k)), where n is the number of tweets in the user's feed, and k is the number of users the user follows.
- Following/unfollowing a user: O(1)

Space Complexity:
O(m + n), where m is the total number of tweets, and n is the total number of users.
*/

use std::cmp::Reverse;
use std::collections::HashSet;
use std::collections::{BinaryHeap, HashMap};

struct Twitter {
    user_tweets: HashMap<i32, Vec<(i32, i32)>>, // User ID -> List of (Tweet ID, Timestamp)
    user_follows: HashMap<i32, Vec<i32>>,       // User ID -> List of Followed User IDs
    timestamp: i32,
}

impl Twitter {
    fn new() -> Self {
        Twitter {
            user_tweets: HashMap::new(),
            user_follows: HashMap::new(),
            timestamp: 0,
        }
    }

    fn post_tweet(&mut self, user_id: i32, tweet_id: i32) {
        self.timestamp += 1;
        self.user_tweets
            .entry(user_id)
            .or_insert(vec![])
            .push((tweet_id, self.timestamp));
    }

    fn get_news_feed(&self, user_id: i32) -> Vec<i32> {
        let mut tweet_set = HashSet::new();
        let mut min_heap = BinaryHeap::new();

        // Include user's own tweets
        if let Some(tweets) = self.user_tweets.get(&user_id) {
            for &(tweet_id, timestamp) in tweets.iter() {
                min_heap.push(Reverse((timestamp, tweet_id)));
                if min_heap.len() > 10 {
                    min_heap.pop();
                }
            }
        }

        // Include tweets from followed users
        if let Some(followed) = self.user_follows.get(&user_id) {
            for &followed_user_id in followed.iter() {
                if let Some(tweets) = self.user_tweets.get(&followed_user_id) {
                    for &(tweet_id, timestamp) in tweets.iter() {
                        min_heap.push(Reverse((timestamp, tweet_id)));
                        if min_heap.len() > 10 {
                            min_heap.pop();
                        }
                    }
                }
            }
        }

        // Extract the top tweets from the min-heap
        let mut result = vec![];
        while let Some(Reverse((_, tweet_id))) = min_heap.pop() {
            if tweet_set.insert(tweet_id) {
                result.push(tweet_id);
            }
        }

        result.reverse(); // Reverse to get tweets in chronological order
        result
    }

    fn follow(&mut self, follower_id: i32, followee_id: i32) {
        if follower_id != followee_id {
            self.user_follows
                .entry(follower_id)
                .or_insert(vec![])
                .push(followee_id);
        }
    }

    fn unfollow(&mut self, follower_id: i32, followee_id: i32) {
        if let Some(followees) = self.user_follows.get_mut(&follower_id) {
            if let Some(pos) = followees.iter().position(|&id| id == followee_id) {
                followees.remove(pos);
            }
        }
    }
}
