class Twitter {
private:
	struct P {
		int id, ref;
		P(int i = 0, int j = 0) :id(i), ref(j) {}
		inline bool operator<(const P& a)const {
			return ref > a.ref;
		}
	};
public:
	/** Initialize your data structure here. */
	Twitter() {
		time = 1;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		userPost[userId].insert(P(tweetId, time++));
		userFollow[userId].insert(userId);
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		q.clear();
		vector<int> res;
		for (auto &r : userFollow[userId]) {
			int n = userPost[r].size();
			auto it = userPost[r].begin();
			n = min(n, 10);
			while (n--) {
				if (q.size() < 10) {
					q.insert(*it++);
				}
				else {
					auto c = q.end();
					if (*it < *--c) {
						q.erase(c);
						q.insert(*it++);
					}
				}
			}
		}
		for (auto &r : q)
			res.push_back(r.id);
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		userFollow[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (followerId == followeeId)
			return;
		userFollow[followerId].erase(followeeId);
	}
private:
	int time;
	set<P> q;
	unordered_map<int, set<int>> userFollow;
	unordered_map<int, set<P>> userPost;
};

/**
* Your Twitter object will be instantiated and called as such:
* Twitter obj = new Twitter();
* obj.postTweet(userId,tweetId);
* vector<int> param_2 = obj.getNewsFeed(userId);
* obj.follow(followerId,followeeId);
* obj.unfollow(followerId,followeeId);
*/