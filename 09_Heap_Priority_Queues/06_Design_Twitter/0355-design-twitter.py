"""
Problem: LeetCode 355 - Design Twitter

Key Idea:
To design a simplified version of Twitter, we can use a combination of data structures. We maintain a dictionary to map users to their tweets, and a set of followees for each user. When a user posts a tweet, we add it to their tweet list. When a user wants to retrieve their news feed, we merge their own tweets and the tweets of their followees, and then sort them based on timestamps.

Time Complexity:
- Post Tweet: The time complexity of posting a tweet is O(1).
- Get News Feed: The time complexity of retrieving a user's news feed is O(f + t log t), where f is the number of followees and t is the total number of tweets.

Space Complexity:
- The space complexity is O(u + t), where u is the number of users and t is the total number of tweets.
"""

import heapq


class Tweet:
    def __init__(self, tweet_id, timestamp):
        self.tweet_id = tweet_id
        self.timestamp = timestamp


class Twitter:
    def __init__(self):
        self.user_tweets = {}  # User ID -> List of Tweet objects
        self.user_followees = {}  # User ID -> Set of followees
        self.timestamp = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.timestamp += 1
        if userId not in self.user_tweets:
            self.user_tweets[userId] = []
        self.user_tweets[userId].append(Tweet(tweetId, self.timestamp))

    def getNewsFeed(self, userId: int) -> List[int]:
        tweets = []

        if userId in self.user_tweets:
            tweets.extend(self.user_tweets[userId])

        if userId in self.user_followees:
            for followee in self.user_followees[userId]:
                if followee in self.user_tweets:
                    tweets.extend(self.user_tweets[followee])

        tweets.sort(key=lambda x: x.timestamp, reverse=True)
        return [tweet.tweet_id for tweet in tweets[:10]]

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId != followeeId:
            if followerId not in self.user_followees:
                self.user_followees[followerId] = set()
            self.user_followees[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if (
            followerId in self.user_followees
            and followeeId in self.user_followees[followerId]
        ):
            self.user_followees[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
